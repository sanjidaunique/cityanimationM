#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <iostream>
#include<math.h>
using namespace std;
bool isDay = true;

/// #############  Circle  #############
void circle(float centerX, float centerY, float radius)
{
    glBegin(GL_POLYGON);
    for(int i = 0; i < 360; i++)
    {
        float pi = 3.1416;
        float A  = (i*2*pi)/180 ;
        float r  = radius;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x + centerX, y + centerY );
    }
    glEnd();
}

void halfCircle(float centerX, float centerY, float radius)
{
    glBegin(GL_POLYGON);
    for(int i = 0; i <= 180; i++)
    {
        float pi = 3.1416;
        float A  = (i*pi)/180 ;
        float r  = radius;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x + centerX, y + centerY );
    }
    glEnd();
}

/// #############  Sun  #############
float moveSun = 0.0f;
float sunSpeed =0.3f;
float savedSunSpeed = 0.0f;
bool sunPaused = false;

void sun()
{
    if(isDay)
    {
        glPushMatrix();
        glTranslatef(moveSun, 0, 0);
        glColor3f(1,1,0);
        circle(50,650,35);
        glPopMatrix();
    }
}

void updateSun(int value)
{
    if(!sunPaused)
    {
        moveSun += sunSpeed;
        if (moveSun > 1050)
        {
            moveSun = -200;
        }

        glutPostRedisplay();
    }

    glutTimerFunc(16, updateSun, 0);
}

/// ############# Moon #############
float moveMoon = 0;
float moonSpeed =0.3f;
float savedMoonSpeed = 0.0f;
bool moonPaused = false;

void moon()
{
    if(!isDay)
    {
        glPushMatrix();
        glTranslatef(moveMoon, 0, 0);

        glColor3f(1,1,1);
        circle(850,650,40);

        glPopMatrix();
    }
}

void updateMoon(int value)
{
    if(!moonPaused)
    {
        moveMoon -= moonSpeed;
        if (moveMoon < -940)
        {
            moveMoon = 200;
        }

        glutPostRedisplay();
    }
    glutTimerFunc(16, updateMoon, 0);
}

/// #############  SKY  #############
void sky()
{
    glBegin(GL_QUADS);

    if(isDay)
        glColor3f(0.37f, 0.82f, 0.94f);
    else
        glColor3f(0.10f, 0.13f, 0.22f);

    glVertex2f(0,   200);
    glVertex2f(1000,200);
    glVertex2f(1000,700);
    glVertex2f(0,   700);
    glEnd();
}

/// #############  Cloud  #############

float V_moveCloud1 = 0.0f;
float V_cloudSpeed1 =1.0f;
float V_savedCloudSpeed1 = 0.0f;
bool V_cloudPaused1 = false;

float V_moveCloud2 = 0.0f;
float V_cloudSpeed2 =1.0f;
float V_savedCloudSpeed2 = 0.0f;
bool V_cloudPaused2 = false;

float V_moveCloud3 = 0.0f;
float V_cloudSpeed3 =1.0f;
float V_savedCloudSpeed3 = 0.0f;
bool V_cloudPaused3 = false;

float V_moveCloud4 = 0.0f;
float V_cloudSpeed4 =1.0f;
float V_savedCloudSpeed4 = 0.0f;
bool V_cloudPaused4 = false;

void V_cloud1()
{
    glPushMatrix();
    glTranslatef(V_moveCloud1, 0, 0);

    if (isDay)
        glColor3f(1.0f, 1.0f, 1.0f);
    else
        glColor3f(0.75f, 0.75f, 0.75f);

    int x = 200, y = 650, r = 20;
    circle(x,    y, r);
    circle(x-25, y+5, r);
    circle(x+25, y+5, r);
    circle(x-10, y+20, r-3);
    circle(x+10, y+20, r-3);

    glPopMatrix();
}

void V_cloud2()
{
    glPushMatrix();
    glTranslatef(V_moveCloud2, 0, 0);

    if (isDay)
        glColor3f(1.0f, 1.0f, 1.0f);
    else
        glColor3f(0.75f, 0.75f, 0.75f);

    circle(337,640,18);
    circle(365,640,20);
    circle(390,640,18);
    circle(350,632,20);
    circle(375,632,20);
    circle(355,648,20);
    circle(375,648,20);

    glPopMatrix();
}


