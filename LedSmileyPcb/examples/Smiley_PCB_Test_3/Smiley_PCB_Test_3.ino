/* 
 *  3. Test for Smiley_PCB
 *     Print Character and Scrolling Text
 */

#include <LedSmileyPcb.h>

LedSmileyPcb lsp = LedSmileyPcb();

char text[] = "Hello World!";

void setup() {
  lsp.shutdown(false);
  lsp.setIntensity(8);
  lsp.clearDisplay();
  
  // lsp.setFont(FONT5x7); // default 8x8
  // lsp.scrollDelay(1000); // default 130
  
  lsp.printChar('A');
  delay(3000);
  lsp.clearDisplay();
}

void loop() {
  for (int i = 0; i < sizeof(text)-1; i++) {
    lsp.scrollChar(text[i]);
  }
}  
