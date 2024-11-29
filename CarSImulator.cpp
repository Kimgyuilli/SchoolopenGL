//#define PROGRAM_TITLE "Interactive OpenGL Game"
//#define SPACEBAR 32
//#define _USE_MATH_DEFINES
//
//#include <stdlib.h>
//#include <stdio.h>
//#include <time.h>
//#include <string>
//#include <math.h>
//#include <cmath>
//#include <iostream>
//#include <sstream>
//#include <GL/glut.h>
//
//
//using namespace std;
//
///*****************Global Variables Start*****************/
//GLUquadricObj* t;
//GLfloat r = 0, g = 0, b = 1;
//float rotateCylinderBuildingTop = 1.0f;
//float rotateSphereBuildingTop = 20.0f;
//float antRot = 0;
//float mapBoundary = 140;
//int counter = 0;
//
//int fixedTurnInterval = 25;
//int numBuildingsPerBlock = 3;
//int currentAxis = 1;
//int rotateCarAngle = 0;
//
//float angle;
//float xt, yt, zt = 0.0;
//float Window_Width = 1620;
//float Window_Height = 730;
//float carSpeed = 0.5;
//
//bool paused = false;
//
///*****************Global Variables End*******************/
//void setupLighting()
//{
//	// Enable lighting and specific light source
//	glEnable(GL_LIGHTING);
//	glEnable(GL_LIGHT0);
//
//	// Define light properties
//	GLfloat light_ambient[] = { 0.2f, 0.2f, 0.2f, 1.0f };  // Ambient light
//	GLfloat light_diffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };  // Diffuse light
//	GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f }; // Specular light
//	GLfloat light_position[] = { 30.0f, 60.0f, 30.0f, 1.0f }; // Light position
//
//	// Apply light properties to GL_LIGHT0
//	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
//	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
//	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
//	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
//
//	// Enable color material for simpler color manipulation
//	glEnable(GL_COLOR_MATERIAL);
//	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
//	glMaterialfv(GL_FRONT, GL_SPECULAR, light_specular);
//	glMateriali(GL_FRONT, GL_SHININESS, 50); // Shininess
//}
//
//GLvoid Transform(GLfloat Width, GLfloat Height)
//{
//	glViewport(0, 0, Width, Height);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluPerspective(60.0, Width / Height, 0.1, 1000.0); // Increased far clipping plane
//	glMatrixMode(GL_MODELVIEW);
//}
//
//GLvoid InitGL(GLfloat Width, GLfloat Height)
//{
//	glClearColor(0.0, 0.0, 0.0, 1.0);
//	glLineWidth(2.0);              // Add line width, ditto
//	Transform(Width, Height);      // Perform the transformation
//	t = gluNewQuadric();
//	gluQuadricDrawStyle(t, GLU_FILL);
//
//	setupLighting(); // Initialize lighting
//}
//
//// draws rectangular building with windows
//void drawRectangleBuilding(int i, int j, int sel) {
//	glCullFace(GL_BACK);
//
//	// 재질 설정
//	GLfloat rect_diffuse[] = { 0.5f, 0.7f, 0.5f, 1.0f }; //색
//	GLfloat rect_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f }; // 밝은 하이라이트
//	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, rect_diffuse);
//	glMaterialfv(GL_FRONT, GL_SPECULAR, rect_specular);
//	glMateriali(GL_FRONT, GL_SHININESS, 50); // 중간 정도의 광택
//
//	glPushMatrix();
//	switch (sel)
//	{
//	case 0:
//		glTranslatef(i + 8, 7.0f, j + 8.0);
//		break;
//	case 1:
//		glTranslatef(i + 8, 7.0f, j + 17.0);
//		break;
//	default:
//		break;
//	}
//	glScalef(3, 3, 3);
//
//
//	glColorMaterial(GL_FRONT, GL_DIFFUSE);
//	glBegin(GL_QUADS);
//	// Top face (y = 1.0f)
//	glColor3f(0.0f, 0.0f, 0.0f);
//	glVertex3f(1.0f, 2.5f, -1.0f);
//	glVertex3f(-1.0f, 2.5f, -1.0f);
//	glVertex3f(-1.0f, 2.5f, 1.0f);
//	glVertex3f(1.0f, 2.5f, 1.0f);
//
//	// Front face  (z = 1.0f)
//	glColor3f(0.25f, 0.25f, 0.25f);
//	glVertex3f(1.0f, 2.5f, 1.0f);
//	glVertex3f(-1.0f, 2.5f, 1.0f);
//	glVertex3f(-1.0f, -2.5f, 1.0f);
//	glVertex3f(1.0f, -2.5f, 1.0f);
//
//	// Back face (z = -1.0f)
//	glColor3f(0.5f, 0.5f, 0.5f);
//	glVertex3f(1.0f, -2.5f, -1.0f);
//	glVertex3f(-1.0f, -2.5f, -1.0f);
//	glVertex3f(-1.0f, 2.5f, -1.0f);
//	glVertex3f(1.0f, 2.5f, -1.0f);
//
//	// Left face (x = -1.0f)
//	glColor3f(0.75f, 0.75f, 0.75f);
//	glVertex3f(-1.0f, 2.5f, 1.0f);
//	glVertex3f(-1.0f, 2.5f, -1.0f);
//	glVertex3f(-1.0f, -2.5f, -1.0f);
//	glVertex3f(-1.0f, -2.5f, 1.0f);
//
//	// Right face (x = 1.0f)
//	glColor3f(1.0f, 1.0f, 1.0f);
//	glVertex3f(1.0f, 2.5f, -1.0f);
//	glVertex3f(1.0f, 2.5f, 1.0f);
//	glVertex3f(1.0f, -2.5f, 1.0f);
//	glVertex3f(1.0f, -2.5f, -1.0f);
//
//	glEnd();  // End of drawing rectangle building
//
//	glPopMatrix();
//}
//
//// draws sphere building with small cylinder on top
//void drawSphereBuilding(int i, int j, int sel)
//{
//	glCullFace(GL_BACK);
//
//	// Draw sphere on bottom
//	glPushMatrix();
//	switch (sel)
//	{
//	case 0:
//		glTranslatef(i, 4.5f, j + 8);
//		break;
//	case 1:
//		glTranslatef(i, 4.5f, j + 17.0);
//		break;
//	default:
//		break;
//	}
//
//	glScalef(2, 2, 2);
//
//	// Material properties for the sphere
//	GLfloat sphere_diffuse[] = { 0.5f, 0.5f, 0.7f, 1.0f };  // Gray diffuse
//	GLfloat sphere_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f }; // Bright specular
//	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, sphere_diffuse);
//	glMaterialfv(GL_FRONT, GL_SPECULAR, sphere_specular);
//	glMateriali(GL_FRONT, GL_SHININESS, 100); // High shininess for glossy effect
//
//	glutSolidSphere(2, 30, 30);
//
//	glPopMatrix();
//}
//
//void drawCylinderBuilding(int i, int j, int sel) {
//	glCullFace(GL_BACK);
//
//	glPushMatrix();
//
//	// 위치 설정
//	switch (sel) {
//	case 0:
//		glTranslatef(i + 8, 0.0f, j + 8); // 위치 조정
//		break;
//	case 1:
//		glTranslatef(i + 8, 0.0f, j + 17.0); // 위치 조정
//		break;
//	default:
//		break;
//	}
//
//	// 실린더 높이 및 반지름 설정
//	GLfloat height = 10.0f; // 증가된 높이
//	GLfloat radius = 3.5f;
//
//	// Material properties for the sphere
//	GLfloat cylinder_diffuse[] = { 0.3f, 0.7f, 0.7f, 1.0f };  // Gray diffuse
//	GLfloat cylinder_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f }; // Bright specular
//	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, cylinder_diffuse);
//	glMaterialfv(GL_FRONT, GL_SPECULAR, cylinder_specular);
//	glMateriali(GL_FRONT, GL_SHININESS, 50); // High shininess for glossy effect
//
//	// 회전 순서를 높이 적용 후로 조정
//	glRotatef(-90.0f, 1.0f, 0.0f, 0.0f); // X축 기준으로 회전하여 세로 방향
//
//	GLUquadric* quad = gluNewQuadric(); // Quadric 객체 생성
//	//gluQuadricNormals(quad, GLU_SMOOTH); // 조명 설정
//
//	// 실린더 본체
//	gluCylinder(quad, radius, radius, height, 30, 30);
//
//	// 상단 캡 추가
//	glPushMatrix();
//	glTranslatef(0.0f, 0.0f, height); // 상단으로 이동
//	gluDisk(quad, 0.0f, radius, 30, 1);
//	glPopMatrix();
//
//	gluDeleteQuadric(quad); // Quadric 객체 삭제
//	glPopMatrix();
//}
//
//void drawConeBuilding(int i, int j, int sel) {
//	glCullFace(GL_BACK);
//
//	glPushMatrix();
//
//	// 위치 설정
//	switch (sel) {
//	case 0:
//		glTranslatef(i + 8, 0.0f, j + 8); // 위치 조정
//		break;
//	case 1:
//		glTranslatef(i + 8, 0.0f, j + 17.0); // 위치 조정
//		break;
//	default:
//		break;
//	}
//
//	// 실린더 높이 및 반지름 설정
//	GLfloat height = 10.0f; // 증가된 높이
//	GLfloat radius = 3.5f;
//
//	// Material properties for the sphere
//	GLfloat cone_diffuse[] = { 0.7f, 0.5f, 0.7f, 1.0f };  // Gray diffuse
//	GLfloat cone_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f }; // Bright specular
//	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, cone_diffuse);
//	glMaterialfv(GL_FRONT, GL_SPECULAR, cone_specular);
//	glMateriali(GL_FRONT, GL_SHININESS, 50); // High shininess for glossy effect
//
//	// 회전 순서를 높이 적용 후로 조정
//	glRotatef(-90.0f, 1.0f, 0.0f, 0.0f); // X축 기준으로 회전하여 세로 방향
//
//	GLUquadric* quad = gluNewQuadric(); // Quadric 객체 생성
//	//gluQuadricNormals(quad, GLU_SMOOTH); // 조명 설정
//
//	// 실린더 본체
//	gluCylinder(quad, radius, 0, height, 30, 30);
//
//
//	gluDeleteQuadric(quad); // Quadric 객체 삭제
//	glPopMatrix();
//}
//
//void drawTorusBuilding(int i, int j) {
//	glCullFace(GL_BACK);
//
//	glPushMatrix();
//
//	glTranslatef(i + 8, 1.2f, j); // 위치 조정
//
//	glScalef(2, 2, 2); // 도넛 전체 크기 조정
//
//	// 재질 설정
//	GLfloat torus_diffuse[] = { 0.0f, 1.0f, 1.0f, 1.0f }; //색
//	GLfloat torus_specular[] = { 1.0f, 0.5f, 0.5f, 1.0f }; // 밝은 하이라이트
//	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, torus_diffuse);
//	glMaterialfv(GL_FRONT, GL_SPECULAR, torus_specular);
//	glMateriali(GL_FRONT, GL_SHININESS, 50); // 중간 정도의 광택
//
//
//	glRotated(90, 0, 1, 0);
//	// 도넛 렌더링
//	glutSolidTorus(1.0, 2.5, 25, 25);
//
//	glPopMatrix();
//}
//
//void drawPentagonalPyramid(int i, int j, int sel) {
//	glCullFace(GL_BACK);
//
//	glPushMatrix();
//
//	// 위치 설정
//	switch (sel) {
//	case 0:
//		glTranslatef(i + 8, 0.0f, j + 8.0);
//		break;
//	case 1:
//		glTranslatef(i + 8, 0.0f, j + 17.0);
//		break;
//	default:
//		break;
//	}
//
//	glScalef(4, 4, 4); // 크기 조정
//
//	// 재질 설정
//	GLfloat penta_diffuse[] = { 1.0f, 1.0f, 0.5f, 1.0f }; //색
//	GLfloat penta_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f }; // 밝은 하이라이트
//	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, penta_diffuse);
//	glMaterialfv(GL_FRONT, GL_SPECULAR, penta_specular);
//	glMateriali(GL_FRONT, GL_SHININESS, 50); // 중간 정도의 광택
//
//	glColorMaterial(GL_FRONT, GL_DIFFUSE);
//
//	// 오각형 바닥 (Base face)
//	glBegin(GL_POLYGON);
//	glColor3f(0.5f, 0.5f, 0.5f); // 회색
//	for (int k = 0; k < 5; ++k) {
//		float angle = 2.0f * M_PI * k / 5.0f;
//		float x = cos(angle); // X 좌표 계산
//		float z = sin(angle); // Z 좌표 계산
//		glVertex3f(x, 0.0f, z); // 오각형의 꼭짓점
//	}
//	glEnd();
//
//	// 삼각형 면 (Side faces)
//	glBegin(GL_TRIANGLES);
//	for (int k = 0; k < 5; ++k) {
//		float angle1 = 2.0f * M_PI * k / 5.0f;          // 현재 꼭짓점 각도
//		float angle2 = 2.0f * M_PI * (k + 1) / 5.0f;    // 다음 꼭짓점 각도
//
//		float x1 = cos(angle1), z1 = sin(angle1); // 현재 꼭짓점 좌표
//		float x2 = cos(angle2), z2 = sin(angle2); // 다음 꼭짓점 좌표
//
//		glColor3f((k + 1) * 0.2f, (k + 1) * 0.1f, 0.5f); // 각 면에 다른 색상 적용
//		glVertex3f(x1, 0.0f, z1); // 현재 꼭짓점
//		glVertex3f(x2, 0.0f, z2); // 다음 꼭짓점
//		glVertex3f(0.0f, 2.0f, 0.0f); // 꼭대기 (뿔의 정점)
//	}
//	glEnd();
//
//	glPopMatrix();
//}
//
//void drawGround()
//{
//	// Ground
//	glPushMatrix();
//	glColor3f(0.7f, 0.7f, 0.7f);
//	glTranslatef(0.0f, 0.0f, 0.0f);
//
//	glBegin(GL_QUADS);
//	glVertex3f(-mapBoundary * 2, 0.0f, -mapBoundary * 2);
//	glVertex3f(-mapBoundary * 2, 0.0f, mapBoundary * 2);
//	glVertex3f(mapBoundary * 2, 0.0f, mapBoundary * 2);
//	glVertex3f(mapBoundary * 2, 0.0f, -mapBoundary * 2);
//	glEnd();
//
//	glPopMatrix();
//}
//
//void drawVerticalStreet(int j)
//{
//	float xint = 9.5;
//	glPushMatrix();
//
//	glTranslatef(0, 0.01f, j - 2.2);
//	glScalef(5, 0, 5);
//
//	//glColorMaterial(GL_FRONT, GL_DIFFUSE);
//
//	glBegin(GL_TRIANGLE_STRIP);
//
//	// Road center (grey)
//	glColor3f(0.3, 0.3, 0.3);
//	glVertex3f(-mapBoundary / (xint + 5), 0.1, 0);
//	glVertex3f(mapBoundary / (xint + 16.7), 0.1, 0);
//
//	glVertex3f(-mapBoundary / (xint + 5), 0.1, 1);
//	glVertex3f(mapBoundary / (xint + 16.7), 0.1, 1);
//
//	glEnd();
//
//	// Median strip (orange)
//	glEnable(GL_POLYGON_OFFSET_FILL); // Enable polygon offset
//	glPolygonOffset(-1.0, -1.0);      // Offset for depth fighting prevention
//
//	glBegin(GL_TRIANGLE_STRIP);
//
//	glColor3f(1.0, 0.75, 0.0); // Bright orange
//	glVertex3f(-mapBoundary / (xint + 4.5), 0.102, 0.45); // Slightly above the road
//	glVertex3f(mapBoundary / (xint + 18.4), 0.102, 0.45);
//	glVertex3f(-mapBoundary / (xint + 4.5), 0.102, 0.55);
//	glVertex3f(mapBoundary / (xint + 18.4), 0.102, 0.55);
//
//	glEnd();
//
//	glDisable(GL_POLYGON_OFFSET_FILL); // Disable polygon offset
//
//	glPopMatrix();
//}
//
//void drawHorizontalStreet(int j)
//{
//	float yint = 9.5;
//	glPushMatrix();
//
//	glTranslatef(j - 2.5, 0.02f, 0.0);
//	glScalef(5, 0, 5);
//
//	glRotatef(90, 0, 1, 0);
//
//	glBegin(GL_TRIANGLE_STRIP);
//
//	// Road center (grey)
//	glColor3f(0.3, 0.3, 0.3);
//	glVertex3f(-mapBoundary / (yint + 15.7), 0.1, 0);
//	glVertex3f(mapBoundary / (yint + 3.9), 0.1, 0);
//
//	glVertex3f(-mapBoundary / (yint + 15.7), 0.1, 1);
//	glVertex3f(mapBoundary / (yint + 3.9), 0.1, 1);
//
//	glEnd();
//
//	// Median strip (orange)
//	glEnable(GL_POLYGON_OFFSET_FILL); // Enable polygon offset
//	glPolygonOffset(-1.0, -1.0);      // Offset for depth fighting prevention
//	glBegin(GL_TRIANGLE_STRIP);
//
//	glColor3f(1.0, 0.75, 0.0);
//	glVertex3f(-mapBoundary / (yint + 18), 0.101, 0.45);
//	glVertex3f(mapBoundary / (yint + 4.5), 0.101, 0.45);
//
//	glVertex3f(-mapBoundary / (yint + 18), 0.101, 0.55);
//	glVertex3f(mapBoundary / (yint + 4.5), 0.101, 0.55);
//
//	glEnd();
//	glDisable(GL_POLYGON_OFFSET_FILL); // Disable polygon offset
//	glPopMatrix();
//}
//
//void drawVStreet()
//{
//	float yint = 9.5;
//	glPushMatrix();
//
//	glTranslatef(35.5, 0.02f, -14.0);
//	glScalef(5, 0, 5);
//
//	glRotatef(45, 0, 1, 0);
//
//	glBegin(GL_TRIANGLE_STRIP);
//
//	// Road center (grey)
//	glColor3f(0.3, 0.3, 0.3);
//	glVertex3f(-mapBoundary / (yint + 30.5), 0.1, 0);
//	glVertex3f(mapBoundary / (yint + 2.5), 0.1, 0);
//
//	glVertex3f(-mapBoundary / (yint + 30.5), 0.1, 1);
//	glVertex3f(mapBoundary / (yint + 2.5), 0.1, 1);
//
//	glEnd();
//
//	// Median strip (orange)
//	glEnable(GL_POLYGON_OFFSET_FILL); // Enable polygon offset
//	glPolygonOffset(-1.0, -1.0);      // Offset for depth fighting prevention
//	glBegin(GL_TRIANGLE_STRIP);
//
//	glColor3f(1.0, 0.75, 0.0);
//	glVertex3f(-mapBoundary / (yint + 29.5), 0.101, 0.45);
//	glVertex3f(mapBoundary / (yint + 0.4), 0.101, 0.45);
//
//	glVertex3f(-mapBoundary / (yint + 29.5), 0.101, 0.55);
//	glVertex3f(mapBoundary / (yint + 0.4), 0.101, 0.55);
//
//	glEnd();
//	glDisable(GL_POLYGON_OFFSET_FILL); // Disable polygon offset
//	glPopMatrix();
//}
//
//// draws rectangular building with windows
//void drawVBuilding(int i, int j) {
//	glCullFace(GL_BACK);
//
//	// 재질 설정
//	GLfloat rect_diffuse[] = { 0.9f, 0.7f, 0.5f, 1.0f }; // 색
//	GLfloat rect_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f }; // 밝은 하이라이트
//	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, rect_diffuse);
//	glMaterialfv(GL_FRONT, GL_SPECULAR, rect_specular);
//	glMateriali(GL_FRONT, GL_SHININESS, 50); // 중간 정도의 광택
//
//	glPushMatrix();
//	glTranslatef(40, 0.7f, -23.0);
//	glScalef(3, 1, 3);
//	glRotated(45, 0, 1, 0);
//
//	glColorMaterial(GL_FRONT, GL_DIFFUSE);
//	glBegin(GL_QUADS);
//
//	// Top face (y = 1.0f)
//	glColor3f(0.0f, 0.0f, 0.0f);
//	glVertex3f(3.0f, 2.5f, -1.0f);
//	glVertex3f(-3.0f, 2.5f, -1.0f);
//	glVertex3f(-3.0f, 2.5f, 1.0f);
//	glVertex3f(3.0f, 2.5f, 1.0f);
//
//	// Front face (z = 1.0f)
//	glColor3f(0.25f, 0.25f, 0.25f);
//	glVertex3f(3.0f, 2.5f, 1.0f);
//	glVertex3f(-3.0f, 2.5f, 1.0f);
//	glVertex3f(-3.0f, -2.5f, 1.0f);
//	glVertex3f(3.0f, -2.5f, 1.0f);
//
//	// Back face (z = -1.0f)
//	glColor3f(0.5f, 0.5f, 0.5f);
//	glVertex3f(3.0f, -2.5f, -1.0f);
//	glVertex3f(-3.0f, -2.5f, -1.0f);
//	glVertex3f(-3.0f, 2.5f, -1.0f);
//	glVertex3f(3.0f, 2.5f, -1.0f);
//
//	// Left face (x = -3.0f)
//	glColor3f(0.75f, 0.75f, 0.75f);
//	glVertex3f(-3.0f, 2.5f, 1.0f);
//	glVertex3f(-3.0f, 2.5f, -1.0f);
//	glVertex3f(-3.0f, -2.5f, -1.0f);
//	glVertex3f(-3.0f, -2.5f, 1.0f);
//
//	// Right face (x = 3.0f)
//	glColor3f(1.0f, 1.0f, 1.0f);
//	glVertex3f(3.0f, 2.5f, -1.0f);
//	glVertex3f(3.0f, 2.5f, 1.0f);
//	glVertex3f(3.0f, -2.5f, 1.0f);
//	glVertex3f(3.0f, -2.5f, -1.0f);
//
//	glEnd();  // End of drawing rectangle building
//
//	glPopMatrix();
//}
//
////Each block is 20x20 units
//void generateBlock(int i, int j)
//{
//	for (int sel = 0; sel < 4; sel++)
//		drawRectangleBuilding(i, j, sel);
//}
//
//void generateCity()
//{
//	// Draw the streets
//	for (int i = -2; i < 2; i++)
//	{
//		for (int j = -2; j < 2; j++)
//		{
//			// Vertical and Horizontal streets are separated by 25 units
//			drawVerticalStreet(25 * i);
//			drawHorizontalStreet(25 * j);
//		}
//	}
//}
//
//void processLookAtView(GLfloat viewAngles[4][9]) // 시점 배열 크기를 4로 확장
//{
//	GLfloat angleRad = rotateCarAngle * M_PI / 180.0f; // 각도를 라디안으로 변환
//
//	// 방향 벡터 초기화
//	GLfloat leftX = -std::sin(angleRad) * 4.0;
//	GLfloat leftZ = std::cos(angleRad) * 4.0;
//	GLfloat frontX = std::cos(angleRad) * 4.0;
//	GLfloat frontZ = std::sin(angleRad) * 4.0;
//	GLfloat backX = -frontX; // 뒤쪽 방향
//	GLfloat backZ = -frontZ;
//
//	// 왼쪽 시점
//	viewAngles[2][0] = xt;          viewAngles[2][1] = 2;    viewAngles[2][2] = zt;
//	viewAngles[2][3] = xt + leftX;  viewAngles[2][4] = 1.5;  viewAngles[2][5] = zt + leftZ;
//	viewAngles[2][6] = 0.0;         viewAngles[2][7] = 1.0;  viewAngles[2][8] = 0.0;
//
//	// 정면 시점
//	viewAngles[1][0] = xt + frontX / 2.0; viewAngles[1][1] = 2;  viewAngles[1][2] = zt + frontZ / 2.0;
//	viewAngles[1][3] = xt + frontX;       viewAngles[1][4] = 1.5; viewAngles[1][5] = zt + frontZ;
//	viewAngles[1][6] = 0.0;               viewAngles[1][7] = 1.0; viewAngles[1][8] = 0.0;
//
//	// 오른쪽 시점
//	viewAngles[0][0] = xt;          viewAngles[0][1] = 2;    viewAngles[0][2] = zt;
//	viewAngles[0][3] = xt - leftX;  viewAngles[0][4] = 1.5;  viewAngles[0][5] = zt - leftZ;
//	viewAngles[0][6] = 0.0;         viewAngles[0][7] = 1.0;  viewAngles[0][8] = 0.0;
//
//	// 백미러 시점 (뒤쪽)
//	viewAngles[3][0] = xt;          viewAngles[3][1] = 2;    viewAngles[3][2] = zt;
//	viewAngles[3][3] = xt + backX;  viewAngles[3][4] = 1.5;  viewAngles[3][5] = zt + backZ;
//	viewAngles[3][6] = 0.0;         viewAngles[3][7] = 1.0;  viewAngles[3][8] = 0.0;
//}
//
//void display() {
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//	GLfloat viewAngles[4][9];
//	processLookAtView(viewAngles);
//
//	int topHeight = Window_Height * 2 / 3; // 상단의 높이
//	int bottomHeight = Window_Height / 3; // 하단의 높이
//	int width = Window_Width / 3;
//
//	// 상단의 좌측, 정면, 우측 뷰
//	for (int i = 0; i < 3; ++i) {
//		InitGL(Window_Width, Window_Height);
//		glViewport(i * Window_Width / 3, 0, Window_Width / 3, Window_Height); // 각 뷰포트를 설정
//
//		glMatrixMode(GL_PROJECTION);
//		glLoadIdentity();
//		gluPerspective(45.0, (GLfloat)width / (GLfloat)topHeight, 0.1, 100.0);
//
//		glMatrixMode(GL_MODELVIEW);
//		glLoadIdentity();
//
//		gluLookAt(
//			viewAngles[i][0], viewAngles[i][1], viewAngles[i][2],  // 카메라 위치
//			viewAngles[i][3], viewAngles[i][4], viewAngles[i][5],  // 보는 방향
//			viewAngles[i][6], viewAngles[i][7], viewAngles[i][8]   // 업벡터
//		);
//
//		glPushMatrix();
//		generateCity();
//		drawGround();
//		drawVStreet();
//
//		for (int z = 0; z < 3; z++) {
//			for (int i = 0; i < 2; i++) {
//				drawRectangleBuilding(0, z * (-25), i);
//				drawSphereBuilding(17, z * (-23), i);
//				drawCylinderBuilding(-15, z * (-24), i);
//				drawConeBuilding(-25, z * (-24), i);
//				if (z != 2) {
//					drawTorusBuilding(-41, z * (-25));
//				}
//				drawPentagonalPyramid(-49, z * (-24), i);
//			}
//		}
//		drawVBuilding(0, -20);
//		glPopMatrix();
//	}
//
//	// 추가 백미러 창 설정 (상단 중앙 작은 창)
//	int mirrorWidth = 400; // 백미러 창의 너비
//	int mirrorHeight = 200; // 백미러 창의 높이
//	int mirrorX = Window_Width / 2 - mirrorWidth / 2; // 화면 중앙에 배치
//	int mirrorY = Window_Height - mirrorHeight + 20; // 상단에서 약간 아래로 배치
//
//	InitGL(Window_Width, Window_Height);
//	glViewport(mirrorX, mirrorY, mirrorWidth, mirrorHeight);
//
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluPerspective(45.0, (GLfloat)mirrorWidth / (GLfloat)mirrorHeight, 0.1, 100.0);
//
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//
//	gluLookAt(
//		viewAngles[3][0], viewAngles[3][1], viewAngles[3][2],  // 카메라 위치
//		viewAngles[3][3], viewAngles[3][4], viewAngles[3][5],  // 보는 방향
//		viewAngles[3][6], viewAngles[3][7], viewAngles[3][8]   // 업벡터
//	);
//
//	glPushMatrix();
//	generateCity();
//	drawGround();
//	drawVStreet();
//	glPopMatrix();
//
//	glutSwapBuffers();
//
//	// 애니메이션 업데이트
//	rotateSphereBuildingTop += 1.0f;
//	rotateCylinderBuildingTop += 1.5f;
//	antRot += 3.0;
//	if (antRot >= 360.0) {
//		antRot -= 360.0;
//	}
//}
//
//
//
//
//
//void NormalKey(GLubyte key, GLint x, GLint y)
//{
//	switch (key)
//	{
//		// 리셋
//	case 'r':
//		xt = zt = rotateCarAngle = 0;
//		break;
//
//		// 좌회전
//	case 'd':
//		rotateCarAngle += 5; // 2도씩 증가
//		if (rotateCarAngle >= 360) {
//			rotateCarAngle -= 360; // 360도 이상이면 0도로 되돌림
//		}
//		break;
//
//		// 우회전
//	case 'a':
//		rotateCarAngle -= 5; // 2도씩 감소
//		if (rotateCarAngle < 0) {
//			rotateCarAngle += 360; // 0도 이하이면 360도로 되돌림
//		}
//		break;
//
//		// 전진
//	case 'w':
//		if (paused) {
//			break;
//		}
//
//		angle += 5;
//
//		// 회전 각도에 따라 이동 방향 계산
//		xt += carSpeed * cos(rotateCarAngle * M_PI / 180.0); // 회전 각도 기준으로 x축 이동
//		zt += carSpeed * sin(rotateCarAngle * M_PI / 180.0); // 회전 각도 기준으로 z축 이동
//
//		glutPostRedisplay();
//		break;
//
//		// 후진
//	case 's':
//		if (paused) {
//			break;
//		}
//
//		angle += 5;
//
//		// 회전 각도에 따라 이동 방향 계산
//		xt -= carSpeed * cos(rotateCarAngle * M_PI / 180.0); // 회전 각도 기준으로 x축 이동
//		zt -= carSpeed * sin(rotateCarAngle * M_PI / 180.0); // 회전 각도 기준으로 z축 이동
//
//		glutPostRedisplay();
//		break;
//
//	default:
//		break;
//	}
//}
//
//
//
//void reshape(GLsizei width, GLsizei height) {
//	if (height == 0) height = 1;                // To prevent divide by 0
//	GLfloat aspect = (GLfloat)width / (GLfloat)height;
//
//	glViewport(0, 0, width, height);
//
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluPerspective(45.0f, aspect, 0.1f, 100.0f);
//}
//
///* Main function: GLUT runs as a console application starting at main() */
//int main(int argc, char** argv) {
//	glutInit(&argc, argv);				    	// Initialize GLUT
//	glutInitDisplayMode(GLUT_DOUBLE);		    	// Enable double buffered mode
//	glutInitWindowSize(Window_Width, Window_Height);    	// Set the window's initial width & height
//	glutInitWindowPosition(50, 50);				// Position the window's initial top-left corner
//	glutCreateWindow(PROGRAM_TITLE);			// Create window with the given title
//	glutDisplayFunc(display);				// Register callback handler for window re-paint event
//	glutIdleFunc(display);					// If nothing to do, refresh screen
//	glutReshapeFunc(reshape);				// Register callback handler for window re-size event
//	glutKeyboardFunc(NormalKey);				// Register callback for normal key events
//
//	glEnable(GL_DEPTH_TEST);				// Enable depth testing
//	glutMainLoop();						// Enter the infinite event-processing loop
//	return 0;
//}