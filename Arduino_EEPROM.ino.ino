#include <EEPROM.h>


int address = 0,  number = 0 ;

char command;
void setup() {
  Serial.begin(9600);
    while (!Serial) {}
}

void loop() {
  while (Serial.available()) {

  command = Serial.read();
    address = Serial.parseInt();
    number = Serial.parseInt();
  
  switch (command) {
   
    case 'r' :
      // read address.
      number = EEPROM.read(address);
      Serial.print("Read Address ");
      Serial.print(address);
      Serial.print(" --> ");
      Serial.println(number);
      command = '0';
      break;
       case 'w':
      // writes value to address.
      EEPROM.write(address, number);
      Serial.print("Write Address ");
      Serial.print(address);
      Serial.print(" <-- ");
      Serial.println(number);
      command = '0';
      break;
  }
  delay(50);
}}
