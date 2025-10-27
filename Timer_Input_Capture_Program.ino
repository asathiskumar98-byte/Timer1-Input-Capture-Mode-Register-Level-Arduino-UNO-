void setup()
{
  //Enable the Global Interrupt Enable Bit
  SREG |= (1<<7);

  //Enable the Required Timer Interrupt
  TIMSK1 |= (1<<ICIE1);

  //Set Mode of the  Timer
  TCCR1A &= (~(1<<WGM10)) & (~(WGM11));
  TCCR1B &= (~(1<<WGM12)) & (~(WGM13)); // Normal Mode

  //Set the Prescaler for the Timer
  TCCR1B |=  (1<<CS10) | (1<<CS12);
  TCCR1B &=  (~(1<<CS11)); // Prescaler = 1024

  //Start the Period for the Timer
  TCNT1 = 0;

  //Select the  Edge for capturing
  TCCR1B |= (1<<ICES1); //Rising Edge

  Serial.begin(9600);

}

void loop()
{

}

uint16_t captured = 0;
//Implement the ISR Function
ISR(TIMER1_CAPT_vect)
{
  captured = ICR1;
  Serial.print(captured);
  Serial.print('\n');
}
