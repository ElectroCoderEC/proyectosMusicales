/*
//**********************************************
//Realizado por: Sebastian Cuenca
//Pueden suscribirse a mi canal de Youtube para mas videos
// https://www.youtube.com/channel/UCSFuCPnuj9d379TgGQ880sw
//**********************************************
*/

int speakerPin = 4;

int length = 191; // Numero de notas (incluido espacios)                                                               
char notes[] = "cgfgegdg ggefgagfed eecdefedc=0 00caggcdefedcdcc=cde !BAGFEDC ccccc-9-c- -------989-9 99998888668468 99-ccccccc-9-c---cddr-989 9-98888gfffrdrcdrrcrrcr rfrdcc-8--8-- 8-cddrcddrc cgfffrfg"; // Reproduccion del tono, cada espacio representa un descanso
float beats[] = {4,1,1,1,1,1,1,1,1, 2,2,1,1,1,1,2,1,2,2,1, 2,2,1,1,1,1,2,1,2,2,2,1, 1,1,2,2,2,1,3,1,1,2, 2,2,2,3,2,2,1,8,8,2,1, 2,2,2,2,2,2,2,4,1, 1,1,1,1,2,1,2,1,2,3,1, 1,1,1,1,1,1,1,1,2,1,2,3,1, 1,2,2,1,2,1,2,2,1,2,2,1,2,6,1, 1,1,1,4,1,1,1,1,1,2,1,2, 1,2,3,1,2,2,1,3,1,2,2,1,6,1, 1,1,1,2,2,1,2,2,1,4,1, 1,1,6,2,2,1,2,1,1,2,1,3,1, 1,1,1,1,1,1,2,1,1,2,1,1,2,1, 1,1,2,1,3,1,5,1,1,2,1,1, 1,2,3,1,1,1,1,10}; //Duracion de cada nota
//                        0                 1                       2                      3                     4                     5                     6                         7                             8                       9                               10                        11                        12                        13                         14                      15                                                                                        
                
int tempo = 170; //Velocidad de reproduccion

void playTone(int ton1, int duration) {
  for (long i = 0; i < duration * 1000L; i += ton1) { 
    tone(speakerPin, ton1);   
    delayMicroseconds(ton1);
  }
  noTone(speakerPin);
}

void playNote(char note, int duration) {
//                        c    c#   d    d#   e    f    f#   g    g#   a    a#   b             d#                  g#              a#           D#                   G#        A#
  char names[] = { ' ',  '!', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', 'c', 'd', 'r', 'e', 'f', 'g', 'S',  'a', 'b','s','C', 'D', 'R', 'E', 'F', 'G', 'O', 'A', 'o', 'B', 'i', 'N', 'R', 'u',  '1', 'L', 'k'}; // Notas musicales
  int tones[] =  {   0, 1046, 138, 146, 155, 164, 174, 184, 195, 207, 220, 233, 246, 261, 293, 311, 329, 349, 391, 415, 440, 493, 466 ,523, 587, 622, 659, 698, 783, 831,880, 932, 987, 466, 740, 622, 415, 1046, 622u, 227}; // Frecuencia de cada nota
  
  // Tocando nota por nota del vector notes[]
  for (int i = 0; i < 40; i++) {
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
//*******************************************************
//Realizado por: Sebastian Cuenca
