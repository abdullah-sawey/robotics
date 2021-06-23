/*
 * pwm.c
 *
 * Created: 2/5/2021 1:25:20 AM
 *  Author: abdul
 */ 
#define F_CPU 8000000UL
#include "pwm.h"
#include "std.h"
#define amp 5
 void setup(void){
	  TCCR0A |= (1<<WGM00)|(1<<WGM01);
	  TCCR1A |= (1 << COM1A1)|(1 << COM1B1);
	  TCCR1A |= (1 << WGM10);
	  TCCR1B |= (1 << WGM12);
	  TCCR2A |= (1 << COM2A1)|(1 << COM2B1);;
	  TCCR2A |= (1 << WGM21) | (1 << WGM20);
	  TCCR2B |= (1 << CS20)| (1 << CS21)| (1 << CS22);
	  TCCR0B |= (1<<CS00)|(1<<CS02);
	  TCCR1B |= (1 << CS10)|(1 << CS12);

 }
 
 
  void anlog_write(int pin , float value)
  {
	   
	   float rduty_cycle;
	   float duty_cycle ;
	   switch (pin)
	   {
	   case 1:
	      SET_BIT( DDRD,DDD6)  ; 
		  rduty_cycle = (value/ amp);
		  duty_cycle =(rduty_cycle*rduty_cycle);
		  OCR0A = (duty_cycle*256) ;
		 if (value!=0) {TCCR0A |= (1<<COM0A1);}
		 if (value==0) {CLR_BIE(TCCR0A,COM0A1);}
		  break;
	
	      case 2:
		  
		  SET_BIT( DDRD,DDD5)  ; 
		  
		  rduty_cycle = (value/ amp);
		  duty_cycle =(rduty_cycle*rduty_cycle);
		  OCR0B = (duty_cycle*256) ;
		 
	   if (value!=0) {TCCR0A |= (1<<COM0B1);}
       if (value==0) {CLR_BIE(TCCR0A,COM0B1);}
		  break;
	  
	 case 3:
		 
	  SET_BIT( DDRB,DDB1)  ; 
		
		  rduty_cycle = (value/ amp);
		  duty_cycle =(rduty_cycle*rduty_cycle);
		  OCR1A = (duty_cycle*256) ;  	 
	  	 if (value!=0) {TCCR1A |= (1 << COM1A1);}
  	     if (value==0) {CLR_BIE(TCCR1A,COM1A1);}
	
		  
		   break;
	  
	 case  4:
	  SET_BIT( DDRB,DDB2)  ; 
		
		  rduty_cycle = (value/ amp);
		  duty_cycle =(rduty_cycle*rduty_cycle);
		  OCR1B = (duty_cycle*256) ;
	   if (value!=0) {TCCR1A |= (1 << COM1B1);}
       if (value==0) {CLR_BIE(TCCR1A,COM1B1);}
		 
		  break;
	  
	  case 5:
		  SET_BIT( DDRB,DDB3)  ; 
		  rduty_cycle = (value/ amp);
		  duty_cycle =(rduty_cycle*rduty_cycle);
		  OCR2A = (duty_cycle*256) ;
	      if (value!=0) {TCCR2A |= (1 << COM2A1);}
          if (value==0) {CLR_BIE(TCCR2A,COM2A1);}
		
		  break;
	  

	  case 6:
		  SET_BIT( DDRD,DDD3) ; 
		 
		  rduty_cycle = (value/ amp);
		  duty_cycle =(rduty_cycle*rduty_cycle);
		  OCR2B = (duty_cycle*256) ;
	    if (value!=0) {TCCR2A |= (1 <<COM2B1);}
        if (value==0) {CLR_BIE(TCCR2A,COM2B1);}
		
		   break;
		   default:
		   break;
     
	   }}	  
