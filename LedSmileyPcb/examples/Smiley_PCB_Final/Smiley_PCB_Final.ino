/* 
 *  Final Code for Smiley_PCB
 *  Buttons and Print Character
 *    
 *  The button pins are pullt high wiht a pullupresistor on the PCB.
 *  If the button is presst, the pin gos low!
 * 
 * Button 1 short - Change figure - (mode 1)
 * Button 2 short - Change figure + (mode 1)
 *
 * Button 3 short - 2x Flash        (mode 3)
 * Button 4 short - Fade In/Out     (mode 4)
 * Button 5 short - animated man    (mode 5)
 * 
 * Button 3 long  - Text Scrolling  (mode 6)
 * Button 4 long  - Text Scrolling  (mode 7)
 * Button 5 long  - Text Scrolling  (mode 8)
 * 
 */

#include <LedSmileyPcb.h>
#include <Metro.h>

LedSmileyPcb lsp = LedSmileyPcb();

Metro ticMetro = Metro(125);
Metro scrMetro = Metro(90);

Button_v2 button1(BUTTON_1_PIN, B_PULLUP, 2000);
Button_v2 button2(BUTTON_2_PIN, B_PULLUP, 2000);
Button_v2 button3(BUTTON_3_PIN, B_PULLUP, 2000);
Button_v2 button4(BUTTON_4_PIN, B_PULLUP, 2000);
Button_v2 button5(BUTTON_5_PIN, B_PULLUP, 2000);

short button_1 = NO_PRESS;
short button_2 = NO_PRESS;
short button_3 = NO_PRESS;
short button_4 = NO_PRESS;
short button_5 = NO_PRESS;

int mode = 1;
int mode_step = 0;

int figure_num = 0;
int figure_max_num = 20;
int figure_old = -1;

byte figure[21][8] = {
  { B00111100,   //   ****
    B01000010,   //  *    *
    B10100101,   // * *  * *
    B10000001,   // *      *
    B10100101,   // * *  * *
    B10011001,   // *  **  *
    B01000010,   //  *    *
    B00111100},  //   ****

  { B00111100,   //   ****
    B01000010,   //  *    *
    B10100101,   // * *  * *
    B10000001,   // *      *
    B10111101,   // * **** *
    B10011001,   // *  **  *
    B01000010,   //  *    *
    B00111100},  //   ****

  { B00111100,   //   ****
    B01000010,   //  *    *
    B10100101,   // * *  * *
    B10000001,   // *      *
    B10111101,   // * **** *
    B10001001,   // *   *  *
    B01000010,   //  *    *
    B00111100},  //   ****

  { B00111100,   //   ****
    B01000010,   //  *    *
    B10100101,   // * *  * *
    B10000001,   // *      *
    B10011001,   // *  **  *
    B10100101,   // * *  * *
    B01000010,   //  *    *
    B00111100},  //   ****

  { B00111100,   //   ****
    B01000010,   //  *    *
    B10100101,   // * *  * *
    B11000011,   // **    **
    B10000001,   // *      *
    B10011001,   // *  **  *
    B01000010,   //  *    *
    B00111100},  //   ****

  { B00111100,   //   ****
    B01000010,   //  *    *
    B10100101,   // * *  * *
    B10100101,   // * *  * *
    B10000001,   // *      *
    B10011001,   // *  **  *
    B01000010,   //  *    *
    B00111100},  //   ****

  { B00111100,   //   ****
    B01000010,   //  *    *
    B10100101,   // * *  * *
    B10000001,   // *      *
    B10000001,   // *      *
    B10000001,   // *      *
    B01000010,   //  *    *
    B00111100},  //   ****

  { B00111100,   //   ****
    B01000010,   //  *    *
    B10100101,   // * *  * *
    B10000001,   // *      *
    B10011001,   // *  **  *
    B10011001,   // *  **  *
    B01000010,   //  *    *
    B00111100},  //   ****

  { B00111100,   //   ****
    B01000010,   //  *    *
    B10100101,   // * *  * *
    B10000001,   // *      *
    B10111101,   // * **** *
    B10000001,   // *      *
    B01000010,   //  *    *
    B00111100},  //   ****

  { B00111100,   //   ****
    B01000010,   //  *    *
    B10101001,   // * * *  *
    B10101001,   // * * *  *
    B10000101,   // *    * *
    B10111001,   // * ***  *
    B01000010,   //  *    *
    B00111100},  //   ****

  { B00000000,   // 
    B01100110,   //  **  **
    B11111111,   // ********
    B11111111,   // ********
    B11111111,   // ********
    B01111110,   //  ******
    B00111100,   //   ****
    B00011000},  //    **

  { B00000000,   // 
    B01100110,   //  **  **
    B10011001,   // *  **  *
    B10000001,   // *      *
    B10000001,   // *      *
    B01000010,   //  *    *
    B00100100,   //   *  *
    B00011000},  //    **

  { B00001000,   //     *
    B00001100,   //     **
    B00001110,   //     ***
    B00001000,   //     *
    B00111000,   //   ***
    B01001000,   //  *  *
    B01001000,   //  *  *
    B00110000},  //   **

  { B00001000,   //     *
    B00001100,   //     **
    B00001110,   //     ***
    B00001000,   //     *
    B00111000,   //   ***
    B01111000,   //  ****
    B01111000,   //  ****
    B00110000},  //   **

  { B01111100,   //  *****
    B11111110,   // *******
    B10010010,   // *  *  *
    B11011010,   // ** ** *
    B11111110,   // *******
    B11111110,   // *******
    B11111110,   // *******
    B10101010},  // * * * *

  { B00000000,   // 
    B00100000,   //   *
    B11100000,   // ***
    B11100001,   // ***    *
    B00111110,   //   *****
    B00111110,   //   *****
    B00100010,   //   *   *
    B01100110},  //  **  **

  { B01110000,   //  ***
    B11010000,   // ** *
    B01110000,   //  ***
    B01111000,   //  ****
    B01111111,   //  *******
    B01111110,   //  ******
    B01111000,   //  ****
    B00100000},  //   *

  { B00011000,   //    **
    B00001000,   //     *
    B01110110,   //  *** **
    B11111111,   // ********
    B11111111,   // ********
    B11111111,   // ********
    B01111010,   //  **** *
    B00110100},  //   ** *

  { B00000000,   // 
    B01111100,   //  *****
    B10010010,   // *  *  *
    B10010010,   // *  *  *
    B11111110,   // *******
    B11101110,   // *** ***
    B11111110,   // *******
    B01010100},  //  * * *

  { B10001000,   // *   *
    B11111000,   // *****
    B10101000,   // * * *
    B01110001,   //  ***   *
    B00100001,   //   *    *
    B01111001,   //  ****  *
    B01111101,   //  ***** *
    B10111110},  // * *****

  { B00011000,   //    **
    B00011000,   //    **
    B00111100,   //   ****
    B11111111,   // ********
    B11111111,   // ********
    B00111100,   //   ****
    B01100110,   //  **  **
    B11000011}   // **    **
};

