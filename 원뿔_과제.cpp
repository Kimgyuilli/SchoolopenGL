#include <gl/glut.h>
#include <gl/gl.h>
#include <gl/glu.h>
#include <stdio.h>

float angleX = 0.0f;  // X축 회전 각도
float angleY = 0.0f;  // Y축 회전 각도
GLfloat eX = 0.0;
GLfloat eY = 0.0;
GLfloat eZ = 3.0; // 카메라를 z축 방향으로 뒤로 이동
GLfloat aX = 0.0;
GLfloat aY = 0.0;
GLfloat aZ = 0.0; // 원점을 바라보도록 수정
GLfloat uX = 0.0;
GLfloat uY = 1.0;
GLfloat uZ = 0.0;

// 기존 정육면체의 정점 (0-7) + 삼각뿔의 꼭짓점 (8)
GLfloat MyVertices[10][3] = {
	// 정육면체의 정점 (0-7)
	{-0.25,-0.25,0.25}, {-0.25,0.25,0.25}, {0.25,0.25,0.25}, {0.25,-0.25,0.25},
	{-0.25,-0.25,-0.25}, {-0.25,0.25,-0.25}, {0.25,0.25,-0.25}, {0.25,-0.25,-0.25},
	// 삼각뿔의 꼭짓점 (8)
	{0.0, 0.75, -0.125},  // 정육면체 위에 위치한 삼각뿔의 정점
	{0.0,0.25,0.25},
};

// 정육면체의 색상 (0-7) + 삼각뿔 꼭짓점의 색상 (8)
GLfloat MyColors[9][3] = {
	// 정육면체의 색상
	{0.8,0.8,0.8}, {0.8,0.8,0.8}, {0.8,0.8,0.8}, {0.8,0.8,0.8},
	{0.2,0.2,0.2}, {0.2,0.2,0.2}, {0.2,0.2,0.2}, {0.2,0.2,0.2},
	// 삼각뿔의 색상
	{1.0,0.0,0.0}  // 빨간색
};

// 정육면체의 면 (24개 정점) + 삼각뿔의 면 (12개 정점)
GLubyte MyVertexList[33] = {
	// 정육면체의 면 (0-23)
	0,4,7,3, 4,5,6,7, 0,1,5,4, 0,3,2,1, 2,3,7,6, 1,2,6,5,
	// 삼각뿔의 면 (24-33) - 정육면체 윗면의 네 꼭짓점과 삼각뿔의 정점으로 3개의 삼각형 만들기
	5,8,6,  // 앞면
	6,8,9,  // 오른쪽면 (1번과 2번 사이에 있음)
	9,8,5   // 왼쪽면
};

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	glFrontFace(GL_CCW);
	glEnableClientState(GL_COLOR_ARRAY);
	glEnableClientState(GL_VERTEX_ARRAY);
	glColorPointer(3, GL_FLOAT, 0, MyColors);
	glVertexPointer(3, GL_FLOAT, 0, MyVertices);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(eX, eY, eZ, aX, aY, aZ, uX, uY, uZ);
	// 물체 회전
	glRotatef(angleX, 1.0f, 0.0f, 0.0f); // X축 회전
	glRotatef(angleY, 0.0f, 1.0f, 0.0f); // Y축 회전
	// 정육면체 그리기
	for (int i = 0; i < 6; i++) {
		glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_BYTE, &MyVertexList[4 * i]);
	}

	// 삼각뿔 그리기
	for (int i = 6; i < 10; i++) {
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, &MyVertexList[3 * (i - 6) + 24]);
	}

	glDisable(GL_DEPTH_TEST);
	glFlush();
	glutSwapBuffers();
}

//void UpdateRotation() {
//	// 현재 시간을 측정
//	static int lastTime = 0;
//	int currentTime = glutGet(GLUT_ELAPSED_TIME);
//	float deltaTime = (currentTime - lastTime) / 1000.0f;  // 초 단위로 변환
//
//	// 원하는 FPS (예: 60fps)에 맞춰 회전 속도 조절
//	float rotationSpeed = 30.0f;  // 초당 30도 회전
//	angle += rotationSpeed * deltaTime;
//
//	if (angle > 360.0f)
//		angle -= 360.0f;
//
//	lastTime = currentTime;
//	glutPostRedisplay();
//}

void SetupProjection() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, 1.0, 1.0, 10.0);  // 원근 투영 설정
}

void KB(unsigned char KeyPressed, int X, int Y) {
	switch (KeyPressed) {
	case 'q': case 'Q': eX += 0.1; break;
	case 'w': case 'W': eY += 0.1; break;
	case 'e': case 'E': eZ += 0.1; break;
	case 'a': case 'A': eX -= 0.1; break;
	case 's': case 'S': eY -= 0.1; break;
	case 'd': case 'D': eZ -= 0.1; break;
	case 'r': case 'R': aX += 0.1; break;
	case 't': case 'T': aY += 0.1; break;
	case 'y': case 'Y': aZ += 0.1; break;
	case 'f': case 'F': aX -= 0.1; break;
	case 'g': case 'G': aY -= 0.1; break;
	case 'h': case 'H': aZ -= 0.1; break;
	case 'u': case 'U': uX += 0.1; break;
	case 'i': case 'I': uY += 0.1; break;
	case 'o': case 'O': uZ += 0.1; break;
	case 'j': case 'J': uX -= 0.1; break;
	case 'k': case 'K': uY -= 0.1; break;
	case 'l': case 'L': uZ -= 0.1; break;
	}
	printf("eye(%.2f, %.2f, %.2f) at(%.2f, %.2f, %.2f) up(%.2f, %.2f, %.2f)\n", eX, eY, eZ, aX, aY, aZ, uX, uY, uZ);
	glutPostRedisplay();
}

// 화살표 키 입력에 따른 각도 조절
void SpecialKeys(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_RIGHT:
		angleY += 5.0f;  // Y축으로 회전 (좌우 회전)
		break;
	case GLUT_KEY_LEFT:
		angleY -= 5.0f;  // Y축으로 반대 방향 회전
		break;
	case GLUT_KEY_UP:
		angleX += 5.0f;  // X축으로 회전 (위로 회전)
		break;
	case GLUT_KEY_DOWN:
		angleX -= 5.0f;  // X축으로 반대 방향 회전
		break;
	}
	glutPostRedisplay();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);  // 더블 버퍼링과 깊이 버퍼 사용
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("OpenGL Rotating Cube");

	glClearColor(1.0, 1.0, 1.0, 1.0);

	SetupProjection();  // 원근 투영 설정
	glutDisplayFunc(MyDisplay);
	glutSpecialFunc(SpecialKeys);  // 화살표 키 입력 설정
	glutKeyboardFunc(KB);
	glutMainLoop();
	return 0;
}
