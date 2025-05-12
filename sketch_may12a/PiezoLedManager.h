class PiezoLedManager {
private:
  int piezoPin;
  int ledPin;
  const note* melody;
  int length;
  int noteIndex;
  int lastUpdate;

public:
  PiezoLedManager(int piezoPin, int ledPin, const note* melody, int length) {
    this->piezoPin = piezoPin;
    this->ledPin = ledPin;
    this->melody = melody;
    this->length = length;
    lastUpdate = 0;
    noteIndex = 0;
    tone(piezoPin, melody[0].pitch, melody[0].duration);
  }

  void updateState(int currentMillis) {
    if (currentMillis - lastUpdate >= melody[noteIndex].duration + 50) {

      // update note to be played
      noteIndex++;
      if (noteIndex == length) {
        noteIndex = 0;
      }

      // get the note stored in a new variable
      int noteToPlay = melody[noteIndex].pitch;

      // play that note
      tone(piezoPin, noteToPlay, melody[noteIndex].duration);
      
      //turn off LED if note has a pitch of 0
      if(melody[noteIndex].pitch == 0){
        digitalWrite(ledPin, LOW);
      }
      //turn on LED at the same time as a note is played
      else {
        digitalWrite(ledPin, HIGH);
        delay((melody[noteIndex].duration)/2);
        digitalWrite(ledPin, LOW);
      }
      

      // update last update
      lastUpdate = currentMillis;
    }
  }
};
  
PiezoLedManager piezoLed(13, 12, melody, 17);
