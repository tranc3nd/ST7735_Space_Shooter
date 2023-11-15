// Walk_Man.c
// Runs on TM4C123
// Uses ST7735.c LCD.
// Jonathan Valvano
// August 5, 2015
// Possible main program to test the lab
// Feel free to edit this to match your specifications

// Backlight (pin 10) connected to +3.3 V
// MISO (pin 9) unconnected 
// SCK (pin 8) connected to PA2 (SSI0Clk)
// MOSI (pin 7) connected to PA5 (SSI0Tx)
// TFT_CS (pin 6) connected to PA3 (SSI0Fss)
// CARD_CS (pin 5) unconnected
// Data/Command (pin 4) connected to PA6 (GPIO)
// RESET (pin 3) connected to PA7 (GPIO)
// VCC (pin 2) connected to +3.3 V
// Gnd (pin 1) connected to ground

#include <stdio.h>
#include <stdint.h>
#include "string.h"
#include "ST7735.h"
#include "PLL.h"
#include "walking.h"
#include "tm4c123gh6pm.h"

void DelayWait10ms(uint32_t n);


int main(void){
	uint32_t x = 40, ht = 0;	
	int32_t l = 15, h = 15;
	
//  PLL_Init(12);
  PLL_Init(Bus80MHz);
	
  ST7735_InitR(INITR_REDTAB);
	
	// DRAW THE GROUND
	//ST7735_FillScreen(ST7735_CYAN);
	//ST7735_FillRect(0, 150,128, 30, ST7735_GREEN);
	  
	// DRAW THE SUN
	//ST7735_FillCircle(100, 30, 15,ST7735_YELLOW);
	
	// test some driver functions
	/*ST7735_DrawChar(0,0,'J',ST7735_RED,ST7735_GREEN, 3);
	ST7735_DrawChar(20,0,'A',ST7735_RED,ST7735_GREEN, 3);
	ST7735_DrawChar(40,0,'S',ST7735_RED,ST7735_GREEN, 3);
	ST7735_DrawChar(60,0,'O',ST7735_RED,ST7735_GREEN, 3);
	ST7735_DrawChar(80,0,'N',ST7735_RED,ST7735_GREEN, 3);
	*/
	
	//ST7735_DrawBitmap(0, 117, Calvin, 128, 160);
	ST7735_FillScreen(ST7735_WHITE);
	ST7735_FillRect(0, 0, 128, 30, ST7735_YELLOW);
	ST7735_FillRect(0, , 128, 30, ST7735_YELLOW);
	//ST7735_DrawCircle( 20, 65, 15,ST7735_GREEN);							//face
	//ST7735_FillCircle(20, 65, 15, ST7735_RED);
	
  while(1){
		/*
		// DRAW THE MAN
		ST7735_XYPlotMan( x, l, h, ST7735_RED);		
		DelayWait10ms(10);
			
		// REMOVE THE MAN
		ST7735_XYPlotMan( x, l, h, ST7735_CYAN);
	 
		// MOVE THE COORDINATES OF THE MAN
		x++;
	 
		// CODE for MOVING the LEG
		l--;
		if (l == -15)
				l = 15;
	 
		// CODE for MOVING the HAND    
		if (ht == 1)
				h++;
		else
				h--;
	 
		if (h == 15)
			 ht = 0;
		else if (h == -15)   
			ht = 1;
	 
		//Reset parameters
		if(x>170){
			x = 40, ht = 0,l = 15, h = 15;
		}
		*/
		DelayWait10ms(500);	
		ST7735_FillCircle(40, 65, 15, ST7735_RED);
		DelayWait10ms(500);					
		ST7735_FillCircle(40, 65, 15, ST7735_WHITE);
		DelayWait10ms(500);							
		ST7735_FillCircle(80, 65, 15, ST7735_BLUE);
		DelayWait10ms(500);						
		ST7735_FillCircle(80, 65, 15, ST7735_WHITE);
		DelayWait10ms(500);								
		ST7735_FillCircle(60, 100, 15, ST7735_BLACK);
		DelayWait10ms(500);					
		ST7735_FillCircle(60, 100, 15, ST7735_WHITE);
	}
	
} 


// Subroutine to wait 10 msec
// Inputs: None
// Outputs: None
// Notes: ...
void DelayWait10ms(uint32_t n){uint32_t volatile time;
  while(n){
//    time = 727240*2/91;  // 10msec for launchpad
    time = 727240/91;  // for simulation
    while(time){
	  	time--;
    }
    n--;
  }
}



