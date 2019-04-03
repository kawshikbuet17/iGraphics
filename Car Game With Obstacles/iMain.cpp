# include "iGraphics.h"
# include <Windows.h>
# include <stdlib.h>

char str[100], str2[100];
int len, start=0;

struct highscorer
{
 char name[100];
 int sss;

}high[1000];

int mv = 25+5+100+10;
int x = mv+25+5+150+5+38, y = 150, yd, d=0, yd1, level=1;
int Game_Over = 0, mode;
double y1, y2, y3, y4, y5, y6, y7, y8, y9, y10, y11, y12;
int life = 3,currentscore,player[5];
char w1[10];
//h1[10],h2[10],h3[10],h4[10],h5[10];

int w=0,q=500,i;
void drawTextBox()
{
	iSetColor(150, 150, 150);
	//iRectangle(50, 250, 250, 30);
	iRectangle(300-20, 450, 250, 30);
}
void itoa(int n,char s[])
{
int i,sign,j,t,l;
if((sign=n)<0)
    n=-n;
    i=0;

    do
    {
        s[i++]=n%10+'0';

    }while((n/=10)>0);

    if(sign<0)
        s[i++]='-';
    s[i]='\0';
    l=strlen(s);
  for(i=0,j=l-1;i<=l/2,j>=l/2;i++,j--){
    t=s[i];
    s[i]=s[j];
    s[j]=t;
  }
}


void resume()
{
    FILE *res;
    res=fopen("resume.txt","r");
    fscanf(res,"%d %d %d %d %d",&x,&y,&level,&life,&w);

    fclose(res);
}

void resume22()
{
    FILE *res;
    res=fopen("resume.txt","w");
    fprintf(res,"%d %d %d %d %d",x,y,level,life,w);
    fclose(res);
}

/*
    function iDraw() is called again and again by the system.

    */


