// opengl20180912.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <GL/glut.h>
void Show()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glRectf(-0.2f, -0.1f, 0.5f, 0.5f);
	glFlush();
}

void myDisplay(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);

	glBegin(GL_TRIANGLES);

	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(0.25, 0.25, 0);
	glVertex3f(0.75, 0.25, 0);
	glVertex3f(0.75, 0.75, 0);
	glVertex3f(0.25, 0.75, 0);
	glEnd();

	glFlush();
}

void myDisplay2(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);

	glBegin(GL_LINE_STRIP);
	glVertex2iv(p1);
	glVertex2iv(p2);
	glVertex2iv(p3);
	glVertex2iv(p4);
	glVertex2iv(p5);
	glEnd();

	glFlush();
}



int main(int argc, char *argv[])
{
	glutInit(&argc, argv);//这个是例行配置
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);//这个是gult 也就是说要单独输出
	glutInitWindowPosition(1, 100);//似乎是与cmd文件的相对位置 2100就在屏幕外面了
	glutInitWindowSize(600, 600);//画框的大小 x 横向 y 纵向
	glutCreateWindow("OpenGL-ONE");//这是框框的名称
	//glutDisplayFunc(Show);//没有这个显示就要崩溃了，括号里面是display(显示)的函数
	glutDisplayFunc(myDisplay);//没有这个显示就要崩溃了，括号里面是display(显示)的函数
	glutMainLoop();//不断循环，没有这个就闪退
	return 0;
}