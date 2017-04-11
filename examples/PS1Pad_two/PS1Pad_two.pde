#include <PSXPad.h>

byte lbAttPinNos[] = {2, 3};
PSXPad_KeyState_t tKeyState;

void setup() {
  Serial.begin(115200);
  PSXPads.begin(2, lbAttPinNos);
}

void loop() {
  PSXPads.pool();
  PSXPads.lpcPads[0]->getKeyState(&tKeyState);
  Serial.print("Pad1: ");
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
  PSXPads.lpcPads[1]->getKeyState(&tKeyState);
  Serial.print("Pad2: ");
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