void V_cloud4()
{
    glPushMatrix();
    glTranslatef(V_moveCloud4, 0, 0);

    if (isDay)
        glColor3f(1.0f, 1.0f, 1.0f);
    else
        glColor3f(0.75f, 0.75f, 0.75f);
    circle(830,640,20);
    circle(860,638,22);
    circle(890,640,20);
    circle(845,652,20);
    circle(870,655,28);

    glPopMatrix();
}

void V_updateCloud1(int value)
{
    if(isDay)
    {
        if(!V_cloudPaused1)
        {
            V_moveCloud1 -= V_cloudSpeed1+1;
            if (V_moveCloud1 < -250)
            {
                V_moveCloud1 = 860;
            }

            glutPostRedisplay();
        }
    }
    else
    {
        if(!V_cloudPaused1)
        {
            V_moveCloud1 += V_cloudSpeed1+1;
            if (V_moveCloud1 >1000)
            {
                V_moveCloud1 = -250;
            }

            glutPostRedisplay();
        }
    }
    glutTimerFunc(16, V_updateCloud1, 0);
}

void V_updateCloud2(int value)
{
    if(!V_cloudPaused2)
    {
        V_moveCloud2 -= V_cloudSpeed2+.3;
        if (V_moveCloud2 < -450)
        {
            V_moveCloud2 = 740;
        }

        glutPostRedisplay();
    }
    glutTimerFunc(9, V_updateCloud2, 0);
}

void V_updateCloud4(int value)
{
    if(isDay)
    {
        if(!V_cloudPaused4)
        {
            V_moveCloud4 -= V_cloudSpeed4+1;
            if (V_moveCloud4 < -900)
            {
                V_moveCloud4 = 250;
            }

            glutPostRedisplay();
        }
    }
    else
    {
        if(!V_cloudPaused4)
        {
            V_moveCloud4 += V_cloudSpeed4+2;
            if (V_moveCloud4 >250)
            {
                V_moveCloud4 = -940;
            }

            glutPostRedisplay();
        }
    }
    glutTimerFunc(16, V_updateCloud4, 0);
}

/// ##############################################################  Garden  ###############################################################
void garden()
{
    //Base
    if (isDay)
        glColor3f(0.0f, 0.5f, 0.0f);
    else
        glColor3f(0.1f, 0.3f, 0.1f);

    glBegin(GL_QUADS);
    glVertex2f(0,180);
    glVertex2f(1000,180);
    glVertex2f(1000,200);
    glVertex2f(0,200);
    glEnd();

}

/// ##############################################################  Road  ###############################################################
void road()
{
    if (isDay)
        glColor3f(.3f, .3f, .3f);
    else
        glColor3f(0.15f, 0.15f, 0.15f);

    //Base Gray Color
    glBegin(GL_QUADS);
    glVertex2f(0,   0);
    glVertex2f(1000,0);
    glVertex2f(1000,40);
    glVertex2f(0,   40);
    glEnd();

    //Base white line
    if (isDay)
        glColor3f(1.0f, 1.0f, 1.0f);
    else
        glColor3f(0.6f, 0.6f, 0.6f);

    glLineWidth(10);
    glBegin(GL_LINES);
    glVertex2f(0,   40);
    glVertex2f(1000,40);
    glEnd();

    //Main Road
    glBegin(GL_QUADS);

    if(isDay)
        glColor3f(0.3f, 0.3f, 0.3f);
    else
        glColor3f(0,0,0);

    glVertex2f(0,   160);
    glVertex2f(1000,160);
    glVertex2f(1000,40);
    glVertex2f(0,   40);
    glEnd();

    //Upper white line of the road
    if (isDay)
        glColor3f(1.0f, 1.0f, 1.0f);
    else
        glColor3f(0.6f, 0.6f, 0.6f);

    glLineWidth(3);
    glBegin(GL_LINES);
    glVertex2f(0,   160);
    glVertex2f(1000,160);
    glEnd();

    //Upper gray color
    if (isDay)
        glColor3f(0.51f, 0.51f, 0.51f);
    else
        glColor3f(0.25f, 0.25f, 0.25f);

    glBegin(GL_QUADS);
    glVertex2f(0,   160);
    glVertex2f(1000,160);
    glVertex2f(1000,173);
    glVertex2f(0,   173);
    glEnd();

    //Road dash line
    if (isDay)
        glColor3f(1.0f, 1.0f, 1.0f);
    else
        glColor3f(0.6f, 0.6f, 0.6f);

    glLineWidth(3);
    glBegin(GL_LINES);
    for(int x = 0; x<1000; x+=60)
    {
        glVertex2f(x,   102);
        glVertex2f(x+30,102);
    }
    glEnd();
}

