
#include<GL/glut.h>
#include <math.h>
#include <iostream>
#define PI 3.1415926
using namespace std;


GLfloat no_mat[] = { 1.0, 1.0, 0.0, 1.0 };
GLfloat mat_ambient[] = { 1.0, 0.5, 1.0, 1.0 };
GLfloat mat_ambient_color[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat mat_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat mat_specular[] = { 0.0, 0.6, 0.5, 1.0 };
GLfloat no_shininess[] = { 0.1 };
GLfloat low_shininess[] = { 5.0 };
GLfloat high_shininess[] = { 100.0 };
GLfloat mat_emission[] = { 0.3, 0.2, 0.2, 0.0 };
static int angle = 0, neck = 0, lshoulder = -5, lelbow = -10, rshoulder = 5, relbow = 10,
lhips = 5, rhips = -5, lfoot = 10, rfoot = -10, flagneck = 0, flaglshoulder = 0,
flaglelbow = 0, flagrshoulder = 0, flagrelbow = 0, flaglhips = 0,
flagrhips = 0, flaglfoot = 0, flagrfoot = 0;

float r = 2.0, u = 0, v = 0;
float oldx = 0, oldy = 0, move = 0;

void init(void)
{
	GLfloat ambient[] = { 0.0, 0.0, 0.0, 1.0 };               //環境
	GLfloat diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat position[] = { 20.0, 5.0, 10.0, 0.0 };           //光源位置
	GLfloat lmodel_ambient[] = { 0.4, 0.4, 0.4, 1.0 };      
	GLfloat local_view[] = { 0.0 };

	GLfloat ambient1[] = { 0.4,0.4,0.4,1 };             //環境
	GLfloat diffuse1[] = { 0.6,0.6,0.6,1 };
	GLfloat position1[] = { 1,1,1,1 };             //光源位置
	GLfloat specular1[] = { 0.6,0.6,0.6,1 };

	glClearColor(0, 0, 0, 0);

	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT0, GL_POSITION, position);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
	glLightModelfv(GL_LIGHT_MODEL_LOCAL_VIEWER, local_view);

	glLightfv(GL_LIGHT1, GL_AMBIENT, ambient1);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuse1);
	glLightfv(GL_LIGHT1, GL_POSITION, position1);
	glLightfv(GL_LIGHT1, GL_SPECULAR, specular1);

	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glEnable(GL_LIGHT1);
}

void draw_body(void)
{
	glPushMatrix();
	glTranslatef(0, 1.5, 0);
	glScalef(0.5, 1, 0.4);
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_color);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
	glutSolidCube(4); ;
	glPopMatrix();
}

void draw_leftshoulder(void)
{
	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_AMBIENT, no_mat);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
	glMaterialfv(GL_FRONT, GL_SHININESS, no_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
	glTranslatef(1.5, 3, 0);
	glRotatef(lshoulder, 1, 0, 0);

	glTranslatef(0, -0.5, 0);
	glScalef(0.4, 1, 0.5);
	glutSolidCube(2);

	glScalef(1 / 0.4, 1 / 1, 1 / 0.5);
	glTranslatef(0, -1.4, 0);
	glRotatef(lelbow, 1, 0, 0);
	glutWireSphere(0.4, 200, 500);

	glScalef(0.4, 1, 0.5);
	glTranslatef(0, -1.4, 0);
	glutSolidCube(2);

	glPopMatrix();
}

void draw_rightshoulder(void)
{
	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_AMBIENT, no_mat);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
	glMaterialfv(GL_FRONT, GL_SHININESS, no_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
	glTranslatef(-1.5, 3, 0);
	glRotatef(rshoulder, 1, 0, 0);

	glTranslatef(0, -0.5, 0);
	glScalef(0.4, 1, 0.5);
	glutSolidCube(2);

	glScalef(1 / 0.4, 1 / 1, 1 / 0.5);
	glTranslatef(0, -1.4, 0);
	glRotatef(relbow, 1, 0, 0);
	glutWireSphere(0.4, 200, 500);

	glScalef(0.4, 1, 0.5);
	glTranslatef(0, -1.4, 0);
	glutSolidCube(2);

	glPopMatrix();
}

void draw_head(void)
{
	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_AMBIENT, no_mat);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);

	glTranslatef(0, 3.5, 0);
	glRotatef(neck, 0, 0, 1);
	glTranslatef(0, 1, 0);
	glutWireSphere(1, 200, 500);

	glPopMatrix();
}

