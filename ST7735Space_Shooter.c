// ST7735Space_Shooter.c
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
#include "tm4c123gh6pm.h"
#include "SysTick.h"


int main(void){
	// Initialize Ball location
	uint32_t x0 = 40, y0 = 80, r = 15;
	
	// Initialize horizontal line
	uint32_t x1 = 60, y1 = 80, x2 = 80, y2 = 80;
	
	// Initialize wing
	uint32_t wxb = 28, wyb = 88, wlb = 20;
	
  // PLL_Init(12);
  PLL_Init(Bus80MHz);
	SysTick_Init();
	
  ST7735_InitR(INITR_REDTAB);
	
	// Create background
	ST7735_FillScreen(ST7735_WHITE);
	ST7735_FillRect(0, 0, 128, 30, ST7735_BLACK);
	ST7735_FillRect(0, 130, 128, 30, ST7735_BLACK);
	
	// Create wall to destory
	ST7735_FillRect(120, 30,128, 100, ST7735_MAGENTA);
	
	// Write Space string
	ST7735_DrawChar(0+15, 5,'S',ST7735_RED,ST7735_BLACK, 3);
	ST7735_DrawChar(20+15,5,'P',ST7735_BLUE,ST7735_BLACK, 3);
	ST7735_DrawChar(40+15,5,'@',ST7735_YELLOW,ST7735_BLACK, 3);
	ST7735_DrawChar(60+15,5,'C',ST7735_GREEN,ST7735_BLACK, 3);
	ST7735_DrawChar(80+15,5,'E',ST7735_RED,ST7735_BLACK, 3);
	// Write Shooter string
	ST7735_DrawChar(0+10,132,'S',ST7735_RED,ST7735_BLACK, 3);
	ST7735_DrawChar(20+10,132,'H',ST7735_BLUE,ST7735_BLACK, 2);
	ST7735_DrawChar(35+10,132,'0',ST7735_YELLOW,ST7735_BLACK, 1);
	ST7735_DrawChar(50+10,132,'0',ST7735_YELLOW,ST7735_BLACK, 1);
	ST7735_DrawChar(65+10,132,'T',ST7735_CYAN,ST7735_BLACK, 2);
	ST7735_DrawChar(80+10,132,'E',ST7735_GREEN,ST7735_BLACK, 2);
	ST7735_DrawChar(95+10,132,'R',ST7735_RED,ST7735_BLACK, 2);

	
  while(1){
		y0++;
		wyb++;
		x1++;
		x2++;

		// Moving Spaceship shooter
		ST7735_DrawCircle( x0, y0, r,ST7735_BLACK);
		ST7735_FillCircle(x0, y0, r-2, ST7735_CYAN);
		ST7735_DrawFastVLine(wxb, wyb, wlb, ST7735_BLACK);
		ST7735_DrawLine(wxb, wyb+20, wxb+20, wyb+5,ST7735_BLACK);
		ST7735_DrawFastVLine(wxb, wyb-37, wlb, ST7735_BLACK);
		ST7735_DrawLine(wxb, wyb-37, wxb+20, wyb-21,ST7735_BLACK);
		ST7735_DrawLine(x1, y1-5, x2, y2-5,ST7735_RED );
		ST7735_DrawLine(x1, y1-7, x2, y2-7,ST7735_RED );
		ST7735_DrawLine(x1, y1, x2+10, y2,ST7735_BLUE );
		ST7735_DrawLine(x1, y1+5, x2, y2+5,ST7735_RED );
		ST7735_DrawLine(x1, y1+7, x2, y2+7,ST7735_RED );
		SysTick_Wait10ms(4);
		ST7735_DrawCircle( x0, y0, r,ST7735_WHITE);
		ST7735_FillCircle(x0, y0, r-2, ST7735_WHITE);
		ST7735_DrawFastVLine(wxb, wyb, wlb, ST7735_WHITE);
		ST7735_DrawLine(wxb, wyb+20, wxb+20, wyb+5,ST7735_WHITE);
		ST7735_DrawFastVLine(wxb, wyb-37, wlb, ST7735_WHITE);
		ST7735_DrawLine(wxb, wyb-37, wxb+20, wyb-21,ST7735_WHITE);
		ST7735_DrawLine(x1, y1-5, x2, y2-5,ST7735_WHITE );
		ST7735_DrawLine(x1, y1-7, x2, y2-7,ST7735_WHITE );
		ST7735_DrawLine(x1, y1, x2+10, y2,ST7735_WHITE );
		ST7735_DrawLine(x1, y1+5, x2, y2+5,ST7735_WHITE );
		ST7735_DrawLine(x1, y1+7, x2, y2+7,ST7735_WHITE );
		
		if(x1>128) {
			x1=60;
			x2=80;
		}
		if(y0==90 && wyb==98) {
			for(int i = 0; i < 20; i++) {
				y0--;
				wyb--;
				x1++;
				x2++;
				
				ST7735_DrawCircle( x0, y0, r,ST7735_BLACK);
				ST7735_FillCircle(x0, y0, r-2, ST7735_CYAN);
				ST7735_DrawFastVLine(wxb, wyb, wlb, ST7735_BLACK);
				ST7735_DrawLine(wxb, wyb+20, wxb+20, wyb+5,ST7735_BLACK);
				ST7735_DrawFastVLine(wxb, wyb-37, wlb, ST7735_BLACK);
				ST7735_DrawLine(wxb, wyb-37, wxb+20, wyb-21,ST7735_BLACK);
				ST7735_DrawLine(x1, y1-5, x2, y2-5,ST7735_RED );
				ST7735_DrawLine(x1, y1-7, x2, y2-7,ST7735_RED );
				ST7735_DrawLine(x1, y1, x2+10, y2,ST7735_BLUE );
				ST7735_DrawLine(x1, y1+5, x2, y2+5,ST7735_RED );
				ST7735_DrawLine(x1, y1+7, x2, y2+7,ST7735_RED );
				SysTick_Wait10ms(4);
				ST7735_DrawCircle( x0, y0, r,ST7735_WHITE);
				ST7735_FillCircle(x0, y0, r-2, ST7735_WHITE);
				ST7735_DrawFastVLine(wxb, wyb, wlb, ST7735_WHITE);
			  ST7735_DrawLine(wxb, wyb+20, wxb+20, wyb+5,ST7735_WHITE);
				ST7735_DrawFastVLine(wxb, wyb-37, wlb, ST7735_WHITE);
				ST7735_DrawLine(wxb, wyb-37, wxb+20, wyb-21,ST7735_WHITE);
				ST7735_DrawLine(x1, y1-5, x2, y2-5,ST7735_WHITE );
				ST7735_DrawLine(x1, y1-7, x2, y2-7,ST7735_WHITE );
				ST7735_DrawLine(x1, y1, x2+10, y2,ST7735_WHITE );
				ST7735_DrawLine(x1, y1+5, x2, y2+5,ST7735_WHITE );
				ST7735_DrawLine(x1, y1+7, x2, y2+7,ST7735_WHITE );
			}
		}
	}
} 





