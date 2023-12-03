# LED Smiley PCB #

[![donate](https://img.shields.io/badge/donate-PayPal-blue.svg)](https://www.paypal.me/Sinclair81)

<!-- markdownlint-disable MD033 -->
<img src="https://github.com/Sinclair81/LED_Smiley/blob/master/Smiley_Top.png" align="right" alt="Smiley_Top" height="233" width="350">

<!-- https://raw.githubusercontent.com/Sinclair81/LED_Smiley/master/Smiley_Top.png -->

<!-- markdownlint-enable MD033 -->

A [Arduino](https://www.arduino.cc) [Leonardo](https://store.arduino.cc/arduino-leonardo-with-headers) like PCB with 65 LED's and 5 Buttons.  
MCU - ATmega32U4-AU (16MHz)  
LED Driver - Max7219CWG  
  
The main parts of the library code are from:  
[LedControl.h](http://wayoda.github.io/LedControl/) Copyright (c) 2007 Eberhard Fahle  
[LedMatrix.h](https://github.com/agr00m/LedMatrix) Copyright (c) 2015 Aaron Groom  
[Button.h (v1)](https://github.com/madleech/Button) Copyright (c) 2016 Michael D K Adams  
[Button.h (v2)](https://github.com/davidepalladino/Button-Arduino) Copyright (c) 2021 Davide Palladino  
  
Name            | Pin
--------------- | ---------------------
Button 1        | D0  
Button 2        | D1  
Button 3        | D2  
Button 4        | D3  
Button 5        | D4  
Max7219CWG LOAD | D10  
Max7219CWG CLK  | D11  
Max7219CWG DIN  | D12  
LED 1           | D13  
LED 2 to LED 65 | Max7219CWG  
  