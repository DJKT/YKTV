#include "audio.h"
struct config_type
{
  int EEPROM_music_num;       //歌曲的数目
  int EEPROM_music_vol;       //歌曲的音量
};


int music2_Pin = 6;//按键控制引脚定义
int pinBuzzer=10;//管脚D3接到蜂鸣器

boolean play_pause;
boolean play_change;//定义boolean型变量
int music_num = 1;    //歌曲序号
int music_vol=30;

#include <ESP8266.h>

#ifdef ESP32
#error "This code is not recommended t························· o run on the ESP32 platform! Please check your Tools->Board setting."
#endif

/**
**CoreUSB UART Port: [Serial1] [D0,D1]
**Core+ UART Port: [Serial1] [D2,D3]
**/
#if defined(__AVR_ATmega32U4__) || defined(__AVR_ATmega1284P__) || defined (__AVR_ATmega644P__) || defined(__AVR_ATmega128RFA1__)
#define EspSerial Serial1
#define UARTSPEED  115200
#endif

/**
**Core UART Port: [SoftSerial] [D2,D3]
**/
#if defined (__AVR_ATmega168__) || defined (__AVR_ATmega328__) || defined (__AVR_ATmega328P__)
#include <SoftwareSerial.h>
SoftwareSerial mySerial1(2, 3); /* RX:D2, TX:D3 */

#define EspSerial mySerial1
#define UARTSPEED  9600
#endif

#define SSID        F("OPPO R15")
#define PASSWORD    F("djzm0701")
#define HOST_NAME   F("api.heclouds.com")
#define HOST_PORT   (80)
#define DEVICEID    "508870000" //OneNet上的设备ID
String apiKey = "iBGjCGF2iZcFI1KllNtlb5Xc5Hk=";
String jsonToSend;
String postString;



char shijian1[23] = {'0'}, shijian2[23] = {'0'};



static const byte  GETDATA[]  PROGMEM = {
  "GET https://api.heclouds.com/devices/508870000/datapoints?datastream_id=Humidity&limit=1 HTTP/1.1\r\nHost:api.heclouds.com\r\napi-key:iBGjCGF2iZcFI1KllNtlb5Xc5Hk=\r\nConnection: close\r\n\r\n"
};

ESP8266 wifi(&EspSerial);

void setup(void)
{
  
  Serial.begin(9600);

  pinMode(pinBuzzer, OUTPUT);
  pinMode(music2_Pin, INPUT);


  audio_pause();

  audio_init(DEVICE_Flash, MODE_loopOne, 9);




  while (!Serial); // wait for Leonardo enumeration, others continue immediately
  Serial.print(F("setup begin\r\n"));
  delay(100);




  WifiInit(EspSerial, UARTSPEED);

  Serial.print(F("FW Version:"));
  Serial.println(wifi.getVersion().c_str());

  if (wifi.setOprToStationSoftAP()) {
    Serial.print(F("to station + softap ok\r\n"));
  } else {
    Serial.print(F("to station + softap err\r\n"));
  }

  if (wifi.joinAP(SSID, PASSWORD)) {
    Serial.print(F("Join AP success\r\n"));

    Serial.print(F("IP:"));
    Serial.println( wifi.getLocalIP().c_str());
  } else {
    Serial.print(F("Join AP failure\r\n"));
  }

  if (wifi.disableMUX()) {
    Serial.print(F("single ok\r\n"));
  } else {
    Serial.print(F("single err\r\n"));
  }

  Serial.print(F("setup end\r\n"));
}

