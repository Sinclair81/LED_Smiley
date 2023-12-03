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
 *    AND:
 * 
 *    Button.h - This library allows to manage a button, specifying if the pressure is long or not.
 *    Copyright (C) 2021 Davide Palladino
 *    https://github.com/davidepalladino/Button-Arduino
 * 
 */

#ifndef LED_SMILEY_PCB_h
#define LED_SMILEY_PCB_h

#include <avr/pgmspace.h>

#if (ARDUINO >= 100)
#include <Arduino.h>
#else
#include <WProgram.h>
#endif

#include "font_5x7_row.h"
#include "font_8x8_row.h"

#define FONT5x7 5
#define FONT8x8 8

#define BUTTON_1_PIN 0
#define BUTTON_2_PIN 1
#define BUTTON_3_PIN 2
#define BUTTON_4_PIN 3
#define BUTTON_5_PIN 4 // 7 for Interrupt ??? pcb v2 ???

#define INTERRUPT_1_PIN 0
#define INTERRUPT_2_PIN 1
#define INTERRUPT_3_PIN 2
#define INTERRUPT_4_PIN 3
#define INTERRUPT_5_PIN 7


class LedSmileyPcb {
    private :
        /* The array for shifting the data to the devices */
        byte spidata[16];
        /* Send out a single command to the device */
        void spiTransfer(byte opcode, byte data);

        /* We keep track of the led-status in this array */
        byte status[8];
        /* Data is shifted out of this pin*/
        int SPI_MOSI;
        /* The clock is signaled on this pin */
        int SPI_CLK;
        /* This one is driven LOW for chip selectzion */
        int SPI_CS;
        /* Character read buffer */
        uint8_t charBuffer[8];
        /* Scroll delay */
        int sDelay;
        /* Current font width */
        uint8_t font;

        /* 
         * Shifts all the leds in a single display row one position to the left.
         * Params :
         */
        void shiftLeft(); 

        void bufferChar(uint8_t c);      

    public:
        /* 
         * Create a new controler 
         * Params :
         * dataPin		pin on the Arduino where data gets shifted out (D12)
         * clockPin		pin for the clock                              (D11)
         * csPin		pin for selecting the device                   (D10)
         */
        LedSmileyPcb(int dataPin = 12, int clkPin = 11, int csPin = 10);

        /* 
         * Set the shutdown (power saving) mode for the device
         * Params :
         * addr	The address of the display to control
         * status	If true the device goes into power-down mode. Set to false
         *		for normal operation.
         */
        void shutdown(bool status);

        /* 
         * Set the number of digits (or rows) to be displayed.
         * See datasheet for sideeffects of the scanlimit on the brightness
         * of the display.
         * Params :
         * limit	number of digits to be displayed (1..8)
         */
        void setScanLimit(int limit);

        /* 
         * Set the brightness of the display.
         * Params:
         * intensity	the brightness of the display. (0..15)
         */
        void setIntensity(int intensity);

        /* 
         * Switch all Leds on the display off. 
         * Params:
         */
        void clearDisplay();

        /* 
         * Updates the display.
         */
        void update(void);

        /* 
         * Sets the font to display
         * Params:
         * font        Font to display (5x7 or 8x8)
         */
        void setFont(uint8_t newFont);

        /* 
         * Get the char lenght from font
         */
        int getFontLengh();

        /* 
         * Set the status of a single Led.
         * Params :
         * row	        the row of the Led (0..7)
         * col	        the column of the Led (0..7)
         * state	    If true the led is switched on, if false it is switched off
         */
        void setLed(int row, int col, boolean state);

        /* 
         * Set all 8 Led's in a column to a new state
         * Params:
         * col	column which is to be set (0..7)
         * value	each bit set to 1 will light up the
         *		corresponding Led.
         */
        void setColumn(int col, byte value);

        /* 
         * Set all 8 Led's in a row to a new state
         * Params:
         * row	row which is to be set (0..7)
         * value	each bit set to 1 will light up the
         *		corresponding Led.
         */
        void setRow(int row, byte value);

        /* 
         * Sets the delay time, in miliseconds, for scrolling text.
         * Params:   
         * val       Delay time
         */
        void scrollDelay(int val);

        /* 
         * Prints a single character.
         * Params:
         * c           Character to draw
         */
        void printChar(char c);
        
        /* 
         * Prints a single character.
         * Params:
         * c           Character to draw
         * x           X coordinate of the top left corner
         * y           Y coordinate of the top left corner
         */
        void printChar(char c, uint8_t x, uint8_t y);
        
