/* 
 *  5. Test for Smiley_PCB
 *     Buttons with out Interrupt and Scrolling Text
 */

#include <LedSmileyPcb.h>

LedSmileyPcb lsp = LedSmileyPcb();

char text_1[] = "AAAA";
char text_2[] = "BBBB";
char text_3[] = "CCCC";
char text_4[] = "DDDD";
char text_5[] = "EEEE";

Button button1(BUTTON_1_PIN);
Button button2(BUTTON_2_PIN);
Button button3(BUTTON_3_PIN);
Button button4(BUTTON_4_PIN);
Button button5(BUTTON_5_PIN);

int text = 0;

void setup() {
  lsp.shutdown(false);
  lsp.setIntensity(8);
  lsp.clearDisplay();
  // lsp.setFont(FONT5x7); // default 8x8
  // lsp.scrollDelay(1000); // default 130
  
  button1.begin();
  button2.begin();
  button3.begin();
  button4.begin();
  button5.begin();
}

void loop() {

  checkButtons();
  displayText();
}

bool checkButtons() {
  
  int new_text = 0;

  if (button1.pressed()) {
    new_text = 1;
  }

  if (button2.pressed()) {
    new_text = 2;
  }

  if (button3.pressed()) {
    new_text = 3;
  }

  if (button4.pressed()) {
    new_text = 4;
  }

  if (button5.pressed()) {
    new_text = 5;
  }

  if (new_text != text & new_text != 0) {
    lsp.clearDisplay();
    text = new_text;
    return true;
  }

  return false;
}

void displayText() {

  int charLengh = lsp.getFontLengh();
  bool end = false;

  if (text == 1) {
    for (int i = 0; i < sizeof(text_1)-1; i++) {
      for (int x = 0; x < charLengh; x++) {
        lsp.scrollChar(text_1[i], x);
        end = checkButtons();
        if (end) {
          break;
        }
      }
      if (end) {
        break;
      }
    }
  }

  if (text == 2) {
    for (int i = 0; i < sizeof(text_2)-1; i++) {
      for (int x = 0; x < charLengh; x++) {
        lsp.scrollChar(text_2[i], x);
        end = checkButtons();
        if (end) {
          break;
        }
      }
      if (end) {
        break;
      }
    }
  }

  if (text == 3) {
    for (int i = 0; i < sizeof(text_3)-1; i++) {
      for (int x = 0; x < charLengh; x++) {
        lsp.scrollChar(text_3[i], x);
        end = checkButtons();
        if (end) {
          break;
        }
      }
      if (end) {
        break;
      }
    }
  }

  if (text == 4) {
    for (int i = 0; i < sizeof(text_4)-1; i++) {
      for (int x = 0; x < charLengh; x++) {
        lsp.scrollChar(text_4[i], x);
        end = checkButtons();
        if (end) {
          break;
        }
      }
      if (end) {
        break;
      }
    }
  }

  if (text == 5) {
    for (int i = 0; i < sizeof(text_5)-1; i++) {
      for (int x = 0; x < charLengh; x++) {
        lsp.scrollChar(text_5[i], x);
        end = checkButtons();
        if (end) {
          break;
        }
      }
      if (end) {
        break;
      }
    }
  }

  
  
}
