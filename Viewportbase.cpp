//#include <GL/glut.h>
//#include <GL/GL.h>
//#include <GL/GLU.h>
//#include <string.h>
//#include <math.h>
//
//GLfloat red = 1.0f, green = 0.0f, blue = 0.0f;
//GLfloat angle = 0.0f;
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
//
//
//    // ���۸� ��ü�Ͽ� �׸� ������ ȭ�鿡 ǥ��
//    glutSwapBuffers();
//}
//
//int main(int argc, char** argv) {
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
//    glutInitWindowSize(480, 480);  // ������ ũ��
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