void draw_leye(void)
{
	glPushMatrix();
	/*glMaterialfv(GL_FRONT, GL_AMBIENT, no_mat);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);*/
	glColor3f(0, 0, 0);
	//glTranslatef(-0.3,4.5,1);
	glTranslatef(-0.2, 4, 0.5);
	glRotatef(neck, 0, 0, 1);
	glTranslatef(-0.2, 0.5, 0.5);
	//glRotatef(neck,0,0,1);
	//glTranslatef(0,1,0);
	glutWireSphere(0.2, 100, 300);

	glPopMatrix();
}

void draw_reye(void)
{
	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_AMBIENT, no_mat);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);

	glTranslatef(0.2, 4, 0.5);
	glRotatef(neck, 0, 0, 1);
	glTranslatef(0.2, 0.5, 0.5);
	glutWireSphere(0.2, 100, 300);

	glPopMatrix();
}

void draw_mouth(void)
{
	glPushMatrix();
	glColor3f(1, 0, 0);
	//glTranslatef(0,4,1);
	glTranslatef(0, 3.5, 0.5);
	glRotatef(neck, 0, 0, 1);
	glTranslatef(0, 0.5, 0.5);
	glScalef(0.6, 0.4, 0.4);
	//glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_color);
	//glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	//glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	//glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
	//glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
	glutSolidCube(0.6);
	glPopMatrix();
}
void draw_leftfoot(void)
{
	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_AMBIENT, no_mat);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
	glMaterialfv(GL_FRONT, GL_SHININESS, no_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);

	glTranslatef(-0.6, -0.6, 0);
	glRotatef(lfoot, 1, 0, 0);
	glTranslatef(0, -1, 0);
	glScalef(0.4, 1, 0.5);
	glutSolidCube(2);

	glScalef(1 / 0.4, 1 / 1, 1 / 0.5);
	glTranslatef(0, -1.4, 0);
	glRotatef(lhips, 1, 0, 0);
	glutWireSphere(0.4, 200, 500);

	glScalef(0.4, 1, 0.5);
	glTranslatef(0, -1.4, 0);
	glutSolidCube(2);

	glPopMatrix();
}

void draw_rightfoot(void)
{
	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_AMBIENT, no_mat);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
	glMaterialfv(GL_FRONT, GL_SHININESS, no_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);

	glTranslatef(0.6, -0.6, 0);
	glRotatef(rfoot, 1, 0, 0);
	glTranslatef(0, -1, 0);
	glScalef(0.4, 1, 0.5);
	glutSolidCube(2);

	glScalef(1 / 0.4, 1 / 1, 1 / 0.5);
	glTranslatef(0, -1.4, 0);
	glRotatef(rhips, 1, 0, 0);
	glutWireSphere(0.4, 200, 500);

	glScalef(0.4, 1, 0.5);
	glTranslatef(0, -1.4, 0);
	glutSolidCube(2);

	glPopMatrix();
}

void display(void)
{
	/*
	glLoadIdentity();
	gluLookAt(r*sin(u*PI / 180)*cos(v*PI / 180), r*sin(u*PI / 180)*sin(v*PI / 180), r*cos(u*PI / 180),
		0.0, 0.0, 0.0,
		0.0, 1.0, 0.0);
		*/
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();

	glRotatef(angle, 0, 1, 0);

	glTranslatef(0, 4, 0);
	draw_body();
	
	draw_leye();
	draw_reye();
	draw_mouth();
	
	draw_head();
	
	draw_leftshoulder();
	draw_rightshoulder();

	draw_leftfoot();
	draw_rightfoot();

	glPopMatrix();
	glutSwapBuffers();
}

void reshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(74.0f, (GLfloat)w / (GLfloat)h, 1.0f, 1000.0f);
	//glOrtho(-8,8,-8,8,-10,10);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0, 4.0, 10, 0.0, 4, 0.0, 0.0, 1.0, 0.0);
}


