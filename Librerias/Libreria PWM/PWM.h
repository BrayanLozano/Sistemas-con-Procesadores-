#ifndef PWM_H
#define PWM_H

void initPWM();
void initDutyCycle(char Buf, int util, int per);
void initSetper(int numHerz,int escaler);
void initEnableDisable(char chanel , int OnOff);


#endif 