byte figure_2[6][8] = { 
  { B00011000,   // man 1
    B00100100,   // 
    B00100100,   // 
    B00011000,   // 
    B01111110,   // 
    B00011000,   // 
    B00100100,   // 
    B01000010},  // 

  { B00011000,   //  man 2
    B00100100,   // 
    B00100100,   // 
    B00011010,   // 
    B01111100,   // 
    B00011000,   // 
    B01100100,   // 
    B00000010},  // 

  { B00011000,   //  man 3
    B00100100,   // 
    B00100100,   // 
    B00011010,   // 
    B00111100,   // 
    B01011000,   // 
    B00110100,   // 
    B00000100},  // 

  { B00011000,   //  man 4
    B00100100,   // 
    B00100100,   // 
    B00011010,   // 
    B00111100,   // 
    B01011000,   // 
    B00011000,   // 
    B00011000},  // 

  { B00011000,   //  man 5
    B00100100,   // 
    B00100100,   // 
    B00011010,   // 
    B00111100,   // 
    B01011000,   // 
    B00010100,   // 
    B00010000},  // 

  { B00011000,   //  man 6
    B00100100,   // 
    B00100100,   // 
    B00011000,   // 
    B00111110,   // 
    B01011000,   // 
    B00010100,   // 
    B00010100}   // 
};

char text_1[] = "Das ist der Text 1!";
char text_2[] = "Das ist der Text 2!";
char text_3[] = "Das ist der Text 3!";
int char_step = 0;
int char_max_step = 0;

void setup() {
  Serial.begin(9600);

  lsp.shutdown(false);
  lsp.setIntensity(8);
  lsp.clearDisplay();
  lsp.setFont(FONT5x7); // default 8x8

  char_max_step = lsp.getFontLengh();

}

void loop() {

  button_1 = button1.checkPress();
  button_2 = button2.checkPress();
  button_3 = button3.checkPress();
  button_4 = button4.checkPress();
  button_5 = button5.checkPress();

  if (button_1 == SHORT_PRESS) {
    if (mode == 1) {
      if (figure_num > 1) {
        figure_num -= 1;
      } else {
        figure_num = figure_max_num;
      }
    } else {
      mode = 1;
      figure_old = -1;
      lsp.setIntensity(8);
    }
    mode_step = 0;
  }
  
  if (button_2 == SHORT_PRESS) {
    if (mode == 1) {
      if (figure_num < figure_max_num) {
        figure_num += 1;
      } else {
        figure_num = 0;
      }
    } else {
      mode = 1;
      figure_old = -1;
      lsp.setIntensity(8);
    }
    mode_step = 0;
  }

  if (button_3 == SHORT_PRESS) {
    mode = 3;
    draw_reset();
  }
  if (button_3 == LONG_PRESS) {
    mode = 6;
    draw_reset();
  }

  if (button_4 == SHORT_PRESS) {
    mode = 4;
    draw_reset();
  }
  if (button_4 == LONG_PRESS) {
    mode = 7;
    draw_reset();
  }

  if (button_5 == SHORT_PRESS) {
    mode = 5;
    draw_reset();
  }
  if (button_5 == LONG_PRESS) {
    mode = 8;
    draw_reset();
  }

  switch (mode) {
  case 1:
    mode_1();
    break;
  case 2:
    mode_2();
    break;
  case 3:
    mode_3();
    break;
  case 4:
    mode_4();
    break;
  case 5:
    mode_5();
    break;
  case 6:
    mode_6();
    break;
  case 7:
    mode_7();
    break;
  case 8:
    mode_8();
    break;
  }
  
}

