// Keith Cavanaugh

#include "mylib.h"
#include "text.h"

#define MODE3 3
#define BG2_ENABLE (1<<10)
#define RGB(r,g,b) ((r) | (g) << 5 | (b) <<10)

void splash();
void win();
int game();
void lose();

enum {SPLASH, GAME, WIN, LOSE};

int main(void) {
	REG_DISPCTL = MODE3 | BG2_ENABLE;

	int state = SPLASH;
	while(1)
	{
		switch(state)
		{
			case SPLASH:
			splash();
			state = GAME;
			break;
			case GAME:
			state = game();
			break;
			case WIN:
			win();
			state = SPLASH;
			break;
			case LOSE:
			lose();
			state = SPLASH;
			break;
		}
	}
}

void splash()
{
	REG_DISPCTL = MODE3 | BG2_ENABLE;
	drawRect(0, 0, 240, 160, GREEN);
	drawString(70, 100, "SLUGGER", YELLOW);
	drawString(90, 90, "Press Start", YELLOW);
	while(!KEY_DOWN_NOW(BUTTON_START))
		while(KEY_DOWN_NOW(BUTTON_START));
}

void win()
{
	drawRect(0, 0, 240, 160, YELLOW);
	drawString(70, 10, "SLUGGER MASTER!!!", BLACK);
	drawString(90, 10, "Press Start", BLACK);
	while(!KEY_DOWN_NOW(BUTTON_START));
	while(KEY_DOWN_NOW(BUTTON_START));
}

void lose()
{
	drawRect(0, 0, 240, 160, RED);
	drawString(70, 10, "FAILURE!", YELLOW);
	drawString(90, 10, "Press Start", YELLOW);
	while(!KEY_DOWN_NOW(BUTTON_START));
	while(KEY_DOWN_NOW(BUTTON_START));
}

int game()
{
	REG_DISPCTL = MODE3 | BG2_ENABLE;

	drawRect(0, 0, 240, 160, YELLOW); // draw background

	drawRect(70, 0, 240, 50, COLOR(15, 15, 15)); // draw road

	drawRect(15, 0, 240, 45, CYAN);

	FROG frog;
	FROG oldFrog;

	TRUCK truck;
	TRUCK oldTruck;
	TRUCK truck2;
	TRUCK oldTruck2;

	TRUNK loggy;
	TRUNK oldLog;
	int lil1;
	int lil2;
	int lil3;

	drawRect(0, 50, 20, 25, MAGENTA);
	drawRect(0, 125, 20, 25, MAGENTA);
	drawRect(0, 200, 20, 25, MAGENTA);

	lil1 = 0;
	lil2 = 0;
	lil3 = 0;

	frog.row = 130;
	frog.col = 120;
	frog.isLog = 0;

	oldFrog.row = 130;
	oldFrog.col = 120;
	oldFrog.isLog = 0;

	truck.row = 100;
	truck.col = 100;
	oldTruck.row = 100;
	oldTruck.col = 100;

	truck2.row = 80;
	truck2.col = 100;
	oldTruck2.row = 80;
	oldTruck2.col = 100;

	loggy.row = 27;
	loggy.col = 0;
	oldLog.row = 27;
	oldLog.col = 0;

	while(1) {

		if(KEY_DOWN_NOW(BUTTON_SELECT))
		{
			return LOSE;
		}

		if(KEY_DOWN_NOW(BUTTON_RIGHT))
		{
			frog.col = frog.col + 1;
		}

		if(KEY_DOWN_NOW(BUTTON_LEFT))
		{
			frog.col = frog.col - 1;
		}

		if(KEY_DOWN_NOW(BUTTON_UP))
		{
			frog.row = frog.row - 1;
		}

		if(KEY_DOWN_NOW(BUTTON_DOWN))
		{
			frog.row = frog.row + 1;
		}

		if(truck.col > 240)
			truck.col = 0;
		else
			truck.col = truck.col + 2;

		if(truck2.col < 0)
			truck2.col = 240;
		else
			truck2.col = truck2.col - 2;


		if(loggy.col > 240)
			loggy.col = 0;
		else
			loggy.col = loggy.col + 1;

		waitForVBlank();

		drawRect(oldFrog.row, oldFrog.col, 10, 10, GREEN); // draw slime

		drawRect(oldLog.row, oldLog.col, 30, 20, CYAN); // draw 
		drawRect(loggy.row, loggy.col, 30, 20, COLOR(31, 20, 5));	// draw log

		drawRect(frog.row, frog.col, 10, 10, COLOR(0, 15, 0));	// draw frog
		setPixel(frog.row + 3, frog.col + 3, BLACK);
		setPixel(frog.row + 3, frog.col + 6, BLACK);

		drawRect(oldTruck.row, oldTruck.col, 20, 10, COLOR(15, 15, 15));
		drawRect(truck.row, truck.col, 20, 10, RED);

		drawRect(oldTruck2.row, oldTruck2.col, 20, 10, COLOR(15, 15, 15));
		drawRect(truck2.row, truck2.col, 20, 10, RED);


		if(frog.col <= loggy.col + 30 && frog.col >= loggy.col && frog.row <=
			loggy.row + 20 && frog.row >= loggy.row)
			frog.isLog = 1;
		else
			frog.isLog = 0;

if (frog.row <= 28 && frog.col >= 47 && frog.col <= 67 && !lil1) {
		lil1 = 1;
		drawRect(10, 55, 10, 10, COLOR(0, 15, 0));	// draw frog
		setPixel(15, 58, BLACK);
		setPixel(15, 62, BLACK);
		frog.row = 130;
		frog.col = 120;
}

if (frog.row <= 28 && frog.col >= 122 && frog.col <= 142 && !lil2) {
		lil2 = 1;
		drawRect(10, 130, 10, 10, COLOR(0, 15, 0));	// draw frog
		setPixel(15, 133, BLACK);
		setPixel(15, 137, BLACK);
		frog.row = 130;
		frog.col = 120;
}

if (frog.row <= 28 && frog.col >= 197 && frog.col <= 217 && !lil3) {
		lil3 = 1;
		drawRect(10, 205, 10, 10, COLOR(0, 15, 0));	// draw frog
		setPixel(15, 208, BLACK);
		setPixel(15, 212, BLACK);
		frog.row = 130;
		frog.col = 120;
}

if (!lil1)
drawRect(0, 50, 20, 25, MAGENTA);			// draw lillies
if(!lil2)
	drawRect(0, 125, 20, 25, MAGENTA);
if(!lil3)
	drawRect(0, 200, 20, 25, MAGENTA);

if(lil1 && lil2 && lil3)
	return WIN;

		if(frog.row >=15 && frog.row <= 45 && !frog.isLog)
			return LOSE;

		if(frog.col <= truck.col + 20 && frog.col >= truck.col && frog.row <=
			truck.row + 10 && frog.row >= truck.row)
			return LOSE;

		if(frog.col <= truck2.col + 20 && frog.col >= truck2.col && frog.row <=
			truck2.row + 10 && frog.row >= truck2.row)
			return LOSE;

		oldFrog.row = frog.row;
		oldFrog.col = frog.col;

		oldTruck.col = truck.col;
		oldTruck2.col = truck2.col;

		oldLog.col = loggy.col;
	}
	return 1;
}