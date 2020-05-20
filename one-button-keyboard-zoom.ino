#include "Keyboard.h"

#define PIN_KEYSW (9)

int prevKeyState;
int currKeyState;

void setup() {
 pinMode(PIN_KEYSW, INPUT_PULLUP);
 prevKeyState = HIGH;
 currKeyState = HIGH;

 Keyboard.begin();
}

void loop() {
 currKeyState = digitalRead(PIN_KEYSW);

 // キースイッチが押された
 if ((prevKeyState == HIGH) && (currKeyState == LOW)) {

   delay(500); // 長押し判定
   if(digitalRead(PIN_KEYSW) == HIGH) {

     // 短押しの場合は音声OFF/ON [Alt]+[a]
     Keyboard.press(KEY_LEFT_ALT);  // [Alt]を押す
     Keyboard.press('a');            // [a]を押す
     delay(10);                      // 10ms待つ
     Keyboard.releaseAll();          // すべて放す
     
   } else {
     // 長押しの場合はビデオOFF/ON [Alt]+[v]
     Keyboard.press(KEY_LEFT_ALT);  // [Alt]を押す
     Keyboard.press('v');            // [v]を押す
     delay(10);                      // 10ms待つ
     Keyboard.releaseAll();          // すべて放す
   }

 }
 prevKeyState = currKeyState;
 delay(10);
}
