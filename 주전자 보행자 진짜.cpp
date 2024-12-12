//#define _USE_MATH_DEFINES
//#include <gl/glut.h>
//#include <gl/gl.h>
//#include <gl/glu.h>
//#include <math.h>
//
//
//// ���� ������ ������ ��ġ�� ������ ����
//GLfloat LightPosition0[] = { 0.0, 10.0, 10.0, 1.0 }; // 0�� ������ ��ġ (������)
//
//bool is_running = true;
//float wide = 100.0, tiles = 10.0;
//float move = 0;
//// ī�޶� ���� ���� (�ʱⰪ: z�� -����)
//float cameraDirectionX = 0.0f;
//float cameraDirectionZ = -1.0f;
//
//// ī�޶� ��ġ ����
//float cameraPosX = -90.0f + 9.0f;
//float cameraPosZ = 90.0f - 9.0f;
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
//    glEnable(GL_DEPTH_TEST);   // ���� �׽�Ʈ Ȱ��ȭ
//    glEnable(GL_COLOR_MATERIAL); // ����� ���� ��ȭ
//    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
//
//    InitLight0();              // 0�� ���� �ʱ�ȭ (������)
//    InitMaterial();            // ��ü ���� �ʱ�ȭ
//}
//
//void DrawDividedFloor(float width, float depth, int rows, int cols) {
//    float cellWidth = width / cols; // �� ���� �ʺ�
//    float cellDepth = depth / rows; // �� ���� ����
//    float c = 0.0;
//    for (int i = 0; i < rows; i++) {
//        for (int j = 0; j < cols; j++) {
//            // �� ���� ���� ��ǥ ���
//            float x_start = -width / 2 + j * cellWidth;
//            float z_start = -depth / 2 + i * cellDepth;
//
//            // �� �׸���
//            glBegin(GL_QUADS);
//            glNormal3f(0.0f, 1.0f, 0.0f); // ���� ���� (���� ����)
//            glColor3f(c, c, c); // �� ���� (���� ȸ��)
//
//            glVertex3f(x_start, -0.1f, z_start);                   // ���� �Ʒ�
//            glVertex3f(x_start + cellWidth, -0.1f, z_start);       // ������ �Ʒ�
//            glVertex3f(x_start + cellWidth, -0.1f, z_start + cellDepth); // ������ ��
//            glVertex3f(x_start, -0.1f, z_start + cellDepth);       // ���� ��
//
//            glEnd();
//            if (c < 1) {
//                c += 0.2;
//            }
//            else {
//                c = 0.0;
//            }
//        }
//    }
//}
//
//void MyDisplay() {
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//    glMatrixMode(GL_MODELVIEW);
//    glLoadIdentity();
//
//    // ī�޶� ����
//    gluLookAt(cameraPosX, 10.0f, cameraPosZ,                     // ī�޶� ��ġ
//        cameraPosX + cameraDirectionX, 10.0f, cameraPosZ + cameraDirectionZ, // ī�޶� �ٶ󺸴� ����
//        0.0, 1.0, 0.0);  
//
//    glPushMatrix();
//    DrawDividedFloor(wide, wide, tiles, tiles); // �ʺ� 180, ���� 180, 10x10 �׸���
//    glPopMatrix();
//
//    // ť�� �迭 ����
//    for (int i = -4; i < 6; i++) {
//        for (int j = -4; j < 6; j++) {
//            glPushMatrix();
//            glTranslated(i * 10 - 5, 0, j * 10 - 5); // ť�� ��ġ
//            glScalef(1.5, 1.5, 1.5); // ť�� ũ�� ����
//
//            glutSolidTeapot(1.0); // ũ�� 10�� Teapot ����
//
//            glPopMatrix();
//        }
//    }
//    glFlush();
//}
//
//// Ÿ�̸� �Լ� (����)
//void TimerFunc(int value) {
//    if (is_running) {
//        // ī�޶� ���� �������� ����
//        cameraPosX += cameraDirectionX * (wide / tiles);
//        cameraPosZ += cameraDirectionZ * (wide / tiles);
//    }
//    glutPostRedisplay();       // ȭ�� ���� ��û
//    glutTimerFunc(1000, TimerFunc, 0); // 1�� �Ŀ� �ٽ� ȣ��
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
//// Ű���� �Է� ó�� �Լ� (��ȸ�� �� ��ȸ��)
//void KeyboardFunc(unsigned char key, int x, int y) {
//    float angle; // ȸ�� ���� (����)
//    float newDirX, newDirZ;
//
//    switch (key) {
//    case 'd': // ��ȸ��
//        angle = M_PI / 2; // 90�� (����)
//        newDirX = cameraDirectionX * cos(angle) - cameraDirectionZ * sin(angle);
//        newDirZ = cameraDirectionX * sin(angle) + cameraDirectionZ * cos(angle);
//        cameraDirectionX = newDirX;
//        cameraDirectionZ = newDirZ;
//        break;
//
//    case 'a': // ��ȸ��
//        angle = -M_PI / 2; // -90�� (����)
//        newDirX = cameraDirectionX * cos(angle) - cameraDirectionZ * sin(angle);
//        newDirZ = cameraDirectionX * sin(angle) + cameraDirectionZ * cos(angle);
//        cameraDirectionX = newDirX;
//        cameraDirectionZ = newDirZ;
//        break;
//    }
//    glutPostRedisplay(); // ȭ�� ���� ��û
//}
//
//void MyReshape(int w, int h) {
//    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
//    glMatrixMode(GL_PROJECTION); // ���� ���
//    glLoadIdentity();            // �׵� ��� �ε�
//    gluPerspective(60.0, (GLdouble)w / h, 0.1, 1000.0); // ���� ���� ����
//}
//
//int main(int argc, char** argv) {
//    glutInit(&argc, argv);
//    glutInitWindowSize(800, 800);
//    glutInitWindowPosition(100, 100);
//    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
//    glutCreateWindow("OpenGL Cube with Orthographic Projection");
//
//    InitLighting(); // ���� �ʱ�ȭ
//    glutDisplayFunc(MyDisplay);
//    glutReshapeFunc(MyReshape);
//    glutTimerFunc(500, TimerFunc, 0); // Ÿ�̸� �ݹ� �Լ� ���
//    glutMouseFunc(MyMouseClick); // ���콺 Ŭ�� ó�� �Լ� ���
//    glutKeyboardFunc(KeyboardFunc); // Ű���� �Է� ó�� �Լ� ���
//    glutMainLoop();
//    return 0;
//}
