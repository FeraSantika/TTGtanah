// #include "BluetoothSerial.h"
// #if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
// #error Bluetooth is not enabled! Please run `make menuconfig` to and
// enable it
// #endif
// BluetoothSerial SerialBT;
// void setup() {
// Serial.begin(115200);
// SerialBT.begin("ESP32"); //Bluetooth device name
// Serial.println("The device started, now you can pair it with bluetooth!");
// }
// void loop() {
//   if (Serial.available()) {
//       SerialBT.write(Serial.read());
//   }
//   if (SerialBT.available()) {
//       Serial.write(SerialBT.read());
//   }
//       delay(20);
// }
#include <Servo.h>
#define AOUT_PIN 34 // Arduino pin that connects to AOUT pin of moisture sensor
#define SERVO_PIN 13

Servo servo;

void setup() {
  Serial.begin(9600);
  servoMotor.attach(SERVO_PIN);
}

void loop() {
  int value = analogRead(AOUT_PIN); // read the analog value from sensor
  float kelembaban = (100 - (value * 0.0244)); //Rumus kelembaban = (100 - (Nilai ADC x resolusi bit pada ESP)); Nilai ADC = value

  Serial.print("kelembaban: "); 
  Serial.print(kelembaban);
  Serial.print("%\n\n");
  delay(500);

  if (kelembaban <= 19 )
  {
    (pos = 0; pos <= 90; pos += 1){
      servoMotor.write(pos);
      delay(1000);
    }
  }else if (kelembaban >19 ){
     (pos = 90; pos <= 0; pos -= 1){
      servoMotor.write(pos);
      delay(1000);
     }
  }
}
