//#include <GL/glut.h>
//#include <GL/GL.h>
//#include <GL/GLU.h>
//#include <stdlib.h>
//#include <time.h>
//
//GLfloat angle = 0.0f;
//int grid_size = 5;      // ������ ũ��
//int square_size = 40;   // �� �簢���� ũ��
//GLfloat colors[5][5][3]; // ���� ���� ���� (R, G, B)
//int black_i = 0, black_j = 0; // ������ ������ ��ġ
//
//// ������ ũ�� ���� �� ȣ��Ǵ� �Լ�
//void ResizeViewport(int w, int h) {
//    if (h == 0) h = 1;
//    glViewport(0, 0, w, h);
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluOrtho2D(0.0, w, 0.0, h);
//}
//
//// �簢�� �׸��� �Լ�
//void DrawSquare(int i, int j) {
//    glBegin(GL_QUADS);
//    glVertex2f(150 + i * square_size, 150 + j * square_size);  // ���ϴ�
//    glVertex2f(150 + (i + 1) * square_size, 150 + j * square_size);  // ���ϴ�
//    glVertex2f(150 + (i + 1) * square_size, 150 + (j + 1) * square_size);  // ����
//    glVertex2f(150 + i * square_size, 150 + (j + 1) * square_size);  // �»��
//    glEnd();
//}
//
//// ���� �׸��� �Լ�
//void DisplayMultiple() {
//    glClear(GL_COLOR_BUFFER_BIT);
//    // ���� �׸���
//    for (int i = 0; i < grid_size; ++i) {
//        for (int j = 0; j < grid_size; ++j) {
//            glColor3f(colors[i][j][0], colors[i][j][1], colors[i][j][2]); // ���� ����
//            DrawSquare(i, j);
//        }
//    }
//    glutSwapBuffers();
//}
//
//// ���콺 Ŭ�� �̺�Ʈ ó��
//void MouseClick(int button, int state, int x, int y) {
//    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
//        int i = (x - 150) / square_size;
//        int j = (grid_size - 1) - ((y - 150) / square_size);  // y ��ǥ ��ȯ
//
//        if (i >= 0 && i < grid_size && j >= 0 && j < grid_size) {
//            // Ŭ���� ���ڰ� ������ ���ڿ� ������ ���
//            if ((i == black_i && j == black_j + 1) ||  // ��
//                (i == black_i && j == black_j - 1) ||  // �Ʒ�
//                (i == black_i + 1 && j == black_j) ||  // ������
//                (i == black_i - 1 && j == black_j)) {  // ����
//
//                // ���� ��ȯ
//                GLfloat temp[3];
//                for (int k = 0; k < 3; k++) {
//                    temp[k] = colors[black_i][black_j][k];
//                    colors[black_i][black_j][k] = colors[i][j][k];
//                    colors[i][j][k] = temp[k];
//                }
//
//                // ������ ���� ��ġ ������Ʈ
//                black_i = i;
//                black_j = j;
//
//                glutPostRedisplay(); // ȭ�� ����
//            }
//        }
//    }
//}
//
//int main(int argc, char** argv) {
//    srand(time(NULL));  // ���� �õ� �ʱ�ȭ
//
//    // �ʱ� ���� ���� (������ ù ��° ����)
//    for (int i = 0; i < grid_size; ++i) {
//        for (int j = 0; j < grid_size; ++j) {
//            if (i == black_i && j == black_j) {
//                colors[i][j][0] = 0.0f; // R
//                colors[i][j][1] = 0.0f; // G
//                colors[i][j][2] = 0.0f; // B
//            }
//            else {
//                colors[i][j][0] = (GLfloat)rand() / RAND_MAX; // R
//                colors[i][j][1] = (GLfloat)rand() / RAND_MAX; // G
//                colors[i][j][2] = (GLfloat)rand() / RAND_MAX; // B
//            }
//        }
//    }
//
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
//    glutInitWindowSize(480, 480);  // ������ ũ��
//    glutInitWindowPosition(100, 100);  // ������ ���� ��ġ
//    glutCreateWindow("OpenGL Color Change Game");
//    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
//    glutDisplayFunc(DisplayMultiple);
//    glutReshapeFunc(ResizeViewport);
//    glutMouseFunc(MouseClick);  // ���콺 Ŭ�� �̺�Ʈ ���
//    glutMainLoop();
//    return 0;
//}