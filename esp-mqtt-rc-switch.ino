#include <Homie.h>
#include <RCSwitch.h>

const int PIN_TRANSMITTER = 5;

RCSwitch mySwitch = RCSwitch();
HomieNode RCSwitch1Node("RCSwitch1", "switch");
HomieNode RCSwitch2Node("RCSwitch2", "switch");
HomieNode RCSwitch3Node("RCSwitch3", "switch");

bool RCSwitch1OnHandler(String value) {
  if (value == "true") {
    mySwitch.send(1070387, 24);
    Homie.setNodeProperty(RCSwitch1Node, "on", "true"); // Update the state of the switch
    Serial.println("RC Switch1 is on");
  } else if (value == "false") {
    mySwitch.send(1070396, 24);
    Homie.setNodeProperty(RCSwitch1Node, "on", "false");
    Serial.println("RC Switch1 is off");
  } else {
    return false;
  }
  return true;
}

bool RCSwitch2OnHandler(String value) {
  if (value == "true") {
    mySwitch.send(1070531, 24);
    Homie.setNodeProperty(RCSwitch2Node, "on", "true"); // Update the state of the switch
    Serial.println("RC Switch2 is on");
  } else if (value == "false") {
    mySwitch.send(1070540, 24);
    Homie.setNodeProperty(RCSwitch2Node, "on", "false");
    Serial.println("RC Switch2 is off");
  } else {
    return false;
  }
  return true;
}

bool RCSwitch3OnHandler(String value) {
  if (value == "true") {
    mySwitch.send(1070851, 24);
    Homie.setNodeProperty(RCSwitch3Node, "on", "true"); // Update the state of the switch
    Serial.println("RC Switch3 is on");
  } else if (value == "false") {
    mySwitch.send(1070860, 24);
    Homie.setNodeProperty(RCSwitch3Node, "on", "false");
    Serial.println("RC Switch3 is off");
  } else {
    return false;
  }
  return true;
}

void setup() {
  Serial.begin(115200);
  Serial.println();
  Serial.println();
  pinMode(PIN_TRANSMITTER, OUTPUT);
  // Transmitter is connected to ESP8266 GPIO 5
  mySwitch.enableTransmit(PIN_TRANSMITTER);
  //EtekCity ZAP Remote Outlets use pulse of approximately 189
  mySwitch.setPulseLength(189);
   // Optional set number of transmission repetitions.
  mySwitch.setRepeatTransmit(3);
 
  Homie.setFirmware("esp-mqtt-rc-switch", "1.0.0");
  RCSwitch1Node.subscribe("on", RCSwitch1OnHandler);
  RCSwitch2Node.subscribe("on", RCSwitch2OnHandler);
  RCSwitch3Node.subscribe("on", RCSwitch3OnHandler);
  Homie.registerNode(RCSwitch1Node);
  Homie.registerNode(RCSwitch2Node); 
  Homie.registerNode(RCSwitch3Node); 
  
  Homie.setup();
}

void loop() {
  Homie.loop();
}
