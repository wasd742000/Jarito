#define _CRT_SECURE_NO_WARNINGS
#define WIN32_LEAN_AND_MEAN

#include <iostream>
#include <vector>
#include <list>
#include <windows.h>

#include <GL/glut.h>

using namespace std;

typedef struct {
	int myX;
	int myY;
	float myR;
	float myG;
	float myB;
}myPoint;

// GLOBAL VARIABLE 
int width = 820; int height = 640;		// Window size
float red = 1.0, green = 1.0, blue = 1.0; //
int first_x, first_y;		// first point position for drawing in two points mode (line, rectangle, circle)
int brushSize = 4;		//default Brush size = 4px
int eraserSize = 2;		//default eraser size = 4px
int mode = 1;		// 1:point, 2:line, 3:rectangle, 4:circle, 5:brush
vector<myPoint> points;		// array to store drawn points


// flag
bool isTwoPoint = false; // two points drawing mode (line, rectangdle, circle) 
bool isEraser = false; // Eraser mode







void drw_clear()
{
	points.clear(); // clean all points in array vector
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
	isEraser = false;
}

void quit()
{
	int msgboxID = MessageBox(
		NULL,
		(LPCWSTR)L"Do you really want to quit ?",
		(LPCWSTR)L"QUESTION",
		MB_ICONQUESTION | MB_YESNO | MB_DEFBUTTON2);

	switch (msgboxID)
	{
	case IDYES:
		exit(0);
		break;
	}

	//return msgboxID;
}

void drw_point(int x, int y)
{
	float tmpR, tmpG, tmpB;
	if (isEraser)
		tmpR = tmpG = tmpB = 0;
	else
	{
		tmpR = red;
		tmpG = green;
		tmpB = blue;
	}

	myPoint newpoint = { x, height - y, tmpR, tmpG, tmpB };
	points.push_back(newpoint);
}

void drw_brush(int x, int y)
{
	for (int i = 0; i < brushSize; i++)
	{
		int randX = rand() % (brushSize + 1) - brushSize / 2 + x;
		int randY = rand() % (brushSize + 1) - brushSize / 2 + y;
		drw_point(randX, randY);
	}
}

void drw_line(int x1, int y1, int x2, int y2)
{
	bool changed = false;
	// Bresenham's line algorithm is only good when abs(dx) >= abs(dy)
	// So when abs(dx) < abs(dy), change axis x and y
	if (abs(x2 - x1) < abs(y2 - y1))
	{
		int tmp1 = x1;
		x1 = y1;
		y1 = tmp1;
		int tmp2 = x2;
		x2 = y2;
		y2 = tmp2;
		changed = true;
	}
	int dx = x2 - x1;
	int dy = y2 - y1;
	int yi = 1;
	int xi = 1;
	if (dy < 0)
	{
		yi = -1;
		dy = -dy;
	}
	if (dx < 0)
	{
		xi = -1;
		dx = -dx;
	}
	int d = 2 * dy - dx;
	int incrE = dy * 2;
	int incrNE = 2 * dy - 2 * dx;

	int x = x1, y = y1;
	if (changed)
		drw_point(y, x);
	else
		drw_point(x, y);
	while (x != x2)
	{
		if (d <= 0)
			d += incrE;
		else
		{
			d += incrNE;
			y += yi;
		}
		x += xi;
		if (changed)
			drw_point(y, x);
		else
			drw_point(x, y);
	}
}

/**
 * We can use drawLine function to draw the rectangle
 *
 * Top-left corner specified by the first click,
 * and the bottom-right corner specified by a second click
 */
void drw_rectangle(int x1, int y1, int x2, int y2)
{
	if (x1 < x2 && y1 < y2)
	{
		drw_line(x1, y1, x2, y1);
		drw_line(x2, y1, x2, y2);
		drw_line(x2, y2, x1, y2);
		drw_line(x1, y2, x1, y1);
	}
	else
	{
		MessageBox(
			NULL,
			(LPCWSTR)L"When drawing a rectangle, the second click must be at the bottom-right of the first click.",
			(LPCWSTR)L"NOTICE !",
			MB_ICONINFORMATION | MB_OK);
	}
}