void draw_figure() {

  if (figure_old != figure_num) {
    figure_old = figure_num;
    for (int i=0; i<8; i++) {
      lsp.setRow(i,figure[figure_num][i]);
    }
  }

}

void draw_man(int num) {
  for (int i=0; i<8; i++) {
    lsp.setRow(i,figure_2[num][i]);
  }
}

void draw_reset() {
  mode_step = 0;
  char_step = 0;
  figure_old = -1;
  lsp.setIntensity(8);
  lsp.clearDisplay();
}

void mode_1() {

   draw_figure();

}

void mode_2() {

  if (ticMetro.check() == 1) {
    draw_figure();
  }
  
}

void mode_3() {

  if (ticMetro.check() == 1) {

    switch(mode_step){
      case 0:
        draw_figure();
        break;
      case 1:
        figure_old = -1;
        lsp.clearDisplay();
        break;
      case 2:
        draw_figure();
        break;
      case 3:
        figure_old = -1;
        lsp.clearDisplay();
        break;
    }

    if (mode_step < 8) {
      mode_step += 1;
    } else {
      mode_step = 0;
    }
  }
  
}

void mode_4() {

  if (ticMetro.check() == 1) {

    switch(mode_step){
      case 0:
        lsp.setIntensity(8);
        break;
      case 1:
        lsp.setIntensity(7);
        break;
      case 2:
        lsp.setIntensity(6);
        break;
      case 3:
        lsp.setIntensity(5);
        break;
      case 4:
        lsp.setIntensity(4);
        break;
      case 5:
        lsp.setIntensity(3);
        break;
      case 6:
        lsp.setIntensity(2);
        break;
      case 7:
        lsp.setIntensity(1);
        break;
      case 8:
        lsp.setIntensity(0);
        break;
      case 9:
        lsp.setIntensity(1);
        break;
      case 10:
        lsp.setIntensity(2);
        break;
      case 11:
        lsp.setIntensity(3);
        break;
      case 12:
        lsp.setIntensity(4);
        break;
      case 13:
        lsp.setIntensity(5);
        break;
      case 14:
        lsp.setIntensity(6);
        break;
      case 15:
        lsp.setIntensity(7);
        break;
    }

    if (mode_step <= 15) {
      mode_step += 1;
    } else {
      mode_step = 0;
    }
    draw_figure();
  }
  
}

void mode_5() {

  if (ticMetro.check() == 1) {

    draw_man(mode_step);

    if (mode_step < 5) {
      mode_step += 1;
    } else {
      mode_step = 0;
    }
  }

}

void mode_6() {

  if (scrMetro.check() == 1) {

    lsp.scrollChar(text_1[mode_step], char_step);

    if (char_step < (char_max_step - 1)) {
      char_step += 1;
    } else {
      char_step = 0;
      if (mode_step < sizeof(text_1) - 1) {
        mode_step += 1;
      } else {
        mode_step = 0;
      }
      if (text_1[mode_step] == ' ') {
        char_max_step = (lsp.getFontLengh() / 2);
      } else {
        char_max_step = lsp.getFontLengh();
      }
    }

  }

}

void mode_7() {

  if (scrMetro.check() == 1) {

    lsp.scrollChar(text_2[mode_step], char_step);

    if (char_step < (char_max_step - 1)) {
      char_step += 1;
    } else {
      char_step = 0;
      if (mode_step < sizeof(text_2) - 1) {
        mode_step += 1;
      } else {
        mode_step = 0;
      }
      if (text_2[mode_step] == ' ') {
        char_max_step = (lsp.getFontLengh() / 2);
      } else {
        char_max_step = lsp.getFontLengh();
      }
    }

  }

}

void mode_8() {

  if (scrMetro.check() == 1) {

    lsp.scrollChar(text_3[mode_step], char_step);

    if (char_step < (char_max_step - 1)) {
      char_step += 1;
    } else {
      char_step = 0;
      if (mode_step < sizeof(text_3) - 1) {
        mode_step += 1;
      } else {
        mode_step = 0;
      }
      if (text_3[mode_step] == ' ') {
        char_max_step = (lsp.getFontLengh() / 2);
      } else {
        char_max_step = lsp.getFontLengh();
      }
    }

  }

}
