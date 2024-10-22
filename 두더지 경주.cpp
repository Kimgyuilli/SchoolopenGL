//#include <GL/glut.h>
//#include <GL/GL.h>
//#include <GL/GLU.h>
//#include <stdlib.h> // rand() �Լ� ���
//#include <time.h>   // ���� ������ ���� �ð� �ʱ�ȭ
//
//// ���� �� ȸ�� ���� ����
//GLfloat red = 1.0f, green = 0.0f, blue = 0.0f;
//GLfloat angle = 0.0f;
//int tick_count = 0;
//int is_running = 1; // �ð� �۵� ���θ� ��Ÿ���� ���� (1: �۵�, 0: ����)
//int numberOfBoxes = 6; // �׸� ����
//int boxSize = 10; // �׸� ũ�� (10x10 �ȼ�)
//float boxPositions[6]; // �� �׸��� x ��ǥ�� �����ϴ� �迭
//int boxFinish[6];
//float Distance = 1.0f; // �׸� �̵��Ÿ�
//
//// â ũ�Ⱑ ����� �� ȣ��Ǵ� �Լ�
//void reshape(int width, int height) {
//    glViewport(0, 0, width, height); // ���ο� â ũ�⿡ ���� ����Ʈ ����
//    glMatrixMode(GL_PROJECTION); // ���� ��� ���� ����
//    glLoadIdentity(); // ���� ��� �ʱ�ȭ
//    gluOrtho2D(0.0, width, 0.0, height); // 2D ���� ���� ���� (��ǥ�踦 â ũ�⿡ ����)
//    glMatrixMode(GL_MODELVIEW); // �ٽ� �𵨺� ��� ���� ����
//}
//
//// ȭ���� �׸��� �Լ�
//void DisplayMultiple() {
//    glClear(GL_COLOR_BUFFER_BIT); // ȭ���� ����
//
//
//
//    // ������ 6���� �׸� �׸��� (���� 10x10 �ȼ�)
//    for (int i = 0; i < numberOfBoxes; i++) {
//        float x = boxPositions[i]; // �� �׸��� x ��ǥ
//        float y = 480 - (i + 1) * (boxSize + 50); // �� �׸� �� 50�ȼ� �������� ������ �Ʒ��� ��ġ ����
//        glColor3f(0, 0, 1); // �׸� �Ķ������� ����
//        if (boxFinish[i]) { // �ڽ��� �ѹ��� ��������
//            glColor3f(1, 0, 0); // �׸� ���������� ����
//        }
//        glPushMatrix(); // ���� ��� ���� ����
//        glTranslatef(x, y, 0.0f); // �׸� x, y ��ǥ�� �̵�
//        glBegin(GL_POLYGON); // �ٰ���(�簢��) �׸��� ����
//        glVertex2f(0.0f, 0.0f); // ���� �ϴ�
//        glVertex2f(0.0f, boxSize); // ���� ���
//        glVertex2f(boxSize, boxSize); // ���� ���
//        glVertex2f(boxSize, 0.0f); // ���� �ϴ�
//        glEnd(); // �ٰ��� �׸��� ��
//        glPopMatrix(); // ���� ��� ���� ����
//    }
//
//    glutSwapBuffers(); // ȭ���� ��ü (���� ���۸�)
//}
//
//void MyKeyboard(unsigned char KeyPressed, int X, int Y) { //Ű���� �Է�
//    switch (KeyPressed) {
//    case 'i': // i �Է½� �ӵ� ����
//        Distance += 1; break;
//    case 'm': // m �Է½� �ӵ� ����
//        Distance -= 1; break;
//    }
//    glutPostRedisplay();
//}
//
//void MyMouseClick(GLint Button, GLint State, GLint X, GLint Y) {
//    if (Button == GLUT_LEFT_BUTTON && State == GLUT_DOWN) {
//        // Ŭ���� ��ġ�� Y ��ǥ�� ��ȯ (OpenGL ��ǥ��� ������ ���� �ϴ�)
//        float clickY = 480 - Y; // Y ��ǥ ��ȯ
//
//        // �׸��� ���� �ȿ� Ŭ���� ��ġ�� �ִ��� Ȯ��
//        for (int i = 0; i < numberOfBoxes; i++) {
//            float boxY = 480 - (i + 1) * (boxSize + 50); // �� �׸��� Y ��ǥ ���
//            if (clickY >= boxY && clickY <= boxY + boxSize && !boxFinish[i]) {
//                // Ŭ���� Y��ǥ�� �׸��� ���� �ȿ� ���� ���
//                boxPositions[i] = (float)X; // Ŭ���� X ��ǥ�� �׸��� X ��ǥ ����
//                break; // ù ��° �׸� ���� �� ���� ����
//            }
//        }
//        glutPostRedisplay(); // ȭ���� �ٽ� �׸����� ��û
//    }
//}
//
//// Ÿ�̸� �Լ� (0.01�ʸ��� ȣ���)
//void timer(int value) {
//    if (is_running) {
//        // 0.01�ʸ��� ������ �׸� �ϳ��� ���������� 1�ȼ� �̵�
//        int randomBox = rand() % numberOfBoxes; // 0���� numberOfBoxes-1 ������ ������ �׸� ����
//        if (boxPositions[randomBox] > 640) { //���� �����ϸ� ��ġ �ʱ�ȭ
//            boxPositions[randomBox] = 10.0f;
//            boxFinish[randomBox] = 1;
//        }
//        if (!boxFinish[randomBox]) //�������� ���� �׸� �̵� x ��ǥ�� 1�ȼ� ����
//        {
//            boxPositions[randomBox] += Distance;
//        }
//        glutPostRedisplay(); // ȭ���� �ٽ� �׸����� ��û (���÷��� �Լ� ȣ��)
//    }
//
//    glutTimerFunc(10, timer, 0); // 0.01��(10�и���)���� Ÿ�̸� �Լ� �ٽ� ȣ��
//}
//
//// ���� �Լ�
//int main(int argc, char** argv) {
//    srand(time(0)); // ���� ������ ���� �õ� �ʱ�ȭ (���� �ð� ���)
//
//    // �׸���� �ʱ� x ��ǥ�� 10�ȼ��� ���� (���� ������ 10�ȼ� ������ ��ġ)
//    for (int i = 0; i < numberOfBoxes; i++) {
//        boxPositions[i] = 10.0f;
//        boxFinish[i] = 0; //�ڽ� �ʱⰪ
//    }
//
//    glutInit(&argc, argv); // GLUT �ʱ�ȭ
//    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // ���� ���۸��� RGB ��� ����
//    glutInitWindowSize(640, 480); // â ũ�� ����
//    glutInitWindowPosition(0, 0); // â�� �ʱ� ��ġ ����
//    glutCreateWindow("2020E7008 with Viewport"); // â ���� �� ���� ����
//
//    glClearColor(1.0, 1.0, 1.0, 1.0); // ��� ���� ���� (���)
//
//    glutDisplayFunc(DisplayMultiple); // ���÷��� �Լ� ���
//    glutReshapeFunc(reshape); // â ũ�� ���� �� ȣ��� �Լ� ���
//    glutTimerFunc(10, timer, 0); // 0.01�ʸ��� Ÿ�̸� �Լ� ȣ�� ����
//    glutKeyboardFunc(MyKeyboard);
//    glutMouseFunc(MyMouseClick);		
//    glutMainLoop(); // �̺�Ʈ ó�� ���� ���� (���α׷��� ����� ������ ����)
//    return 0;
//}
