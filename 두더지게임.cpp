//#include <GL/glut.h>
//#include <GL/GL.h>
//#include <GL/GLU.h>
//#include <stdlib.h>
//#include <time.h>
//#include <string>
//
//// ���� ����
//const int GRID_SIZE = 3;  // ���� ũ�� (3x3)
//const int SQUARE_SIZE = 100;  // �� �簢���� ũ�� (�ȼ�)
//const int WINDOW_SIZE = GRID_SIZE * SQUARE_SIZE;  // ��ü ������ ũ��
//
//// ���� ���� ����
//int redSquareX = -1, redSquareY = -1;  // ���� �簢���� ��ġ
//int score = 0;  // ���� ����
//bool gameActive = false;  // ���� Ȱ��ȭ ����
//bool draw = false;  // ���� ǥ�� ����
//
//// �簢�� �׸��� �Լ�
//void drawSquare(int x, int y) {
//    glBegin(GL_QUADS);
//    glVertex2f(x * SQUARE_SIZE, y * SQUARE_SIZE);
//    glVertex2f((x + 1) * SQUARE_SIZE, y * SQUARE_SIZE);
//    glVertex2f((x + 1) * SQUARE_SIZE, (y + 1) * SQUARE_SIZE);
//    glVertex2f(x * SQUARE_SIZE, (y + 1) * SQUARE_SIZE);
//    glEnd();
//}
//
//// �ؽ�Ʈ �׸��� �Լ�
//void drawText(float x, float y, const std::string& text) {
//    glRasterPos2f(x, y);
//    for (char c : text) {
//        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
//    }
//}
//
//// ���÷��� �ݹ� �Լ�
//void display() {
//    glClear(GL_COLOR_BUFFER_BIT);
//
//    // ���� �׸���
//    for (int i = 0; i < GRID_SIZE; i++) {
//        for (int j = 0; j < GRID_SIZE; j++) {
//            if (i == redSquareX && j == redSquareY) {
//                glColor3f(1.0f, 0.0f, 0.0f);  // ������ (Ÿ�� �簢��)
//            }
//            else {
//                glColor3f(1.0f, 1.0f, 1.0f);  // ��� (�Ϲ� �簢��)
//            }
//            drawSquare(i, j);
//        }
//    }
//
//    // ���� ǥ�� (draw�� true�� ����)
//    if (draw) {
//        glColor3f(0.0f, 0.0f, 0.0f);  // ������ �ؽ�Ʈ
//        std::string scoreText = "Score: " + std::to_string(score);
//        drawText(10, WINDOW_SIZE - 30, scoreText);
//    }
//
//    glutSwapBuffers();
//}
//
//// ������ ũ�� ���� �ݹ� �Լ�
//void reshape(int w, int h) {
//    glViewport(0, 0, w, h);
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluOrtho2D(0, WINDOW_SIZE, 0, WINDOW_SIZE);
//    glMatrixMode(GL_MODELVIEW);
//}
//
//// ���콺 Ŭ�� �ݹ� �Լ�
//void mouseClick(int button, int state, int x, int y) {
//    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && gameActive) {
//        int gridX = x / SQUARE_SIZE;
//        int gridY = (WINDOW_SIZE - y) / SQUARE_SIZE;
//
//        // Ŭ���� ��ġ�� ���� �簢���� ���
//        if (gridX == redSquareX && gridY == redSquareY) {
//            score++;  // ���� ����
//            redSquareX = -1;  // ���� �簢�� ��ġ �ʱ�ȭ
//            redSquareY = -1;
//            glutPostRedisplay();  // ȭ�� ����
//        }
//    }
//}
//
//// ���� ������Ʈ �Լ� (Ÿ�̸� �ݹ�)
//void updateGame(int value) {
//    if (gameActive) {
//        // ���ο� ���� �簢�� ��ġ ����
//        redSquareX = rand() % GRID_SIZE;
//        redSquareY = rand() % GRID_SIZE;
//        glutPostRedisplay();  // ȭ�� ����
//    }
//    glutTimerFunc(1000, updateGame, 0);  // 1�� �� �ٽ� ȣ��
//}
//
//// ���� ���� �Լ� (Ÿ�̸� �ݹ�)
//void startGame(int value) {
//    //gameActive = true;  // �ڵ� ���� ���� (���� ��Ȱ��ȭ)
//    updateGame(0);  // ���� ������Ʈ ����
//}
//
//// ���� �޴� �ݹ� �Լ�
//void MyMainMenu(int entryID) {
//    if (entryID == 0)
//        gameActive = true;  // ���� ����
//    else if (entryID == 1)
//        draw = !draw;  // ���� ǥ�� ���
//    else if (entryID == 2)
//        exit(0);  // ���α׷� ����
//    glutPostRedisplay();  // ȭ�� ����
//}
//
//// ���� �Լ�
//int main(int argc, char** argv) {
//    srand(time(NULL));  // ���� ������ �ʱ�ȭ
//
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
//    glutInitWindowSize(WINDOW_SIZE, WINDOW_SIZE);
//    glutInitWindowPosition(100, 100);
//    glutCreateWindow("Reaction Game");
//
//    glClearColor(0.8f, 0.8f, 0.8f, 1.0f);  // ���� ���� (���� ȸ��)
//
//    glutDisplayFunc(display);  // ���÷��� �ݹ� ����
//    glutReshapeFunc(reshape);  // ������ ũ�� ���� �ݹ� ����
//    glutMouseFunc(mouseClick);  // ���콺 Ŭ�� �ݹ� ����
//
//    // ���� �޴� ����
//    GLint MyMainMenuID = glutCreateMenu(MyMainMenu);
//    glutAddMenuEntry("start", 0);
//    glutAddMenuEntry("score", 1);
//    glutAddMenuEntry("exit", 2);
//    glutAttachMenu(GLUT_RIGHT_BUTTON);  // ������ ���콺 ��ư�� �޴� ����
//
//    glutTimerFunc(1000, startGame, 0);  // 1�� �� ���� ����
//
//    glutMainLoop();  // �̺�Ʈ ���� ����
//    return 0;
//}