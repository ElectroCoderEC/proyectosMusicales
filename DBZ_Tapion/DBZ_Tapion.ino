//*****************************************************
//Realizado por © 2017 Sebastian Cuenca ***************
//Comparte, like y comenta :D :D :D ******************* 
//*****************************************************

//Pueden suscribirse a mi canal de Youtube para mas videos
// https://www.youtube.com/channel/UCSFuCPnuj9d379TgGQ880sw

int statePin = LOW; 
int speakerPin = 4;
int led1 = 14;
int led2 = 16;


int length = 64; // the number of notes                                                               
char notes[] = "CCF!oOoFGOOoOG CCF!oOoFGOOGGFRF ccfCsSsfgSSSsSgccfCsSsfgSSggfrf "; // a space represents a rest
float beats[] = {1,1,8,1,1,1,8,1,1,8,1,1,1,8,1, 1,1,8,1,1,1,8,1,1,4,1,1,1,1,1,8,1, 1,1,8,1,1,1,8,1,1,4,1,1,1,1,8,1,1,8,1,1,1,8,1,1,4,1,1,1,1,1,12,4}; //Page 6
                
int tempo = 195;

void playTone(int ton1, int duration) {
  for (long i = 0; i < duration * 1000L; i += ton1) { 
    tone(speakerPin, ton1);   
    delayMicroseconds(ton1);
  }
  noTone(speakerPin);
}

void playNote(char note, int duration) {
//                        c    c#   d    d#   e    f    f#   g    g#   a    a#   b             d#                  g#              a#           D#                   G#        A#
  char names[] = { ' ',  '!', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', 'c', 'd', 'r', 'e', 'f', 'g', 'S',  'a', 'b','s','C', 'D', 'R', 'E', 'F', 'G', 'O', 'A', 'o', 'B', 'i', 'N', 'R', 'u',  '1', 'L', 'k'}; // [i = b flat] [N = G flat] [R = D#] [u = g#] [1 = C oct. 5] [L = E flat]
  int tones[] =  {   0, 1046, 138, 146, 155, 164, 174, 184, 195, 207, 220, 233, 246, 261, 293, 311, 329, 349, 391, 415, 440, 493, 466 ,523, 587, 622, 659, 698, 783, 831,880, 932, 987, 466, 740, 622, 415, 1046, 622u, 227};
  
  // play the tone corresponding to the note name
  for (int i = 0; i < 40; i++) {
    if (names[i] == note) {
      playTone(tones[i], duration);
    }
  }
}


void setup() {
  pinMode(speakerPin, OUTPUT);
  pinMode(14, OUTPUT); 
  pinMode(9, OUTPUT); 
  delay(3000);
}

void loop() {
  for (int i = 0; i < length; i++) {
    if (notes[i] == ' ') {
      delay(beats[i] * tempo); // rest
    } else {
      
      playNote(notes[i], beats[i] * tempo);
      
  }
   
    // pause between notes
    delay(tempo / 2); 
  }
}

//*****************************************************
//Realizado por © 2016 Sebastian Cuenca ***************
//Comparte, like y comenta :D :D :D ******************* 
//*****************************************************
