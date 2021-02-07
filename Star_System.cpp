#include<stdio.h>
#include<stdlib.h>
#include <GL/glut.h>
#include<math.h>
#include<time.h>
#include<windows.h>
#define PI 3.14
float angleEarth=0.0, angleMars=0.0, angleMercury=0.0;
GLfloat sx=0.2,sy=0.2,sz=0.2;
int planet1;
GLfloat black[]={0.0f,0.0f,0.0f,1.0f};
GLfloat yellow[]={0.7f,0.2f,0.0f,1.0f};
GLfloat qAmb[]={0.1,0.1,0.1,1.0};
GLfloat qDif[]={1.0,1.0,1.0,1.0};
GLfloat qSpec[]={.50,.50,.50,.10};
GLfloat qPos[]={0,0,0,0.1};
GLfloat sc[8]={0.295 , 0.40,0.50, 0.60,0.80,1.0,1.05,1.13};
double ang=2*PI/300;
double angular=2*PI/50;
void initLighting()
{
glEnable(GL_LIGHTING);
glEnable(GL_LIGHT7);
glLightfv(GL_LIGHT7,GL_AMBIENT,qAmb);
glLightfv(GL_LIGHT7,GL_DIFFUSE,qDif);
glLightfv(GL_LIGHT7,GL_SPECULAR,qSpec);
}
void myinit()
{
glClearColor(0.0,0.0,0.0,0.0);
glPointSize(1.0);
glLineWidth(2.0);
}
void background()
{
glBegin(GL_QUADS);
glColor3f(0.0,0.00,0.00);
glVertex3f(-01.00,01.00,1);
glColor3f(.20,0.0,0.70);
glVertex3f(01.00,1.00,1);
glColor3f(0,0.0,0.0);
glVertex3f(1.00,-1.00,1);
glColor3f(.70,.10,.20);
glVertex3f(-1.00,-1.00,1);
glEnd();
}
void orbit()
{
glColor3f(0.5,0.5,0.5);
int i=0;
for(i=0;i<4;i++){
glPushMatrix();
if(i==1)
{continue;}
glRotatef(63,1.0,0.0,0.0);
glScalef(sc[i],sc[i],sc[i]);
glBegin(GL_POINTS);
double ang1=0.0;
int i=0;
for(i=0;i<300;i++)
{glVertex2d(cos(ang1),sin(ang1));
ang1+=ang; }
glEnd();
glPopMatrix();
}
}
void draw(void)
{
glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
background();
orbit();
glLoadIdentity();
glPushMatrix();
glEnable(GL_DEPTH_TEST);
glEnable(GL_COLOR_MATERIAL);
glPushMatrix();
glColor3f(0.7,0.5,0.0);
glScalef(sx,sy,sz);
glLightfv(GL_LIGHT7,GL_POSITION,qPos);
glMaterialfv(GL_FRONT_AND_BACK,GL_EMISSION,yellow);
glutSolidSphere(1,50,50);
glMaterialfv(GL_FRONT_AND_BACK,GL_EMISSION,black);
glPopMatrix();
glScalef(0.2,0.2,0.2);
glPushMatrix();
glRotatef(angleMercury,0.0,1.0,-0.5);
glTranslatef(1.5,0.0,0.0);
glColor3f(1.0,0.9,0.0);
glScalef(0.08,0.08,0.08);
glutSolidSphere(1,50,50);
glPopMatrix();
glPushMatrix();
glRotatef(angleEarth,0.0,1.0,-0.5);
glTranslatef(2.5,0.0,0.0);
glColor3f(0.0,0.1,0.7);
glScalef(0.23,0.23,0.23);
glutSolidSphere(1,50,50);
glPopMatrix();//earth made
glPushMatrix();
glRotatef(angleMars,0.0,1.0,-0.5);
glTranslatef(-3.0,0.0,0.0);
glColor3f(0.05,0.05,0.01);
glScalef(0.17,0.17,0.17);
glutSolidSphere(1,50,50);
glPopMatrix();
glPopMatrix();
glFlush();
}
void update(int value){
angleEarth+=0.7;
if(angleEarth>360){
angleEarth-=360;}
angleMercury+=2;
if(angleMercury>360){
angleMercury-=360;}
angleMars+=0.5;
if(angleMars>360){
angleMars-=360;}
glutPostRedisplay();
glutTimerFunc(20,update,0);
}
int main(int argc, char **argv)
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowPosition(0,0);
glutInitWindowSize(600,600);
glutCreateWindow("Solar System");
initLighting();
myinit();
glutDisplayFunc(draw);
glutTimerFunc(25,update,0);
glutMainLoop();
return 0;
}