// ##############################################################  Road Side Wall  ###############################################################
void roadSideWall()
{
    if (isDay)
        glColor3f(0.96f, 0.96f, 0.86f);
    else
        glColor3f(0.42f, 0.22f, 0.13f);

    glBegin(GL_QUADS);
    glVertex2f(0,   170);
    glVertex2f(1000,170);
    glVertex2f(1000,190);
    glVertex2f(0,   190);
    glEnd();

    //Breaks Line
        glColor3f(0.5f, 0.5f, 0.5f);

    glLineWidth(1);
    glBegin(GL_LINES);

    glVertex2f(0,   170);
    glVertex2f(1000,170);

    glVertex2f(0,   175);
    glVertex2f(1000,175);

    glVertex2f(0,   180);
    glVertex2f(1000,180);

    glVertex2f(0,   185);
    glVertex2f(1000,185);

    glVertex2f(0,   190);
    glVertex2f(1000,190);


    glEnd();

}

// ####################################################################### Building ###########################################################
void building()
{
    /// 1st Building
    // Left side
   if (isDay)
        glColor3f(0.4f, 0.4f, 0.4f);
    else
        glColor3f(0.50f, 0.15f, 0.20f);

    glBegin(GL_QUADS);
    glVertex2f(190, 200);
    glVertex2f(235, 200);
    glVertex2f(235, 480);
    glVertex2f(190, 480);

    glVertex2f(235, 200);
    glVertex2f(280, 200);
    glVertex2f(280, 480);
    glVertex2f(235, 480);

    //Top bar
    if (isDay)
        glColor3f(0.50f, 0.15f, 0.20f);
    else
        glColor3f(0.30f, 0.10f, 0.15f);

    glVertex2f(185, 490);
    glVertex2f(285, 490);
    glVertex2f(285, 475);
    glVertex2f(185, 475);

    if (isDay)
        glColor3f(0.50f, 0.15f, 0.20f);
    else
        glColor3f(0.30f, 0.10f, 0.15f);

    for(int y = 410; y>200; y-=70)
    {
        glVertex2f(185, y);
        glVertex2f(285, y);
        glVertex2f(285, y-10);
        glVertex2f(185, y-10);
    }

    glEnd();

    ///     window
    //   white border
    glBegin(GL_QUADS);
    if(isDay)
        glColor3f(1,1,1);
    else
        glColor3f(0.15f, 0.07f, 0.03f);

    for(int x = 198; x < 280; x += 47)
    {
        for(int y=454; y>220; y-=70)
        {
            glVertex2f(x,    y);
            glVertex2f(x+26, y);
            glVertex2f(x+26, y-34);
            glVertex2f(x,    y-34);
        }
    }
    glEnd();

    // blue
    if (isDay)
        glColor3f(0.36f, 0.54f, 0.66f);
    else
        glColor3f(1.0f, 1.0f, 0.5f);

    for(int x = 202; x < 280; x += 47)
    {
        for(int y=450; y>220; y-=70)
        {
            glBegin(GL_QUADS);
            glVertex2f(x,    y);
            glVertex2f(x+18, y);
            glVertex2f(x+18, y-27);
            glVertex2f(x,    y-27);
            glEnd();
        }
    }
}
///*******red car*****
float moveCar = 0.0f;
float carSpeed =1.0f;
float savedCarSpeed = 0.0f;
float carTireAngle = 0.0f;
bool carPaused = false;

