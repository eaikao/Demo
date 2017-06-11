/*************************************************************************
    > File Name: test.c
    > Author: eaikao
    > Mail: 279712302@qq.com 
    > Created Time: 2017年06月11日 星期日 14时59分26秒
 ************************************************************************/

#include <stdio.h>
#include <GL/glut.h>

void init()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glOrtho(-5, 5, -5, 5, 5 ,15);
	glMatrixMode(GL_MODELVIEW);
	gluLookAt(0, 0, 10, 0, 0, 0, 0, 1, 0);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0, 0);
	glutWireTeapot(3);
	glFlush();

}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(300,300);
	glutCreateWindow("OpenGL #D View");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
