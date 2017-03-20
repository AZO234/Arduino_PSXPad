PSX(PS1/2) pad library by AZO
=============================
version: v1.0.0(Mar 19, 2017)  
http://domisan.sakura.ne.jp/

PSX(PS1/PS2) pads connect with SPI bus.  
Other than Attention(SS), almost wire is common.  

All PSX pad can be gotton digital keys state.(PSXPAD_KEYSTATE_DIGITAL)  
PS1(with analog) pad can be  gotton analog stick value.(PSXPAD_KEYSTATE_ANALOG1)  
PS2 pad can be gotton analog key value.(PSXPAD_KEYSTATE_ANALOG2)  

Pins connection
---------------
PSX(PS1/2) controler pins (not PSX's socket, pad side)  
 123 456 789  
(...|...|...)  

[for Arduino]  
1 : DAT -> Arduino MISO [need pullup by 1k owm registor to 5V]  
2 : CMD -> Arduino MOSI  
3 : 9V (for motor, If you not necessary NC)  
4 : GND  
5 : 3.3V  
6 : Attention -> Arduino DigitalPin  
7 : SCK -> Arduino SCK  
8 : NC (Non Conect)  
9 : ACK -> (Not use)  

[for ATmega88P/168P/328P 3.3V powered]  
1 : DAT -> MISO [need pullup 1k owm registor to 3.3V]  
2 : CMD -> MOSI  
3 : 9V (for motor, If you not necessary NC)  
4 : GND  
5 : 3.3V  
6 : SEL -> DigitalPin  
7 : SCK -> SCK  
8 : NC (Non Conect)  
9 : ACK -> (Not use)  

Reference
---------
- Interfacing a PS2 (PlayStation 2) Controller - CuriousInventor Tutorials  
http://store.curiousinventor.com/guides/PS2/

