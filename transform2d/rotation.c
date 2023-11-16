#include <GL/glut.h>
#include <math.h>
#include <stdio.h>

#include "common.h"

#define VEC2F struct vec2f

VEC2F points[3] = {{10, 10}, {30, 10}, {10, 30}};
float angle = 0;

VEC2F rotation(VEC2F v, VEC2F pivot, float degree) {
  float rad = degree * M_PI / 180.0f;

  float x = pivot.x + (v.x - pivot.x) * cosf(rad) - (v.y - pivot.y) * sinf(rad);
  float y = pivot.y + (v.x - pivot.x) * sinf(rad) + (v.y - pivot.y) * cosf(rad); 

  VEC2F result = vec2f_init(x, y);

  return result;
}

void make_rotation() {
  VEC2F pivot = vec2f_init(10, 10);

  glPointSize(10.0f);

  glBegin(GL_LINE_LOOP);
  for (int i = 0; i < 3; i++) {
    glVertex2f(points[i].x, points[i].y);
  }
  glEnd();

  glBegin(GL_LINE_LOOP);
  for (int i = 0; i < 3; i++) {
    VEC2F result = rotation(points[i], pivot, angle);

    glVertex2f(result.x, result.y);
  }
  glEnd();
}

void init() {
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0, 100, 0, 100);
  glMatrixMode(GL_MODELVIEW);
}

void display() {
  glClear(GL_COLOR_BUFFER_BIT);
  glLoadIdentity();

  make_rotation();

  glutSwapBuffers();
}

void timer(int msec) {
  if (angle <= 30) {
    angle += 0.1f;
  }

  glutPostRedisplay();
  glutTimerFunc(1, timer, 0);
}

int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

  glutInitWindowPosition(200, 100);
  glutInitWindowSize(500, 500);

  glutCreateWindow("Rotation");

  glutDisplayFunc(display);
  glutTimerFunc(0, timer, 0);

  init();

  glutMainLoop();

  return 0;
}
