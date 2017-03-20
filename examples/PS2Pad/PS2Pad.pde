#include <stdio.h>
#include <PSXPad.h>

byte lbAttPinNos[] = {2};
PSXPad_KeyState_t tKeyState;
char strString[256];

void setup() {
  Serial.begin(115200);
  PSXPads.begin(1, lbAttPinNos);
  PSXPads.lpcPads[0]->SetADMode(true, true);  // into analog mode and lock.
}

void loop() {
  PSXPads.Pool();
  PSXPads.lpcPads[0]->GetKeyState(&tKeyState);
  sprintf(strString, "LX:%02X LY:%02X RX:%02X RY:%02X U:%02X D:%02X L:%02X R:%02X Tri:%02X Sqr:%02X Crs:%02X Cir:%02X L1:%02X R1:%02X L2:%02X R2:%02X\r\n",
    tKeyState.bLX,
    tKeyState.bLY,
    tKeyState.bRX,
    tKeyState.bRY,
    tKeyState.bAU,
    tKeyState.bAD,
    tKeyState.bAL,
    tKeyState.bAR,
    tKeyState.bATri,
    tKeyState.bASqr,
    tKeyState.bACrs,
    tKeyState.bACir,
    tKeyState.bAL1,
    tKeyState.bAR1,
    tKeyState.bAL2,
    tKeyState.bAR2
  );
  Serial.print(strString);
}
