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
//float Window_Height = 530;
//float carSpeed = 0.5;
//
//bool paused = false;
//
///*****************Global Variables End*******************/
//
//
//void printString(string str) {
//	for (int i = 0; i < str.length(); i++) {
//		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, str[i]);
//	}
//}
//
//void printString2(string str) {
//	for (int i = 0; i < str.length(); i++) {
//		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, str[i]);
//	}
//}
//
//void setOrthographicProjection() {
//	// switch to projection mode
//	glMatrixMode(GL_PROJECTION);
//
//	// save previous matrix which contains the
//	//settings for the perspective projection
//	glPushMatrix();
//
//	// reset matrix
//	glLoadIdentity();
//
//	// set a 2D orthographic projection
//	gluOrtho2D(0, Window_Width, Window_Height, 0);
//
//	// switch back to modelview mode
//	glMatrixMode(GL_MODELVIEW);
//}
//
//void endPrintingOfText() {
//	//Set things up for normal rendering of display
//	glPopMatrix();
//	glMatrixMode(GL_PROJECTION);
//	// Restore the original projection matrix
//	glPopMatrix();
//	glMatrixMode(GL_MODELVIEW);
//}
//
//void setText() {
//	setOrthographicProjection();
//
//	// std::to_string is not supported by codeblocks c++ compiler, we
//	// must use stringstream as an alternative due to this
//	stringstream ss;
//	string axis, xVal, yVal, zVal;
//
//	// Change int values to their string equivalent
//	ss << currentAxis;
//	ss >> axis;
//	ss.clear();
//	ss << xt;
//	ss >> xVal;
//	ss.clear();
//	ss << yt;
//	ss >> yVal;
//	ss.clear();
//	ss << zt;
//	ss >> zVal;
//	ss.clear();
//	// done parsing values
//
//	glColor3f(0.0f, 0.8f, 0.0f);
//
//	glLoadIdentity();
//	glRasterPos2f(Window_Width * 0.02, Window_Height * 0.10);
//	printString2("CAR COORDINATES");
//
//	glLoadIdentity();
//	glRasterPos2f(Window_Width * 0.02, Window_Height * 0.12);
//	printString("X: " + xVal);
//
//	glLoadIdentity();
//	glRasterPos2f(Window_Width * 0.02, Window_Height * 0.135);
//	printString("Y: " + yVal);
//
//	glLoadIdentity();
//	glRasterPos2f(Window_Width * 0.02, Window_Height * 0.150);
//	printString("Z: " + zVal);
//
//	endPrintingOfText();
//	glutPostRedisplay();
//}
//
//// draws rectangular building with windows
//void drawRectangleBuilding(int i, int j, int sel) {
//	glMatrixMode(GL_MODELVIEW);
//	glCullFace(GL_BACK);
//
//	glPushMatrix();
//	//middle
//	switch (sel)
//	{
//	case 0:	
//		glTranslatef(i + 8, 7.0f, j + 8.0);
//		break;
//	case 1:
//		glTranslatef(i - 8, 7.0f, j - 8.0);
//		break;
//	case 2:
//		glTranslatef(i + 17, 7.0f, j - 17.0);
//		break;
//	case 3:
//		glTranslatef(i + 8, 7.0f, j + 17.0);
//		break;
//	default:
//		break;
//	}
//	//glTranslatef(i + 8, 7.0f, j + 8.0);
//	glScalef(3, 3, 3);
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
//void drawGround()
//{
//	//Ground
//	glPushMatrix();
//	glColor3f(0.5f, 0.5f, 0.5f);
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
//	glPushMatrix();
//
//	//the -2.2 is the offset to make the road in line with the origin. We want an intersection at (0,...,0)
//	glTranslatef(0, 0.01f, j - 2.2);
//	glScalef(5, 0, 5);
//
//	glBegin(GL_QUADS);
//
//	// Sides of Road
//	glColor3f(0, 0, 0);
//	glVertex3f(-mapBoundary / 2.5, 0.1, -0.05);
//	glVertex3f(-mapBoundary / 2.5, 0.1, 0.0);
//	glVertex3f(mapBoundary / 2.5, 0.1, 0.0);
//	glVertex3f(mapBoundary / 2.5, 0.1, -0.05);
//
//	glVertex3f(-mapBoundary / 2.5, 0.1, 1.05);
//	glVertex3f(-mapBoundary / 2.5, 0.1, 1.00);
//	glVertex3f(mapBoundary / 2.5, 0.1, 1.00);
//	glVertex3f(mapBoundary / 2.5, 0.1, 1.05);
//
//
//	glColor3f(0.7, 0.7, 0.7);
//	glVertex3f(-mapBoundary / 2.5, 0.1, 0);
//	glVertex3f(-mapBoundary / 2.5, 0.1, 0.45);		//a long road
//	glVertex3f(mapBoundary / 2.5, 0.1, 0.45);
//	glVertex3f(mapBoundary / 2.5, 0.1, 0);
//
//	glColor3f(1.0, 0.75, 0.0);
//	glVertex3f(-mapBoundary / 2.5, 0.1, 0.45);		//a median
//	glVertex3f(-mapBoundary / 2.5, 0.1, 0.55);
//	glVertex3f(mapBoundary / 2.5, 0.1, 0.55);
//	glVertex3f(mapBoundary / 2.5, 0.1, 0.45);
//
//	glColor3f(0.7, 0.7, 0.7);
//	glVertex3f(-mapBoundary / 2.5, 0.1, 0.55);
//	glVertex3f(-mapBoundary / 2.5, 0.1, 1);			//a long road
//	glVertex3f(mapBoundary / 2.5, 0.1, 1);
//	glVertex3f(mapBoundary / 2.5, 0.1, 0.55);
//
//	glEnd();
//
//	glPopMatrix();
//}
//
//void drawHorizontalStreet(int j) {
//	glPushMatrix();
//
//	//-2.0 is to offset the road so our car starts on the intersection at (0,..,0)
//	glTranslatef(j - 2.5, 0.02f, 0.0);
//	glScalef(5, 0, 5);
//
//	glRotatef(90, 0, 1, 0);
//
//	glBegin(GL_QUADS);
//
//	// Sides of Road
//	glColor3f(0, 0, 0);
//	glVertex3f(-mapBoundary / 2.5, 0.1, -0.05);
//	glVertex3f(-mapBoundary / 2.5, 0.1, 0.0);
//	glVertex3f(mapBoundary / 2.5, 0.1, 0.0);
//	glVertex3f(mapBoundary / 2.5, 0.1, -0.05);
//
//	glVertex3f(-mapBoundary / 2.5, 0.1, 1.05);
//	glVertex3f(-mapBoundary / 2.5, 0.1, 1.00);
//	glVertex3f(mapBoundary / 2.5, 0.1, 1.00);
//	glVertex3f(mapBoundary / 2.5, 0.1, 1.05);
//
//
//	glColor3f(0.7, 0.7, 0.7);
//	glVertex3f(-mapBoundary / 2.5, 0.1, 0);
//	glVertex3f(-mapBoundary / 2.5, 0.1, 0.45);		//a long road
//	glVertex3f(mapBoundary / 2.5, 0.1, 0.45);
//	glVertex3f(mapBoundary / 2.5, 0.1, 0);
//
//	glColor3f(1.0, 0.75, 0.0);
//	glVertex3f(-mapBoundary / 2.5, 0.1, 0.45);		//a median
//	glVertex3f(-mapBoundary / 2.5, 0.1, 0.55);
//	glVertex3f(mapBoundary / 2.5, 0.1, 0.55);
//	glVertex3f(mapBoundary / 2.5, 0.1, 0.45);
//
//	glColor3f(0.7, 0.7, 0.7);
//	glVertex3f(-mapBoundary / 2.5, 0.1, 0.55);
//	glVertex3f(-mapBoundary / 2.5, 0.1, 1);			//a long road
//	glVertex3f(mapBoundary / 2.5, 0.1, 1);
//	glVertex3f(mapBoundary / 2.5, 0.1, 0.55);
//
//	glEnd();
//	glPopMatrix();
//}
//
////Each block is 20x20 units
//void generateBlock(int i, int j)
//{
//	for(int sel = 0; sel < 4; sel++)
//		drawRectangleBuilding(i, j, sel);
//}
//
//void generateCity()
//{
//	//Draw the streets
//	for (int i = -10; i < 10; i++)
//	{
//		for (int j = -10; j < 10; j++)
//		{
//			//Vertical and Horizontal streets are seperated by 25 units
//			drawVerticalStreet(25 * i);
//			drawHorizontalStreet(25 * j);
//
//			//If the block to draw is within range
//			if (25 * i > xt + 50 || 25 * j > zt + 50 || 25 * i < xt - 75 || 25 * j < zt - 75)
//			{
//				continue;
//
//			}
//			generateBlock(25 * i, 25 * j);
//		}
//
//	}
//}
//
//void processLookAtView(GLfloat viewAngles[3][9])
//{
//    GLfloat angleRad = rotateCarAngle * M_PI / 180.0f;  // 각도를 라디안으로 변환
//
//    // 방향 벡터 초기화
//    GLfloat leftX = -std::sin(angleRad) * 4.0;
//    GLfloat leftZ = std::cos(angleRad) * 4.0;
//    GLfloat frontX = std::cos(angleRad) * 4.0;
//    GLfloat frontZ = std::sin(angleRad) * 4.0;
//
//    // 왼쪽 시점
//    viewAngles[2][0] = xt;          viewAngles[2][1] = 2;    viewAngles[2][2] = zt;
//    viewAngles[2][3] = xt + leftX;  viewAngles[2][4] = 1.5;  viewAngles[2][5] = zt + leftZ;
//    viewAngles[2][6] = 0.0;         viewAngles[2][7] = 1.0;  viewAngles[2][8] = 0.0;
//
//    // 정면 시점
//    viewAngles[1][0] = xt + frontX / 2.0; viewAngles[1][1] = 2;  viewAngles[1][2] = zt + frontZ / 2.0;
//    viewAngles[1][3] = xt + frontX;       viewAngles[1][4] = 1.5; viewAngles[1][5] = zt + frontZ;
//    viewAngles[1][6] = 0.0;               viewAngles[1][7] = 1.0; viewAngles[1][8] = 0.0;
//
//    // 오른쪽 시점
//    viewAngles[0][0] = xt;          viewAngles[0][1] = 2;    viewAngles[0][2] = zt;
//    viewAngles[0][3] = xt - leftX;  viewAngles[0][4] = 1.5;  viewAngles[0][5] = zt - leftZ;
//    viewAngles[0][6] = 0.0;         viewAngles[0][7] = 1.0;  viewAngles[0][8] = 0.0;
//}
//
//void display() {
//	if (!paused) {
//		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//		glClearColor(1.0, 1.0, 1.0, 1.0);
//
//		int width = Window_Width / 3;
//		GLfloat viewAngles[3][9];
//
//		// 시점 정보 가져오기
//		processLookAtView(viewAngles);
//
//		for (int i = 0; i < 3; ++i) {
//			glViewport(i * width, 0, width, Window_Height);
//
//			glMatrixMode(GL_PROJECTION);
//			glLoadIdentity();
//			gluPerspective(45.0, (GLfloat)width / (GLfloat)Window_Height, 0.1, 100.0);
//
//			glMatrixMode(GL_MODELVIEW);
//			glLoadIdentity();
//
//			// viewAngles 배열 사용하여 시점 설정
//			gluLookAt(
//				viewAngles[i][0], viewAngles[i][1], viewAngles[i][2],  // 카메라 위치
//				viewAngles[i][3], viewAngles[i][4], viewAngles[i][5],  // 보는 방향
//				viewAngles[i][6], viewAngles[i][7], viewAngles[i][8]   // 업벡터
//			);
//
//			glPushMatrix();
//			generateCity();
//			drawGround();
//			setText();
//			glPopMatrix();
//		}
//
//		glutSwapBuffers();
//
//		// 애니메이션 업데이트
//		rotateSphereBuildingTop += 1.0f;
//		rotateCylinderBuildingTop += 1.5f;
//		antRot += 3.0;
//		if (antRot >= 360.0) {
//			antRot -= 360.0;
//		}
//	}
//}
//
//
//void NormalKey(GLubyte key, GLint x, GLint y)
//{
//	switch (key)
//	{
//	//리셋
//	case 'r':
//		xt = zt = rotateCarAngle = 0;
//		break;
//
//	//좌회전
//	case 'a':
//		if (paused) {
//			break;
//		}
//
//		if (((int)fabs(xt) + 26) % fixedTurnInterval <= 2 && currentAxis == 1)
//		{
//			currentAxis = 2;
//			rotateCarAngle += 90;
//
//			if (rotateCarAngle >= 360) {
//				rotateCarAngle -= 360;
//			}
//		}
//
//		else if (((int)fabs(zt) + 26) % fixedTurnInterval <= 2 && currentAxis == 2)
//		{
//			currentAxis = 1;
//			rotateCarAngle += 90;
//
//			if (rotateCarAngle >= 360) {
//				rotateCarAngle -= 360;
//			}
//		}
//
//		break;
//
//	//우회전
//	case 'd':
//		if (paused) {
//			break;
//
//		}
//
//		if (((int)fabs(xt) + 26) % fixedTurnInterval <= 2 && currentAxis == 1)
//		{
//			currentAxis = 2;
//			rotateCarAngle -= 90;
//
//			if (rotateCarAngle < 0) {
//				rotateCarAngle += 360.0;
//			}
//
//			break;
//		}
//
//		if (((int)fabs(zt) + 26) % fixedTurnInterval <= 2 && currentAxis == 2)
//		{
//			currentAxis = 1;
//			rotateCarAngle -= 90;
//
//			if (rotateCarAngle < 0) {
//				rotateCarAngle += 360.0;
//			}
//			break;
//		}
//
//		break;
//
//	//전진
//	case 'w':
//		if (paused) {
//			break;
//		}
//
//		angle += 5;
//
//		if (rotateCarAngle == 0 && (xt + carSpeed < mapBoundary * 2)) {
//			xt += carSpeed;
//		}
//
//		else if (rotateCarAngle == 90 && (zt - carSpeed > -mapBoundary * 2)) {
//			zt += carSpeed;
//		}
//
//		else if (rotateCarAngle == 180 && (xt - carSpeed > -mapBoundary * 2)) {
//			xt -= carSpeed;
//		}
//
//		else if (rotateCarAngle == 270 && (zt + carSpeed < mapBoundary * 2)) {
//			zt -= carSpeed;
//		}
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
//		if (rotateCarAngle == 0 && (xt - carSpeed > -mapBoundary * 2)) {
//			xt -= carSpeed;
//		}
//
//		else if (rotateCarAngle == 90 && (zt + carSpeed < mapBoundary * 2)) {
//			zt -= carSpeed;
//		}
//
//		else if (rotateCarAngle == 180 && (xt + carSpeed < mapBoundary * 2)) {
//			xt += carSpeed;
//		}
//
//		else if (rotateCarAngle == 270 && (zt - carSpeed > -mapBoundary * 2)) {
//			zt += carSpeed;
//		}
//
//		glutPostRedisplay();
//		break;
//
//	//중지
//	case 'p':
//		paused = !paused;
//		break;
//
//	default:
//		break;
//	}
//}
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