#include<GL/gl.h>
#include<GL/glu.h>
#include<Gl/glut.h>
#include<math.h>


void display();
void reshape(int,int);
void timer(int);

void init()
{
	glClearColor(0.0,0.0,0.6,1.0);
}


int main(int argc,char**argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	
	glutInitWindowPosition(200,100);
	glutInitWindowSize(650,500);
	
	glutCreateWindow("WaterCycle");
	
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutTimerFunc(0,timer,0);
	init();
	
	
	glutMainLoop();
}


float x_position = 6.5;
float y_position = -3.0;
float y2_position = 6.5;
int state = 1;
float theta;

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	
	//draw
	
	//sky
	glColor3f(0.0,1.0,1.0);
	glBegin(GL_POLYGON);
	
	glVertex2f(-10.0,-2.0);
	glVertex2f(10.0,-2.0);
	glColor3f(0.4,0.4,1.0);
	glVertex2f(10.0,10.0);
	glVertex2f(-10.0,10.0);
	
	glEnd();
	
	//ground
	glColor3f(0.4,0.5,0.0);
	glBegin(GL_POLYGON);
	
	glVertex2f(-10.0,-10.0);
	glVertex2f(0.0,-10.0);
	glVertex2f(-2.0,-2.0);
	glVertex2f(-10.0,-2.0);
	
	glEnd();
	
	//sea
	glColor3f(0.0,0.5,1.0);
	glBegin(GL_POLYGON);
	
	glVertex2f(0.0,-10.0);
	glVertex2f(10.0,-10.0);
	glColor3f(0.0,0.0,0.6);
	glVertex2f(10.0,-2.0);
	glVertex2f(-2.0,-2.0);
	
	glEnd();
	
	//mountains	
	glColor3f(0.4,0.1,0.1);
	glBegin(GL_POLYGON);
	
	glVertex2f(-10.0,-2.0);
	glVertex2f(-8.0,3.5);
	glVertex2f(-7.5,4.5);
	glColor3f(0.6,0.3,0.2);
	glVertex2f(-7.0,3.5);
	glVertex2f(-5.0,-2.0);
	
	glEnd();
	
	glColor3f(0.4,0.1,0.1);
	glBegin(GL_POLYGON);
	
	glVertex2f(-7.0,-2.0);
	glVertex2f(-5.0,3.5);
	glVertex2f(-4.5,4.5);
	glColor3f(0.6,0.3,0.2);
	glVertex2f(-4.0,3.5);
	glVertex2f(-2.0,-2.0);
	
	glEnd();
	
	//river
	glColor3f(0.0,0.3,1.0);
	glBegin(GL_POLYGON);
	glVertex2f(-6.5,-3);
	glVertex2f(-5.5,-3);
	glVertex2f(-7.0,-2.0);
	
	glEnd();
	
	glColor3f(0.0,0.3,1.0);
	glBegin(GL_POLYGON);
	glVertex2f(-6.8,-4.5);
	glVertex2f(-5.3,-4.0);
	glVertex2f(-5.5,-3.0);
	glVertex2f(-6.5,-3.0);
	
	glEnd();

	glColor3f(0.0,0.3,1.0);
	glBegin(GL_POLYGON);
	glVertex2f(-6.7,-6.0);
	glVertex2f(-4.9,-4.8);
	glVertex2f(-5.3,-4.0);
	glVertex2f(-6.8,-4.5);
	
	glEnd();
	
	glColor3f(0.0,0.3,1.0);
	glBegin(GL_POLYGON);
	glVertex2f(-5.4,-6.8);
	glVertex2f(-3.6,-5.4);
	glVertex2f(-4.9,-4.8);
	glVertex2f(-6.7,-6.0);
	
	glEnd();
	
	glColor3f(0.0,0.3,1.0);
	glBegin(GL_POLYGON);
	glVertex2f(-5.4,-6.8);
	glVertex2f(-0.3,-8.8);
	glVertex2f(-1.0,-6.0);
	glVertex2f(-4.9,-4.8);
	
	glEnd();
	
	//cloud1
	glColor3f(0.7,0.8,0.8);
	glBegin(GL_POLYGON);
	
	for(int i=0;i<360;i++)
	{
		theta=i*3.142/180;
		glVertex2f(x_position+0.9*cos(theta),8+0.9*sin(theta));
	}
	glEnd();
	
	glBegin(GL_POLYGON);
	
	for(int i=0;i<360;i++)
	{
		theta=i*3.142/180;
		glVertex2f((x_position-1)+0.9*cos(theta),8+0.9*sin(theta));
	}
	glEnd();
	
	glBegin(GL_POLYGON);
	
	for(int i=0;i<360;i++)
	{
		theta=i*3.142/180;
		glVertex2f((x_position-0.5)+0.63*cos(theta),8.2+1.12*sin(theta));
	}
	glEnd();

	//cloud2
	glColor3f(0.7,0.8,0.8);
	glBegin(GL_POLYGON);
	
	for(int i=0;i<360;i++)
	{
		theta=i*3.142/180;
		glVertex2f((x_position-4.0)+0.9*cos(theta),8+0.9*sin(theta));
	}
	glEnd();
	
	glBegin(GL_POLYGON);
	
	for(int i=0;i<360;i++)
	{
		theta=i*3.142/180;
		glVertex2f((x_position-5.0)+0.9*cos(theta),8+0.9*sin(theta));
	}
	glEnd();
	
	glBegin(GL_POLYGON);
	
	for(int i=0;i<360;i++)
	{
		theta=i*3.142/180;
		glVertex2f((x_position-4.5)+0.63*cos(theta),8.2+1.12*sin(theta));
	}
	glEnd();

	//cloud3
	glColor3f(0.7,0.8,0.8);
	glBegin(GL_POLYGON);
	
	for(int i=0;i<360;i++)
	{
		theta=i*3.142/180;
		glVertex2f(-5.5+0.9*cos(theta),8+0.9*sin(theta));
	}
	glEnd();
	
	glBegin(GL_POLYGON);
	
	for(int i=0;i<360;i++)
	{
		theta=i*3.142/180;
		glVertex2f(-6.5+0.9*cos(theta),8+0.9*sin(theta));
	}
	glEnd();
	
	glBegin(GL_POLYGON);
	
	for(int i=0;i<360;i++)
	{
		theta=i*3.142/180;
		glVertex2f(-6+0.63*cos(theta),8.2+1.12*sin(theta));
	}
	glEnd();

	//cloud4
	glColor3f(0.7,0.8,0.8);
	glBegin(GL_POLYGON);
	
	for(int i=0;i<360;i++)
	{
		theta=i*3.142/180;
		glVertex2f(-8.5+0.9*cos(theta),8+0.9*sin(theta));
	}
	glEnd();
	
	glBegin(GL_POLYGON);
	
	for(int i=0;i<360;i++)
	{
		theta=i*3.142/180;
		glVertex2f(-9.5+0.9*cos(theta),8+0.9*sin(theta));
	}
	glEnd();
	
	glBegin(GL_POLYGON);
	
	for(int i=0;i<360;i++)
	{
		theta=i*3.142/180;
		glVertex2f(-9.0+0.63*cos(theta),8.2+1.12*sin(theta));
	}
	glEnd();
	
	//rain1
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
	
	glVertex2f(-9.1,y2_position);
	glVertex2f(-9.05,y2_position);
	glVertex2f(-9.0,y2_position+0.4);
	glVertex2f(-9.05,y2_position+0.4);
	
	glEnd();

	glBegin(GL_POLYGON);
	
	glVertex2f(-9.7,y2_position);
	glVertex2f(-9.65,y2_position);
	glVertex2f(-9.6,y2_position+0.4);
	glVertex2f(-9.65,y2_position+0.4);
	
	glEnd();
	
	glBegin(GL_POLYGON);
	
	glVertex2f(-8.5,y2_position);
	glVertex2f(-8.45,y2_position);
	glVertex2f(-8.4,y2_position+0.4);
	glVertex2f(-8.45,y2_position+0.4);
	
	glEnd();
	
	//rain2
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
	
	glVertex2f(-9.1,y2_position-1.0);
	glVertex2f(-9.05,y2_position-1.0);
	glVertex2f(-9.0,y2_position-0.6);
	glVertex2f(-9.05,y2_position-0.6);
	
	glEnd();

	glBegin(GL_POLYGON);
	
	glVertex2f(-9.7,y2_position-1.0);
	glVertex2f(-9.65,y2_position-1.0);
	glVertex2f(-9.6,y2_position-0.6);
	glVertex2f(-9.65,y2_position-0.6);
	
	glEnd();
	
	glBegin(GL_POLYGON);
	
	glVertex2f(-8.5,y2_position-1.0);
	glVertex2f(-8.45,y2_position-1.0);
	glVertex2f(-8.4,y2_position-0.6);
	glVertex2f(-8.45,y2_position-0.6);
	
	glEnd();
	
	//rain3
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
	
	glVertex2f(-9.1,y2_position-2.0);
	glVertex2f(-9.05,y2_position-2.0);
	glVertex2f(-9.0,y2_position-1.6);
	glVertex2f(-9.05,y2_position-1.6);
	
	glEnd();

	glBegin(GL_POLYGON);
	
	glVertex2f(-9.7,y2_position-2.0);
	glVertex2f(-9.65,y2_position-2.0);
	glVertex2f(-9.6,y2_position-1.6);
	glVertex2f(-9.65,y2_position-1.6);
	
	glEnd();
	
	glBegin(GL_POLYGON);
	
	glVertex2f(-8.5,y2_position-2.0);
	glVertex2f(-8.45,y2_position-2.0);
	glVertex2f(-8.4,y2_position-1.6);
	glVertex2f(-8.45,y2_position-1.6);
	
	glEnd();
	
	//rain4
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
	
	glVertex2f(-9.1,y2_position-3.0);
	glVertex2f(-9.05,y2_position-3.0);
	glVertex2f(-9.0,y2_position-2.6);
	glVertex2f(-9.05,y2_position-2.6);
	
	glEnd();

	glBegin(GL_POLYGON);
	
	glVertex2f(-9.7,y2_position-3.0);
	glVertex2f(-9.65,y2_position-3.0);
	glVertex2f(-9.6,y2_position-2.6);
	glVertex2f(-9.65,y2_position-2.6);
	
	glEnd();
	
	glBegin(GL_POLYGON);
	
	glVertex2f(-8.5,y2_position-3.0);
	glVertex2f(-8.45,y2_position-3.0);
	glVertex2f(-8.4,y2_position-2.6);
	glVertex2f(-8.45,y2_position-2.6);
	
	glEnd();
	
	//rain5
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
	
	glVertex2f(-6.1,y2_position);
	glVertex2f(-6.05,y2_position);
	glVertex2f(-6.0,y2_position+0.4);
	glVertex2f(-6.05,y2_position+0.4);
	
	glEnd();

	glBegin(GL_POLYGON);
	
	glVertex2f(-6.7,y2_position);
	glVertex2f(-6.65,y2_position);
	glVertex2f(-6.6,y2_position+0.4);
	glVertex2f(-6.65,y2_position+0.4);
	
	glEnd();
	
	glBegin(GL_POLYGON);
	
	glVertex2f(-5.5,y2_position);
	glVertex2f(-5.45,y2_position);
	glVertex2f(-5.4,y2_position+0.4);
	glVertex2f(-5.45,y2_position+0.4);
	
	glEnd();
	
	//rain6
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
	
	glVertex2f(-6.1,y2_position-1.0);
	glVertex2f(-6.05,y2_position-1.0);
	glVertex2f(-6.0,y2_position-0.6);
	glVertex2f(-6.05,y2_position-0.6);
	
	glEnd();

	glBegin(GL_POLYGON);
	
	glVertex2f(-6.7,y2_position-1.0);
	glVertex2f(-6.65,y2_position-1.0);
	glVertex2f(-6.6,y2_position-0.6);
	glVertex2f(-6.65,y2_position-0.6);
	
	glEnd();
	
	glBegin(GL_POLYGON);
	
	glVertex2f(-5.5,y2_position-1.0);
	glVertex2f(-5.45,y2_position-1.0);
	glVertex2f(-5.4,y2_position-0.6);
	glVertex2f(-5.45,y2_position-0.6);
	
	glEnd();
	
	//rain7
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
	
	glVertex2f(-6.1,y2_position-2.0);
	glVertex2f(-6.05,y2_position-2.0);
	glVertex2f(-6.0,y2_position-1.6);
	glVertex2f(-6.05,y2_position-1.6);
	
	glEnd();

	glBegin(GL_POLYGON);
	
	glVertex2f(-6.7,y2_position-2.0);
	glVertex2f(-6.65,y2_position-2.0);
	glVertex2f(-6.6,y2_position-1.6);
	glVertex2f(-6.65,y2_position-1.6);
	
	glEnd();
	
	glBegin(GL_POLYGON);
	
	glVertex2f(-5.5,y2_position-2.0);
	glVertex2f(-5.45,y2_position-2.0);
	glVertex2f(-5.4,y2_position-1.6);
	glVertex2f(-5.45,y2_position-1.6);
	
	glEnd();
	
	//rain8
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
	
	glVertex2f(-6.1,y2_position-3.0);
	glVertex2f(-6.05,y2_position-3.0);
	glVertex2f(-6.0,y2_position-2.6);
	glVertex2f(-6.05,y2_position-2.6);
	
	glEnd();

	glBegin(GL_POLYGON);
	
	glVertex2f(-6.7,y2_position-3.0);
	glVertex2f(-6.65,y2_position-3.0);
	glVertex2f(-6.6,y2_position-2.6);
	glVertex2f(-6.65,y2_position-2.6);
	
	glEnd();
	
	glBegin(GL_POLYGON);
	
	glVertex2f(-5.5,y2_position-3.0);
	glVertex2f(-5.45,y2_position-3.0);
	glVertex2f(-5.4,y2_position-2.6);
	glVertex2f(-5.45,y2_position-2.6);
	
	glEnd();
	
	//arrow1
	glBegin(GL_POLYGON);
	
	glVertex2f(3.0,y_position);
	glVertex2f(3.07,y_position);
	glVertex2f(3.07,y_position+2);
	glVertex2f(3.0,y_position+2);
	
	glEnd();
	
	glBegin(GL_POLYGON);
	
	glVertex2f(2.9,y_position+1.8);
	glVertex2f(3.17,y_position+1.8);
	glVertex2f(3.035,y_position+2.1);
	
	glEnd();
	
	//arrow2
	glBegin(GL_POLYGON);
	
	glVertex2f(2.0,y_position);
	glVertex2f(2.07,y_position);
	glVertex2f(2.07,y_position+2.0);
	glVertex2f(2.0,y_position+2.0);
	
	glEnd();
	
	glBegin(GL_POLYGON);
	
	glVertex2f(1.9,y_position+1.8);
	glVertex2f(2.17,y_position+1.8);
	glVertex2f(2.035,y_position+2.1);
	
	glEnd();
	
	//arrow3
	glBegin(GL_POLYGON);
	
	glVertex2f(4.0,y_position);
	glVertex2f(4.07,y_position);
	glVertex2f(4.07,y_position+2.0);
	glVertex2f(4.0,y_position+2.0);
	
	glEnd();
	
	glBegin(GL_POLYGON);
	
	glVertex2f(3.9,y_position+1.8);
	glVertex2f(4.17,y_position+1.8);
	glVertex2f(4.035,y_position+2.1);
	
	glEnd();
	
	//sun
	glColor3f(0.9,0.8,0.0);
	glBegin(GL_POLYGON);
	
	for(int i=0;i<360;i++)
	{
		theta=i*3.142/180;
		glVertex2f(8.5+0.63*cos(theta),8.5+1.12*sin(theta));
	}
	glEnd();
	
	//lines
	glColor3f(0.0,0.7,1.0);
	
	glRasterPos2f(-1.0,-3.0);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'-');
	glRasterPos2f(0.0,-3.0);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'-');
	glRasterPos2f(1.0,-3.0);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'-');
	glRasterPos2f(2.0,-3.0);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'-');
	glRasterPos2f(3.0,-3.0);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'-');
	glRasterPos2f(4.0,-3.0);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'-');
	glRasterPos2f(5.0,-3.0);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'-');
	glRasterPos2f(6.0,-3.0);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'-');
	glRasterPos2f(7.0,-3.0);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'-');
	glRasterPos2f(8.0,-3.0);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'-');
	glRasterPos2f(9.0,-3.0);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'-');
	
	glRasterPos2f(-0.75,-4.0);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'-');
	glRasterPos2f(0.25,-4.0);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'-');
	glRasterPos2f(1.25,-4.0);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'-');
	glRasterPos2f(2.25,-4.0);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'-');
	glRasterPos2f(3.25,-4.0);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'-');
	glRasterPos2f(4.25,-4.0);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'-');
	glRasterPos2f(5.25,-4.0);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'-');
	glRasterPos2f(6.25,-4.0);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'-');
	glRasterPos2f(7.25,-4.0);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'-');
	glRasterPos2f(8.25,-4.0);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'-');
	glRasterPos2f(9.25,-4.0);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'-');
	
	glRasterPos2f(-0.5,-5.0);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'-');
	glRasterPos2f(0.5,-5.0);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'-');
	glRasterPos2f(1.5,-5.0);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'-');
	glRasterPos2f(2.5,-5.0);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'-');
	glRasterPos2f(3.5,-5.0);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'-');
	glRasterPos2f(4.5,-5.0);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'-');
	glRasterPos2f(5.5,-5.0);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'-');
	glRasterPos2f(6.5,-5.0);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'-');
	glRasterPos2f(7.5,-5.0);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'-');
	glRasterPos2f(8.5,-5.0);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'-');
	glRasterPos2f(9.5,-5.0);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'-');
	
	glRasterPos2f(-0.25,-6.0);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'-');
	glRasterPos2f(0.75,-6.0);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'-');
	glRasterPos2f(1.75,-6.0);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'-');
	glRasterPos2f(2.75,-6.0);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'-');
	glRasterPos2f(3.75,-6.0);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'-');
	glRasterPos2f(4.75,-6.0);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'-');
	glRasterPos2f(5.75,-6.0);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'-');
	glRasterPos2f(6.75,-6.0);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'-');
	glRasterPos2f(7.75,-6.0);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'-');
	glRasterPos2f(8.75,-6.0);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'-');
	glRasterPos2f(9.75,-6.0);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'-');
	
	glRasterPos2f(0.0,-7.0);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'-');
	glRasterPos2f(1.0,-7.0);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'-');
	glRasterPos2f(2.0,-7.0);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'-');
	glRasterPos2f(3.0,-7.0);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'-');
	glRasterPos2f(4.0,-7.0);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'-');
	glRasterPos2f(5.0,-7.0);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'-');
	glRasterPos2f(6.0,-7.0);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'-');
	glRasterPos2f(7.0,-7.0);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'-');
	glRasterPos2f(8.0,-7.0);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'-');
	glRasterPos2f(9.0,-7.0);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'-');
	
	glRasterPos2f(0.25,-8.0);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'-');
	glRasterPos2f(1.25,-8.0);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'-');
	glRasterPos2f(2.25,-8.0);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'-');
	glRasterPos2f(3.25,-8.0);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'-');
	glRasterPos2f(4.25,-8.0);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'-');
	glRasterPos2f(5.25,-8.0);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'-');
	glRasterPos2f(6.25,-8.0);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'-');
	glRasterPos2f(7.25,-8.0);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'-');
	glRasterPos2f(8.25,-8.0);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'-');
	glRasterPos2f(9.25,-8.0);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'-');
	
	glRasterPos2f(0.5,-9.0);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'-');
	glRasterPos2f(1.5,-9.0);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'-');
	glRasterPos2f(2.5,-9.0);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'-');
	glRasterPos2f(3.5,-9.0);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'-');
	glRasterPos2f(4.5,-9.0);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'-');
	glRasterPos2f(5.5,-9.0);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'-');
	glRasterPos2f(6.5,-9.0);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'-');
	glRasterPos2f(7.5,-9.0);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'-');
	glRasterPos2f(8.5,-9.0);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'-');
	glRasterPos2f(9.5,-9.0);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'-');
	
	//text
	glColor3f(0.0,0.0,0.0);
	
	glRasterPos2f(4.5,-1.0);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'E');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'v');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'a');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'p');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'o');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'r');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'a');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'t');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'i');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'o');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'n');
	
	glRasterPos2f(8.1,6.8);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'S');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'u');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'n');
	
	glRasterPos2f(1.7,4.0);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'C');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'o');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'n');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'d');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'e');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'n');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'s');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'a');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'t');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'i');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'o');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'n');
	
	glRasterPos2f(-8.0,5.3);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'P');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'r');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'e');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'c');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'i');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'p');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'i');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'t');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'a');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'t');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'i');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'o');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'n');
	
	glRasterPos2f(-7.5,-6.0);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'S');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'u');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'r');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'f');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'a');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'c');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'e');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,' ');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'R');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'u');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'n');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,' ');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'O');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'f');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'f');
	
	glutSwapBuffers();
}


void reshape(int w,int h)
{
	glViewport(0,0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-10,10,-10,10);
	glMatrixMode(GL_MODELVIEW);
	
}

//Animation
void timer(int)
{
	glutPostRedisplay();
	glutTimerFunc(1000/60,timer,0);
	
	//cloud
	switch(state)
	{
	case 1:
		if(x_position>-5)
			x_position-=0.04;
		else
			x_position = 6.5;
		break;	
	}
	//arrow
	switch(state)
	{
	case 1:
		if(y_position<0)
			y_position+=0.02;
		else
			y_position= -3.0;
		break;
	}
	//rain
	switch(state)
	{
	case 1:
		if(y2_position>5.6)
			y2_position-=0.02;
		else
			y2_position= 6.5;
		break;
	}
}








