    /* Raw IR decoder sketch!
    This sketch/program uses the Arduno and a PNA4602 to
    decode IR received. This can be used to make a IR receiver
    (by looking for a particular code)
    or transmitter (by pulsing an IR LED at ~38KHz for the
    durations detected
    Code is public domain, check out www.ladyada.net and adafruit.com
    for more tutorials!
    */
     
    // We need to use the 'raw' pin reading methods
    // because timing is very important here and the digitalRead()
    // procedure is slower!
    //uint8_t IRpin = 2;
    // Digital pin #2 is the same as Pin D2 see
    #define IRpin_PIN PIND
    #define IRpin 2
    // for MEGA use these!
    //#define IRpin_PIN PINE
    //#define IRpin 4
     
    #define MAXPULSE 65000
     
    // what our timing resolution should be, larger is better
    // as its more 'precise' - but too large and you wont get
    // accurate timing
    #define RESOLUTION 20
     
    // we will store up to 100 pulse pairs (this is -a lot-)
    uint16_t pulses[100][2]; // pair is high and low pulse
    uint8_t currentpulse = 0; // index for pulses we're storing
     
    void setup(void) {
    Serial.begin(9600);
    Serial.println("Ready to decode IR!");
    }
     
    void loop(void) {
    uint16_t highpulse, lowpulse;
    highpulse = lowpulse = 0;
    while (IRpin_PIN & (1 << IRpin)) {
    highpulse++;
    delayMicroseconds(RESOLUTION);
     
    if ((highpulse >= MAXPULSE) && (currentpulse != 0)) {
    printpulses();
    currentpulse=0;
    return;
    }
    }
    // we didn't time out so lets stash the reading
    pulses[currentpulse][0] = highpulse;
    // same as above
    while (! (IRpin_PIN & _BV(IRpin))) {
    // pin is still LOW
    lowpulse++;
    delayMicroseconds(RESOLUTION);
    if ((lowpulse >= MAXPULSE) && (currentpulse != 0)) {
    printpulses();
    currentpulse=0;
    return;
    }
    }
    pulses[currentpulse][1] = lowpulse;
     
    // we read one high-low pulse successfully, continue!
    currentpulse++;
    }
     
    //IMPORTANT: Delete the first delayMicroseconds, it's useless and will add unnecessary time to the operation. 
    void printpulses(void) {
    Serial.println("\n\r\n\rReceived: \n\rOFF \tON");
    for (uint8_t i = 0; i < currentpulse; i++) {
    Serial.print("delayMicroseconds(");
    Serial.print(pulses[i][0] * RESOLUTION, DEC);
    Serial.print("); ");
    Serial.print("\n");
    Serial.print("pulseIR(");
    Serial.print(pulses[i][1] * RESOLUTION, DEC);
    Serial.print(");");
    Serial.print("\n");
    }
}
