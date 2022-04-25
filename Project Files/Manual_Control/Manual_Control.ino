#include <Arduino.h>

#include "PinDefinitionsAndMore.h"

#include <IRremote.hpp>

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);

    Serial.begin(9600);

    // Just to know which program is running on my Arduino
    Serial.println(F("START " __FILE__ " from " __DATE__ "\r\nUsing library version " VERSION_IRREMOTE));

    /*
     * The IR library setup. That's all!
     */
    IrSender.begin(); // Start with IR_SEND_PIN as send pin and if NO_LED_FEEDBACK_CODE is NOT defined, enable feedback LED at default feedback LED pin

    Serial.print(F("Ready to send IR signals at pin "));
    Serial.println(IR_SEND_PIN);
}
uint8_t sRepeats = 0;
//Code in text file
void loop() {
    if(Serial.available() > 0){  //id data is available to read
    char val = Serial.read();

    if(val == 'u'){       //if UP received
      // UP button (2 32-bit hex codes with raw data)
      Serial.println(F("Send NECRaw 0xE619C2EA"));
      IrSender.sendNECRaw(0xE619C2EA, sRepeats);
      Serial.println(F("Send NECRaw 0x6699C2EA"));
      IrSender.sendNECRaw(0x6699C2EA, sRepeats);
      Serial.println(F("UP"));
      }
    if(val == 'd'){       //if b received
      // DOWN button (2 32-bit hex codes with raw data;
      Serial.println(F("Send NECRaw 0x6699C2EA"));
      IrSender.sendNECRaw(0xCC33C2EA, sRepeats);
      Serial.println(F("DOWN"));
      }
    if(val == 'l'){       //if y received
      // LEFT button (2 32-bit hex codes with raw data;
      Serial.println(F("Send NECRaw 0xE11EC2EA"));
      IrSender.sendNECRaw(0xE11EC2EA, sRepeats);
      Serial.println(F("LEFT"));
      }
    if(val == 'r'){       //if f received
      // RIGHT button (2 32-bit hex codes with raw data;
      Serial.println(F("Send NECRaw 0xD22DC2EA"));
      IrSender.sendNECRaw(0xD22DC2EA, sRepeats);
      Serial.println(F("RIGHT"));
      }
    if(val == 'k'){       //if f received
      // OK button (2 32-bit hex codes with raw data)
      Serial.println(F("Send NECRaw 0xD52AC2EA"));
      IrSender.sendNECRaw(0xD52AC2EA, sRepeats);
      Serial.println(F("Send NECRaw 0x55AAC2EA"));
      IrSender.sendNECRaw(0x55AAC2EA, sRepeats);
      Serial.println(F("OK"));
      } 
      if(val == 'a'){       //if b received
      // This code opens Amazon Prime
      //0x6F90C2EA
      Serial.println(F("Send NECRaw 0xF00FC2EA"));
      IrSender.sendNECRaw(0x6F90C2EA, sRepeats);
      }
    if(val == 'n'){       //if y received
      // NETFLIX button (2 32-bit hex codes with raw data;
      Serial.println(F("Send NECRaw 0xB44BC2EA"));
      IrSender.sendNECRaw(0xB44BC2EA, sRepeats);
      Serial.println(F("NETFLIX"));
      }
    if(val == 'h'){       //if f received
      // HULU button (2 32-bit hex codes with raw data;
      Serial.println(F("Send NECRaw 0xB24DC2EA"));
      IrSender.sendNECRaw(0xB24DC2EA, sRepeats);
      Serial.println(F("HULU"));
      }
    if(val == 'p'){       //if f received
      // DISNEY button (2 32-bit hex codes with raw data;
      Serial.println(F("Send NECRaw 0xEE11C2EA"));
      IrSender.sendNECRaw(0xEE11C2EA, sRepeats);
      Serial.println(F("DISNEY"));
      }  
    if(val == 'o'){       //if f received
      // HOME button (2 32-bit hex codes with raw data;
      Serial.println(F("Send NECRaw 0xFC03C2EA"));
      IrSender.sendNECRaw(0xFC03C2EA, sRepeats);
      Serial.println(F("HOME"));
      }
    }
    delay(1000);  // delay must be greater than 5 ms (RECORD_GAP_MICROS), otherwise the receiver sees it as one long signal
}
