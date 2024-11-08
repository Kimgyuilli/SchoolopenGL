#include <GL/glut.h>
#include <cstdlib>  // rand() �Լ��� ���� ���
#include <ctime>    // time() �Լ��� ���� ���

int posX1, posY1;       // ù ��° �簢���� ��ġ
int posX2, posY2;       // �� ��° �簢���� ��ġ
int squareSize = 2;     // �簢���� �ʱ� ũ��
int sizeIncrement = 1;  // �簢���� Ŀ���� �ӵ�(�ѹ��� �����ϴ� �ȼ� ��)
float backgroundColor[3] = { 1.0f, 1.0f, 1.0f };  // �ʱ� ���� (���)

void initialize() {
    // ���α׷��� ���۵� �� ������ ��ġ�� �����մϴ�.
    posX1 = rand() % 638;  // 640���� ���� ������ �����Ͽ� ȭ���� ����� �ʰ� �մϴ�.
    posY1 = rand() % 478;

    posX2 = rand() % 638;
    posY2 = rand() % 478;

    squareSize = 2;        // �簢�� ũ�⸦ �ʱ�ȭ
    sizeIncrement = 1;     // ũ�� ���� �ӵ��� �ʱ�ȭ
    backgroundColor[0] = 1.0f;  // ������ ������� �ʱ�ȭ
    backgroundColor[1] = 1.0f;
    backgroundColor[2] = 1.0f;
}

void reshape(int width, int height) {
    glViewport(0, 0, 640, 480);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 640, 0, 480);  // 2D ���簢�� ���� ����
}

bool checkCollision() {
    // �� �簢���� ��踦 ���Ͽ� �浹 ���θ� Ȯ��
    return !(posX1 + squareSize < posX2 || posX2 + squareSize < posX1 ||
        posY1 + squareSize < posY2 || posY2 + squareSize < posY1);
}

void display() {
    glClearColor(backgroundColor[0], backgroundColor[1], backgroundColor[2], 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // ù ��° �簢��: ���� ��ġ���� �����ϴ� ũ��
    glBegin(GL_QUADS);
    glColor3f(0.0f, 1.0f, 0.0f);  // ���
    glVertex2i(posX1, posY1);                          // ���� �Ʒ�
    glVertex2i(posX1 + squareSize, posY1);             // ������ �Ʒ�
    glVertex2i(posX1 + squareSize, posY1 + squareSize); // ������ ��
    glVertex2i(posX1, posY1 + squareSize);             // ���� ��
    glEnd();

    // �� ��° �簢��: �ٸ� ���� ��ġ���� �����ϴ� ũ��
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 1.0f);  // �Ķ���
    glVertex2i(posX2, posY2);                          // ���� �Ʒ�
    glVertex2i(posX2 + squareSize, posY2);             // ������ �Ʒ�
    glVertex2i(posX2 + squareSize, posY2 + squareSize); // ������ ��
    glVertex2i(posX2, posY2 + squareSize);             // ���� ��
    glEnd();

    glutSwapBuffers();
}

void updateSize(int value) {
    if (sizeIncrement != 0) { // ������ ������ �ʾ��� ���� ����
        squareSize += sizeIncrement;

        if (checkCollision()) {
            // �浹 �� ������ ���������� �����ϰ� ũ�� ���� ����
            backgroundColor[0] = 1.0f;
            backgroundColor[1] = 0.0f;
            backgroundColor[2] = 0.0f;
            sizeIncrement = 0;
        }
        else {
            // �浹���� ������ ������ ������� ����
            backgroundColor[0] = 1.0f;
            backgroundColor[1] = 1.0f;
            backgroundColor[2] = 1.0f;
        }
    }

    glutPostRedisplay();          // ȭ���� �ٽ� �׸����� ��û
    glutTimerFunc(10, updateSize, 0);  // 0.01�� �Ŀ� updateSize ȣ��
}

void handleKeyPress(unsigned char key, int x, int y) {
    if (key == 'i') {
        sizeIncrement += 1;  // 'i'�� ������ ���� �ӵ��� 1�� ����
    }
    else if (key == 'm') {
        if (sizeIncrement >= 0) {
            sizeIncrement -= 1;  // 'm'�� ������ ���� �ӵ��� 1�� ����, �ּҰ� 1
        }
    }
}

void handleMouseClick(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        initialize(); // ��Ŭ�� �� �ʱ� ���·� �缳��
        glutPostRedisplay(); // ȭ���� �ٽ� �׸����� ��û
    }
}

int main(int argc, char** argv) {
    srand(static_cast<unsigned>(time(0)));  // ������ ������ �ٸ� �õ�� ���� �ʱ�ȭ

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(640, 480);
    glutCreateWindow("OpenGL Expanding Random Positioned Squares");

    initialize();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(handleKeyPress);      // Ű���� �Է� ó�� �Լ� ���
    glutMouseFunc(handleMouseClick);       // ���콺 Ŭ�� ó�� �Լ� ���
    glutTimerFunc(10, updateSize, 0);      // 0.01�� �Ŀ� updateSize ó�� ȣ��
    glutMainLoop();
    return 0;
}
