//#include <gl/glut.h>
//#include <gl/gl.h>
//#include <gl/glu.h>
//
//// ���� ������ ������ ��ġ�� ������ ����
//GLfloat LightPosition0[] = { 0.0, 10.0, 10.0, 1.0 }; // 0�� ������ ��ġ (������)
//GLfloat LightPosition1[] = { -5.0, 10.0, 10.0, 1.0 }; // 1�� ������ ��ġ (����Ʈ����Ʈ)
//GLfloat LightDirection1[] = { 0.0, -1.0, -1.0 };      // 1�� ������ ���� (�Ʒ��� ����)
//
//// 0�� ���� �ʱ�ȭ �Լ� (������)
//void InitLight0() {
//    // ������ �� Ư���� ����
//    GLfloat light0_ambient[] = { 0.2, 0.2, 0.2, 1.0 }; // ���� �ֺ��� (��ü���� �⺻ ���)
//    GLfloat light0_diffuse[] = { 0.8, 0.8, 0.8, 1.0 }; // ���� Ȯ�걤 (��ü ǥ���� ���)
//    GLfloat light0_specular[] = { 1.0, 1.0, 1.0, 1.0 }; // ���� �ݻ籤 (��¦�� ȿ��)
//
//    glEnable(GL_LIGHT0); // 0�� ���� Ȱ��ȭ
//    glLightfv(GL_LIGHT0, GL_AMBIENT, light0_ambient); // �ֺ��� ����
//    glLightfv(GL_LIGHT0, GL_DIFFUSE, light0_diffuse); // Ȯ�걤 ����
//    glLightfv(GL_LIGHT0, GL_SPECULAR, light0_specular); // �ݻ籤 ����
//    glLightfv(GL_LIGHT0, GL_POSITION, LightPosition0); // ������ ��ġ ����
//}
//
//// 1�� ���� �ʱ�ȭ �Լ� (����Ʈ����Ʈ)
//void InitLight1() {
//    // ������ �� Ư���� ����
//    GLfloat light1_ambient[] = { 0.1, 0.1, 0.1, 1.0 }; // ���� �ֺ��� (��ü���� �⺻ ���)
//    GLfloat light1_diffuse[] = { 1.0, 0.5, 0.5, 1.0 }; // ���� Ȯ�걤 (������ �迭�� ���)
//    GLfloat light1_specular[] = { 0.5, 0.5, 0.5, 1.0 }; // ���� �ݻ籤 (����� ��¦�� ȿ��)
//
//    glEnable(GL_LIGHT1); // 1�� ���� Ȱ��ȭ
//    glLightfv(GL_LIGHT1, GL_AMBIENT, light1_ambient); // �ֺ��� ����
//    glLightfv(GL_LIGHT1, GL_DIFFUSE, light1_diffuse); // Ȯ�걤 ����
//    glLightfv(GL_LIGHT1, GL_SPECULAR, light1_specular); // �ݻ籤 ����
//    glLightfv(GL_LIGHT1, GL_POSITION, LightPosition1); // ������ ��ġ ����
//
//    // ����Ʈ����Ʈ �߰� ����
//    glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, LightDirection1); // ����Ʈ����Ʈ ���� ����
//    glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 45.0); // ����Ʈ����Ʈ ������ ���� ���� (45��)
//    glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 2.0); // ����Ʈ����Ʈ ���ߵ� ���� (���� Ŭ���� �߽��� �� ����)
//}
//
//// ����(Material) �ʱ�ȭ �Լ�
//void InitMaterial() {
//    // ��ü ǥ���� �� ���� Ư���� ����
//    GLfloat material_ambient[] = { 0.3, 0.3, 0.3, 1.0 }; // ���� �ֺ��� �ݻ�
//    GLfloat material_diffuse[] = { 0.7, 0.7, 0.7, 1.0 }; // Ȯ�걤 �ݻ� (���)
//    GLfloat material_specular[] = { 1.0, 1.0, 1.0, 1.0 }; // ���� �ݻ籤 (��¦�� ȿ��)
//    GLfloat material_shininess[] = { 50.0 };              // ��¦�� ���� (���� Ŭ���� ��¦���� ������)
//
//    glMaterialfv(GL_FRONT, GL_AMBIENT, material_ambient);  // �ֺ��� �ݻ� ����
//    glMaterialfv(GL_FRONT, GL_DIFFUSE, material_diffuse);  // Ȯ�걤 �ݻ� ����
//    glMaterialfv(GL_FRONT, GL_SPECULAR, material_specular);// �ݻ籤 ����
//    glMaterialfv(GL_FRONT, GL_SHININESS, material_shininess); // ��¦�� ���� ����
//}
//
//// ���� �ʱ�ȭ �Լ�
//void InitLighting() {
//    glEnable(GL_LIGHTING);     // ���� Ȱ��ȭ
//    glEnable(GL_DEPTH_TEST);   // ���� �׽�Ʈ Ȱ��ȭ (3D ��ü�� �յ� ���� ó��)
//    glShadeModel(GL_SMOOTH);   // ���� ���̵� Ȱ��ȭ (�ε巯�� ���� ȿ��)
//    InitLight0();              // 0�� ���� �ʱ�ȭ (������)
//    InitLight1();              // 1�� ���� �ʱ�ȭ (����Ʈ����Ʈ)
//    InitMaterial();            // ��ü ���� �ʱ�ȭ
//}
//
//// ȭ�� ��� �Լ�
//void MyDisplay() {
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // ȭ�� �� ���� ���� �ʱ�ȭ
//
//    glMatrixMode(GL_MODELVIEW); // �𵨺� ��� ����
//    glLoadIdentity();           // ��� �ʱ�ȭ
//
//    // ī�޶� ���� (�� ��ȯ)
//    gluLookAt(0.0, 20.0, 50.0,  // ī�޶� ��ġ (x, y, z)
//              0.0, 0.0, 0.0,    // ī�޶� �ٶ󺸴� �� (x, y, z)
//              0.0, 1.0, 0.0);   // ī�޶��� ���� ���� (y��)
//
//    // Teapot(������) �׸���
//    glutSolidTeapot(10.0); // ũ�� 10�� Teapot ����
//
//    glFlush(); // ������ ��� ����
//}
//
//// â ũ�� ���� ó�� �Լ�
//void MyReshape(int w, int h) {
//    if (h == 0) h = 1; // ���̰� 0�� ��� ���� (������ ���� ����)
//    glViewport(0, 0, w, h); // ����Ʈ ���� (������ ũ�⿡ ����)
//    glMatrixMode(GL_PROJECTION); // ���� ��� ����
//    glLoadIdentity(); // ��� �ʱ�ȭ
//    gluPerspective(45.0, (GLdouble)w / h, 1.0, 1000.0); // ���� ���� ����
//    // 45�� �þ߰�, ȭ�� ���� w/h, ����� 1.0, ����� 1000.0
//}
//
//// ���� �Լ�
//int main(int argc, char** argv) {
//    glutInit(&argc, argv); // GLUT �ʱ�ȭ
//    glutInitWindowSize(800, 800); // â ũ�� ���� (800x800)
//    glutInitWindowPosition(100, 100); // â ��ġ ���� (ȭ�� ���� �� ����)
//    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH); // ������ ��� ���� (���� ����, RGBA, ���� �׽�Ʈ)
//    glutCreateWindow("OpenGL Lighting Example"); // â ���� �� ���� ����
//
//    InitLighting(); // ���� �ʱ�ȭ
//    glutDisplayFunc(MyDisplay); // ���÷��� �ݹ� ��� (ȭ�� ��� �Լ�)
//    glutReshapeFunc(MyReshape); // �������� �ݹ� ��� (â ũ�� ���� �� ȣ��)
//
//    glutMainLoop(); // �̺�Ʈ ���� ����
//    return 0; // ���α׷� ���� �� ��ȯ ��
//}
