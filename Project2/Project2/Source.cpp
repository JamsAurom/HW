#include <iostream>
#include "Header.h"
#include "Display.h"

//#if defined(linux) || defined(_WIN32)
#include <glut.h>    /*Для Linux и Windows*/
#include <math.h>

#define M_PI

using namespace std;

void reshape(int w, int h);


int main(int argc, char * argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); /*Включаем двойную буферизацию и четырехкомпонентный цвет*/

	glutInitWindowSize(800, 800);
	glutCreateWindow("OpenGL lesson 1");

	glutReshapeFunc(reshape);
	glutDisplayFunc(display);

	glutMainLoop();

	return 0;
}

void reshape(int w, int h)
{
	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, w, 0, h);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}