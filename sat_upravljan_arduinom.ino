//Napravio Dominik Žužić, 2019.g.

#include <FastLED.h>
#include "RTClib.h"


#define PIN 3
#define NUM_LEDS 182

RTC_DS3231 rtc;
CRGB leds[NUM_LEDS];


void setup() {
  Serial.begin(9600);
  rtc.begin();
 // rtc.adjust(DateTime(__DATE__, __TIME__));
  //DateTime t = DateTime(rtc.now().unixtime()+10);
  //rtc.adjust(t);
  FastLED.addLeds<WS2812B, PIN, GRB>(leds, NUM_LEDS);

}

void loop() {
  DateTime now = rtc.now();
  int sat = now.hour();
  int minuta = now.minute();

  if(sat>12) {
    sat-=12;
  }
  else {
    sat = now.hour();
  }
 
  Serial.print(sat, DEC);
  Serial.print(":");
  Serial.print(minuta, DEC);
  Serial.print(":");
  Serial.print(now.second(), DEC);
  Serial.println();
  delay(1000);
//-------------------------------------------------------------MINUTE-----MINUTE-----MINUTE-----------------------------------------------------------

  if(minuta==0) {//gasenje minuta/minute ako je 0
    for(int i=0; i<=10; i++) {
      leds[i]=CRGB::Black; FastLED.show();
    }
  }
  
  else if ( (minuta==1) ||
       (minuta>=5 && minuta<=21) ||
       (minuta>=25 && minuta<=31) ||
       (minuta>=35 && minuta<=41) ||
       (minuta>=45 && minuta<=51) ||
       (minuta>=55 && minuta<=59)) {

//paljenje ledica "MINUTA"
        for(int i=0;i<=4;i++) {
          leds[i]=CRGB::FireBrick; FastLED.show();
        }        
//gasenje ledica "MINUTE"
        for(int i=6; i<=10;i++) {
          leds[i]=CRGB::Black; FastLED.show();
        }
       }        

  else if ( (minuta>=2 && minuta<=4) ||
            (minuta>=22 && minuta<=24) ||
            (minuta>=32 && minuta<=34) ||
            (minuta>=42 && minuta<=44) ||
            (minuta>=52 && minuta<=54) ) {

//paljenje ledica "MINUTE"
              for(int i=6; i<=10; i++) {
                leds[i]=CRGB::FireBrick; FastLED.show();
              }              
//gasenje ledica "MINUTA"
              for(int i=0; i<=4; i++) {
                leds[i]=CRGB::Black; FastLED.show();
              }
            }
//-----------------------------------------------------SATI-----SATI-------SATI--------------------------------------------------
//
//
//
//
//------ gasenje 59 minuta-----------
if(minuta==0) {
  leds[141]=CRGB::Black; FastLED.show();
  for(int i=110; i<=115; i++) { //gasenje "PEDESET"
    leds[i]=CRGB::Black; FastLED.show();
  }
  for(int y=25; y<=28; y++) { //gasenje "DEVET"
    leds[y]=CRGB::Black; FastLED.show();
  }
}
else {
  leds[141]=CRGB::FireBrick; FastLED.show();
}

switch (sat) {
  case 1:
    for(int i=175; i<=178; i++) { //paljenje "JEDAN"
      leds[i]=CRGB::FireBrick; FastLED.show();
    }
    for(int x=137; x<=139; x++) { //paljenje "SAT"
      leds[x]=CRGB::FireBrick; FastLED.show();
    }
    for(int y=149; y<=154; y++) { //gasenje "DVANAEST"
      leds[y]=CRGB::Black; FastLED.show();
    }
    for(int z=133; z<=135; z++) { //gasenje "SATI"
      leds[z]=CRGB::Black; FastLED.show();
    }
    break;
    
  case 2:
  for(int i=153; i<=154; i++) { //paljenje "DVA"
    leds[i]=CRGB::FireBrick; FastLED.show();
  }
  for(int y=175; y<=178; y++) { //gasenje "JEDAN"
    leds[y]=CRGB::Black; FastLED.show();
  }
  for(int x=137; x<=140; x++) { //paljenje "SATA"
    leds[x]=CRGB::FireBrick; FastLED.show();
  }
  break;

  case 3:
    for(int i=179; i<=180; i++) { //paljenje "TRI"
      leds[i]=CRGB::FireBrick; FastLED.show(); 
    }
    for(int y=153; y<=154; y++) { //gasenje "DVA"
      leds[y]=CRGB::Black; FastLED.show();
    }
    for(int x=137; x<=140; x++) { //paljenje "SATA"
    leds[x]=CRGB::FireBrick; FastLED.show(); 
  }
    break;

  case 4:
    for(int i=155; i<=158; i++) { //paljenje "ČETIRI"
      leds[i]=CRGB::FireBrick; FastLED.show();
    }
    for(int y=179; y<=180; y++) { //gasenje "TRI"
      leds[y]=CRGB::Black; FastLED.show();
    }
    for(int x=137; x<=140; x++) { //paljenje "SATA"
    leds[x]=CRGB::FireBrick; FastLED.show();
  }
    break;

  case 5:
    for(int i=142; i<=143; i++) { //paljenje "PET"
      leds[i]=CRGB::FireBrick; FastLED.show();
    }
    for(int y=155; y<=158; y++) { //gasenje "ČETIRI"
      leds[y]=CRGB::Black; FastLED.show();
    }
    for(int x=133; x<=135; x++) { //paljenje "SATI"
      leds[x]=CRGB::FireBrick; FastLED.show();
    }
    for(int x=137; x<=140; x++) { //gasenje "SATA"
    leds[x]=CRGB::Black; FastLED.show();
    }
    break;

    case 6:
      for(int i=129; i<=131; i++) { //paljenje "ŠEST"
        leds[i]=CRGB::FireBrick; FastLED.show();
      }
      for(int y=142; y<=143; y++) { //gasenje "PET"
        leds[y]=CRGB::Black; FastLED.show();
      }
      for(int x=133; x<=135; x++) { //paljenje "SATI"
        leds[x]=CRGB::FireBrick; FastLED.show();
      }
      break;

     case 7:
        for(int i=159; i<=163; i++) { //paljenje "SEDAM"
          leds[i]=CRGB::FireBrick; FastLED.show();
        }
        for(int y=129; y<=131; y++) { //gasenje "ŠEST"
          leds[y]=CRGB::Black; FastLED.show();
        }
        for(int x=133; x<=135; x++) { //paljenje "SATI"
          leds[x]=CRGB::FireBrick; FastLED.show();
      }
        break;

     case 8:
      for(int i=168; i<=170; i++) { //paljenje "OSAM"
        leds[i]=CRGB::FireBrick; FastLED.show();
      }
      for(int y=159; y<=163; y++) { //gasenje "SEDAM"
        leds[y]=CRGB::Black; FastLED.show();
      }
      for(int x=133; x<=135; x++) { //paljenje "SATI"
        leds[x]=CRGB::FireBrick; FastLED.show();
      }
      break;

    case 9:
      for(int i=144; i<=147; i++) { //paljenje "DEVET"
        leds[i]=CRGB::FireBrick; FastLED.show();
      }
      for(int y=168; y<=170; y++) { //gasenje "OSAM"
        leds[y]=CRGB::Black; FastLED.show();
      }
      for(int x=133; x<=135; x++) { //paljenje "SATI"
        leds[x]=CRGB::FireBrick; FastLED.show();
      }      
      break;

    case 10:
      for(int i=164; i<=167; i++) { //paljenje "DESET"
        leds[i]=CRGB::FireBrick; FastLED.show();
      }
      for(int y=144; y<=147; y++) { //gasenje "DEVET"
        leds[y]=CRGB::Black; FastLED.show();
      }
     for(int x=133; x<=135; x++) { //paljenje "SATI"
        leds[x]=CRGB::FireBrick; FastLED.show();
      }
      break;

    case 11:
      for(int i=171; i<=178; i++) { //paljenje "JEDANAEST"
        leds[i]=CRGB::FireBrick; FastLED.show();
      }
      for(int y=164; y<=167; y++) { //gasenje "DESET"
        leds[y]=CRGB::Black; FastLED.show();
      }
     for(int x=133; x<=135; x++) { //paljenje "SATI"
        leds[x]=CRGB::FireBrick; FastLED.show();
      }
      break;

    case 12:
      for(int i=149; i<=154; i++) { //paljenje "DVANAEST"
        leds[i]=CRGB::FireBrick; FastLED.show();
      }
      for(int y=171; y<=178; y++) { //gasenje "JEDANAEST"
        leds[y]=CRGB::Black; FastLED.show();
      }
      for(int x=133; x<=135; x++) { //paljenje "SATI"
        leds[x]=CRGB::FireBrick; FastLED.show();
      }
      break;
}
//--------------------------------------MINUTE---MINUTE---MINUTE----------------------------



switch(minuta) {

  case 1:
    for(int i=47; i<=50; i++) { //paljenje "JEDNA"
      leds[i]=CRGB::FireBrick; FastLED.show();
    }
    for(int y=25; y<=28; y++) { //gasenje "DEVET"
      leds[y]=CRGB::Black; FastLED.show();
    }
    break;

  case 2:
    for(int i=73; i<=76; i++) { //paljenje "DVIJE"
      leds[i]=CRGB::FireBrick; FastLED.show();
    }
    for(int y=47; y<=50; y++) { //gasenje "JEDNA"
      leds[y]=CRGB::Black; FastLED.show();
    }
    break;

  case 3:
    for(int i=17; i<=18; i++) { //paljenje "TRI"
      leds[i]=CRGB::FireBrick; FastLED.show();
    }
    for(int y=73; y<=76; y++) { //gasenje "DVIJE"
      leds[y]=CRGB::Black; FastLED.show();
    }
    break;

  case 4:
    for(int i=59; i<=62; i++) { //paljenje "ČETIRI"
      leds[i]=CRGB::FireBrick; FastLED.show();
    }
    for(int y=17; y<=18; y++) { //gasenje "TRI"
      leds[y]=CRGB::Black; FastLED.show();
    }
    break;

  case 5:
    for(int i=84; i<=85; i++) { //paljenje "PET"
      leds[i]=CRGB::FireBrick; FastLED.show();
    }
    for(int y=59; y<=62; y++) { //gasenje "ČETIRI"
      leds[y]=CRGB::Black; FastLED.show();
    }
    break;

  case 6:
    for(int i=34; i<=37; i++) { //paljenje "ŠEST"
      leds[i]=CRGB::FireBrick; FastLED.show();
    }
    for(int y=84; y<=85; y++) { //gasenje "PET"
      leds[y]=CRGB::Black; FastLED.show();
    }
    break;

  case 7:
    for(int i=43; i<=46; i++) { //paljenje "SEDAM"
      leds[i]=CRGB::FireBrick; FastLED.show();
    }
    for(int y=34; y<=37; y++) { //gasenje "ŠEST"
      leds[y]=CRGB::Black; FastLED.show();
    }
    break;

  case 8:
    for(int i=51; i<=53; i++) { //paljenje "OSAM"
      leds[i]=CRGB::FireBrick; FastLED.show();
    }
    for(int y=43; y<=46; y++) { //gasenje "SEDAM"
      leds[y]=CRGB::Black; FastLED.show();
    }
    break;

  case 9:
    for(int i=25; i<=28; i++) { //paljenje "DEVET"
      leds[i]=CRGB::FireBrick; FastLED.show();
    }
    for(int y=51; y<=53; y++) { //gasenje "OSAM"
      leds[y]=CRGB::Black; FastLED.show();
    }
    break;

  case 10:
    for(int i=123; i<=126; i++) { //paljenje "DESET"
      leds[i]=CRGB::FireBrick; FastLED.show();
    }
    for(int y=25; y<=28; y++) { //gasenje "DEVET"
      leds[y]=CRGB::Black; FastLED.show();
    }
    break;

  case 11:
    for(int i=95; i<=102; i++) { //paljenje "JEDANAEST"
      leds[i]=CRGB::FireBrick; FastLED.show();
    }
    for(int y=123; y<=126; y++) { //gasenje "DESET"
      leds[y]=CRGB::Black; FastLED.show();
    }
    break;

  case 12:
    for(int i=77; i<=82; i++) { //paljenje "DVANAEST"
      leds[i]=CRGB::FireBrick; FastLED.show();
    }
    for(int y=95; y<=102; y++) { //gasenje "JEDANAEST"
      leds[y]=CRGB::Black; FastLED.show();
    }
    break;

  case 13:
    for(int i=13; i<=17; i++) { //paljenje "TRINAEST"
      leds[i]=CRGB::FireBrick; FastLED.show();
    }
    leds[18]=CRGB::FireBrick; FastLED.show();
    for(int y=77; y<=82; y++) { //gasenje "DVANAEST"
      leds[y]=CRGB::Black; FastLED.show();
    }
    break;

  case 14:
    for(int i=19; i<=24; i++) { //paljenje "ČETRNAEST"
      leds[i]=CRGB::FireBrick; FastLED.show();
    }
    leds[18]=CRGB::FireBrick; FastLED.show();
    for(int y=13; y<=17; y++) { //gasenje "TRINAEST"
      leds[y]=CRGB::Black; FastLED.show();
    }
    break;

  case 15:
    for(int i=84; i<=89; i++) { //paljenje "PETNAEST"
      leds[i]=CRGB::FireBrick; FastLED.show();
    }
    leds[18]=CRGB::Black; FastLED.show();
    for(int y=19; y<=24; y++) { //gasenje "ČETRNAEST"
      leds[y]=CRGB::Black; FastLED.show();
    }
    break;

  case 16:
    for(int i=65; i<=71; i++) { //paljenje "ŠESNAEST"
      leds[i]=CRGB::FireBrick; FastLED.show();
    }
    for(int y=84; y<=89; y++) { //gasenje "PETNAEST"
      leds[y]=CRGB::Black; FastLED.show();
    }
    break;

  case 17:
    for(int i=39; i<=46; i++) { //paljenje "SEDAMNAEST"
      leds[i]=CRGB::FireBrick; FastLED.show();
    }
    for(int y=65; y<=71; y++) { //gasenje "ŠESNAEST"
      leds[y]=CRGB::Black; FastLED.show();
    }
    break;

  case 18:
    for(int i=51; i<=58; i++) { //paljenje "OSAMNAEST"
      leds[i]=CRGB::FireBrick; FastLED.show();
    }
    for(int y=39; y<=46; y++) { //gasenje "SEDAMNAEST"
      leds[y]=CRGB::Black; FastLED.show();
    }
    break;

  case 19:
    for(int i=25; i<=32; i++) { //paljenje "DEVETNAEST"
      leds[i]=CRGB::FireBrick; FastLED.show();
    }
    for(int y=51; y<=58; y++) { //gasenje "OSAMNAEST"
      leds[y]=CRGB::Black; FastLED.show();
    }
    break;

  case 20:
    for(int i=116; i<=122; i++) { //paljenje "DVADESET"
      leds[i]=CRGB::FireBrick; FastLED.show();
    }
    for(int y=25; y<=32; y++) { //gasenje "DEVETNAEST"
      leds[y]=CRGB::Black; FastLED.show();
    }
    break;

  case 21:
    for(int i=116; i<=122; i++) { //paljenje "DVADESET"
      leds[i]=CRGB::FireBrick; FastLED.show();
    }
    for(int i=47; i<=50; i++) { //paljenje "JEDNA"
      leds[i]=CRGB::FireBrick; FastLED.show();
    }
    break;

  case 22:
    for(int i=116; i<=122; i++) { //paljenje "DVADESET"
      leds[i]=CRGB::FireBrick; FastLED.show();
    }
    for(int x=73; x<=76; x++) { //paljenje "DVIJE"
      leds[x]=CRGB::FireBrick; FastLED.show();
    }
    for(int y=47; y<=50; y++) { //gasenje "JEDNA"
      leds[y]=CRGB::Black; FastLED.show();
    }
    break;

  case 23:
    for(int i=116; i<=122; i++) { //paljenje "DVADESET"
      leds[i]=CRGB::FireBrick; FastLED.show();
    }
    for(int i=17; i<=18; i++) { //paljenje "TRI"
      leds[i]=CRGB::FireBrick; FastLED.show();
    }
    for(int y=73; y<=76; y++) { //gasenje "DVIJE"
      leds[y]=CRGB::Black; FastLED.show();
    }
    break;

  case 24:
    for(int i=116; i<=122; i++) { //paljenje "DVADESET"
      leds[i]=CRGB::FireBrick; FastLED.show();
    }
    for(int i=59; i<=62; i++) { //paljenje "ČETIRI"
      leds[i]=CRGB::FireBrick; FastLED.show();
    }
    for(int y=17; y<=18; y++) { //gasenje "TRI"
      leds[y]=CRGB::Black; FastLED.show();
    }
    break;

  case 25:
    for(int i=116; i<=122; i++) { //paljenje "DVADESET"
      leds[i]=CRGB::FireBrick; FastLED.show();
    }
    for(int i=84; i<=85; i++) { //paljenje "PET"
      leds[i]=CRGB::FireBrick; FastLED.show();
    }
    for(int y=52; y<=59; y++) { //gasenje "ČETIRI"
      leds[y]=CRGB::Black; FastLED.show();
    }
    break;

  case 26:
    for(int i=116; i<=122; i++) { //paljenje "DVADESET"
      leds[i]=CRGB::FireBrick; FastLED.show();
    }
    for(int i=34; i<=37; i++) { //paljenje "ŠEST"
      leds[i]=CRGB::FireBrick; FastLED.show();
    }
    for(int y=84; y<=85; y++) { //gasenje "PET"
      leds[y]=CRGB::Black; FastLED.show();
    }
    break;

  case 27:
    for(int i=116; i<=122; i++) { //paljenje "DVADESET"
      leds[i]=CRGB::FireBrick; FastLED.show();
    }
    for(int i=43; i<=46; i++) { //paljenje "SEDAM"
      leds[i]=CRGB::FireBrick; FastLED.show();
    }
    for(int y=34; y<=37; y++) { //gasenje "ŠEST"
      leds[y]=CRGB::Black; FastLED.show();
    }
    break;

  case 28:
    for(int i=116; i<=122; i++) { //paljenje "DVADESET"
      leds[i]=CRGB::FireBrick; FastLED.show();
    }
    for(int i=51; i<=53; i++) { //paljenje "OSAM"
      leds[i]=CRGB::FireBrick; FastLED.show();
    }
    for(int y=43; y<=46; y++) { //gasenje "SEDAM"
      leds[y]=CRGB::Black; FastLED.show();
    }
    break;

  case 29:
    for(int i=116; i<=122; i++) { //paljenje "DVADESET"
      leds[i]=CRGB::FireBrick; FastLED.show();
    }
    for(int i=25; i<=28; i++) { //paljenje "DEVET"
      leds[i]=CRGB::FireBrick; FastLED.show();
    }
    for(int y=51; y<=53; y++) { //gasenje "OSAM"
      leds[y]=CRGB::Black; FastLED.show();
    }
    break;

  case 30:
    for(int i=123; i<=128; i++) { //paljenje "TRIDESET"
      leds[i]=CRGB::FireBrick; FastLED.show();
    }
    for(int y=25; y<=28; y++) { //gasenje "DEVET"
      leds[y]=CRGB::Black; FastLED.show();
    }
    for(int x=116; x<=122; x++) { //gasenje "DVADESET"  
      leds[x]=CRGB::Black; FastLED.show();
    }
    break;

   case 31:
    for(int i=123; i<=128; i++) { //paljenje "TRIDESET"
      leds[i]=CRGB::FireBrick; FastLED.show();
    }
    for(int i=47; i<=50; i++) { //paljenje "JEDNA"
      leds[i]=CRGB::FireBrick; FastLED.show();
    }
    break;

  case 32:
    for(int i=123; i<=128; i++) { //paljenje "TRIDESET"
      leds[i]=CRGB::FireBrick; FastLED.show();
    }
    for(int x=73; x<=76; x++) { //paljenje "DVIJE"
      leds[x]=CRGB::FireBrick; FastLED.show();
    }
    for(int y=47; y<=50; y++) { //gasenje "JEDNA"
      leds[y]=CRGB::Black; FastLED.show();
    }
    break;

  case 33:
    for(int i=123; i<=128; i++) { //paljenje "TRIDESET"
      leds[i]=CRGB::FireBrick; FastLED.show();
    }
    for(int x=17; x<=18; x++) { //paljenje "TRI"
      leds[x]=CRGB::FireBrick; FastLED.show();
    }
    for(int y=73; y<=76; y++) { //gasenje "DVIJE"
      leds[y]=CRGB::Black; FastLED.show();
    }
    break;

  case 34:
    for(int i=123; i<=128; i++) { //paljenje "TRIDESET"
      leds[i]=CRGB::FireBrick; FastLED.show();
    }
    for(int i=59; i<=62; i++) { //paljenje "ČETIRI"
      leds[i]=CRGB::FireBrick; FastLED.show();
    }
    for(int y=17; y<=18; y++) { //gasenje "TRI"
      leds[y]=CRGB::Black; FastLED.show();
    }
    break;

  case 35:
    for(int i=123; i<=128; i++) { //paljenje "TRIDESET"
      leds[i]=CRGB::FireBrick; FastLED.show();
    }
    for(int i=84; i<=85; i++) { //paljenje "PET"
      leds[i]=CRGB::FireBrick; FastLED.show();
    }
    for(int y=59; y<=62; y++) { //gasenje "ČETIRI"
      leds[y]=CRGB::Black; FastLED.show();
    }
    break;

  case 36:
    for(int i=123; i<=128; i++) { //paljenje "TRIDESET"
      leds[i]=CRGB::FireBrick; FastLED.show();
    }
    for(int i=34; i<=37; i++) { //paljenje "ŠEST"
      leds[i]=CRGB::FireBrick; FastLED.show();
    }
    for(int y=84; y<=85; y++) { //gasenje "PET"
      leds[y]=CRGB::Black; FastLED.show();
    }
    break;

  case 37:
    for(int i=123; i<=128; i++) { //paljenje "TRIDESET"
      leds[i]=CRGB::FireBrick; FastLED.show();
    }
    for(int i=43; i<=46; i++) { //paljenje "SEDAM"
      leds[i]=CRGB::FireBrick; FastLED.show();
    }
    for(int y=34; y<=37; y++) { //gasenje "ŠEST"
      leds[y]=CRGB::Black; FastLED.show();
    }
    break;

  case 38:
    for(int i=123; i<=128; i++) { //paljenje "TRIDESET"
      leds[i]=CRGB::FireBrick; FastLED.show();
    }
    for(int i=51; i<=53; i++) { //paljenje "OSAM"
      leds[i]=CRGB::FireBrick; FastLED.show();
    }
    for(int y=43; y<=46; y++) { //gasenje "SEDAM"
      leds[y]=CRGB::Black; FastLED.show();
    }
    break;

  case 39:
    for(int i=123; i<=128; i++) { //paljenje "TRIDESET"
      leds[i]=CRGB::FireBrick; FastLED.show();
    }
    for(int i=25; i<=28; i++) { //paljenje "DEVET"
      leds[i]=CRGB::FireBrick; FastLED.show();
    }
    for(int y=51; y<=53; y++) { //gasenje "OSAM"
      leds[y]=CRGB::Black; FastLED.show();
    }
    break;

  case 40:
    for(int i=103; i<=109; i++) { //paljenje "ČETRDESET"
      leds[i]=CRGB::FireBrick; FastLED.show();
    }
    for(int y=25; y<=28; y++) { //gasenje "DEVET"
      leds[y]=CRGB::Black; FastLED.show();
    }
    for(int x=123; x<=128; x++) { //gasenje "TRIDESET"
      leds[x]=CRGB::Black; FastLED.show();
    }
    break;

  case 41:
    for(int i=103; i<=109; i++) { //paljenje "ČETRDESET"
      leds[i]=CRGB::FireBrick; FastLED.show();
    }
    for(int i=47; i<=50; i++) { //paljenje "JEDNA"
      leds[i]=CRGB::FireBrick; FastLED.show();
    }
    break;

  case 42:
    for(int i=103; i<=109; i++) { //paljenje "ČETRDESET"
      leds[i]=CRGB::FireBrick; FastLED.show();
    }
    for(int i=73; i<=76; i++) { //paljenje "DVIJE"
      leds[i]=CRGB::FireBrick; FastLED.show();
    }
    for(int y=47; y<=50; y++) { //gasenje "JEDNA"
      leds[y]=CRGB::Black; FastLED.show();
    }
    break;

  case 43:
    for(int i=103; i<=109; i++) { //paljenje "ČETRDESET"
      leds[i]=CRGB::FireBrick; FastLED.show();
    }
    for(int x=17; x<=18; x++) { //paljenje "TRI"
      leds[x]=CRGB::FireBrick; FastLED.show();
    }
    for(int y=73; y<=76; y++) { //gasenje "DVIJE"
      leds[y]=CRGB::Black; FastLED.show();
    }
    break;

  case 44:
    for(int i=103; i<=109; i++) { //paljenje "ČETRDESET"
      leds[i]=CRGB::FireBrick; FastLED.show();
    }
    for(int i=59; i<=62; i++) { //paljenje "ČETIRI"
      leds[i]=CRGB::FireBrick; FastLED.show();
    }
    for(int y=17; y<=18; y++) { //gasenje "TRI"
      leds[y]=CRGB::Black; FastLED.show();
    }
    break;

  case 45:
    for(int i=103; i<=109; i++) { //paljenje "ČETRDESET"
      leds[i]=CRGB::FireBrick; FastLED.show();
    }
    for(int i=84; i<=85; i++) { //paljenje "PET"
      leds[i]=CRGB::FireBrick; FastLED.show();
    }
    for(int y=59; y<=62; y++) { //gasenje "ČETIRI"
      leds[y]=CRGB::Black; FastLED.show();
    }
    break;

  case 46:
    for(int i=103; i<=109; i++) { //paljenje "ČETRDESET"
      leds[i]=CRGB::FireBrick; FastLED.show();
    }
    for(int i=34; i<=37; i++) { //paljenje "ŠEST"
      leds[i]=CRGB::FireBrick; FastLED.show();
    }
    for(int y=84; y<=85; y++) { //gasenje "PET"
      leds[y]=CRGB::Black; FastLED.show();
    }
    break;

  case 47:
    for(int i=103; i<=109; i++) { //paljenje "ČETRDESET"
      leds[i]=CRGB::FireBrick; FastLED.show();
    }
    for(int i=43; i<=46; i++) { //paljenje "SEDAM"
      leds[i]=CRGB::FireBrick; FastLED.show();
    }
    for(int y=34; y<=37; y++) { //gasenje "ŠEST"
      leds[y]=CRGB::Black; FastLED.show();
    }
    break;

  case 48:
    for(int i=103; i<=109; i++) { //paljenje "ČETRDESET"
      leds[i]=CRGB::FireBrick; FastLED.show();
    }
    for(int i=51; i<=53; i++) { //paljenje "OSAM"
      leds[i]=CRGB::FireBrick; FastLED.show();
    }
    for(int y=43; y<=46; y++) { //gasenje "SEDAM"
      leds[y]=CRGB::Black; FastLED.show();
    }
    break;

  case 49:
    for(int i=103; i<=109; i++) { //paljenje "ČETRDESET"
      leds[i]=CRGB::FireBrick; FastLED.show();
    }
    for(int i=25; i<=28; i++) { //paljenje "DEVET"
      leds[i]=CRGB::FireBrick; FastLED.show();
    }
    for(int y=51; y<=53; y++) { //gasenje "OSAM"
      leds[y]=CRGB::Black; FastLED.show();
    }
    break;

  case 50:
    for(int i=110; i<=115; i++) { //paljenje "PEDESET"
      leds[i]=CRGB::FireBrick; FastLED.show();
    }
    for(int y=25; y<=28; y++) { //gasenje "DEVET"
      leds[y]=CRGB::Black; FastLED.show();
    }
    for(int x=103; x<=109; x++) { //gasenje "ČETRDESET"
      leds[x]=CRGB::Black; FastLED.show();
    }
    break;

  case 51:
    for(int i=110; i<=115; i++) { //paljenje "PEDESET"
      leds[i]=CRGB::FireBrick; FastLED.show();
    }
    for(int i=47; i<=50; i++) { //paljenje "JEDNA"
      leds[i]=CRGB::FireBrick; FastLED.show();
    }
    break;

  case 52:
    for(int i=110; i<=115; i++) { //paljenje "PEDESET"
      leds[i]=CRGB::FireBrick; FastLED.show();
    }
    for(int i=73; i<=76; i++) { //paljenje "DVIJE"
      leds[i]=CRGB::FireBrick; FastLED.show();
    }
    for(int y=47; y<=50; y++) { //gasenje "JEDNA"
      leds[y]=CRGB::Black; FastLED.show();
    }
    break;

  case 53:
    for(int i=110; i<=115; i++) { //paljenje "PEDESET"
      leds[i]=CRGB::FireBrick; FastLED.show();
    }
    for(int i=17; i<=18; i++) { //paljenje "TRI"
      leds[i]=CRGB::FireBrick; FastLED.show();
    }
    for(int y=73; y<=76; y++) { //gasenje "DVIJE"
      leds[y]=CRGB::Black; FastLED.show();
    }
    break;

  case 54:
    for(int i=110; i<=115; i++) { //paljenje "PEDESET"
      leds[i]=CRGB::FireBrick; FastLED.show();
    }
    for(int i=59; i<=62; i++) { //paljenje "ČETIRI"
      leds[i]=CRGB::FireBrick; FastLED.show();
    }
    for(int y=17; y<=18; y++) { //gasenje "TRI"
      leds[y]=CRGB::Black; FastLED.show();
    }
    break;

  case 55:
    for(int i=110; i<=115; i++) { //paljenje "PEDESET"
      leds[i]=CRGB::FireBrick; FastLED.show();
    }
    for(int i=84; i<=85; i++) { //paljenje "PET"
      leds[i]=CRGB::FireBrick; FastLED.show();
    }
    for(int y=59; y<=62; y++) { //gasenje "ČETIRI"
      leds[y]=CRGB::Black; FastLED.show();
    }
    break;

  case 56:
    for(int i=110; i<=115; i++) { //paljenje "PEDESET"
      leds[i]=CRGB::FireBrick; FastLED.show();
    }
    for(int i=34; i<=37; i++) { //paljenje "ŠEST"
      leds[i]=CRGB::FireBrick; FastLED.show();
    }
    for(int y=84; y<=85; y++) { //gasenje "PET"
      leds[y]=CRGB::Black; FastLED.show();
    }
    break;

  case 57:
    for(int i=110; i<=115; i++) { //paljenje "PEDESET"
      leds[i]=CRGB::FireBrick; FastLED.show();
    }
    for(int i=43; i<=46; i++) { //paljenje "SEDAM"
      leds[i]=CRGB::FireBrick; FastLED.show();
    }
    for(int y=34; y<=37; y++) { //gasenje "ŠEST"
      leds[y]=CRGB::Black; FastLED.show();
    }
    break;

  case 58:
    for(int i=110; i<=115; i++) { //paljenje "PEDESET"
      leds[i]=CRGB::FireBrick; FastLED.show();
    }
    for(int i=51; i<=53; i++) { //paljenje "OSAM"
      leds[i]=CRGB::FireBrick; FastLED.show();
    }
    for(int y=43; y<=46; y++) { //gasenje "SEDAM"
      leds[y]=CRGB::Black; FastLED.show();
    }
    break;

  case 59:
    for(int i=110; i<=115; i++) { //paljenje "PEDESET"
      leds[i]=CRGB::FireBrick; FastLED.show();
    }
    for(int i=25; i<=28; i++) { //paljenje "DEVET"
      leds[i]=CRGB::FireBrick; FastLED.show();
    }
    for(int y=51; y<=53; y++) { //gasenje "OSAM"
      leds[y]=CRGB::Black; FastLED.show();
    }
    break;

  
  

}

  
}
