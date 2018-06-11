#include <Servo.h>
#include <IRremote.h>


int RECV_PIN = 9;
IRrecv irrecv(RECV_PIN);
decode_results results;
int posy;
int posx;
int d = 5; // grade beweeg per click

Servo servox;
Servo servoy;

void setup() {              

Serial.begin(9600);
  irrecv.enableIRIn();

servoy.attach(10); 
servox.attach(11);
}


void loop() {

  posx = constrain(posx, 0, 180);
  posy = constrain(posy, 0, 180);
  
if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    switch(results.value) { 
      
      case 150458925: 
      posx = posx - d;
        servox.write(posx);
        break;
        
      case 150435975:
      posx = posx + d;
        servox.write(posx);
        break;
        
        case 150427815: 
      posy = posy - d;
        servoy.write(posy);
        break;
        
      case 150414045:
      posy = posy + d;
        servoy.write(posy);
        break;
        
        case 150429855:
        servoy.write(90);
        posy = 90;
        break;
        
        case 150433935:
        servox.write(90);
        posx = 90;
        break;
        
        case 150405375:
        servox.write(0);
        posx = 0;
        break;
        
        case 150413535:
        servox.write(180);
        posx = 180;
        break;
        
        case 150454335:
        servoy.write(0);
        posy = 0;
        break;
        
        case 150466575:
        servoy.write(180);
        posy = 180;
        break;
        
        case 150469125:
        servoy.write(90);
        posy = 90;
        servox.write(90);
        posx = 90;
        break;
    }
    irrecv.resume();
}
}
