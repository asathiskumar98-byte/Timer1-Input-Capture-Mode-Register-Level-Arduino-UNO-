⚡ Timer1 Input Capture Mode — Register-Level (Arduino UNO)

This project demonstrates Timer1 Input Capture Mode on ATmega328P (Arduino UNO) using register-level programming.
The timer captures the value of TCNT1 whenever a rising edge appears on the ICP1 pin (PD6 / Arduino D8) and stores it in the ICR1 register.
The captured timer value is displayed via Serial Monitor.

⚙️ Hardware Used

Arduino UNO (ATmega328P)

Signal Source → D8 (ICP1 pin)

USB connection for serial data output

🔌 Pin Configuration
Function	Arduino Pin	ATmega328P Pin	Port
Input Capture (ICP1)	D8	14	PD6
TX (Serial Out)	D1	3	PD1
GND	—	—	—
🧩 Registers Used
Register	Purpose
TCCR1A / TCCR1B	Configure Timer1 mode, edge select, and prescaler
TIMSK1	Enable Input Capture Interrupt
ICR1	Stores the captured timer value
SREG	Enables global interrupt
TCNT1	Timer counter register
TIFR1	Input Capture Flag (handled automatically on ISR)
⚙️ Timer Configuration

Mode: Normal Mode (WGM13:0 = 0)

Edge Select: Rising edge (ICES1 = 1)

Prescaler: 1024 (CS12 + CS10)

Interrupt: Input Capture Interrupt (ICIE1 = 1)

🧠 Working Principle

Timer1 counts continuously with a prescaler of 1024.

When a rising edge appears on the ICP1 (D8) pin:

The current timer value (TCNT1) is copied into ICR1.

The ISR (TIMER1_CAPT_vect) executes.

Inside the ISR, the captured value is printed via the Serial Monitor.

Each edge trigger gives a precise time measurement in timer ticks.

📏 Timing Calculation

At 16 MHz system clock with prescaler = 1024:

Timer frequency = 16,000,000 / 1024 = 15625 Hz
Timer tick = 1 / 15625 = 64 µs per count


If ICR1 = 5000,
→ Captured time = 5000 × 64 µs = 0.32 seconds (320 ms) between two edges.

🧪 Example Output (Serial Monitor)
Captured Value: 5000
Captured Value: 5200
Captured Value: 5100


Each value corresponds to the timer count at the moment the rising edge occurred.

💡 Applications

Frequency measurement

Pulse width and duty cycle analysis

Signal timing or RPM measurement

Ultrasonic or sensor timing experiments
