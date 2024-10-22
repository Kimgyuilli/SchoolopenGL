#include <gl/glut.h>
#include <gl/gl.h>
#include <gl/glu.h>
#include <stdio.h>

float angleX = 0.0f;  // X�� ȸ�� ����
float angleY = 0.0f;  // Y�� ȸ�� ����
GLfloat eX = 0.0;
GLfloat eY = 0.0;
GLfloat eZ = 3.0; // ī�޶� z�� �������� �ڷ� �̵�
GLfloat aX = 0.0;
GLfloat aY = 0.0;
GLfloat aZ = 0.0; // ������ �ٶ󺸵��� ����
GLfloat uX = 0.0;
GLfloat uY = 1.0;
GLfloat uZ = 0.0;

// ���� ������ü�� ���� (0-7) + �ﰢ���� ������ (8)
GLfloat MyVertices[10][3] = {
	// ������ü�� ���� (0-7)
	{-0.25,-0.25,0.25}, {-0.25,0.25,0.25}, {0.25,0.25,0.25}, {0.25,-0.25,0.25},
	{-0.25,-0.25,-0.25}, {-0.25,0.25,-0.25}, {0.25,0.25,-0.25}, {0.25,-0.25,-0.25},
	// �ﰢ���� ������ (8)
	{0.0, 0.75, -0.125},  // ������ü ���� ��ġ�� �ﰢ���� ����
	{0.0,0.25,0.25},
};

// ������ü�� ���� (0-7) + �ﰢ�� �������� ���� (8)
GLfloat MyColors[9][3] = {
	// ������ü�� ����
	{0.8,0.8,0.8}, {0.8,0.8,0.8}, {0.8,0.8,0.8}, {0.8,0.8,0.8},
	{0.2,0.2,0.2}, {0.2,0.2,0.2}, {0.2,0.2,0.2}, {0.2,0.2,0.2},
	// �ﰢ���� ����
	{1.0,0.0,0.0}  // ������
};

// ������ü�� �� (24�� ����) + �ﰢ���� �� (12�� ����)
GLubyte MyVertexList[33] = {
	// ������ü�� �� (0-23)
	0,4,7,3, 4,5,6,7, 0,1,5,4, 0,3,2,1, 2,3,7,6, 1,2,6,5,
	// �ﰢ���� �� (24-33) - ������ü ������ �� �������� �ﰢ���� �������� 3���� �ﰢ�� �����
	5,8,6,  // �ո�
	6,8,9,  // �����ʸ� (1���� 2�� ���̿� ����)
	9,8,5   // ���ʸ�
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
	// ��ü ȸ��
	glRotatef(angleX, 1.0f, 0.0f, 0.0f); // X�� ȸ��
	glRotatef(angleY, 0.0f, 1.0f, 0.0f); // Y�� ȸ��
	// ������ü �׸���
	for (int i = 0; i < 6; i++) {
		glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_BYTE, &MyVertexList[4 * i]);
	}

	// �ﰢ�� �׸���
	for (int i = 6; i < 10; i++) {
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, &MyVertexList[3 * (i - 6) + 24]);
	}

	glDisable(GL_DEPTH_TEST);
	glFlush();
	glutSwapBuffers();
}

//void UpdateRotation() {
//	// ���� �ð��� ����
//	static int lastTime = 0;
//	int currentTime = glutGet(GLUT_ELAPSED_TIME);
//	float deltaTime = (currentTime - lastTime) / 1000.0f;  // �� ������ ��ȯ
//
//	// ���ϴ� FPS (��: 60fps)�� ���� ȸ�� �ӵ� ����
//	float rotationSpeed = 30.0f;  // �ʴ� 30�� ȸ��
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
	gluPerspective(45.0, 1.0, 1.0, 10.0);  // ���� ���� ����
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

// ȭ��ǥ Ű �Է¿� ���� ���� ����
void SpecialKeys(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_RIGHT:
		angleY += 5.0f;  // Y������ ȸ�� (�¿� ȸ��)
		break;
	case GLUT_KEY_LEFT:
		angleY -= 5.0f;  // Y������ �ݴ� ���� ȸ��
		break;
	case GLUT_KEY_UP:
		angleX += 5.0f;  // X������ ȸ�� (���� ȸ��)
		break;
	case GLUT_KEY_DOWN:
		angleX -= 5.0f;  // X������ �ݴ� ���� ȸ��
		break;
	}
	glutPostRedisplay();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);  // ���� ���۸��� ���� ���� ���
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("OpenGL Rotating Cube");

	glClearColor(1.0, 1.0, 1.0, 1.0);

	SetupProjection();  // ���� ���� ����
	glutDisplayFunc(MyDisplay);
	glutSpecialFunc(SpecialKeys);  // ȭ��ǥ Ű �Է� ����
	glutKeyboardFunc(KB);
	glutMainLoop();
	return 0;
}
