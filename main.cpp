///////////////////////////////////////////////////////////
#include<windows.h>
#include <stdio.h>
#include <math.h>
#include <bits/stdc++.h>
#include <GL\glut.h>

void Mountain();
void AIUB();
void City();
void rainf();
void Airport();
void Airport1();
void Sea();
void stars();
void Final();
void Plane();
void sun(GLfloat x,GLfloat Y);

////////////////////////////////////////////////////////////

GLfloat YY1=860;
GLfloat x1=500;
int count1=0;
GLfloat a = 1.001;
GLfloat carX=.1;
GLfloat x=50,y=150,nl=0;
GLfloat gfPosSX = 250.0;
GLfloat gfPosSY = 600.0;
GLfloat gfPosX = 830.0;
GLfloat gfPosY = 309.0;
GLfloat gfPosX1 =800.0;
GLfloat gfPosY1 =340.0;
GLfloat gfPosX2 =0.0;
GLfloat gfPosY2 = 5.0;
GLfloat gfDeltaX = 4.0;
GLfloat gfDeltaY = 0.0;
GLfloat sx=900,sy=400,lx=1000,ly=250;
bool rain=false;
bool clud=false;

int count=0,scount=0;
float radius=5,radiusC=3;
GLfloat gfDeltaX1 = 4.0;
GLfloat gfDeltaY1 = 0.0;


void Timer(int i)
{
    glutPostRedisplay();
    glutTimerFunc(26, Timer, 0);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////

float move,angle;

void DrawCircle(float cx, float cy, float r, int num_segments)
{

		 glBegin(GL_TRIANGLE_FAN);
		for (int i = 0; i < num_segments; i++)
		{
		float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);//get the current angle

		float x = r * cosf(theta);//calculate the x component
		float y = r * sinf(theta);//calculate the y component

		glVertex2f(x + cx, y + cy);//output vertex

		}
		glEnd();
	}

void cloud()
	{
		glColor3f(1.0, 1.0, 1.0);
		//cloud1
		DrawCircle(500, 930, 20, 500);
		DrawCircle(530, 930, 25, 500);
		DrawCircle(560, 930, 17, 500);
		//cloud2
		DrawCircle(100, 950, 20, 500);
		DrawCircle(130, 950, 25, 500);
		DrawCircle(160, 950, 17, 500);
		//cloud3
		DrawCircle(700, 920, 20, 500);
		DrawCircle(730, 920, 25, 500);
		DrawCircle(760, 920, 17, 500);
        //cloud14
		DrawCircle(250, 900, 20, 500);
		DrawCircle(280, 900, 25, 500);
		DrawCircle(310, 900, 17, 500);
	}

void Full(int r,int g,int b)
{
    glColor3ub(r,g,b);
    glBegin(GL_QUADS);
    glVertex3i(-200,0,0);
    glVertex3i(1324,0,0);
    glVertex3i(1324,768,0);
    glVertex3i(-200,768,0);
}
//Road
void Road()
{
    glColor3ub(78,78,78);
    glBegin(GL_QUADS);
    glVertex3i(-200,0,0);
    glVertex3i(1324,0,0);
    glVertex3i(1324,120,0);
    glVertex3i(-200,120,0);
    glEnd();
}
void roadBorder()
{
    glColor3ub(255,255,255);
    glBegin(GL_QUADS);
    glVertex3i(-200,120,0);
    glVertex3i(1324,120,0);
    glVertex3i(1324,130,0);
    glVertex3i(-200,130,0);
    glEnd();
}
//ROad Line
void RoadLine(int x,int y,int z)
{
    glColor3ub(255,255,255);
    glBegin(GL_QUADS);
    glVertex3i(x,y,z);
    glVertex3i(x+50,y,z);
    glVertex3i(x+50,y+10,z);
    glVertex3i(x,y+10,z);
    glEnd();
}

void tprint(int x, int y,int z, char *string)
{
    //set the position of the text in the window using the x and y coordinates
    glRasterPos2f(x,y);
    //get the length of the string to display
    int len = (int) strlen(string);

    //loop to display character by character
    for (int i = 0; i < len; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,string[i]);
    }
};
void playGround(int r,int g,int b)
{
    //Grass
    glColor3ub(r,g,b);
    glBegin(GL_QUADS);
    glVertex3i(-200,120,0);
    glVertex3i(1324,120,0);
    glVertex3i(1324,260,0);
    glVertex3i(-200,260,0);
    glEnd();

    //Walkway
    glColor3ub(94, 65, 33);
    glBegin(GL_QUADS);
    glVertex3i(-200,250,0);
    glVertex3i(1324,250,0);
    glVertex3i(1324,260,0);
    glVertex3i(-200,260,0);

}
//dynamic lamp post function
void lampPost(int x,int y,int z)
{
    //verticle
    glColor3ub(222,250,50);
    glBegin(GL_QUADS);
    glVertex3i(x,y,z);
    glVertex3i(x+7,y,z);
    glVertex3i(x+7,y+100,z);
    glVertex3i(x,y+100,z);
    glEnd();

    //horizontal
    glColor3ub(222,250,50);
    glBegin(GL_QUADS);
    glVertex3i(x,y+93,z);
    glVertex3i(x+70,y+93,z);
    glVertex3i(x+70,y+100,z);
    glVertex3i(x,y+100,z);
    glEnd();

    //lightcarry
    glColor3ub(222,250,50);
    glBegin(GL_TRIANGLES);
    glVertex3i(x+50,y+85,z);
    glVertex3i(x+70,y+85,z);
    glVertex3i(x+60,y+93,z);
    glEnd();
}
//light
void Light(int x,int y,int z)
{
    //light
    glColor3ub(200,200,200);
    glBegin(GL_QUADS);
    glVertex3i(x+9,y,z);
    glVertex3i(x+110,y,z);
    glVertex3i(x+70,y+85,z);
    glVertex3i(x+50,y+85,z);
    glEnd();

}

