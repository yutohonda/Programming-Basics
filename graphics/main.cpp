#include <iostream>
#include <cmath>
#include <ctime>
#ifdef WIN32
#include <windows.h>
#include <gl/GL.h>
#include "GLUT.h"
#else
#include <OpenGL/OpenGL.h>
#include <GLUT/GLUT.h>
#endif

using namespace std;

double getTime();
double mousePosX = 0;
double mousePosY = 0;
unsigned char key = 0;
void predisplay();
void postdisplay();

////////////////////////////////////////////////////////////////////////////////

void display()
{
    predisplay(); // 消してはならない

    if (key == 'q' || key == 'Q')
    {
        exit(0);
    }

    double time = getTime(); // 経過時間を秒単位で取得

    // 画面を横切る線
    glLineWidth(1);
    float lineColor[4] = { 1.0, 1.0, 1.0, 1.0 };
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, lineColor);
    glBegin(GL_LINES);
    glVertex3d(-100.0, 0, 0);
    glVertex3d(100.0, 0, 0);
    glEnd();

    // マウスカーソルについてくるティーポット
    glPushMatrix();
    float color1[4] = { 1.0, 0.5, 0.5, 1.0 };
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, color1);
    glTranslatef(mousePosX, mousePosY, 0);
    glRotatef(time * 60.0f, 0, 0, 1.0f);
    glutSolidTeapot(10.0);
    glPopMatrix();

    // 画面を横方向に往復しているティーポット
    glPushMatrix();
    double px = 80.0 * sin(time * 2.0);
    glTranslatef(px, 0, 0);
    float color2[4] = { 0.5, 0.5, 1.0, 1.0 };
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, color2);
    glutSolidTeapot(10.0);
    glPopMatrix();

    postdisplay(); // 消してはならない
}

////////////////////////////////////////////////////////////////////////////////

void predisplay()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, 0, 130.0,
        0, 0, 0,
        0, 1.0, 0.0);
}

void postdisplay()
{
    glutSwapBuffers();
    key = 0;
}

void keyboard(unsigned char k, int x, int y)
{
    key = k;
}

static double prevTime;
double getTime()
{
#ifdef WIN32
    LARGE_INTEGER freq, t;
    QueryPerformanceFrequency(&freq);
    QueryPerformanceCounter(&t);
    return (double)t.QuadPart / freq.QuadPart;
#else
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    uint64_t absoluteUs =
        return ts.tv_sec + ts.tv_nsec) * 1.0e3;
#endif
}

void idle()
{
    double time = getTime();
    if (time - prevTime > 1.0 / 60.0)
    {
        display();
        prevTime = time;
    }
}

int screenWidth = 1;
int screenHeight = 1;
void resize(int w, int h)
{
    screenWidth = w;
    screenHeight = h;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-100.0, 100.0, -100.0, 100.0, 1.0e-2, 1.0e3);
}

void mouseMotion(int x, int y)
{
    mousePosX = (x - screenWidth / 2) * 200.0 / screenWidth;
    mousePosY = -(y - screenHeight / 2) * 200.0 / screenHeight;
    glutIdleFunc(idle);
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);

    glutInitWindowSize(800, 800);
    glutCreateWindow("graphics");
    
    glutDisplayFunc(display);
    glutIdleFunc(idle);
    glutKeyboardFunc(keyboard);
    glutPassiveMotionFunc(mouseMotion);
    glutReshapeFunc(resize);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    prevTime = getTime();
    glutMainLoop();
    return 0;
}
