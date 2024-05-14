#include <Arduino.h>

//requirements:
//3 voices
//5kb +/- program memory



#include <asmsynth.h>

byte counter;

void setup()
{
  synthSetup();
  pinMode(13, OUTPUT);
}

void loop()
{
  digitalWrite(13, HIGH);
  delay(1000);
  digitalWrite(13, LOW);
  delay(1000);
}

start_interrupt
  wave01();
  triangleWave();

  wave02();
  sineWave();

end_interrupt

start_secondProgram
  wave01_volume(50);
  wave01_frequency(e2);
  delay_ms(500);

  wave01_volume(0);
  wave01_frequency(0);
  wave01_phase(0);
  delay_ms(100);

  wave02_volume(50);
  wave02_frequency(e2);
  delay_ms(500);

  wave02_volume(0);
  wave02_frequency(0);
  wave02_phase(0);
  delay_ms(100);

  wave02_volume(50);
  wave02_frequency(e6);
  delay_ms(500);

  wave02_volume(0);
  wave02_frequency(0);
  wave02_phase(0);
  delay_ms(100);

end_secondProgram