//Dynamic Tree Function
void Tree(int x,int y,int z)
{
    //Timber
    glColor3ub(90,70,60);
    glBegin(GL_QUADS);
    glVertex3i(x,y,z);
    glVertex3i(x+7,y,z);
    glVertex3i(x+7,y+20,z);
    glVertex3i(x,y+20,z);
    glEnd();

    //Lower Leaf
    glColor3ub(14,120,14);
    glBegin(GL_TRIANGLES);
    glVertex3i(x-15,y+19,z);
    glVertex3i(x+22,y+19,z);
    glVertex3f(x+3.5,y+45,z);
    glEnd();

    //Upper Leaf
    glBegin(GL_TRIANGLES);
    glVertex3i(x-10,y+35,z);
    glVertex3i(x+17,y+35,z);
    glVertex3f(x+3.5,y+60,z);
    glEnd();
}
//Dynamic Windows Function
void Windows(int x,int y,int z)
{
    glColor3ub(255,255,255);
    glBegin(GL_QUADS);
    glVertex3i(x,y,z);
    glVertex3i(x+60,y,z);
    glVertex3i(x+60,y+70,z);
    glVertex3i(x,y+70,z);
    glEnd();

    //Black
    glColor3ub(0,0,0);
    glBegin(GL_QUADS);
    glVertex3i(x+7,y+7,z);
    glVertex3i(x+27,y+7,z);
    glVertex3i(x+27,y+33,z);
    glVertex3i(x+7,y+33,z);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3i(x+33,y+7,z);
    glVertex3i(x+54,y+7,z);
    glVertex3i(x+54,y+33,z);
    glVertex3i(x+33,y+33,z);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3i(x+7,y+40,z);
    glVertex3i(x+27,y+40,z);
    glVertex3i(x+27,y+63,z);
    glVertex3i(x+7,y+63,z);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3i(x+33,y+40,z);
    glVertex3i(x+54,y+40,z);
    glVertex3i(x+54,y+63,z);
    glVertex3i(x+33,y+63,z);
    glEnd();
}
//Buildings
void FirstBuilding(int r,int g,int b)
{
   int windowsXf=-310,windowsXl=556;

    //Left Building
    glColor3ub(r,g,b);
    glBegin(GL_QUADS);
    glVertex3i(-200,260,0);
    glVertex3i(396,260,0);
    glVertex3i(396,375,0);
    glVertex3i(-200,375,0);
    glEnd();

    //Right Building
    glBegin(GL_QUADS);
    glVertex3i(628,260,0);
    glVertex3i(1324,260,0);
    glVertex3i(1324,375,0);
    glVertex3i(628,375,0);
    glEnd();

    //Middle
    glColor3ub(48,49,54);
    glBegin(GL_QUADS);
    glVertex3i(396,260,0);
    glVertex3i(628,260,0);
    glVertex3i(628,400,0);
    glVertex3i(396,400,0);
    glEnd();

    //First 4 Windows
    for(int i=6;i>=0;i--)
    {
        windowsXf+=90;
        Windows(windowsXf,280,0);
    }
    //Last 4 Windows
    for(int i=7;i>=0;i--)
    {
        windowsXl+=90;
        Windows(windowsXl,280,0);
    }
}
//Cross For Tin Shade;
void Cross(int x,int y,int z)
{
    glColor3b(10,150,12);
    glBegin(GL_QUADS);

    glVertex3i(x,y,z);
    glVertex3i(x+2,y,z);
    glVertex3i(x+2,y+15,z);
    glVertex3i(x,y+15,z);
    glEnd();

}
//TinShade
void TinShade()
{
    glColor3ub(233,235,238);
    //Left One
    glBegin(GL_QUADS);
    glVertex3i(-200,375,0);
    glVertex3i(396,375,0);
    glVertex3i(396,390,0);
    glVertex3i(-200,390,0);
    glEnd();

    //Right One
    glBegin(GL_QUADS);
    glVertex3i(628,375,0);
    glVertex3i(1324,375,0);
    glVertex3i(1324,390,0);
    glVertex3i(628,390,0);
    glEnd();

    //Middle One
    glBegin(GL_QUADS);
    glVertex3i(386,400,0);
    glVertex3i(638,400,0);
    glVertex3i(638,420,0);
    glVertex3i(386,420,0);
    glEnd();
    //Green Top
    glColor3ub(42,85,6);
    glBegin(GL_QUADS);
    glVertex3i(-200,390,0);
    glVertex3i(396,390,0);
    glVertex3i(396,395,0);
    glVertex3i(-200,395,0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3i(628,390,0);
    glVertex3i(1324,390,0);
    glVertex3i(1324,395,0);
    glVertex3i(628,395,0);
    glEnd();

    //Left Top Side
    glColor3ub(140,140,130);
    glBegin(GL_QUADS);
    glVertex3i(0,395,0);
    glVertex3i(125,395,0);
    glVertex3i(120,410,0);
    glVertex3i(0,410,0);
    glEnd();
    //Cross
    int CrossX=0;
    for(int i=15;i>0;i--)
    {
        Cross(CrossX,395,0);
        CrossX+=8;
    }

    glColor3b(10,150,12);
    glBegin(GL_QUADS);
    glVertex3i(0,400,0);
    glVertex3i(125,400,0);
    glVertex3i(122,402,0);
    glVertex3i(0,402,0);
    glEnd();
}

void Pillar(int x,int y,int z)
{
    glColor3ub(166,166,166);
    glBegin(GL_QUADS);
    glVertex3i(x,y,z);
    glVertex3i(x+3,y,z);
    glVertex3i(x+3,y+45,z);
    glVertex3i(x,y+45,z);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3i(x+15,y,z);
    glVertex3i(x+18,y,z);
    glVertex3i(x+18,y+40,z);
    glVertex3i(x+15,y+40,z);
    glEnd();
}

void VerticalLine(int x,int y,int z)
{
    for(int i=10;i>=0;i--)
    {
        glColor3ub(166,166,166);
        glBegin(GL_QUADS);
        glVertex3i(x,y,0);
        glVertex3i(x+2,y,0);
        glVertex3i(x+2,y+35,0);
        glVertex3i(x,y+35,0);
        glEnd();
        x+=10;
    }
}

void HorizontalLine(int x,int y,int z)
{
    for(int i=3;i>=0;i--)
    {
        glColor3ub(166,166,166);
        glBegin(GL_QUADS);
        glVertex3i(x,y,0);
        glVertex3i(x+105,y,0);
        glVertex3i(x+105,y+2,0);
        glVertex3i(x,y+2,0);
        glEnd();
        y+=10;
    }
}


//Middle top Corridor Main Function
void MiddleTop()
{
    //Top
    glColor3ub(205,205,205);
    glBegin(GL_QUADS);
    glVertex3i(300,430,0);
    glVertex3i(405,430,0);
    glVertex3i(405,450,0);
    glVertex3i(300,450,0);
    glEnd();
    glColor3ub(255,0,0);
    //Pillar
    glColor3ub(166,166,166);
    glBegin(GL_QUADS);
    glVertex3i(300,395,0);
    glVertex3i(303,395,0);
    glVertex3i(303,430,0);
    glVertex3i(300,430,0);
    glEnd();

    glColor3ub(166,166,166);
    glBegin(GL_QUADS);
    glVertex3i(402,420,0);
    glVertex3i(405,420,0);
    glVertex3i(405,430,0);
    glVertex3i(402,430,0);
    glEnd();
    //Line
    VerticalLine(300,395,0);
    HorizontalLine(300,395,0);
    //Shadow
    glColor3ub(5,5,5);
    glBegin(GL_QUADS);
    glVertex3i(300,427,0);
    glVertex3i(405,427,0);
    glVertex3i(405,431,0);
    glVertex3i(300,431,0);
    glEnd();
}
void FrontTop()
{
    int pillarX=0;

    glColor3ub(147,154,174);
    glBegin(GL_QUADS);
    glVertex3i(3,395,0);
    glVertex3i(120,395,0);
    glVertex3i(120,440,0);
    glVertex3i(3,442,0);
    glEnd();

    glColor3ub(147,154,174);
    glBegin(GL_QUADS);
    glVertex3i(120,395,0);
    glVertex3i(220,395,0);
    glVertex3i(220,410,0);
    glVertex3i(120,410,0);
    glEnd();

    //Green Tin Shade
    glColor3ub(83,186,60);
    glBegin(GL_QUADS);
    glVertex3i(0,440,0);
    glVertex3i(200,440,0);
    glVertex3i(210,455,0);
    glVertex3i(10,455,0);
    glEnd();
    //Front Triangle
    glColor3ub(48,56,67);
    glBegin(GL_TRIANGLES);
    glVertex3i(190,435,0);
    glVertex3i(220,435,0);
    glVertex3i(210,455,0);
    glEnd();
    //Shadow
    glBegin(GL_QUADS);
    glVertex3i(0,436,0);
    glVertex3i(200,435,0);
    glVertex3i(210,440,0);
    glVertex3i(0,440,0);
    glEnd();
    //Pillar
    for(int i=6;i>=0;i--)
    {

        Pillar(pillarX,395,0);
        pillarX+=32;
    }

    glBegin(GL_QUADS);
    glVertex3i(217,395,0);
    glVertex3i(220,395,0);
    glVertex3i(220,435,0);
    glVertex3i(217,435,0);
    glEnd();
}

void drawFilledCircle(GLfloat x, GLfloat y,GLfloat z, GLfloat radius,int color){
	int i;
	int triangleAmount = 50; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * 3.1416;
    int counter=0;
    glColor3ub(color,color,color);
	glBegin(GL_TRIANGLE_FAN);
		glVertex3f(x, y,z); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			counter+=1;
			glVertex3f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount)),z
			);
			if(counter<25)
            {
                color+=3;
                glColor3ub(color,color,color);
            }
            else
            {
                color-=3;
                glColor3ub(color,color,color);
            }
		}
	glEnd();
}