        /* 
         * Scrolls a single character onto the matrix from the right to left
         * Params:
         * c           Character to scroll
        */
        void scrollChar(uint8_t c);

        /* 
         * Scrolls a single character onto the matrix from the right to left
         * Params:
         * c            Character to scroll
         * col          Position for scrolling
        */
        void scrollChar(uint8_t c, uint8_t col);

};


// https://github.com/madleech/Button
class Button {
	public:
		Button(uint8_t pin, uint16_t debounce_ms = 30);
		void begin();
		bool read();
		bool toggled();
		bool pressed();
		bool released();
		bool has_changed();
		
		const static bool PRESSED = LOW;
		const static bool RELEASED = HIGH;
	
	private:
		uint8_t  _pin;
		uint16_t _delay;
		bool     _state;
		uint32_t _ignore_until;
		bool     _has_changed;
};

// https://github.com/davidepalladino/Button-Arduino
#define DEFAULT_LONG_PRESS 0
#define NO_PRESS 0
#define SHORT_PRESS 1
#define LONG_PRESS -1
typedef enum input : uint8_t {B_PULLUP, B_NOPULLUP} input_t; 
class Button_v2 {
    public:            
        /** 
         * @brief This constructor creates the object setting only the pin button. Moreover, it calls "pinMode".
         * @param pin Digital pin of the button.
         * @warning The pin will be set to "B_NOPULLUP" mode, respectively "INPUT" of "pinMode".
         */
        Button_v2(uint8_t pin);

        /** 
         * @brief This constructor creates the object setting the pin button and the mode of the input. Moreover, it calls "pinMode".
         * @param pin Digital pin of the button.
         * @param mode Mode of the input, between "INPUT" (with "B_NOPULLUP" constant) and "INPUT_PULLUP" (with "B_PULLUP" constant).
         */
        Button_v2(uint8_t pin, input_t mode);

        /** 
         * @brief This constructor creates the object setting the pin button and the time to define the long press. Moreover, it calls "pinMode".
         * @param pin Digital pin of the button.
         * @param timeLongPress Time in milliseconds for long press.
         * @warning The pin will be set to "B_NOPULLUP" mode, respectively "INPUT" of "pinMode".
         */
        Button_v2(uint8_t pin, uint32_t timeLongPress);

        /** 
         * @brief This constructor creates the object setting the pin button, the mode of the input and the time to define the long press. Moreover, it calls "pinMode".
         * @param pin Digital pin of the button.
         * @param mode Mode of the input, between "INPUT" (with "B_NOPULLUP" constant) and "INPUT_PULLUP" (with "B_PULLUP" constant).
         * @param timeLongPress Time in milliseconds for long press.
         */
        Button_v2(uint8_t pin, input_t mode, uint32_t timeLongPress);

        /**
         * @brief This method sets the time for the long press.
         * @param timeLongPress Time in milliseconds for long press.
         */
        void setTimeLongPress(uint32_t timeLongPress);

        /**
         * @brief This method gets the time for the long press.
         * @return Time in milliseconds for long press.
         */          
        uint32_t getTimeLongPress();

        /**
         * @brief This method gets the actual press, both for short and long. For short press there is the debouncing.
         * @return Value -1 if the pressure is long; 0 if there is not any pressure; 1 if the pressure is short.
         */     
        int8_t checkPress();

    private:
        uint8_t pin;                                // Pin of the button to read the status.
        uint8_t mode;                               // Mode of the input, between "INPUT" (with "B_NOPULLUP" constant) and "INPUT_PULLUP" (with "B_PULLUP" constant).
        uint32_t timeLongPress;                     // Time in milliseconds for the long press.
        uint8_t valuePress;                         // This variable will contain the value where the button will be considered pressed. In example, "HIGH" if the "pinMode" is set to "INPUT"; "LOW" if the "pinMode" is set to "INPUT_PULLUP".
        uint32_t timeOut;                           // End of time, calculated with the actual time plus "timeLongPress".
        bool isPressed;                             // Flag to indicate if the button was already pressed.
        bool isLongPressed;                         // Flag to indicate if the last press was long or not.
        int8_t actualValue;                         // Actual value of the button.

        /**
         * @brief This method sets the input mode.
         * @param mode Mode of the input.
         */
        void setMode(input_t mode);

        /**
         * @brief This method sets the value where the button will be considered pressed.
         */
        void setValuePress();  
};

#endif	//LedSmileyPcb.h



