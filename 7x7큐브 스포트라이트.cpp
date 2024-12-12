#include <gl/glut.h>
#include <gl/gl.h>
#include <gl/glu.h>

// ���� ������ ������ ��ġ�� ������ ����
GLfloat LightPosition0[] = { 0.0, 10.0, 10.0, 1.0 }; // 0�� ������ ��ġ (������)
GLfloat LightPosition1[] = { 0, 5, 20.0, 1.0 }; // ����Ʈ����Ʈ ��ġ (�߾� ť�� ��)
GLfloat LightDirection1[] = { 0.0, 0.0, -1.0 };       // ����Ʈ����Ʈ ���� (�Ʒ���)

// 0�� ���� �ʱ�ȭ �Լ� (������)
void InitLight0() {
    // ������ �� Ư���� ����
    GLfloat light0_ambient[] = { 0.2, 0.2, 0.2, 1.0 }; // ���� �ֺ��� (��ü���� �⺻ ���)
    GLfloat light0_diffuse[] = { 0.8, 0.8, 0.8, 1.0 }; // ���� Ȯ�걤 (��ü ǥ���� ���)
    GLfloat light0_specular[] = { 1.0, 1.0, 1.0, 1.0 }; // ���� �ݻ籤 (��¦�� ȿ��)

    glEnable(GL_LIGHT0); // 0�� ���� Ȱ��ȭ
    glLightfv(GL_LIGHT0, GL_AMBIENT, light0_ambient); // �ֺ��� ����
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light0_diffuse); // Ȯ�걤 ����
    glLightfv(GL_LIGHT0, GL_SPECULAR, light0_specular); // �ݻ籤 ����
    glLightfv(GL_LIGHT0, GL_POSITION, LightPosition0); // ������ ��ġ ����
}

void InitLight1() {
    GLfloat light1_ambient[] = { 0.1, 0.1, 0.1, 1.0 }; // ���� �ֺ���
    GLfloat light1_diffuse[] = { 1.0, 1.0, 1.0, 1.0 }; // ���� Ȯ�걤
    GLfloat light1_specular[] = { 1.0, 1.0, 1.0, 1.0 }; // ���� �ݻ籤

    glEnable(GL_LIGHT1); // 1�� ���� Ȱ��ȭ
    //glLightfv(GL_LIGHT1, GL_AMBIENT, light1_ambient); // �ֺ��� ����
    glLightfv(GL_LIGHT1, GL_DIFFUSE, light1_diffuse); // Ȯ�걤 ����
    glLightfv(GL_LIGHT1, GL_SPECULAR, light1_specular); // �ݻ籤 ����

    glPushMatrix();
    glLoadIdentity();
    glLightfv(GL_LIGHT1, GL_POSITION, LightPosition1);     // ��ġ ����
    glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, LightDirection1); // ���� ����
    glPopMatrix();

    glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 15.0);  // ����Ʈ����Ʈ ���� ����
    glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 10.0); // ����Ʈ����Ʈ ���ߵ�
}

// ����(Material) �ʱ�ȭ �Լ�
void InitMaterial() {
    // ��ü ǥ���� �� ���� Ư���� ����
    GLfloat material_ambient[] = { 0.3, 0.3, 0.3, 1.0 }; // ���� �ֺ��� �ݻ�
    GLfloat material_diffuse[] = { 0.7, 0.7, 0.7, 1.0 }; // Ȯ�걤 �ݻ� (���)
    GLfloat material_specular[] = { 1.0, 1.0, 1.0, 1.0 }; // ���� �ݻ籤 (��¦�� ȿ��)
    GLfloat material_shininess[] = { 50.0 };              // ��¦�� ���� (���� Ŭ���� ��¦���� ������)

    glMaterialfv(GL_FRONT, GL_AMBIENT, material_ambient);  // �ֺ��� �ݻ� ����
    glMaterialfv(GL_FRONT, GL_DIFFUSE, material_diffuse);  // Ȯ�걤 �ݻ� ����
    glMaterialfv(GL_FRONT, GL_SPECULAR, material_specular);// �ݻ籤 ����
    glMaterialfv(GL_FRONT, GL_SHININESS, material_shininess); // ��¦�� ���� ����
}

