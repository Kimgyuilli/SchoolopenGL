//#include <GL/glut.h>
//#include <GL/GL.h>
//#include <GL/GLU.h>
//#include <string.h>
//#include <math.h>
//
//GLfloat red = 1.0f, green = 0.0f, blue = 0.0f;
//GLfloat s11 = 100, s12 = 110, s21 = 300, s22 = 310;
//
//
//// ������ ũ�� ���� �� ȣ��Ǵ� �Լ� (����Ʈ ũ�� ����)
//void ResizeViewport(int w, int h) {
//    // �������� ���̳� ���̰� 0�� �Ǵ� ���� ����
//    if (h == 0) h = 1;
//
//    // ����Ʈ ���� (x, y, width, height)
//    glViewport(0, 0, w, h);
//
//    // ���� ��� �ʱ�ȭ
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//
//    // �������� ��Ⱦ�� �°� ��ǥ�� ����
//    gluOrtho2D(0.0, w, 0.0, h);
//
//    // �𵨺� ��ķ� ����
//    glMatrixMode(GL_MODELVIEW);
//}
//
//void DisplayMultiple() {
//    // ȭ���� ������� Ŭ����
//    glClear(GL_COLOR_BUFFER_BIT);
//
//    // ������ �簢�� �׸���
//    glColor3f(1.0f, 0.0f, 0.0f);
//    glBegin(GL_QUADS);
//    glVertex2f(s11, s11);  // ���ϴ�
//    glVertex2f(s12, s11);  // ���ϴ�
//    glVertex2f(s12, s12);  // ����
//    glVertex2f(s11, s12);  // �»��
//    glEnd();
//
//    glBegin(GL_QUADS);
//    glVertex2f(s21, s21);  // ���ϴ�
//    glVertex2f(s22, s21);  // ���ϴ�
//    glVertex2f(s22, s22);  // ����
//    glVertex2f(s21, s22);  // �»��
//    glEnd();
//
//    // ���۸� ��ü�Ͽ� �׸� ������ ȭ�鿡 ǥ��
//    glutSwapBuffers();
//}
//
////void timer(int value) {
////    if (is_running) {
////        if (angle <= -360.0f) {
////            angle = 0.0f;
////        }
////
////        if (tick_count >= 4) {
////            tick_count = 0;
////            if (red == 1.0f) {
////                red = 0.0f; blue = 1.0f;
////            }
////            else {
////                red = 1.0f; blue = 0.0f;
////            }
////        }
////        glutPostRedisplay();
////    }
////    glutTimerFunc(10, timer, 0);
////}
//
//int main(int argc, char** argv) {
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
//    glutInitWindowSize(640, 480);  // ������ ũ��
//    glutInitWindowPosition(100, 100);  // ������ ���� ��ġ
//    glutCreateWindow("OpenGL Viewport Example");
//
//    // ������ ������� ����
//    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
//
//    // ���÷��� �ݹ� �Լ� ���
//    glutDisplayFunc(DisplayMultiple);
//
//    // ������ ũ�� ���� �� ȣ��� �ݹ� �Լ� ���
//    glutReshapeFunc(ResizeViewport);
//
//    // ���� ���� ����
//    glutMainLoop();
//    return 0;
//}