void car()
{
    glPushMatrix();
    glTranslatef(moveCar, 0, 0);

    glBegin(GL_POLYGON);
    if (isDay)
        glColor3f(1.0f, 0.0f, 0.0f);
    else
        glColor3f(0.5f, 0.0f, 0.0f);

    glVertex2i(100,125);
    glVertex2i(100,140);
    glVertex2i(105,150);
    glVertex2i(193,150);
    glVertex2i(205,145);
    glVertex2i(205,125);
    glEnd();

    /// Light
    glBegin(GL_QUADS);
    if (isDay)
        glColor3f(1,1,1);
    else
        glColor3f(1,1,.7);
    /// Front light
    glVertex2i(200,128);
    glVertex2i(205,128);
    glVertex2i(205,135);
    glVertex2i(200,135);

    /// Yellow light for night
    if(!isDay)
    {
        glColor3f(1,1,.7);
        glVertex2i(205,128);
        glVertex2i(260,115);
        glVertex2i(260,140);
        glVertex2i(205,135);

    }

    glEnd();

    glBegin(GL_POLYGON);
    if (isDay)
        glColor3f(1.0f, 0.0f, 0.0f);
    else
        glColor3f(0.5f, 0.0f, 0.0f);

    glVertex2i(110,145);
    glVertex2i(121,168);
    glVertex2i(170,168);
    glVertex2i(190,145);

    glEnd();


    glBegin(GL_QUADS);//////////glass///////
    if (isDay)
        glColor3f(0.27f, 0.28f, 0.29f);
    else
        glColor3f(0.15f, 0.07f, 0.03f);
    glVertex2i(123,150);
    glVertex2i(123,162);
    glVertex2i(145,162);
    glVertex2i(145,150);
    glEnd();


    glBegin(GL_QUADS);/////////////////
    if (isDay)
        glColor3f(0.27f, 0.28f, 0.29f);
    else
        glColor3f(1.0f, 1.0f, 0.5f);
    glVertex2i(125,152);
    glVertex2i(125,160);
    glVertex2i(143,160);
    glVertex2i(143,152);
    glEnd();


    glBegin(GL_QUADS);//////////glass///////
    if (isDay)
        glColor3f(0.27f, 0.28f, 0.29f);
    else
        glColor3f(0.15f, 0.07f, 0.03f);

    glVertex2i(152,151);
    glVertex2i(152,162);
    glVertex2i(168,162);
    glVertex2i(177,151);
    glEnd();


    glBegin(GL_QUADS);/////////////////
    if (isDay)
        glColor3f(0.27f, 0.28f, 0.29f);
    else
        glColor3f(1.0f, 1.0f, 0.5f);

    glVertex2i(154,149);
    glVertex2i(154,160);
    glVertex2i(166,160);
    glVertex2i(175,149);
    glEnd();


    //first car chakka//
    if (isDay)
        glColor3f(0.34f, 0.34f, 0.34f);
    else
        glColor3f(0.15f, 0.15f, 0.15f);

    halfCircle(125,125,10);


    if (isDay)
        glColor3f(0.0f, 0.0f, 0.0f);
    else
        glColor3f(0.0f, 0.0f, 0.0f);

    circle(125,125,9);

    if (isDay)
        glColor3f(1.0f, 1.0f, 1.0f);
    else
        glColor3f(0.5f, 0.5f, 0.5f);

    circle(125,125,3);

    if (isDay)
        glColor3f(0.34f, 0.34f, 0.34f);
    else
        glColor3f(0.15f, 0.15f, 0.15f);

    circle(175,125,10);


    if (isDay)
        glColor3f(0.0f, 0.0f, 0.0f);
    else
        glColor3f(0.0f, 0.0f, 0.0f);

    circle(175,125,9);

    if (isDay)
        glColor3f(1.0f, 1.0f, 1.0f);
    else
        glColor3f(0.5f, 0.5f, 0.5f);

    circle(175,125,3);

    glPopMatrix();
}
void updateCar(int value)
{
    if(!carPaused){

         moveCar += carSpeed+1;
    if (moveCar > 900)
    {
        moveCar = -350;
    }

    glutPostRedisplay();
    }

    glutTimerFunc(10, updateCar, 0);
}

void keyboardInput(unsigned char key, int x, int y)
{
    if (key == 'd' || key == 'D')
    {
        isDay = true;
        glutPostRedisplay();
    }

    if(key == 'n' || key == 'N')
    {
        isDay = false;
        glutPostRedisplay();
    }
}
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    sky();
    moon();
    sun();
    V_cloud1();
    V_cloud2();
    V_cloud4();
    building();
    garden();
    road();
    roadSideWall();
    //bus();
    car(); //RED
    //cargoTruck();
    //blueCar();

    glFlush();
    glutSwapBuffers();
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1000, 700);
    glutCreateWindow("City Scene Animation");
    glClearColor(0.37f, 0.82f, 0.94f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glutKeyboardFunc(keyboardInput);
    glLoadIdentity();
    gluOrtho2D(0, 1000, 0, 700);

    glutDisplayFunc(display);

    // Register timers
    glutTimerFunc(0, updateSun, 0);
    glutTimerFunc(0, updateMoon, 0);
    glutTimerFunc(0, V_updateCloud1, 0);
    glutTimerFunc(0, V_updateCloud2, 0);
    glutTimerFunc(0, V_updateCloud4, 0);
    //glutTimerFunc(0, V_updateBus, 0);
    glutTimerFunc(0, updateCar, 0); //RED
    //glutTimerFunc(0, V_updateCargo, 0);
   // glutTimerFunc(0, V_updateBlueCar, 0);

    glutMainLoop();
    return 0;
}
