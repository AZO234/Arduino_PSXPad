PSX(Play Station 1/2) pad library for Arduino IDE by AZO
========================================================
version: v1.0.2(Apr 12, 2017)  
http://domisan.sakura.ne.jp/

This library is PSX(Play Station 1/2) pads connect with SPI bus for Arduino IDE(Arduino/AVR).  
Other than Attention(SS) almost wire is common, then micro-controler can connect to many pads.  

All PSX pad can be gotten digital keys state.(PSXPAD_KEYSTATE_DIGITAL)  
PS1(with analog) pad can be  gotten analog stick value.(PSXPAD_KEYSTATE_ANALOG1)  
PS2 pad can be gotten analog key value.(PSXPAD_KEYSTATE_ANALOG2)  

Pins connection
---------------
PSX(PS1/2) controler pins (not PSX's socket, pad side)  
 123 456 789  
(...|...|...)  

[for Arduino]  
1 : DAT -> Arduino 12 MISO [need pullup by 1k owm registor to 5V]  
2 : CMD -> Arduino 11 MOSI  
3 : 9V (for motor, If you not necessary NC)  
4 : GND  
5 : 3.3V  
6 : Attention -> Arduino 2 DigitalPin  
7 : SCK -> Arduino 13 SCK  
8 : NC (Non Conect)  
9 : ACK -> (Not use)  

[for ATmega88P/168P/328P 3.3V powered]  
1 : DAT -> 18 MISO [need pullup 1k owm registor to 3.3V]  
2 : CMD -> 17 MOSI  
3 : 9V (for motor, If you not necessary NC)  
4 : GND  
5 : 3.3V  
6 : SEL -> 2 DigitalPin  
7 : SCK -> 19 SCK  
8 : NC (Non Conect)  
9 : ACK -> (Not use)  

Reference
---------
- Interfacing a PS2 (PlayStation 2) Controller - CuriousInventor Tutorials  
http://store.curiousinventor.com/guides/PS2/

