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
	glEnable(GL_DEPTH_TEST);                          //��ֹ�ڵ�
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
	glPushMatrix(); //��ס�Լ���λ��
	glutSolidSphere(1.0, 20, 16);   //  ��̫���뾶�� 20���ȡ�16γ��
	glRotatef(spin, 0.0, 1.0, 0.0);  //��ת������һ�������Ը����Ƕ���ת������Ϊ��ʱ�룩
	glTranslatef(2.0, 1.0, 0.0);
	glRotatef(spin, 1.0, 0.0, 0.0); //��ת
	glRectf(0.1, 0.1, 0.5, 0.5);
	glColor3f(0.0, 0.0, 1.0);
	glutWireSphere(0.2, 8, 8);    // ����һ��С���� 
	glColor3f(1.0, 0.0, 0.0);
	glTranslatef(2.0, 1.0, 0.0);
	glRotatef(2 * spin, 0.0, 1.0, 0.0);
	glutSolidSphere(0.5, 16, 8);
	glPopMatrix();//�ص�ԭ����λ��
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
	glClearColor(1.0, 1.0, 1.0, 0.0); //���ô�����ɫ
	//OpenGLĬ�ϵĴ���������Χ�£��������н���Χ��߱�ɶ�ά����
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 200,
		      0, 150);    //�涨�����x����ֵ��0.0��200.0��y��0.0��150.0
}

void lineSegment(void)
{
	glClear(GL_COLOR_BUFFER_BIT);//�ø�ֵ�Ĵ�����ʾ��GL_COLOR_BUFFER_BIT��һ����������ʾ��ɫ�����е�λ��
	glColor3f(1.0, 0.0, 0.0); //3f���ʾʹ�ø�������
	
	//����
	glBegin (GL_LINES);
	  glVertex2i(180, 15);
	  glVertex2i(10, 145);
	glEnd ();
	//����
	int point1[] = { 75, 150 };
	GLfloat point2[] = { 261.91, 50.67, 188.33 }; //
	glBegin(GLU_POINT);
	  glVertex2i (50,100);
	  glVertex2iv (point1);
	glEnd();
	//��Χ��
	int point1[] = { 75, 150 };
	glBegin(GLU_POINT);
	glVertex3f(-78.05,909.72,14.60);
	glVertex3f(261.91, 50.67, 188.33);
	glEnd();
	//ͨ���ṹ�廭��
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
	glutInit(&argc, argv);//��ʼ������

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);//���ô��ڻ������ɫģʽ
	glutInitWindowSize(400, 400);
	glutInitWindowPosition(50, 100); //�������Ͻ�ȷ�е�λ��
	
	glutCreateWindow("OpengGL ����");// ��������ʾ������
	init();
	glutDisplayFunc(lineSegment);
	//glutDisplayFunc(DrawCircle); //��Ļ�ϻ��Ƶĺ���
	//glutDisplayFunc(display);
	//glutReshapeFunc(reshape);
	//glutKeyboardFunc(keyboard);
	//glutMouseFunc(mouse);
	setPixel(x, y);    //����ǰ��ɫ�趨ֵ����֡�������������λ��
	getPixel(x, y, color); //����color�õ��ɸ��洢�ڣ�x��y�����س���RGB��϶�Ӧ������


	glutMainLoop();


}