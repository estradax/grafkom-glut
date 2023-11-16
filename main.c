#include <stdlib.h>

#include <GL/freeglut_std.h>
#include <GL/gl.h>
#include <GL/glu.h>

void display();
void init();

int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB);

  glutInitWindowPosition(200, 100);
  glutInitWindowSize(500, 500);

  glutCreateWindow("OpenGL freeglut Window");

  glutDisplayFunc(display);

  init();

  glutMainLoop();

  return EXIT_SUCCESS;
}

void init() {
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(10, -10, 10, -10);
  glMatrixMode(GL_MODELVIEW);
}

void display() {
  glClear(GL_COLOR_BUFFER_BIT);
  glLoadIdentity();

  glPointSize(10.0);

  glBegin(GL_POINTS);
  glVertex2f(0, 0);
  glVertex2f(1, 0);
  glEnd();

  glFlush();
}
