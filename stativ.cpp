#include <Wire.h> //I2C Bibliothek einbinden
#include <Servo.h> //Servo Bibliothek einbinden
#include <wiinunchuck.h> //Nunchuck Bibliothek einbinden
 
Servo horizontalservo; // Servo Links-Rechts = Pan = Roll
Servo vertikalservo; // Servo Oben-Unten = Tilt = Pitch
  
float horizontalPos = 90.0; // Aktuelle Position
float vertikalPos = 90.0; // Aktuelle Position
 
void setup(){
 
 Serial.begin(9600);
 
 nunchuk_init();
 delay(100);
 nunchuk_get_data();
 delay(100); 
 
 horizontalservo.attach(5); //Pan-Servo an Pin 5
 vertikalservo.attach(6); //Tilt-Servo an Pin 6
 delay(10);
 horizontalservo.write(horizontalPos); //Servo in Grundstellung
 vertikalservo.write(vertikalPos); //Servo in Grundstellung
 
}
 
void loop(){
 
 nunchuk_get_data(); // Daten vom Nunchuk empfangen
 delay(10);
 
 if (nunchuk_zbutton() == 1) { //Wenn Z-Taste gedrückt,horizontale Bewegung
 
 int roll = nunchuk_rollangle();
 horizontalPos = 90+roll*1.5;
 }
 if (nunchuk_cbutton() == 1) { //Wenn C-Taste gedrückt,vertikale Bewegung
  int pitch = nunchuk_pitchangle();
  vertikalPos = 90-pitch*1.5;
 }
 
 char buffer[50]; // String erzeugen
 sprintf(buffer, "X:%3d Y:%3d Z:%3d - Roll: %3d Pitch: %3d", 
 nunchuk_accelx(), nunchuk_accely(), nunchuk_accelz(), nunchuk_rollangle(), nunchuk_pitchangle());
 
 horizontalservo.write((int)horizontalPos);
 vertikalservo.write((int)vertikalPos); 
 
 delay(50); 
}
