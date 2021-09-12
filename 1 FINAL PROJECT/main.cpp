#include <windows.h>
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#include <iostream>

/* Submitted By
  17-33795-1  Rahman, Md. Saidur
  18-38094-2  Tabassum, Shakira
  18-38715-3  Khayeruzzaman, Md.
  19-39478-1  Farabi, Sazid Al
  19-40008-1  Rahman, Md.Musfiqur
*/
using namespace std;
int carStatus =0;

float _ang_tri = 0.0;
float _run = 0.0;
float _run1 = 0.0;
float _run2 = 0.0;
float _run3 = 0.0;

bool onOff;
bool frd = false;
bool bck = false;



float car1X =0;
float car1Y =0;
float car2X =0;
float car2Y =0;
float planeX =0;
float planeY =0;
float cloud =0;
int waterStatus = 0;
float waterX = 0;
float waterY = 0;
float rain = 0.0;
bool rainday = false;


//sky color
int dnr=45,dng=179,dnb=236;
//Headlight colour
int ldr=0,ldg=0,ldb=0;
//sun color
int sdr=246,sdg=171,sdb=26;
//cloud color
int cdr=230,cdg=234,cdb=237;
//land btn riv & road
int gdr=100,gdg=171,gdb=55;
//moon colour
int m1r=103,m1g=155,m1b=176;
int m2r=103,m2g=155,m2b=176;
//school color
int scr=152,scg=135,scb=135;
//river color
int rir=133,rig=230,rib=230;
//building light
int bulr=191,bulg=191,bulb=165;
//hotel light
int hlr=5,hlg=150,hlb=155;
//int m=0;

char school[] = "School";
char hotel[] = "Hotel";
char manual[] = "d=digital town, a = moveCar, s=stopCar , n=night/day, q=boat start, t=boat stop";
char text [] = "g=back word, h=forward, j= stop train";
char e[] = "e = exit.";


void myInit (void)
{
        glClearColor(1.0, 1.0, 1.0, 0.0);
        glColor3f(0.0f, 0.0f, 0.0f);
        glPointSize(4.0);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(0.0, 902.0, 0.0, 684.0);
}

void print( float x, float y, char *st)
{
    int l,i;

    l=strlen( st ); // see how many characters are in text string.
    glColor3f(0.2,1.0,0.7);
    glRasterPos2f( x, y); // location to start printing text
    for( i=0; i < l; i++) // loop until i is greater then l
    {
       glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, st[i]);
    }
}
void drawCircle(GLfloat x, GLfloat y, GLfloat radius)
{
    int i;
    int triangleAmount = 50; //# of triangles used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi = 2.0f * 3.1416;

    //glColor3ub(23,60,43);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2d(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2d(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
        glEnd();
}

void Sky()
{
        glPushMatrix();
        glColor3ub(dnr,dng,dnb);
        glBegin(GL_QUADS);
        glVertex2i(0,684);
        glVertex2i(902,684);
        glVertex2i(902,0);
        glVertex2i(0,0);
        glEnd();
        glPopMatrix();

        glutPostRedisplay();
}


void railbody()
{
    ///Making of Rail Body

    glPushMatrix();
    glTranslatef(_ang_tri, 0.0, 0.0);

    glColor3ub(9, 99, 4);
    glBegin(GL_QUADS); //Back Green
    glVertex2i(20, 35);
    glVertex2i(170, 35);
	glVertex2i(170, 110);
	glVertex2i(20, 110);
	glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS); //Window 4th
    glVertex2i(30, 70);
    glVertex2i(50, 70);
	glVertex2i(50, 90);
	glVertex2i(30, 90);
	glEnd();

	glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS); //Window 3rd
    glVertex2i(60, 70);
    glVertex2i(80, 70);
	glVertex2i(80, 90);
	glVertex2i(60, 90);
	glEnd();

	glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS); //Window 2nd
    glVertex2i(100, 70);
    glVertex2i(120, 70);
	glVertex2i(120, 90);
	glVertex2i(100, 90);
	glEnd();

	glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS); //Window 1st
    glVertex2i(130, 70);
    glVertex2i(150, 70);
	glVertex2i(150, 90);
	glVertex2i(130, 90);
	glEnd();

	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_QUADS); // Back red line
    glVertex2i(20, 50);
    glVertex2i(170, 50);
	glVertex2i(170, 45);
	glVertex2i(20, 45);
	glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS); //Back front
    glVertex2i(170, 35);
    glVertex2i(170, 120);
	glVertex2i(180, 120);
	glVertex2i(180, 45);
	glEnd();


	glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS); //Back up
    glVertex2i(20, 110);
    glVertex2i(170, 110);
	glVertex2i(176, 120);
	glVertex2i(30, 120);
	glEnd();

	glPushMatrix();
    glTranslatef(40, 25, 0.0);
    glBegin(GL_POLYGON); //back wheel
    glColor3ub(109, 109, 115);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=15;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
   glPopMatrix();


    glPushMatrix();
    glTranslatef(150, 25, 0.0);
    glBegin(GL_POLYGON); //back front wheel
    glColor3ub(109, 109, 115);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=15;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
   glPopMatrix();


    glPushMatrix();
    glTranslatef(83, 0, 0);

    glColor3ub(9, 99, 4);
    glBegin(GL_QUADS); //Middle Green
    glVertex2i(255, 35);
    glVertex2i(105, 35);
	glVertex2i(105, 110);
	glVertex2i(255, 110);
	glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS); //Middle window 4th
    glVertex2i(115, 70);
    glVertex2i(135, 70);
	glVertex2i(135, 90);
	glVertex2i(115, 90);
	glEnd();

	glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS); //Middle window 3rd
    glVertex2i(145, 70);
    glVertex2i(165, 70);
	glVertex2i(165, 90);
	glVertex2i(145, 90);
	glEnd();

	glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS); //Middle window 2nd
    glVertex2i(190, 70);
    glVertex2i(210, 70);
	glVertex2i(210, 90);
	glVertex2i(190, 90);
	glEnd();

	glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS); //Middle window 1st
    glVertex2i(220, 70);
    glVertex2i(240, 70);
	glVertex2i(240, 90);
	glVertex2i(220, 90);
	glEnd();

	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_QUADS); //Middle red line
    glVertex2i(105, 50);
    glVertex2i(255, 50);
	glVertex2i(255, 45);
	glVertex2i(105, 45);
	glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS); // Middle front
    glVertex2i(255, 35);
	glVertex2i(255, 110);
	glVertex2i(265, 120);
	glVertex2i(265, 45);
	glEnd();


	glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS); //Middle up
    glVertex2i(105, 110);
    glVertex2i(255, 110);
	glVertex2i(265, 120);
	glVertex2i(115, 120);
	glEnd();

	glPushMatrix();
    glTranslatef(125, 25, 0.0);
    glBegin(GL_POLYGON); //middle back wheel
    glColor3ub(109, 109, 115);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=15;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
   glPopMatrix();


   glPushMatrix();
    glTranslatef(235, 25, 0.0);
    glBegin(GL_POLYGON); //middle front wheel
    glColor3ub(109, 109, 115);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=15;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

    glPopMatrix();


    glPushMatrix();
    glTranslatef(320, 0, 0);

    glColor3ub(9, 99, 4);
    glBegin(GL_QUADS); //Front Green
    glVertex2i(35, 110);
    glVertex2i(190, 110);
	glVertex2i(190, 35);
	glVertex2i(35, 35);
	glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS); //Front window 4th
    glVertex2i(145, 90);
    glVertex2i(120, 90);
	glVertex2i(120, 70);
	glVertex2i(145, 70);
	glEnd();

	glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS); //Front window 3rd
    glVertex2i(105, 90);
    glVertex2i(80, 90);
	glVertex2i(80, 70);
	glVertex2i(105, 70);
	glEnd();

	glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS); //Front window 2nd
    glVertex2i(65, 90);
    glVertex2i(40, 90);
	glVertex2i(40, 70);
	glVertex2i(65, 70);
	glEnd();

	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_QUADS); // Front Red line
    glVertex2i(35, 50);
    glVertex2i(190, 50);
	glVertex2i(190, 45);
	glVertex2i(35, 45);
	glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS); //Front front white
    glVertex2i(190, 35);
    glVertex2i(200, 45);
	glVertex2i(200, 120);
	glVertex2i(190, 110);
	glEnd();

	glColor3ub(14, 201, 186);
    glBegin(GL_QUADS); //Front blue window
    glVertex2i(190, 90);
    glVertex2i(160, 90);
	glVertex2i(160, 70);
	glVertex2i(190, 70);
	glEnd();

	glColor3ub(14, 201, 186);
    glBegin(GL_QUADS); //Front light
    glVertex2i(190, 68);
    glVertex2i(200, 78);
	glVertex2i(200, 100);
	glVertex2i(190, 90);
	glEnd();


	glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS); //Front up
    glVertex2i(35, 110);
    glVertex2i(190, 110);
	glVertex2i(200, 120);
	glVertex2i(45, 120);
	glEnd();

	glPushMatrix();
    glTranslatef(55, 25, 0.0);
    glBegin(GL_POLYGON); //Front back wheel
    glColor3ub(109, 109, 115);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=15;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
   glPopMatrix();


   glPushMatrix();
    glTranslatef(170, 25, 0.0);
    glBegin(GL_POLYGON); //Front front wheel
    glColor3ub(109, 109, 115);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=15;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

    glPopMatrix();

    glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_QUADS); //Front Red light
    glVertex2i(510, 110);
    glVertex2i(520, 120);
	glVertex2i(520, 100);
	glVertex2i(510, 90);
	glEnd();

	glColor3ub(145, 17, 17);
	glBegin(GL_QUADS); // Streamer
    glVertex2i(490, 130);
    glVertex2i(505, 130);
	glVertex2i(505, 115);
	glVertex2i(490, 115);
	glEnd();

	glPushMatrix();
    glTranslatef(495, 140, 0.0);
    glBegin(GL_POLYGON); // small smoke
    glColor3f(0.709, 0.701, 0.717);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(485, 155, 0.0);
    glBegin(GL_POLYGON); //middle smoke
    glColor3f(0.709, 0.701, 0.717);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=8;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(465, 170, 0.0);
    glBegin(GL_POLYGON); //Big smoke
    glColor3f(0.709, 0.701, 0.717);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=12;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

    glPopMatrix();

