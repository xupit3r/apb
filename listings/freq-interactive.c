#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main () {
  double c5, c0, semitoneRatio, frequency;
  int midiNote;
  char message[256];
  char* result;

  semitoneRatio = pow(2, 1.0 / 12);
  c5 = 220.0 * pow(semitoneRatio, 3);
  c0 = c5 * pow(0.5, 5);

  printf("enter MIDI note (0 - 127): ");
  result = gets(message);

  if (result == NULL) {
    printf("there was an error reading the input.\n");
    return 1;
  }

  if (message[0] == '\0') {
    printf("have a nice day.\n");
    return 1;
  }

  midiNote = atoi(message);
  if (midiNote < 0) {
    printf("sorry - %s is a bad MIDI note number\n", message);
    return 1;
  }

  if (midiNote > 127) {
    printf("sorry - %s is beyond the MIDI range!\n", message);
  }

  frequency = c0 * pow(semitoneRatio, midiNote);
  printf("frequency of MIDI note %d = %f\n", midiNote, frequency);

  return 1;
}