void loop(void)
{
  if (wifi.createTCP(HOST_NAME, HOST_PORT)) {
    Serial.print(F("create tcp ok\r\n"));
  } else {
    Serial.print(F("create tcp err\r\n"));
  }

  //char *hello = "GET /testwifi/index.html HTTP/1.0\r\nHost: www.adafruit.com\r\nConnection: close\r\n\r\n";
  //wifi.send((const uint8_t*)hello, strlen(hello));  //直接发送

  wifi.sendFromFlash(GETDATA, sizeof(GETDATA)); //从Flash读取发送内容，节约内存
  char a = '0';
  uint8_t buffer[512] = {0};
  uint32_t len = wifi.recv(buffer, sizeof(buffer), 20000);
  if (len > 0) {
    Serial.print(F("Received:["));
    for (uint32_t i = 0; i < len; i++) {
      Serial.print((char)buffer[i]);
    }
    Serial.print(F("]\r\n"));

    for (uint32_t i = 0; i < len - 12; i++) {
      if ((char)buffer[i] == 'v' && (char)buffer[i + 1] == 'a' && (char)buffer[i + 2] == 'l' && (char)buffer[i + 3] == 'u' && (char)buffer[i + 4] == 'e')
      {

        a = buffer[i + 8];
      }
    }

    for (uint32_t i = 0; i < len ; i++) {
      if ((char)buffer[i - 1] == '"' && (char)buffer[i] == 'a' && (char)buffer[i + 1] == 't' && (char)buffer[i + 2] == '"' && (char)buffer[i + 3] == ':')
      {
        for (int j = 0; j < 23; j++)
        { shijian1[j] = buffer[i + 5 + j];
          Serial.print((char)shijian1[j]);
        }
      }
    }
    int sum = 0;
    for (int j = 0; j < 22; j++)
    {
      if (shijian1[j] != shijian2[j])
        sum++;
    }
    if (sum == 0)
      a = '0';


    Serial.print(F("]\r\n"));
  }

  if (wifi.releaseTCP()) {
    Serial.print(F("release tcp ok\r\n"));
  } else {
    Serial.print(F("release tcp err\r\n"));
  }
 Serial.println(a);
 if (a == '1')//设置闹钟
  {
    delay(600000);
   long frequency=1400;
   tone(pinBuzzer,frequency);
   delay(5000);
   noTone(pinBuzzer);
   delay(1000);
  }
  if (a == '2')//设置闹钟
  {
    delay(1200000);
   long frequency=1400;
   tone(pinBuzzer,frequency);
   delay(5000);
   noTone(pinBuzzer);
   delay(1000);
  }
   if (a == '3')//设置闹钟
  {
    delay(1800000);
   long frequency=1400;
   tone(pinBuzzer,frequency);
   delay(5000);
   noTone(pinBuzzer);
   delay(1000);
  }
   if (a == '4')//设置闹钟
  {
    delay(2400000);
  long frequency=1400;
   tone(pinBuzzer,frequency);
   delay(5000);
   noTone(pinBuzzer);
   delay(1000);
  }
  if (a == '5')//设置闹钟
  {
    delay(3000000);
   long frequency=1400;
   tone(pinBuzzer,frequency);
   delay(5000);
   noTone(pinBuzzer);
   delay(1000);
  }
  if (a == '6')//设置闹钟
  {
    delay(3600000);
  long frequency=1400;
   tone(pinBuzzer,frequency);
   delay(5000);
   noTone(pinBuzzer);
   delay(1000);
  }
  if (a == '7')//设置泡澡
  {
    audio_play();
    delay(600000);
   audio_pause();
   delay(1000);
  }
  if (a == '9')//设置泡澡
  {
    audio_play();
    delay(1200000);
   audio_pause();
   delay(1000);
  }
  if (a == 'v')//设置泡澡
  {
    audio_play();
    delay(1800000);
   audio_pause();
   delay(1000);
  }
  if (a == 'u')//设置泡澡
  {
    audio_play();
    delay(2400000);
   audio_pause();
   delay(1000);
  }
  if (a == 's')//设置泡澡
  {
    audio_play();
    delay(3000000);
   audio_pause();
   delay(1000);
  }
  if (a == 'f')//设置泡澡
  {
    audio_play();
    delay(3600000);
   audio_pause();
   delay(1000);
  }
 if (a == '8')
  {
    audio_play();
  }
  if (a == 'a')
  {
   audio_pause();
  }
  if (a == 'b')
  {
    music_num++;  //歌曲序号加
    if (music_num > 9)  //限制歌曲序号范围，如果歌曲序号大于9
    {
      music_num = 1; //歌曲序号返回1
    }
    audio_choose(music_num);
    audio_play();

  }
  delay(1000);

  for (int j = 0; j < 23; j++)
  { shijian2[j] = shijian1[j];
    Serial.print((char)shijian2[j]);
  }
}





