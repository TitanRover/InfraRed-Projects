#include <IRremote.h>

int RECV_PIN = 11;

int one = 7;                 
int two = 2;                
int three = 3;                
int four = 4;  
int five = 5;
int six = 6;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  pinMode(one, OUTPUT);      // sets the digital pin as output
  pinMode(two, OUTPUT);      // sets the digital pin as output
  pinMode(three, OUTPUT);      // sets the digital pin as output
  pinMode(four, OUTPUT);      // sets the digital pin as output
  pinMode(five, OUTPUT);
  pinMode(six, OUTPUT);
  
}

void loop() {
  if (irrecv.decode(&results)) {
    
    long int decCode = results.value;
    Serial.println(decCode);
    switch (results.value) {
      case 150433935:
        Serial.println("POWER");
        digitalWrite(one,HIGH);
       break;
      case 150429855:
        Serial.println("RESET");
        digitalWrite(two,HIGH);
        break;
      case 150423735:
        Serial.println("LOOP LEFT");
        digitalWrite(one,LOW);
        break;
      case 150421695:
        Serial.println("LOOP RIGHT");
        digitalWrite(two,LOW);
        break;  
      case 150427815:
        Serial.println("MENU");
        digitalWrite(three,HIGH);
        break;
      case 150469125:
        Serial.println("ENTER");
        digitalWrite(three,LOW);
        break;    
        case 150458925:
        Serial.println("REWIND");
        digitalWrite(one,HIGH);
        digitalWrite(two,HIGH);
        digitalWrite(three,HIGH);
        digitalWrite(four,HIGH);
        digitalWrite(five,HIGH);
        digitalWrite(six,HIGH);

        break;
        case 150435975:
        Serial.println("FAST FORWARD");
        digitalWrite(one,LOW);
        digitalWrite(two,LOW);
        digitalWrite(three,LOW);
        digitalWrite(four,LOW);
        digitalWrite(five,LOW);
        digitalWrite(six,LOW);
        
        break;
        case 150414045:
        Serial.println("PLAY / PAUSE");
        break;
        case 150405375:
        Serial.println("TREBLE (+)");
        digitalWrite(four,HIGH);
        break;
        case 150413535:
        Serial.println("TREBLE (-)");
        digitalWrite(four,LOW);
        break;
        case 150438015:
        Serial.println("BASS (+)");
        digitalWrite(five,HIGH);
        break;
        case 150442095:
        Serial.println("BASS (-)");
        digitalWrite(five,LOW);
        break;
        case 150454335:
        Serial.println("VOLUME (+)");
        digitalWrite(six,HIGH);
        break;
        case 150466575:
        Serial.println("VOLUME (-)");
        digitalWrite(six,LOW);
        break;
      default: 
        Serial.println("Waiting ...");
    }

    irrecv.resume(); // Receive the next value
  }
}

