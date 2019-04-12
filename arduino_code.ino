#include <CapacitiveSensor.h>
#define speaker 11

const int KEYNUM = 26;
unsigned int HT[KEYNUM] = {0};
unsigned int LT[KEYNUM] = {0};
char keys[KEYNUM] = {'Z', 'S', 'X', 'D',
                     'C', 'V', 'G', 'B',
                     'H', 'N', 'J', 'M', ',',
                     'Q', '2', 'W', '3',
                     'E', 'R', '5', 'T',
                     '6', 'Y', '7', 'U', 'I'};
CapacitiveSensor sensor = CapacitiveSensor(2,3); 


void setup() {
sensor.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1 - just as an example
  Serial.begin(9600);
  /*
   * int a = 0;
  for(int i = 0; i < KEYNUM; i++){ 
    for(int j = 0; j < 7; j++)
    {
      a += baseline(i);
      delay(5);
    }
    High_Th = a - 10;
    Low_Th = a - 50;
  }
   */
}

void loop() {
  // Set a timer.
  long start = millis();
  
  // Set the sensitivity of the sensors.
  long total1 =  sensor.capacitiveSensor(3000);
  /*
   *  i = 0;
  for(int i = 0; i < KEYNUM; i++)
  {
    if(D(i) < Low_Th(i))
    {
      Keyboard.press(keys[i])
    }
    else(D(i) > High_Th(i))
    {
      //don't send
    }
  }
   */

   if (total1 > 500)
   {
    tone(speaker,131);
   }
   
   delay(10); 
}
