#include "PWM.h"

void initPWM(void){
	
	PORTE.DIRSET |= 0x07;//Enable pin 0,1 y 2 as Outputs
	PORTE.OUTSET |= 0x07; //set pin 0,1 y 2 high.
	
	TCE0.CTRLB |=0x03; // set singelslope
	TCE0.CTRLA |=0x01; // set prescaler div 1
	
	 
  /*TCE0.CTRLB |= 0x70; // set ch A, B y C enable
	//TCE0.PER = per;    // per = 4000, fpwm=fclk/per/TCE0.PER @Fpwm=500Hz
	
	TCE0.CCABUF = 2000;
	TCE0.CCABUF = 3000;
	TCE0.CCABUF = 1000;
  */
	
}

//--------------------------------------------------
void initDutyCycle(char Buf, int util, int per){
	
	if (Buf == 'A'){ TCE0.CCABUF = floor(per/util); }
	if (Buf == 'B'){ TCE0.CCBBUF = floor(per/util); }
	if (Buf == 'C'){ TCE0.CCCBUF = floor(per/util); }
	if (Buf == 'D'){ TCE0.CCDBUF = floor(per/util); }
}

//-------------------------------------------------
int initSetper(int numHerz,int escaler){
	int per=0;
	TCE0.PER = floor( 2000000/escaler/numHerz ); 
	per = floor( 2000000/escaler/numHerz );
	
	return per;
}

//-------------------------------------------------

#define enableA 0x10
#define enableB 0x20
#define enableC 0x40
#define enableD 0x80

void initEnableDisable(char chanel , int OnOff){
	
	if (chanel == 'A'){
		if ( OnOff == 1 ) { TCE0.CTRLB |= enableA; }
		else ( OnOff == 0 ) { TCE0.CTRLB &= ~enableA; }
	}
	if (chanel == 'B'){
		if ( OnOff == 1 ) { TCE0.CTRLB |= enableB; }
		else ( OnOff == 0 ) { TCE0.CTRLB &= ~enableB; }
	}
	if (chanel == 'C'){
		if ( OnOff == 1 ) { TCE0.CTRLB |= enableC; }
		else ( OnOff == 0 ) { TCE0.CTRLB &= ~enableC; }
	}
	if (chanel == 'D'){
		if ( OnOff == 1 ) { TCE0.CTRLB |= enableD; }
		else ( OnOff == 0 ) { TCE0.CTRLB &= ~enableD; }
	}
	
}
