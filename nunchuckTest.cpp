#include <Wire.h> //I2C Bibliothek einbinden
#include <wiinunchuck.h> //Nunchuk Bibliothek einbinden
void setup() {
  Serial.begin(9600); //serielle Kommunikation starten
  nunchuk_init(); //Nunchuk initialisieren
  delay(100); //100ms warten
  nunchuk_calibrate_joy(); //Nunchuk kalibrieren
  delay(100); //100ms warten
  
}

void loop() {
  nunchuk_get_data();
  char buffer[25];
  sprintf(buffer,"X:%3d Y:%3d Z:%1d C:%1d ",     
  nunchuk_cjoy_x(),nunchuk_cjoy_y(), nunchuk_zbutton(), nunchuk_cbutton());
  Serial.println(buffer);
  delay(50);
  }
