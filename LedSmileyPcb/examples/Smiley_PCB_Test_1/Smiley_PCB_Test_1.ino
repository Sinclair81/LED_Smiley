/* 
 *  1. Test for Smiley_PCB
 *     Basic Smileys
 */

#include <LedSmileyPcb.h>

LedSmileyPcb lsp = LedSmileyPcb();

byte figure_1[8] = { B00111100,
                     B01000010,
                     B10100101,
                     B10000001,
                     B10100101,
                     B10011001,
                     B01000010,
                     B00111100 };

byte figure_2[8] = { B00111100,
                     B01000010,
                     B10100101,
                     B10000001,
                     B10000001,
                     B10111101,
                     B01000010,
                     B00111100 };

byte figure_3[8] = { B00111100,
                     B01000010,
                     B10100101,
                     B10000001,
                     B10011001,
                     B10100101,
                     B01000010,
                     B00111100 };

void setup() {
  lsp.shutdown(false);
  lsp.setIntensity(8);
  lsp.clearDisplay();
}

void loop() { 
  for (int i=0; i<8; i++){
    lsp.setRow(i,figure_1[i]);
  }
  delay(2000);
  for (int i=0; i<8; i++){
    lsp.setRow(i,figure_2[i]);
  }
  delay(2000);
  for (int i=0; i<8; i++){
    lsp.setRow(i,figure_3[i]);
  }
  delay(2000);
}  