void iDraw() {
    //place your drawing codes here
    iClear();
    iSetColor(255,255,255);
    iPauseTimer(0);
    iPauseTimer(1);
    iPauseTimer(2);
    iShowBMP(0, 0, "homepage_wallpaper.bmp");
    iSetColor(180,0,0);
    iFilledRectangle(78, 458, 200, 50);
    iFilledRectangle(78, 458-80, 200, 50);
    iFilledRectangle(78, 458-2*80, 200, 50);
    iFilledRectangle(78, 458-3*80, 200, 50);
    iFilledRectangle(78, 458-4*80, 200, 50);
    iSetColor(255,255,255);
    iText(78+30, 458+20, "NEW GAME", GLUT_BITMAP_TIMES_ROMAN_24);
    iText(78+30+15, 458+20-80, "RESUME", GLUT_BITMAP_TIMES_ROMAN_24);
    iText(78+30+15, 458+20-2*80, "CREDITS", GLUT_BITMAP_TIMES_ROMAN_24);
    iText(78+30+10-2, 458+20-3*80, "SETTINGS", GLUT_BITMAP_TIMES_ROMAN_24);
    iText(78+30+40, 458+20-4*80, "QUIT", GLUT_BITMAP_TIMES_ROMAN_24);
    if(mode == 5)
        exit(0);
    if(mode == 1)
    {

    if(level==1)
    {

    //iShowBMP(0,0,"level1wall1.bmp");
    iShowBMP(0,0, "grass4.bmp");
    iResumeTimer(0);
    iResumeTimer(1);
    iResumeTimer(2);

    iShowBMP(640, 500, "level1.bmp");
    iSetColor(255,255,255);
    iFilledRectangle(mv+0+25, 0, 5+150+5+150+5+150+5, 1100);
    iSetColor(0,0,0);
    //iFilledRectangle(mv+0,0,25,1000);
    //iFilledRectangle(mv+25+5+150+5+150+5+150+5,0,1000,1000);
    iSetColor(0, 0, 0);
    for(yd=d; yd<10000 ; yd+=55)
    {
        iFilledRectangle(mv+25, yd, 5, 30);
        iFilledRectangle(mv+25+5+150, yd, 5, 30);
        iFilledRectangle(mv+25+5+150+5+150, yd, 5, 30);
        iFilledRectangle(mv+25+5+150+5+150+5+150, yd, 5, 30);
    }

    iSetColor(240, 0, 0);
    iFilledRectangle(10, 700-100, 110, 50);
    //iFilledRectangle(10, 700-100-80, 110, 50);
    iSetColor(255, 255, 255);
    iText(10+20,700-85,"BACK",GLUT_BITMAP_TIMES_ROMAN_24);
    //iText(10+10+5,700-85-80,"PAUSE",GLUT_BITMAP_TIMES_ROMAN_24);


    iShowBMP(mv+25+5+150+5+150+5+38-20, y1, "ashcar1.bmp");

    iShowBMP(mv+25+5+150+5+150+5+25, y7, "gift3.bmp");
    iShowBMP(mv+25+5+38+20, y2, "orangecar1.bmp");
    iShowBMP(mv+25+5+150+5+35, y3, "bluecar1.bmp");

   // iShowBMP(mv+25+5+150+5+10, y4, "ashcar1.bmp");
    iShowBMP(mv+25+5+25-20, y6, "stone1.bmp" );
    iShowBMP(mv+25+5+35, y11, "gift2.bmp");
    //iShowBMP(mv+25+5+150+5+25, y12, "life1.bmp");
    //iShowBMP(mv+25+5+150+35, y8, "stone2.bmp");
    //iShowBMP(mv+25+5+150+35, y9, "brick1.bmp");

    iShowBMP(x, y, "yellowcar1.bmp");


    iSetColor(0,128,0);
    iFilledRectangle(mv+25+5,0,5+150+5+150+5+150+5-10,120);

    iSetColor(255,255,255);

    iText(mv+25+40+250,80,"LIFE REMAINS",GLUT_BITMAP_TIMES_ROMAN_24);
    if(life==1)
    {
        iText(mv+25+40+300,50,"1",GLUT_BITMAP_TIMES_ROMAN_24);
    }
    if(life==2)
    {
        iText(mv+25+40+300,50,"2",GLUT_BITMAP_TIMES_ROMAN_24);
    }
    if(life==3)
    {
        iText(mv+25+40+300,50,"3",GLUT_BITMAP_TIMES_ROMAN_24);
    }
    if(life==0)
    {
        iText(mv+25+40+300,50,"0",GLUT_BITMAP_TIMES_ROMAN_24);
    }
    if(life<0)
    {
        iText(mv+25+40+300,50,"No Life",GLUT_BITMAP_TIMES_ROMAN_24);
    }

    if(Game_Over==1)
    {
            //iShowBMP(0, 0, "gameover6.bmp");
            iPauseTimer(1);
            iPauseTimer(2);
            currentscore=w;
            iSetColor(240, 0, 0);
            iFilledRectangle(10, 700-100, 110, 50);
            iSetColor(255, 255, 255);
            iText(10+20,700-85,"BACK",GLUT_BITMAP_TIMES_ROMAN_24);
            mode=10;

    }

    iText(mv+25+40,80,"SCORE",GLUT_BITMAP_TIMES_ROMAN_24);
    itoa(w,w1);
    iText(mv+25+40,50,w1,GLUT_BITMAP_TIMES_ROMAN_24);
    }


    if(level == 2)
    {

    iShowBMP(0,0, "grass2.bmp");
    iResumeTimer(0);
    iResumeTimer(1);
    iResumeTimer(2);

    iShowBMP(640, 500, "level2.bmp");
    iSetColor(255,255,0);
    iSetColor(255,255,255);
    iFilledRectangle(mv+0+25, 0, 5+150+5+150+5+150+5, 1100);
    iSetColor(0,0,0);

    iSetColor(0, 0, 0);
    for(yd=d; yd<10000 ; yd+=55)
    {
        iFilledRectangle(mv+25, yd, 5, 30);
        iFilledRectangle(mv+25+5+150, yd, 5, 30);
        iFilledRectangle(mv+25+5+150+5+150, yd, 5, 30);
        iFilledRectangle(mv+25+5+150+5+150+5+150, yd, 5, 30);
    }

    iSetColor(240, 0, 0);
    iFilledRectangle(10, 700-100, 110, 50);
    //iFilledRectangle(10, 700-100-80, 110, 50);
    iSetColor(255, 255, 255);
    iText(10+20,700-85,"BACK",GLUT_BITMAP_TIMES_ROMAN_24);
    //iText(10+10+5,700-85-80,"PAUSE",GLUT_BITMAP_TIMES_ROMAN_24);


    iShowBMP(mv+25+5+150+5+150+5+38-20, y1, "ashcar1.bmp");

    iShowBMP(mv+25+5+150+5+150+5+25+15, y7, "gift3.bmp");
    iShowBMP(mv+25+5+38+20, y2, "orangecar1.bmp");
    iShowBMP(mv+25+5+150+5+35, y3, "bluecar1.bmp");


    //iShowBMP(mv+25+5+150+5+10, y5, "man1.bmp");
    iShowBMP(mv+25+5+25-20, y6, "stone1.bmp" );
    iShowBMP(mv+25+5+150+5+35, y8, "stone2.bmp");
    iShowBMP(mv+25+5+150+35+15, y9, "brick1.bmp");
    iShowBMP(mv+25+5+35+20, y10, "brick2.bmp");

    iShowBMP(x, y, "yellowcar1.bmp");
    //iSetColor(0, 0, 111);
    //iFilledRectangle(mv+25+5+150+5+150+5+150,400, 250, 350);

    iSetColor(0,128,0);
    iFilledRectangle(mv+25+5,0,5+150+5+150+5+150+5-10,120);


    iSetColor(255,255,255);

    iText(mv+25+40+250,80,"LIFE REMAINS",GLUT_BITMAP_TIMES_ROMAN_24);
    if(life==1)
    {
        iText(mv+25+40+300,50,"1",GLUT_BITMAP_TIMES_ROMAN_24);
    }
    if(life==2)
    {
        iText(mv+25+40+300,50,"2",GLUT_BITMAP_TIMES_ROMAN_24);
    }
    if(life==3)
    {
        iText(mv+25+40+300,50,"3",GLUT_BITMAP_TIMES_ROMAN_24);
    }
    if(life==0)
    {
        iText(mv+25+40+300,50,"0",GLUT_BITMAP_TIMES_ROMAN_24);
    }
    if(life<0)
    {
        iText(mv+25+40+300,50,"No Life",GLUT_BITMAP_TIMES_ROMAN_24);
    }
    if(Game_Over==1)
    {
            //iShowBMP(0, 0, "gameover6.bmp");
            iPauseTimer(1);
            iPauseTimer(2);
            iSetColor(240, 0, 0);
            iFilledRectangle(10, 700-100, 110, 50);
            //iFilledRectangle(10, 700-100-80, 110, 50);
            iSetColor(255, 255, 255);
            iText(10+20,700-85,"BACK",GLUT_BITMAP_TIMES_ROMAN_24);
           // iText(10+10+5,700-85-80,"PAUSE",GLUT_BITMAP_TIMES_ROMAN_24);
            currentscore=w;
            //scoreup(currentscore);
            level = 1;
    }

    iText(mv+25+40,80,"SCORE",GLUT_BITMAP_TIMES_ROMAN_24);
    itoa(w,w1);
        iText(mv+25+40,50,w1,GLUT_BITMAP_TIMES_ROMAN_24);
    }
    }
    if(mode==2)
    {
        resume();
        mode = 1;
    }


    if(mode==6)
    {
        mode = 0;
    }


    if(mode==7)
    {
        iPauseTimer(0);
        iPauseTimer(1);
        iPauseTimer(2);
        mode = 0;
    }


    if(mode==3)
    {
        iShowBMP(0, 0, "wall4.bmp");

        iSetColor(0,0,255);
        iFilledRectangle(10, 700-100, 110, 50);
        iSetColor(255,255,255);


        FILE *fp;
        fp= fopen("score.txt","r");
        int idx=0;
        while(!feof(fp))
        {
            fscanf(fp,"%s %d",high[idx].name,&high[idx].sss);
            idx++;
            if(feof(fp))
                break;
        }
        fclose(fp);

        while(1)
        {
            int swapped=0;
            for(int ini=0;ini<idx-1;ini++)
            {
                if(high[ini].sss<high[ini+1].sss)
                {
                    int temp=high[ini].sss;
                    high[ini].sss=high[ini+1].sss;
                    high[ini+1].sss=temp;
                    char nam[1000];
                    strcpy(nam,high[ini].name);
                    strcpy(high[ini].name,high[ini+1].name);
                    strcpy(high[ini+1].name,nam);
                    swapped=1;
                }
            }
            if(swapped==0)
                break;
        }
        iText(10+20,700-85,"BACK",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(200,600,"HALL OF FAME",GLUT_BITMAP_TIMES_ROMAN_24);
        int y_y=500;
        for(int ini=0;ini<5;ini++)
        {
            iText(200,y_y,high[ini].name,GLUT_BITMAP_TIMES_ROMAN_24);
            char show[100];
            itoa(high[ini].sss,show);
            iText(350,y_y,show,GLUT_BITMAP_TIMES_ROMAN_24);
            y_y-=50;

        }


    }
    if(mode==4)
    {
        iShowBMP(0, 0,"wall4.bmp");

        iSetColor(255,255,255);
        iText(50,150,"FARDIN(38)",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(50, 100,"KAWSHIK(43)",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(50, 50,"MAISA(46)",GLUT_BITMAP_TIMES_ROMAN_24);
        iFilledRectangle(10, 700-100, 110, 50);
        iFilledRectangle(300,500,250,50);
        iFilledRectangle(300,500-60,100,50);
        iFilledRectangle(450,500-60,100,50);
        iSetColor(0,0,0);
        iText(380,520,"SOUND",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(330,460,"ON",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(470,460,"OFF",GLUT_BITMAP_TIMES_ROMAN_24);

        iText(10+20,700-85,"BACK",GLUT_BITMAP_TIMES_ROMAN_24);



    }
    if(mode==10){
        iShowBMP(0, 0,"gameover6.bmp");
        iSetColor(0,0,0);
        drawTextBox();
        iSetColor(250,0,0);
        iFilledRectangle(300-20, 450-50, 250, 30);
        iSetColor(255,255,255);
        iText(300-20+100-10, 450 -50 +10,"DONE",GLUT_BITMAP_TIMES_ROMAN_24);
        iSetColor(240, 0, 0);
        iFilledRectangle(10, 700-100, 110, 50);
        iSetColor(255, 255, 255);
        iText(10+20,700-85,"BACK",GLUT_BITMAP_TIMES_ROMAN_24);
        iSetColor(255,0,0);
		iText(300+10, 450+10, str);


    }

}
void track(double m1, double m2)
{
    double d = m1 - m2;
    if(d<0)
        d = -d;
    if(d<200)
    {
        if(m1>m2)
            m1+=200;
        else
            m2+=200;
    }
}

void ValueChangeOfY(void)
{

    if(level == 1)
    {
        if(abs(y2-y6)<600) y2=1000;
        if(abs(y1-y7)<500) y1=1500;
        if(abs(y3-y4)<500) y3=1000;

        if(y1<-200)
        y1 = 1500;
    if(y2<-200)
        y2 = 1000;
    if(y3<-200)
        y3 = 1000;
    if(y4<-200)
        y4 = 4000;
    if(y5<-200)
        y5 = 15000;
    if(y6<-200)
        y6 = 1000;
    if(y7<-200)
        y7 = 2500;
    if(y11<-200)
        y11 = 3000;
    //if(y12<-200)
        //y12 = 3500;


    /*if(y8<-200)
        y8 = rand()%100+2400;*/
    y1 = y1 - 12;
    y2 = y2 -12;
    y3 = y3 -12;
    y4 = y4 - 12;
    y5 = y5 - 12;
    y6 = y6 -12;
    y7 = y7 - 12;
    y11 = y11 -12;
    //y12= y12 - 12;
    //y8 = y8 - 12;
    //y9 = y9 - 12;
    //y10 = y10 -12;

    d = d - 6;
    yd1 = yd+35;
    if (yd1<0)
        d = 1000;
    }
    if(level == 2)
    {
        if(abs(y2-y6)<600) y2=1000;
        if(abs(y1-y7)<500) y1=1500;
        if(abs(y3-y4)<500) y3=1000;
        if(abs(y4-y8)<500) y4=3000;
        if(abs(y3-y8)<500) y3=1000;
        if(abs(y3-y9)<500) y3=1000;
        if(abs(y9-y4)<500) y4=3000;
        if(abs(y2-y10)<500) y2=1000;
        if(abs(y6-y10)<500) y6=1000;


    if(y1<-200)
        y1 = 1000;
    if(y2<-200)
        y2 = 2000;
    if(y3<-200)
        y3 = 2000;
    if(y4<-200)
        y4 = 2000;
    if(y5<-200)
        y5 = 5000;
    if(y6<-200)
        y6 = 6000;
    if(y7<-200)
        y7= 2500;
    if(y8<-200)
        y8 = 8000;
    if(y9<-200)
        y9 = 9000;
    if(y10<-200)
        y10 = 10000;
    if(y11<-200)
        y11 = 11000;


    y1 = y1 - 12;
    y2 = y2 -12;
    y3 = y3 -12;
    y4 = y4 - 12;
    y5 = y5 - 12;
    y6 = y6 -12;
    y7 = y7 - 12;
    y8 = y8 - 12;
    y9 = y9 - 12;
    y10 = y10 - 12;
    y11 = y11 - 12;
    //y12 = y12 - 12;

    d = d - 8;
    yd1 = yd+35;
    if (yd1<0)
        d = 1000;
    }

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
          printf("x = %d, y= %d\n",mx,my);
        //if(x>25+5+50)
            //x -= 150;
    }
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
        //place your codes here
        //if(x<25+5+50+5+150+5+20)
            //x += 150;
    }
    if(mx >= 78 && mx <= 78+200 && my >= 458 && my <= 458+50 && mode == 0)
		{
			mode=1;
		    w=0;
		    x = mv+25+5+150+5+38, y = 150;
		    life=3;
		    Game_Over = 0;
		    level=1;
            y1 = 1500, y2 = 1000, y3 = 1000, y4 = 3000, y5 = 1500, y6=1000, y7=2500, y8=4000, y9=5000, y10=6000;
		}
    else if(mx>=78 && mx<= 78+200 && my >= 458-80 && my <= 458-80+50 && mode == 0)
    {

        mode = 2;
    }
    else if(mx>=78 && mx<= 78+200 && my >= 458-2*80 && my <= 458-2*80+50 && mode == 0)
    {
        mode = 3;
    }
    else if(mx>=78 && mx<= 78+200 && my >= 458-3*80 && my <= 458-3*80+50 && mode == 0)
    {
        mode = 4;
    }
    else if(mx>=78 && mx<= 78+200 && my >= 458-4*80 && my <= 458-4*80+50 && mode == 0)
    {
        mode = 5;
    }
    else if(mx>=10 && mx<= 10+110 && my >=700-100 && my <= 700-100+50 && ((mode == 1) || (mode==2 )||(mode==10)))
    {
        iPauseTimer(0);
        iPauseTimer(1);
        iPauseTimer(2);
        //y1 = 2000; y2 = 1200; y3 = 1000+80;
        //mode = 0;
        //back = 1;
        resume22();
        //mode = 0;
        mode = 6;
    }
    else if(mx >= 300-20 && mx <= 300-20+250 && my >=450-50 && my <= 450-50+30 && mode ==10)
		{
		    mode=0;

		}
   /* else if(mx>=10 && mx<= 10+110 && my >=700-100-80 && my <= 700-100-80+50 && ((mode == 1) || (mode==2 )))
    {
        mode = 7;
    }*/
   /* else if(mx>=10 && mx<= 10+110 && my >=700-100 && my <= 700-100+50 && mode == 3)
    {
        mode = 0;
    }*/

    else if(mx>=450 && mx<= 550 && my >=440 && my <=510 && mode == 4)
    {
        PlaySound(NULL,NULL,0);
    }
    else if(mx>=300 && mx<=400 && my >=440 && my <=510 && mode == 4)
    {
        PlaySound(TEXT("Sherlock.wav"), NULL, SND_LOOP|SND_ASYNC);
    }
     else if(mx>=10 && mx<= 10+110 && my >=700-100 && my <= 700-100+50 && mode == 4)
    {
        mode = 0;
    }
    else if(mx>=10 && mx<= 10+110 && my >=700-100 && my <= 700-100+50 && mode == 3)
    {
        mode = 0;
    }
    else if(mx >= 78 && mx <= 78+200 && my >= 458 && my <= 458+50 && mode == 0)
    {
        mode = 1;
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
    if(Game_Over==1)
	{
        if(key == '\r')
		{
			//mode = 0;
			strcpy(str2, str);
			printf("%s\n", str2);
			FILE *fp;
			fp=fopen("score.txt","a");
			fprintf(fp,"\n%s %d",str2,currentscore);
			fclose(fp);
			for(i = 0; i < len; i++)
				str[i] = 0;
			len = 0;

		}
		else
		{
			str[len] = key;
			len++;
		}
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
    if(key == GLUT_KEY_LEFT)
	{
		if(x>mv+25+5+50)
            x-=20;
	}
	if(key == GLUT_KEY_RIGHT)
	{
		if(x<mv+25+5+50+5+150+5+20+120)
            x+=20;
	}
	if(key == GLUT_KEY_UP)
	{
		d-=6;
		y1-=6;
		y2-=6;
		y3-=6;
		y4-=6;
		y5-=6;
		y6-=6;
		y7-=6;
		y8-=6;
		y9-=6;
		y10-=6;
		y11-=6;
		y12-=6;


	}
	if(key == GLUT_KEY_DOWN)
	{
		//d+=10;
	}

    //place your codes for other keys here
}



void CollisionCheck()
{

    if(x<=mv+25+5+150-40+20 && y+134-4>=y2 && y2>=y-130)
        {life--;
        //PlaySound(TEXT("carhitsound.wav"), NULL, SND_ASYNC);
        printf("y2");
        y2 = -800;
        }
    if(x>=mv+25+5+150+5+150+5+10-30-20 && y+134-4>=y1 && y1>=y-134)
        {life--;printf("y1");
        //PlaySound(TEXT("carhitsound.wav"), NULL, SND_ASYNC);
        y1 = -800;
        }
    if(x>=mv+25+5+150+5+35-75 && x<=mv+25+5+150+5+35+80 && y+134-4>=y3 && y3>=y-150)
        {life--;printf("y3");
        //PlaySound(TEXT("carhitsound.wav"), NULL, SND_ASYNC);
        y3 = -800;
        }
    if(x<=mv+25+5+25+100-30 && y+134-4>=y6 && y6>=y-134)
        {life--;printf("y6");
        //PlaySound(TEXT("carhitsound.wav"), NULL, SND_ASYNC);
        y6 = -800;
        }
    /*if(x>=mv+25+5+150+5+10-75 && x<=mv+25+5+150+5+10+130 && y+134-4>=y5 && y5>=y-90)
        {//life--;
            w=w-50;
        printf("y5");
        y5 = -800;
        }*/

    if(x>=mv+25+5+150+5+150+5+35-75+10 && y+134-4>=y7 && y7>=y-80)
        {w+=50;printf("y7");
        //PlaySound(TEXT("carhitsound.wav"), NULL, SND_ASYNC);
        y7 = -800;
        }
    if(x>=mv+25+5+150+5+35-75 && x<=mv+25+5+150+5+35+80 && y+134-4>=y8 && y8>=y-80)
        {life--;printf("y8");
        //PlaySound(TEXT("carhitsound.wav"), NULL, SND_ASYNC);
        y8 = -800;
        }
    /*if(x>=mv+25+5+150+5+25-75 && x<=mv+25+5+150+5+25+80 && y+134-4>=y12 && y12>=y-28)
        {life++;printf("y12");
        PlaySound(TEXT("carhitsound.wav"), NULL, SND_ASYNC);
        y12 = -800;
        }*/
    if(x>=mv+25+5+35-75+20 && x<=mv+25+5+35+100+20 && y+134-4>=y10 && y10>=y-70)
        {life--;printf("y10");
        //PlaySound(TEXT("carhitsound.wav"), NULL, SND_ASYNC);
        y10 = -800;
        }
        if(x>=mv+25+5+35-75 && x<=mv+25+5+35+80 && y+134-4>=y11 && y11>=y-45)
        {w+=20;printf("y11");
        y11 = -800;
        }
    if(x>=mv+25+5+150+35-75+15 && x<=mv+25+5+150+35+80+15 && y+134-4>=y9 && y9>=y-90)
        {life--;printf("y9");
        //PlaySound(TEXT("carhitsound.wav"), NULL, SND_ASYNC);
        y9 = -800;
        }
    if(life<0)
        {
            iPauseTimer(0);
            iPauseTimer(1);
            iPauseTimer(2);
            Game_Over = 1;
        }
}


void score()
{
    w=w+1;
    if(w>200)
        level = 2;
}

int main()
{
    //place your own initialization codes here.
    mode = 0;
    iSetTimer(5, CollisionCheck);
    iSetTimer(30, ValueChangeOfY);
    iSetTimer(2000, score);
    //iSetTimer(10, resume22);
    PlaySound(TEXT("Sherlock.wav"), NULL, SND_LOOP|SND_ASYNC);
    iInitialize(800, 700, "CAR  GAME  WITH  OBSTACLES");

    return 0;
}
