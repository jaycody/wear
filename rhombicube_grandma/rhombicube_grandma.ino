// jstephens   2017_09
// nightLight - Gemma with NeoPixel 16Ring for the stellated rhombicuboctahedron
// updated for grandma's hospital room

// Adafruit Tutorial
// https://learn.adafruit.com/gemma-hoop-earrings/overview

/// Requires Adafruit_NeoPixel library

#include <Adafruit_NeoPixel.h>

#define PIN 0

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(32, PIN);



uint8_t  mode       = 11,    // Current animation effect
         offset     = 0,    // Position of spinny eyes
         redRand    = 255,  // random red level value
         greenRand  = 255,
         blueRand   = 255;

//uint32_t color  = 0xffae00; // Start red
uint32_t color  = 0xFF0000; // Start red
uint32_t prevTime;

void setup() {
  pixels.begin();
  //pixels.setBrightness(90); // 1/3 brightness
  prevTime = millis();
}

void loop() {
  uint8_t  i;
  uint32_t t;

  switch (mode) {

    // all red
    case 0: // Random sparks - just one LED on at a time!
      for (i = 0; i < 16; i++) pixels.setPixelColor(i, 255, 0, 0);
      pixels.show();
      break;


    // all green
    case 1:
      for (i = 0; i < 16; i++) pixels.setPixelColor(i, 0, 255, 0);
      pixels.show();
      break;


    // all blue
    case 2:
      for (i = 0; i < 16; i++) pixels.setPixelColor(i, 0, 0, 255);
      pixels.show();
      break;


    // all orange
    case 3:
      for (i = 0; i < 16; i++) pixels.setPixelColor(i, 255, 100, 0);
      pixels.show();
      break;

    // all purple
    case 4:
      for (i = 0; i < 16; i++) pixels.setPixelColor(i, 255, 0, 255);
      pixels.show();
      break;

    // all coral
    case 5:
      for (i = 0; i < 16; i++) pixels.setPixelColor(i, 255, 127, 80);
      pixels.show();
      break;

    // all pink
    case 6:
      for (i = 0; i < 16; i++) pixels.setPixelColor(i, 255, 20, 147);
      pixels.show();
      break;

    // all dark violet
    case 7:
      for (i = 0; i < 16; i++) pixels.setPixelColor(i, 148, 0, 211);
      pixels.show();
      break;

    // all grey
    case 8:
      for (i = 0; i < 16; i++) pixels.setPixelColor(i, 190, 190, 190);
      pixels.show();
      break;


    case 9:
      for (i = 0; i < 16; i++) pixels.setPixelColor(i, redRand, greenRand, blueRand);
      pixels.show();
      //delay(50);//75
      break;


    // spinning wheels
    case 10:
      for (i = 0; i < 16; i++) {
        uint32_t c = 0;
        if (((offset + i) & 7) < 6) c = color; // 4 pixels on...
        pixels.setPixelColor(   i, c); // First eye
        pixels.setPixelColor(31 - i, c); // Second eye (flipped)
      }
      pixels.show();
      offset++;
      delay(50);//75
      break;

    // GRANDMA'S COLORS
    case 11:
      for (i = 0; i < 16; i++) pixels.setPixelColor(i, 0, 0, 255);
      pixels.show();
      break;
  }


  t = millis();
  if ((t - prevTime) > 40000) {     // Every 8 seconds...
    //mode       = random(10);
    mode       = 11;  // grandma's color
    redRand    = random(255);
    greenRand  = random(255);
    blueRand   = random(255);
    /*
      mode++;                        // Next mode
      if(mode > 1) {                 // End of modes?
      //mode = random(3);
      //mode = 0;                    // Start modes over
      color >>= 8;                 // Next color R->G->B
      if(!color) color = 0xFF0000; // Reset to red
      }
    */
    // reset to black
    for (i = 0; i < 32; i++) pixels.setPixelColor(i, 0);
    prevTime = t;
  }
}

