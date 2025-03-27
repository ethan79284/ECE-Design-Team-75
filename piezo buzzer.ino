/* Piezo Buzzer Example
www.mybotic.com.my
Parameter for each music node */
const int c = 261;
const int d = 294;
const int e = 329;
const int f = 349;
const int g = 391;
const int a = 440;
const int b = 466;
const int C = 523;

//Parameter for pin mode
const int buzzerPin = 12;
char notes[] = "ccggaag ffeeddc ggffeed ggffeed ccggaag ffeeddc #"; // a space represents a rest
int beats[] = { 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2, 4 };
int tempo = 300;
int length = 15;

void playNote(char note, int duration) {
  char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };
  int tones[] = { 1915, 1700, 1519, 1432, 1275, 1136, 1014, 956 };
  
  // play the tone corresponding to the note name
  for (int i = 0; i < 8; i++) {
    if (names[i] == note) {
      playTone(tones[i], duration);
    }
  }
}

void playTone(int tone, int duration) {
  for (long i = 0; i < duration * 1000L; i += tone * 2) {
    digitalWrite(buzzerPin, HIGH);
    delayMicroseconds(tone);
    digitalWrite(buzzerPin, LOW);
    delayMicroseconds(tone);
  }
}

void setup() 
{
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

void loop() 
{
 unsigned short usExit = 0;
  
  for(int a = 0; a < 10; a++)
  {
     for (int i = 0; i < length; i++)
     {
        Serial.print("a: ");
        Serial.print(a);
        Serial.print(", i: ");
        Serial.print(i);
        Serial.print(", a + i: ");
        Serial.print((a*14)+i);
        Serial.print(", Note: ");
        Serial.println(notes[i+(a*14)]);

        if(notes[i+(a*14)] == '#')
        {
          usExit = 1;
          break;
          //Serial.print(" ");
        } 
        else if (notes[i+(a*14)] == ' ')
        {
          delay(beats[i] * tempo); // rest
          //Serial.print(" ");
        } 
        else 
        {
          //Serial.print(notes[i+a]);
          playNote(notes[i+(a*14)], beats[i] * tempo);
        }
        // pause between notes
        delay(tempo / 2); 
      }

      if(usExit == 1)
      {
        break;  
      }
  }
}



