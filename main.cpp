/*
 * GLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

int phyWidth= 550;
int phyHeight= 550;
int logWidth=100;
int logHeight=100;
int centerX=logWidth/2;
int centerY=logHeight/2;
int sqWid= 20;
int alphaX=0;
int alphaY=0;
int Bigsquare[4]; // (x-bottom-left,y-bottom-left,x-top-right,y-top-right)
int smsquare1[8] = {80,70,90,70,90,80,80,80}; //(x1,y1,x2,y2,x3,y3,x4,y4)
int smsquare2[8] = {30,20,40,20,40,30,30,30}; //(x1,y1,x2,y2,x3,y3,x4,y4)
int smsquare3[8] = {30,70,40,70,40,80,30,80}; //(x1,y1,x2,y2,x3,y3,x4,y4)
int smsquare4[8] = {60,25,70,25,70,35,60,35}; //(x1,y1,x2,y2,x3,y3,x4,y4)
int smsquare5[8] = {85,10,95,10,95,20,85,20}; //(x1,y1,x2,y2,x3,y3,x4,y4)
int flags[5] = {1,1,1,1,1}; // if 0 then don't display...
int checkflags[5] = {1,1,1,1,1};
int score=0;
void init() {
    glClearColor(0.0, 0.0, 1.0, 1.0);
    glMatrixMode( GL_PROJECTION);
    gluOrtho2D( 0.0, logWidth, 0.0, logHeight);
    }
void printSome(char *str,int x,int y) {
    glColor3f (1.0,1.0,1.0);
    glRasterPos2d(x,y);
    for (int i=0;i<strlen(str);i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,str[i]);
    glFlush();
    }
void Display() {
    glClear( GL_COLOR_BUFFER_BIT);
       Bigsquare[0] =  centerX-sqWid/2 + alphaX;
       Bigsquare[1] =  centerY-sqWid/2 + alphaY;
       Bigsquare[2] =  centerX+sqWid/2 + alphaX;
       Bigsquare[3] =  centerY+sqWid/2 + alphaY;
//------------------------square1----------------------------------------------------
    glColor3f(0.894, 0.505, 0.996);
    if(Bigsquare[0]<=smsquare1[0] && Bigsquare[1]<=smsquare1[1] &&Bigsquare[2]>=smsquare1[4] && Bigsquare[3]>=smsquare1[5])
        {
          flags[0]=0;
        }
    if(flags[0]==1){
        glBegin(GL_QUADS);
           glVertex2f(smsquare1[0], smsquare1[1]);
           glVertex2f(smsquare1[2], smsquare1[3]);
           glVertex2f(smsquare1[4], smsquare1[5]);
           glVertex2f(smsquare1[6], smsquare1[7]);
        glEnd();
    }
//------------------------square2---------------------------------------------------
    if(Bigsquare[0]<=smsquare2[0] && Bigsquare[1]<=smsquare2[1] &&Bigsquare[2]>=smsquare2[4] && Bigsquare[3]>=smsquare2[5])
        {
          flags[1]=0;
        }
    if(flags[1]==1){
         glBegin(GL_QUADS);
           glVertex2f(smsquare2[0], smsquare2[1]);
           glVertex2f(smsquare2[2], smsquare2[3]);
           glVertex2f(smsquare2[4], smsquare2[5]);
           glVertex2f(smsquare2[6], smsquare2[7]);
        glEnd();
    }
//-------------------------square3--------------------------------------------------
    if(Bigsquare[0]<=smsquare3[0] && Bigsquare[1]<=smsquare3[1] &&Bigsquare[2]>=smsquare3[4] && Bigsquare[3]>=smsquare3[5])
        {
          flags[2]=0;
        }
    if(flags[2]==1){
        glBegin(GL_QUADS);
           glVertex2f(smsquare3[0], smsquare3[1]);
           glVertex2f(smsquare3[2], smsquare3[3]);
           glVertex2f(smsquare3[4], smsquare3[5]);
           glVertex2f(smsquare3[6], smsquare3[7]);
        glEnd();
    }
//-------------------------square4--------------------------------------------------
    if(Bigsquare[0]<=smsquare4[0] && Bigsquare[1]<=smsquare4[1] &&Bigsquare[2]>=smsquare4[4] && Bigsquare[3]>=smsquare4[5])
        {
          flags[3]=0;
        }
    if(flags[3]==1){
        glBegin(GL_QUADS);
           glVertex2f(smsquare4[0], smsquare4[1]);
           glVertex2f(smsquare4[2], smsquare4[3]);
           glVertex2f(smsquare4[4], smsquare4[5]);
           glVertex2f(smsquare4[6], smsquare4[7]);
        glEnd();
    }
//-------------------------square5---------------------------------------------------
    if(Bigsquare[0]<=smsquare5[0] && Bigsquare[1]<=smsquare5[1] &&Bigsquare[2]>=smsquare5[4] && Bigsquare[3]>=smsquare5[5])
        {
          flags[4]=0;
        }
    if(flags[4]==1){
          glBegin(GL_QUADS);
           glVertex2f(smsquare5[0], smsquare5[1]);
           glVertex2f(smsquare5[2], smsquare5[3]);
           glVertex2f(smsquare5[4], smsquare5[5]);
           glVertex2f(smsquare5[6], smsquare5[7]);
        glEnd();
    }
//--------------------------BigSquare--------------------------------------------------
     glColor3f(1.0,1.0,1.0);
    glBegin(GL_QUADS);
       glVertex2f(Bigsquare[0], Bigsquare[1]);
       glVertex2f(centerX+sqWid/2 + alphaX, centerY-sqWid/2 + alphaY);
       glVertex2f(Bigsquare[2], Bigsquare[3]);
       glVertex2f(centerX-sqWid/2 + alphaX, centerY+sqWid/2 + alphaY);
    glEnd();
//---------------------------Score-Display----------------------------------------------
 for(int count=0;count<=4;count++){
        if(flags[count]==0 && checkflags[count]==1){
            score++;
            checkflags[count]=0;
            }
        }

    if(score==0){
        printSome("Score:0",5,95);
    }
    if(score==1){
        printSome("Score:1",5,95);
    }
    if(score==2){
        printSome("Score:2",5,95);
    }
    if(score==3){
        printSome("Score:3",5,95);
    }
    if(score==4){
        printSome("Score:4",5,95);
    }
    if(score==5){
        printSome("Score:5",5,95);
    }

    glutSwapBuffers();
    glFlush();
    }

void Keyboard(unsigned char key, int x, int y) {
    if(key=='w')
        alphaY+=5;
    if(key=='s')
        alphaY-=5;
    if(key=='a')
        alphaX-=5;
    if(key=='d')
        alphaX+=5;
    glutPostRedisplay();
    }
void specialKeyboard(int key, int x, int y) {
    if(key==GLUT_KEY_UP)
        alphaY+=5;
    if(key== GLUT_KEY_DOWN)
        alphaY-=5;
    if(key== GLUT_KEY_LEFT)
        alphaX-=5;
    if(key== GLUT_KEY_RIGHT)
        alphaX+=5;
        glutPostRedisplay();
        }


int main( int argc, char ** argv) {
glutInit( &argc, argv);
glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGB);
glutInitWindowPosition( 100, 100);
glutInitWindowSize( phyWidth, phyHeight);
glutCreateWindow( "Game1");
init();
glutDisplayFunc(Display);
glutKeyboardFunc(Keyboard);
glutSpecialFunc(specialKeyboard);
glutMainLoop(); }
