//*****************************************************
//Realizado por © 2017 Sebastian Cuenca ***************
//Comparte, like y comenta :D :D :D ******************* 
//*****************************************************

int statePin = LOW; 
int speakerPin = 4;

int length = 209; // the number of notes                                                                                                                                                                  //%     
char notes[] = "CRGFDshCRDsgCRGFDsH cc CRGFDshCRDsgCRGFDsH cdrfg gffrfrd cdr drf rfgg fgb cdrfg gffrfrd cdrdcr gfrdd-c CDRGHHGGFGFF ssSHGFR CDRDCRDCFRDFsssbCD GGG CGFRDCG FFFFSHGGFGRFG GGGCGFRDCG DDDDRFFD HGFRCCDRHHHSOS  GGG "; // a space represents a rest
float beats[] = {1,1,1,2.5,1,0.7,2.5,1,1,2.5,1,2,1,1,1,2.5,1,0.7,8, 1, 2,1, 1, 1,1,1,2.5,1,0.7,2.5,1,1,2.5,1,2,1,1,1,2.5,1,0.7,8, 1, 2,1,1,1,8, 1, 2,1,1,1,1,2,8, 1, 1,1,6, 1, 1,1,6, 1, 1,1,2,4, 1, 1,1,4, 1, 2,1,1,1,8, 1, 2,1,1,1,1,2,8, 1, 1,1,2,1,1,2, 1, 2,2,2,1,1,1,8, 1, 3,2,1,2,4,2,1,1,1,2,1,2, 1, 1,1,2,2,2,1,3, 1, 1,1,1,1,1,1,1,1,2,1,1,2,1,1,1,4,4,8, 1, 2,1,6, 1, 1,2,2,2,2,4,8, 1, 2,1,6,1,2,2,1,1,1,6,1,1,6, 1, 2,1,6,1,2,2,2,2,4,8, 1, 2,1,6,1,1,1,4,6, 1, 2,2,1,4,1,2,2,1,4,1,2,1,2,10, 1,1, 4,4,12, 1}; //Page 6

                
int tempo = 120;

void playTone(int ton1, int duration) {
  for (long i = 0; i < duration * 1000L; i += ton1) { 
    tone(speakerPin, ton1);   
    delayMicroseconds(ton1);
  }
  noTone(speakerPin);
}

void playNote(char note, int duration) {
//                        c    c#   d    d#   e    f    f#   g    g#   a    a#   b             d#              f#       g#              a#           D#             F#        G#          A#
  char names[] = { ' ',  '!', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', 'c', 'd', 'r', 'e', 'f', 'm', 'g', 'h',  'a', 'b','s','C', 'D', 'R', 'E', 'F', 'M', 'G', 'H', 'A', 'S', 'B', 'O', 'i', 'N', 'R', 'u', 'L', 'k'}; // [i = b flat] [N = G flat] [R = D#] [u = g#] [1 = C oct. 5] [L = E flat]
  int tones[] =  {   0, 1046, 138, 146, 155, 164, 174, 184, 195, 207, 220, 233, 246, 261, 293, 311, 329, 349, 370, 391, 415, 440, 493, 466 ,523, 587, 622, 659, 698, 740 ,783, 831,880, 932, 987, 1046,466, 740, 622, 415, 622u, 227};
  
  // play the tone corresponding to the note name
  for (int i = 0; i < 42; i++) {
    if (names[i] == note) {
      playTone(tones[i], duration);
    }
  }
}


void setup() {
  pinMode(speakerPin, OUTPUT);
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
//Realizado por © 2017 Sebastian Cuenca ***************
//Comparte, like y comenta :D :D :D ******************* 
//*****************************************************
