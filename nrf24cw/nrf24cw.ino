#include <SPI.h>
#include "RF24.h"

int button_pin = 2;
int led_pin = 3;
int id_1 = 4;
int id_2 = 5;
int id_4 = 6;

// Building on https://tmrh20.github.io/RF24/GettingStarted_8ino-example.html

int radioNumber = 0;
/* Hardware configuration: Set up nRF24L01 radio on SPI bus plus pins 7 & 8 */
RF24 radio(7,8);  // CE, CSN

const byte addresses [][6] = {"00001", "00002"};  //Setting the two addresses. One for transmitting and one for receiving

boolean button_state = 0;
boolean remote_state = 0;

void setup() {
  pinMode( button_pin, INPUT_PULLUP );
  attachInterrupt(digitalPinToInterrupt(button_pin), key_change, CHANGE);
  pinMode( led_pin, OUTPUT );
  pinMode( id_1, INPUT_PULLUP );
  pinMode( id_2, INPUT_PULLUP );
  pinMode( id_4, INPUT_PULLUP );

  Serial.begin(9600);
  Serial.println(F("RF24 CW"));

  radioNumber = 
    1 * digitalRead( id_1 ) + 
    2 * digitalRead( id_2 ) + 
    4 * digitalRead( id_4 ) ;

  Serial.print( "Radio number: " );
  Serial.println( radioNumber );
  
  radio.begin();

  // Set up the pipes. For now, assume two radios with bidirectional communication
  if ( radioNumber == 0 ){
    radio.openWritingPipe(addresses[0]);
    radio.openReadingPipe(1, addresses[1]);
  }
  else{
    radio.openWritingPipe(addresses[1]);
    radio.openReadingPipe(1, addresses[0]);    
  }
  
  radio.setPALevel( RF24_PA_LOW );
  

}

// Monitor for traffic
void loop() {
  delay(5);
  radio.startListening();
  if ( radio.available()) {
    radio.read(&remote_state, sizeof(remote_state));
    update_indicator();
  }
}

// Called whenever the local button changes
// Based on https://www.arduino.cc/reference/en/language/functions/external-interrupts/attachinterrupt/
void key_change() {
    radio.stopListening();
    button_state = ! digitalRead( button_pin );
    radio.write(&button_state, sizeof(button_state));

    radio.printDetails();
    update_indicator();
}

// Called to update local status indicator
void update_indicator() {
  Serial.print( "Local button: " );
  Serial.println( button_state );
  Serial.print( "Remote button: " );
  Serial.println( remote_state );
  if ( button_state or remote_state ){
    digitalWrite(led_pin, HIGH);
  } else {
    digitalWrite(led_pin, LOW);
  }
}
