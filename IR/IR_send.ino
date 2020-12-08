// This sketch will send out a Nikon D50 trigger signal (probably works with most Nikons)
// See the full tutorial at http://www.ladyada.net/learn/sensors/ir.html
// this code is public domain, please enjoy!
 
int IRledPin =  3;    // LED connected to digital pin 13
byte serialA;
// The setup() method runs once, when the sketch starts
 
void setup()   {                
  // initialize the IR digital pin as an output:
  pinMode(IRledPin, OUTPUT);      
 
  Serial.begin(9600);
}
 
void loop()                     
{
  if (Serial.available() > 0) {
    serialA = Serial.read();
    Serial.println(serialA);
  }
  if(serialA == '1'){
    Serial.println("Sending IR On/Off signal");
    SendOnCode();
    delay(500);
    SendOffCode();
  }else if(serialA == '2'){
    Serial.println("Sending IR On signal");
    SendOnCode();
  }else if(serialA == '3'){
    Serial.println("Sending IR Off signal");
    SendOffCode();
  }
}
 
// This procedure sends a 38KHz pulse to the IRledPin 
// for a certain # of microseconds. We'll use this whenever we need to send codes
void pulseIR(long microsecs) {
  // we'll count down from the number of microseconds we are told to wait
 
  cli();  // this turns off any background interrupts
 
  while (microsecs > 0) {
    // 38 kHz is about 13 microseconds high and 13 microseconds low
   digitalWrite(IRledPin, HIGH);  // this takes about 3 microseconds to happen
   delayMicroseconds(10);         // hang out for 10 microseconds
   digitalWrite(IRledPin, LOW);   // this also takes about 3 microseconds
   delayMicroseconds(10);         // hang out for 10 microseconds
 
   // so 26 microseconds altogether
   microsecs -= 26;
  }
 
  sei();  // this turns them back on
}
 
void SendOnCode() {
  // This is the code for the turning on toshiba tv
  pulseIR(9280);
  delayMicroseconds(4640); 
  pulseIR(560);
  delayMicroseconds(580); 
  pulseIR(560);
  delayMicroseconds(560); 
  pulseIR(600);
  delayMicroseconds(580); 
  pulseIR(560);
  delayMicroseconds(580); 
  pulseIR(560);
  delayMicroseconds(560); 
  pulseIR(580);
  delayMicroseconds(560); 
  pulseIR(580);
  delayMicroseconds(1720); 
  pulseIR(560);
  delayMicroseconds(580); 
  pulseIR(560);
  delayMicroseconds(1760); 
  pulseIR(580);
  delayMicroseconds(1760); 
  pulseIR(560);
  delayMicroseconds(1760); 
  pulseIR(580);
  delayMicroseconds(1740); 
  pulseIR(580);
  delayMicroseconds(1760); 
  pulseIR(560);
  delayMicroseconds(1760); 
  pulseIR(580);
  delayMicroseconds(560); 
  pulseIR(600);
  delayMicroseconds(1720); 
  pulseIR(580);
  delayMicroseconds(560); 
  pulseIR(600);
  delayMicroseconds(1740); 
  pulseIR(560);
  delayMicroseconds(580); 
  pulseIR(560);
  delayMicroseconds(580); 
  pulseIR(560);
  delayMicroseconds(1760); 
  pulseIR(560);
  delayMicroseconds(580); 
  pulseIR(560);
  delayMicroseconds(580); 
  pulseIR(600);
  delayMicroseconds(560); 
  pulseIR(560);
  delayMicroseconds(1740); 
  pulseIR(560);
  delayMicroseconds(580); 
  pulseIR(600);
  delayMicroseconds(1720); 
  pulseIR(560);
  delayMicroseconds(1780); 
  pulseIR(560);
  delayMicroseconds(580); 
  pulseIR(580);
  delayMicroseconds(1740); 
  pulseIR(560);
  delayMicroseconds(1760); 
  pulseIR(580);
  delayMicroseconds(1760); 
  pulseIR(560);
  delayMicroseconds(41080); 
  pulseIR(9280);
  delayMicroseconds(2340); 
  pulseIR(580);
  delayMicroseconds(33204); 
  pulseIR(9260);
  delayMicroseconds(2360); 
  pulseIR(580);
  
}

void SendOffCode() {
  // This is the code for the turning off toshiba tv
  pulseIR(9300);
  delayMicroseconds(4580); 
  pulseIR(620);
  delayMicroseconds(540); 
  pulseIR(600);
  delayMicroseconds(520); 
  pulseIR(620);
  delayMicroseconds(520); 
  pulseIR(600);
  delayMicroseconds(540); 
  pulseIR(600);
  delayMicroseconds(540); 
  pulseIR(600);
  delayMicroseconds(540); 
  pulseIR(600);
  delayMicroseconds(1720); 
  pulseIR(600);
  delayMicroseconds(560); 
  pulseIR(580);
  delayMicroseconds(1740); 
  pulseIR(600);
  delayMicroseconds(1720); 
  pulseIR(600);
  delayMicroseconds(1740); 
  pulseIR(580);
  delayMicroseconds(1740); 
  pulseIR(600);
  delayMicroseconds(1720); 
  pulseIR(600);
  delayMicroseconds(1740); 
  pulseIR(600);
  delayMicroseconds(540); 
  pulseIR(600);
  delayMicroseconds(1720); 
  pulseIR(600);
  delayMicroseconds(540); 
  pulseIR(600);
  delayMicroseconds(1720); 
  pulseIR(600);
  delayMicroseconds(560); 
  pulseIR(580);
  delayMicroseconds(540); 
  pulseIR(600);
  delayMicroseconds(1720); 
  pulseIR(620);
  delayMicroseconds(540); 
  pulseIR(600);
  delayMicroseconds(540); 
  pulseIR(580);
  delayMicroseconds(540); 
  pulseIR(600);
  delayMicroseconds(1740); 
  pulseIR(600);
  delayMicroseconds(540); 
  pulseIR(600);
  delayMicroseconds(1720); 
  pulseIR(600);
  delayMicroseconds(1720); 
  pulseIR(620);
  delayMicroseconds(520); 
  pulseIR(600);
  delayMicroseconds(1740); 
  pulseIR(600);
  delayMicroseconds(1720); 
  pulseIR(600);
  delayMicroseconds(1740); 
  pulseIR(600);
  delayMicroseconds(41040); 
  pulseIR(9280);
  delayMicroseconds(2360); 
  pulseIR(600);
  delayMicroseconds(33164); 
  pulseIR(9320);
  delayMicroseconds(2320); 
  pulseIR(600);
}
