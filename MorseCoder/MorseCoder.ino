#include"MorseCodes.h"

const int led = 13;

// Argument: Any character
// Return Value: Either:
//                  1) If the character is a letter, the upper case equivalent.  
//                  2) If the character is not a letter, the original value.
char toUpper(char c) {
  if('z'>=c && c>='a'){
    char s = c-32;
    return s;
  }
    return c; 
}

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

unsigned long next = 0;
unsigned long period = 500;
int i = 0;
boolean off = true;
boolean on = false;
boolean moveOn = false;
String words = "";
//write a flag symbols...
//add timing between symbols

void convertIncomingCharsToMorseCode() {
  unsigned long now = millis();
    if(Serial.available()>0 && moveOn == false){
      Serial.print("moveOn");
      char s = Serial.read();
      moveOn = true;
      words = morseEncode(s);
      i = 0;
    }
    if(now > next && words.length()>0){
      if(off == true && on == false){
        if(words[i]=='.'){
          digitalWrite(led, HIGH);
          next = now + period;
          off = false;
          on = true;
          Serial.println(words);
          Serial.println(i);
          Serial.println(words[i]);
          }
        else if(words[i]=='-'){
                digitalWrite(led, HIGH);
                next = now + (3*period);
                off = false;
                on = true;
                Serial.println(words);
                Serial.println(i);
                Serial.println(words[i]);
          }
        else if(words[i]==' '){
                digitalWrite(led, LOW);
                next = now + (7*period);
                off = false;
                on = true;
          }
        }
      else if(on == true){ 
              digitalWrite(led, LOW);
              next = now + period;
              on = false;
              off = true;
              Serial.println("donezo");
              i = i+1;
              if(i == words.length()){
                digitalWrite(led, LOW);
                next = now + (3*period);
                moveOn = false;
              }
            }
    }
}


void loop() {
  // No Need to Modify this.  Put most of your code in "convertIncomingCharsToMorseCode()"
  convertIncomingCharsToMorseCode();
}