void drw_circle(int x1, int y1, int x2, int y2)
{
	int r = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
	double d;
	int x, y;

	x = 0;
	y = r;
	d = 1.25 - r;

	while (x <= y)
	{
		drw_point(x1 + x, y1 + y);
		drw_point(x1 - x, y1 + y);
		drw_point(x1 + x, y1 - y);
		drw_point(x1 - x, y1 - y);
		drw_point(x1 + y, y1 + x);
		drw_point(x1 - y, y1 + x);
		drw_point(x1 + y, y1 - x);
		drw_point(x1 - y, y1 - x);
		x++;
		if (d < 0)
		{
			d += 2*x + 3;
		}
		else
		{
			y--;
			d += 2*(x - y) + 5;
		}
	}
}

void drw_erase(int x, int y)
{
	for (int i = -eraserSize; i <= eraserSize; i++)
	{
		for (int j = -eraserSize; j <= eraserSize; j++)
		{
			drw_point(x + i, y + j);
		}
	}
}


// MENU PROCESS FUNCTION
void menu_out(int value)
{
	switch (value)
	{
	case 0:
		quit();
		break;
	case 1:
		drw_clear();
		break;
	}
}

void menu_brushSize(int value)
{
	mode = 5;
	isEraser = false;
	brushSize = value;
	glutSetCursor(GLUT_CURSOR_CROSSHAIR);
}

void menu_colour(int value)
{
	isTwoPoint = false;
	isEraser = false;

	switch (value)
	{
	case 1: // red
		red = 1.0;
		green = 0.0;
		blue = 0.0;
		break;
	case 2: // green
		red = 0.0;
		green = 1.0;
		blue = 0.0;
		break;
	case 3: // blue
		red = 0.0;
		green = 0.0;
		blue = 1.0;
		break;
	case 4: // orange
		red = 1;
		green = 0.6;
		blue = 0;
		break;
	case 5: // yellow
		red = 1.0;
		green = 1.0;
		blue = 0.0;
		break;
	case 6: // white
		red = 1.0;
		green = 1.0;
		blue = 1.0;
		break;
	case 7: // magenta
		red = 1.0;
		green = 0.0;
		blue = 1.0;
		break;
	case 8: // cyan
		red = 0.0;
		green = 1.0;
		blue = 1.0;
		break;
	case 9: // white
		red = 0.5;
		green = 0.5;
		blue = 0.5;
		break;
	}
}

void menu_shape(int value)
{
	mode = value;
	isEraser = false;
	isTwoPoint = false;

	switch (mode)
	{
	case 1:
		glutSetCursor(GLUT_CURSOR_RIGHT_ARROW);
		break;
	case 2:
	case 3:
	case 4:
		glutSetCursor(GLUT_CURSOR_CROSSHAIR);
		break;
	}
}

void menu_eraserSize(int value)
{
	glutSetCursor(GLUT_CURSOR_RIGHT_ARROW);
	eraserSize = value;
	isEraser = true;
}

// MENU DISPLAY FUNCTION
void myCreateMenu()
{
	int colourMenu = glutCreateMenu(menu_colour);
	glutAddMenuEntry("Red", 1);
	glutAddMenuEntry("Green", 2);
	glutAddMenuEntry("Blue", 3);
	glutAddMenuEntry("Orange", 4);
	glutAddMenuEntry("Yellow", 5);
	glutAddMenuEntry("White", 6);
	glutAddMenuEntry("Magenta", 7);
	glutAddMenuEntry("Cyan", 8);
	glutAddMenuEntry("Gray", 9);

	int sizeMenu = glutCreateMenu(menu_brushSize);
	glutAddMenuEntry("Thin", 4);
	glutAddMenuEntry("Medium", 8);
	glutAddMenuEntry("Bold", 16);
	glutAddMenuEntry("Super Bold", 32);

	int shapeMenu = glutCreateMenu(menu_shape);
	glutAddMenuEntry("Point", 1);
	glutAddMenuEntry("Line", 2);
	glutAddMenuEntry("Rectangle", 3);
	glutAddMenuEntry("Circle", 4);
	glutAddSubMenu("Brush", sizeMenu);

	int eraserSizeMenu = glutCreateMenu(menu_eraserSize);
	glutAddMenuEntry("Small", 2);
	glutAddMenuEntry("Medium", 4);
	glutAddMenuEntry("Big", 8);
	glutAddMenuEntry("GIANT ERASER", 16);

	int main_id = glutCreateMenu(menu_out);
	glutAddSubMenu("Shapes", shapeMenu);
	glutAddSubMenu("Colour", colourMenu);
	glutAddSubMenu("Eraser", eraserSizeMenu);
	glutAddMenuEntry("Clear", 1);
	glutAddMenuEntry("Quit", 0);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 1.0); // blackground is black
	glColor3f(red, green, blue);

	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, width, 0.0, height);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}