void circleLine()
{
    glColor3ub(240,240,240);
    glBegin(GL_LINES);
    glLineWidth(5.0f);
    glVertex3i(780,500,0);
    glVertex3i(1120,500,0);
    glVertex3i(788,550,0);
    glVertex3i(1112,550,0);
    glVertex3i(812,600,0);
    glVertex3i(1088,600,0);
    glVertex3i(788,450,0);
    glVertex3i(1112,450,0);
    glVertex3i(812,400,0);
    glVertex3i(1088,400,0);
    glEnd();
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
void rainf()
{
    int x=0;
    int y=778;
    static float a=-760.0f;
    if(a<=-768)
    {
         a=-760.0f;
    }
    else
    {
        a-=0.5f;
        //glColor3ub(r,g,b);
    }
    glPushMatrix();
    glTranslatef(0.0f,a,0.0f);
    glBegin(GL_LINES);
    for(int i=500;i>=0;i--)
    {
        for(int j=0;j<=i;j++)
        {
            glVertex3i(x,y,0);
            glVertex3i(x+3,y+10,0);
            x+=rand()%1050;
        }
        y+=rand()%15;
        x=0;

    }
    glEnd();
    glPopMatrix();
}
void AIUB()
{

    glBegin(GL_QUADS);
    glVertex2f(0,0);
    glColor3f(0,0,1);
    glVertex2f(0,1000);
    glColor3f(0,0,1);
    glVertex2f(1000,1000);
    glColor3f(1,0.5,0);
    glVertex2f(1000,0);
    glEnd();
        int roadlineX=-300;
        int treeXf=-350;
        int treeXl=528;
        int lamp=-350;
        int light=-350;

       // Full(131,183,231);
        //Road
        Road();
        glColor3f(1,.6,0);
        sun(850,830);

        //RoadLine
        for(int i=55;i>0;i--)
        {
            roadlineX+=100;
            RoadLine(roadlineX,55,0);
        }
        //Play Ground
        playGround(42,95,17);
        //Middle Top Corridor
        MiddleTop();

        drawFilledCircle(950.0f,500.0f,0.0f,170.0f,137.0f);
        //Building
        FirstBuilding(134, 89, 45);

        //First 4 Tree
        for(int i=5;i>=0;i--)
        {
            treeXf+=120;
            Tree(treeXf,260,0);
        }
        //Last 4 Tree
        for(int i=5;i>=0;i--)
        {
            treeXl+=120;
            Tree(treeXl,260,0);
        }
        //Front top corridor
        FrontTop();

        //TinShade

        TinShade();

        //lamp post
        for(int i=9;i>=0;i--)
        {
            lamp+=310;
            lampPost(lamp,130,0);
        }
        //light
        roadBorder();
        TinShade();
        circleLine();
        glColor3f(0,0,1);
        tprint(330,433,0,"AIUB");

        glPopMatrix();
        Plane();
        if(clud)
        {
            cloud();
        }
        stars();

        glColor3f(1,1,1);
        char *o="AIUB";
        glRasterPos2f( 70 , 80 );
        for(int i = 0; o[i] !='\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, o[i]);

        if(rain)
        {
            rainf();
        }
        glFlush();
}

void Plane()
{
    float angle;
    float x2,y2;
    //tyre translation
    if(count1==0){

        if(gfPosX<30)
            gfPosX=-1000;
    }
    glBegin(GL_POLYGON);
    glColor3f(0,0,0);
    //Plane's tyre
    for (angle=1.0f;angle<360.0f;angle+=.2)
    {
        x2 =gfPosX +sin(angle)*radius;
        y2 = gfPosY+cos(angle)*radius;
        glVertex2f(x2,y2);
    }
    glEnd();

    if(gfPosX1==500)
    {
        gfDeltaY = 1.0;
        gfDeltaY1 = 1.0;

    }
    glBegin(GL_POLYGON);
    glColor3f(10.9,10.9,10.9);
    glVertex2f(gfPosX1,gfPosY1);//1

    glVertex2f(gfPosX1+20,gfPosY1+10);//2
    // plane white circle
    //3
    glVertex2f(gfPosX1+35,gfPosY1+22);
    //4
    glVertex2f(gfPosX1+55,gfPosY1+20);
    //5
    glVertex2f(gfPosX1+95,gfPosY1+12);
    //6
    glVertex2f(gfPosX1+125,gfPosY1);
    //7
    glVertex2f(gfPosX1+105,gfPosY1-15);
    //8
    glVertex2f(gfPosX1+70,gfPosY1-28);
    //9
    glVertex2f(gfPosX1+48,gfPosY1-30);
    //10
    glVertex2f(gfPosX1+20,gfPosY1-25);
    //10.1
    glVertex2f(gfPosX1+20,gfPosY1-25);

    //11
    glVertex2f(gfPosX1,gfPosY1-15);
    //white circle ends here
    glVertex2f(gfPosX1-10,gfPosY1-7.5);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0,0.5,0);
    glVertex2f(gfPosX1+95,gfPosY1+12);//5

    glVertex2f(gfPosX1+110,gfPosY1+11);//12

    //13
    glVertex2f(gfPosX1+125,gfPosY1+40);
    //14
    glVertex2f(gfPosX1+140,gfPosY1+40);
    //15
    glVertex2f(gfPosX1+120,gfPosY1);
    glEnd();

    //Window
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_TRIANGLES);
    //16
    glVertex2f(gfPosX1+20,gfPosY1+10);
    //17
    glVertex2f(gfPosX1+35,gfPosY1+20);
    //18
    glVertex2f(gfPosX1+35,gfPosY1+5);

    glEnd();
    glColor3f(0.1,0.1,0.1);
    glBegin(GL_QUADS);
    //19
    glVertex2f(gfPosX1+40,gfPosY1+20);
    //20
    glVertex2f(gfPosX1+55,gfPosY1+17);
    //21
    glVertex2f(gfPosX1+55,gfPosY1+5);
    //22
    glVertex2f(gfPosX1+40,gfPosY1+5);

    //23
    glVertex2f(gfPosX1+60,gfPosY1+15);
    //24
    glVertex2f(gfPosX1+75,gfPosY1+12);
    //25
    glVertex2f(gfPosX1+75,gfPosY1+5);

    //26
    glVertex2f(gfPosX1+60,gfPosY1+5);

    //27
    glVertex2f(gfPosX1+80,gfPosY1+10);
    //28
    glVertex2f(gfPosX1+88,gfPosY1+10);
    //29
    glVertex2f(gfPosX1+88,gfPosY1-4);
    //30
    glVertex2f(gfPosX1+80,gfPosY1-4);

    //wings
    glColor3f(1, 0, 0);

    glVertex2f(gfPosX1+25,gfPosY1-5);
    glVertex2f(gfPosX1+60,gfPosY1-8);
    glVertex2f(gfPosX1+80,gfPosY1-45);
    glVertex2f(gfPosX1+65,gfPosY1-45);

    glEnd();
    //
    //
    glutSwapBuffers();
    if(count1==0)
    {
        gfPosX1 -= gfDeltaX1; //planes coordinate
        gfPosX -= gfDeltaX; //tyre's coordinate

        if(gfPosX1<450&count==0){
            gfPosY1 +=  gfDeltaX;   //planes coordinate
            gfPosY += gfDeltaX; //tyre's coordinate

        }
    }
    if(count1==1) {
        if(gfPosX1<250)

        {
            gfDeltaX1=0;
            gfDeltaX=0;
            scount++;
        }
        gfPosX1-=gfDeltaX1*.5;
        gfDeltaY=2;
        gfPosY=gfPosY1-31;
        gfPosX=gfPosX1+30;
        if(gfPosX1>500){
            gfPosX1 -= gfDeltaX1*.5;
            gfPosY1 -=  gfDeltaX1;
            gfPosY -=   gfDeltaX;
        }
        glFlush();
    }


    if(gfPosX1<450&&count1>0){
        gfDeltaX1=0;
        gfDeltaX=0;

    }

}
/////////for city//////////
void drawhouse1()
{
    int x=0,y=300;
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_QUADS);
    //left corner building of second screen
    glColor3f(0.0,0.0,0.0);
    glVertex2f(x,y);
    glVertex2f(x,y+200);
    glVertex2f(x+70,y+200);
    glVertex2f(x+70,y);

    glColor3f(00,.0,0.0);
    glVertex2f(x+40,y);
    glVertex2f(x+40,y+300);
    glVertex2f(x+100,y+300);
    glVertex2f(x+100,y);

    glColor3f(00,.0,0.0);
    glVertex2f(x+100,y);
    glVertex2f(x+100,y+270);
    glVertex2f(x+150,y+270);
    glVertex2f(x+150,y);
    //end of 1 house


    //2
    //right corner 3 building of second screen
    glBegin(GL_QUADS);
    x=840;
    y=300;
    glColor3f(0.0,0.0,0.0);
    glVertex2f(x,y);
    glVertex2f(x,y+200);
    glVertex2f(x+70,y+200);
    glVertex2f(x+70,y);

    glColor3f(00,.0,0.0);
    glVertex2f(x+40,y);
    glVertex2f(x+40,y+300);
    glVertex2f(x+100,y+300);
    glVertex2f(x+100,y);

    glColor3f(00,.0,0.0);
    glVertex2f(x+100,y);
    glVertex2f(x+100,y+270);
    glVertex2f(x+150,y+270);
    glVertex2f(x+150,y);


    glEnd();
}
//building without windows
void drawbuildings()
{
    int x=300,y=300;
    int x1=310,y1=420,x2=315,y2=540;
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex2f(x,y);
    glVertex2f(x,y+150);
    glVertex2f(x+100,y+150);
    glVertex2f(x+100,y);

    glVertex2f(x1,y1);
    glVertex2f(x1,y1+120);
    glVertex2f(x1+80,y1+120);
    glVertex2f(x1+80,y1);


    glVertex2f(x2,y2);
    glVertex2f(x2,y2+100);
    glVertex2f(x2+70,y2+100);
    glVertex2f(x2+70,y2);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0,0,0);
    int t1=310,t2=640;
    glVertex2f(t1,t2);
    glVertex2f(t1+35,t2+75);
    glVertex2f(t1+80,t2);
    glEnd();



}
void window()
{
    int z=0,x1,y1,x=0,dx,y=0;
    int x4=840,y4=0;
    int k=0;
    glBegin(GL_QUADS);
    glColor3f(1.0,1.0,1.0);


    //3rd from right building window of second screen
    glVertex2f(x4+12,y4+400);
    glVertex2f(x4+12,y4+425);
    glVertex2f(x4+22,y4+425);
    glVertex2f(x4+22,y4+400);


    glVertex2f(x4+11,y4+450);
    glVertex2f(x4+11,y4+475);
    glVertex2f(x4+20,y4+475);
    glVertex2f(x4+20,y4+450);


    glVertex2f(x4+26,y4+450);
    glVertex2f(x4+26,y4+475);
    glVertex2f(x4+36,y4+475);
    glVertex2f(x4+36,y4+450);


    glVertex2f(x4+28,y4+400);
    glVertex2f(x4+28,y4+425);
    glVertex2f(x4+37,y4+425);
    glVertex2f(x4+37,y4+400);


    //completion of 2 bulding window



     while(z<2){
        if(z==1)
        {
            dx=840;

        }
        glBegin(GL_QUADS);
        glColor3f(1.0,1.0,1.0);
        //windows of left building1

        //2
        glVertex2f(x+12,y+400);
        glVertex2f(x+12,y+425);
        glVertex2f(x+22,y+425);
        glVertex2f(x+22,y+400);

        //3
        glVertex2f(x+11,y+450);
        glVertex2f(x+11,y+475);
        glVertex2f(x+20,y+475);
        glVertex2f(x+20,y+450);

        //4
        glVertex2f(x+26,y+450);
        glVertex2f(x+26,y+475);
        glVertex2f(x+36,y+475);
        glVertex2f(x+36,y+450);

        //6
        glVertex2f(x+28,y+400);
        glVertex2f(x+28,y+425);
        glVertex2f(x+37,y+425);
        glVertex2f(x+37,y+400);


        //windows of left building2


        int i=0,y5;
        y5=y;
        x+=50;
        y+=340;
        //second left building windows
        while(i<=16)
        {
            glVertex2f(x,y);
            glVertex2f(x,y+30);
            glVertex2f(x+10,y+30);
            glVertex2f(x+10,y);

            y=y+50;
            if(i<4){
                if(i==3)
                    x=53;
                else
                    x=50;
            }
            if(i==4)
            {
                x=x+840;
                y=y5+350;
            }
            if(i==8)
            {
                x=950;
                y=y5+360;
            }
            if(i==12)
            {x=920;
                y=y5+365;
            }

            i++;

        }
        i=0;
        x1=76;
        y1=370;
        //second column windows of second building from left
        while(i<=3)
        {
            glVertex2f(x1,y1);
            glVertex2f(x1,y1+30);
            glVertex2f(x1+10,y1+30);
            glVertex2f(x1+10,y1);

            y1=y1+50;

            i++;
            if(i==20)
                x1=80;
            else
                x1=76;
        }

        int x2=105,y2=340;
        i=0;
        //3rd left building windows;
        while(i<4)
        {
            glVertex2f(x2,y2);
            glVertex2f(x2,y2+30);
            glVertex2f(x2+10,y2+30);
            glVertex2f(x2+10,y2);

            y2=y2+50;
            i++;
            if(i==1)
                x2=x2+12;
            if(i==2)
                x2=105+15;

            if(i==3)
                x2=105+17;
            if(i==4)
                x2=106+10;



            z++;
        }
        k++;
        x=x+400;
        x1=x1+400;
        x2=x2+400;
        //}
        glEnd();
}

}
void footpath()
{
    //check footpath first upper then lower
    int x=0,y=268,i=0;
    glBegin(GL_QUADS);
    while(x!=1000){
        if(i%2==0)
            glColor3f(0.0,0.0,0.0);
        else
            glColor3f(1.0,1.0,1.0);               //first stripe
        glVertex2f(x,y);

        glVertex2f(x,y+18);
        glVertex2f(x+18,y+18);
        glVertex2f(x+18,y);
        x=x+10;
        i++;
    }
    x=0;
    y=250;
    while(x!=1000){
        if(i%2!=0)
            glColor3f(0.0,0.0,0.0);
        else
            glColor3f(1.0,1.0,1.0);
        glVertex2f(x,y);

        glVertex2f(x,y+18);
        glVertex2f(x+18,y+18);
        glVertex2f(x+18,y);
        x=x+10;
        i++;
    }
    glEnd();
}
void car(int px,int py,float color)
{
    glPointSize(5);
    float angle,x1;
    float x2,y2;
    x1=x+px+5;

    glBegin(GL_POLYGON);
    // car upper body
    glColor3f(0+color,+color,10+color);
    glVertex2f(x+px,y+py);//1
    glVertex2f(x+px,y+10+py);//2
    glVertex2f(x+5+px,y+py+10);//3
    glVertex2f(x+px+8,y+py+15);//4
    glVertex2f(x+px+15,y+py+15);//5
    glVertex2f(x+px+18,y+py+10);//6
    glVertex2f(x+px+23,y+py+10);//7
    glVertex2f(x+px+23,y+py);//8
    glVertex2f(x+px,y+py);//9

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0,0,0);
    // back tyre of car
    for (angle=1.0f;angle<360.0f;angle+=0.2)
    {
        x2 =x1+sin(angle)*radiusC;
        y2 = y+py-1+cos(angle)*radiusC;
        glVertex2f(x2,y2);
    }
    glEnd();
    // rront tyre of car
    glBegin(GL_POLYGON);
    for (angle=1.0f;angle<360.0f;angle+=0.2)
    {
        x2 =x1+12+sin(angle)*radiusC;
        y2 = y+py-1+cos(angle)*radiusC;
        glVertex2f(x2,y2);
    }
    glEnd();
    // car moving logic
    x=x+carX;
    if(x>2000)
        x=0;
}
void lamps(int x,int y)
{
    int z,x1,y1;
    glColor3f(0,0,0);
    glBegin(GL_QUADS);
    glVertex2f(x,y);
    glVertex2f(x,y+100);
    glVertex2f(x+5,y+100);
    glVertex2f(x+5,y);
    glColor3f(135.0,210.0,255.0);
    glVertex2f(x,y+100);
    glVertex2f(x-4,y+125);
    glVertex2f(x+9,y+125);
    glVertex2f(x+5,y+100);
    glEnd();
}
void twintower()
{
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    int x=450,x2,y2,y=300,x1=180,y1=300,x3,x4,x5,y3,y4,y5;
    int i=0;
    x3=x+20;
    y3=y+20;

    x5=x1;
    y5=y1;
    //twin right towers
    glColor3f(0.0,0.0,0.0);

    glVertex2f(x,y);
    glVertex2f(x,y+350);
    glVertex2f(x+80,y+350);
    glVertex2f(x+80,y);

    x2=465;
    y2=345;
    glVertex2f(x2,y2);
    glVertex2f(x2,y2+350);
    glVertex2f(x2+50,y2+350);
    glVertex2f(x2+50,y2);

    x2=475;
    y2=385;
    glVertex2f(x2,y2);
    glVertex2f(x2,y2+350);
    glVertex2f(x2+30,y2+350);
    glVertex2f(x2+30,y2);


    x2=482;
    y2=485;
    glVertex2f(x2,y2);
    glVertex2f(x2,y2+350);
    glVertex2f(x2+6,y2+350);
    glVertex2f(x2+6,y2);

    x2=482+6+4;
    y2=550;
    glVertex2f(x2,y2);
    glVertex2f(x2,y2+350);
    glVertex2f(x2+6,y2+350);
    glVertex2f(x2+6,y2);

    //twing left tower
    glVertex2f(x1,y1);
    glVertex2f(x1,y1+400);
    glVertex2f(x1+80,y1+400);
    glVertex2f(x1+80,y1);

    x2=195;
    y2=380;
    glVertex2f(x2,y2);
    glVertex2f(x2,y2+350);
    glVertex2f(x2+50,y2+350);
    glVertex2f(x2+50,y2);

    x2=205;
    y2=420;
    glVertex2f(x2,y2);
    glVertex2f(x2,y2+350);
    glVertex2f(x2+30,y2+350);
    glVertex2f(x2+30,y2);


    x2=222;
    y2=500;
    glVertex2f(x2,y2);
    glVertex2f(x2,y2+430);
    glVertex2f(x2+6,y2+460);
    glVertex2f(x2+6,y2);

    x2=210;
    y2=450;
    glVertex2f(x2,y2);
    glVertex2f(x2,y2+440);
    glVertex2f(x2+6,y2+410);
    glVertex2f(x2+6,y2);

    y3=y3+45;
    y4=y3;
    while(i<=9)
    {
        glBegin(GL_QUADS);
        glColor3f(1,1,1);
        glVertex2f(x3,y3);
        glVertex2f(x3,y3+30);
        glVertex2f(x3+10,y3+30);
        glVertex2f(x3+10,y3);

        y3=y3+50;
        if(i==4)
        {
            x3=500;
            y3=y4+30;
        }
        i++;

    }
    int y6,x6;
    y5=y5+60;
    y6=y5;
    x5=x5+18;
    x6=x5;
    i=0;
    while(i<=12)
    {
        glBegin(GL_QUADS);
        glColor3f(1,1,1);
        glVertex2f(x5,y5);
        glVertex2f(x5,y5+30);
        glVertex2f(x5+10,y5+30);
        glVertex2f(x5+10,y5);

        y5=y5+50;
        if(i==6)
        {
            x5=x6+30;
            y5=y6+30;
        }
        i++;

    }

    glEnd();
}
void road()
{
    //grey part of road
    glBegin(GL_QUADS);
    glColor3f(.5,.5,.5);
    glVertex2f(0,150);
    glVertex2f(0,250);
    glVertex2f(1000,250);
    glVertex2f(1000,150);
    glEnd();
    int xs=0;
    //stripes of road
    for(int i=0;i<35;i++)
    {

        glBegin(GL_QUADS);
        glColor3f(1,1,1);
        glVertex2f(10+xs,280+46-125);
        glVertex2f(10+xs,380-46-125);
        glVertex2f(35+xs,380-46-125);
        glVertex2f(35+xs,280+46-125);
        glEnd();
        xs=xs+40;
    }
}


