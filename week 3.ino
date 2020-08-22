#include<EEPROM.h>
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

int address;
int dataToWrite;

void loop() {
  // put your main code here, to run repeatedly:
  String buffer = "";
  buffer = Serial.readString();
  if (buffer.startWith("read"))
  {
    address = buffer.substring(buffer.indexOf(' ')+ 1).toInt();
    Serial.print("Program Ready to read from ");
    Serial.print(address);
    Serial.println();
    Serial.println(EEPROM.read(address));
    }
    
    else if (buffer.substring("write"))
    {
      address = buffer.substring(6,7).toint();
      dataToWrite = buffer.substring(8).toint();
      Serial.print("ready to write ");
      Serial.print(dataToWrite);
      Serial.println();
      Serial.print("to address ");
      Serial.print(address);
      Serial.println();
      EEPROM.write(address,datatoWrite);      
    }
}
