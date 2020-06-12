// Final.cpp : Defines the entry point for the console application.
//Includes////////////	

#include "stdafx.h"
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include<iostream>
#include <fstream>
#include <vector>
using namespace std;
struct point {
	double x, y;
};
bool show[5][10];
float x_brick[4][9];
float y_brick[4][9];

int xScale = 50;
int yScale = 10;
int wid = 75, hei = 25;
class brick {
public:
	point origin;

	brick() {

	}
	void buildBrick(point o) {
		origin = o;

		glBegin(GL_LINE_LOOP);
		glVertex2d(o.x, o.y);
		glVertex2d(o.x + wid, o.y);
		glVertex2d(o.x + wid, o.y + hei);
		glVertex2d(o.x, o.y + hei);
		glEnd();
		glFlush();
	}
};

int breakerA[5][6] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 };

double x = 320, y = 50;
double padX = 320, padY = 25, width = 640, height = 480;
double spdY = 0;
double spdX = 0;
const int leftBound = 5, topBound = 475, rightBound = 635, lowerBound = -10;
bool leftPressed = false, rightPressed = false;


void brickGen();
void keyRelease(int, int, int);
void keyPressed(int, int, int);
void drawBall();
point location;




void setWindow(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top) {

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(left, right, bottom, top);


}

void setViewport(GLint left, GLint right, GLint bottom, GLint top) {

	glViewport(left, bottom, right - left, top - bottom);
}

