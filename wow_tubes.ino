#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

Adafruit_NeoPixel strip1 = Adafruit_NeoPixel(40, 3, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip2 = Adafruit_NeoPixel(40, 5, NEO_GRB + NEO_KHZ800);

int brightness = 100;

struct color{
  uint8_t r;
  uint8_t g;
  uint8_t b;
  color(){
    this->r=0;
    this->g=0;
    this->b=0;
  }
  color(uint8_t r, uint8_t g, uint8_t b){
    this->r=r;
    this->g=g;
    this->b=b;
  }
};
#define PATTERN_SIZE 40
struct color pattern[PATTERN_SIZE]; 

void createPattern(){
  for (int i=0;i<PATTERN_SIZE;i++){
    if (i>PATTERN_SIZE/2)
      pattern[i]=color(255,255,0);
    else
      pattern[i]=color(0,0,255);
  }
  
}

void setup() {
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
  #if defined (__AVR_ATtiny85__)
    if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
  #endif
  // End of trinket special code

  strip1.begin();
  strip1.setBrightness(50);
  strip1.show(); // Initialize all pixels to 'off'
  strip2.begin();
  strip2.setBrightness(50);
  strip2.show(); // Initialize all pixels to 'off'
  createPattern();
}


void displayColor(const struct color &c, const int &i, const Adafruit_NeoPixel &strip){
  strip.setPixelColor(i,strip.Color(c.r,c.g,c.b));
  strip.show();
}

void loop() {
//  for (int i=0;i<PATTERN_SIZE;i++){
//    displayColor(pattern[i],i,strip1);
//    displayColor(pattern[PATTERN_SIZE-i],PATTERN_SIZE-i,strip2);
//  }
//  delay(20);
  choateColors(20);
  //strip1.setBrightness(rand()*100.0);
  //pulse(5);
}

void pulse(uint8_t wait){
  for(int j = 0; j <= 100; j++){
    for(int i = 0; i < 40; i++){
      strip1.setPixelColor(i, strip1.Color(255, 255, 0));
      strip2.setPixelColor(i, strip2.Color(0, 0, 255));
    }
    strip1.setBrightness(j);
    strip2.setBrightness(j);
    strip1.show();
    strip2.show();
    delay(wait);
  }

  for(int j = 100; j >= 0; j--){
    for(int i = 0; i < 40; i++){
      strip1.setPixelColor(i, strip1.Color(255, 255, 0));
      strip2.setPixelColor(i, strip2.Color(0, 0, 255));
    }
    strip1.setBrightness(j);
    strip2.setBrightness(j);
    strip1.show();
    strip2.show();
    delay(wait);
  }
  
}

void choateColors(uint8_t wait){
  uint16_t i, j;
  uint16_t len = 40;
  for(int j = len; j >= 0; j--){
    for(int i = 0; i < strip1.numPixels(); i++){
      
      if((i+j)%len > len/2){
        strip1.setPixelColor(i, strip1.Color(255, 255, 0));
      }
      else{
        strip1.setPixelColor(i, strip1.Color(0, 0, 255));
      }

      if((i+(len-1-j))%len > len/2){
        strip2.setPixelColor(i, strip2.Color(0, 0, 255));
      }
      else{
        strip2.setPixelColor(i, strip2.Color(255, 255, 0));
      }

      
      
    }
    strip1.setBrightness(max(abs(50-brightness)%50 * 2, 10));
    strip2.setBrightness(max(abs(50-brightness)%50 * 2, 10));
    brightness--;

    if(brightness == 0){
      brightness = 99;
    }
    
    strip1.show();
    strip2.show();
    delay(wait);
  }
}