void myKeyboard(unsigned char key, int xIn, int yIn)
{
	isTwoPoint = false;
	switch (key)
	{
	case 'q':
	case 27: // esc key
		quit();
		break;
	case 'c':
		drw_clear();
		break;
	case '+': // increase brush/eraser size
		if (mode == 5 && !isEraser)
		{
			if (brushSize < 32)
				brushSize *= 2;
			else
			{
				MessageBox(
					NULL,
					(LPCWSTR)L"Brush's size cannot be larger. It is already the largest",
					(LPCWSTR)L"WARNING !",
					MB_ICONINFORMATION | MB_OK);
			}
		}
		else if (isEraser)
		{
			if (eraserSize < 16)
				eraserSize *= 2;
			else
			{
				MessageBox(
					NULL,
					(LPCWSTR)L"Eraser's size cannot be larger. It is already the largest.",
					(LPCWSTR)L"WARNING !",
					MB_ICONINFORMATION | MB_OK);
			}
		}
		break;
	case '-': // decrease brush/eraser size
		if (mode == 5 && !isEraser)
		{
			if (brushSize > 4)
				brushSize /= 2;
			else
			{
				MessageBox(
					NULL,
					(LPCWSTR)L"Brush's size cannot be smaller. It is already the smallest.",
					(LPCWSTR)L"WARNING !",
					MB_ICONINFORMATION | MB_OK);
			}
		}
		else if (isEraser)
		{
			if (eraserSize > 2)
				eraserSize /= 2;
			else
			{
				MessageBox(
					NULL,
					(LPCWSTR)L"Erasers size cannot be smaller. It is already the smallest.",
					(LPCWSTR)L"WARNING !",
					MB_ICONINFORMATION | MB_OK);
			}
		}
		break;
	}
}

// GL process
void myMouse(int bin, int state, int x, int y)
{
	if (bin == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if (isEraser)
		{
			drw_erase(x, y);
		}
		else
		{
			if (mode == 1)
			{
				drw_point(x, y);
			}
			else if (mode == 5)
			{
				drw_brush(x, y);
			}
			else
			{
				if (!isTwoPoint)
				{
					first_x = x;
					first_y = y;
					isTwoPoint = true;
				}
				else
				{
					if (mode == 2)
						drw_line(first_x, first_y, x, y);
					else if (mode == 3)
						drw_rectangle(first_x, first_y, x, y);
					else if (mode == 4)
						drw_circle(first_x, first_y, x, y);
					isTwoPoint = false;
				}
			}
		}
	}
}

void myMotion(int x, int y)
{
	if (isEraser)
		drw_erase(x, y);
	else
	{
		if (mode == 1)
		{
			drw_point(x, y);
		}
		if (mode == 5)
			drw_brush(x, y);
	}
}

void myReshape(int w, int h)
{
	width = w;
	height = h;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, w, 0, h);

	glMatrixMode(GL_MODELVIEW);
	glViewport(0, 0, w, h);
}

void myDisplay(void)
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(2);
	glBegin(GL_POINTS);
	for (unsigned int i = 0; i < points.size(); i++)
	{
		glColor3f(points[i].myR, points[i].myG, points[i].myB);
		glVertex2i(points[i].myX, points[i].myY);
	}
	glEnd();
	glutSwapBuffers();
}

void myInit()
{
	glutDisplayFunc(myDisplay);
	glutReshapeFunc(myReshape);
	glutKeyboardFunc(myKeyboard);
	glutMouseFunc(myMouse);
	glutMotionFunc(myMotion);
}

// Make drawing smooth
void timer(int val)
{
	glutPostRedisplay();
	glutTimerFunc(1000 / 30, timer, 0);
}

void userManual()
{
	std::cout << "#######################################################################\n" 
		<< "\n\t\tUSER MANUAL:\n\n" 
		<< "Phim 'esc' hoac 'q'\t"
		<< "= Thoat khoi chuong trinh.\n"
		<< "Phim 'c'\t"
		<< "= Xoa toan bo man hinh.\n"
		<< "Phim '+'\t"
		<< "= Tang kich co cho brush hoac eraser.\n"
		<< "Phim '-'\t"
		<< "= Giam kich co cho brush hoac eraser.\n"
		<< "#######################################################################" << std::endl;
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutInitWindowSize(width, height);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Paint");
	myInit();
	timer(0);
	init();
	userManual();
	myCreateMenu();
	glutMainLoop();
	return 0;
}


