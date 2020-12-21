/* 
 *  2. Test Smiley_PCB
 *     Characters and LEDs
 */

#include <LedSmileyPcb.h>

LedSmileyPcb lc = LedSmileyPcb(12,11,10);

unsigned long delaytime=50;

void setup() {
  lc.shutdown(false);
  lc.setIntensity(8);
  lc.clearDisplay();
}

/*
 This method will display the characters for the
 word "Arduino" one after the other on the matrix. 
 (you need at least 5x7 leds to see the whole chars)
 */
void writeArduinoOnMatrix() {
  /* here is the data for the characters */
  byte a[8]={B01111110,B10001000,B10001000,B10001000,B01111110};
  byte r[5]={B00111110,B00010000,B00100000,B00100000,B00010000};
  byte d[5]={B00011100,B00100010,B00100010,B00010010,B11111110};
  byte u[5]={B00111100,B00000010,B00000010,B00000100,B00111110};
  byte i[5]={B00000000,B00100010,B10111110,B00000010,B00000000};
  byte n[5]={B00111110,B00010000,B00100000,B00100000,B00011110};
  byte o[5]={B00011100,B00100010,B00100010,B00100010,B00011100};

  /* now display them one by one with a small delay */
  lc.setColumn(0,a[0]);
  lc.setColumn(1,a[1]);
  lc.setColumn(2,a[2]);
  lc.setColumn(3,a[3]);
  lc.setColumn(4,a[4]);
  delay(delaytime*10);
  lc.setColumn(0,r[0]);
  lc.setColumn(1,r[1]);
  lc.setColumn(2,r[2]);
  lc.setColumn(3,r[3]);
  lc.setColumn(4,r[4]);
  delay(delaytime*10);
  lc.setColumn(0,d[0]);
  lc.setColumn(1,d[1]);
  lc.setColumn(2,d[2]);
  lc.setColumn(3,d[3]);
  lc.setColumn(4,d[4]);
  delay(delaytime*10);
  lc.setColumn(0,u[0]);
  lc.setColumn(1,u[1]);
  lc.setColumn(2,u[2]);
  lc.setColumn(3,u[3]);
  lc.setColumn(4,u[4]);
  delay(delaytime*10);
  lc.setColumn(0,i[0]);
  lc.setColumn(1,i[1]);
  lc.setColumn(2,i[2]);
  lc.setColumn(3,i[3]);
  lc.setColumn(4,i[4]);
  delay(delaytime*10);
  lc.setColumn(0,n[0]);
  lc.setColumn(1,n[1]);
  lc.setColumn(2,n[2]);
  lc.setColumn(3,n[3]);
  lc.setColumn(4,n[4]);
  delay(delaytime*10);
  lc.setColumn(0,o[0]);
  lc.setColumn(1,o[1]);
  lc.setColumn(2,o[2]);
  lc.setColumn(3,o[3]);
  lc.setColumn(4,o[4]);
  delay(delaytime*10);
  lc.setColumn(0,0);
  lc.setColumn(1,0);
  lc.setColumn(2,0);
  lc.setColumn(3,0);
  lc.setColumn(4,0);
  delay(delaytime*10);
  lc.clearDisplay();
}

/*
  This function lights up a some Leds in a row.
 The pattern will be repeated on every row.
 The pattern will blink along with the row-number.
 row number 4 (index==3) will blink 4 times etc.
 */
void rows(bool longTest) {
  for(int row=0;row<8;row++) {
    delay(delaytime);
    lc.setRow(row,B10100000);
    delay(delaytime);
    lc.setRow(row,(byte)0);
    if (longTest) {
      for(int i=0;i<row;i++) {
        delay(delaytime);
        lc.setRow(row,B10100000);
        delay(delaytime);
        lc.setRow(row,(byte)0);
      }
      }
  }
  lc.clearDisplay();
}

/*
  This function lights up a some Leds in a column.
 The pattern will be repeated on every column.
 The pattern will blink along with the column-number.
 column number 4 (index==3) will blink 4 times etc.
 */
void columns(bool longTest) {
  for(int col=0;col<8;col++) {
    delay(delaytime);
    lc.setColumn(col,B10100000);
    delay(delaytime);
    lc.setColumn(col,(byte)0);
    if (longTest) {
      for(int i=0;i<col;i++) {
        delay(delaytime);
        lc.setColumn(col,B10100000);
        delay(delaytime);
        lc.setColumn(col,(byte)0);
      }
    }
  }
  lc.clearDisplay();
}

/* 
 This function will light up every Led on the matrix.
 The led will blink along with the row-number.
 row number 4 (index==3) will blink 4 times etc.
 */
void single(bool longTest) {
  for(int row=0;row<8;row++) {
    for(int col=0;col<8;col++) {
      delay(delaytime);
      lc.setLed(row,col,true);
      delay(delaytime);
      if (longTest) {
        for(int i=0;i<col;i++) {
          lc.setLed(row,col,false);
          delay(delaytime);
          lc.setLed(row,col,true);
          delay(delaytime);
        }
      }
    }
  }
  delay(delaytime*10);
  lc.clearDisplay();
}

void loop() { 
  writeArduinoOnMatrix();
  rows(false);
  columns(false);
  single(false);
}
