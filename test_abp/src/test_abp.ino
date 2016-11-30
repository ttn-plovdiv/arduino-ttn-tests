#include <Arduino.h>
#include <rn2xx3.h>
#include <SoftwareSerial.h>
#include <Credentials.h>

#define LED_PIN 9
#define RX_PIN 10
#define TX_PIN 11
#define RN_RESET_PIN 12
#define LOOP_DELAY 5000

SoftwareSerial loraSerial(RX_PIN, TX_PIN);
rn2xx3 myLora(loraSerial);

void setup()
{
  pinMode(LED_PIN, OUTPUT);
  led_on();

  Serial.begin(57600); //serial port to computer
  loraSerial.begin(9600); //serial port to radio
  Serial.println("Starting ...");

  initialize_radio();

  myLora.tx("Radio setup");
  delay(2000);

  led_off();
}

void led_on()
{
  digitalWrite(LED_PIN, 1);
}

void led_off()
{
  digitalWrite(LED_PIN, 0);
}

void reset_radio()
{
  pinMode(RN_RESET_PIN, OUTPUT);
  digitalWrite(RN_RESET_PIN, LOW);
  delay(500);
  digitalWrite(RN_RESET_PIN, HIGH);
}

void initialize_radio()
{
  reset_radio();
  
  //Autobaud the rn2483 module to 9600. The default would otherwise be 57600.
  myLora.autobaud();

  Serial.println("RN2483 firmware version:");
  Serial.println(myLora.sysver());

  Serial.println("Trying to join TTN ...");
  bool join_result = false;

  join_result = myLora.initABP(DEVICE_ADDRESS, APP_SESSION_KEY, NETWORK_SESSION_KEY);

  while(!join_result)
  {
    Serial.println("Unable to join. Are your keys correct, and do you have TTN coverage?");
    delay(60000);
    join_result = myLora.init();
  }
  Serial.println("Successfully joined TTN");

}

void loop()
{
  led_on();

  Serial.println("Sending");
  myLora.tx("!"); //one byte, blocking function

  led_off();
  delay(LOOP_DELAY);
}
