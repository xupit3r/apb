/* listing 1.2: Calculate frequency of a MIDI Note number */
#include <stdio.h>
#include <math.h>

int main () {
  int midiNote;
  double semitoneRatio, frequency, fracMidi;

  // frequency of MIDI note 0
  double c0;

  // frequency of Middle C
  double c5;

  // approximately 1.0594631
  semitoneRatio = pow(2, 1 / 12.0);

  // find Middle C, three semitones about low A (or 220)
  c5 = 220.0 * pow(semitoneRatio, 3);

  // MIDI Note 0 is C, 5 octaves below middle C
  c0 = c5 * pow(0.5, 5);

  // calculate a frequency for a given MIDI Note Number
  // we will use C# above A (or 440)
  midiNote = 73;
  frequency = c0 * pow(semitoneRatio, midiNote);

  printf("MIDI Note %d has frequency %f\n", midiNote, frequency);

  // find the nearest MIDI note to a given frequency in Hz
  // uses log rule: log_a(N) = log_b(N) / log_b(a) to find
  // the log of a value to base "semitone ratio"
  frequency = 400.0;
  fracMidi = log(frequency / c0) / log (semitoneRatio);
  midiNote = (int) (fracMidi + 0.5);

  printf("The nearest MIDI note to the frequency %f is %d\n", frequency, midiNote);

  return 0;
}