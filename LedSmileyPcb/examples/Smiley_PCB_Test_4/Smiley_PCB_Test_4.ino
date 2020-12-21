/* 
 *  4. Test for Smiley_PCB
 *     Buttons and Print Character
 *    
 *     The button pins are pullt high wiht a pullupresistor on the PCB.
 *     If the button is presst, the pin gos low!
 */

#include <LedSmileyPcb.h>

LedSmileyPcb lsp = LedSmileyPcb();

Button button1(BUTTON_1_PIN);
Button button2(BUTTON_2_PIN);
Button button3(BUTTON_3_PIN);
Button button4(BUTTON_4_PIN);
Button button5(BUTTON_5_PIN);

void setup() {
  lsp.shutdown(false);
  lsp.setIntensity(8);
  lsp.clearDisplay();
  // lsp.setFont(FONT5x7); // default 8x8

  button1.begin();
  button2.begin();
  button3.begin();
  button4.begin();
  button5.begin();
}

void loop() {

  if (button1.pressed()) {
    lsp.printChar('A');
  }

  if (button2.pressed()) {
    lsp.printChar('B');
  }

  if (button3.pressed()) {
    lsp.printChar('C');
  }

  if (button4.pressed()) {
    lsp.printChar('D');
  }

  if (button5.pressed()) {
    lsp.printChar('E');
  }
  
}  