void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
		//top
	case 'e':                         //向上移動
		//flagrfoot+=5;
		glTranslatef(0.0f, 0.1f, 0.0f);
		glutPostRedisplay();
		break;
		//left
	case 'a':                           //向左移動
		glTranslatef(-0.1f, -0.0f, 0.0f);
		if (flaglshoulder)           //左手
		{
			lshoulder += 2;
			if (lshoulder >= 20)flaglshoulder = 0;
		}
		else
		{
			lshoulder -= 2;
			if (lshoulder <= -20)flaglshoulder = 1;
		}
		if (flaglelbow)           //左手腕
		{
			lelbow += 2;
			if (lelbow >= 0)flaglelbow = 0;
		}
		else
		{
			lelbow -= 2;
			if (lelbow <= -20)flaglelbow = 1;
		}

		if (flagrshoulder)                //右手
		{
			rshoulder -= 2;
			if (rshoulder <= -20)flagrshoulder = 0;
		}
		else
		{
			rshoulder += 2;
			if (rshoulder >= 20)flagrshoulder = 1;
		}
		if (flagrelbow)                //右手腕
		{
			relbow -= 2;
			if (relbow <= -20)flagrelbow = 0;
		}
		else
		{
			relbow += 2;
			if (relbow >= 0)flagrelbow = 1;
		}
		if (flaglfoot)                           //左腳
		{
			lfoot += 2;
			if (lfoot >= 20)flaglfoot = 0;
		}
		else
		{
			lfoot -= 2;
			if (lfoot <= -20)flaglfoot = 1;
		}
		if (flaglhips)                            //左小腿
		{
			lhips -= 2;
			if (lhips <= 0)flaglhips = 0;
		}
		else
		{
			lhips += 2;
			if (lhips >= 20)flaglhips = 1;
		}
		if (flagrfoot)                           //右腳
		{
			rfoot -= 2;
			if (rfoot <= -20)flagrfoot = 0;
		}
		else
		{
			rfoot += 2;
			if (rfoot >= 20)flagrfoot = 1;
		}
		if (flagrhips)                           //右小腿
		{
			rhips += 2;
			if (rhips >= 20)flagrhips = 0;
		}
		else
		{
			rhips -= 2;
			if (rhips <= 0)flagrhips = 1;
		}
		glutPostRedisplay();

		glutPostRedisplay();
		break;
		//bottom
	case 'q':                           //向下移動
		glTranslatef(0.0f, -0.1f, 0.0f);
		glutPostRedisplay();
		break;
		//right
	case 'd':                           //向右移動
		glTranslatef(0.1f, 0.0f, 0.0f);
		if (flaglshoulder)           //左手
		{
			lshoulder += 2;
			if (lshoulder >= 20)flaglshoulder = 0;
		}
		else
		{
			lshoulder -= 2;
			if (lshoulder <= -20)flaglshoulder = 1;
		}
		if (flaglelbow)           //左手腕
		{
			lelbow += 2;
			if (lelbow >= 0)flaglelbow = 0;
		}
		else
		{
			lelbow -= 2;
			if (lelbow <= -20)flaglelbow = 1;
		}

		if (flagrshoulder)                //右手
		{
			rshoulder -= 2;
			if (rshoulder <= -20)flagrshoulder = 0;
		}
		else
		{
			rshoulder += 2;
			if (rshoulder >= 20)flagrshoulder = 1;
		}
		if (flagrelbow)                //右手腕
		{
			relbow -= 2;
			if (relbow <= -20)flagrelbow = 0;
		}
		else
		{
			relbow += 2;
			if (relbow >= 0)flagrelbow = 1;
		}
		if (flaglfoot)                           //左腳
		{
			lfoot += 2;
			if (lfoot >= 20)flaglfoot = 0;
		}
		else
		{
			lfoot -= 2;
			if (lfoot <= -20)flaglfoot = 1;
		}
		if (flaglhips)                            //左小腿
		{
			lhips -= 2;
			if (lhips <= 0)flaglhips = 0;
		}
		else
		{
			lhips += 2;
			if (lhips >= 20)flaglhips = 1;
		}
		if (flagrfoot)                           //右腳
		{
			rfoot -= 2;
			if (rfoot <= -20)flagrfoot = 0;
		}
		else
		{
			rfoot += 2;
			if (rfoot >= 20)flagrfoot = 1;
		}
		if (flagrhips)                           //右小腿
		{
			rhips += 2;
			if (rhips >= 20)flagrhips = 0;
		}
		else
		{
			rhips -= 2;
			if (rhips <= 0)flagrhips = 1;
		}
		glutPostRedisplay();
		break;
		//inner
	case 'w':                           //遠離移動
		glTranslatef(0.0f, 0.0f, -0.1f);
		if (flaglshoulder)           //左手
		{
			lshoulder += 2;
			if (lshoulder >= 20)flaglshoulder = 0;
		}
		else
		{
			lshoulder -= 2;
			if (lshoulder <= -20)flaglshoulder = 1;
		}
		if (flaglelbow)           //左手腕
		{
			lelbow += 2;
			if (lelbow >= 0)flaglelbow = 0;
		}
		else
		{
			lelbow -= 2;
			if (lelbow <= -20)flaglelbow = 1;
		}

		if (flagrshoulder)                //右手
		{
			rshoulder -= 2;
			if (rshoulder <= -20)flagrshoulder = 0;
		}
		else
		{
			rshoulder += 2;
			if (rshoulder >= 20)flagrshoulder = 1;
		}
		if (flagrelbow)                //右手腕
		{
			relbow -= 2;
			if (relbow <= -20)flagrelbow = 0;
		}
		else
		{
			relbow += 2;
			if (relbow >= 0)flagrelbow = 1;
		}
		if (flaglfoot)                           //左腳
		{
			lfoot += 2;
			if (lfoot >= 20)flaglfoot = 0;
		}
		else
		{
			lfoot -= 2;
			if (lfoot <= -20)flaglfoot = 1;
		}
		if (flaglhips)                            //左小腿
		{
			lhips -= 2;
			if (lhips <= 0)flaglhips = 0;
		}
		else
		{
			lhips += 2;
			if (lhips >= 20)flaglhips = 1;
		}
		if (flagrfoot)                           //右腳
		{
			rfoot -= 2;
			if (rfoot <= -20)flagrfoot = 0;
		}
		else
		{
			rfoot += 2;
			if (rfoot >= 20)flagrfoot = 1;
		}
		if (flagrhips)                           //右小腿
		{
			rhips += 2;
			if (rhips >= 20)flagrhips = 0;
		}
		else
		{
			rhips -= 2;
			if (rhips <= 0)flagrhips = 1;
		}
		glutPostRedisplay();

		break;
		//outter
	case 's':                           //接近移動
		glTranslatef(0.0f, 0.0f, 0.1f);
		if (flaglshoulder)           //左手
		{
			lshoulder += 2;
			if (lshoulder >= 20)flaglshoulder = 0;
		}
		else
		{
			lshoulder -= 2;
			if (lshoulder <= -20)flaglshoulder = 1;
		}
		if (flaglelbow)           //左手腕
		{
			lelbow += 2;
			if (lelbow >= 0)flaglelbow = 0;
		}
		else
		{
			lelbow -= 2;
			if (lelbow <= -20)flaglelbow = 1;
		}

		if (flagrshoulder)                //右手
		{
			rshoulder -= 2;
			if (rshoulder <= -20)flagrshoulder = 0;
		}
		else
		{
			rshoulder += 2;
			if (rshoulder >= 20)flagrshoulder = 1;
		}
		if (flagrelbow)                //右手腕
		{
			relbow -= 2;
			if (relbow <= -20)flagrelbow = 0;
		}
		else
		{
			relbow += 2;
			if (relbow >= 0)flagrelbow = 1;
		}
		if (flaglfoot)                           //左腳
		{
			lfoot += 2;
			if (lfoot >= 20)flaglfoot = 0;
		}
		else
		{
			lfoot -= 2;
			if (lfoot <= -20)flaglfoot = 1;
		}
		if (flaglhips)                            //左小腿
		{
			lhips -= 2;
			if (lhips <= 0)flaglhips = 0;
		}
		else
		{
			lhips += 2;
			if (lhips >= 20)flaglhips = 1;
		}
		if (flagrfoot)                           //右腳
		{
			rfoot -= 2;
			if (rfoot <= -20)flagrfoot = 0;
		}
		else
		{
			rfoot += 2;
			if (rfoot >= 20)flagrfoot = 1;
		}
		if (flagrhips)                           //右小腿
		{
			rhips += 2;
			if (rhips >= 20)flagrhips = 0;
		}
		else
		{
			rhips -= 2;
			if (rhips <= 0)flagrhips = 1;
		}
		glutPostRedisplay();
		break;

	case 'n':                               //n,m旋轉
		angle = (angle + 5) % 360;
		glutPostRedisplay();
		break;
	case 'm':
		angle = (angle - 5) % 360;
		glutPostRedisplay();
		break;
	case '3':                                        //1~9為肢體操做
		if (flagneck)
		{
			neck = neck + 5;
			if (neck >= 30)flagneck = 0;
		}
		else {
			neck = neck - 5;
			if (neck <= -30)flagneck = 1;
		}
		glutPostRedisplay();
		break;
	case '4':
		if (flaglshoulder)
		{
			lshoulder += 5;
			if (lshoulder >= 60)flaglshoulder = 0;
		}
		else
		{
			lshoulder -= 5;
			if (lshoulder <= -60)flaglshoulder = 1;
		}
		glutPostRedisplay();
		break;
	case '5':
		if (flagrshoulder)
		{
			rshoulder += 5;
			if (rshoulder >= 60)flagrshoulder = 0;
		}
		else
		{
			rshoulder -= 5;
			if (rshoulder <= -60)flagrshoulder = 1;
		}
		glutPostRedisplay();
		break;
	case '6':
		if (flaglelbow)
		{
			lelbow += 5;
			if (lelbow >= 60)flaglelbow = 0;
		}
		else
		{
			lelbow -= 5;
			if (lelbow <= -60)flaglelbow = 1;
		}
		glutPostRedisplay();
		break;
	case '7':
		if (flagrelbow)
		{
			relbow += 5;
			if (relbow >= 60)flagrelbow = 0;
		}
		else
		{
			relbow -= 5;
			if (relbow <= -60)flagrelbow = 1;
		}
		glutPostRedisplay();
		break;
	case '8':
		if (flaglhips)
		{
			lhips += 5;
			if (lhips >= 60)flaglhips = 0;
		}
		else
		{
			lhips -= 5;
			if (lhips <= -60)flaglhips = 1;
		}
		glutPostRedisplay();
		break;
	case '9':
		if (flagrhips)
		{
			rhips += 5;
			if (rhips >= 60)flagrhips = 0;
		}
		else
		{
			rhips -= 5;
			if (rhips <= -60)flagrhips = 1;
		}
		glutPostRedisplay();
		break;
	case '1':
		if (flaglfoot)
		{
			lfoot += 5;
			if (lfoot >= 60)flaglfoot = 0;
		}
		else
		{
			lfoot -= 5;
			if (lfoot <= -60)flaglfoot = 1;
		}
		glutPostRedisplay();
		break;
	case '2':
		if (flagrfoot)
		{
			rfoot += 5;
			if (rfoot >= 60)flagrfoot = 0;
		}
		else
		{
			rfoot -= 5;
			if (rfoot <= -60)flagrfoot = 1;
		}
		glutPostRedisplay();
		break;
	case 'h':                                     //走路

		if (flaglshoulder)           //左手
		{
			lshoulder += 2;
			if (lshoulder >= 20)flaglshoulder = 0;
		}
		else
		{
			lshoulder -= 2;
			if (lshoulder <= -20)flaglshoulder = 1;
		}
		if (flaglelbow)           //左手腕
		{
			lelbow += 2;
			if (lelbow >= 0)flaglelbow = 0;
		}
		else
		{
			lelbow -= 2;
			if (lelbow <= -20)flaglelbow = 1;
		}

		if (flagrshoulder)                //右手
		{
			rshoulder -= 2;
			if (rshoulder <= -20)flagrshoulder = 0;
		}
		else
		{
			rshoulder += 2;
			if (rshoulder >= 20)flagrshoulder = 1;
		}
		if (flagrelbow)                //右手腕
		{
			relbow -= 2;
			if (relbow <= -20)flagrelbow = 0;
		}
		else
		{
			relbow += 2;
			if (relbow >= 0)flagrelbow = 1;
		}
		if (flaglfoot)                           //左腳
		{
			lfoot += 2;
			if (lfoot >= 20)flaglfoot = 0;
		}
		else
		{
			lfoot -= 2;
			if (lfoot <= -20)flaglfoot = 1;
		}
		if (flaglhips)                            //左小腿
		{
			lhips -= 2;
			if (lhips <= 0)flaglhips = 0;
		}
		else
		{
			lhips += 2;
			if (lhips >= 20)flaglhips = 1;
		}
		if (flagrfoot)                           //右腳
		{
			rfoot -= 2;
			if (rfoot <= -20)flagrfoot = 0;
		}
		else
		{
			rfoot += 2;
			if (rfoot >= 20)flagrfoot = 1;
		}
		if (flagrhips)                           //右小腿
		{
			rhips += 2;
			if (rhips >= 20)flagrhips = 0;
		}
		else
		{
			rhips -= 2;
			if (rhips <= 0)flagrhips = 1;
		}
		glutPostRedisplay();

		break;
	case 'j':                                     //跑步

		if (flaglshoulder)           //左手
		{
			lshoulder += 5;
			if (lshoulder >= 45)flaglshoulder = 0;
		}
		else
		{
			lshoulder -= 5;
			if (lshoulder <= -45)flaglshoulder = 1;
		}
		if (flaglelbow)           //左手腕
		{
			lelbow += 5;
			if (lelbow >= 0)flaglelbow = 0;
		}
		else
		{
			lelbow -= 5;
			if (lelbow <= -45)flaglelbow = 1;
		}

		if (flagrshoulder)                //右手
		{
			rshoulder -= 5;
			if (rshoulder <= -45)flagrshoulder = 0;
		}
		else
		{
			rshoulder += 5;
			if (rshoulder >= 45)flagrshoulder = 1;
		}
		if (flagrelbow)                //右手腕
		{
			relbow -= 5;
			if (relbow <= -45)flagrelbow = 0;
		}
		else
		{
			relbow += 5;
			if (relbow >= 0)flagrelbow = 1;
		}
		if (flaglfoot)                           //左腳
		{
			lfoot += 5;
			if (lfoot >= 45)flaglfoot = 0;
		}
		else
		{
			lfoot -= 5;
			if (lfoot <= -45)flaglfoot = 1;
		}
		if (flaglhips)                            //左小腿
		{
			lhips -= 5;
			if (lhips <= 0)flaglhips = 0;
		}
		else
		{
			lhips += 5;
			if (lhips >= 45)flaglhips = 1;
		}
		if (flagrfoot)                           //右腳
		{
			rfoot -= 5;
			if (rfoot <= -45)flagrfoot = 0;
		}
		else
		{
			rfoot += 5;
			if (rfoot >= 45)flagrfoot = 1;
		}
		if (flagrhips)                           //右小腿
		{
			rhips += 5;
			if (rhips >= 45)flagrhips = 0;
		}
		else
		{
			rhips -= 5;
			if (rhips <= 0)flagrhips = 1;
		}
		glutPostRedisplay();

		break;
	default:
		break;
	}
}
void processMenuEvents(int option)      //main menu
{
	switch (option)
	{
	case 0:
		exit(1);
		break;
	case 1:
		lshoulder = 0;
		rshoulder = 0;
		lelbow = 0;
		relbow = 0;
		lhips = 0;
		rhips = 0;
		lfoot = 0;
		rfoot = 0;
		break;
	case 2:
		;
		break;
	case 6:
		glEnable(GL_LIGHT0);
		;
		break;
	case 7:
		glDisable(GL_LIGHT0);
		;
		break;
	case 8:
		glEnable(GL_LIGHT1);
		;
		break;
	case 9:
		glDisable(GL_LIGHT1);
		;
		break;
	}
	glutPostRedisplay();
}
void createGLUTMenus()
{
	int menu, subMenu, Mainlight, sublight;


	Mainlight = glutCreateMenu(processMenuEvents);
	glutAddMenuEntry(" ON ", 6);
	glutAddMenuEntry(" OFF", 7);

	sublight = glutCreateMenu(processMenuEvents);
	glutAddMenuEntry(" ON ", 8);
	glutAddMenuEntry(" OFF", 9);
	

	menu = glutCreateMenu(processMenuEvents);
	
	glutAddMenuEntry("Stand", 1);
	glutAddSubMenu("Mainlight", Mainlight);
	glutAddSubMenu("sublight", sublight);
	//glutAddMenuEntry("walk", 2);
	glutAddMenuEntry("Exit", 0);

	glutAttachMenu(GLUT_RIGHT_BUTTON);


}
/*
void mousecontrol (GLint button, GLint state, GLint x, GLint y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		oldx = x;
		oldy = y;
	}

	display();
}

void motioncontrol(int x, int y) {
	u += oldx - x;
	v += oldy - y;
	oldx = x;
	oldy = y;
	glutPostRedisplay();
}
*/


int main(int argc, char** argv)
{
	printf("按键’w’,'a',’s’,'d'為向前，向左，接近，向右行走\n");
	printf("按键’q’,'e'為向上，向下\n");
	printf("按键’n’,’m’為整体旋转\n");
	printf("按键’h’為行走\n");
	printf("按键’j’為跑\n");
	printf("按键’1’~’9’為肢體動作\n");

	
	
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RED);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(argv[0]);
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	//glutMouseFunc(mousecontrol);
	//glutMotionFunc(motioncontrol);

	createGLUTMenus();
	glutMainLoop();
	return 0;
}
