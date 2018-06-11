int detect = 12;
int nodetect = 11;
int pir = 2;

void setup()  {
 pinMode(pir,INPUT);
 pinMode(11,OUTPUT);
 pinMode(12,OUTPUT);
}
void loop()  {
 while(1)  {
   delay(100);
   if(digitalRead(2)==LOW)  {
     digitalWrite(11,HIGH);
   }
   else  {
     digitalWrite(11,LOW);
   }
   if(digitalRead(2)==HIGH)  {
     digitalWrite(12,HIGH);
   }
   else  {
     digitalWrite(12,LOW);
   }
 }

}
