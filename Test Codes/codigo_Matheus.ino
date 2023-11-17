#define  pwm  11
#define pwm2   9
void setFrequency(char option);     //Seleciona a frequência de operação do PWM
void setDuty_pin10(float value);    //Seleciona o duty cycle na saída digital 11


float sine;
int sine_i;


void setup() 
{
   pinMode(pwm, OUTPUT);
   pinMode(10, OUTPUT);
   TCCR2A = 0xA3;         //Configura operação em fast PWM, utilizando registradores OCR2x para comparação
                         //1010 0011
    setFrequency(2);       //Seleciona opção 4 para frequência PWM (aprox 7.8kHz)
    setDuty_pin10(50);     //Saída 11 com duty de 20%                    
   Serial.begin(9600);

}

void loop() 
{
  for(int i=-180;i<=180;i+=1)
  {
     sine = sin(i*(3.1415/180.0));
     sine_i = 127+int(sine*255.0/2.0);

     analogWrite(pwm, sine_i);
     analogWrite(pwm2, 127);

     Serial.println(sine_i);
     delay(5);
  
  } //end for

}

void setDuty_pin10(float value)
{
   int duty;
   
   value = value/100;
   
   duty = (value * 256) - 1;
   
   OCR2A = duty;

} //end setDuty_pin11




void setFrequency(char option)
{
  /*
  TABLE:
  
      option  frequency
        
        1      62.5  kHz
        2       7.81 kHz
        3       1.95 kHz
        4     976.56  Hz
        5     488.28  Hz
        6     244.14  Hz
        7      61.03  Hz   
  */
  TCCR2B = option;
  
   

} //end setFrequency