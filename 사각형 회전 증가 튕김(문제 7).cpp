//#include <GL/glut.h>
//#include <GL/GL.h>
//#include <GL/GLU.h>
//#include <iostream>
//GLfloat angle =30.0f;
//GLfloat posX = 320.0f; // �簢�� �ʱ� X ��ġ
//GLfloat posY = 240.0f; // �簢�� �ʱ� Y ��ġ
//GLfloat speedX = 0.1f; // X ���� �ӵ�
//GLfloat speedY = 0.1f; // Y ���� �ӵ�
//GLfloat rectSize = 20.0f; // �簢�� �ʱ� ũ��
//
//// ������ ũ�� ���� �� ȣ��Ǵ� �Լ� (����Ʈ ũ�� ����)
//void ResizeViewport(int w, int h) {
//    if (h == 0) h = 1;
//    glViewport(0, 0, w, h);
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluOrtho2D(0.0, w, 0.0, h);
//    glMatrixMode(GL_MODELVIEW);
//}
//
//// �簢���� ��ġ�� ũ�⸦ ������Ʈ�ϰ� �� �浹 ó��
//void UpdatePosition() {
//    // ��ġ ������Ʈ
//    posX += speedX;
//    posY += speedY;
//
//    // ���� �ε����� �ݴ� �������� �̵�
//    if (posX < 0) {
//        posX = 0; // ���� ���� �¾��� �� ��ġ ����
//        speedX = -speedX; // X ���� ����
//    }
//    if (posX > 640 - rectSize) {
//        posX = 640 - rectSize; // ������ ���� �¾��� �� ��ġ ����
//        speedX = -speedX; // X ���� ����
//    }
//    if (posY < 0) {
//        posY = 0; // �Ʒ� ���� �¾��� �� ��ġ ����
//        speedY = -speedY; // Y ���� ����
//    }
//    if (posY > 480 - rectSize) {
//        posY = 480 - rectSize; // ���� ���� �¾��� �� ��ġ ����
//        speedY = -speedY; // Y ���� ����
//    }
//
//    // �簢�� ũ�� ����
//    rectSize += 0.03f; // �� ������Ʈ���� 1�ȼ��� ����
//    angle += 0.1f;
//}
//
//// ȭ���� �׸��� �Լ�
//void Display() {
//    // ȭ���� ������� Ŭ����
//    glClear(GL_COLOR_BUFFER_BIT);
//
//    // ��ȯ �ʱ�ȭ �� ��� ����
//    glLoadIdentity();
//    glPushMatrix();
//
//    // �簢���� �߽��� �������� ȸ����Ű�� ���� �簢�� ��ġ �̵� �� ȸ�� ����
//    glTranslatef(posX + rectSize / 2, posY + rectSize / 2, 0.0f);  // �簢�� �߽����� �̵�
//    glRotatef(angle, 0.0, 0.0, 1.0);  // Z���� �������� ȸ��
//    glTranslatef(-rectSize / 2, -rectSize / 2, 0.0f);  // ȸ�� �� �簢���� ���� ��ġ�� �ǵ�����
//
//    // �Ķ��� �簢�� �׸���
//    glColor3f(0.0f, 0.0f, 1.0f); // �Ķ���
//    glBegin(GL_QUADS);
//    glVertex2f(0.0f, 0.0f);                   // ���ϴ�
//    glVertex2f(rectSize, 0.0f);               // ���ϴ�
//    glVertex2f(rectSize, rectSize);           // ����
//    glVertex2f(0.0f, rectSize);               // �»��
//    glEnd();
//
//    glPopMatrix();  // ��� ����
//
//    // ���۸� ��ü�Ͽ� �׸� ������ ȭ�鿡 ǥ��
//    glutSwapBuffers();
//}
//
//
//// Ÿ�̸� �Լ��� �ִϸ��̼��� ������Ʈ
//void Timer(int value) {
//    UpdatePosition(); // ��ġ �� ũ�� ������Ʈ
//    glutPostRedisplay(); // ȭ�� ���� ��û
//    glutTimerFunc(1, Timer, 0); // 10�и��� �������� Ÿ�̸� ����
//}
//
//int main(int argc, char** argv) {
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
//    glutInitWindowSize(640, 480); // ������ ũ��
//    glutInitWindowPosition(100, 100); // ������ ���� ��ġ
//    glutCreateWindow("OpenGL Rectangle Growth");
//
//    // ������ ������� ����
//    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
//
//    // ���÷��� �ݹ� �Լ� ���
//    glutDisplayFunc(Display);
//
//    // ������ ũ�� ���� �� ȣ��� �ݹ� �Լ� ���
//    glutReshapeFunc(ResizeViewport);
//
//    // Ÿ�̸� �Լ� ���
//    glutTimerFunc(0, Timer, 0);
//
//    // ���� ���� ����
//    glutMainLoop();
//    return 0;
//}
