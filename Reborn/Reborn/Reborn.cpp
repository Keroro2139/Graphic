#include <stdlib.h>
#include <stdio.h>
#include <gl/glut.h>
#include<math.h>
#define PI 3.14
float left = 0, up = 0, lx = 0.11, rx = 3.06, by = 0.05, ty = 0.05, angle = 0;
bool target = false;
void Ellipse(double r1, double r2){
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++) {
		glVertex2f(cos(i*PI / 180)*r1, sin(i*PI / 180)*r2);
	}
	glEnd();
}
void BorderEllipse(double r1, double r2){
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < 360; i++) {
		glVertex2f(cos(i*PI / 180)*r1, sin(i*PI / 180)*r2);
	}
	glEnd();
}
void Curve(GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2, GLdouble x3, GLdouble y3, GLdouble x4, GLdouble y4){
	glBegin(GL_LINE_STRIP);
	for (double i = 0; i < 1; i += 0.001){
		glVertex2f((pow(i, 0) * pow(1 - i, 3) * x1) + (3 * pow(i, 1) * pow(1 - i, 2) * x2) + (3 * pow(i, 2) * pow(1 - i, 1) * x3) + (pow(i, 3) * x4),
			(pow(i, 0) * pow(1 - i, 3) * y1) + (3 * pow(i, 1) * pow(1 - i, 2) * y2) + (3 * pow(i, 2) * pow(1 - i, 1) * y3) + (pow(i, 3) * y4));
	}
	glEnd();
}
class Point{
public:
	float x;
	float y;
};
void Fill(GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2, GLdouble x3, GLdouble y3, GLdouble x4, GLdouble y4){
	Point a[1000];
	int r = 0;
	for (double i = 0; i < 1; i += 0.001, r++)
	{
		a[r].x = (pow(i, 0) * pow(1 - i, 3) * x1) + (3 * pow(i, 1) * pow(1 - i, 2) * x2) + (3 * pow(i, 2) * pow(1 - i, 1) * x3) + (pow(i, 3) * x4);
		a[r].y = (pow(i, 0) * pow(1 - i, 3) * y1) + (3 * pow(i, 1) * pow(1 - i, 2) * y2) + (3 * pow(i, 2) * pow(1 - i, 1) * y3) + (pow(i, 3) * y4);
	}
	glBegin(GL_TRIANGLE_FAN);
	for (int i = 0; i < 1000; i++)
		glVertex2f(a[i].x, a[i].y);
	glEnd();
}
void FillHat(){
	glBegin(GL_TRIANGLES);
	glVertex2f(0.25, 2.6); //6
	glVertex2f(0.28, 3.75); //1
	glVertex2f(1.05, 3.49); //2
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex2f(0.25, 2.6); //6
	glVertex2f(1.05, 3.49); //2
	glVertex2f(1.5, 3.56); //3
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex2f(0.25, 2.6); //6
	glVertex2f(2.31, 3.07); //5
	glVertex2f(1.5, 3.56); //3
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex2f(1.5, 3.56); //3
	glVertex2f(2.02, 3.92); //4
	glVertex2f(2.31, 3.07); //5
	glEnd();

}
void FillShadow(){
	glBegin(GL_TRIANGLE_STRIP);
	glVertex2f(1.98, 3.38);
	glVertex2f(2.08, 2.94);
	glVertex2f(1.74, 3.16);
	glVertex2f(1.46, 3.2);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex2f(1.46, 3.2);
	glVertex2f(0.5, 2.5);
	glVertex2f(1.15, 3.07);
	glEnd();
}
void Hat(){
	//Hat
	//»Õ¡ËÁÇ¡
	glColor3f(0.38555, 0.35, 0.35);//gray
	Curve(0.33, 2.24, 0.12, 2.12, 0.16, 2.14, 0.11, 2.06);
	Fill(0.33, 2.24, 0.12, 2.12, 0.16, 2.14, 0.11, 2.06);
	Curve(0.11, 2.06, 0.3, 1.5, 1.1, 0.8, 3.06, 2.74);
	Fill(0.11, 2.06, 0.3, 1.5, 1.1, 0.8, 3.06, 2.74);
	Curve(3.06, 2.74, 2.94, 2.82, 2.78, 2.83, 2.42, 2.84);
	Fill(3.06, 2.74, 2.94, 2.82, 2.78, 2.83, 2.42, 2.84);
	glBegin(GL_QUADS);
	glVertex2f(0.33, 2.24);
	glVertex2f(2.42, 2.84);
	glVertex2f(3.06, 2.74);
	glVertex2f(0.11, 2.06);
	glEnd();
	glColor3f(0, 0, 0);//Black à§Ò
	Curve(0.34, 2.18, 0.24, 2.1, 0.21, 2.06, 0.21, 2.02);
	Fill(0.34, 2.18, 0.24, 2.1, 0.21, 2.06, 0.21, 2.02);
	Curve(0.21, 2.02, 0.44, 1.44, 1.2, 0.9, 2.91, 2.73);
	Fill(0.21, 2.02, 0.44, 1.44, 1.2, 0.9, 2.91, 2.73);
	Curve(2.91, 2.73, 2.8, 2.75, 2.64, 2.77, 2.44, 2.77);
	Fill(2.91, 2.73, 2.8, 2.75, 2.64, 2.77, 2.44, 2.77);
	glBegin(GL_QUADS);
	glVertex2f(0.34, 2.18);
	glVertex2f(0.21, 2.02);
	glVertex2f(2.91, 2.73);
	glVertex2f(2.44, 2.77);
	glEnd();

	glColor3f(1, 0.7, 0.4);//light orange
	glBegin(GL_QUADS);
	glVertex2f(0.25, 2.6);
	glVertex2f(2.31, 3.07);
	glVertex2f(2.51, 2.6);
	glVertex2f(0.42, 1.94);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(0.42, 1.94);
	glVertex2f(2.51, 2.6);
	glEnd();

	glColor3f(0.38555, 0.35, 0.35);//gray
	Curve(0.28, 3.75, 0.15, 3.4, 0.15, 3.3, 0.25, 2.6);
	Fill(0.28, 3.75, 0.15, 3.4, 0.15, 3.3, 0.25, 2.6);
	Curve(0.28, 3.72, 0.5, 3.75, 0.9, 3.6, 1.05, 3.49);
	Fill(0.28, 3.72, 0.5, 3.75, 0.9, 3.6, 1.05, 3.49);
	Curve(1.05, 3.49, 1.2, 3.56, 1.34, 3.58, 1.5, 3.56);
	Fill(1.05, 3.49, 1.2, 3.56, 1.34, 3.58, 1.5, 3.56);
	Curve(1.5, 3.56, 1.7, 3.72, 1.9, 3.86, 2.02, 3.92);
	Fill(1.5, 3.56, 1.7, 3.72, 1.9, 3.86, 2.02, 3.92);
	Curve(2.02, 3.92, 2.2, 3.6, 2.26, 3.36, 2.31, 3.07);
	Fill(2.02, 3.92, 2.2, 3.6, 2.26, 3.36, 2.31, 3.07);
	Curve(0.25, 2.6, 0.5, 2.44, 0.9, 2.3, 2.31, 3.07);
	Fill(0.25, 2.6, 0.5, 2.4, 0.9, 2.3, 2.31, 3.07);
	FillHat();

	glColor3f(1, 0.7, 0.4);//light orange
	Curve(0.25, 2.6, 0.28, 2.36, 0.36, 2.04, 0.42, 1.94);
	Fill(0.25, 2.6, 0.28, 2.36, 0.36, 2.04, 0.42, 1.94);
	Curve(0.42, 1.94, 0.74, 1.68, 1.5, 1.76, 2.51, 2.6);
	Fill(0.42, 1.94, 0.74, 1.68, 1.5, 1.76, 2.51, 2.6);
	Curve(2.51, 2.6, 2.46, 2.76, 2.38, 2.94, 2.31, 3.07);
	Fill(2.51, 2.6, 2.46, 2.76, 2.38, 2.94, 2.31, 3.07);

	//Hat Shadow
	glColor3f(1, 0.4, 0.2);//orange
	Curve(0.5, 2.5, 0.54, 2.26, 0.62, 2, 0.7, 1.82);
	Fill(0.5, 2.5, 0.54, 2.26, 0.62, 2, 0.7, 1.82);
	Curve(0.7, 1.82, 0.8, 1.72, 1.5, 1.76, 2.3, 2.44);
	Fill(0.7, 1.82, 0.8, 1.72, 1.5, 1.76, 2.3, 2.44);
	Curve(2.3, 2.44, 2.28, 2.52, 2.2, 2.68, 2.11, 2.72);
	Fill(2.3, 2.44, 2.28, 2.52, 2.2, 2.68, 2.11, 2.72);
	Curve(2.11, 2.72, 2.14, 2.8, 2.14, 2.88, 2.08, 2.95);
	Fill(2.11, 2.72, 2.14, 2.8, 2.14, 2.88, 2.08, 2.95);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex2f(0.5, 2.5);
	glVertex2f(2.08, 2.95);
	glVertex2f(0.7, 1.82);
	glVertex2f(2.11, 2.72);
	glVertex2f(2.3, 2.44);
	glEnd();

	glColor3f(0, 0, 0);//black
	Curve(0.5, 2.5, 0.46, 2.66, 0.44, 2.8, 0.46, 3.05);
	Fill(0.5, 2.5, 0.46, 2.66, 0.44, 2.8, 0.46, 3.05);
	glBegin(GL_TRIANGLES);
	glVertex2f(0.5, 2.5);
	glVertex2f(0.46, 3.05);
	glVertex2f(1.15, 3.07);
	glEnd();
	Curve(0.46, 3.05, 0.6, 3.04, 0.94, 3.04, 1.15, 3.07);
	Fill(0.46, 3.05, 0.6, 3.04, 0.94, 3.04, 1.15, 3.07);
	glBegin(GL_LINES);
	glVertex2f(1.15, 3.07);
	glVertex2f(0.6, 3.37);
	glEnd();
	glBegin(GL_QUADS);
	glVertex2f(0.6, 3.37);
	glVertex2f(1.32, 3.41);
	glVertex2f(1.46, 3.2);
	glVertex2f(1.15, 3.07);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex2f(1.32, 3.41);
	glVertex2f(1.46, 3.2);
	glVertex2f(1.74, 3.6);
	glEnd();
	Curve(0.6, 3.37, 1, 3.4, 1.2, 3.4, 1.32, 3.41);
	Fill(0.6, 3.37, 1, 3.4, 1.2, 3.4, 1.32, 3.41);
	Curve(1.32, 3.41, 1.48, 3.5, 1.64, 3.58, 1.74, 3.6);
	Fill(1.32, 3.41, 1.48, 3.5, 1.64, 3.58, 1.74, 3.6);
	Curve(1.74, 3.6, 1.64, 3.46, 1.54, 3.32, 1.46, 3.2);
	Fill(1.74, 3.6, 1.64, 3.46, 1.54, 3.32, 1.46, 3.2);
	Curve(1.46, 3.2, 1.58, 3.18, 1.7, 3.18, 1.74, 3.16);
	Fill(1.46, 3.2, 1.58, 3.18, 1.7, 3.18, 1.74, 3.16);
	Curve(1.74, 3.16, 1.84, 3.22, 1.92, 3.3, 1.98, 3.38);
	Fill(1.74, 3.16, 1.84, 3.22, 1.92, 3.3, 1.98, 3.38);
	Curve(1.98, 3.38, 2.04, 3.26, 2.08, 3.1, 2.08, 2.94);
	Fill(1.98, 3.38, 2.04, 3.26, 2.08, 3.1, 2.08, 2.94);
	FillShadow();
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(1.46, 3.2);
	glVertex2f(2.08, 2.94);
	glVertex2f(0.5, 2.5);
	glEnd();
	Fill(0.5, 2.5, 0.5, 2.44, 0.9, 2.3, 2.08, 2.94);
	Fill(0.5, 2.5, 0.46, 2.86, 0.6, 2.78, 1.15, 3.07);
	glBegin(GL_TRIANGLES);
	glVertex2f(0.46, 3.05);
	glVertex2f(0.76, 2.48);
	glVertex2f(0.5, 2.5);
	glEnd();
}
void Face(){
	//left hairs
	glColor3f(0, 0, 0);//black
	glBegin(GL_QUADS);
	glVertex2f(0.47, 1.62);
	glVertex2f(0.67, 1.538);
	glVertex2f(0.85, 1.23);
	glVertex2f(0.56, 1.5);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex2f(0.45, 1.5);
	glVertex2f(0.56, 1.5);
	glVertex2f(0.85, 1.23);
	glEnd();
	//right hairs
	glColor3f(0.179804, 0.179804, 0.179804); //dark gray
	Curve(2.74, 2.43, 2.76, 2.3, 2.66, 2.12, 2.64, 2.06);
	Fill(2.74, 2.43, 2.76, 2.3, 2.66, 2.12, 2.64, 2.06);
	glBegin(GL_LINES);
	glVertex2f(2.64, 2.06);
	glVertex2f(2.8, 2.13);
	glEnd();
	Curve(2.8, 2.13, 2.8, 2.04, 2.74, 1.94, 2.66, 1.88);
	Fill(2.8, 2.13, 2.8, 2.04, 2.74, 1.94, 2.66, 1.88);
	glBegin(GL_LINE_LOOP);
	glVertex2f(2.66, 1.88);
	glVertex2f(2.76, 1.88);
	glVertex2f(2.665, 1.81);
	glEnd();
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(2.76, 1.88);
	glVertex2f(2.66, 1.88);
	glVertex2f(2.665, 1.81);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex2f(2.665, 1.81);
	glVertex2f(2.75, 1.81);
	glVertex2f(2.63, 1.66);
	glEnd();

	glBegin(GL_TRIANGLE_STRIP);
	glVertex2f(2.07, 1.9);
	glVertex2f(2.74, 2.43);
	glVertex2f(2.4, 1.7);
	glVertex2f(2.64, 2.06);
	glVertex2f(2.8, 2.13);
	glEnd();

	glBegin(GL_TRIANGLE_STRIP);
	glVertex2f(2.8, 2.13);
	glVertex2f(2.4, 1.7);
	glVertex2f(2.66, 1.88);
	glEnd();

	glBegin(GL_QUADS);
	glVertex2f(2.4, 1.7);
	glVertex2f(2.66, 1.88);
	glVertex2f(2.76, 1.88);
	glVertex2f(2.63, 1.66);
	glEnd();

	//face
	glColor3f(1, 0.894118, 0.709804);//Moccasin
	Curve(0.67, 1.538, 0.71, 1.44, 0.78, 1.34, 0.85, 1.23);
	Fill(0.67, 1.538, 0.71, 1.44, 0.78, 1.34, 0.85, 1.23);
	Curve(0.85, 1.25, 0.88, 1.12, 0.7, 1, 0.86, 0.96);
	Fill(0.85, 1.25, 0.88, 1.12, 0.7, 1, 0.86, 0.96);
	Curve(0.86, 0.96, 1.56, 0.8, 2.06, 1.04, 2.4, 1.47);
	Fill(0.86, 0.96, 1.56, 0.8, 2.06, 1.04, 2.4, 1.47);
	Curve(2.4, 1.7, 2.3, 1.82, 2.18, 1.88, 2.07, 1.9);
	Fill(2.4, 1.7, 2.3, 1.82, 2.18, 1.88, 2.07, 1.9);
	//Right Ear
	Curve(2.4, 1.47, 2.52, 1.5, 2.6, 1.58, 2.63, 1.66);
	Fill(2.4, 1.47, 2.52, 1.5, 2.6, 1.58, 2.63, 1.66);
	Curve(2.63, 1.66, 2.66, 1.76, 2.56, 1.88, 2.5, 1.84);
	Fill(2.63, 1.66, 2.66, 1.76, 2.56, 1.88, 2.5, 1.84);
	Curve(2.5, 1.84, 2.44, 1.84, 2.4, 1.8, 2.4, 1.7);
	Fill(2.5, 1.84, 2.4, 1.84, 2.4, 1.76, 2.4, 1.7);

	glColor3f(1, 0.894118, 0.709804);//Moccasin
	//Left Ear
	Curve(0.75, 1.3, 0.68, 1.28, 0.74, 1.16, 0.82, 1.14);
	Fill(0.75, 1.3, 0.68, 1.28, 0.74, 1.16, 0.82, 1.14);
	glBegin(GL_TRIANGLES);
	glVertex2f(0.85, 1.23);
	glVertex2f(0.75, 1.3);
	glVertex2f(0.82, 1.14);
	glEnd();

	glBegin(GL_QUAD_STRIP);
	glVertex2f(2.07, 1.9);
	glVertex2f(0.67, 1.538);
	glVertex2f(2.4, 1.7);
	glVertex2f(0.85, 1.23);
	glVertex2f(2.4, 1.47);
	glVertex2f(0.86, 0.96);
	glEnd();
	glBegin(GL_QUADS);
	glVertex2f(2.4, 1.7);
	glVertex2f(2.5, 1.84);
	glVertex2f(2.63, 1.66);
	glVertex2f(2.4, 1.47);
	glEnd();

	glPushMatrix();
	glTranslatef(0.98, 1.47, 0);
	glRotated(15, 0, 0, 1);
	glColor3f(0, 0, 0);//black
	Ellipse(0.15, 0.3);//Left Eye Black
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.079, 1.48, 0);
	glRotated(15, 0, 0, 1);
	glColor3f(1, 1, 1);//white
	Ellipse(0.05, 0.14);//Left Eye White
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.8, 1.6, 0);
	glRotated(75, 0, 0, 1);
	glColor3f(0, 0, 0);//black
	Ellipse(0.22, 0.3);//Rigt Eye Black
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.88, 1.74, 0);
	glRotated(65, 0, 0, 1);
	glColor3f(1, 1, 1);//white
	Ellipse(0.07, 0.14);//Right Eye White
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1, 1, 0);
	glColor3f(0.980392, 0.501961, 0.447059);//Salmon
	Ellipse(0.14, 0.04);//á¡éÁ«éÒÂ
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2.14, 1.35, 0);
	glRotated(35, 0, 0, 1);
	glColor3f(0.980392, 0.501961, 0.447059);//Salmon
	Ellipse(0.13, 0.035);//á¡éÁ¢ÇÒ
	glPopMatrix();

	glColor3f(0, 0, 0);//black
	Curve(1.24, 1.2, 1.2, 1.2, 1.2, 1.16, 1.24, 1.14);//¨ÁÙ¡

	//mouse
	Curve(1.58, 1.15, 1.54, 1.06, 1.28, 1.12, 1.24, 1.04);
	Curve(1.24, 1.04, 1.18, 1.04, 1.18, 1.08, 1.218, 1.07);

	glColor3f(0, 0, 0);//Black
	Curve(2.53, 1.77, 2.5, 1.74, 2.47, 1.7, 2.46, 1.66);//detail ËÙ¢ÇÒ
	Curve(2.45, 1.66, 2.54, 1.68, 2.54, 1.58, 2.46, 1.56);

	glColor3f(0.179804, 0.179804, 0.179804); //dark gray ¨Í¹
	glBegin(GL_TRIANGLES);
	glVertex2f(2.4, 1.8);
	glVertex2f(2.43, 1.5);
	glVertex2f(2.32, 1.8);
	glEnd();

	glColor3f(0, 0, 0);//black
	//Ë¹Ç´¢ÇÒ
	Curve(2.43, 1.54, 2.5, 1.26, 2.46, 1.14, 2.34, 1.18);
	Curve(2.34, 1.18, 2.22, 1.34, 2.2, 1.56, 2.29, 1.69);
	Curve(2.29, 1.69, 2.34, 1.58, 2.4, 1.42, 2.36, 1.29);
	Curve(2.36, 1.29, 2.3, 1.32, 2.28, 1.42, 2.32, 1.48);
	//Ë¹Ç´¢ÇÒ
	Curve(0.81, 1.01, 0.54, 0.76, 0.32, 0.82, 0.38, 1);
	Curve(0.38, 1, 0.4, 1.16, 0.52, 1.32, 0.6, 1.34);
	Curve(0.6, 1.34, 0.72, 1.24, 0.66, 1.02, 0.54, 0.96);
	Curve(0.54, 0.96, 0.46, 1, 0.52, 1.14, 0.58, 1.18);
}
void Jooknom() {
	glColor3f(1, 1, 0.878); // Light Yellow
	Fill(1.88, 1.14, 1.98, 1.18, 2.06, 1.12, 2.04, 1.04);
	Fill(1.73, 0.87, 1.74, 0.78, 1.82, 0.74, 1.9, 0.78);
	glBegin(GL_QUADS);
	glVertex2f(1.73, 0.87);
	glVertex2f(1.88, 1.14);
	glVertex2f(2.04, 1.04);
	glVertex2f(1.9, 0.78);
	glEnd();

	glColor3f(0, 0, 0);//black
	glBegin(GL_LINES);
	glVertex2f(1.73, 0.87);
	glVertex2f(1.88, 1.14);
	glEnd();
	Curve(1.88, 1.14, 1.98, 1.18, 2.06, 1.12, 2.04, 1.04);
	Curve(1.73, 0.87, 1.74, 0.78, 1.82, 0.74, 1.9, 0.78);

	glColor3f(1, 1, 0.878); // Light Yellow
	glPushMatrix();
	glTranslatef(2.06, 0.82, 0);
	Ellipse(0.22, 0.22);
	glColor3f(0, 0, 0);//black
	BorderEllipse(0.22, 0.22);
	glColor3f(0.941, 0.902, 0.549); // Khaki
	Ellipse(0.09, 0.09);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1, 1, 1); // White
	glTranslatef(2.08, 0.9, 0);
	Ellipse(0.07, 0.07);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1, 1, 1); // White
	glTranslatef(2.08, 0.8, 0);
	Ellipse(0.02, 0.02);
	glPopMatrix();
}
void Gun() {
	glColor3f(0.184, 0.310, 0.310);//DarkSlateGray
	glBegin(GL_LINE_LOOP);
	glVertex2f(1.32, 0.9);
	glVertex2f(1.32, 0.8);
	glVertex2f(1.34, 0.79);
	glVertex2f(1.34, 0.74);
	glVertex2f(1.36, 0.74);
	glVertex2f(1.36, 0.64);
	glVertex2f(1.41, 0.64);
	glVertex2f(1.42, 0.74);
	glVertex2f(1.44, 0.74);
	glVertex2f(1.46, 0.76);
	glVertex2f(1.5, 0.78);
	glVertex2f(1.5, 0.86);
	glEnd();
	glBegin(GL_QUADS);
	glVertex2f(1.36, 0.74);
	glVertex2f(1.36, 0.64);
	glVertex2f(1.41, 0.64);
	glVertex2f(1.42, 0.74);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(1.42, 0.74);
	glVertex2f(1.44, 0.74);
	glVertex2f(1.46, 0.76);
	glVertex2f(1.34, 0.79);
	glVertex2f(1.34, 0.74);
	glVertex2f(1.36, 0.74);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(1.46, 0.76);
	glVertex2f(1.5, 0.78);
	glVertex2f(1.5, 0.86);
	glVertex2f(1.32, 0.9);
	glVertex2f(1.32, 0.8);
	glVertex2f(1.34, 0.79);
	glEnd();
	glColor3f(0, 0, 0);
	glBegin(GL_QUADS);
	glVertex2f(1.31, 0.48);
	glVertex2f(1.31, 0.45);
	glVertex2f(1.42, 0.47);
	glVertex2f(1.42, 0.52);
	glEnd();
	glColor3f(0.184, 0.310, 0.310);//DarkSlateGray
	glBegin(GL_QUADS);
	glVertex2f(1.31, 0.45);
	glVertex2f(1.31, 0.42);
	glVertex2f(1.41, 0.42);
	glVertex2f(1.41, 0.47);
	glEnd();

	glColor3f(0.596, 0.984, 0.596); //Pale green
	glPushMatrix();
	glTranslatef(1.46, 0.92, 0);
	Ellipse(0.1, 0.1);
	glColor3f(0, 0, 0); // black
	Ellipse(0.05, 0.05);
	glPopMatrix();

	glColor3f(0.596, 0.984, 0.596); //Pale green
	glBegin(GL_QUADS);
	glVertex2f(1.36, 0.86);
	glVertex2f(1.38, 0.8);
	glVertex2f(1.45, 0.8);
	glVertex2f(1.46, 0.84);
	glEnd();
}
void Body() {
	glColor3f(1, 0.894118, 0.709804);//Moccasin right hand
	Curve(2.53, 1.36, 2.54, 1.42, 2.55, 1.44, 2.56, 1.48);
	Fill(2.53, 1.36, 2.54, 1.42, 2.55, 1.44, 2.56, 1.48);
	Curve(2.56, 1.48, 2.58, 1.48, 2.59, 1.47, 2.6, 1.46);
	Fill(2.56, 1.48, 2.58, 1.48, 2.59, 1.47, 2.6, 1.46);
	glBegin(GL_LINES);
	glVertex2f(2.6, 1.46);
	glVertex2f(2.6, 1.52);
	glEnd();
	Curve(2.6, 1.52, 2.62, 1.54, 2.64, 1.52, 2.64, 1.5);
	Fill(2.6, 1.52, 2.62, 1.54, 2.64, 1.52, 2.64, 1.5);
	Curve(2.64, 1.5, 2.66, 1.44, 2.63, 1.38, 2.62, 1.34);
	Fill(2.64, 1.5, 2.66, 1.44, 2.63, 1.38, 2.62, 1.34);
	Curve(2.62, 1.34, 2.66, 1.36, 2.68, 1.36, 2.72, 1.32);
	Fill(2.62, 1.34, 2.66, 1.36, 2.68, 1.36, 2.72, 1.32);
	glBegin(GL_LINES);
	glVertex2f(2.72, 1.32);
	glVertex2f(2.53, 1.24);
	glEnd();
	glBegin(GL_TRIANGLE_STRIP);
	glVertex2f(2.53, 1.36);
	glVertex2f(2.56, 1.48);
	glVertex2f(2.6, 1.46);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(2.53, 1.36);
	glVertex2f(2.6, 1.46);
	glVertex2f(2.6, 1.52);
	glVertex2f(2.64, 1.5);
	glVertex2f(2.62, 1.34);
	glVertex2f(2.53, 1.24);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex2f(2.62, 1.34);
	glVertex2f(2.72, 1.32);
	glVertex2f(2.53, 1.24);
	glEnd();

	glColor3f(0.545, 0.000, 0.000);//DarkRed
	glBegin(GL_QUADS);
	glVertex2f(2.5, 1.34);
	glVertex2f(2.52, 1.36);
	glVertex2f(2.53, 1.25);
	glVertex2f(2.48, 1.22);
	glEnd();

	glColor3f(0, 0, 0); //black
	Curve(2.06, 1.2, 2.16, 1.24, 2.26, 1.28, 2.34, 1.28);
	Fill(2.06, 1.2, 2.16, 1.24, 2.26, 1.28, 2.34, 1.28);
	glBegin(GL_QUADS);
	glVertex2f(2.34, 1.28);
	glVertex2f(2.5, 1.36);
	glVertex2f(2.48, 1.2);
	glVertex2f(2.16, 1.02);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(2.06, 1.2);
	glVertex2f(2.34, 1.28);
	glVertex2f(2.16, 1.02);
	glVertex2f(2, 1);
	glVertex2f(2, 1.2);
	glEnd();

	glBegin(GL_QUADS);
	glVertex2f(2.26, 0.84);
	glVertex2f(2.36, 0.8);
	glVertex2f(2.16, 0.56);
	glVertex2f(2.06, 0.58);
	glEnd();
	Curve(2.36, 0.8, 2.32, 0.68, 2.24, 0.6, 2.16, 0.56);
	Fill(2.36, 0.8, 2.32, 0.68, 2.24, 0.6, 2.16, 0.56);
	glBegin(GL_QUADS); 
	glVertex2f(2.06, 0.58);
	glVertex2f(2.02, 0.46);
	glVertex2f(1.8, 0.54);
	glVertex2f(1.66, 0.8);
	glEnd();
	glBegin(GL_QUADS);
	glVertex2f(1.66, 0.8);
	glVertex2f(1.53, 0.72);
	glVertex2f(1.34, 0.74);
	glVertex2f(1.52, 0.95);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(2.06, 0.58);
	glVertex2f(1.66, 0.8);
	glVertex2f(1.52, 0.95);
	glVertex2f(1.86, 1.1);
	glVertex2f(2.36, 0.8);
	glEnd();

	glColor3f(1, 0.894118, 0.709804);//Moccasin left 
	Fill(1.46, 0.76, 1.56, 0.74, 1.54, 0.64, 1.48, 0.62);
	Fill(1.48, 0.62, 1.44, 0.64, 1.45, 0.68, 1.48, 0.71);
	Fill(1.28, 0.7, 1.32, 0.76, 1.46, 0.72, 1.43, 0.65);
	Fill(1.43, 0.65, 1.5, 0.62, 1.5, 0.58, 1.46, 0.58);
	Fill(1.46, 0.58, 1.48, 0.54, 1.4, 0.52, 1.34, 0.54);
	Fill(1.38, 0.54, 1.4, 0.5, 1.36, 0.46, 1.28, 0.5);
	Fill(1.28, 0.5, 1.27, 0.52, 1.28, 0.54, 1.3, 0.56);
	Fill(1.3, 0.56, 1.26, 0.58, 1.26, 0.64, 1.3, 0.66);
	Fill(1.3, 0.66, 1.26, 0.68, 1.26, 0.72, 1.28, 0.7);
	glBegin(GL_POLYGON);
	glVertex2f(1.28, 0.7);
	glVertex2f(1.43, 0.65);
	glVertex2f(1.46, 0.58);
	glVertex2f(1.34, 0.54);
	glVertex2f(1.3, 0.66);
	glEnd();
	glBegin(GL_QUADS);
	glVertex2f(1.34, 0.54);
	glVertex2f(1.28, 0.5);
	glVertex2f(1.3, 0.56);
	glVertex2f(1.3, 0.66);
	glEnd();

	glColor3f(0, 0, 0); //black
	Curve(1.46, 0.76, 1.56, 0.74, 1.54, 0.64, 1.48, 0.62);
	Curve(1.48, 0.62, 1.44, 0.64, 1.45, 0.68, 1.48, 0.71);
	Curve(1.28, 0.7, 1.32, 0.76, 1.46, 0.72, 1.43, 0.65);
	Curve(1.43, 0.65, 1.5, 0.62, 1.5, 0.58, 1.46, 0.58);
	Curve(1.46, 0.58, 1.48, 0.54, 1.4, 0.52, 1.34, 0.54);
	Curve(1.38, 0.54, 1.4, 0.5, 1.36, 0.46, 1.28, 0.5);
	Curve(1.28, 0.5, 1.27, 0.52, 1.28, 0.54, 1.3, 0.56);
	Curve(1.3, 0.56, 1.26, 0.58, 1.26, 0.64, 1.3, 0.66);
	Curve(1.3, 0.66, 1.26, 0.68, 1.26, 0.72, 1.28, 0.7);

	glColor3f(0.38555, 0.35, 0.35);//gray
	Curve(2.36, 0.8, 2.32, 0.68, 2.24, 0.6, 2.16, 0.56);
	glBegin(GL_LINES);
	glVertex2f(2.16, 0.56);
	glVertex2f(2.06, 0.58);
	glVertex2f(2.06, 0.58);
	glVertex2f(2.02, 0.46);
	glVertex2f(1.6, 0.98);
	glVertex2f(1.6, 0.92);
	glVertex2f(1.6, 0.92);
	glVertex2f(1.66, 0.94);
	glVertex2f(1.66, 0.94);
	glVertex2f(1.64, 0.86);
	glVertex2f(1.64, 0.86);
	glVertex2f(1.72, 0.88);
	glEnd();
	glColor3f(0.804, 0.361, 0.361); //IndienRed
	glBegin(GL_TRIANGLES);
	glVertex2f(1.64, 1);
	glVertex2f(1.74, 0.86);
	glVertex2f(1.88, 1.12);
	glEnd();

	glColor3f(0.000, 0.000, 0.804); //mediumblue
	glBegin(GL_POLYGON);
	glVertex2f(1.69, 1.2);
	glVertex2f(1.73, 1.03);
	glVertex2f(1.76, 1);
	glVertex2f(1.76, 0.96);
	glVertex2f(1.72, 0.96);
	glVertex2f(1.69, 0.96);
	glEnd();

	glColor3f(0, 0, 0);//black
	glBegin(GL_LINES);
	glVertex2f(1.69, 1.2);
	glVertex2f(1.68, 0.92);
	glVertex2f(1.73, 1.03);
	glVertex2f(1.8, 0.98);
	glEnd();

}
void Pants() {
	//left pants
	glColor3f(0, 0, 0); // black
	glBegin(GL_QUADS);
	glVertex2f(1.94, 0.48);
	glVertex2f(2.52, 0.16);
	glVertex2f(2.52, 0.16);
	glVertex2f(2.56, 0.3);
	glEnd();
	Curve(2.56, 0.3, 2.52, 0.34, 2.48, 0.36, 2.42, 0.38);
	Fill(2.56, 0.3, 2.52, 0.34, 2.48, 0.36, 2.42, 0.38);
	glBegin(GL_LINES);
	glVertex2f(2.42, 0.38);
	glVertex2f(2.35, 0.45);
	glEnd();
	glBegin(GL_TRIANGLE_STRIP);
	glVertex2f(2.52, 0.16);
	glVertex2f(2.56, 0.3);
	glVertex2f(2.42, 0.38);
	glEnd();
	glBegin(GL_QUADS);
	glVertex2f(1.94, 0.48);
	glVertex2f(2.1, 0.7);
	glVertex2f(2.35, 0.45);
	glVertex2f(2.52, 0.16);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(2.55, 0.18);
	glVertex2f(2.6, 0.14);
	glEnd();
	Curve(2.6, 0.14, 2.6, 0.08, 2.66, 0.04, 2.72, 0.07);
	Fill(2.6, 0.14, 2.6, 0.08, 2.66, 0.04, 2.72, 0.07);
	Curve(2.72, 0.07, 2.72, 0.16, 2.66, 0.26, 2.62, 0.3);
	Fill(2.72, 0.07, 2.72, 0.16, 2.66, 0.26, 2.62, 0.3);
	glBegin(GL_LINES);
	glVertex2f(2.62, 0.3);
	glVertex2f(2.56, 0.3);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(2.55, 0.18);
	glVertex2f(2.6, 0.14);
	glVertex2f(2.72, 0.07);
	glVertex2f(2.62, 0.3);
	glVertex2f(2.56, 0.3);
	glEnd();
	glColor3f(0.38555, 0.35, 0.35);//gray
	Curve(2.72, 0.07, 2.74, 0.16, 2.72, 0.2, 2.68, 0.22);
	Fill(2.72, 0.07, 2.74, 0.16, 2.72, 0.2, 2.68, 0.22);

	//right pants
	glColor3f(0.38555, 0.35, 0.35);//gray
	Curve(2.12, 0.52, 2.04, 0.46, 1.96, 0.34, 1.94, 0.24);
	Curve(2.34, 0.72, 2.5, 0.5, 2.28, 0.36, 2.2, 0.32);
	Curve(2.37, 0.06, 2.44, 0.12, 2.44, 0.2, 2.38, 0.24);
	Fill(2.37, 0.06, 2.44, 0.12, 2.44, 0.2, 2.38, 0.24);
	Curve(2.38, 0.25, 2.41, 0.28, 2.4, 0.32, 2.36, 0.34);
	Fill(2.38, 0.25, 2.41, 0.28, 2.4, 0.32, 2.36, 0.34);
	glColor3f(0, 0, 0); // black
	Fill(2.12, 0.52, 2.04, 0.46, 1.96, 0.34, 1.94, 0.24);
	Curve(1.94, 0.24, 2, 0.2, 2.1, 0.18, 2.18, 0.22);
	Fill(1.94, 0.24, 2, 0.2, 2.1, 0.18, 2.18, 0.22);
	Fill(2.34, 0.72, 2.5, 0.5, 2.28, 0.36, 2.2, 0.32);
	Curve(2.17, 0.2, 2.2, 0.19, 2.26, 0.18, 2.29, 0.18);
	Fill(2.17, 0.2, 2.2, 0.19, 2.26, 0.18, 2.29, 0.18);
	glBegin(GL_LINES);
	glVertex2f(2.29, 0.18);
	glVertex2f(2.27, 0.1);
	glEnd();
	Curve(2.27, 0.1, 2.28, 0.06, 2.34, 0.06, 2.37, 0.06);
	Fill(2.27, 0.1, 2.28, 0.06, 2.34, 0.06, 2.37, 0.06);
	Curve(2.37, 0.06, 2.4, 0.16, 2.4, 0.28, 2.36, 0.34);
	Fill(2.37, 0.06, 2.4, 0.16, 2.4, 0.28, 2.36, 0.34);
	glBegin(GL_LINES);
	glVertex2f(2.36, 0.34);
	glVertex2f(2.24, 0.34);
	glEnd();
	glBegin(GL_QUADS);
	glVertex2f(2.36, 0.34);
	glVertex2f(2.24, 0.34);
	glVertex2f(2.29, 0.18); 
	glVertex2f(2.37, 0.06);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex2f(2.29, 0.18);
	glVertex2f(2.37, 0.06);
	glVertex2f(2.27, 0.1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(2.12, 0.52);
	glVertex2f(1.94, 0.24);
	glVertex2f(2.18, 0.22);
	glVertex2f(2.29, 0.18);
	glVertex2f(2.34, 0.72);
	glEnd();
}
void Reborn() {
	Pants();
	Body();
	glPushMatrix();
	glTranslatef(0, 0.04, 0);
		Face();
		Hat();
		Jooknom();
	glPopMatrix();
	Gun();
}
void Background() {
	glColor3f(1.000, 0.843, 0.000);
	glBegin(GL_QUADS);
	glVertex2f(0, 2.9); 
	glVertex2f(10, 2.9);
	glColor3f(1.000, 0.980, 0.804);
	glVertex2f(14.1, 0);
	glVertex2f(0, 0);
	glEnd();
}
void Window(){
	glColor3f(0, 0, 0);
	glBegin(GL_QUADS);
	glVertex2f(4.1, 6.82);
	glVertex2f(4.1, 4.96);
	glVertex2f(7.76, 4.96);
	glVertex2f(7.76, 6.82);
	glEnd();

	glColor3f(0.000, 1.000, 1.000);
	glBegin(GL_QUADS);
	glVertex2f(4.18, 6.74);
	glVertex2f(4.18, 5.04);
	glVertex2f(7.69, 5.04);
	glVertex2f(7.69, 6.74);
	glEnd();
}
void Table() {
	glColor3f(0.545, 0.271, 0.075); //SaddleBrown
	glBegin(GL_POLYGON);
	glVertex2f(9.5, 2.72);
	glVertex2f(9.6, 2.66);
	glVertex2f(9.6, 2.02);
	glVertex2f(9.56, 2.02);
	glVertex2f(9.5, 2.08);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(10.78, 1.83);
	glVertex2f(10.87, 1.8);
	glVertex2f(10.87, 1.14);
	glVertex2f(10.82, 1.14);
	glVertex2f(10.78, 1.2);
	glEnd();
	glBegin(GL_QUADS);
	glVertex2f(12.44, 1.8);
	glVertex2f(12.49, 1.8);
	glVertex2f(12.49, 1.14);
	glVertex2f(12.44, 1.14);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(9.5, 2.82);
	glVertex2f(9.5, 2.72);
	glVertex2f(10.82, 1.8);
	glVertex2f(12.49, 1.8);
	glVertex2f(12.49, 1.88);
	glVertex2f(11.1, 2.82);
	glEnd();
	glColor3f(1.000, 0.843, 0.000); //Gold
	glBegin(GL_POLYGON);
	glVertex2f(9.5, 2.82);
	glVertex2f(10.82, 1.88);
	glVertex2f(12.49, 1.88);
	glVertex2f(11.1, 2.82);
	glEnd();
}
void baipad()
{
	glBegin(GL_POLYGON);
	glVertex2f(-1, 1);
	glVertex2f(1, 1);
	glVertex2f(1, -1);
	glEnd();
}
void Baipad() {
	glColor3f(0, 0, 0);
	glPointSize(5);
	glRotatef(0, 0, 0, 0);
	glBegin(GL_POINTS);
	glVertex2f(0, 0);
	glEnd();

	glPushMatrix();
	glRotatef(angle, 0, 0, 1);
	glScalef(0.07, 0.3, 1);
	glTranslatef(-1, 1, 0);
	baipad();
	glPopMatrix();

	glPushMatrix();
	glRotatef(angle + 90, 0, 0, 1);
	glScalef(0.07, 0.3, 1);
	glTranslatef(-1, 1, 0);
	baipad();
	glPopMatrix();

	glPushMatrix();
	glRotatef(angle + 180, 0, 0, 1);
	glScalef(0.07, 0.3, 1);
	glTranslatef(-1, 1, 0);
	baipad();
	glPopMatrix();

	glPushMatrix();
	glRotatef(angle + 270, 0, 0, 1);
	glScalef(0.07, 0.3, 1);
	glTranslatef(-1, 1, 0);
	baipad();
	glPopMatrix();
}
void Spin(){
	angle += 7;
	glutPostRedisplay();
}
void BaseOfBaipad() {
	glColor3f(1, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2f(6.6, 6);
	glVertex2f(6.8, 6);
	
	glVertex2f(7, 5.04);
	glVertex2f(6.4, 5.04);
	glEnd();
}
void Target() {
	glColor3f(1, 0, 0);
	glLineWidth(3);

	glPushMatrix();
	glTranslatef(1.46, 0.92, 0);
	BorderEllipse(0.4, 0.4);
	glPopMatrix();

	glBegin(GL_LINES);
	glVertex2f(1.7, 0.92);//right
	glVertex2f(2.1, 0.92);
	glVertex2f(1.2, 0.92);//left
	glVertex2f(0.8, 0.92);
	glVertex2f(1.46, 1.15);//up
	glVertex2f(1.46, 1.5);
	glVertex2f(1.46, 0.68);//down
	glVertex2f(1.46, 0.3);
	glEnd();
}
void Timer(){
	float T = 3000;
	for (int i = 0; i <3001; i++) {
		if (T == 0) {
			target = false;
			glutPostRedisplay();
		}
		else T -= 1;
	}
}
void display(void)
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLineWidth(1);
	glColor3f(0, 0, 0);
	glBegin(GL_LINES);
	glVertex2f(10, 2.9);
	glVertex2f(10, 9);
	glEnd();

	Background();
	glPushMatrix();
	glTranslatef(1.4, 0, 0);
	Window();

	BaseOfBaipad();
	glPushMatrix();
	glTranslatef(6.7, 6, 0);
	Baipad();
	glPopMatrix();
	glPopMatrix();
	
	Table();
	glPushMatrix();
	glTranslatef(left, up, 0);
	Reborn();
	if (target) {
		Target();
		Timer();
	}
	glPopMatrix();
	glutIdleFunc(Spin);
	glutSwapBuffers(); 
}
void SpecialKeyboard(int key, int x, int y) {
	switch(key) {
	case GLUT_KEY_LEFT :
		if (lx >= 0) {
			lx -= 0.2;
			rx -= 0.2;
			left -= 0.2;
			glutPostRedisplay();
		}
		break;
	case GLUT_KEY_RIGHT:
		if (rx <= 15) {
			rx += 0.2;
			lx += 0.2;
			left += 0.2;
			glutPostRedisplay();
		}
		break;
	case GLUT_KEY_UP:
		if (ty <= 2.7) {
			ty += 0.2;
			by += 0.2;
			up += 0.2;
			glutPostRedisplay();
		}
		break;
	case GLUT_KEY_DOWN:
		if (by >= 0.2) {
			ty -= 0.2;
			by -= 0.2;
			up -= 0.2;
			glutPostRedisplay();
		}
		break;
	}
}
void Keyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 'x':
	case 'X':
		target = true;
		glutPostRedisplay();
		break;
	}
}
void init() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, 15, 0, 9, 0, 2);
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800, 500);
	glutInitWindowPosition(30, 40);
	glutCreateWindow("Press right/left/up/down for walk and Press 'x' or 'X' for shoot");
	init();
	glutSpecialFunc(SpecialKeyboard);
	glutKeyboardFunc(Keyboard);
	glutDisplayFunc(display);
	glutMainLoop();
}