/*    
 *    Approx. 80% of the LED code are from:
 * 
 *    LedControl.h - A library for controling Leds with a MAX7219/MAX7221
 *    Copyright (c) 2007 Eberhard Fahle
 *    http://wayoda.github.io/LedControl/
 * 
 *    AND:
 * 
 *    LedMatrix.h - An Arduino library for led dot matrix using MAX72XX drivers
 *    Copyright (c) 2015 Aaron Groom
 *    https://github.com/agr00m/LedMatrix
 * 
 * 
 *    100% of the Button code are from:
 * 
 *    Button.h - a small library for Arduino to handle button debouncing
 *    Copyright (C) 2016 Michael D K Adams
 *    https://github.com/madleech/Button
 * 
 */

#include "LedSmileyPcb.h"

//the opcodes for the MAX7219
#define OP_NOOP   0
#define OP_DECODEMODE  9
#define OP_INTENSITY   10
#define OP_SCANLIMIT   11
#define OP_SHUTDOWN    12
#define OP_DISPLAYTEST 15

#define SETBIT(ADDRESS,BIT)   (ADDRESS |= (1<<BIT))
#define CLEARBIT(ADDRESS,BIT) (ADDRESS &= ~(1<<BIT))
#define CHECKBIT(ADDRESS,BIT) (ADDRESS & (1<<BIT))

LedSmileyPcb::LedSmileyPcb(int dataPin, int clkPin, int csPin) {
    SPI_MOSI=dataPin;
    SPI_CLK=clkPin;
    SPI_CS=csPin;
    pinMode(SPI_MOSI,OUTPUT);
    pinMode(SPI_CLK,OUTPUT);
    pinMode(SPI_CS,OUTPUT);
    digitalWrite(SPI_CS,HIGH);
    for(int i=0;i<8;i++) {
        status[i]=0x00;
    }
    spiTransfer(OP_DISPLAYTEST,0);
    //scanlimit is set to max on startup
    setScanLimit(7);
    //decode is done in source
    spiTransfer(OP_DECODEMODE,0);
    clearDisplay();
    //we go into shutdown-mode on startup
    shutdown(true);
    // Set the default scroll delay
    sDelay = 100;
    // Set the default font to 8x8
    font = FONT8x8;
}

void LedSmileyPcb::shutdown(bool b) {
    if (b) {
        spiTransfer(OP_SHUTDOWN,0);
    } else {
        spiTransfer(OP_SHUTDOWN,1);
    }
}

void LedSmileyPcb::setScanLimit(int limit) {
    if (limit>=0 && limit<8) {
        spiTransfer(OP_SCANLIMIT,limit);
    }
}

void LedSmileyPcb::setIntensity(int intensity) {
    if (intensity>=0 && intensity<16) {
        spiTransfer(OP_INTENSITY,intensity);
    }
}

void LedSmileyPcb::clearDisplay() {
    for (int i=0;i<8;i++) {
        status[i]=0;
        spiTransfer(i+1,status[i]);
    }
}

void LedSmileyPcb::setFont(uint8_t newFont) {
   if (newFont != FONT5x7 && newFont != FONT8x8) {
      return;
   }
   font = newFont;
}

int LedSmileyPcb::getFontLengh() {
    if (font == FONT5x7) {
        return 7;
    }
    return 8;
}

void LedSmileyPcb::setLed(int row, int column, boolean state) {
    byte val=0x00;
    if (row<0 || row>7 || column<0 || column>7) {
        return;
    }
    val=B10000000 >> column;
    if (state) {
        status[row]=status[row]|val;
    } else {
        val=~val;
        status[row]=status[row]&val;
    }
    spiTransfer(row+1,status[row]);
}

void LedSmileyPcb::setColumn(int col, byte value) {
    if(col<0 || col>7) {
        return;
    }
    status[col]=value;
    spiTransfer(col+1,status[col]);
}

void LedSmileyPcb::setRow(int row, byte value) {
    byte val;
    if(row<0 || row>7) {
        return;
    }
    for (int col=0;col<8;col++) {
        val=value >> (7-col);
        val=val & 0x01;
        setLed(col,row,val);
    }
}

void LedSmileyPcb::scrollDelay(int val) {
	sDelay = val;
}

