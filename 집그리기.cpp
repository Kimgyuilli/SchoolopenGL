//#include <GL/glut.h>
//#include <GL/GL.h>
//#include <GL/GLU.h>
//
//// ���� ���¸� �����ϴ� ����
//GLfloat red = 1.0f, green = 1.0f, blue = 0.0f;
//
//void DisplayMultiple() {
//    glClear(GL_COLOR_BUFFER_BIT);
//
//    // ù ��° ����: �ٰ���
//    glColor3f(red, green, blue); // ���� ����
//    glBegin(GL_POLYGON);
//    glVertex3f(-0.5, -0.5, 0.0);
//    glVertex3f(0.5, -0.5, 0.0);
//    glVertex3f(0.5, 0.4, 0.0);
//    glVertex3f(-0.5, 0.4, 0.0);
//    glVertex3f(0.0, 0.0, 0.5);
//    glEnd();
//
//    // �� ��° ����: �ﰢ��
//    glColor3f(0.0f, 0.0f, 1.0f); // �Ķ���
//    glBegin(GL_TRIANGLES);
//    glVertex3f(-0.7, -0.7, 0.0);
//    glVertex3f(-0.4, -0.1, 0.0);
//    glVertex3f(-0.1, -0.7, 0.0);
//    glEnd();
//
//    // �� ��° ����: �簢��
//    glColor3f(1.0f, 0.0f, 0.0f); // ������
//    glBegin(GL_QUADS);
//    glVertex3f(0.2, 0.2, 0.0);
//    glVertex3f(0.6, 0.2, 0.0);
//    glVertex3f(0.6, 0.6, 0.0);
//    glVertex3f(0.2, 0.6, 0.0);
//    glEnd();
//
//    glFlush();
//}
//
//// Ű���� �Է� ó��
//void Keyboard(unsigned char key, int x, int y) {
//    switch (key) {
//    case 'r': // 'r' Ű �Է� �� ���������� ����
//        red = 1.0f; green = 0.0f; blue = 0.0f;
//        break;
//    case 'g': // 'g' Ű �Է� �� �ʷϻ����� ����
//        red = 0.0f; green = 1.0f; blue = 0.0f;
//        break;
//    case 'b': // 'b' Ű �Է� �� �Ķ������� ����
//        red = 0.0f; green = 0.0f; blue = 1.0f;
//        break;
//    case 'y': // 'y' Ű �Է� �� ��������� ����
//        red = 1.0f; green = 1.0f; blue = 0.0f;
//        break;
//    }
//    glutPostRedisplay(); // ȭ�� �ٽ� �׸��� ��û
//}
//
//void main(int argc, char** argv) {
//    glutInit(&argc, argv);
//    glutCreateWindow("OpenGL Multiple Shapes & Keyboard Interaction");
//    glutDisplayFunc(DisplayMultiple);
//    glutKeyboardFunc(Keyboard); // Ű���� �Է� �ݹ� �Լ� ����
//    glutMainLoop();
//}