void moveBall() {
	if (x == rightBound) { spdX *= -1; }
	if (x == leftBound) { spdX = .5; }
	if (y == topBound) { spdY *= -1; }
	if (y == lowerBound) { spdX = 0; spdY = 0; x = 320; y = 50; }
	if (x >= padX - 50 && x <= padX + 50 && y == padY + 10) {
		spdY *= -1;
	}



	if (breakerA[0][0] == 1) {
		if (x >= 80 && x <= 80 + wid && y == 240) {
			spdY *= -1;
			breakerA[0][0] = 0;

		}
		//top
		if (x >= 80 && x <= 80 + wid && y == 240 + hei) {
			spdY *= -1;
			breakerA[0][0] = 0;

		}
		//left
		if (x == 80 && y <= 240 + hei && y >= 240) {
			spdX *= -1;
			breakerA[0][0] = 0;


		}//right
		if (x == 80 + wid && y <= 240 + hei && y >= 240) {
			spdX *= -1;
			breakerA[0][0] = 0;

		}
	}

	if (breakerA[0][1] == 1) {
		if (x >= 80 * 2 && x <= 80 * 2 + wid && y == 240) {
			spdY *= -1;
			breakerA[0][1] = 0;

		}
		//top
		if (x >= 80 * 2 && x <= 80 * 2 + wid && y == 240 + hei) {
			spdY *= -1;
			breakerA[0][1] = 0;

		}
		//left
		if (x == 80 * 2 && y <= 240 + hei && y >= 240) {
			spdX *= -1;
			breakerA[0][1] = 0;


		}//right
		if (x == 80 * 2 + wid && y <= 240 + hei && y >= 240) {
			spdX *= -1;
			breakerA[0][1] = 0;

		}
	}

	if (breakerA[0][2] == 1) {
		if (x >= 80 * 3 && x <= 80 * 3 + wid && y == 240) {
			spdY *= -1;
			breakerA[0][2] = 0;

		}
		//top
		if (x >= 80 * 3 && x <= 80 * 3 + wid && y == 240 + hei) {
			spdY *= -1;
			breakerA[0][2] = 0;

		}
		//left
		if (x == 80 * 3 && y <= 240 + hei && y >= 240) {
			spdX *= -1;
			breakerA[0][2] = 0;


		}//right
		if (x == 80 * 3 + wid && y <= 240 + hei && y >= 240) {
			spdX *= -1;
			breakerA[0][2] = 0;

		}
	}

	if (breakerA[0][3] == 1) {
		if (x >= 80 * 4 && x <= 80 * 4 + wid && y == 240) {
			spdY *= -1;
			breakerA[0][3] = 0;

		}
		//top
		if (x >= 80 * 4 && x <= 80 * 4 + wid && y == 240 + hei) {
			spdY *= -1;
			breakerA[0][3] = 0;

		}
		//left
		if (x == 80 * 4 && y <= 240 + hei && y >= 240) {
			spdX *= -1;
			breakerA[0][3] = 0;


		}//right
		if (x == 80 * 4 + wid && y <= 240 + hei && y >= 240) {
			spdX *= -1;
			breakerA[0][3] = 0;

		}
	}


	if (breakerA[0][4] == 1) {
		if (x >= 80 * 5 && x <= 80 * 5 + wid && y == 240) {
			spdY *= -1;
			breakerA[0][4] = 0;

		}
		//top
		if (x >= 80 * 5 && x <= 80 * 5 + wid && y == 240 + hei) {
			spdY *= -1;
			breakerA[0][4] = 0;

		}
		//left
		if (x == 80 * 5 && y <= 240 + hei && y >= 240) {
			spdX *= -1;
			breakerA[0][4] = 0;


		}//right
		if (x == 80 * 5 + wid && y <= 240 + hei && y >= 240) {
			spdX *= -1;
			breakerA[0][4] = 0;

		}
	}


	if (breakerA[0][5] == 1) {
		if (x >= 80 * 6 && x <= 80 * 6 + wid && y == 240) {
			spdY *= -1;
			breakerA[0][5] = 0;

		}
		//top
		if (x >= 80 * 6 && x <= 80 * 6 + wid && y == 240 + hei) {
			spdY *= -1;
			breakerA[0][5] = 0;

		}
		//left
		if (x == 80 * 6 && y <= 240 + hei && y >= 240) {
			spdX *= -1;
			breakerA[0][5] = 0;


		}//right
		if (x == 80 * 6 + wid && y <= 240 + hei && y >= 240) {
			spdX *= -1;
			breakerA[0][5] = 0;

		}
	}



	///////////////////////////////////////////////////////////////////////////////

	if (breakerA[1][0] == 1) {
		if (x >= 80 && x <= 80 + wid && y == 240 + 50) {
			spdY *= -1;
			breakerA[1][0] = 0;

		}
		//top
		if (x >= 80 && x <= 80 + wid && y == 240 + 50 + hei) {
			spdY *= -1;
			breakerA[1][0] = 0;

		}
		//left
		if (x == 80 && y <= 240 + 50 + hei && y >= 240 + 50) {
			spdX *= -1;
			breakerA[1][0] = 0;


		}//right
		if (x == 80 + wid && y <= 240 + 50 + hei && y >= 240 + 50) {
			spdX *= -1;
			breakerA[1][0] = 0;

		}
	}


	if (breakerA[1][1] == 1) {
		if (x >= 80 * 2 && x <= 80 * 2 + wid && y == 240 + 50) {
			spdY *= -1;
			breakerA[1][1] = 0;

		}
		//top
		if (x >= 80 * 2 && x <= 80 * 2 + wid && y == 240 + 50 + hei) {
			spdY *= -1;
			breakerA[1][1] = 0;

		}
		//left
		if (x == 80 * 2 && y <= 240 + 50 + hei && y >= 240 + 50) {
			spdX *= -1;
			breakerA[1][1] = 0;


		}//right
		if (x == 80 * 2 + wid && y <= 240 + 50 + hei && y >= 240 + 50) {
			spdX *= -1;
			breakerA[1][1] = 0;

		}
	}
	if (breakerA[1][2] == 1) {
		if (x >= 80 * 3 && x <= 80 * 3 + wid && y == 240 + 50) {
			spdY *= -1;
			breakerA[1][2] = 0;

		}
		//top
		if (x >= 80 * 3 && x <= 80 * 3 + wid && y == 240 + 50 + hei) {
			spdY *= -1;
			breakerA[1][2] = 0;

		}
		//left
		if (x == 80 * 3 && y <= 240 + 50 + hei && y >= 240 + 50) {
			spdX *= -1;
			breakerA[1][2] = 0;


		}//right
		if (x == 80 * 3 + wid && y <= 240 + 50 + hei && y >= 240 + 50) {
			spdX *= -1;
			breakerA[1][2] = 0;

		}
	}

	if (breakerA[1][3] == 1) {
		if (x >= 80 * 4 && x <= 80 * 4 + wid && y == 240 + 50) {
			spdY *= -1;
			breakerA[1][3] = 0;

		}
		//top
		if (x >= 80 * 4 && x <= 80 * 4 + wid && y == 240 + 50 + hei) {
			spdY *= -1;
			breakerA[1][3] = 0;

		}
		//left
		if (x == 80 * 4 && y <= 240 + 50 + hei && y >= 240 + 50) {
			spdX *= -1;
			breakerA[1][3] = 0;


		}//right
		if (x == 80 * 4 + wid && y <= 240 + 50 + hei && y >= 240 + 50) {
			spdX *= -1;
			breakerA[1][3] = 0;

		}
	}

	if (breakerA[1][4] == 1) {
		if (x >= 80 * 5 && x <= 80 * 5 + wid && y == 240 + 50) {
			spdY *= -1;
			breakerA[1][4] = 0;

		}
		//top
		if (x >= 80 * 5 && x <= 80 * 5 + wid && y == 240 + 50 + hei) {
			spdY *= -1;
			breakerA[1][4] = 0;

		}
		//left
		if (x == 80 * 5 && y <= 240 + 50 + hei && y >= 240 + 50) {
			spdX *= -1;
			breakerA[1][4] = 0;


		}//right
		if (x == 80 * 5 + wid && y <= 240 + 50 + hei && y >= 240 + 50) {
			spdX *= -1;
			breakerA[1][4] = 0;

		}
	}

	if (breakerA[1][5] == 1) {
		if (x >= 80 * 6 && x <= 80 * 6 + wid && y == 240 + 50) {
			spdY *= -1;
			breakerA[1][5] = 0;

		}
		//top
		if (x >= 80 * 6 && x <= 80 * 6 + wid && y == 240 + 50 + hei) {
			spdY *= -1;
			breakerA[1][5] = 0;

		}
		//left
		if (x == 80 * 6 && y <= 240 + 50 + hei && y >= 240 + 50) {
			spdX *= -1;
			breakerA[1][5] = 0;


		}//right
		if (x == 80 * 6 + wid && y <= 240 + 50 + hei && y >= 240 + 50) {
			spdX *= -1;
			breakerA[1][5] = 0;

		}
	}


	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	if (breakerA[2][0] == 1) {
		if (x >= 80 && x <= 80 + wid && y == 240 + 100) {
			spdY *= -1;
			breakerA[2][0] = 0;

		}
		//top
		if (x >= 80 && x <= 80 + wid && y == 240 + 100 + hei) {
			spdY *= -1;
			breakerA[2][0] = 0;

		}
		//left
		if (x == 80 && y <= 240 + 100 + hei && y >= 240 + 100) {
			spdX *= -1;
			breakerA[2][0] = 0;


		}//right
		if (x == 80 + wid && y <= 240 + 100 + hei && y >= 240 + 100) {
			spdX *= -1;
			breakerA[2][0] = 0;

		}
	}
	if (breakerA[2][1] == 1) {
		if (x >= 80 * 2 && x <= 80 * 2 + wid && y == 240 + 100) {
			spdY *= -1;
			breakerA[2][1] = 0;

		}
		//top
		if (x >= 80 * 2 && x <= 80 * 2 + wid && y == 240 + 100 + hei) {
			spdY *= -1;
			breakerA[2][1] = 0;

		}
		//left
		if (x == 80 * 2 && y <= 240 + 100 + hei && y >= 240 + 100) {
			spdX *= -1;
			breakerA[2][1] = 0;


		}//right
		if (x == 80 * 2 + wid && y <= 240 + 100 + hei && y >= 240 + 100) {
			spdX *= -1;
			breakerA[2][1] = 0;

		}
	}


	if (breakerA[2][2] == 1) {
		if (x >= 80 * 3 && x <= 80 * 3 + wid && y == 240 + 100) {
			spdY *= -1;
			breakerA[2][2] = 0;

		}
		//top
		if (x >= 80 * 3 && x <= 80 * 3 + wid && y == 240 + 100 + hei) {
			spdY *= -1;
			breakerA[2][2] = 0;

		}
		//left
		if (x == 80 * 3 && y <= 240 + 100 + hei && y >= 240 + 100) {
			spdX *= -1;
			breakerA[2][2] = 0;


		}//right
		if (x == 80 * 3 + wid && y <= 240 + 100 + hei && y >= 240 + 100) {
			spdX *= -1;
			breakerA[2][2] = 0;

		}
	}


	if (breakerA[2][3] == 1) {
		if (x >= 80 * 4 && x <= 80 * 4 + wid && y == 240 + 100) {
			spdY *= -1;
			breakerA[2][3] = 0;

		}
		//top
		if (x >= 80 * 4 && x <= 80 * 4 + wid && y == 240 + 100 + hei) {
			spdY *= -1;
			breakerA[2][3] = 0;

		}
		//left
		if (x == 80 * 4 && y <= 240 + 100 + hei && y >= 240 + 100) {
			spdX *= -1;
			breakerA[2][3] = 0;


		}//right
		if (x == 80 * 4 + wid && y <= 240 + 100 + hei && y >= 240 + 100) {
			spdX *= -1;
			breakerA[2][3] = 0;

		}
	}




	//
	if (breakerA[2][4] == 1) {
		if (x >= 80 * 5 && x <= 80 * 5 + wid && y == 240 + 100) {
			spdY *= -1;
			breakerA[2][3] = 0;

		}
		//top
		if (x >= 80 * 5 && x <= 80 * 5 + wid && y == 240 + 100 + hei) {
			spdY *= -1;
			breakerA[2][4] = 0;

		}
		//left
		if (x == 80 * 5 && y <= 240 + 100 + hei && y >= 240 + 100) {
			spdX *= -1;
			breakerA[2][4] = 0;


		}//right
		if (x == 80 * 5 + wid && y <= 240 + 100 + hei && y >= 240 + 100) {
			spdX *= -1;
			breakerA[2][4] = 0;

		}
	}

	//
	if (breakerA[2][5] == 1) {
		if (x >= 80 * 6 && x <= 80 * 6 + wid && y == 240 + 100) {
			spdY *= -1;
			breakerA[2][5] = 0;

		}
		//top
		if (x >= 80 * 6 && x <= 80 * 6 + wid && y == 240 + 100 + hei) {
			spdY *= -1;
			breakerA[2][5] = 0;

		}
		//left
		if (x == 80 * 6 && y <= 240 + 100 + hei && y >= 240 + 100) {
			spdX *= -1;
			breakerA[2][5] = 0;


		}//right
		if (x == 80 * 6 + wid && y <= 240 + 100 + hei && y >= 240 + 100) {
			spdX *= -1;
			breakerA[2][5] = 0;

		}
	}

	//
	if (breakerA[3][0] == 1) {
		if (x >= 80 && x <= 80 + wid && y == 240 + 150) {
			spdY *= -1;
			breakerA[3][0] = 0;

		}
		//top
		if (x >= 80 && x <= 80 + wid && y == 240 + 150 + hei) {
			spdY *= -1;
			breakerA[3][0] = 0;

		}
		//left
		if (x == 80 && y <= 240 + 150 + hei && y >= 240 + 150) {
			spdX *= -1;
			breakerA[3][0] = 0;


		}//right
		if (x == 80 + wid && y <= 240 + 150 + hei && y >= 240 + 150) {
			spdX *= -1;
			breakerA[3][0] = 0;

		}
	}

	//

	if (breakerA[3][1] == 1) {
		if (x >= 80 * 2 && x <= 80 * 2 + wid && y == 240 + 150) {
			spdY *= -1;
			breakerA[3][1] = 0;

		}
		//top
		if (x >= 80 * 2 && x <= 80 * 2 + wid && y == 240 + 150 + hei) {
			spdY *= -1;
			breakerA[3][1] = 0;

		}
		//left
		if (x == 80 * 2 && y <= 240 + 150 + hei && y >= 240 + 150) {
			spdX *= -1;
			breakerA[3][1] = 0;


		}//right
		if (x == 80 * 2 + wid && y <= 240 + 150 + hei && y >= 240 + 150) {
			spdX *= -1;
			breakerA[3][1] = 0;

		}
	}

	//

	if (breakerA[3][2] == 1) {
		if (x >= 80 * 3 && x <= 80 * 3 + wid && y == 240 + 150) {
			spdY *= -1;
			breakerA[3][2] = 0;

		}
		//top
		if (x >= 80 * 3 && x <= 80 * 3 + wid && y == 240 + 150 + hei) {
			spdY *= -1;
			breakerA[3][2] = 0;

		}
		//left
		if (x == 80 * 3 && y <= 240 + 150 + hei && y >= 240 + 150) {
			spdX *= -1;
			breakerA[3][2] = 0;


		}//right
		if (x == 80 * 3 + wid && y <= 240 + 150 + hei && y >= 240 + 150) {
			spdX *= -1;
			breakerA[3][2] = 0;

		}
	}


	//
	if (breakerA[3][3] == 1) {
		if (x >= 80 * 4 && x <= 80 * 4 + wid && y == 240 + 150) {
			spdY *= -1;
			breakerA[3][3] = 0;

		}
		//top
		if (x >= 80 * 4 && x <= 80 * 4 + wid && y == 240 + 150 + hei) {
			spdY *= -1;
			breakerA[3][3] = 0;

		}
		//left
		if (x == 80 * 4 && y <= 240 + 150 + hei && y >= 240 + 150) {
			spdX *= -1;
			breakerA[3][3] = 0;


		}//right
		if (x == 80 * 4 + wid && y <= 240 + 150 + hei && y >= 240 + 150) {
			spdX *= -1;
			breakerA[3][3] = 0;

		}
	}


	//
	if (breakerA[3][4] == 1) {
		if (x >= 80 * 5 && x <= 80 * 5 + wid && y == 240 + 150) {
			spdY *= -1;
			breakerA[3][4] = 0;

		}
		//top
		if (x >= 80 * 5 && x <= 80 * 5 + wid && y == 240 + 150 + hei) {
			spdY *= -1;
			breakerA[3][4] = 0;

		}
		//left
		if (x == 80 * 5 && y <= 240 + 150 + hei && y >= 240 + 150) {
			spdX *= -1;
			breakerA[3][4] = 0;


		}//right
		if (x == 80 * 5 + wid && y <= 240 + 150 + hei && y >= 240 + 150) {
			spdX *= -1;
			breakerA[3][4] = 0;

		}
	}
	//
	if (breakerA[3][5] == 1) {
		if (x >= 80 * 6 && x <= 80 * 6 + wid && y == 240 + 150) {
			spdY *= -1;
			breakerA[3][5] = 0;

		}
		//top
		if (x >= 80 * 6 && x <= 80 * 6 + wid && y == 240 + 150 + hei) {
			spdY *= -1;
			breakerA[3][5] = 0;

		}
		//left
		if (x == 80 * 6 && y <= 240 + 150 + hei && y >= 240 + 150) {
			spdX *= -1;
			breakerA[3][5] = 0;


		}//right
		if (x == 80 * 6 + wid && y <= 240 + 150 + hei && y >= 240 + 150) {
			spdX *= -1;
			breakerA[3][5] = 0;

		}
	}

	//
	if (breakerA[4][0] == 1) {
		if (x >= 80 && x <= 80 + wid && y == 240 + 200) {
			spdY *= -1;
			breakerA[4][0] = 0;

		}
		//top
		if (x >= 80 && x <= 80 + wid && y == 240 + 200 + hei) {
			spdY *= -1;
			breakerA[4][0] = 0;

		}
		//left
		if (x == 80 && y <= 240 + 200 + hei && y >= 240 + 200) {
			spdX *= -1;
			breakerA[4][0] = 0;


		}//right
		if (x == 80 + wid && y <= 240 + 200 + hei && y >= 240 + 200) {
			spdX *= -1;
			breakerA[4][0] = 0;

		}
	}

	//
	if (breakerA[4][1] == 1) {
		if (x >= 80 * 2 && x <= 80 * 2 + wid && y == 240 + 200) {
			spdY *= -1;
			breakerA[4][1] = 0;

		}
		//top
		if (x >= 80 * 2 && x <= 80 * 2 + wid && y == 240 + 200 + hei) {
			spdY *= -1;
			breakerA[4][1] = 0;

		}
		//left
		if (x == 80 * 2 && y <= 240 + 200 + hei && y >= 240 + 200) {
			spdX *= -1;
			breakerA[4][1] = 0;


		}//right
		if (x == 80 * 2 + wid && y <= 240 + 200 + hei && y >= 240 + 200) {
			spdX *= -1;
			breakerA[4][1] = 0;

		}
	}

	//
	if (breakerA[4][2] == 1) {
		if (x >= 80 * 3 && x <= 80 * 3 + wid && y == 240 + 200) {
			spdY *= -1;
			breakerA[4][2] = 0;

		}
		//top
		if (x >= 80 * 3 && x <= 80 * 3 + wid && y == 240 + 200 + hei) {
			spdY *= -1;
			breakerA[4][2] = 0;

		}
		//left
		if (x == 80 * 3 && y <= 240 + 200 + hei && y >= 240 + 200) {
			spdX *= -1;
			breakerA[4][2] = 0;


		}//right
		if (x == 80 * 3 + wid && y <= 240 + 200 + hei && y >= 240 + 200) {
			spdX *= -1;
			breakerA[4][2] = 0;

		}
	}

	//
	if (breakerA[4][3] == 1) {
		if (x >= 80 * 4 && x <= 80 * 4 + wid && y == 240 + 200) {
			spdY *= -1;
			breakerA[4][3] = 0;

		}
		//top
		if (x >= 80 * 4 && x <= 80 * 4 + wid && y == 240 + 200 + hei) {
			spdY *= -1;
			breakerA[4][3] = 0;

		}
		//left
		if (x == 80 * 4 && y <= 240 + 200 + hei && y >= 240 + 200) {
			spdX *= -1;
			breakerA[4][3] = 0;


		}//right
		if (x == 80 * 4 + wid && y <= 240 + 200 + hei && y >= 240 + 200) {
			spdX *= -1;
			breakerA[4][3] = 0;

		}
	}


	//
	if (breakerA[4][4] == 1) {
		if (x >= 80 * 5 && x <= 80 * 5 + wid && y == 240 + 200) {
			spdY *= -1;
			breakerA[4][4] = 0;

		}
		//top
		if (x >= 80 * 5 && x <= 80 * 5 + wid && y == 240 + 200 + hei) {
			spdY *= -1;
			breakerA[4][4] = 0;

		}
		//left
		if (x == 80 * 5 && y <= 240 + 200 + hei && y >= 240 + 200) {
			spdX *= -1;
			breakerA[4][4] = 0;


		}//right
		if (x == 80 * 5 + wid && y <= 240 + 200 + hei && y >= 240 + 200) {
			spdX *= -1;
			breakerA[4][4] = 0;

		}
	}

	//
	if (breakerA[4][5] == 1) {
		if (x >= 80 * 6 && x <= 80 * 6 + wid && y == 240 + 200) {
			spdY *= -1;
			breakerA[4][5] = 0;

		}
		//top
		if (x >= 80 * 6 && x <= 80 * 6 + wid && y == 240 + 200 + hei) {
			spdY *= -1;
			breakerA[4][5] = 0;

		}
		//left
		if (x == 80 * 6 && y <= 240 + 200 + hei && y >= 240 + 200) {
			spdX *= -1;
			breakerA[4][5] = 0;


		}//right
		if (x == 80 * 6 + wid && y <= 240 + 200 + hei && y >= 240 + 200) {
			spdX *= -1;
			breakerA[4][5] = 0;

		}
	}



	x += spdX;
	y += spdY;
}








