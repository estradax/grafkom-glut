#include <GL/glut.h>

#include "common.h"

#define POINTS_LENGTH 3
struct vec2f points[POINTS_LENGTH] = {
  {10.0f, 10.0f},
  {30.0f, 10.0f},
  {10.0f, 30.0f}}; 

struct vec2f t = {3.0f, 2.0f};

void make_translated_triangle() {
  glPointSize(10.0f);

  glBegin(GL_POINTS);
  for (int i = 0; i < POINTS_LENGTH; i++) {
    glVertex2f(points[i].x, points[i].y);
  }
  glEnd();

  glBegin(GL_LINE_LOOP);
  for (int i = 0; i < POINTS_LENGTH; i++) {
    glVertex2f(points[i].x, points[i].y);
  }
  glEnd();

  glBegin(GL_POINTS);
  for (int i = 0; i < POINTS_LENGTH; i++) {
    glVertex2f(points[i].x * t.x, points[i].y * t.y);
  }
  glEnd();

  glBegin(GL_LINE_LOOP);
  for (int i = 0; i < POINTS_LENGTH; i++) {
    glVertex2f(points[i].x * t.x, points[i].y * t.y);
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

  make_translated_triangle();

  glutSwapBuffers();
}

void timer(int msec) {
  glutPostRedisplay();
  glutTimerFunc(0, timer, 0);
}

int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

  glutInitWindowPosition(200, 100);
  glutInitWindowSize(500, 500);

  glutCreateWindow("Scale");

  glutDisplayFunc(display);
  glutTimerFunc(0, timer, 0);

  init();

  glutMainLoop();

  return EXIT_SUCCESS;
}
