#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
/*
static int year = 0, spin = 0, day = 0;
static GLint fogMode;
const int n = 100;
const GLfloat R = 1.0f;
const GLfloat Pi = 3.1415926536f;

void DrawCircle()
{
	int  i;
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINE_LOOP);
	for (i = 0; i < n; ++i)
	{
		glColor3f(1.0, 0.0, 0.0);
		glVertex2f(R*cos(2 * Pi / n*i), R*sin(2 * Pi / n*i));
	}
	glEnd();
	glFlush();
}
void init(void)
{
	GLfloat position[] = { 0.5, 0.5, 3.0, 0.0 };
	glEnable(GL_DEPTH_TEST);                          //防止遮挡
	glLightfv(GL_LIGHT0, GL_POSITION, position);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	{
		GLfloat mat[3] = { 0.1745, 0.01175, 0.01175 };
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat);
		mat[0] = 0.61424; mat[1] = 0.04136; mat[2] = 0.04136;
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat);
		mat[0] = 0.727811; mat[1] = 0.626959; mat[2] = 0.626959;
		glMaterialfv(GL_FRONT, GL_SPECULAR, mat);
		glMaterialf(GL_FRONT, GL_SHININESS, 0.6*128.0);
	}
	glEnable(GL_FOG);
	{
		GLfloat fogColor[4] = { 0.5, 0.5, 0.5, 1.0 };
		fogMode = GL_EXP;
		glFogi(GL_FOG_MODE, fogMode);
		glFogfv(GL_FOG_COLOR, fogColor);
		glFogf(GL_FOG_DENSITY, 0.35);
		glHint(GL_FOG_HINT, GL_DONT_CARE);
		glFogf(GL_FOG_START, 1.0);
		glFogf(GL_FOG_END, 5.0);
	}
	glClearColor(0.5, 0.9, 0.9, 1.0);  // fog color 
}


void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(0.0, 1.0, 1.0);
	glPushMatrix(); //记住自己的位置
	glutSolidSphere(1.0, 20, 16);   //  画太阳半径、 20经度、16纬度
	glRotatef(spin, 0.0, 1.0, 0.0);  //自转，绕着一个向量以给定角度旋转（正的为逆时针）
	glTranslatef(2.0, 1.0, 0.0);
	glRotatef(spin, 1.0, 0.0, 0.0); //公转
	glRectf(0.1, 0.1, 0.5, 0.5);
	glColor3f(0.0, 0.0, 1.0);
	glutWireSphere(0.2, 8, 8);    // 画第一颗小行星 
	glColor3f(1.0, 0.0, 0.0);
	glTranslatef(2.0, 1.0, 0.0);
	glRotatef(2 * spin, 0.0, 1.0, 0.0);
	glutSolidSphere(0.5, 16, 8);
	glPopMatrix();//回到原来的位置
	glutSwapBuffers();
}
void spinDisplay(void)
{
	spin = spin + 2;
	if (spin > 360)
		spin = spin - 360;
	glutPostRedisplay();
}
void mouse(int button, int state, int x, int y)
{
	switch (button)
	{
	case GLUT_LEFT_BUTTON:
		if (state == GLUT_DOWN)
			glutIdleFunc(spinDisplay);
		break;
	case GLUT_MIDDLE_BUTTON:
		if (state == GLUT_DOWN)
			glutIdleFunc(NULL);
		break;
	default:
		break;
	}
}
void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 0.5, 20.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0, 10.0, 10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}
void keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case 'd':
		day = (day + 10) % 360;
		glutPostRedisplay();
		break;
	case 'D':
		day = (day - 10) % 360;
		glutPostRedisplay();
		break;
	case 'y':
		year = (year + 5) % 360;
		glutPostRedisplay();
		break;
	case 'Y':
		year = (year - 5) % 360;
		glutPostRedisplay();
		break;
	case 27:
		exit(0);
		break;
	default:
		break;
	}
}
*/
#define xmin = 0
#define xmax =200
#define ymin = 0
#define ymax = 150


class wcPt2D{
public:
	GLfloat x, y;
};

void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0); //设置窗口颜色
	//OpenGL默认的处理是在三围下，下面两行将三围左边变成二维坐标
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 200,
		      0, 150);    //规定区域的x坐标值从0.0到200.0，y从0.0到150.0
}

void lineSegment(void)
{
	glClear(GL_COLOR_BUFFER_BIT);//让赋值的窗口显示。GL_COLOR_BUFFER_BIT是一个常量，表示颜色缓存中的位置
	glColor3f(1.0, 0.0, 0.0); //3f表表示使用浮点数，
	
	//画线
	glBegin (GL_LINES);
	  glVertex2i(180, 15);
	  glVertex2i(10, 145);
	glEnd ();
	//画点
	int point1[] = { 75, 150 };
	GLfloat point2[] = { 261.91, 50.67, 188.33 }; //
	glBegin(GLU_POINT);
	  glVertex2i (50,100);
	  glVertex2iv (point1);
	glEnd();
	//三围点
	int point1[] = { 75, 150 };
	glBegin(GLU_POINT);
	glVertex3f(-78.05,909.72,14.60);
	glVertex3f(261.91, 50.67, 188.33);
	glEnd();
	//通过结构体画线
	wcPt2D pointPos;

	pointPos.x = 120.75;
	pointPos.y = 45.30;
	glBegin(GLU_POINT);
	    glVertex2i(pointPos.x, pointPos.y);
    glEnd();

	glFlush ();
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);//初始化窗口

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);//设置窗口缓存和颜色模式
	glutInitWindowSize(400, 400);
	glutInitWindowPosition(50, 100); //窗口左上角确切的位置
	
	glutCreateWindow("OpengGL 程序");// 窗口上显示的名称
	init();
	glutDisplayFunc(lineSegment);
	//glutDisplayFunc(DrawCircle); //屏幕上绘制的函数
	//glutDisplayFunc(display);
	//glutReshapeFunc(reshape);
	//glutKeyboardFunc(keyboard);
	//glutMouseFunc(mouse);
	setPixel(x, y);    //将当前颜色设定值存入帧缓存的整数坐标位置
	getPixel(x, y, color); //参数color得到可个存储在（x，y）像素出的RGB组合对应的整数


	glutMainLoop();


}