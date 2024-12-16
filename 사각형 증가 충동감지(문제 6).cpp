//#include <GL/glut.h>
//#include <GL/GL.h>
//#include <GL/GLU.h>
//#include <stdlib.h>
//#include <time.h>
//#include <corecrt_math.h>
//
//// ���� �� ȸ�� ���� ����
//GLfloat red = 1.0f, green = 0.0f, blue = 0.0f;
//GLfloat angle = 0.0f;
//int tick_count = 0;
//int is_running = 1;
//int numberOfBoxes = 2; // ȭ�鿡 ǥ���� �簢���� ����
//float boxSize[2] = { 10.0f, 10.0f }; // �� �簢���� ũ��
//float boxPositions[2][2]; // �� �簢���� x, y ��ǥ�� �����ϴ� 2D �迭
//float boxSpeeds[2][2]; // �� �簢���� x, y ���� �ӵ��� �����ϴ� 2D �迭
//float Distance = 1.0f;
//float speed = 0.1f; // �簢�� ũ�� ���� �ӵ�
//float margin = 5.0f; // �浹 ���� ������
//
//// â�� ũ�Ⱑ �ٲ� �� ȣ��Ǵ� �Լ�
//void reshape(int width, int height) {
//    glViewport(0, 0, width, height); // ����Ʈ ����
//    glMatrixMode(GL_PROJECTION); // ���� ��� ���� ����
//    glLoadIdentity(); // ���� ��� �ʱ�ȭ
//    gluOrtho2D(-100.0, width, -100.0, height); // 2D ���� ���� ����
//    glMatrixMode(GL_MODELVIEW); // �ٽ� �𵨺� ��� ���� ����
//}
//
//// ȭ���� �׸��� �Լ�
//void DisplayMultiple() {
//    glClear(GL_COLOR_BUFFER_BIT); // ȭ���� ����
//
//    for (int i = 0; i < numberOfBoxes; i++) {
//        if (is_running) {
//            boxSize[i] += speed; // �簢�� ũ�� ����
//            // �� �簢���� ��ġ���� Ȯ��
//            for (int j = i + 1; j < numberOfBoxes; j++) {
//                float dx = boxPositions[i][0] - boxPositions[j][0];
//                float dy = boxPositions[i][1] - boxPositions[j][1];
//                float distance = sqrt(dx * dx + dy * dy); // �� �簢�� �� �Ÿ� ���
//                if (distance < boxSize[i] + boxSize[j] - margin) { // ��ġ��
//                    red = 1.0f; // ���������� ����
//                    green = 0.0f;
//                    blue = 0.0f;
//                    is_running = false;
//                    break;
//                }
//                else { // ��ġ�� ������
//                    red = 0.0f; // �Ķ������� ����
//                    green = 0.0f;
//                    blue = 1.0f;
//                }
//            }
//        }
//        // �簢�� �׸���
//        glColor3f(red, green, blue);
//        glPushMatrix();
//        glTranslatef(boxPositions[i][0], boxPositions[i][1], 0.0f); // �簢�� ��ġ�� �̵�
//        glRotatef(0.3f, 1.0f, 1.0f, 0.0f); // �簢�� ȸ��
//        glBegin(GL_POLYGON);
//        glVertex2f(-boxSize[i], -boxSize[i]); // ���� �ϴ�
//        glVertex2f(-boxSize[i], boxSize[i]); // ���� ���
//        glVertex2f(boxSize[i], boxSize[i]); // ���� ���
//        glVertex2f(boxSize[i], -boxSize[i]); // ���� �ϴ�
//        glEnd();
//        glPopMatrix();
//    }
//    glutSwapBuffers(); // ȭ�� ��ü
//}
//
//void MyKeyboard(unsigned char KeyPressed, int X, int Y) { //Ű���� �Է�
//    switch (KeyPressed) {
//    case 'i': // i �Է½� �ӵ� ����
//        speed += 0.01; break;
//    case 'm': // m �Է½� �ӵ� ����
//        speed = (speed > 0.01) ? speed - 0.01 : 0.01; // �ּ� �ӵ� ����
//        break;
//    }
//    glutPostRedisplay();
//}
//
//// ���콺 Ŭ�� �̺�Ʈ ó�� �Լ�
//void MyMouseClick(GLint Button, GLint State, GLint X, GLint Y) {
//    if (Button == GLUT_LEFT_BUTTON && State == GLUT_DOWN) { // ���콺 ���� ��ư�� ������
//        // �簢���� ��ġ�� �������� ����
//        for (int i = 0; i < numberOfBoxes; i++) {
//            boxPositions[i][0] = rand() % 630;
//            boxPositions[i][1] = rand() % 470;
//            boxSize[i] = 10.0f;
//        }
//        is_running = true;
//        glutPostRedisplay(); // ȭ���� �ٽ� �׸����� ��û
//    }
//}
//
//// Ÿ�̸� �Լ� (0.01�ʸ��� ȣ���)
//void timer(int value) {
//    DisplayMultiple(); // ȭ�� �׸��� �Լ� ȣ��
//    glutTimerFunc(1, timer, 0); // 0.01��(10�и���)���� Ÿ�̸� �Լ� �ٽ� ȣ��
//}
//
//// ���� �Լ�
//int main(int argc, char** argv) {
//    srand(time(0)); // ���� ������ ���� �õ� �ʱ�ȭ
//
//    // �簢���� �ʱ� ��ġ�� �ӵ��� �������� ����
//    for (int i = 0; i < numberOfBoxes; i++) {
//        boxPositions[i][0] = rand() % 630;
//        boxPositions[i][1] = rand() % 470;
//        boxSpeeds[i][0] = rand() % 4 - 2;
//        boxSpeeds[i][1] = rand() % 4 - 2;
//    }
//
//    glutInit(&argc, argv); // GLUT �ʱ�ȭ
//    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // ���� ���۸��� RGB ��� ����
//    glutInitWindowSize(640, 480); // â ũ�� ����
//    glutInitWindowPosition(0, 0); // â�� �ʱ� ��ġ ����
//    glutCreateWindow("2020E7008 with Viewport"); // â ���� �� ���� ����
//    glClearColor(1.0, 1.0, 1.0, 1.0); // ��� ���� ���� (���)
//    glutDisplayFunc(DisplayMultiple); // ���÷��� �Լ� ���
//    glutReshapeFunc(reshape); // â ũ�� ���� �� ȣ��� �Լ� ���
//    glutMouseFunc(MyMouseClick); // ���콺 Ŭ�� �̺�Ʈ ó�� �Լ� ���
//    glutKeyboardFunc(MyKeyboard); // Ű���� �Լ� ���
//    glutTimerFunc(10, timer, 0); // 0.01�ʸ��� Ÿ�̸� �Լ� ȣ�� ����
//    glutMainLoop(); // �̺�Ʈ ó�� ���� ����
//    return 0;
//}
