/* 
 *  6. Test for Smiley_PCB
 *     Buttons with Interrupt and Scrolling Text
 */

#include <LedSmileyPcb.h>

LedSmileyPcb lsp = LedSmileyPcb();

char text_1[] = "AAAA";
char text_2[] = "BBBB";
char text_3[] = "CCCC";
char text_4[] = "DDDD";
char text_5[] = "EEEE";

volatile bool end = false;
volatile int text = 0;

void btn_1_callback() {
   if (text != 1) {
    text = 1;
    end = true;
   }
}

void btn_2_callback() {
   if (text != 2) {
    text = 2;
    end = true;
   }
}

void btn_3_callback() {
   if (text != 3) {
    text = 3;
    end = true;
   }
}

void btn_4_callback() {
   if (text != 4) {
    text = 4;
    end = true;
   }
}

void btn_5_callback() {
   if (text != 5) {
    text = 5;
    end = true;
   }
}

void setup() {
  lsp.shutdown(false);
  lsp.setIntensity(8);
  lsp.clearDisplay();
  // lsp.setFont(FONT5x7); // default 8x8
  // lsp.scrollDelay(1000); // default 130

  pinMode(INTERRUPT_1_PIN, INPUT);
  pinMode(INTERRUPT_2_PIN, INPUT);
  pinMode(INTERRUPT_3_PIN, INPUT);
  pinMode(INTERRUPT_4_PIN, INPUT);
  pinMode(INTERRUPT_5_PIN, INPUT);
  attachInterrupt(digitalPinToInterrupt(INTERRUPT_1_PIN), btn_1_callback, FALLING);
  attachInterrupt(digitalPinToInterrupt(INTERRUPT_2_PIN), btn_2_callback, FALLING);
  attachInterrupt(digitalPinToInterrupt(INTERRUPT_3_PIN), btn_3_callback, FALLING);
  attachInterrupt(digitalPinToInterrupt(INTERRUPT_4_PIN), btn_4_callback, FALLING);
  attachInterrupt(digitalPinToInterrupt(INTERRUPT_5_PIN), btn_5_callback, FALLING);
}

void loop() {

  displayText();
}

void displayText() {

  int charLengh = lsp.getFontLengh();
  end = false;

  if (text == 1) {
    for (int i = 0; i < sizeof(text_1)-1; i++) {
      for (int x = 0; x < charLengh; x++) {
        lsp.scrollChar(text_1[i], x);
        if (end) {
          break;
        }
      }
      if (end) {
        lsp.clearDisplay();
        break;
      }
    }
  }

  if (text == 2) {
    for (int i = 0; i < sizeof(text_2)-1; i++) {
      for (int x = 0; x < charLengh; x++) {
        lsp.scrollChar(text_2[i], x);
        if (end) {
          break;
        }
      }
      if (end) {
        lsp.clearDisplay();
        break;
      }
    }
  }

  if (text == 3) {
    for (int i = 0; i < sizeof(text_3)-1; i++) {
      for (int x = 0; x < charLengh; x++) {
        lsp.scrollChar(text_3[i], x);
        if (end) {
          break;
        }
      }
      if (end) {
        lsp.clearDisplay();
        break;
      }
    }
  }

  if (text == 4) {
    for (int i = 0; i < sizeof(text_4)-1; i++) {
      for (int x = 0; x < charLengh; x++) {
        lsp.scrollChar(text_4[i], x);
        if (end) {
          break;
        }
      }
      if (end) {
        lsp.clearDisplay();
        break;
      }
    }
  }

  if (text == 5) {
    for (int i = 0; i < sizeof(text_5)-1; i++) {
      for (int x = 0; x < charLengh; x++) {
        lsp.scrollChar(text_5[i], x);
        if (end) {
          break;
        }
      }
      if (end) {
        lsp.clearDisplay();
        break;
      }
    }
  }

  
  
}
