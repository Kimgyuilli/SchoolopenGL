//#include <GL/glut.h>
//#include <GL/GL.h>
//#include <GL/GLU.h>
//#include <stdlib.h>
//#include <time.h>
//
//GLfloat angle = 0.0f;
//int grid_size = 5;      // 격자의 크기
//int square_size = 40;   // 각 사각형의 크기
//GLfloat colors[5][5][3]; // 격자 색상 저장 (R, G, B)
//int black_i = 0, black_j = 0; // 검은색 격자의 위치
//
//// 윈도우 크기 변경 시 호출되는 함수
//void ResizeViewport(int w, int h) {
//    if (h == 0) h = 1;
//    glViewport(0, 0, w, h);
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluOrtho2D(0.0, w, 0.0, h);
//}
//
//// 사각형 그리기 함수
//void DrawSquare(int i, int j) {
//    glBegin(GL_QUADS);
//    glVertex2f(150 + i * square_size, 150 + j * square_size);  // 좌하단
//    glVertex2f(150 + (i + 1) * square_size, 150 + j * square_size);  // 우하단
//    glVertex2f(150 + (i + 1) * square_size, 150 + (j + 1) * square_size);  // 우상단
//    glVertex2f(150 + i * square_size, 150 + (j + 1) * square_size);  // 좌상단
//    glEnd();
//}
//
//// 격자 그리기 함수
//void DisplayMultiple() {
//    glClear(GL_COLOR_BUFFER_BIT);
//    // 격자 그리기
//    for (int i = 0; i < grid_size; ++i) {
//        for (int j = 0; j < grid_size; ++j) {
//            glColor3f(colors[i][j][0], colors[i][j][1], colors[i][j][2]); // 색상 설정
//            DrawSquare(i, j);
//        }
//    }
//    glutSwapBuffers();
//}
//
//// 마우스 클릭 이벤트 처리
//void MouseClick(int button, int state, int x, int y) {
//    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
//        int i = (x - 150) / square_size;
//        int j = (grid_size - 1) - ((y - 150) / square_size);  // y 좌표 변환
//
//        if (i >= 0 && i < grid_size && j >= 0 && j < grid_size) {
//            // 클릭된 격자가 검은색 격자와 인접한 경우
//            if ((i == black_i && j == black_j + 1) ||  // 위
//                (i == black_i && j == black_j - 1) ||  // 아래
//                (i == black_i + 1 && j == black_j) ||  // 오른쪽
//                (i == black_i - 1 && j == black_j)) {  // 왼쪽
//
//                // 색상 교환
//                GLfloat temp[3];
//                for (int k = 0; k < 3; k++) {
//                    temp[k] = colors[black_i][black_j][k];
//                    colors[black_i][black_j][k] = colors[i][j][k];
//                    colors[i][j][k] = temp[k];
//                }
//
//                // 검은색 격자 위치 업데이트
//                black_i = i;
//                black_j = j;
//
//                glutPostRedisplay(); // 화면 갱신
//            }
//        }
//    }
//}
//
//int main(int argc, char** argv) {
//    srand(time(NULL));  // 랜덤 시드 초기화
//
//    // 초기 색상 설정 (검은색 첫 번째 격자)
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
//    glutInitWindowSize(480, 480);  // 윈도우 크기
//    glutInitWindowPosition(100, 100);  // 윈도우 시작 위치
//    glutCreateWindow("OpenGL Color Change Game");
//    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
//    glutDisplayFunc(DisplayMultiple);
//    glutReshapeFunc(ResizeViewport);
//    glutMouseFunc(MouseClick);  // 마우스 클릭 이벤트 등록
//    glutMainLoop();
//    return 0;
//}