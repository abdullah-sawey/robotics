/*
 * UART.h
 *
 * Created: 1/24/2021 4:29:59 AM
 *  Author: abdul
 */ 


#ifndef UART_H_
#define UART_H_
void timer_wave_fastPWM(void);
void UART_vInit(unsigned long baud);
void UART_vSendData(char data);
char UART_u8ReceiveData(void);
void UART_vSendstring( char *ptr);
void timer_cTc_init_interup(void);



#endif /* UART_H_ */