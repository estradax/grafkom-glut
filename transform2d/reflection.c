#include <stdio.h>
#include <GL/glut.h>

#include "common.h"

#define POINTS_LENGTH 3
struct vec2f points[POINTS_LENGTH] = {{1.0f, 2.0f}, {3.0f, -1.0f}, {-4.0f, -6.0f}};

#define MX_LENGTH 2
struct vec2f m_x[MX_LENGTH] = {{1.0f, 0.0f}, {0.0f, -1.0f}};


void make_reflection() {
  struct vec2f result[3] = {0};
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 2; j++) {
      result[i].x += points[i].x * m_x[j].x;
      result[i].y += points[i].y * m_x[j].y;
    }
  }
  for (int i = 0; i < 3; i++) {
    printf("%f, %f\n", result[i].x, result[i].y);
  }

  glPointSize(10.0f);

  glBegin(GL_LINE_LOOP);
  for (int i = 0; i < POINTS_LENGTH; i++) {
    glVertex2f(points[i].x, points[i].y);
  }
  glEnd();

  glBegin(GL_LINE_LOOP);
  for (int i = 0; i < 3; i++) {
    glVertex2f(result[i].x, result[i].y);
  }
  glEnd();
}

void init() {
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(-10, 10, -10, 10);
  glMatrixMode(GL_MODELVIEW);
}

void display() {
  glClear(GL_COLOR_BUFFER_BIT);
  glLoadIdentity();

  make_reflection();

  glutSwapBuffers();
}

int main(int argc, char  **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

  glutInitWindowPosition(200, 100);
  glutInitWindowSize(500, 500);

  glutCreateWindow("Reflection");

  glutDisplayFunc(display);

  init();

  glutMainLoop();
}
