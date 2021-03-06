#ifndef _PMS_PACKET_H
#define _PMS_PACKET_H

#include <Arduino.h>

class PMSPacket {
public:
  PMSPacket();
  bool is_valid();
  void reset();
  float pm1();
  float pm25();
  float pm10();
private:
  uint16_t calculated_checksum();
  byte start1;
  byte start2;
  byte framelen_hi;
  byte framelen_lo;
  byte pm1_hi; // Data1 refers to PM1.0 concentration unit μg/m3（CF=1，standard particle
  byte pm1_lo;
  byte pm25_hi; // Data2 refers to PM2.5 concentration unit μg/m3（CF=1，standard particle）
  byte pm25_lo;
  byte pm10_hi; // Data3 refers to PM10 concentration unit μg/m3（CF=1，standard particle）
  byte pm10_lo;
  byte pm1_atm_hi; // Data4 refers to PM1.0 concentration unit μg/m3（under atmospheric environment）
  byte pm1_atm_lo;
  byte pm25_atm_hi; // Data 5 refers to PM2.5 concentration unit μg/m3（under atmospheric environment）
  byte pm25_atm_lo;
  byte pm10_atm_hi; // Data 6 refers to concentration unit (under atmospheric environment) μg/m3
  byte pm10_atm_lo;
  byte np3_hi; // Data7 indicates the number of particles with diameter beyond 0.3 um in 0.1 L of air.
  byte np3_lo;
  byte np5_hi; // Data 8 indicates the number of particles with diameter beyond 0.5 um in 0.1 L of air.
  byte np5_lo;
  byte np10_hi;
  byte np10_lo;
  byte np25_hi;
  byte np25_lo;
  byte np50_hi;
  byte np50_lo;
  byte np100_hi;
  byte np100_lo;
  byte _reserved1;
  byte _reserved2;
  byte checksum_hi;
  byte checksum_lo;
} __attribute__ ((packed)) ;

#endif
