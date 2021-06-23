/*
 * UART.c
 *
 * Created: 1/24/2021 4:27:45 AM
 *  Author: abdul
 */ 
#define F_CPU 8000000UL
#include <avr/interrupt.h>
#include <util/delay.h>
#include <avr/io.h>
#include "IncFile1.h"
#include "IncFile2.h"
void timer_wave_fastPWM(void){
	SET_BIT(DDRB,3);
	SET_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
	OCR0 = 92;
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	SET_BIT(TCCR0,COM01);
	SET_BIT(TCCR0,COM00);
	
	
	
}
void timer_cTc_init_interup(void){
	
	
	SET_BIT(TCCR0,WGM01);
	OCR0 =80;
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	sei();
	SET_BIT(TIMSK,OCIE0);
}
void UART_vInit(unsigned long baud)
{
	/*1 - Choose baud rate that will be used by sender and receiver by writing to UBRRL/UBRRH*/
	unsigned short UBRR ;
	UBRR=(F_CPU/(16*baud))-1 ;
	UBRRH=(unsigned char)(UBRR>>8);
	UBRRL=(unsigned char)UBRR;
	/*2 - Enable USART Sender & Receiver*/
	SET_BIT(UCSRB,TXEN);
	SET_BIT(UCSRB,RXEN);
	/*3 - Choose number of data bits to be sent,parity and stop bits from UCSRC
	, We will work with 8 bits data,1 stop bit and no parity bits*/
	UCSRC=(1<<URSEL)|(1<<UCSZ0)|(1<<UCSZ1);
}

void UART_vSendData(char data)
{
	/*Wait for UDR transmit buffer to be empty*/
	while(READ_BIT(UCSRA,UDRE)==0);
	/*Put data to UDR transmit buffer transmit*/
	UDR=data ;
}

char UART_u8ReceiveData(void)
{
	/*Wait for UDR receive buffer to be filled with data*/
	while(READ_BIT(UCSRA,RXC)==0);
	/*Receive data from UDR receive buffer*/
	return UDR ;
}
void UART_vSendstring( char *ptr)
{
	while(*ptr!=0)
	{
		UART_vSendData(*ptr);
		ptr++;
		_delay_ms(100);
	}
}

 