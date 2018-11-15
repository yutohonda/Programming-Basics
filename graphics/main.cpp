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

double getTime();      // 開始時からの経過時間を秒単位で取得する関数
double mousePosX = 0;  // マウスカーソル位置X
double mousePosY = 0;  // マウスカーソル位置Y
unsigned char key = 0; // キーボードからの入力値
void predisplay();     // 描画開始時に必ず呼ぶ関数
void postdisplay();    // 描画終了時に必ず呼ぶ関数

////////////////////////////////////////////////////////////////////////////////

void display()
{
    predisplay(); // 描画開始時に必ず呼ぶ関数。消してはならない

    /***** 以降を編集する *****/

    if (key == 'q' || key == 'Q')
    {
        exit(0);
    }

    double time = getTime(); // 経過時間を秒単位で取得

    // 画面を横切る線
    glPushMatrix();
    //
    // 引数に線の太さを指定（浮動小数）
    glLineWidth(1.0);
    // 線の色：4次元配列の先頭から[Red, Green, Blue, Alpha] を指定。Alphaは透明度
    float lineColor[4] = { 1.0, 1.0, 1.0, 1.0 }; 
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, lineColor);
    // 線の描画
    glBegin(GL_LINES);        // 線描はじめ
    glVertex3d(-100.0, 0, 0); // 始端 [x, y, z]
    glVertex3d(100.0, 0, 0);  // 終端 [x, y, z]
    glEnd();                  // 線描おわり
    //
    glPopMatrix();

    // マウスカーソルについてくるティーポット
    glPushMatrix();
    //
    // ティーポットの位置指定 [x, y, z]
    glTranslatef(mousePosX, mousePosY, 2);
    // ティーポットの回転 [回転角度(degree), 回転軸x, 回転軸y, 回転軸z]
    glRotatef(time * 60.0f, 0, 0, 1.0f);
    // ティーポットの色
    float color1[4] = { 1.0, 0.5, 0.5, 1.0 };
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, color1);
    // ティーポットの描画。引数には大きさを指定
    glutSolidTeapot(10.0);
    //
    glPopMatrix();

    // 画面を横方向に往復しているティーポット（同上）
    glPushMatrix();
    //
    double px = 80.0 * sin(time * 2.0);
    glTranslatef(px, 0, 0);
    float color2[4] = { 0.5, 0.5, 1.0, 0.5 };
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, color2);
    glutSolidTeapot(10.0);
    //
    glPopMatrix();

    /***** ここまで編集する *****/

    postdisplay(); // 描画終了時に必ず呼ぶ関数。消してはならない
}

////////////////////////////////////////////////////////////////////////////////

#pragma region not have to edit
void predisplay()
{
    // 背景色の設定
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // 背景色 [Red, Green, Blue, Alpha] Alphaは1.0固定
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    // カメラの設定
    gluLookAt(0, 0, 130.0,  // カメラの中心位置 [x, y, z]
              0, 0, 0,      // カメラが注視する位置 [x, y, z]
              0, 1.0, 0.0); // [0, 1, 0] で固定（google: CG y-up）
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

static double startTime;
static double prevTime;
double getTime()
{
#ifdef WIN32
    LARGE_INTEGER freq, t;
    QueryPerformanceFrequency(&freq);
    QueryPerformanceCounter(&t);
    return (double)t.QuadPart / freq.QuadPart - startTime;
#else
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return ts.tv_sec + ts.tv_nsec / 1.0e9 - startTime;
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
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);

#ifdef WIN32
    LARGE_INTEGER freq, t;
    QueryPerformanceFrequency(&freq);
    QueryPerformanceCounter(&t);
    startTime = (double)t.QuadPart / freq.QuadPart;
#else
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    startTime = ts.tv_sec + ts.tv_nsec / 1.0e9;
#endif
    prevTime = getTime();
    glutMainLoop();
    return 0;
}
#pragma endregion