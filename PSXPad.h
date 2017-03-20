#ifndef _PSXPAD_H_
#define _PSXPAD_H_

/*
====================================================
 PSX(PS1/2) pad library by AZO v1.0.0(Mar 19, 2017)
====================================================

About PSX pad library
---------------------
  This is PSX(PS1/2) pad library.
  PSX pads connect with SPI bus(LSBFIRST, MODE_3).
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

Initialise and use
------------------

  Using a PSX pad use, see next code.

******************************
#include <PSXPad.h>

byte lbAttPinNos[] = {2};  // Assign Attention pinNos. Attention is DigitalPin.2
PSXPad_KeyState_t tKeyState;

void setup() {
  Serial.begin(115200);  // for UART (UART uses DigitalPin.0 and 1)
  PSXPads.begin(1, lbAttPinNos);  // one PSX pad
}

void loop() {
  PSXPads.Pool();
  PSXPads.lpcPads[0]->GetKeyState(&tKeyState);  // get No.1 pad's key state.
  if(tKeyState.bSel) Serial.print("Sel ");
  if(tKeyState.bL3) Serial.print("L3 ");
  if(tKeyState.bR3) Serial.print("R3 ");
  if(tKeyState.bStt) Serial.print("Stt ");
  if(tKeyState.bU) Serial.print("U ");
  if(tKeyState.bR) Serial.print("R ");
  if(tKeyState.bD) Serial.print("D ");
  if(tKeyState.bL) Serial.print("L ");
  if(tKeyState.bL2) Serial.print("L2 ");
  if(tKeyState.bR2) Serial.print("R2 ");
  if(tKeyState.bL1) Serial.print("L1 ");
  if(tKeyState.bR1) Serial.print("R1 ");
  if(tKeyState.bTri) Serial.print("Tri ");
  if(tKeyState.bCir) Serial.print("Cir ");
  if(tKeyState.bCrs) Serial.print("Crs ");
  if(tKeyState.bSqr) Serial.print("Sqr ");
  Serial.print("\r\n");
}
******************************

  Using two PSX pads use, see next code.

******************************
#include <PSXPad.h>

byte lbAttPinNos[] = {2, 3};  // No.1's attention is DigitalPin.2. No.2's attention is DigitalPin.3
PSXPad_KeyState_t ltKeyState[2];

void setup() {
  Serial.begin(115200);
  PSXPads.begin(2, lbAttPinNos);  // two PSX pad
}

void loop() {
  PSXPads.Pool();
  PSXPads.lpcPads[0]->GetKeyState(&tKeyState[0]);  // get No.1 pad's key state.
  PSXPads.lpcPads[1]->GetKeyState(&tKeyState[1]);  // get No.2 pad's key state.

  ...
}
******************************

  Setting analog mode, see next code.

******************************
#include <PSXPad.h>

byte lbAttPinNos[] = {2};

void setup() {
  PSXPads.begin(1, lbAttPinNos);
  PSXPads.lpcPads[0]->SetADMode(true, false); // analog mode, no lock
}
******************************

  To rumble motor, see next code. (need supply 9V to pad)

******************************
#include <PSXPad.h>

byte lbAttPinNos[] = {2};

void setup() {
  PSXPads.begin(1, lbAttPinNos);
  PSXPads.lpcPads[0]->SetMotorLevel(0xFF, 0xFF); // small(0 or other), large(0-255) 
  PSXPads.lpcPads[0]->SetEnableMotor(true, true, true); // enable both motor, immediately
}
******************************
*/

#include <Arduino.h>

extern class PSXPads PSXPads;

typedef enum {
  PSXPAD_KEYSTATE_DIGITAL = 0,
  PSXPAD_KEYSTATE_ANALOG1,
  PSXPAD_KEYSTATE_ANALOG2,
  PSXPAD_KEYSTATE_UNKNOWN
} PSXPad_KeyStateType_t;

typedef struct PSXPad_KeyState {
  PSXPad_KeyStateType_t vType;
  /* PSXPAD_KEYSTATE_DIGITAL */
  boolean bSel;
  boolean bStt;
  boolean bU;
  boolean bR;
  boolean bD;
  boolean bL;
  boolean bL2;
  boolean bR2;
  boolean bL1;
  boolean bR1;
  boolean bTri;
  boolean bCir;
  boolean bCrs;
  boolean bSqr;
  /* PSXPAD_KEYSTATE_ANALOG1 */
  boolean bL3;
  boolean bR3;
  byte bRX;
  byte bRY;
  byte bLX;
  byte bLY;
  /* PSXPAD_KEYSTATE_ANALOG2 */
  byte bAR;
  byte bAL;
  byte bAU;
  byte bAD;
  byte bATri;
  byte bACir;
  byte bACrs;
  byte bASqr;
  byte bAL1;
  byte bAR1;
  byte bAL2;
  byte bAR2;
} PSXPad_KeyState_t;

/* PSX pad class */
class PSXPad {
public:
  PSXPad(const byte i_bAttPinNo);
  void Pool(void);
  void SetADMode(const boolean i_bAnalog, const boolean i_bLock);
  void SetEnableMotor(const boolean i_bMotor1Enable, const boolean i_bMotor2Enable);
  void SetMotorLevel(const byte i_bMotor1Level, const byte i_bMotor2Level, const boolean i_bPool);
  void GetKeyState(PSXPad_KeyState_t* ptKeyState);

private:
  byte bAttPinNo;
  boolean bAnalog;
  boolean bLock;
  boolean bMotor1Enable;
  boolean bMotor2Enable;
  byte bMotor1Level;
  byte bMotor2Level;
  byte lbResponse[21];
  byte lbPoolCmd[21];
  byte lbEnableMotor[9];
  byte lbADMode[9];

  void Command(const byte i_lbSendCmd[], const byte i_bSendCmdLen);
};

/* PSX pads class */
class PSXPads {
public:
  void begin(const byte i_bPadNum, const byte i_lbAttPinNos[]);
  ~PSXPads(void);
  class PSXPad** lpcPads;
  void Pool(void);

private:
  byte bPadNum;
};

#endif /* _PSXPAD_H_ */