///End of Making of Rail Body
}
//train line
void trainline()
{
    //rail line
    glColor3ub(150, 150, 144);
	glBegin(GL_QUADS);
    glVertex2i(0,10);
    glVertex2i(1000,10);
    glVertex2i(1000,40);
    glVertex2i(0,40);
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2i(0,10);
    glVertex2i(1000,10);
    glVertex2i(1000,13);
    glVertex2i(0,13);

    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2i(0,40);
    glVertex2i(1000,40);
    glVertex2i(1000,43);
    glVertex2i(0,43);
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_LINES);
    float j;
    for(j=0;j<=1000;j+=20) //rail line
   {
        glVertex2i(10+j,10);
        glVertex2i(15+j,40);

    }
    glEnd();
}

void Moon()
{
    glPushMatrix();
    glColor3ub(m1r,m1g,m1b);
    drawCircle(730.0f,620.0f,40.0f);
    glColor3ub(m2r,m2g,m2b);
    drawCircle(740.0f,640.0f,40.0f);
    glPopMatrix();
}

void Sun()
{
    glColor3ub(sdr,sdg,sdb);
    drawCircle(824.0f,615.0f,40.0f);
    glutPostRedisplay();
}

float cdxp1=0.9;
float cdxp2=0.05;
float cdxp3=2.009;

