/*
Student ID: B00163482
Student Name: Raja M. Sumeer
Module: Microcontroller Applications @ Year 2, Semester 2 (Technological University Dublin - Blanch Campus)

Date: 18/02/2025

Code Purpose:
LAB 4
- 

Rightful Authors:

Additional Comments:

*/
#include <avr/io.h>

#define F_CPU 16000000UL
#include <util/delay.h>
int main(void)
{
    // USART Control and Status Register B: Transmitter & Reciever (enabling)
    UCSR0B |=((1<<TXEN0) | (1<<RXEN0));

    // USART Control and Status Register C: (comm)
    // UMSEL Mode: 0 = Asynchronous (only two lines TX/RX) 
    UCSR0C &= ~((0<<UMSEL00) | (0<<UMSEL01) | (0<<UPM00) | (0<<UPM01) | (0<<USBS0) | (1<<UCSZ00) | (1<<UCSZ01));

    UBRR0 = 103; // Set Baud Rate (bps)
    //9600

    // char character;

    // Set Pin 5 as output on PORTB
    DDRB |= (1<<5);
    while(1) {
        // if char recieved (RXD)
        if (UCSR0A & (1<<RXC0)) {
            // write & read from buffer
            // get char out of USART buffer
            UDR0 = 'a';
            _delay_ms(1000);
        }
    }
    return 0;
}