void LedSmileyPcb::printChar(char c) {
    if (font == FONT5x7) {
        printChar(c, 0, 1);
    } else if (font == FONT8x8) {
        printChar(c, 0, 0);
    }
}

void LedSmileyPcb::printChar(char c, uint8_t x, uint8_t y) {
    int8_t fHeight, rows, offset; 
    bufferChar(c);
    for (uint8_t col = 0; col < font; col++) { 
        if (x+col >= 0 && x+col < 8) {
            if (font == FONT5x7) {
                rows = 7;
                offset = 1;
            } else if (font == FONT8x8) {
                rows = 8;
                offset = 0;
            }
            for (uint8_t row = 0; row < rows; row++) {
                if (y+row >= 0 && y+row < 8) {
                setLed(x+col, y+row, CHECKBIT(charBuffer[col], 7-row-offset));
                }
            }
        }
    }
}

void LedSmileyPcb::scrollChar(uint8_t c) {
    bufferChar(c);
    for (uint8_t col = 0; col < font; col++) {
        shiftLeft();
        status[7] = charBuffer[col];
        update();
    }
    // If 5x7 font, shift one more to add a space between characters.
    if (font == FONT5x7) {
        shiftLeft();
        update();
    }
}

void LedSmileyPcb::scrollChar(uint8_t c, uint8_t col) { 
    bufferChar(c);
    shiftLeft();
    status[7] = charBuffer[col];
    update();
    // If 5x7 font, shift one more to add a space between characters.
    if ((font == FONT5x7) & (col == 7)) {
        shiftLeft();
        update();
    }
}

void LedSmileyPcb::shiftLeft() {
    for (byte col = 0; col < 8; col++) {
        if (col > 0) {
            status[col-1] = status[col];
        }
    }
    status[7] = 0;
    delay(sDelay);
}

void LedSmileyPcb::bufferChar(uint8_t c) { 
   for (uint8_t row = 0; row < font; row++) {  
      if (font == FONT5x7) {
        charBuffer[row] = pgm_read_byte(&font_5x7_row[c][row]);
      } else if (font == FONT8x8) {
        charBuffer[row] = pgm_read_byte(&font_8x8_row[c][row]);
      }
   }
}

void LedSmileyPcb::update(void) {
    for (int i=0;i<8;i++) {
        spiTransfer(i+1,status[i]);
    }
}

void LedSmileyPcb::spiTransfer(volatile byte opcode, volatile byte data) {
    //Create an array with the data to shift out
    for (int i=0;i<8;i++) {
        spidata[i]=(byte)0;
    }
    //put our device data into the array
    spidata[1]=opcode;
    spidata[0]=data;
    //enable the line 
    digitalWrite(SPI_CS,LOW);
    //Now shift out the data 
    for (int i=8;i>0;i--) {
        shiftOut(SPI_MOSI,SPI_CLK,MSBFIRST,spidata[i-1]);
    }
    //latch the data onto the display
    digitalWrite(SPI_CS,HIGH);
}


/***************************************************************************************
 *                                                                                     *
 *          Button Code !!!                                                            *
 *          https://github.com/madleech/Button                                         *
 *                                                                                     *
 ***************************************************************************************/

Button::Button(uint8_t pin, uint16_t debounce_ms): _pin(pin), _delay(debounce_ms), _state(HIGH), _ignore_until(0), _has_changed(false) {
}

void Button::begin() {
	pinMode(_pin, INPUT);
}

bool Button::read() {
	// ignore pin changes until after this delay time
	if (_ignore_until > millis()) {
		// ignore any changes during this period
	} else if (digitalRead(_pin) != _state) {// pin has changed 
		_ignore_until = millis() + _delay;
		_state = !_state;
		_has_changed = true;
	}
	return _state;
}

// has the button been toggled from on -> off, or vice versa
bool Button::toggled() {
	read();
	return has_changed();
}

// mostly internal, tells you if a button has changed after calling the read() function
bool Button::has_changed() {
	if (_has_changed) {
		_has_changed = false;
		return true;
	}
	return false;
}

// has the button gone from off -> on
bool Button::pressed() {
	return (read() == PRESSED && has_changed());
}

// has the button gone from on -> off
bool Button::released() {
	return (read() == RELEASED && has_changed());
}
