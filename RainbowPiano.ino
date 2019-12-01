#include <FastLED.h>
#include <CapacitiveSensor.h>
int Do = 262, Re = 294 , Mi = 330 , Fa = 349 , Sol = 392 , 
    La = 440 , Si = 494, Do2 = 524;
int buzz = 13;  
int wait = 100;
#define LED_PIN     13
#define NUM_LEDS    5
CRGB leds[NUM_LEDS];

CapacitiveSensor   cs_2_4 = CapacitiveSensor(2,4);
CapacitiveSensor   cs_2_6 = CapacitiveSensor(2,6);
CapacitiveSensor   cs_2_8 = CapacitiveSensor(2,8);    
CapacitiveSensor   cs_2_10 = CapacitiveSensor(2,10);
CapacitiveSensor   cs_2_12 = CapacitiveSensor(2,12);
CapacitiveSensor  cs_2_11 = CapacitiveSensor(2,11);
CapacitiveSensor  cs_2_9 = CapacitiveSensor(2,9);
CapacitiveSensor   cs_2_7 = CapacitiveSensor(2,7);
void setup() {
FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  
 cs_2_4.set_CS_AutocaL_Millis(0xFFFFFFFF);
 cs_2_6.set_CS_AutocaL_Millis(0xFFFFFFFF);
 cs_2_8.set_CS_AutocaL_Millis(0xFFFFFFFF);
 cs_2_10.set_CS_AutocaL_Millis(0xFFFFFFFF);
 cs_2_12.set_CS_AutocaL_Millis(0xFFFFFFFF);
 cs_2_11.set_CS_AutocaL_Millis(0xFFFFFFFF);
cs_2_7.set_CS_AutocaL_Millis(0xFFFFFFFF);
 cs_2_9.set_CS_AutocaL_Millis(0xFFFFFFFF);
  // Arduino start communicate with computer.
  Serial.begin(9600);
  pinMode(buzz,OUTPUT);
}

void loop() {
  
  // Set the sensitivity of the sensors.
  long total1 =  cs_2_4.capacitiveSensor(100);
  long total2 =  cs_2_6.capacitiveSensor(100);
  long total3 = cs_2_8.capacitiveSensor(500);
  long total4 = cs_2_10.capacitiveSensor(500);
  long total5 = cs_2_12.capacitiveSensor(500);
  long total6 = cs_2_11.capacitiveSensor(500);
  long total7 = cs_2_9.capacitiveSensor(100);
  long total8 = cs_2_7.capacitiveSensor(500);
 
  if(total1>=1000)
  {  
 for (int i = 0; i <= NUM_LEDS; i++) {
    leds[i] = CRGB::Violet;
    FastLED.show();}
  tone(buzz, Do, wait);}
  else if(total2>=1000)
  {
     for (int i = 0; i <= NUM_LEDS; i++) {
    leds[i] = CRGB::Indigo;
    FastLED.show();}
    tone(buzz, Re, wait);}
  else if(total3>=1000)
  {
     for (int i = 0; i <= NUM_LEDS; i++) {
    leds[i] = CRGB(0,0,255);
    FastLED.show();}
    tone(buzz, Mi, wait);}
  else if (total4>=1000)
  { for (int i = 0; i <= NUM_LEDS; i++) {
    leds[i] = CRGB(0,255,0);
    FastLED.show();}
    tone(buzz, Fa, wait);
  } 
  else if (total5>=1000)
  { for (int i = 0; i <= NUM_LEDS; i++) {
    leds[i] = CRGB::Yellow;
    FastLED.show();}
    tone(buzz, Sol, wait);}
  else if(total6>=1000)
  { for (int i = 0; i <= NUM_LEDS; i++) {
    leds[i] = CRGB::Orange;
    FastLED.show();}
    tone(buzz, La, wait);}
    else if(total7>=1000)
  { for (int i = 0; i <= NUM_LEDS; i++) {
    leds[i] = CRGB(255,0,0);
    FastLED.show();}
    tone(buzz, Si, wait);}
   else if(total8>=1000)
  { for (int i = 0; i <= NUM_LEDS; i++) {
    leds[i] = CRGB::Violet;
    FastLED.show();}
    tone(buzz, Do2, wait);}
  else
  { for (int i = 0; i <= NUM_LEDS; i++) {
    leds[i] = CRGB(0,0,0);
    FastLED.show();}
    noTone(buzz);}
    

}