void Display(void)
{
    int x,y;
    glClearColor(1.0,1.0,0,1);
    glClear(GL_COLOR_BUFFER_BIT);
    //Draw();
    if(rain)
        {
            rainf();
        }
    drawhouse1();
    window();
    footpath();
    drawbuildings();
    twintower();
    road();
    //for lamp post :)
    x=0;
    y=0;
    for(int i=0;i<8;i++){
        lamps(x+270,y+300);
        lamps(x+290,y+300);
        if(i==2)
            x=x+300;
        if(i>2)
            x+=60;

    }
    glFlush();
}
void Initialize() {

    if(gfPosX1<0||count>0)
    {
        if(gfPosX1<0)
        {
            gfPosX1=1000;
            gfPosY1=850;
            count++;
        }
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(1.0, 1.0, 1.0, 1.0);
        switch(count)
        {
            case 1:if(!scount){
                       AIUB();
                   // count++;
                    break;}
            case 2:if(!scount){
                       gfDeltaX1 = 4.0;
                      City();
                //   count++;
                   break;}
            case 3:if(!scount){
                       Mountain();
                   //  count++;
                    break;
                   }
            case 4:if(!scount){
                       Sea();
                   // count++;
                    break;}

            case 5:gfDeltaX1=4.7;
                   if(!scount||lx>780)
                       Airport1();
                   else
                       Final();
                   break;

        }
    }
    else{
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(1.0, 1.0, 0.0, 1.0);
        Airport();
    }
}
void City(){

    glBegin(GL_QUADS);
    glVertex2f(0,0);
    glColor3f(0,0,1);
    glVertex2f(0,1000);
    glColor3f(0,0,1);
    glVertex2f(1000,1000);
    glColor3f(1,0.5,0);
    glVertex2f(1000,0);
    glEnd();
    int x,y;
    glColor3f(1,.6,0);
    sun(850,730);

    drawhouse1();
    window();
    footpath();
    drawbuildings();
    twintower();
    road();

    car(0,10,.1);
    car(175,10,.5);
    car(150+85,10,.6);
    car(400,10,.7);
    car(700,10,5);
    car(100,75,.7);
    car(150,75,.54);
    car(850,75,.12);
    car(750,75,6);
    car(500,75,.56);
    car(0,10,.78);
    car(-175,10,4);
    car(-150-85,10,.45);
    car(-400,10,.70);
    car(-700,10,.20);
    car(-100,75,5);
    car(-150,75,4);
    car(-850,75,47);
    car(-750,75,5);
    car(-500,75,0);

    //for lamp post :)
    x=0;
    y=0;
    for(int i=0;i<8;i++){
        lamps(x+270,y+300);
        lamps(x+290,y+300);
        if(i==2)
            x=x+300;
        if(i>2)
            x+=60;

    }

    glColor3f(1,1,1);
    char *a="Dhaka City";
    glRasterPos2f( 70 , 100 );
    for(int i = 0; a[i] !='\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, a[i]);
    if(clud)
        {
            cloud();
        }
    stars();
    if(rain)
        {
            rainf();
        }
    Plane();

    glFlush();

}
void Airport()
{

    glBegin(GL_QUADS);
    glColor3f(0.36 , 0.25, 0.20);
    glVertex2f(0,0);
    glVertex2f(0,400);
    glVertex2f(1000,400);
    glVertex2f(1000,0);
    glEnd();
    int i;
    glBegin(GL_QUADS);
    glColor3f(1,.5,0);
    glVertex2f(0,400);
    glColor3f(0,0,1);
    glVertex2f(0,1000);
    glColor3f(0,0,1);
    glVertex2f(1000,1000);
    glColor3f(1,0.5,0);
    glVertex2f(1000,400);
    glEnd();
    //runway
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex2f(85-3,280-4);
    glVertex2f(110-3,380+3);
    glVertex2f(1000+3,380+3);
    glVertex2f(1000+3,280-4);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(.752941,.752941,.752941);
    glVertex2f(85,280);
    glVertex2f(110,380);
    glVertex2f(1000,380);
    glVertex2f(1000,280);
    glEnd();

    //stripes
    int xs=0;
    for(i=0;i<35;i++)
    {

        glBegin(GL_QUADS);
        glColor3f(1,1,1);
        glVertex2f(105+xs,280+46);
        glVertex2f(105+xs,380-46);
        glVertex2f(135+xs,380-46);
        glVertex2f(135+xs,280+46);

        glEnd();
        xs=xs+40;
    }

    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex2f(50-3,160-4);
    glVertex2f(75-3,260+3);
    glVertex2f(1000+3,260+3);
    glVertex2f(1000+3,160-4);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(.752941,.752941,.752941);
    glVertex2f(50,160);
    glVertex2f(75,260);
    glVertex2f(1000,260);
    glVertex2f(1000,160);
    glEnd();
    xs=0;
    for(i=0;i<35;i++)
    {

        glBegin(GL_QUADS);
        glColor3f(1,1,1);
        glVertex2f(63+xs,160+46);
        glVertex2f(63+xs,260-46);
        glVertex2f(93+xs,260-46);
        glVertex2f(93+xs,160+46);
        glEnd();
        xs=xs+40;
    }


    // railing in Airport
    glBegin(GL_QUADS);
    glColor3f(.1,.1,.1);
    glVertex2f(400,400);
    glVertex2f(400,500);
    glVertex2f(1000,500);
    glVertex2f(1000,400);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(.1,.5,1);
    glVertex2f(415,415);
    glVertex2f(415,485);
    glVertex2f(1000,485);
    glVertex2f(1000,415);
    glEnd();
    //windows
    int x=0,y=0;
    for( i=0;i<25;i++){
        glBegin(GL_QUADS);
        glColor3f(1,1,1);
        glVertex2f(425+x,415+20);
        glVertex2f(425+x,485-20);
        glVertex2f(435+x,485-20);
        glVertex2f(435+x,415+20);
        glEnd();
        x=x+25;
        if(x>6)
            x=x+10;
    }

    glColor3f(1,.6,0);
    sun(900,900);
    if(clud)
        {
            cloud();
        }
    //tower control
    glBegin(GL_QUADS);
    glColor3f(.1,.1,.2);
    glVertex2f(250,400);
    glVertex2f(250,600);
    glVertex2f(275,600);
    glVertex2f(275,400);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(.1,.1,.2);
    glVertex2f(225+15,600);
    glVertex2f(225+15,630);
    glVertex2f(300-15,630);
    glVertex2f(300-15,600);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0,.1,1);
    glVertex2f(225+15,607);
    glVertex2f(225+15,613);
    glVertex2f(300-15,613);
    glVertex2f(300-15,607);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(.1,.1,.2);
    glVertex2f(250+8,630);
    glVertex2f(250+8,670);
    glVertex2f(275-8,670);
    glVertex2f(275-8,630);
    glEnd();

    glColor3f(1,1,1);
    char *a="Shah Jalal International Airport,Bangladesh";
    glRasterPos2f( 70 , 100 );
    for(int i = 0; a[i] !='\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, a[i]);

    stars();
    if(rain)
        {
            rainf();
        }

    Plane();

    glFlush();

}

void Airport1()
{
    if(count1==0)
        count1++;

    int i;

    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex2f(0,400);
    glColor3f(0,0,0);
    glVertex2f(0,1000);
    glColor3f(0,0,0);
    glVertex2f(1000,1000);
    glColor3f(0,0,0);
    glVertex2f(1000,400);
    glEnd();

    glColor3f(.8,.9,.91);
    sun(200,850);
    glBegin(GL_QUADS);
    glColor3f(0,0,.5);
    glVertex2f(0,0);
    glVertex2f(0,400);
    glVertex2f(1000,400);
    glVertex2f(1000,0);
    glEnd();

    //runway
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex2f(85-3,280-4);
    glVertex2f(110-3,380+3);
    glVertex2f(1000+3,380+3);
    glVertex2f(1000+3,280-4);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(.752941,.752941,.752941);
    glVertex2f(85,280);
    glVertex2f(110,380);
    glVertex2f(1000,380);
    glVertex2f(1000,280);
    glEnd();

    //stripes
    int xs=0;
    for(i=0;i<35;i++)
    {

        glBegin(GL_QUADS);
        glColor3f(1,1,1);
        glVertex2f(105+xs,280+46);
        glVertex2f(105+xs,380-46);
        glVertex2f(135+xs,380-46);
        glVertex2f(135+xs,280+46);
        glEnd();
        xs=xs+40;
    }

    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex2f(50-3,160-4);
    glVertex2f(75-3,260+3);
    glVertex2f(1000+3,260+3);
    glVertex2f(1000+3,160-4);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(.752941,.752941,.752941);
    glVertex2f(50,160);
    glVertex2f(75,260);
    glVertex2f(1000,260);
    glVertex2f(1000,160);
    glEnd();
    xs=0;
    for(i=0;i<35;i++)
    {

        glBegin(GL_QUADS);
        glColor3f(1,1,1);
        glVertex2f(63+xs,160+46);
        glVertex2f(63+xs,260-46);
        glVertex2f(93+xs,260-46);
        glVertex2f(93+xs,160+46);
        glEnd();
        xs=xs+40;
    }



    glBegin(GL_QUADS);
    glColor3f(.1,.1,.1);
    glVertex2f(400,400);
    glVertex2f(400,500);
    glVertex2f(1000,500);
    glVertex2f(1000,400);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(.1,.5,1);
    glVertex2f(415,415);
    glVertex2f(415,485);
    glVertex2f(1000,485);
    glVertex2f(1000,415);
    glEnd();
    //windows
    int x=0,y=0;
    for( i=0;i<25;i++){
        glBegin(GL_QUADS);
        glColor3f(1,1,1);
        glVertex2f(425+x,415+20);
        glVertex2f(425+x,485-20);
        glVertex2f(435+x,485-20);
        glVertex2f(435+x,415+20);
        glEnd();
        x=x+25;
        if(x>6)
            x=x+10;
    }




    //tower control
    glBegin(GL_QUADS);
    glColor3f(.8,.8,.7);
    glVertex2f(250,400);
    glVertex2f(250,600);
    glVertex2f(275,600);
    glVertex2f(275,400);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(.8,.8,.7);
    glVertex2f(225+15,600);
    glVertex2f(225+15,630);
    glVertex2f(300-15,630);
    glVertex2f(300-15,600);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0,.1,1);
    glVertex2f(225+15,607);
    glVertex2f(225+15,613);
    glVertex2f(300-15,613);
    glVertex2f(300-15,607);
    glEnd();
    glColor3f(1,1,1);
    glBegin(GL_POINTS);
    glVertex2f(lx,ly-500);
    glEnd();
    lx=lx-1;
    glBegin(GL_QUADS);
    glColor3f(.8,.8,.7);
    glVertex2f(250+8,630);
    glVertex2f(250+8,670);
    glVertex2f(275-8,670);
    glVertex2f(275-8,630);
    glEnd();
    stars();
    if(clud)
        {
            cloud();
        }
    if(rain)
        {
            rainf();
        }
    Plane();

    glFlush();


    glColor3f(1,1,1);
    char *a="Cox's Bazar Airport,Bangladesh";
    glRasterPos2f( 70 , 100 );
    for(int i = 0; a[i] !='\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, a[i]);

    glFlush();


}
void Sea(){

    //background of sea
  glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex2f(0,0);
    glColor3f(0,0,.8);
    glVertex2f(0,1000);
    glColor3f(0,0,.8);
    glVertex2f(1000,1000);
    glColor3f(1,1,1);
    glVertex2f(1000,0);

    glEnd();
    glColor3f(.91,.2,0);
    sun(400,410);
    if(clud)
        {
            cloud();
        }

    float angle,x2,y2;
    float radius=100;
    // color of water

    glBegin(GL_QUADS);
    glVertex2f(0,0);
    glVertex2f(0,400);
    glVertex2f(1000,400);
    glVertex2f(1000,0);

    glEnd();

    // boat from here
    glBegin(GL_QUADS);

    glColor3f(0.10,0.55,1.00);
    glVertex2f(0,0);
    glVertex2f(0,400);
    glVertex2f(1000,400);
    glVertex2f(1000,0);

    glEnd();

    glBegin(GL_QUADS);

    glColor3f(0,0,0);
    glVertex2f(sx,sy);
    glVertex2f(sx-20,sy+50);
    glVertex2f(sx+80,sy+50);
    glVertex2f(sx+60,sy);

    glEnd();

    glBegin(GL_TRIANGLES);

    glColor3f(0,0,0.819608);

    glVertex2f(sx+35,sy+50);
    glVertex2f(sx+35,sy+135);
    glVertex2f(sx+75,sy+50);
    glEnd();
   //boat ends here

    stars();
    Plane();
    sx=sx-1;

    glColor3f(1,1,1);
    char *a="Cox's Bazar";
    glRasterPos2f( 70 , 100 );
    for(int i = 0; a[i] !='\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, a[i]);

     if(rain)
        {
            rainf();
        }

    glFlush();


}
void Mountain() {
    // Mountain background gradient
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex2f(0,0);
    glColor3f(0,0,.8);
    glVertex2f(0,1000);
    glColor3f(0,0,.8);
    glVertex2f(1000,1000);
    glColor3f(1,1,1);
    glVertex2f(1000,0);
    glEnd();

    glColor3f(1,.6,0);
    sun(350,700);
    if(clud)
        {
            cloud();
        }
    //Mountains
    glBegin(GL_POLYGON);
    glColor3f(0.36 , 0.25, 0.20);
    glVertex2f(0,0);
    glVertex2f(0,300);
    glVertex2f(100,500);
    glVertex2f(240,600);
    glVertex2f(400,550);
    glVertex2f(550,880);
    glVertex2f(770,650);
    glVertex2f(900,900);
    glVertex2f(1000,800);
    glVertex2f(1000,0);
    glEnd();
    GLfloat x=100,y=-100;

    glColor3f(1,1,1);
    char *a="Chattagram hill-tracks";
    glRasterPos2f( 70 , 100 );
    for(int i = 0; a[i] !='\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, a[i]);
    if(rain)
        {
            rainf();
        }
    stars();
    Plane();
    glFlush();

}
void stars()
    {
            glPointSize(5.0);
	// Draw a Red 1x1 Square centered at origin
	glBegin(GL_POINTS);              // Each set of 4 vertices form a quad
	glColor3f(1.0f, 1.0f, 1.0f); // Red
	glVertex2f(550.0f, 915.0f);    // x, y

	glEnd();


	glPointSize(6.0);
	// Draw a Red 1x1 Square centered at origin
	glBegin(GL_POINTS);              // Each set of 4 vertices form a quad
	glColor3f(1.0f, 1.0f, 1.0f); // Red
	glVertex2f(600.0f, 900.0f);    // x, y

	glEnd();

	glPointSize(5.0);
	// Draw a Red 1x1 Square centered at origin
	glBegin(GL_POINTS);              // Each set of 4 vertices form a quad
	glColor3f(1.0f, 1.0f, 1.0f); // Red
	glVertex2f(400.0f, 950.0f);    // x, y


	glPointSize(5.5);
	// Draw a Red 1x1 Square centered at origin
	glBegin(GL_POINTS);              // Each set of 4 vertices form a quad
	glColor3f(1.0f, 1.0f, 1.0f); // Red
	glVertex2f(100.0f, 950.0f);    // x, y

	glPointSize(5.5);
	// Draw a Red 1x1 Square centered at origin
	glBegin(GL_POINTS);              // Each set of 4 vertices form a quad
	glColor3f(1.0f, 1.0f, 1.0f); // Red
	glVertex2f(150.0f, 850.0f);    // x, y

	glEnd();


	glPointSize(4.0);
	// Draw a Red 1x1 Square centered at origin
	glBegin(GL_POINTS);              // Each set of 4 vertices form a quad
	glColor3f(1.0f, 1.0f, 1.0f); // Red
	glVertex2f(650.0f, 800.0f);    // x, y

	glEnd();


	glPointSize(3.0);
	// Draw a Red 1x1 Square centered at origin
	glBegin(GL_POINTS);              // Each set of 4 vertices form a quad
	glColor3f(1.0f, 1.0f, 1.0f); // Red
	glVertex2f(900.0f, 700.0f);    // x, y

	glEnd();

	glPointSize(4.5);
	// Draw a Red 1x1 Square centered at origin
	glBegin(GL_POINTS);              // Each set of 4 vertices form a quad
	glColor3f(1.0f, 1.0f, 1.0f); // Red
	glVertex2f(850.0f, 900.0f);    // x, y

	glEnd();

    }

void sun(GLfloat x,GLfloat Y)
{
    float radius=50,angle,x2,y2;
    glBegin(GL_POLYGON);
    for (angle=1.0f;angle<360.0f;angle+=0.2)
    {
        x2 = x+sin(angle)*radius;
        y2 = Y+cos(angle)*radius;
        glVertex2f(x2,y2);
    }
    glEnd();
}
void Final()
{
    glBegin(GL_QUADS);
    glColor3f(1,0,0);
    glVertex2f(0,0);
    glColor3f(.4,0,0);
    glVertex2f(0,1000);
    glColor3f(.7,0,0);
    glVertex2f(1000,1000);
    glColor3f(.4,0,0);
    glVertex2f(1000,0);
    glEnd();



    if(nl<150)
    {
        glColor3f(1,1,1);
        char *a="BANGABONDHU AIRWAYS";
        glRasterPos2f(420,700);
        for(int i = 0; a[i] !='\0'; i++)
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, a[i]);
        char *b="Press (Q) for Exit";
        glRasterPos2f(440,200);
        for(int i = 0; b[i] !='\0'; i++)
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, b[i]);
    }
    glFlush();
}


void keys(unsigned char key,int x,int y)
{

    if(key=='s'||key=='S'){
        glutDisplayFunc(Initialize);
    }
    else if(key=='r'||key=='R')
    {
        rain=true;
        clud=true;
    }
    else if(key=='e'||key=='E')
    {
        rain=false;
        clud=false;
    }
	else if(key=='q'||key=='Q')
        exit(0);
}

float w = 0;
void myinit(void)
{
    w > .3 ? w = 0:w += .001;
    glClearColor(1.0,1.0,1.0,1.0);
    glColor3f(0.62352 +w , 0.372549 + w, 0.623529);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluOrtho2D(0,1000.0,0.0,1000.0);
    glBegin(GL_QUADS);
    glColor3f(0.62352 + w , 0.372549 + w , 0.623529+ w);
    glVertex2f(0,0);
    glColor3f(0.4+w,0.0+w,0+w);
    glVertex2f(0,1000);
    glColor3f(0.7+w,0.0+w,0+w);
    glVertex2f(1000,1000);
    glColor3f(0.4+w,0.0+w,0+w);
    glVertex2f(1000,0);
    glEnd();

    glColor3f(1.0 +w, 1.0+w, 1.0+w);
    char *a="Press (S) for Plane start";
    glRasterPos2f( 100 , 200 );
    for(int i = 0; a[i] !='\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, a[i]);

    glColor3f(1.0 +w, 1.0+w, 1.0+w);
    char *n="Press (R) for Rain ";
    glRasterPos2f( 450 , 200 );
    for(int i = 0; n[i] !='\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, n[i]);

    glColor3f(1.0 +w, 1.0+w, 1.0+w);
    char *l="Press (E) for Stop Rain ";
    glRasterPos2f( 450 , 150 );
    for(int i = 0; l[i] !='\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, l[i]);

    glColor3f(1.0 +w, 1.0+w, 1.0+w);
    char *b="Press (Q) for Exit";
    glRasterPos2f(800,200);
    for(int i = 0; b[i] !='\0'; i++)
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, b[i]);



    glColor3f(1.0 +w, 1.0+w, 1.0+w);
    char *G="COMPUTER GRAPHICS [C]";
    glRasterPos2f( 400 , 900 );
    for(int i = 0; G[i] !='\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, G[i]);


    glColor3f(1.0 +w, 1.0+w, 1.0+w);
    char *D="HAQUE, MD ASHIQUL (17-33578-1)";
    glRasterPos2f( 370 , 550 );
    for(int i = 0; D[i] !='\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, D[i]);

    glColor3f(1.0 +w, 1.0+w, 1.0+w);
    char *A="MUNEM, MOHAMMAD AFZAR ALL (17-33469-1)";
    glRasterPos2f( 370 , 600 );
    for(int i = 0; A[i] !='\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, A[i]);

    glColor3f(1.0 +w, 1.0+w, 1.0+w);
    char *C="FAISAL, MD SAJID BIN- (17-33596-1)";
    glRasterPos2f( 370 , 650 );
    for(int i = 0; C[i] !='\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, C[i]);

    glColor3f(1.0 +w, 1.0+w, 1.0+w);
    char *F="ANNA, MD. AOLAD HOSSAIN (17-33513-1)";
    glRasterPos2f( 370 , 700 );
    for(int i = 0; F[i] !='\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, F[i]);

    glFlush();

}
int main(int argc, char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(1920,1080);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Aero-plane takeoff and landing");
    glutDisplayFunc(myinit);
    glutKeyboardFunc(keys);
    Timer(1);
    glutMainLoop();
    return 0;
}
