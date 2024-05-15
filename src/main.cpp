#include <Arduino.h>
#include <asmsynth.h>

const int tone_inc[] = {
    c0, cs0, d0, ds0, e0, f0, fs0, g0, gs0, a0, as0, b0, h0,
    c1, cs1, d1, ds1, e1, f1, fs1, g1, gs1, a1, as1, b1, h1,
    c2, cs2, d2, ds2, e2, f2, fs2, g2, gs2, a2, as2, b2, h2,
    c3, cs3, d3, ds3, e3, f3, fs3, g3, gs3, a3, as3, b3, h3,
    c4, cs4, d4, ds4, e4, f4, fs4, g4, gs4, a4, as4, b4, h4,
    c5, cs5, d5, ds5, e5, f5, fs5, g5, gs5, a5, as5, b5, h5,
    c6, cs6, d6, ds6, e6, f6, fs6, g6, gs6, a6, as6, b6, h6,
    c7, cs7, d7, ds7, e7, f7, fs7, g7, gs7, a7, as7, b7, h7,
    c8, cs8, d8, ds8, e8, f8, fs8, g8, gs8, a8, as8, b8, h8
};

struct Note {
  int frequency;
  char volume;
};

Note note = {tone_inc[22], 50};

void setup()
{
  Serial.begin(115200);
  synthSetup();
  // pinMode(13, OUTPUT);
}

void loop()
{
  if (Serial.available())
  {
    Serial.read();
    wave01_frequency(note.frequency++);

    // if (serialData == 0x90) {
    //   const int midiNote = Serial.read();
    //   const char midiVelocity = Serial.read();
    //   note.volume = midiVelocity - 50;
    //   note.frequency = tone_inc[midiNote];
    // }
  }
}

start_interrupt
  wave01();
  triangleWave();

  wave02();
  sawWave();

end_interrupt

start_secondProgram
  wave01_volume(note.volume);
  wave01_frequency(note.frequency);

  delay_ms(1000);
end_secondProgram
