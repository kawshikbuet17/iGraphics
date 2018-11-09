/*
KAWSHIK KUMAR PAUL
BUET CSE '17
ROLL - 1705043
SECTION - A(2)
*/
//OFFLINE1


# include "iGraphics.h"
#include<math.h>

int x = 300, y = 300, r = 20;
float pi = asin(1)*2;
float theta = 0;
float theta2 = 0;
float theta3 = 0;
/*
	function iDraw() is called again and again by the system.

	*/
void secondkata()
{
    theta = theta - 0.1047197551; //6*pi/180
}
void minutekata()
{
    theta2 = theta2 - 0.00174533; //(6/60)*pi/180
}
void hourkata()
{
    theta3 = theta3 - 0.0001454441; //(30/3600)*pi/180
}
void iDraw() {
	//place your drawing codes here
	iClear();
	iSetColor(255, 128, 0);
	iCircle(250, 250, 200);
	iFilledCircle(250, 250, 5);
	//iSetColor(255, 128, 0);
	iText(250-70, 250+90, "KAWSHIK KUMAR PAUL");
	iSetColor(255, 255, 255);
	iLine(250, 250, 250+190*cos(theta), 250+190*sin(theta));
	iSetColor(128, 128, 255);
	iLine(250, 250, 250+165*cos(theta2), 250+165*sin(theta2));
	iSetColor(128, 255, 0);
	iLine(250, 250, 250+115*cos(theta3), 250+115*sin(theta3));
	iSetColor(255, 128, 0);
	iText(250+180, 246, "3", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(250-1+180*cos(pi/6), 250+180*sin(pi/6), "2", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(250-2+180*cos(pi/3), 250+180*sin(pi/3), "1", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(250-10+180*cos(pi/2), 250-3+180*sin(pi/2), "12", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(250-5+180*cos(pi/2+pi/6), 250-5+180*sin(pi/2+pi/6), "11", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(250-4+180*cos(pi/2+pi/3), 250-4+180*sin(pi/2+pi/3), "10", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(250+180*cos(pi/2+pi/2), 250-3+180*sin(pi/2+pi/2), "9", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(250-6+180*cos(pi+pi/6), 250-3+180*sin(pi+pi/6), "8", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(250-4+180*cos(pi+pi/3), 250-4+180*sin(pi+pi/3), "7", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(250-4+180*cos(pi+pi/2), 250-5+180*sin(pi+pi/2), "6", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(250+180*cos(pi+pi/2+pi/6), 250-4+180*sin(pi+pi/2+pi/6), "5", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(250+180*cos(pi+pi/2+pi/3), 250-5+180*sin(pi+pi/2+pi/3), "4", GLUT_BITMAP_TIMES_ROMAN_24);
}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouseMove(int mx, int my) {
	printf("x = %d, y= %d\n",mx,my);
	//place your codes here
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouse(int button, int state, int mx, int my) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		//place your codes here
		//	printf("x = %d, y= %d\n",mx,my);
		x += 10;
		y += 10;
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
		//place your codes here
		x -= 10;
		y -= 10;
	}
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
	*/
void iKeyboard(unsigned char key) {
	if (key == 'q') {
		exit(0);
	}
	//place your codes for other keys here
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
	*/
void iSpecialKeyboard(unsigned char key) {

	if (key == GLUT_KEY_END) {
		exit(0);
	}
	//place your codes for other keys here
}

void print(){
printf("Kawshik BUET CSE'17    ");}

int main() {
	//place your own initialization codes here.
	int hr, minute, sec;
	char D;

	printf("If you want to see real time press Y, else press N  : \n");
	scanf("%c",&D);
	switch(D)
	{
    case 'Y':
    {
    time_t now;
	struct tm *timeinfo;
	time(&now);
	timeinfo=localtime(&now);
	hr=timeinfo->tm_hour;
	hr=hr%12;
	minute=timeinfo->tm_min;
	sec=timeinfo->tm_sec;

	theta3 = pi/2 - (pi/6)*hr - 0.0001454441*sec - 0.008726646*minute;
	theta2 = pi/2 - (pi/30)*minute - 0.001745329*sec;
	theta = pi/2 - .10471975511966*sec;
	iSetTimer(1000, secondkata);
	iSetTimer(1000, minutekata);
	iSetTimer(1000, hourkata);
	iSetTimer(1000, print);
	iInitialize(500, 500, "KAWSHIK KUMAR PAUL");
	break;
	}
	case 'N':
	{
    printf("Input Hour :    ");
	scanf("%d", &hr);
	printf("Input Minute :    ");
	scanf("%d", &minute);
	printf("Input Second :    ");
	scanf("%d", &sec);
	hr=hr%12;
	theta3 = pi/2 - (pi/6)*hr - 0.0001454441*sec - 0.008726646*minute;
	theta2 = pi/2 - (pi/30)*minute - 0.001745329*sec;
	theta = pi/2 - .10471975511966*sec;
	iSetTimer(1000, secondkata);
	iSetTimer(1000, minutekata);
	iSetTimer(1000, hourkata);
	iSetTimer(1000, print);
	iInitialize(500, 500, "KAWSHIK KUMAR PAUL");
	}
	}
	return 0;
}
