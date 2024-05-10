#include<GL/freeglut.h>
#include<GL/glut.h>
#include<iostream>
#include<cmath>
using namespace std;

void init(){
  glClear(GL_COLOR_BUFFER_BIT);
  glClearColor(0,0,0,0);
  glMatrixMode(GL_PROJECTION);
  gluOrtho2D(-500,500,-500,500);
}

void plotpixel(float x, float y){
  glColor3f(1.0,1.0,0.0);
  glBegin(GL_POINTS);
  glVertex2i(x,y);
  glEnd();
  glFlush();
}

void dda(float x1,float y1, float x2, float y2){
  float x,y,dx,dy,xinc,yinc;
  int steps;
  
  dx=x2-x1;
  dy=y2-y1;
  
  steps=(abs(dx)>abs(dy))?abs(dx):abs(dy);
  
  xinc=dx/(float)steps;
  yinc=dy/(float)steps;
  
  x=x1;
  y=y1;
  plotpixel(x,y);
  
  for(int i=0;i<steps;i++){
    x+=xinc;
    y+=yinc;
    plotpixel(x,y);
  }
  glFlush();
}

void render(){
  dda(200,200,200,-200);
  dda(200,-200,-200,-200);
  dda(-200,-200,-200,-160);
  dda(-200,-160,-160,-160);
  dda(-160,-160,-160,-120);
  dda(-160,-120,-120,-120);
  dda(-120,-120,-120,-80);
  dda(-120,-80,-80,-80);
  dda(-80,-80,-80,-40);
  dda(-80,-40,-40,-40);
  dda(-40,-40,-40,0);
  dda(-40,0,0,0);
  dda(0,0,0,40);
  dda(0,40,40,40);
  dda(40,40,40,80);
  dda(40,80,80,80);
  dda(80,80,80,120);
  dda(80,120,120,120);
  dda(120,120,120,160);
  dda(120,160,160,160);
  dda(160,160,160,200);
  dda(160,200,200,200);
}

int main(int argc, char** argv){
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE);
  glutInitWindowSize(800,800);
  glutInitWindowPosition(100,100);
  glutCreateWindow("DDA Staircase");
  init();
  glutDisplayFunc(render);
  glutMainLoop();
  return 0;
}
