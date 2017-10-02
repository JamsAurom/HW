#include <iostream>
#include "Header.h"
#include <glut.h>    
#include <math.h>



const double PI = 157;
const double PI_2 = 79;
const double Pi = 3.14159265359;

using namespace std;


void display()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glLineWidth(2);

	glBegin(GL_LINES);
		glColor3f(1.0, 1.0, 1.0);
		glVertex2i(400, 800);
		glVertex2i(400, 0);
	glEnd();

	glBegin(GL_LINES);
		glColor3f(1.0, 1.0, 1.0);
		glVertex2i(800, 400);
		glVertex2i(0, 400);
	glEnd();

	glLineWidth(1);

	for (size_t i = 0; i < 800; i += 20)
	{
		glBegin(GL_LINES);
			glColor3f(1.0, 1.0, 1.0);
			glVertex2i(400, i);
			glVertex2i(395, i);
		glEnd();
	}

	for (size_t i = 0; i < 800; i += 50)
	{
		glBegin(GL_LINES);
			glColor3f(1.0, 1.0, 1.0);
			glVertex2i(i, 400);
			glVertex2i(i, 395);
		glEnd();
	}

	glEnable(GL_LINE_STIPPLE);
	glLineStipple(2, 58360);

	for (size_t i = PI_2; i < 400; i += PI)
	{
		glBegin(GL_LINES);
			glColor3f(0.0, 1.0, 0.0);
			glVertex2i(400 + i, 800);
			glVertex2i(400 + i, 0);
		glEnd();

		glBegin(GL_LINES);
			glColor3f(0.0, 1.0, 0.0);
			glVertex2i(400 - i, 800);
			glVertex2i(400 - i, 0);
		glEnd();
	}

	glDisable(GL_LINE_STIPPLE);

	glLineWidth(2);

	/*for (size_t i = 0; i < length; i++)
	{
		glBegin(GL_LINE_STRIP);
			glColor3f(1.0, 0.0, 0.0);
			glVertex2i(400 - i, 800);
			glVertex2i(400 - i, 0);
		glEnd();
	}*/

	double rez, k;
	double i = 400;
	for (size_t l = 0; l <= 3; l++)
	{
		glBegin(GL_LINE_STRIP);
			glColor3f(1.0, 0.0, 0.0);
			for (i; i <= 400 + PI_2 + PI * l - 1; i++)
			{
				k = (i - 400) / 50;
				rez = cos(k);
				//cout << k << "  :  " << rez << "\n";
				if (rez == 0) break;
				rez = 1 / rez;
				glVertex2i(i, 400 + (rez * 20));
			}
		glEnd();
		i += 2;
	}

	i = 400;

	for (size_t l = 0; l <= 3; l++)
	{
		glBegin(GL_LINE_STRIP);
			glColor3f(1.0, 0.0, 0.0);
			for (i; i >= 400 - PI_2 - PI * l + 1; i--)
			{
				k = (400 - i) / 50;
				rez = cos(k);
				//cout << -k << "  :  " << rez << "\n";
				if (rez == 0) break;
				rez = 1 / rez;
				glVertex2i(i, 400 + (rez * 20));
			}
		glEnd();
		i -= 2;
	}


	
	glColor3f(1.0, 1.0, 0.0);
	double _tmpPoint;
	
	double x, xi;

	cin >> x;

	xi = topi(x);

	rez = cosin(xi, 0.000000000000000001);
	rez = abs(1 / rez);

	double p = 0.0;
	int iii = 0;

	do
	{
		if ((x >= (p - Pi / 2)) && (x <= (p + Pi / 2)))
		{
			break;
		}

		p += Pi;
		iii++;
	} while (true);

	if (iii % 2 == 0)
	{}
	else	rez = -rez;

	double ll = 1 / cos(x);
	cout << " My:   " << rez << "\n Csec: " << ll;
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(400 + (x * 50), 400 + (rez * 20));
	int rad = 50;

	for (int i = 0; i <= rad; i++)
	{
		_tmpPoint = (float)i / rad * 3.1415f * 2.0f;
		glVertex2f(400 + (x * 50) + cos(_tmpPoint) * (rad / 10),
			400 + (rez * 20) + sin(_tmpPoint) * (rad / 10));
	}
	glEnd();

	glutSwapBuffers();
}