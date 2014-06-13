  
  /*
  switch(mode) {
 
   case 0: // Random sparks - just one LED on at a time!
    i = random(32);
    pixels.setPixelColor(i, color);
    pixels.show();
    delay(10);
    pixels.setPixelColor(i, 0);
    break;
 
   case 1: // Spinny wheels (8 LEDs on at a time)
    for(i=0; i<16; i++) {
      uint32_t c = 0;
      if(((offset + i) & 7) < 2) c = color; // 4 pixels on...
      pixels.setPixelColor(   i, c); // First eye
      pixels.setPixelColor(31-i, c); // Second eye (flipped)
    }
    pixels.show();
    offset++;
    delay(50);
    break;
  }
  
  */
