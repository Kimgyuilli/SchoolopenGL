//#include <GL/glut.h>
//#include <GL/GL.h>
//#include <GL/GLU.h>
//#include <string.h>
//#include <math.h>
//
//GLfloat red = 1.0f, green = 0.0f, blue = 0.0f;
//int isRunning = 0;
//float centerX = 0.0; // �簢���� �߾� X ��ǥ
//float centerY = 0.0; // �簢���� �߾� Y ��ǥ
//
//void DisplayMultiple() {
//    glClear(GL_COLOR_BUFFER_BIT);
//
//    // ��� �簢��
//    glColor3f(1, 0, 0); // ������
//    glBegin(GL_POLYGON); // �簢��
//    glVertex3f(centerX - 0.1, centerY + 0.1, 0.0); // �»�� ��ǥ
//    glVertex3f(centerX - 0.1, centerY - 0.1, 0.0); // ���ϴ� ��ǥ
//    glVertex3f(centerX + 0.1, centerY - 0.1, 0.0); // ���ϴ� ��ǥ
//    glVertex3f(centerX + 0.1, centerY + 0.1, 0.0); // ���� ��ǥ	
//    glEnd();
//
//    glFlush();
//    glutSwapBuffers();
//}
//
//void MyMouseClick(GLint Button, GLint State, GLint X, GLint Y) {
//    if (Button == GLUT_LEFT_BUTTON && State == GLUT_DOWN) {
//        // Ŭ���� ��ġ�� OpenGL ��ǥ��� ��ȯ
//        float normalizedX = (float)(X - 300) / 300; // â�� �߾��� �������� X ��ǥ�� ����ȭ
//        float normalizedY = (float)(300 - Y) / 300; // Y ��ǥ�� ������
//
//        if (isRunning) {
//            // Ŭ���� �������� �簢�� �̵�
//            if (fabs(normalizedX) > fabs(normalizedY)) {
//                // X �������� �̵�
//                centerX += (normalizedX > 0) ? 0.1f : -0.1f;
//            }
//            else {
//                // Y �������� �̵�
//                centerY += (normalizedY > 0) ? 0.1f : -0.1f;
//            }
//        }
//    }
//
//    if (Button == GLUT_RIGHT_BUTTON && State == GLUT_DOWN) {
//        isRunning = !isRunning; // ���¸� ���
//    }
//
//    glutPostRedisplay(); // ȭ�� �ٽ� �׸���
//}
//
//int main(int argc, char** argv) {
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
//    glutInitWindowSize(600, 400);
//    int screenWidth = glutGet(GLUT_SCREEN_WIDTH);
//    int screenHeight = glutGet(GLUT_SCREEN_HEIGHT);
//    glutInitWindowPosition(screenWidth - 600, screenHeight - 450);
//    glutCreateWindow("2020E7008");
//    glClearColor(1.0, 1.0, 1.0, 1.0); // ���� ����
//    glutDisplayFunc(DisplayMultiple);
//    glutMouseFunc(MyMouseClick);
//    glutMainLoop();
//    return 0;
//}
