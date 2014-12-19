// Keith Cavanaugh

#include "mylib.h"

u16* vidBuffer = (u16 *)0x6000000;

// void drawFrog(int r, int c, u16 color) {
// 	//
// }

void setPixel(int r, int c, u16 color) {
	*(vidBuffer + (r * 240 + c))= color;
}

void drawRect(int r, int c, int width, int height, u16 color) {
	for (int row = 0 ; row < height ; row++) {
		for (int col = 0 ; col < width ; col++) {
			setPixel(r + row, c + col, color);
		}
	}
}

void drawHollowRect(int r, int c, int width, int height, u16 color) {
	for (int row = 0 ; row < height ; row++) {
		if(row == 0 || row == (height - 1)) {
			for (int col = 0 ; col < width ; col++) {
				setPixel(r + row, c + col, color);
			}
		}
		else {
			for (int col = 0 ; col < width ; col+= (width - 1)) {
				setPixel(r + row, c + col, color);
			}
		}
	}
}

void plotLine(int x0, int y0, int x1, int y1, u16 color) {
	int dx = x1 - x0;
	int dy = y1 - y0;

	int d = (dy << 1) - dx;
	setPixel(x0, y0, color);
	int y = y0;

	for (int x = 0 ; x < x1 ; x++)
		if (d > 0) {
			y++;
			setPixel(x, y, color);
			d = d + ((dy << 1) - (dx << 1));
		}
		else {
			setPixel(x,y, color);
			d = d + (dy << 1);
		}
}

void waitForVBlank()
{
	while(SCANLINECOUNTER > 160);
	while(SCANLINECOUNTER < 160);
}