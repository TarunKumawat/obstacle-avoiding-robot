/*
 * hashtag electrical.cpp
 *
 * Created: 16-11-2018 21:22:59
 * Author : HP PC
 */ 

#include <stdio.h>
#include <util/delay.h>
#include <avr/io.h>
#include <avr/sfr_defs.h>

void forward();
void left();
void right();
void hardleft();
void hardright();
void stop();
int prev=0;

void pwm_init()
{
	TCCR0 |=(1<<WGM00) | (1<<WGM01) ;
	TCCR0 |=(1<<COM00) | (1<<COM01) ;
	TCCR0 |=(1<<CS01)
	TCCR0 &= ~(1<<CS02)
	ICR1=1000;
	
}

void forward()
{
	PORTD=0b00010100;
	prev=3;
	OCR1A=1000;
	OCR1B=1000;
}

void left()
{
	PORTD &= ~(1<<PIND4);
	prev=2;
	OCR1A=450;
	OCR1B=450;
}
void right()
{
	PORTD &= ~(1<<PIND2);
	OCR1A=450;
	OCR1B=450;
	prev=4;
}

 void hardleft()
 {
 	PORTD &= ~(1<<PIND4);
	PORTD |= (1<<PIND5);
	OCR1A=750;
	OCR1B=750;
	prev=1;
 }

 void hardright()
 {
	 PORTD &= ~(1<<PIND2);
	 PORTD |= (1<<PIND3);
	 OCR1A=750;
	 OCR1B=750;
 	prev=5;
 } 

void stop()
{
	PORTD &= (5<<PIND2);
	prev=6;
}

int main(void)
{
    /* Replace with your application code */

	
	DDRD=0b11111111;
	DDRA=0b00000000;
	
	
	PORTD=0b00000000;
	
//	forward();
    while (1) ;
	
	
    {
	
	 
	if (	bit_is_clear(PINA,0)&&bit_is_clear(PINA,1)&&bit_is_clear(PINA,2)&&bit_is_clear(PINA,3)&&bit_is_clear(PINA,4)&&bit_is_clear(PINA,5)&&bit_is_clear(PINA,6)&&bit_is_clear(PINA,7))
	{
		if(prev==1)
		{
			right();
		}
		else if(prev==2)
		{
			right();
		}
		else if(prev==3)
		{
			right();
		}
			else if(prev==4)
			{
				left();
			}
			else if(prev==5)
			{
			left();	
			}
			
			else
			{
				stop();
			}
			
		}
		
	else if(bit_is_set(PINA,0)&&bit_is_set(PINA,1)&&bit_is_set(PINA,2)&&bit_is_set(PINA,3)&&bit_is_set(PINA,4)&&bit_is_clear(PINA,5)&&bit_is_clear(PINA,6)&&bit_is_clear(PINA,7))
	{
		stop();
	}
	
	else if(	bit_is_clear(PINA,0)&&bit_is_set(PINA,1)&&bit_is_set(PINA,2)&&bit_is_set(PINA,3)&&bit_is_clear(PINA,4)&&bit_is_clear(PINA,5)&&bit_is_clear(PINA,6)&&bit_is_clear(PINA,7))
	{
		left();
	}	
	else if(	bit_is_set(PINA,0)&&bit_is_set(PINA,1)&&bit_is_set(PINA,2)&&bit_is_clear(PINA,3)&&bit_is_clear(PINA,4)&&bit_is_clear(PINA,5)&&bit_is_clear(PINA,6)&&bit_is_clear(PINA,7))
	{
		left();
	}
	else if(	bit_is_clear(PINA,0)&&bit_is_clear(PINA,1)&&bit_is_set(PINA,2)&&bit_is_set(PINA,3)&&bit_is_set(PINA,4)&&bit_is_clear(PINA,5)&&bit_is_clear(PINA,6)&&bit_is_clear(PINA,7))
	{
		forward();
	}
	else if(	bit_is_clear(PINA,0)&&bit_is_clear(PINA,1)&&bit_is_clear(PINA,2)&&bit_is_set(PINA,3)&&bit_is_set(PINA,4)&&bit_is_set(PINA,5)&&bit_is_clear(PINA,6)&&bit_is_clear(PINA,7))
	{
		forward();
	}
	
	else if( bit_is_clear(PINA,0)&&bit_is_clear(PINA,1)&&bit_is_clear(PINA,2)&&bit_is_clear(PINA,3)&&bit_is_clear(PINA,4)&&bit_is_set(PINA,5)&&bit_is_set(PINA,6)&&bit_is_set(PINA,7))
	{
		
		right();
	}
	else if( bit_is_clear(PINA,0)&&bit_is_clear(PINA,1)&&bit_is_clear(PINA,2)&&bit_is_clear(PINA,3)&&bit_is_set(PINA,4)&&bit_is_set(PINA,5)&&bit_is_set(PINA,6)&&bit_is_clear(PINA,7))
	{
		
		right();
	}
	
	else if( bit_is_set(PINA,0)&&bit_is_set(PINA,1)&&bit_is_clear(PINA,2)&&bit_is_clear(PINA,3)&&bit_is_clear(PINA,4)&&bit_is_clear(PINA,5)&&bit_is_clear(PINA,6)&&bit_is_clear(PINA,7))
	{
	hardleft();	
	}
	else if( bit_is_set(PINA,0)&&bit_is_clear(PINA,1)&&bit_is_clear(PINA,2)&&bit_is_clear(PINA,3)&&bit_is_clear(PINA,4)&&bit_is_clear(PINA,5)&&bit_is_clear(PINA,6)&&bit_is_clear(PINA,7))
	{
		hardleft();
	}
	
	else if( bit_is_clear(PINA,0)&&bit_is_clear(PINA,1)&&bit_is_clear(PINA,2)&&bit_is_clear(PINA,3)&&bit_is_clear(PINA,4)&&bit_is_clear(PINA,5)&&bit_is_set(PINA,6)&&bit_is_set(PINA,7))
	{
		hardright();
	}
	else if( bit_is_clear(PINA,0)&&bit_is_clear(PINA,1)&&bit_is_clear(PINA,2)&&bit_is_clear(PINA,3)&&bit_is_clear(PINA,4)&&bit_is_clear(PINA,5)&&bit_is_clear(PINA,6)&&bit_is_set(PINA,7))
	{
		hardright();
	}
	
	
	}
	}
	
	
	
		
	
    

