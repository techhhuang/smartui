#include <GL/glut.h>

void myDisplay(void)

{
  glClear(GL_COLOR_BUFFER_BIT);

  glViewport(0, 0, 200, 200);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(60, 1, 0, 20);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(0, 0, 1, 0, 0, 0, 1, 1, 0);

  glPolygonMode(GL_FRONT, GL_FILL);  // 设置正面为填充模式

  glPolygonMode(GL_BACK, GL_LINE);  // 设置反面为线形模式

  glFrontFace(GL_CCW);  // 设置逆时针方向为正面

  glBegin(GL_POLYGON);  // 按逆时针绘制一个正方形，在左下方

  glVertex2f(-0.5f, -0.5f);

  glVertex2f(0.0f, -0.5f);

  glVertex2f(0.0f, 0.0f);

  glVertex2f(-0.5f, 0.0f);

  glEnd();

  glBegin(GL_POLYGON);  // 按顺时针绘制一个正方形，在右上方

  glVertex2f(0.0f, 0.0f);

  glVertex2f(0.0f, 0.5f);

  glVertex2f(0.5f, 0.5f);

  glVertex2f(0.5f, 0.0f);

  glEnd();

  glFlush();
}

int main(int argc, char *argv[])

{
  glutInit(&argc, argv);

  glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);

  glutInitWindowPosition(100, 100);

  glutInitWindowSize(600, 600);

  glutCreateWindow("第一个OpenGL程序");

  glutDisplayFunc(&myDisplay);

  glutMainLoop();

  return 0;
}