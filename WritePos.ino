/*
The normal write example passed the test in ST3215/ST3020/ST3025 Servo, 
and if testing other models of ST series servos
please change the appropriate position, speed and delay parameters.
*/

#include <SCServo.h>

SMS_STS st;

// the uart used to control servos.
// GPIO 18 - S_RXD, GPIO 19 - S_TXD, as default.
int BUTTON_PIN = 4;
#define S_RXD 2
#define S_TXD 3


void setup()
{
  //Serial.begin(115200);
  Serial.begin(1000000);
  st.pSerial = &Serial;
  delay(1000);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop()
{
  if(digitalRead(BUTTON_PIN) == LOW){
    st.WritePosEx(1, 4095, 3400, 50);//servo(ID1) speed=3400，acc=50，move to position=4095.
    delay(2000);
    
    st.WritePosEx(1, 2000, 1500, 50);//servo(ID1) speed=3400，acc=50，move to position=2000.
    delay(2000);
  }
}
