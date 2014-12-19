// Keith Cavanaugh

typedef unsigned short u16;

#define REG_DISPCTL *(u16 *)0x4000000

#define MODE3 3
#define BG2_ENABLE (1<<10)
#define SCANLINECOUNTER *(volatile u16 *) 0x4000006

#define OFFSET(r,c,numcols) ((r)*(numcols)+(c))

#define COLOR(r, g, b) ((r) | (g)<<5 | (b)<<10)
#define WHITE COLOR(31,31,31)
#define RED COLOR(31,0,0)
#define GREEN COLOR(0,31,0)
#define BLUE COLOR(0,0,31)
#define CYAN COLOR(0, 31,31)
#define MAGENTA COLOR(31,0,31)
#define YELLOW COLOR(31, 31, 0)
#define GRAY COLOR(15, 15, 15);
#define BLACK 0

// Buttons

#define BUTTON_A		(1<<0)
#define BUTTON_B		(1<<1)
#define BUTTON_SELECT	(1<<2)
#define BUTTON_START	(1<<3)
#define BUTTON_RIGHT	(1<<4)
#define BUTTON_LEFT		(1<<5)
#define BUTTON_UP		(1<<6)
#define BUTTON_DOWN		(1<<7)
#define BUTTON_R		(1<<8)
#define BUTTON_L		(1<<9)

#define KEY_DOWN_NOW(key)  (~(BUTTONS) & key)

#define BUTTONS *(volatile unsigned int *)0x4000130

extern unsigned short *vidBuffer;

typedef struct
{
	int row;
	int col;
	int isLog;
} FROG;

typedef struct
{
	int row;
	int col;
} TRUCK;

typedef struct
{
	int row;
	int col;
} TRUNK;

extern void setPixel(int r, int c, u16 color);
extern void drawRect(int r, int c, int width, int height, u16 color);
extern void drawHollowRect(int r, int c, int width, int height, u16 color);
extern void plotLine(int x0, int y0, int x1, int y1, u16 color);
extern void waitForVBlank();

//extern u16 *videoBuffer;