// ���� �ʱ�ȭ �Լ�
void InitLighting() {
    glEnable(GL_LIGHTING);     // ���� Ȱ��ȭ
    glEnable(GL_DEPTH_TEST);   // ���� �׽�Ʈ Ȱ��ȭ
    glEnable(GL_COLOR_MATERIAL); // ����� ���� ��ȭ
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

    //glEnable(GL_LIGHT0);       // �⺻ ������ Ȱ��ȭ
    //InitLight0();              // 0�� ���� �ʱ�ȭ (������)
    InitLight1();              // 1�� ���� �ʱ�ȭ (����Ʈ����Ʈ)
    InitMaterial();            // ��ü ���� �ʱ�ȭ
}


void MyDisplay() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // ī�޶� ����
    gluLookAt(30.0, 70.0, 50.0,  // ī�޶� ��ġ
        30.0, 30.0, 0.0,   // ī�޶� �ٶ󺸴� �߽��� (�߾� ť��)
        0.0, 1.0, 0.0);    // ī�޶��� ���� ����

    // ť�� �迭 ����
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            glPushMatrix();
            glTranslated(i * 10, j * 10, 0); // ť�� ��ġ
            glScalef(1.5, 1.5, 1.5); // ť�� ũ�� ����

            glBegin(GL_QUADS);
            // ���� ��
            glColor3f(1.0f, 0.0f, 0.0f);
            glVertex3f(1.0f, 1.0f, -1.0f);
            glVertex3f(-1.0f, 1.0f, -1.0f);
            glVertex3f(-1.0f, 1.0f, 1.0f);
            glVertex3f(1.0f, 1.0f, 1.0f);

            // �Ʒ��� ��
            glColor3f(0.0f, 1.0f, 0.0f);
            glVertex3f(1.0f, -1.0f, 1.0f);
            glVertex3f(-1.0f, -1.0f, 1.0f);
            glVertex3f(-1.0f, -1.0f, -1.0f);
            glVertex3f(1.0f, -1.0f, -1.0f);

            // ���� ��
            glColor3f(0.0f, 0.0f, 1.0f);
            glVertex3f(1.0f, 1.0f, 1.0f);
            glVertex3f(-1.0f, 1.0f, 1.0f);
            glVertex3f(-1.0f, -1.0f, 1.0f);
            glVertex3f(1.0f, -1.0f, 1.0f);

            // ���� ��
            glColor3f(1.0f, 1.0f, 0.0f);
            glVertex3f(1.0f, -1.0f, -1.0f);
            glVertex3f(-1.0f, -1.0f, -1.0f);
            glVertex3f(-1.0f, 1.0f, -1.0f);
            glVertex3f(1.0f, 1.0f, -1.0f);

            // ���� ��
            glColor3f(0.0f, 1.0f, 1.0f);
            glVertex3f(-1.0f, 1.0f, 1.0f);
            glVertex3f(-1.0f, 1.0f, -1.0f);
            glVertex3f(-1.0f, -1.0f, -1.0f);
            glVertex3f(-1.0f, -1.0f, 1.0f);

            // ������ ��
            glColor3f(1.0f, 0.0f, 1.0f);
            glVertex3f(1.0f, 1.0f, -1.0f);
            glVertex3f(1.0f, 1.0f, 1.0f);
            glVertex3f(1.0f, -1.0f, 1.0f);
            glVertex3f(1.0f, -1.0f, -1.0f);
            glEnd();

            glPopMatrix();
        }
    }
    glFlush();
}

void MyReshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION); // ���� ���
    glLoadIdentity();            // �׵� ��� �ε�
    glOrtho(-50, 50, -50, 50, -1.0, 100.0); // ���� ����
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(100, 100);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
    glutCreateWindow("OpenGL Cube with Orthographic Projection");

    InitLighting(); // ���� �ʱ�ȭ
    glutDisplayFunc(MyDisplay);
    glutReshapeFunc(MyReshape);

    glutMainLoop();
    return 0;
}
