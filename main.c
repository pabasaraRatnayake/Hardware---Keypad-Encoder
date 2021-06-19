
#define _XTAL_FREQ 20000000

//for keypad_encoder
#define A RB1
#define B RB2
#define C RB3
#define D RB5
#define E RB6

//for LCD
#define RS RD2
#define EN RD3
#define D4 RD4
#define D5 RD5
#define D6 RD6
#define D7 RD7

#include <xc.h>
#include <pic16f877a.h>

// CONFIG (can be auto generated)
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

#include <stdio.h>
#include "lcd.h"


void system_init(void); 

void initKeypad(void){
	OPTION_REG &= 0x7F;    
      }

char keypadScanner(void)	
{	
 while (A==1 && B==1 && C==1 && D==1 && E==0){
        __delay_ms(100);
           if (A==1 && B==1 && C==1 && D==1 && E==0){
            return '1';
           }
       
    }
        while (A==0 && B==1 && C==1 && D==1 && E==0){
          __delay_ms(100);
           if (A==0 && B==1 && C==1 && D==1 && E==0){
            return '2';
           }
        
    }
        while (A==1 && B==0 && C==1 && D==1 && E==0){
          __delay_ms(100);
           if (A==1 && B==0 && C==1 && D==1 && E==0){
            return '3';
           }
        
    }
        while (A==1 && B==1 && C==0 && D==1 && E==0){
          __delay_ms(100);
           if (A==1 && B==1 && C==0 && D==1 && E==0){
            return '4';
           }
        
    }
        while (A==0 && B==1 && C==0 && D==1 && E==0){
          __delay_ms(100);
           if (A==0 && B==1 && C==0 && D==1 && E==0){
           return '5';
           }
        
    }
        while (A==1 && B==0 && C==0 && D==1 && E==0){
          __delay_ms(100);
           if (A==1 && B==0 && C==0 && D==1 && E==0){
           return '6';
           }
        
    }
        while (A==1 && B==1 && C==1 && D==0 && E==0){
          __delay_ms(100);
           if (A==1 && B==1 && C==1 && D==0 && E==0){
             return '7';
           }
       
    }
        while (A==0 && B==1 && C==1 && D==0 && E==0){
          __delay_ms(100);
           if (A==0 && B==1 && C==1 && D==0 && E==0){
            return '8';
           }
        
    }
        while (A==1 && B==0 && C==1 && D==0 && E==0){
          __delay_ms(100);
           if (A==1 && B==0 && C==1 && D==0 && E==0){
             return '9';
           }
       
    }
        while (A==0 && B==1 && C==0 && D==0 && E==0){
          __delay_ms(100);
           if (A==0 && B==1 && C==0 && D==0 && E==0){
           return '0';
           }
        
    }
        while (A==0 && B==0 && C==1 && D==1 && E==0){
          __delay_ms(100);
           if (A==0 && B==0 && C==1 && D==1 && E==0){
             return 'A';
           }
       
    }
        while (A==0 && B==0 && C==0 && D==1 && E==0){
          __delay_ms(100);
           if (A==0 && B==0 && C==0 && D==1 && E==0){
             return 'B';
           }
       
    }
        while (A==0 && B==0 && C==1 && D==0 && E==0){
          __delay_ms(100);
           if (A==0 && B==0 && C==1 && D==0 && E==0){
            return 'C';
           }
        
    }
        while (A==0 && B==0 && C==0 && D==0 && E==0){
          __delay_ms(100);
           if (A==0 && B==0 && C==0 && D==0 && E==0){
             return 'D';
           }
       
    }
        while (A==1 && B==1 && C==0 && D==0 && E==0){
          __delay_ms(100);
           if (A==1 && B==1 && C==0 && D==0 && E==0){
            return '*';
           }
       
    }
        while (A==1 && B==0 && C==0 && D==0 && E==0){
          __delay_ms(100);
           if (A==1 && B==0 && C==0 && D==0 && E==0){
             return '#';
           }
       
    }
    return 'n'; 
}

char switchPressScan(void)       // Get key from user
{
    char key = 'n';              // Assume no key pressed
    while(key=='n'){		 // Wait untill a key is pressed
        key= keypadScanner();    // Scan the keys again and again
    }		
	  return key;            //when key pressed then return its value
}


void main(void) {  
    //Initiate ports and other services
    system_init(); 

    while(1){

       Lcd_Clear();
       char key_returned = switchPressScan();
       Lcd_Print_Char(key_returned); 
      __delay_ms(5000); 

      }  
   }

void system_init(void){
   TRISD = 0x00;
   PORTD = 0x00;
  initKeypad(); //initialize keypad
   Lcd_Start();
}






