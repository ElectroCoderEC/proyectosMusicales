//*****************************************************
//Realizado por © 2016 Sebastian Cuenca ***************
//Comparte, like y comenta :D :D :D ******************* 
//*****************************************************



int statePin = LOW; 
int speakerPin = 4;

int length = 238; // Numero de notas (incluido espacios)                                                                                                            //10                                          178 bbsbIIRIRIIsIIMMUBRFMFHFRRIIIIIbbsbIIRIRIRIbshsbIRFMMMHMFR
char notes[] = "RsRFSFRsRsRFSFRsRsRFSFRsRsRFSMRFRMRFMRFRMRFMRFRMRFMRFRMFVUBSHSBUVTWWWX sMHFMSS MMFR bIRMHF IIRFMHMFD sMHFMSS MMFR bIRRMHF IMHFRIRM IIhIRF RRFMFRRRIhhIsshmRFM IsIMSUWRFMFHFRRIIII IbbsbIIRIRFMsIISUWRFMFHFRRIIII IbbsbIIRIRFMIbshsb IRFMMMHMFR"; // // Reproduccion del tono, cada espacio representa un descanso
float beats[] = {0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,3,1,1,1,1,1,1,3,1,1,1,1,1,1,3,1,1,1,1,1,1,3,1,1,1,1,3,6,3,1,6,1,1,6,1,1,1,1,1,1,6, 1, 3,8,1,1,6,2,2, 1, 3,1,3,6, 1, 1,1,6,1,1,6, 1, 1,1,3,3,3,3,1,3,4, 1, 3,6,1,1,6,2,2, 1, 3,1,3,6, 1, 1,1,6,1,1,1,6, 1, 3,3,3,1,1,1,4,8, 1, 1,3,3,3,1,3, 4, 1,3,3,3,1,6,1,1,3,1,3,1,10,1,1,1,8,6,10, 1, 6,3,1,8,3,1,4,3,1,3,6,3,3,3,3,1,6,3,10, 1, 3,1,1,1,3,1,1,3,1,3,6,8,3,1,8,3,1,3,3,1,3,6,3,6,3,3,1,6,3,8, 1, 3,1,1,1,3,1,1,3,1,3,6,8,3,1,8,1,1,8, 1, 1,1,1,1,1,1,3,1,1,6}; //Duracion de cada nota
                                                                                                                                                                                                                                                                                                                                                                                //             
                
int tempo = 110;       //Velocidad de reproduccion

void playTone(int ton1, int duration) {
  for (long i = 0; i < duration * 1000L; i += ton1) { 
    tone(speakerPin, ton1);   
    delayMicroseconds(ton1);
  }
  noTone(speakerPin);
}


//Notas frecuencias de notas musicales arduino
//******************************************* 
void playNote(char note, int duration) {
//                         c#   d    d#   e    f    f#   g    g#   a    a#   b             d#              f#       g#              a#       C#      D#             F#        G#          A#       Do   C#   Re  D#    Mi  Fa F#  G#
  char names[] = { ' ',   '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', 'c', 'd', 'r', 'e', 'f', 'm', 'g', 'h',  'a', 'b','s','C', 'I','D', 'R', 'E', 'F', 'M', 'G', 'H', 'A', 'S', 'B', 'O', 'U', 'P', 'V', 'Q','T','W','X' };  // Notas musicales
  int tones[] =  {   0,  138, 146, 155, 164, 174, 184, 195, 207, 220, 233, 246, 261, 293, 311, 329, 349, 370, 391, 415, 440, 493, 466 ,523, 554,  587, 622, 659, 698, 740 ,783, 831,880, 932, 987, 1046,1108,1174,1244,1318,1397,1480,1661}; // Frecuencia de cada nota
  
  // Tocando nota por nota del vector notes[]
  for (int i = 0; i < 43; i++) {
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
   
    // Pausa entre notas
    delay(tempo / 2); 
  }
}

//*****************************************************
//Realizado por © 2016 Sebastian Cuenca ***************
//Comparte, like y comenta :D :D :D ******************* 
//*****************************************************