void Cloud()
{
    glPushMatrix();
    glTranslatef(cdxp1+cloud,0,0);
    glColor3ub(cdr,cdg,cdb);
    drawCircle(594.0f,586.0f,20.0f);
    drawCircle(572.0f,595.0f,28.0f);
    drawCircle(539.0f,595.0f,35.0f);
    drawCircle(513.0f,575.0f,20.0f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(cdxp2+cloud,0,0);
    drawCircle(393.0f,577.0f,20.0f);
    drawCircle(370.0f,585.0f,28.0f);
    drawCircle(339.0f,583.0f,35.0f);
    drawCircle(311.0f,565.0f,20.0f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(cdxp3+cloud,0,0);
    drawCircle(193.0f,607.0f,20.0f);
    drawCircle(170.0f,615.0f,28.0f);
    drawCircle(139.0f,613.0f,35.0f);
    drawCircle(111.0f,595.0f,20.0f);
    glPopMatrix();

    glutPostRedisplay();
}


void Road()
{
    glPushMatrix();
    glColor3ub(0,0,0);
    glBegin(GL_QUADS);
    glVertex2i(0,148);
    glVertex2i(902,148);
    glVertex2i(902,47);
    glVertex2i(0,47);
    glEnd();
    glPopMatrix();

    for(int i=0;i<120*8;i+=120)
    {
        glPushMatrix();
        glColor3ub(255,255,255);
        glBegin(GL_QUADS);
        glVertex2i(0+i,95);
        glVertex2i(35+i,95);
        glVertex2i(35+i,100);
        glVertex2i(0+i,100);
        glEnd();
        glPopMatrix();
    }
}

void RoadCorner1()
{
    for(int i=0;i<31*30;i+=30)
    {
        glPushMatrix();
        glColor3ub(255,255,255);
        glBegin(GL_QUADS);
        glVertex2i(0+i,148);
        glVertex2i(16+i,148);
        glVertex2i(16+i,157);
        glVertex2i(0+i,157);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glColor3ub(0,0,0);
        glBegin(GL_QUADS);
        glVertex2i(16+i,148);
        glVertex2i(39+i,148);
        glVertex2i(39+i,157);
        glVertex2i(16+i,157);
        glEnd();
        glPopMatrix();
    }
    glPushMatrix();  ////////school road
    glColor3ub(0,0,0);
    glBegin(GL_QUADS);
    glVertex2i(740,192);
    glVertex2i(784,192);
    glVertex2i(784,147);
    glVertex2i(740,147);
    glEnd();
    glPopMatrix();
}

void RoadCorner2()
{
    for(int i=0;i<31*30;i+=30)
    {
        glPushMatrix();
        glColor3ub(255,255,255);
        glBegin(GL_QUADS);
        glVertex2i(0+i,48);
        glVertex2i(16+i,48);
        glVertex2i(16+i,57);
        glVertex2i(0+i,57);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glColor3ub(0,0,0);
        glBegin(GL_QUADS);
        glVertex2i(16+i,48);
        glVertex2i(39+i,48);
        glVertex2i(39+i,57);
        glVertex2i(16+i,57);
        glEnd();
        glPopMatrix();
    }
}

void Plane()
{
    glPushMatrix();
    glColor3ub(0,78,168);
    glBegin(GL_QUADS);
    glVertex2i(7-200,307+350);
    glVertex2i(76-200,318+350);
    glVertex2i(95-200,312+350);
    glVertex2i(22-200,290+350);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(13-200,305+350);
    glVertex2i(0-200,338+350);
    glVertex2i(4-200,339+350);
    glVertex2i(25-200,313+350);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(32-200,277+350);
    glVertex2i(49-200,301+350);
    glVertex2i(64-200,306+350);
    glVertex2i(37-200,279+350);
    glEnd();

    int j=0;
    for(int i=0;i<5*10;i+=10)
    {
        glColor3ub(249,190-j,0);
        drawCircle(73-i-200,312.5-j+350,2);
        j+=2;
    }

    glPopMatrix();
}
void homeWindow(int x,int y)
{
        glPushMatrix();
        glColor3ub(156,178,189);
        glBegin(GL_QUADS);
        glVertex2i(x,y);
        glVertex2i(x+10,y);
        glVertex2i(x+10,y+12);
        glVertex2i(x,y+12);
        glEnd();
        glPopMatrix();
}

void homeWindow2(int x,int y)
{
    glPushMatrix();
    glColor3ub(96,131,135);
    glBegin(GL_QUADS);
    glVertex2i(x,y);
    glVertex2i(x+4,y);
    glVertex2i(x+4,y+17);
    glVertex2i(x,y+17);
    glEnd();
    glPopMatrix();
}


void Home()   ///digital home
{
    glPushMatrix();
    glColor3ub(235,214,184);
    glBegin(GL_QUADS);
    glVertex2i(40,275);
    glVertex2i(138,275);
    glVertex2i(138,288);
    glVertex2i(40,288);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(127,10,20);
    glBegin(GL_QUADS);
    glVertex2i(40,269);
    glVertex2i(138,269);
    glVertex2i(138,275);
    glVertex2i(40,275);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(235,214,184);
    glBegin(GL_QUADS);
    glVertex2i(48,260);
    glVertex2i(130,260);
    glVertex2i(130,269);
    glVertex2i(48,269);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(235,214,184);
    glBegin(GL_QUADS);
    glVertex2i(20,239);
    glVertex2i(161,239);
    glVertex2i(161,261);
    glVertex2i(20,261);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(235,214,184);
    glBegin(GL_QUADS);
    glVertex2i(25,187);
    glVertex2i(157,187);
    glVertex2i(157,239);
    glVertex2i(25,239);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(0,0,0);
    glBegin(GL_QUADS);
    glVertex2i(72,187);
    glVertex2i(107,187);
    glVertex2i(107,217);
    glVertex2i(72,217);
    glPopMatrix();
    glEnd();

    //Bottom Block

    int HomeStripe1=15;
     for(int i=9;i>=0;i--)
    {
        HomeStripe1+=13;
        homeWindow(HomeStripe1,222);
    }

    //Bottom up block
    int HomeStripe2=15;
    for(int i=16;i>=0;i--)
    {
        HomeStripe2+=8;
        homeWindow2(HomeStripe2,242);
    }

}


//**********School part***********

void SchoolWindow1(int x,int y)
{
    glPushMatrix();
    glColor3ub(190,202,200);
    glBegin(GL_QUADS);
    glVertex2i(x,y);
    glVertex2i(x+20,y);
    glVertex2i(x+20,y+17);
    glVertex2i(x,y+17);
    glEnd();
    glPopMatrix();
}

void School()
{
    glPushMatrix(); //////////school body
    glColor3ub(scr,scg,scb);
    glBegin(GL_QUADS);
    glVertex2i(643,192);
    glVertex2i(884,192);
    glVertex2i(884,286);
    glVertex2i(643,286);
    glEnd();
    glPopMatrix();

    glPushMatrix();  //////////school top
    glColor3ub(73,3,5);
    glBegin(GL_QUADS);
    glVertex2i(640,286);
    glVertex2i(887,286);
    glVertex2i(887,293);
    glVertex2i(640,293);
    glEnd();
    glPopMatrix();

    glPushMatrix();   //////////school left lower strip
    glColor3ub(80,149,146);
    glBegin(GL_QUADS);
    glVertex2i(648,200);
    glVertex2i(719,200);
    glVertex2i(719,210);
    glVertex2i(648,210);
    glEnd();
    glPopMatrix();

    glPushMatrix();   //////////school right lower strip
    glColor3ub(80,149,146);
    glBegin(GL_QUADS);
    glVertex2i(808,200);
    glVertex2i(879,200);
    glVertex2i(879,210);
    glVertex2i(808,210);
    glEnd();
    glPopMatrix();



    int SchoolStripe1=623;
    for(int i=2;i>=0;i--)
    {
        SchoolStripe1+=25;
        SchoolWindow1(SchoolStripe1,263);
    }

     int SchoolStripe2=623;
    for(int i=2;i>=0;i--)
    {
        SchoolStripe2+=25;
        SchoolWindow1(SchoolStripe2,239);
    }

    int SchoolStripe3=623;
    for(int i=2;i>=0;i--)
    {
        SchoolStripe3+=25;
        SchoolWindow1(SchoolStripe3,216);
    }

    int SchoolStripe4=783;
    for(int i=2;i>=0;i--)
    {
        SchoolStripe4+=25;
        SchoolWindow1(SchoolStripe4,263);
    }

    int SchoolStripe5=783;
    for(int i=2;i>=0;i--)
    {
        SchoolStripe5+=25;
        SchoolWindow1(SchoolStripe5,239);
    }

    int SchoolStripe6=783;
    for(int i=2;i>=0;i--)
    {
        SchoolStripe6+=25;
        SchoolWindow1(SchoolStripe6,217);
    }

    //////////////////
    //flag
    glPushMatrix();
    glTranslatef(-5, -20, 0);

    glColor3ub(156, 143, 6);    //STAIR
    glBegin(GL_QUADS);
    glVertex2i(650, 192);
    glVertex2i(650, 202);
	glVertex2i(673, 202);
	glVertex2i(673, 192);
	glEnd();

    glColor3ub(104, 138, 143);    //STAND
    glBegin(GL_QUADS);
    glVertex2i(660, 202);
    glVertex2i(660, 270);
	glVertex2i(665, 270);
	glVertex2i(665, 202);
	glEnd();

	glColor3ub(9, 107, 4);    //QUAD
    glBegin(GL_QUADS);
    glVertex2i(665, 235);
    glVertex2i(665, 270);
	glVertex2i(730, 270);
	glVertex2i(730, 235);
	glEnd();

    //Circle
    glPushMatrix();
   // glScalef(0.5, 0.5, 0.5);
    glTranslatef(696, 252, 0);
    glBegin(GL_POLYGON);
    glColor3f(1,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=12;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
   glEnd();

   glPopMatrix();
   glPopMatrix();

    ////////////////


}
void SchoolDoor()
{
    glPushMatrix();  //////////school door background
    glColor3ub(72,2,4);
    glBegin(GL_QUADS);
    glVertex2i(728,192);
    glVertex2i(797,192);
    glVertex2i(797,256);
    glVertex2i(728,256);
    glEnd();
    glPopMatrix();

    glPushMatrix();    //////////school door triangle
    glColor3ub(75,3,4);
    glBegin(GL_TRIANGLES);
    glVertex2i(722,256);
    glVertex2i(803,256);
    glVertex2i(763,282);
    glEnd();
    glPopMatrix();

    glPushMatrix();    //////////school nameplate background
    glColor3ub(100,150,100);
    glBegin(GL_QUADS);
    glVertex2i(733,239);
    glVertex2i(792,239);
    glVertex2i(792,256);
    glVertex2i(733,256);
    glEnd();
    glPopMatrix();

    glPushMatrix();     //////////school door
    glColor3ub(89,107,121);
    glBegin(GL_QUADS);
    glVertex2i(743,192);
    glVertex2i(782,192);
    glVertex2i(782,230);
    glVertex2i(743,230);
    glEnd();
    glPopMatrix();
}

/////Hotel part

void HotelBelowWindow1(int x,int y)
{
    glPushMatrix();
    glColor3ub(hlr,hlg,hlb);
    glBegin(GL_QUADS);
    glVertex2i(x,y);
    glVertex2i(x+19,y);
    glVertex2i(x+19,y+13);
    glVertex2i(x,y+13);
    glEnd();
    glPopMatrix();
}

void HotelAboveWindow1(int x,int y)
{
    glPushMatrix();
    glColor3ub(hlr,hlg,hlb);
    glBegin(GL_QUADS);
    glVertex2i(x,y);
    glVertex2i(x+17,y);
    glVertex2i(x+17,y+21);
    glVertex2i(x,y+21);
    glEnd();
    glPopMatrix();
}
void Hotel()
{
    glPushMatrix();  ///////hotel lower back
    glColor3ub(8,32,19);
    glBegin(GL_QUADS);
    glVertex2i(359,365);
    glVertex2i(504,365);
    glVertex2i(504,397);
    glVertex2i(359,397);
    glEnd();
    glPopMatrix();

    glPushMatrix();   ///////hotel top body
    glColor3ub(21,63,53);
    glBegin(GL_QUADS);
    glVertex2i(380,397);
    glVertex2i(479,397);
    glVertex2i(479,516);
    glVertex2i(380,516);
    glEnd();
    glPopMatrix();

    glPushMatrix();  // above name plate
    glColor3ub(30,72,230);
    glBegin(GL_QUADS);
    glVertex2i(386,516);
    glVertex2i(460,516);
    glVertex2i(460,531);
    glVertex2i(386,531);
    glEnd();
    glPopMatrix();

     int HotelBelowStripe1=338;
    for(int i=5;i>=0;i--)
    {
        HotelBelowStripe1+=24;
        HotelBelowWindow1(HotelBelowStripe1,375);
    }

    int HotelAboveStripe1=361;
    for(int i=3;i>=0;i--)
    {
        HotelAboveStripe1+=24;
        HotelAboveWindow1(HotelAboveStripe1,485);
    }

    int HotelAboveStripe2=361;
    for(int i=3;i>=0;i--)
    {
        HotelAboveStripe2+=24;
        HotelAboveWindow1(HotelAboveStripe2,458);
    }

    int HotelAboveStripe3=361;
    for(int i=3;i>=0;i--)
    {
        HotelAboveStripe3+=24;
        HotelAboveWindow1(HotelAboveStripe3,431);
    }

    int HotelAboveStripe4=361;
    for(int i=3;i>=0;i--)
    {
        HotelAboveStripe4+=24;
        HotelAboveWindow1(HotelAboveStripe4,403);
    }
}
void Door()
{
    glColor3ub(8,32,19);
    drawCircle(430.0f,393.0f,22.0f);

    glPushMatrix();     // door
    glColor3ub(119,81,70);
    glBegin(GL_QUADS);
    glVertex2i(407,366);
    glVertex2i(453,366);
    glVertex2i(453,389);
    glVertex2i(407,389);
    glEnd();
    glPopMatrix();

    glPushMatrix();     // door middle
    glColor3ub(70,113,106);
    glBegin(GL_QUADS);
    glVertex2i(411,388);
    glVertex2i(429,388);
    glVertex2i(429,365);
    glVertex2i(411,365);
    glEnd();
    glPopMatrix();

    glPushMatrix();     // door middle
    glColor3ub(70,113,106);
    glBegin(GL_QUADS);
    glVertex2i(431,365);
    glVertex2i(448,365);
    glVertex2i(448,388);
    glVertex2i(431,388);
    glEnd();
    glPopMatrix();

    glPushMatrix();  ///////////hotel land
    glColor3ub(gdr,gdg,gdb);
    glBegin(GL_QUADS);
    glVertex2i(0,360);
    glVertex2i(902,360);
    glVertex2i(902,365);
    glVertex2i(0,365);
    glEnd();
    glPopMatrix();

}




void house()
{
//left triangle or chal
    glColor3ub (181, 158, 90);
    glBegin(GL_TRIANGLES);
    glVertex2i(50, 230);
    glVertex2i(70, 280);
    glVertex2i(90, 230);
    glEnd();
    //////////////line of chal
    glColor3ub (170, 140, 70);
    glBegin(GL_LINES);
    glVertex2i(55, 230);
    glVertex2i(75, 280);
    glEnd();
    ///////////////////right  chal
    glColor3ub (219, 183, 72);
    glBegin(GL_QUADS);
    glVertex2i(90, 230);
    glVertex2i(170, 230);
    glVertex2i(150, 280);
    glVertex2i(70, 280);
    glEnd();
    //glFlush ();
    ////////////////// left body
    glColor3ub (153, 153, 153);
    glBegin(GL_QUADS);
    glVertex2i(55, 180);
    glVertex2i(90, 180);
    glVertex2i(90, 230);
    glVertex2i(55, 230);
    glEnd();
    ///////////right body
    glColor3ub (180, 180, 180);
    glBegin(GL_QUADS);
    glVertex2i(90, 180);
    glVertex2i(165, 180);
    glVertex2i(165, 230);
    glVertex2i(90, 230);
    glEnd();
    ///////////////////right body janala (left)
    glColor3ub (90, 90, 90);
    glBegin(GL_QUADS);
    glVertex2i(95, 190);
    glVertex2i(110, 190);
    glVertex2i(110, 217);
    glVertex2i(95, 217);
    glEnd();
    /////////////////////right body janala (right)
    glColor3ub (90, 90, 90);
    glBegin(GL_QUADS);
    glVertex2i(145, 190);
    glVertex2i(160, 190);
    glVertex2i(160, 217);
    glVertex2i(145, 217);
    glEnd();
    ////////////left body janala
    glColor3ub (90, 90, 90);
    glBegin(GL_QUADS);
    glVertex2i(65, 190);
    glVertex2i(80, 190);
    glVertex2i(80, 217);
    glVertex2i(65, 217);
    glEnd();

    ////right body door
    glColor3ub (90, 90, 90);
    glBegin(GL_QUADS);
    glVertex2i(120, 185);
    glVertex2i(135, 185);
    glVertex2i(135, 220);
    glVertex2i(120, 220);
    glEnd();
}
void Rasta() ///////////analog
{
    glPushMatrix();
    glColor3ub(66,66,49);
    glBegin(GL_QUADS);
    glVertex2i(0,157);
    glVertex2i(902,157);
    glVertex2i(902,90);
    glVertex2i(0,90);
    glEnd();
    glPopMatrix();

    glPushMatrix();  ///////school road
    glColor3ub(66,66,49);
    glBegin(GL_QUADS);
    glVertex2i(743,192);
    glVertex2i(782,192);
    glVertex2i(782,147);
    glVertex2i(743,147);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub (66,66,66); ///home road
    glBegin(GL_QUADS);
    glVertex2i(115, 157);
    glVertex2i(140, 157);
    glVertex2i(140, 185);
    glVertex2i(115, 185);
    glEnd();
    glPopMatrix();
}
////first green grass part
void RoadGrash()
{
    glPushMatrix();
    glColor3ub(gdr,gdg,gdb);
    glBegin(GL_QUADS);
    glVertex2i(0 ,0);
    glVertex2i(902,0);
    glVertex2i(902,90);
    glVertex2i(0,90);
    glEnd();
    glPopMatrix();
}

void Car1()
{
    glPushMatrix();
    glColor3ub(34,160,160);
   // glTranslatef(c1xp,c1yp,c1zp);
    glBegin(GL_QUADS);
    glVertex2i(311-500,112);
    glVertex2i(414-500,112);
    glVertex2i(414-500,174);
    glVertex2i(311-500,174);
    glEnd();
    //glPopMatrix();

    //glPushMatrix();
    glColor3ub(45,194,198);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2i(414-500,162);
    glVertex2i(445-500,162);
    glVertex2i(473-500,134);
    glVertex2i(473-500,112);
    glVertex2i(414-500,112);
    glEnd();
    //glPopMatrix();

    //glPushMatrix();
    glColor3ub(75,89,89);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2i(417-500,158);
    glVertex2i(444-500,158);
    glVertex2i(463-500,139);
    glVertex2i(463-500,134);
    glVertex2i(417-500,134);
    glEnd();
    //glPopMatrix();

    //glPushMatrix();
    glColor3ub(255,0,0);
    glBegin(GL_QUADS);
    glVertex2i(464-500,128);
    glVertex2i(472-500,128);
    glVertex2i(472-500,113);
    glVertex2i(464-500,113);
    glEnd();
    //glPopMatrix();

        ///////// light
    glColor3ub(ldr,ldg,ldb);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2i(-28,117);
    glVertex2i(-28,125);
    glVertex2i(2,146);
    glVertex2i(2,98);
    glEnd();

    //glPushMatrix();
    glColor3ub(0,0,0);
    glBegin(GL_QUADS);
    glVertex2i(419-500,126);
    glVertex2i(431-500,126);
    glVertex2i(431-500,129);
    glVertex2i(419-500,129);
    glEnd();
    //glPopMatrix();

    //glPushMatrix();
    glColor3ub(48,48,46);
    drawCircle(342-500,116,15);
    glColor3ub(255,255,255);
    drawCircle(342-500,116,10);
    glColor3ub(0,0,0);
    drawCircle(342-500,116,8);


    glColor3ub(48,48,46);
    drawCircle(434-500,116,15);
    glColor3ub(255,255,255);
    drawCircle(434-500,116,10);
    glColor3ub(0,0,0);
    drawCircle(434-500,116,8);

    //drawCircle(434-500,110,15);
    //drawCircle(434-500,110,15);
    glPopMatrix();
}

void Car2()
{
    glPushMatrix();
    glColor3ub(232,35,35);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2i(459+500,154-70);
    glVertex2i(466+500,160-70);
    glVertex2i(491+500,160-70);
    glVertex2i(510+500,179-70);
    glVertex2i(568+500,179-70);
    glVertex2i(579+500,162-70);
    glVertex2i(579+500,141-70);
    glVertex2i(459+500,141-70);
    glEnd();
        ///////// light
    glColor3ub(ldr,ldg,ldb);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2i(958,80);
    glVertex2i(958,77);
    glVertex2i(929,97);
    glVertex2i(929,57);
    glEnd();

    glColor3ub(155,186,189);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2i(503+500,169-70);
    glVertex2i(512+500,177-70);
    glVertex2i(525+500,177-70);
    glVertex2i(521+500,163-70);
    glVertex2i(503+500,163-70);
    glEnd();

    glColor3ub(155,186,189);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2i(526+500,163-70);
    glVertex2i(530+500,177-70);
    glVertex2i(547+500,177-70);
    glVertex2i(547+500,163-70);
    glEnd();

    glColor3ub(155,186,189);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2i(552+500,163-70);
    glVertex2i(551+500,177-70);
    glVertex2i(561+500,177-70);
    glVertex2i(570+500,163-70);
    glEnd();

    //glPushMatrix();
    glColor3ub(51,53,50);
    drawCircle(474+500,142-70,10);
    glColor3ub(255,0,0);
    drawCircle(474+500,142-70,8);
    glColor3ub(0,0,0);
    drawCircle(474+500,142-70,7);
    //glPopMatrix();

    //glPushMatrix();
    glColor3ub(51,53,50);
    drawCircle(551+500,142-70,10);
    glColor3ub(255,0,0);
    drawCircle(551+500,142-70,8);
    glColor3ub(0,0,0);
    drawCircle(551+500,142-70,7);

    glPopMatrix();
}


void Tree()  ///digital triangle tree
{
    for(int i=0; i<7*130;i+=130)
    {
        glPushMatrix();
        glColor3ub(58, 146, 7);
        glBegin(GL_TRIANGLES);
        glVertex2i(24+i,46);
        glVertex2i(67+i,46);
        glVertex2i(46+i,78);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glColor3ub(58, 146, 7);
        glBegin(GL_TRIANGLES);
        glVertex2i(24+i,40);
        glVertex2i(67+i,40);
        glVertex2i(46+i,72);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glColor3ub(161,89,61);
        glBegin(GL_QUADS);
        glVertex2i(39+i,40);
        glVertex2i(52+i,40);
        glVertex2i(52+i,10);
        glVertex2i(39+i,10);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glColor3ub(58, 146, 7);
        glBegin(GL_TRIANGLES);
        glVertex2i(24+i,32);
        glVertex2i(67+i,32);
        glVertex2i(46+i,64);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glColor3ub(58, 146, 7);
        glBegin(GL_TRIANGLES);
        glVertex2i(24+i,24);
        glVertex2i(67+i,24);
        glVertex2i(46+i,56);
        glEnd();
        glPopMatrix();
    }
}



////river
void river()
{
    glPushMatrix();
    glColor3ub (rir, rig, rib);
    glBegin(GL_QUADS);
    glVertex2i(0, 258);
    glVertex2i(901, 258);
    glVertex2i(901, 360);
    glVertex2i(0, 360);
    glEnd();
    glPopMatrix();

}
//////////////////////////////////////////////////river water
void water()
{
    glPushMatrix();
    glColor3ub (169, 242, 242);
    glBegin(GL_LINES);
    glVertex2i(200, 300);
    glVertex2i(220, 300);

    glVertex2i(210, 310);
    glVertex2i(220, 310);

    glVertex2i(300, 300);
    glVertex2i(320, 300);

    glVertex2i(400, 300);
    glVertex2i(420, 300);

    glVertex2i(100, 320);
    glVertex2i(120, 320);

    glVertex2i(150, 260);
    glVertex2i(150, 260);

    glVertex2i(0, 270);
    glVertex2i(10, 270);

    glVertex2i(0, 280);
    glVertex2i(10, 280);

    glVertex2i(30, 265);
    glVertex2i(40, 265);

    glVertex2i(100, 330);
    glVertex2i(125, 330);

    glVertex2i(150,320);
    glVertex2i(165,320);

    glVertex2i(90,280);
    glVertex2i(100,280);

    glVertex2i(300,270);
    glVertex2i(320,270);

    glVertex2i(270,315);
    glVertex2i(275,315);

    glVertex2i(500,280);
    glVertex2i(510,280);

    glVertex2i(600,300);
    glVertex2i(615,300);

    glVertex2i(650,310);
    glVertex2i(665,310);

    glVertex2i(700,320);
    glVertex2i(715,320);

    glVertex2i(850,280);
    glVertex2i(865,280);

    glVertex2i(520,325);
    glVertex2i(540,325);

    glVertex2i(370,295);
    glVertex2i(380,295);
    glEnd();
    glPopMatrix();
     ////////////////////////////////////////////////////boat
    ////////////////////////////////noukar body
    glPushMatrix();
    glColor3ub (150, 129, 117);
    glBegin(GL_QUADS);
    glVertex2i(20, 300);
    glVertex2i(60, 300);
    glVertex2i(70, 310);
    glVertex2i(10, 310);
    glEnd();
    glPopMatrix();

    ///////////////////////////////noukar soi
    glPushMatrix();
    glColor3ub (206, 175, 109);
    glBegin(GL_POLYGON);
    glVertex2i(27, 310);
    glVertex2i(57, 310);
    glVertex2i(57, 320);
    glVertex2i(27, 320);
    glEnd();
    glPopMatrix();

    ////////////////////////////////pal er kapor
    glPushMatrix();
    glColor3ub (209, 102, 27);
    glBegin(GL_TRIANGLES);
    glVertex2i(57, 310);
    glVertex2i(90, 350);
    glVertex2i(50, 360);
    glEnd();
    glPopMatrix();
    ///////////////////////////noukar pal er khuda
    glPushMatrix();
    glColor3ub (206, 175, 109);
    glBegin(GL_LINES);
    glVertex2i(57, 310);
    glVertex2i(73, 360);
    glEnd();
    glPopMatrix();

    ///////////////////////////////noukar shadow
    glPushMatrix();
    glColor3ub (149, 187, 198);
    glBegin(GL_QUADS);
    glVertex2i(15, 290);
    glVertex2i(55, 290);
    glVertex2i(60, 300);
    glVertex2i(20, 300);
    glEnd();
    glPopMatrix();
    ////////////////////////////////////////////////////boat
}
///end river
//////////////circle drawing function


///HILLS
 void hills()
{
    glPushMatrix();
    glColor3ub(0, 0, 153);
    glBegin(GL_TRIANGLES);///////// gradually from left
    glVertex2i(0, 360);
    glVertex2i(60, 390);
    glVertex2i(120, 360);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(0, 0, 153);
    glBegin(GL_TRIANGLES);
    glVertex2i(115, 360);
    glVertex2i(170, 380);
    glVertex2i(220, 360);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(0, 0, 153);
    glBegin(GL_TRIANGLES);
    glVertex2i(215, 360);
    glVertex2i(315, 420);
    glVertex2i(415, 360);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(0, 0, 153);
    glBegin(GL_TRIANGLES);
    glVertex2i(640, 360);
    glVertex2i(720, 420);
    glVertex2i(800, 360);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(0, 0, 153);
    glBegin(GL_TRIANGLES);
    glVertex2i(380, 360);
    glVertex2i(460, 400);
    glVertex2i(550, 360);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(0, 0, 153);
    glBegin(GL_TRIANGLES);
    glVertex2i(545, 360);
    glVertex2i(600, 380);
    glVertex2i(650, 360);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(0, 0, 153);
    glBegin(GL_TRIANGLES);
    glVertex2i(640, 360);
    glVertex2i(720, 420);
    glVertex2i(800, 360);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(0, 0, 153);
    glBegin(GL_TRIANGLES);
    glVertex2i(800, 360);
    glVertex2i(850, 390);
    glVertex2i(890, 360);
    glEnd();
    glPopMatrix();

    ////lower trees
//TREE 2
    glPushMatrix();
    glScalef(0.50, 0.50, 0.25);
    //glTranslatef(1400, 500, 0);

    glColor3f(0, 0.8, 0.2);
    glBegin(GL_TRIANGLES);
    glVertex2i(545, 430);
    glVertex2i(592, 530);//440
	glVertex2i(645, 430);//340
	glEnd();

    glColor3f(0, 0.8, 0.2);
	glBegin(GL_TRIANGLES);
    glVertex2i(545, 450);
    glVertex2i(592, 540);//460
	glVertex2i(645, 450);//360
	glEnd();


	glColor3f(0.4, 0, 0.5);
	glBegin(GL_QUADS);
    glVertex2i(597, 430);//340
    glVertex2i(586, 430);
    glVertex2i(586, 340);//250
    glVertex2i(597, 340);
    glEnd();

    glPopMatrix();


    //tree 3

    glPushMatrix();
    glScalef(0.50, 0.50, 0.25);
    //glTranslatef(250, 600, 0);

    glColor3f(0, 0.8, 0.2);
    glBegin(GL_TRIANGLES);
    glVertex2i(665, 440);
    glVertex2i(712, 540);//440
	glVertex2i(760, 440);//340
	glEnd();

    glColor3f(0, 0.8, 0.2);
	glBegin(GL_TRIANGLES);
    glVertex2i(665, 460);
    glVertex2i(712, 540);//460
	glVertex2i(760, 460);//360
	glEnd();

	glColor3f(0.4, 0, 0.5);
	glBegin(GL_QUADS);
    glVertex2i(717, 440);
    glVertex2i(706, 440);//340
    glVertex2i(706, 360);
    glVertex2i(717, 360);//250
    glEnd();

    glPopMatrix();

    //tree 4

    glPushMatrix();

   //glTranslatef(150, 420, 0);
   glScalef(0.50, 0.50, 0.25);

    glColor3f(0, 0.8, 0.2);
    glBegin(GL_TRIANGLES);
    glVertex2i(790, 420);
    glVertex2i(837, 500);//440
	glVertex2i(890, 420);//340
	glEnd();

    glColor3f(0, 0.8, 0.2);
	glBegin(GL_TRIANGLES);
    glVertex2i(790, 440);
    glVertex2i(837, 540);//460
	glVertex2i(890, 440);//360
	glEnd();

	glColor3f(0.4, 0, 0.5);
	glBegin(GL_QUADS);
    glVertex2i(842, 420);
    glVertex2i(831, 420);//340
    glVertex2i(831, 320);
    glVertex2i(842, 320);//250
    glEnd();

    glPopMatrix();


    //tree 5

    glPushMatrix();

    //glTranslatef(-50, 400, 0);
    glScalef(0.50, 0.50, 0.25);

    glColor3f(0, 0.8, 0.2);
    glBegin(GL_TRIANGLES);
    glVertex2i(920, 410);
    glVertex2i(967, 490);//440
	glVertex2i(1020, 410);//340
	glEnd();

    glColor3f(0, 0.8, 0.2);
	glBegin(GL_TRIANGLES);
    glVertex2i(920, 430);
    glVertex2i(967, 520);//460
	glVertex2i(1020, 430);//360
	glEnd();

	glColor3f(0.4, 0, 0.5);
	glBegin(GL_QUADS);
    glVertex2i(972, 410);
    glVertex2i(961, 410);//340
    glVertex2i(961, 350);
    glVertex2i(972, 350);//250
    glEnd();

    glPopMatrix();

}


void BetweenRoadAndBuldings()
{
    glPushMatrix();
    glColor3ub(gdr,gdg,gdb);
    glBegin(GL_QUADS);
    glVertex2i(0,157);
    glVertex2i(902,157);
    glVertex2i(902,258);
    glVertex2i(0,258);
    glEnd();
    glPopMatrix();


    //TREE 1

    glPushMatrix();
    glScalef(0.5, 0.5, 0.5);
    glTranslatef(-90,70 , 0);

    glColor3f(0, 0.8, 0.2);
    glBegin(GL_TRIANGLES);
    glVertex2i(445, 400);
    glVertex2i(492, 450);
	glVertex2i(540, 400);//340
	glEnd();

    glColor3f(0, 0.8, 0.2);;
	glBegin(GL_TRIANGLES);
    glVertex2i(445, 420);//360
    glVertex2i(492, 500);//460
	glVertex2i(540, 420);//360
	glEnd();


	glColor3f(0.4, 0, 0.5);
	glBegin(GL_QUADS);
    glVertex2i(497, 400);//340
    glVertex2i(486, 400);
    glVertex2i(486, 315);//250
    glVertex2i(497, 315);
    glEnd();

    glPopMatrix();

    //tree 6

    glPushMatrix();

   glTranslatef(60, 40, 0);
    glScalef(0.50, 0.50, 0.25);

    glColor3f(0, 0.8, 0.2);
    glBegin(GL_TRIANGLES);
    glVertex2i(1050, 390);
    glVertex2i(1097, 480);//440
	glVertex2i(1150, 390);//340
	glEnd();

    glColor3f(0, 0.8, 0.2);
	glBegin(GL_TRIANGLES);
    glVertex2i(1050, 410);
    glVertex2i(1097, 500);//460
	glVertex2i(1150, 410);//360
	glEnd();

	glColor3f(0.4, 0, 0.5);
	glBegin(GL_QUADS);
    glVertex2i(1102, 390);
    glVertex2i(1091, 390);//340
    glVertex2i(1091, 315);
    glVertex2i(1102, 315);//250
    glEnd();

    glPopMatrix();
}

void draw_circle(float x, float y, float radius);
void draw_circle(float x, float y, float radius) {

    glPushMatrix();
    glTranslatef(x, y, 0.0f);
    static const int circle_points = 100;
    static const float angle = 2.0f * 3.1416f / circle_points;

    glBegin(GL_POLYGON);
    double angle1=0.0;
    glVertex2d(radius * cos(0.0) , radius * sin(0.0));
    int i;
    for (i=0; i<circle_points; i++)
    {
        glVertex2d(radius * cos(angle1), radius *sin(angle1));
        angle1 += angle;
    }
    glEnd();
    glPopMatrix();
}
void GrassField(){   ///////analog tree
    int treeDistance=20;
    for(int i=0;i<5;i++){
        glBegin(GL_POLYGON);
        glColor3ub(102, 51, 0);  //tree body color
        glVertex2i(60+treeDistance,30);
        glVertex2i(70+treeDistance,30);
        glVertex2i(65+treeDistance,150);
        glEnd();
        glColor3f(0, 0.8, 0.2);   //tree leaf color
        draw_circle(50+treeDistance,100,20);     //tree  top 1st leaf
        draw_circle(80+treeDistance,100,20);     //tree top 2nd leaf
        draw_circle(58+treeDistance,130,18);     //tree middle 1st leaf
        draw_circle(72+treeDistance,130,18);     //tree middle 2nd leaf
        draw_circle(65+treeDistance,150,14);     //tree top leaf

        treeDistance=treeDistance+180;
    }
}






void City()
{
     ///====================================  Building two
    glPushMatrix();
    glTranslatef(0, 8, 0);
    glScalef(0.85, 0.85, 0.85);
    glBegin(GL_POLYGON);
	glColor3ub(153, 51, 51);
    glVertex2i(100,420);
    glVertex2i(200,420);
    glVertex2i(200,600);
    glVertex2i(100,600);
    glEnd();

    int buildingY1=570,buildingY2=573;
	for(int i=0;i<6;i++){
        //=================flor of building 2
        glBegin(GL_POLYGON);
        glColor3ub(153, 153, 102);
        glVertex2i(100,buildingY1);
        glVertex2i(200,buildingY1);
        glVertex2i(200,buildingY2);
        glVertex2i(100,buildingY2);
        glEnd();
        buildingY1=buildingY1-25;
        buildingY2=buildingY2-25;
	}

	///====================================  Building one
    glBegin(GL_POLYGON);
	glColor3ub(102, 153, 153);
    glVertex2i(10,420);
    glVertex2i(110,420);
    glVertex2i(110,580);
    glVertex2i(10,580);
    glEnd();

    //===============================gate of building one
    glBegin(GL_POLYGON);
	glColor3ub(bulr,bulg, bulb);
    glVertex2i(50,420);
    glVertex2i(70,420);
    glVertex2i(70,440);
    glVertex2i(50,440);
    glEnd();

    int b1y1=450,b1y2=460;
    int b1x1=15,b1x2=35;
	for(int i=1;i<16;i++){
        glBegin(GL_POLYGON);

        glColor3ub(bulr, bulg, bulb);
        glVertex2i(b1x1,b1y1);
        glVertex2i(b1x2,b1y1);
        glVertex2i(b1x2,b1y2);
        glVertex2i(b1x1,b1y2);
        glEnd();


        b1x1=b1x1+35;
        b1x2=b1x2+35;
        if(i%3==0){
            b1x1=15;
            b1x2=35;
            b1y1=b1y1+25;
            b1y2=b1y2+25;
        }

	}

    ///==================================== Building three
    glBegin(GL_POLYGON);
	glColor3ub(102, 51, 0);
    glVertex2i(190,420);
    glVertex2i(300,420);
    glVertex2i(300,560);
    glVertex2i(190,560);
    glEnd();

    int b3y1=430,b3y2=440;
    int b3x1=200,b3x2=215;
    for(int j=1;j<21;j++){
        glBegin(GL_POLYGON);

        glColor3ub(bulb, bulg, bulb);
        glVertex2i(b3x1,b3y1);
        glVertex2i(b3x2,b3y1);
        glVertex2i(b3x2,b3y2);
        glVertex2i(b3x1,b3y2);
        glEnd();


        b3x1=b3x1+25;
        b3x2=b3x2+25;
        if(j%4==0){
            b3x1=200;
            b3x2=215;
            b3y1=b3y1+25;
            b3y2=b3y2+25;
        }

    }
    //==========================================antina

    for(int i=0;i<5;i++){
        glBegin(GL_POLYGON);
        if(i%2==0){
            glColor3ub(153, 204, 0);
        }
        else{
            glColor3ub(153,0, 0);
        }

        glVertex2i(200+(i*10),560+(i*5));
        glVertex2i(290-(i*10),560+(i*5));
        glVertex2i(290-(i*10),565+(i*5));
        glVertex2i(200+(i*10),565+(i*5));
        glEnd();
    }

    glBegin(GL_POLYGON);
	glColor3ub(102, 51, 0);
    glVertex2i(243,585);
    glVertex2i(247,585);
    glVertex2i(247,640);
    glVertex2i(243,640);
    glEnd();
    glPopMatrix();

    //////////city tree
    glPushMatrix();   //////tree1
    glScalef(0.5, 0.5, 0.5);
    glTranslatef(100, 476, 0);

    glColor3f(0, 0.8, 0.2);
    glBegin(GL_TRIANGLES);
    glVertex2i(445, 340);
    glVertex2i(492, 440);
	glVertex2i(540, 340);
	glEnd();

    glColor3f(0, 0.8, 0.5);
	glBegin(GL_TRIANGLES);
    glVertex2i(445, 360);
    glVertex2i(492, 460);
	glVertex2i(540, 360);
	glEnd();


	glColor3f(0.4, 0, 0.5);
	glBegin(GL_QUADS);
    glVertex2i(497, 340);
    glVertex2i(486, 340);
    glVertex2i(486, 250);
    glVertex2i(497, 250);
    glEnd();

    glPopMatrix();
    glPushMatrix();   ////////tree2
    glTranslatef(430, -100, 0);
    glTranslatef(0, 400, 0);
    glScalef(0.25, 0.25, 0.25);
    glColor3f(0, 0.8, 0.2);
    glBegin(GL_TRIANGLES);
    glVertex2i(445, 340);
    glVertex2i(492, 440);
	glVertex2i(540, 340);
	glEnd();

    glColor3f(0, 0.8, 0.5);
	glBegin(GL_TRIANGLES);
    glVertex2i(445, 360);
    glVertex2i(492, 460);
	glVertex2i(540, 360);
	glEnd();

	glColor3f(0.4, 0, 0.5);
	glBegin(GL_QUADS);
    glVertex2i(497, 340);
    glVertex2i(486, 340);
    glVertex2i(486, 250);
    glVertex2i(497, 250);
    glEnd();

    glPopMatrix();

    glPushMatrix(); /////////tree 3
    glTranslatef(540, -100, 0);
    glTranslatef(0, 400, 0);
    glScalef(0.25, 0.25, 0.25);
    glColor3f(0, 0.8, 0.2);
    glBegin(GL_TRIANGLES);
    glVertex2i(445, 340);
    glVertex2i(492, 440);
	glVertex2i(540, 340);
	glEnd();

    glColor3f(0, 0.8, 0.5);
	glBegin(GL_TRIANGLES);
    glVertex2i(445, 360);
    glVertex2i(492, 460);
	glVertex2i(540, 360);
	glEnd();

	glColor3f(0.4, 0, 0.5);
	glBegin(GL_QUADS);
    glVertex2i(497, 340);
    glVertex2i(486, 340);
    glVertex2i(486, 250);
    glVertex2i(497, 250);
    glEnd();

    glPopMatrix();
}
void Bench(){

    glPushMatrix();
    glTranslatef(0, -173, 0);

    glColor3ub(8,32,19); /////back low to up
    glBegin(GL_QUADS);
    glVertex2i(580,565);
    glVertex2i(620+20,565);
    glVertex2i(620+20,570);
    glVertex2i(580,570);
    glEnd();

    glColor3ub(8,32,19);
    glBegin(GL_QUADS);
    glVertex2i(580,573);
    glVertex2i(620+20,573);
    glVertex2i(620+20,578);
    glVertex2i(580,578);
    glEnd();

    glColor3ub(8,32,19);
    glBegin(GL_QUADS);
    glVertex2i(580,581);
    glVertex2i(620+20,581);
    glVertex2i(620+20,586);
    glVertex2i(580,586);
    glEnd();

    glColor3ub(8,32,19);  /////////sits
    glBegin(GL_QUADS);
    glVertex2i(580,555+5);
    glVertex2i(620+20,555+5);
    glVertex2i(627+20,542+5);
    glVertex2i(572,542+5);
    glEnd();

    glColor3ub(8,32,19);  /////////angel
    glBegin(GL_QUADS);
    glVertex2i(605-20,560);
    glVertex2i(608-20,560);
    glVertex2i(608-20,586);
    glVertex2i(605-20,586);
    glEnd();

    glColor3ub(8,32,19);  /////////angel
    glBegin(GL_QUADS);
    glVertex2i(635,560);
    glVertex2i(632,560);
    glVertex2i(632,586);
    glVertex2i(635,586);
    glEnd();


    glColor3ub(8,32,19);  /////////legs
    glBegin(GL_QUADS);
    glVertex2i(575+8,547);
    glVertex2i(582+5,547);
    glVertex2i(582+5,538);
    glVertex2i(575+8,538);
    glEnd();

    glColor3ub(8,32,19);
    glBegin(GL_QUADS);
    glVertex2i(629+4,547);
    glVertex2i(637,547);
    glVertex2i(637,538);
    glVertex2i(629+4,538);
    glEnd();

    glPopMatrix();




}
void Industry(){
     ///////////////////////////////////garments
    glPushMatrix();  ////body
    glTranslatef(0, -65, 0);
    glBegin(GL_QUADS);
	glColor3ub(153, 51, 0);
    glVertex2i(720, 430);
    glVertex2i(870, 430);
    glVertex2i(870, 510);
    glVertex2i(720, 510);
    glEnd();

    glBegin(GL_QUADS);      //// left pipe
	glColor3ub(153, 51, 0);
    glVertex2i(765, 510);
    glVertex2i(785, 510);
    glVertex2i(785, 570);
    glVertex2i(765, 570);
    glEnd();

    glBegin(GL_QUADS);    ////pipe
	glColor3ub(153, 51, 0);
    glVertex2i(815, 510);
    glVertex2i(835, 510);
    glVertex2i(835, 570);
    glVertex2i(815, 570);
    glEnd();


    glColor3ub(102, 153, 153);
    drawCircle(773.0f,575.0f,4.0f);
    drawCircle(778.0f,585.0f,7.0f);
    drawCircle(782.0f,597.0f,10.0f);
    drawCircle(825.0f,575.0f,6.0f);
    drawCircle(778+55.0f,585.0f,7.0f);
    drawCircle(782+55.0f,597.0f,10.0f);


    glBegin(GL_TRIANGLES);
	glColor3ub(102, 51, 0);
    glVertex2i(720, 510);
    glVertex2i(750, 560);
    glVertex2i(760, 510);
    glEnd();

    glBegin(GL_TRIANGLES);
	glColor3ub(102, 51, 0);
    glVertex2i(745, 510);
    glVertex2i(790, 560);
    glVertex2i(800, 510);
    glEnd();

    glBegin(GL_TRIANGLES);
	glColor3ub(102, 51, 0);
    glVertex2i(785, 510);
    glVertex2i(850, 560);
    glVertex2i(870, 510);
    glEnd();

int inx1=725,inx2=745,iny1=470,iny2=490;
 for(int i=1 ; i<=10 ; i++){

    glBegin(GL_POLYGON);  ///industry window
    glColor3ub(242, 242, 242);
    glVertex2i(inx1,iny1);
    glVertex2i(inx2,iny1);
    glVertex2i(inx2,iny2);
    glVertex2i(inx1,iny2);
    glEnd();

    inx1+=30;
    inx2+=30;

    if(i%5==0)
    {
        iny1-=30;
        iny2-=30;

        inx1=725;
        inx2=745;
    }
 }
    glPopMatrix();

}

/*void Rain(int value){

if(rainday){

    rain += 0.01f;

    glBegin(GL_POINTS);
    for(int i=1;i<=1000;i++)
    {
        int x=rand(),y=rand();
        x%=1000; y%=1000;
        glBegin(GL_LINES);
        glColor3f(1.0, 1.0, 1.0);
        glVertex2d(x,y);
        glVertex2d(x+5,y+5);
        glEnd();
    }

	glutPostRedisplay();
	glutTimerFunc(5, Rain, 0);

    glFlush();
   }
}*/

void update(int value)
{

    cloud=cloud+.04;
    if(cloud > 800)
    {
        cloud =-600;
    }
 //cout << "Cloud :" << cloud << endl;


     _run += 0.01f;
	if (_run > 1000)
    {
        _run -= 1700;
    }

    _run1 += 3.0f;
	if (_run1 > 1000)
    {
        _run1 -= 1300;
    }

    _run2 += 2.5f;
	if (_run2 > 1000)
    {
        _run2 -= 1300;
    }

     _run3 += 3.0f;
	if (_run3 > 1000)
    {
        _run3 -= 1700;
    }

    if(onOff){
	_ang_tri += 2.5f;
	if (_ang_tri > 1000){
		_ang_tri = 1300;
	}
	 }

	glutPostRedisplay(); //Tell GLUT that the display has changed
	glutTimerFunc(0, update, 25);
}



////////////////////////////////////////////move water
void movewater()
{
    if (waterStatus ==1)
    {
        waterX += 0.1;

    }
    if (waterX>900)
    {
        waterX = -200;
        glutPostRedisplay();
    }
    glPushMatrix();
    glTranslatef(waterX, waterY, 0);
    water();
    glPopMatrix();
}
void moveCar()
{
    if (carStatus ==1)
    {
        car1X += 0.5;
        car2X -= 0.5;
        planeX += 0.4;

    }
    if (car1X>1300)
    {
        car1X = -350;
        car2X =  900;
        planeX = -200;
        glutPostRedisplay();
    }
    glPushMatrix();
    glTranslatef(car1X, car1Y, 0);
    Car1();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(car2X, car2Y, 0);
    Car2();
    glPopMatrix();
    glTranslatef(planeX, planeY, 0);
    Plane();
    glPopMatrix();
}

void railForward(int value){

if(frd){

    _ang_tri += 2.5f;

    if (_ang_tri > 1000) {
		_ang_tri -= 1600;
	}

	glutPostRedisplay();
	glutTimerFunc(25, railForward, 0);
}
}

void railBackward(int value){
if(bck){

    _ang_tri -= 2.2f;

     if (_ang_tri < -350) {
		_ang_tri = 1100;
	}
	glutPostRedisplay();
	glutTimerFunc(25, railBackward, 0);
}
}

void keyboard(unsigned char key, int x, int y)
{
    if (key == 'Q' || key == 'q')
	{
		waterStatus = 1;
	}

	else if (key == 'T' || key == 't')
	{
		waterStatus = 0;
	}

    if (key == 'A' || key == 'a')
	{
		carStatus = 1;
	}

	else if (key == 'S' || key == 's')
	{
		carStatus = 0;
	}
    if(key=='e' || key=='E')
    {
        exit(1);
    }

    if(key=='n' || key=='N')
    {
        if(dnr==45 && dng==179 && dnb==236) ////when night
        {
            dnr=0;
            dng=50;
            dnb=59;

            ldr=255;
            ldg=244;
            ldb=78;

            sdr=0;
            sdg=50;
            sdb=59;

            cdr=0;
            cdg=50;
            cdb=59;

            gdr=29;
            gdg=96;
            gdb=17;

            m1r=246;
            m1g=171;
            m1b=26;

            m2r=0;
            m2g=50;
            m2b=59;

            bulr=242;
            bulg=242;
            bulb=242;

            ldr=255;
            ldg=244;
            ldb=78;

            hlr=22;
            hlg=229;
            hlb=236;

        }else if(dnr==0 && dng==50 && dnb==59)
        {
            dnr=45;
            dng=179;
            dnb=236;

            ldr=255;
            ldg=255;
            ldb=255;

            sdr=246;
            sdg=171;
            sdb=26;

            cdr=230;
            cdg=234;
            cdb=237;

            gdr=100;
            gdg=171;
            gdb=55;

            m1r=103;
            m1g=155;
            m1b=176;

            m2r=103;
            m2g=155;
            m2b=176;

            bulr=191;
            bulg=191;
            bulb=165;

            ldr=0;
            ldg=0;
            ldb=0;

            hlr=5;
            hlg=150;
            hlb=155;


        }
    }
    if(key=='d' || key=='D')
    {
        if(scr ==152 && scg ==135 && scb ==135 ) ////digital school and river color change
        {
            scr=214;
            scg=130;
            scb=5;

            rir=144;
            rig=183;
            rib=188;

        }
        else if(scr ==214 && scg ==130 && scb ==5) ///analog
        {
            scr=152;
            scg=135;
            scb=135;

            rir=133;
            rig=230;
            rib=230;


        }

    }


    if(key == 'g' || key == 'G')
    {
        frd = false;
	    bck = true;
	    railBackward(_ang_tri);
    }
   if(key == 'h' || key == 'H')
    {
        frd = true;
        bck = false;
        railForward(_ang_tri);
    }

   else if(key == 'j' || key == 'J')
    {
        frd = false;
        bck = false;
        railForward(_ang_tri);
    }

}


void myDisplay(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    Sky();
    Sun();
    Cloud();
    river();
    movewater();
    BetweenRoadAndBuldings();
    RoadGrash();


    if(ldr==255 && ldg==244 && ldb==78)  ///when night
    {
        Moon();
    }

    if(scr ==214 && scg ==130 && scb ==5)  ///digital
    {
        Road();
        RoadCorner1();
        RoadCorner2();
        Car1();
        moveCar();
        Car2();
        Plane();
        Tree();
        Home();
        Hotel();
        Door();
        City();
        Industry();
        Bench();
        print(398,518,hotel);
    }
    if(scr ==152 && scg ==135 && scb ==135)  ///analog
    {
        Rasta();
        house();
        //GrassField();
        hills();
        trainline();
        railbody();
    }

    School();
    SchoolDoor();

    print(732,241,school);
    print(10,665,manual);
    print(10,650,text);
    print(10,620,e);

    glFlush ();
    glutPostRedisplay();
    glutSwapBuffers();
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (902,684);
    glutInitWindowPosition (250, 30);
    glutCreateWindow ("Rural to Metro City View");
    glutDisplayFunc(myDisplay);
    glutTimerFunc(0,update,25);
    glutKeyboardFunc(keyboard);
    myInit ();
    glutMainLoop();
}
