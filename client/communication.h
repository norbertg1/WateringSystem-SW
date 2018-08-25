#ifndef COM_H
#define COM_H

#include "client.h"

void mqtt_callback(char* topic, byte* payload, unsigned int length);
void mqtt_reconnect();
void setup_wifi();
void start_wifimanager();
void web_update_setup();
void web_update(long long minutes);
void send_log();
void mqttsend_d(double payload, char* device_id, char* topic, char precision);
void mqttsend_i(int payload, char* device_id, char* topic);
void mqttsend_s(char *payload, char* device_id, char* topic);
uint32_t calculateCRC32( const uint8_t *data, size_t length );
String getSsidPass( String s );

// The ESP8266 RTC memory is arranged into blocks of 4 bytes. The access methods read and write 4 bytes at a time,
// so the RTC data structure should be padded to a 4-byte multiple.
struct {
  uint32_t crc32;   // 4 bytes
  uint8_t channel;  // 1 byte,   5 in total
  uint8_t bssid[6]; // 6 bytes, 11 in total
  time_t  epoch;    // 4 bytes  15 in total
  uint8_t valid;    // 1 byte,  16 in total
  //uint8_t padding;  // 1 byte,  12 in total
  
} rtcData;

#endif