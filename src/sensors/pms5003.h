#ifndef _PMS5003_H
#define _PMS5003_H

#include "const.h"
#include <Arduino.h>
#include <ArduinoJson.h>
#include <SoftwareSerial.h>

#include "pms_packet.h"

class PMS5003 {
public:
  PMS5003(SoftwareSerial &);
  bool probe();
  void begin();
  bool read();
  bool readUntilSuccessful(int);
  void sleep();
  void wake_up(bool force=false);
  bool report(JsonArray &, DynamicJsonBuffer &);
private:
  bool detected;
  SoftwareSerial &uart;
  PMSPacket packet;
};

#endif
