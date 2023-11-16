#include <GL/glut.h>

#include "common.h"

#define HS_LENGTH 3
struct vec2f hs[HS_LENGTH] = {{10, 10}, {30, 10}, {10, 30}};

struct translate ss;

void make_scaled_triangle() {
  glPointSize(10.0f);

  glBegin(GL_LINE_LOOP);
  for (int i = 0; i < HS_LENGTH; i++) {
    glVertex2f(hs[i].x * ss.point.x, hs[i].y * ss.point.y);
  }
  glEnd();
}

void init() {
  ss = translate_init(vec2f_init(1, 1), vec2f_init(3, 2));

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0, 100, 0, 100);
  glMatrixMode(GL_MODELVIEW);
}

void display() {
  glClear(GL_COLOR_BUFFER_BIT);
  glLoadIdentity();

  make_scaled_triangle();

  glutSwapBuffers();
}

void timer(int msec) {
  translate_step(&ss);

  glutPostRedisplay();
  glutTimerFunc(1, timer, 0);
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
