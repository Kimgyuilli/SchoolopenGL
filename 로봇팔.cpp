//#include <GL/glut.h>
//
//void drawArm(); // �� �׸��� �Լ�
//int mode = 0; // 1�̸� ������ �� ����, 2�̸� �����·� ����
//
//void Draw_Body() {
//    // ������ ��������� ǥ��
//    GLUquadric* quadric = gluNewQuadric();
//    gluCylinder(quadric, 0.5, 0.5, 1.0, 20, 20); // ������ 0.5, ���� 1.0�� �����
//    gluDeleteQuadric(quadric);
//}
//
//void Draw_UpperArm() {
//    GLUquadric* quadric = gluNewQuadric();
//    gluCylinder(quadric, 0.3, 0.3, 0.8, 20, 20); // ����� ���� �� ���� �����
//    gluDeleteQuadric(quadric);
//}
//
//void Draw_LowerArm() {
//    GLUquadric* quadric = gluNewQuadric();
//    gluCylinder(quadric, 0.2, 0.2, 0.7, 20, 20); // �Ͽ��� �� ���� �����
//    gluDeleteQuadric(quadric);
//}
//
//void Draw_Hand() {
//    // ���� ���� ǥ��
//    GLUquadric* quadric = gluNewQuadric();
//    gluSphere(quadric, 0.2, 20, 20); // ������ 0.2�� ���� �׷��� ���� ǥ��
//    gluDeleteQuadric(quadric);
//}
//
//
//void display() {
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluPerspective(45.0, 1.0, 0.1, 100.0);  // near ���� 0.1�� ����
//
//    glMatrixMode(GL_MODELVIEW);
//    glLoadIdentity();
//    // ī�޶� ��ġ�� ����
//    gluLookAt(3.0, 3.0, 5.0,  // ī�޶� ��ġ�� �밢�� �������� �̵�
//        0.0, 0.0, 0.0,  // ������ �ٶ�
//        0.0, 1.0, 0.0);
//
//    // ��ü ���� �ణ �̵�
//    glTranslatef(0.0, -1.0, 0.0);  // y������ �ణ �Ʒ��� �̵�
//
//    if (mode == 1) {
//        glPushMatrix();
//        glRotatef(-45, 1.0, 0.0, 0.0);  // ���� 45���� ���ø�
//        drawArm();
//        glPopMatrix();
//    }
//    else if (mode == 2) {
//        drawArm();
//    }
//
//    glutSwapBuffers();
//}
//
//
//void keyboard(unsigned char key, int x, int y) {
//    // Ű���� �Է��� ���� ��带 ����
//    if (key == '1') {
//        mode = 1; // 1�� Ű�� ������ ���� ������ ����
//    }
//    else if (key == '2') {
//        mode = 2; // 2�� Ű�� ������ ���� �����·� ����
//    }
//    glutPostRedisplay(); // ȭ�� ����
//}
//
//void drawArm() {
//    glPushMatrix();
//
//    // ����
//    Draw_Body();
//
//    // ��� (���)
//    glTranslatef(0.0, 0.0, 1.0);
//    glRotatef(90, 1.0, 0.0, 0.0);
//    Draw_UpperArm();
//
//    // �Ͽ� (�Ȳ�ġ)
//    glTranslatef(0.0, 0.0, 0.8);
//    Draw_LowerArm();
//
//    // ��
//    glTranslatef(0.0, 0.0, 0.7);
//    Draw_Hand();
//
//    glPopMatrix();
//}
//
//int main(int argc, char** argv) {
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
//    glutInitWindowSize(500, 500);
//    glutCreateWindow("Arm Movement");
//
//    // ���� ����
//    glEnable(GL_LIGHTING);
//    glEnable(GL_LIGHT0);
//
//    GLfloat light_position[] = { 5.0, 5.0, 5.0, 1.0 };
//    GLfloat light_ambient[] = { 0.2, 0.2, 0.2, 1.0 };
//    GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
//    GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
//
//    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
//    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
//    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
//    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
//
//    // ���� ����
//    GLfloat mat_ambient[] = { 0.7, 0.7, 0.7, 1.0 };
//    GLfloat mat_diffuse[] = { 0.8, 0.8, 0.8, 1.0 };
//    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
//    GLfloat mat_shininess[] = { 100.0 };
//
//    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
//    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
//    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
//    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
//
//    glEnable(GL_DEPTH_TEST);
//    glClearColor(1.0, 1.0, 1.0, 1.0);
//
//    glutDisplayFunc(display);
//    glutKeyboardFunc(keyboard);
//    glutMainLoop();
//    return 0;
//}