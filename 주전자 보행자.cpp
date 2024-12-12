//#define _USE_MATH_DEFINES
//#include <gl/glut.h>
//#include <gl/gl.h>
//#include <gl/glu.h>
//#include <math.h>
//
//// ���� ��ġ �� ���� ����
//GLfloat LightPosition0[] = { 0.0, 10.0, 10.0, 1.0 }; // 0�� ������ ��ġ
//GLfloat LightPosition1[] = { 0.0, 20.0, 10.0, 1.0 }; // 1�� ������ ��ġ
//GLfloat LightDirection1[] = { 0.0, -1.0, 0.0 };      // 1�� ������ ���� (�Ʒ��� ����)
//
//// ī�޶� ��ġ �� ȸ�� ����
//GLfloat cameraX = 0.0;         // ī�޶� X�� ��ġ
//GLfloat cameraZ = 50.0;        // ī�޶� Z�� ��ġ
//GLfloat cameraAngle = 0.0;     // ī�޶� ȸ�� ���� (�� ����)
//const GLfloat moveStep = 1.0;  // ī�޶� ���� �ӵ�
//const GLfloat angleStep = 90.0; // ī�޶� ȸ�� ���� ��ȭ��
//bool is_running = 1;           // ī�޶� �����̴��� ���θ� �����ϴ� ����
//
//// ���� �� ���� �ʱ�ȭ �Լ�
//void InitLighting() {
//    glEnable(GL_LIGHTING); // ���� Ȱ��ȭ
//    glEnable(GL_LIGHT0);   // 0�� ���� Ȱ��ȭ
//    glEnable(GL_LIGHT1);   // 1�� ���� Ȱ��ȭ
//    glEnable(GL_DEPTH_TEST); // ���� �׽�Ʈ Ȱ��ȭ (3D ��ü�� �յ� ���� ó��)
//
//    // 0�� ������ Ȯ�걤 ����
//    GLfloat light0_diffuse[] = { 0.8, 0.8, 0.8, 1.0 };
//    glLightfv(GL_LIGHT0, GL_POSITION, LightPosition0);
//    glLightfv(GL_LIGHT0, GL_DIFFUSE, light0_diffuse);
//
//    // 1�� ������ Ȯ�걤 �� ����Ʈ����Ʈ ����
//    GLfloat light1_diffuse[] = { 1.0, 0.5, 0.5, 1.0 };
//    glLightfv(GL_LIGHT1, GL_POSITION, LightPosition1);
//    glLightfv(GL_LIGHT1, GL_DIFFUSE, light1_diffuse);
//    glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, LightDirection1);
//    glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 45.0); // ����Ʈ����Ʈ�� ���� ���� ����
//}
//
//// ȭ�� ��� �Լ�
//void MyDisplay() {
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // ȭ�� �� ���� ���� �ʱ�ȭ
//
//    glMatrixMode(GL_MODELVIEW); // �𵨺� ��� ����
//    glLoadIdentity();           // ��� �ʱ�ȭ
//
//    // ī�޶� ���� ���
//    GLfloat lookX = cameraX + sin(cameraAngle * M_PI / 180.0); // ī�޶� �ٶ󺸴� X�� ����
//    GLfloat lookZ = cameraZ - cos(cameraAngle * M_PI / 180.0); // ī�޶� �ٶ󺸴� Z�� ����
//
//    // ī�޶� ��ġ �� ���� ����
//    gluLookAt(cameraX, 5.0, cameraZ,  // ī�޶� ��ġ (x, y, z)
//        lookX, 5.0, lookZ,      // ī�޶� �ٶ󺸴� �� (x, y, z)
//        0.0, 1.0, 0.0);         // ī�޶��� ���� ���� (y��)
//
//    // ȭ�鿡 Teapot(������) �׸���
//    glutSolidTeapot(10.0); // ũ�� 10�� Teapot ����
//
//    glFlush(); // ������ ��� ����
//}
//
//// â ũ�� ���� ó�� �Լ�
//void MyReshape(int w, int h) {
//    if (h == 0) h = 1; // ���̰� 0�� ��� ����
//    glViewport(0, 0, w, h); // ����Ʈ ����
//    glMatrixMode(GL_PROJECTION); // ���� ��� ����
//    glLoadIdentity(); // ��� �ʱ�ȭ
//    gluPerspective(45.0, (GLdouble)w / h, 0.1, 1000.0); // ���� ���� ����
//}
//
//// ���콺 Ŭ�� ó�� �Լ�
//void MyMouseClick(GLint Button, GLint State, GLint X, GLint Y) {
//    if (Button == GLUT_LEFT_BUTTON && State == GLUT_DOWN) {
//        is_running = !is_running; // ���콺 Ŭ�� �� ������ ���
//
//        glutPostRedisplay(); // ȭ�� ���� ��û
//    }
//}
//
//// Ÿ�̸� �Լ� (0.5�ʸ��� ȣ��)
//void TimerFunc(int value) {
//    if (is_running) {
//        // ī�޶� �ٶ󺸴� �������� ����
//        cameraX += moveStep * sin(cameraAngle * M_PI / 180.0); // X�� �̵�
//        cameraZ -= moveStep * cos(cameraAngle * M_PI / 180.0); // Z�� �̵�
//    }
//    glutPostRedisplay();       // ȭ�� ���� ��û
//    glutTimerFunc(500, TimerFunc, 0); // 500ms(0.5��) �Ŀ� �ٽ� ȣ��
//}
//
//// Ű���� �Է� ó�� �Լ�
//void KeyboardFunc(unsigned char key, int x, int y) {
//    switch (key) {
//    case 'd': // ī�޶� ��ȸ��
//        cameraAngle += angleStep; // ȸ�� ���� ����
//        if (cameraAngle >= 360.0) cameraAngle -= 360.0; // 360�� �ʰ� �� �ʱ�ȭ
//        break;
//    case 'a': // ī�޶� ��ȸ��
//        cameraAngle -= angleStep; // ȸ�� ���� ����
//        if (cameraAngle < 0.0) cameraAngle += 360.0; // 0�� �̸� �� �ʱ�ȭ
//        break;
//    }
//    glutPostRedisplay(); // ȭ�� ���� ��û
//}
//
//// ���� �Լ�
//int main(int argc, char** argv) {
//    glutInit(&argc, argv); // GLUT �ʱ�ȭ
//    glutInitWindowSize(800, 800); // â ũ�� ����
//    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH); // ������ ��� ����
//    glutCreateWindow("OpenGL Camera Movement Example"); // â ����
//
//    InitLighting(); // ���� �� ���� �ʱ�ȭ
//    glutDisplayFunc(MyDisplay); // ���÷��� �ݹ� �Լ� ���
//    glutReshapeFunc(MyReshape); // â ũ�� ���� ó�� �Լ� ���
//    glutKeyboardFunc(KeyboardFunc); // Ű���� �Է� ó�� �Լ� ���
//    glutTimerFunc(500, TimerFunc, 0); // Ÿ�̸� �ݹ� �Լ� ���
//    glutMouseFunc(MyMouseClick); // ���콺 Ŭ�� ó�� �Լ� ���
//    glutMainLoop(); // �̺�Ʈ ���� ����
//    return 0;
//}
