#include <GL/gl.h>
#include <math.h>

#include <GL/glut.h>
#include <stdio.h>
#include "common.h"

#define POINTS_LENGTH 3
struct vec2f points[POINTS_LENGTH] = {
  {10.0f, 10.0f},
  {30.0f, 10.0f},
  {10.0f, 30.0f}}; 

struct vec2f t = {10.0f, 20.0f};

struct translate h[3];

void make_translated_triangle() {
  glPointSize(10.0f);

  glBegin(GL_POINTS);
  for (int i = 0; i < POINTS_LENGTH; i++) {
    glVertex2f(h[i].point.x, h[i].point.y);
  }
  glEnd();

  glBegin(GL_LINE_LOOP);
  for (int i = 0; i < POINTS_LENGTH; i++) {
    glVertex2f(h[i].point.x, h[i].point.y);
  }
  glEnd();
}

void init() {
  for (int i = 0; i < POINTS_LENGTH; i++) {
    h[i] = translate_init(points[i], vec2f_add(points[i], t));
  }

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
  for (int i = 0; i < POINTS_LENGTH; i++) {
    translate_step(&h[i]);
  }

  glutPostRedisplay();
  glutTimerFunc(10, timer, 0);
}

int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

  glutInitWindowPosition(200, 100);
  glutInitWindowSize(500, 500);

  glutCreateWindow("Translate");

  glutDisplayFunc(display);
  glutTimerFunc(0, timer, 0);

  init();

  glutMainLoop();

  return EXIT_SUCCESS;
}
