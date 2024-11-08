//#include <GL/glut.h>
//#include <GL/GL.h>
//#include <GL/GLU.h>
//#include <iostream>
//GLfloat angle1 =30.0f;
//GLfloat angle2 = 30.0f;
//GLfloat posX1 = 320.0f; // �簢��1 �ʱ� X ��ġ
//GLfloat posY1 = 240.0f; // �簢��1 �ʱ� Y ��ġ
//GLfloat speedX1 = 0.1f; // X ���� �ӵ�
//GLfloat speedY1 = 0.1f; // Y ���� �ӵ�
//GLfloat posX2 = 370.0f; // �簢��2 �ʱ� X ��ġ
//GLfloat posY2 = 250.0f; // �簢��2 �ʱ� Y ��ġ
//GLfloat speedX2 = -0.1f; // X ���� �ӵ�
//GLfloat speedY2 = -0.1f; // Y ���� �ӵ�
//GLfloat rectSize = 20.0f; // �簢�� �ʱ� ũ��
//GLfloat rotspeed1 = 0.1; //ȸ�� ����, �ӵ�
//GLfloat rotspeed2 = -0.1;
//GLfloat speed = 0.03f; //ũ�� ��ȭ �ӵ�
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
//    posX1 += speedX1;
//    posY1 += speedY1;
//    posX2 += speedX2;
//    posY2 += speedY2;
//
//    // ���� �ε����� �ݴ� �������� �̵�
//    if (posX1 < 0) {
//        posX1 = 0; // ���� ���� �¾��� �� ��ġ ����
//        speedX1 = -speedX1; // X ���� ����
//        rotspeed1 = -rotspeed1;
//    }
//    if (posX1 > 640 - rectSize) {
//        posX1 = 640 - rectSize; // ������ ���� �¾��� �� ��ġ ����
//        speedX1 = -speedX1; // X ���� ����
//        rotspeed1 = -rotspeed1;
//    }
//    if (posY1 < 0) {
//        posY1 = 0; // �Ʒ� ���� �¾��� �� ��ġ ����
//        speedY1 = -speedY1; // Y ���� ����
//        rotspeed1 = -rotspeed1;
//    }
//    if (posY1 > 480 - rectSize) {
//        posY1 = 480 - rectSize; // ���� ���� �¾��� �� ��ġ ����
//        speedY1 = -speedY1; // Y ���� ����
//        rotspeed1 = -rotspeed1;
//    }
//
//    // ���� �ε����� �ݴ� �������� �̵�
//    if (posX2 < 0) {
//        posX2 = 0; // ���� ���� �¾��� �� ��ġ ����
//        speedX2 = -speedX2; // X ���� ����
//        rotspeed2 = -rotspeed2;
//    }
//    if (posX2 > 640 - rectSize) {
//        posX2 = 640 - rectSize; // ������ ���� �¾��� �� ��ġ ����
//        speedX2 = -speedX2; // X ���� ����
//        rotspeed2 = -rotspeed2;
//    }
//    if (posY2 < 0) {
//        posY2 = 0; // �Ʒ� ���� �¾��� �� ��ġ ����
//        speedY2 = -speedY2; // Y ���� ����
//        rotspeed2 = -rotspeed2;
//    }
//    if (posY2 > 480 - rectSize) {
//        posY2 = 480 - rectSize; // ���� ���� �¾��� �� ��ġ ����
//        speedY2 = -speedY2; // Y ���� ����
//        rotspeed2 = -rotspeed2;
//    }
//
//    // �簢�� ũ�� ����
//    rectSize += speed; // �� ������Ʈ���� 1�ȼ��� ����
//    angle1 += rotspeed1;
//    angle2 -= rotspeed2;
//    if (angle1 == 360) {
//        angle1 = 0.0;
//    }
//    if (angle2 == 360) {
//        angle2 = 0.0;
//    }
//}
//
//// ȭ���� �׸��� �Լ�
//void Display() {
//    // ȭ���� ������� Ŭ����
//    glClear(GL_COLOR_BUFFER_BIT);
//    for (int i = 0; i < 2; i++) {
//
//        // ��ȯ �ʱ�ȭ �� ��� ����
//        glLoadIdentity();
//        glPushMatrix();
//
//        // �簢���� �߽��� �������� ȸ����Ű�� ���� �簢�� ��ġ �̵� �� ȸ�� ����
//        if (i == 0) {
//            glTranslatef(posX1 + rectSize / 2, posY1 + rectSize / 2, 0.0f);  // �簢�� �߽����� �̵�
//            glRotatef(angle1, 0.0, 0.0, 1.0);  // Z���� �������� ȸ��
//        }
//        else {
//            glTranslatef(posX2 + rectSize / 2, posY2 + rectSize / 2, 0.0f);  // �簢�� �߽����� �̵�
//            glRotatef(angle2, 0.0, 0.0, 1.0);  // Z���� �������� ȸ��
//        }
//        glTranslatef(-rectSize / 2, -rectSize / 2, 0.0f);  // ȸ�� �� �簢���� ���� ��ġ�� �ǵ�����
//        // �Ķ��� �簢�� �׸���
//        glColor3f(0.0f, 0.0f, 1.0f); // �Ķ���
//        glBegin(GL_QUADS);
//        glVertex2f(0.0f, 0.0f);                   // ���ϴ�
//        glVertex2f(rectSize, 0.0f);               // ���ϴ�
//        glVertex2f(rectSize, rectSize);           // ����
//        glVertex2f(0.0f, rectSize);               // �»��
//        glEnd();
//
//        glPopMatrix();  // ��� ����
//
//    }
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
//void MyKeyboard(unsigned char KeyPressed, int X, int Y) { //Ű���� �Է�
//    switch (KeyPressed) {
//    case 'i': // i �Է½� �ӵ� ����
//        speed += 0.01; break;
//    case 'm': // m �Է½� �ӵ� ����
//        speed -= 0.01;
//        break;
//    }
//    glutPostRedisplay();
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
//    glutKeyboardFunc(MyKeyboard); // Ű���� �Լ� ���
//
//    // Ÿ�̸� �Լ� ���
//    glutTimerFunc(0, Timer, 0);
//
//    // ���� ���� ����
//    glutMainLoop();
//    return 0;
//}
