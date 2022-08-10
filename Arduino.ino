
#include <BoltIoT-Arduino-Helper.h>
# define left_motor1    6
# define left_motor2    7
# define right_motor1   8
# define right_motor2   9
#define PWMmotorL 5
#define PWMmotorR 10
 
 int valuePWML=100;
 int valuePWMR=100;

String command = "";
int delay_time = 2500;

String forward(String *data) {
  command = "FORWARD";
  digitalWrite(left_motor1,LOW);
  digitalWrite(left_motor2,HIGH);
  digitalWrite(right_motor1,LOW);
  digitalWrite(right_motor2,HIGH);
  analogWrite(PWMmotorL, valuePWML);
  analogWrite(PWMmotorR, valuePWMR);
  delay(delay_time);
  digitalWrite(left_motor2,LOW);
  digitalWrite(left_motor1,LOW);
  digitalWrite(right_motor1,LOW);
  digitalWrite(right_motor2,LOW);
  return "Success:Forward";
}

String backward(String *data) {
  command = "BACKWARD";
  digitalWrite(left_motor1,HIGH);
  digitalWrite(left_motor2,LOW);
  digitalWrite(right_motor1,HIGH);
  digitalWrite(right_motor2,LOW);
  analogWrite(PWMmotorL, valuePWML);
  analogWrite(PWMmotorR, valuePWMR);
  delay(delay_time);
  digitalWrite(left_motor2,LOW);
  digitalWrite(left_motor1,LOW);
  digitalWrite(right_motor1,LOW);
  digitalWrite(right_motor2,LOW);
  return "Success:Backward";
}

String right(String *data) {
  command = "RIGHT";
  digitalWrite(left_motor1,LOW);
  digitalWrite(left_motor2,HIGH);
  digitalWrite(right_motor1,HIGH);
  digitalWrite(right_motor2,LOW);
  analogWrite(PWMmotorL, valuePWML);
  analogWrite(PWMmotorR, valuePWMR);
  delay(delay_time);
  digitalWrite(left_motor2,LOW);
  digitalWrite(left_motor1,LOW);
  digitalWrite(right_motor1,LOW);
  digitalWrite(right_motor2,LOW);
  return "Success:Right";
}

String left(String *data) {
  command = "LEFT";
  digitalWrite(left_motor1,HIGH);
  digitalWrite(left_motor2,LOW);
  digitalWrite(right_motor1,LOW);
  digitalWrite(right_motor2,HIGH);
  analogWrite(PWMmotorL, valuePWML);
  analogWrite(PWMmotorR, valuePWMR);
  delay(delay_time);
  digitalWrite(left_motor2,LOW);
  digitalWrite(left_motor1,LOW);
  digitalWrite(right_motor1,LOW);
  digitalWrite(right_motor2,LOW);
  return "Success:Left";
}

String stop(String *data) {
    command = "STOP";
  digitalWrite(left_motor2,LOW);
  digitalWrite(left_motor1,LOW);
  digitalWrite(right_motor1,LOW);
  digitalWrite(right_motor2,LOW);
  return "Success:Stop";
}

void setup() {
 
  pinMode(left_motor1,OUTPUT);
  pinMode(left_motor2,OUTPUT);
  pinMode(right_motor1,OUTPUT);
  pinMode(right_motor2,OUTPUT);
  pinMode(PWMmotorL,OUTPUT);
  pinMode(PWMmotorR,OUTPUT);

  boltiot.begin(Serial);
  Serial.begin(9600);
  boltiot.setCommandString("FORWARD",forward);
  boltiot.setCommandString("BACKWARD",backward);
  boltiot.setCommandString("LEFT",left);
  boltiot.setCommandString("RIGHT",right);
  boltiot.setCommandString("STOP",stopcar);
}

void loop() {
  boltiot.handleCommand();
}