void brickGen() {

	point st;
	st.x = 80;
	st.y = 240;

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 6; j++) {

			if (breakerA[i][j] == 1) {
				brick brick;
				brick.buildBrick(st);

			}
			st.x += 80;


		}
		st.x = 80;
		st.y += 50;
	}



}


void drawBall() {
	glBegin(GL_TRIANGLE_FAN);
	glVertex2d(x, y);
	for (double deg = 0; deg < (10); deg += 0.01)
	{
		glVertex2f((x + sin(deg) * 5), (y + (cos(deg)) * 5));
	}
	glEnd();
	glFlush();


}




void keyPressed(int key, int i, int t) {

	switch (key) {

	case GLUT_KEY_LEFT:
		leftPressed = true;
		if (rightPressed == false && padX != 20) {
			padX = padX - 50;
			cout << padX;
			break;
		}
		else break;

	case GLUT_KEY_RIGHT:
		rightPressed = true;
		if (leftPressed == false && padX != 620) {
			padX = padX + 50;
			cout << padX;
			break;
		}
		else break;


	case GLUT_KEY_UP: {
		spdX = .5;
		spdY = .5;

		break;
	}

	case GLUT_KEY_F1: {
		xScale = 300;

		break;
	}
	case GLUT_KEY_F2: {
		xScale = 50;

		break;
	}

	}
}


void keyRelease(int key, int i, int t) {
	switch (key) {

	case GLUT_KEY_LEFT:
		leftPressed = false;
		break;

	case GLUT_KEY_RIGHT:
		rightPressed = false;
		break;
	}
}

void drawPaddle() {

	glBegin(GL_LINE_LOOP);
	glVertex2d(padX, padY);
	glVertex2d(padX + xScale, padY);
	glVertex2d(padX + xScale, padY + yScale);
	glVertex2d(padX - xScale, padY + yScale);
	glVertex2d(padX - xScale, padY);
	glEnd();
	glFlush();
}


void init() {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glPointSize(2.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 640.0, 0.0, 480);
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	brickGen();
	drawPaddle();
	drawBall();
	moveBall();
	glutSwapBuffers();
	glutPostRedisplay();

}


void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(100, 150);
	glutCreateWindow("Bricks");
	init();
	glutDisplayFunc(display);
	glutSpecialFunc(keyPressed);
	glutSpecialUpFunc(keyRelease);
	glutMainLoop();




}








