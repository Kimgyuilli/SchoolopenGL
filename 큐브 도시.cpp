#define _USE_MATH_DEFINES
#include <gl/glut.h>
#include <gl/gl.h>
#include <gl/glu.h>
#include <math.h>

// ���� ������ ������ ��ġ�� ������ ����
GLfloat LightPosition0[] = { 0.0, 20.0, -20.0, 1.0 }; // 0�� ������ ��ġ (������)
GLfloat LightPosition1[] = { 0.0, 50.0, 0.0, 1.0 }; // �ٴ� �߽� ���� ����Ʈ����Ʈ ��ġ
GLfloat LightDirection1[] = { 0.0, -1.0, -1.0 };    // �Ʒ� ����

// 0�� ���� �ʱ�ȭ �Լ� (������)
void InitLight0() {
    // ������ �� Ư���� ����
    GLfloat light0_ambient[] = { 0.2, 0.2, 0.2, 1.0 }; // ���� �ֺ��� (��ü���� �⺻ ���)
    GLfloat light0_diffuse[] = { 0.8, 0.8, 0.8, 1.0 }; // ���� Ȯ�걤 (��ü ǥ���� ���)
    GLfloat light0_specular[] = { 1.0, 1.0, 1.0, 1.0 }; // ���� �ݻ籤 (��¦�� ȿ��)

    glEnable(GL_LIGHT0); // 0�� ���� Ȱ��ȭ
    //glLightfv(GL_LIGHT0, GL_AMBIENT, light0_ambient); // �ֺ��� ����
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light0_diffuse); // Ȯ�걤 ����
    glLightfv(GL_LIGHT0, GL_SPECULAR, light0_specular); // �ݻ籤 ����
    glLightfv(GL_LIGHT0, GL_POSITION, LightPosition0); // ������ ��ġ ����
}

void InitLight1() {
    GLfloat light1_ambient[] = { 0.0, 0.0, 0.0, 1.0 }; // �ֺ��� ����
    GLfloat light1_diffuse[] = { 10.0, 10.0, 10.0, 1.0 }; // ���� Ȯ�걤
    GLfloat light1_specular[] = { 10.0, 10.0, 10.0, 1.0 }; // ���� �ݻ籤

    glEnable(GL_LIGHT1);
    glLightfv(GL_LIGHT1, GL_AMBIENT, light1_ambient);  // �ֺ��� ����
    glLightfv(GL_LIGHT1, GL_DIFFUSE, light1_diffuse);  // Ȯ�걤 ����
    glLightfv(GL_LIGHT1, GL_SPECULAR, light1_specular); // �ݻ籤 ����
    glLightfv(GL_LIGHT1, GL_POSITION, LightPosition1); // ��ġ ����
    glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, LightDirection1); // ���� ����

    glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 30.0);   // ���� Ȯ�� ����
    glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 50.0); // ���ߵ� ����
}

// ����(Material) �ʱ�ȭ �Լ�
void InitMaterial() {
    GLfloat material_ambient[] = { 0.0, 0.0, 0.0, 1.0 }; // �ֺ��� ����
    GLfloat material_diffuse[] = { 0.7, 0.7, 0.7, 1.0 }; // Ȯ�걤 �ݻ�
    GLfloat material_specular[] = { 1.0, 1.0, 1.0, 1.0 }; // ���� �ݻ籤
    GLfloat material_shininess[] = { 50.0 };              // ��¦�� ����

    glMaterialfv(GL_FRONT, GL_AMBIENT, material_ambient);  // �ֺ��� ����
    glMaterialfv(GL_FRONT, GL_DIFFUSE, material_diffuse);  // Ȯ�걤 �ݻ� ����
    glMaterialfv(GL_FRONT, GL_SPECULAR, material_specular);// �ݻ籤 ����
    glMaterialfv(GL_FRONT, GL_SHININESS, material_shininess); // ��¦�� ����
}

// ���� �ʱ�ȭ �Լ�
void InitLighting() {
    glEnable(GL_LIGHTING);      // ���� Ȱ��ȭ
    glEnable(GL_DEPTH_TEST);    // ���� �׽�Ʈ Ȱ��ȭ
    glEnable(GL_COLOR_MATERIAL); // ����� ���� ����
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
    GLfloat global_ambient[] = { 0.0, 0.0, 0.0, 1.0 };
    //glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient); //���� �ֺ��� ����

    //InitLight0();               // 0�� ���� Ȱ��ȭ ����
    InitLight1();               // 1�� ���� (����Ʈ����Ʈ) Ȱ��ȭ
    InitMaterial();             // ���� �ʱ�ȭ
}

void DrawDividedFloor(float width, float depth, int rows, int cols) {
    float cellWidth = width / cols; // �� ���� �ʺ�
    float cellDepth = depth / rows; // �� ���� ����

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // �� ���� ���� ��ǥ ���
            float x_start = -width / 2 + j * cellWidth;
            float z_start = -depth / 2 + i * cellDepth;

            // �� �׸���
            glBegin(GL_QUADS);
            glNormal3f(0.0f, 1.0f, 0.0f); // ���� ���� (���� ����)
            glColor3f(1.0f, 1.0f, 0.5f); // �� ���� (���� ȸ��)

            glVertex3f(x_start, -0.1f, z_start);                   // ���� �Ʒ�
            glVertex3f(x_start + cellWidth, -0.1f, z_start);       // ������ �Ʒ�
            glVertex3f(x_start + cellWidth, -0.1f, z_start + cellDepth); // ������ ��
            glVertex3f(x_start, -0.1f, z_start + cellDepth);       // ���� ��

            glEnd();
        }
    }
}


void MyDisplay() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // ī�޶� ����
    gluLookAt(0.0, 20.0, 50.0,  // ī�޶� ��ġ
        0.0, 0.0, 0.0,     // ī�޶� �ٶ󺸴� �߽���
        0.0, 1.0, 0.0);    // ���� ����

    // �ٴ� �׸���
    glPushMatrix();
    glPushMatrix();
    DrawDividedFloor(180.0f, 180.0f, 100, 100); // �ʺ� 180, ���� 180, 10x10 �׸���
    glPopMatrix();
    glPopMatrix();

    GLfloat radius = 65.0; // ���� �߽��� ��ġ�� ���� ������

    for (int r = 0; r < 8; r++) {
        glPushMatrix();
        // �� ������ �߽� ��ǥ ���
        GLfloat angle = r * 45.0; // 8���� ������ �յ� ��ġ (360 / 8 = 45��)
        GLfloat x_c = radius * cos(angle * M_PI / 180.0);
        GLfloat z_c = radius * sin(angle * M_PI / 180.0);

        glTranslated(x_c, 0, z_c);   // ���� �߽� �̵�
        glRotated(angle, 0, 1, 0);  // ���� ȸ��

        // ť�� �迭 ����
        for (int i = 0; i < 7; i++) {
            for (int j = 0; j < 7; j++) {
                glPushMatrix();
                glTranslated((i - 3) * 5, 0, (j - 3) * 5); // ť�� ��ġ ����
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
        glPopMatrix();
    }
    glFlush();
}


void MyReshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION); // ���� ���
    glLoadIdentity();            // �׵� ��� �ε�
    glOrtho(-100, 100, -100, 100, -50, 1000.0); // ���� ����
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(100, 100);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
    glutCreateWindow("OpenGL Cube with Orthographic Projection");

    InitLighting(); // ���� �ʱ�ȭ
    glutDisplayFunc(MyDisplay);
    glutReshapeFunc(MyReshape);

    glutMainLoop();
    return 0;
}
