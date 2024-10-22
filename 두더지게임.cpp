//#include <GL/glut.h>
//#include <GL/GL.h>
//#include <GL/GLU.h>
//#include <stdlib.h>
//#include <time.h>
//#include <string>
//
//// 게임 설정
//const int GRID_SIZE = 3;  // 격자 크기 (3x3)
//const int SQUARE_SIZE = 100;  // 각 사각형의 크기 (픽셀)
//const int WINDOW_SIZE = GRID_SIZE * SQUARE_SIZE;  // 전체 윈도우 크기
//
//// 게임 상태 변수
//int redSquareX = -1, redSquareY = -1;  // 빨간 사각형의 위치
//int score = 0;  // 현재 점수
//bool gameActive = false;  // 게임 활성화 상태
//bool draw = false;  // 점수 표시 여부
//
//// 사각형 그리기 함수
//void drawSquare(int x, int y) {
//    glBegin(GL_QUADS);
//    glVertex2f(x * SQUARE_SIZE, y * SQUARE_SIZE);
//    glVertex2f((x + 1) * SQUARE_SIZE, y * SQUARE_SIZE);
//    glVertex2f((x + 1) * SQUARE_SIZE, (y + 1) * SQUARE_SIZE);
//    glVertex2f(x * SQUARE_SIZE, (y + 1) * SQUARE_SIZE);
//    glEnd();
//}
//
//// 텍스트 그리기 함수
//void drawText(float x, float y, const std::string& text) {
//    glRasterPos2f(x, y);
//    for (char c : text) {
//        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
//    }
//}
//
//// 디스플레이 콜백 함수
//void display() {
//    glClear(GL_COLOR_BUFFER_BIT);
//
//    // 격자 그리기
//    for (int i = 0; i < GRID_SIZE; i++) {
//        for (int j = 0; j < GRID_SIZE; j++) {
//            if (i == redSquareX && j == redSquareY) {
//                glColor3f(1.0f, 0.0f, 0.0f);  // 빨간색 (타겟 사각형)
//            }
//            else {
//                glColor3f(1.0f, 1.0f, 1.0f);  // 흰색 (일반 사각형)
//            }
//            drawSquare(i, j);
//        }
//    }
//
//    // 점수 표시 (draw가 true일 때만)
//    if (draw) {
//        glColor3f(0.0f, 0.0f, 0.0f);  // 검은색 텍스트
//        std::string scoreText = "Score: " + std::to_string(score);
//        drawText(10, WINDOW_SIZE - 30, scoreText);
//    }
//
//    glutSwapBuffers();
//}
//
//// 윈도우 크기 변경 콜백 함수
//void reshape(int w, int h) {
//    glViewport(0, 0, w, h);
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluOrtho2D(0, WINDOW_SIZE, 0, WINDOW_SIZE);
//    glMatrixMode(GL_MODELVIEW);
//}
//
//// 마우스 클릭 콜백 함수
//void mouseClick(int button, int state, int x, int y) {
//    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && gameActive) {
//        int gridX = x / SQUARE_SIZE;
//        int gridY = (WINDOW_SIZE - y) / SQUARE_SIZE;
//
//        // 클릭한 위치가 빨간 사각형인 경우
//        if (gridX == redSquareX && gridY == redSquareY) {
//            score++;  // 점수 증가
//            redSquareX = -1;  // 빨간 사각형 위치 초기화
//            redSquareY = -1;
//            glutPostRedisplay();  // 화면 갱신
//        }
//    }
//}
//
//// 게임 업데이트 함수 (타이머 콜백)
//void updateGame(int value) {
//    if (gameActive) {
//        // 새로운 빨간 사각형 위치 설정
//        redSquareX = rand() % GRID_SIZE;
//        redSquareY = rand() % GRID_SIZE;
//        glutPostRedisplay();  // 화면 갱신
//    }
//    glutTimerFunc(1000, updateGame, 0);  // 1초 후 다시 호출
//}
//
//// 게임 시작 함수 (타이머 콜백)
//void startGame(int value) {
//    //gameActive = true;  // 자동 게임 시작 (현재 비활성화)
//    updateGame(0);  // 게임 업데이트 시작
//}
//
//// 메인 메뉴 콜백 함수
//void MyMainMenu(int entryID) {
//    if (entryID == 0)
//        gameActive = true;  // 게임 시작
//    else if (entryID == 1)
//        draw = !draw;  // 점수 표시 토글
//    else if (entryID == 2)
//        exit(0);  // 프로그램 종료
//    glutPostRedisplay();  // 화면 갱신
//}
//
//// 메인 함수
//int main(int argc, char** argv) {
//    srand(time(NULL));  // 난수 생성기 초기화
//
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
//    glutInitWindowSize(WINDOW_SIZE, WINDOW_SIZE);
//    glutInitWindowPosition(100, 100);
//    glutCreateWindow("Reaction Game");
//
//    glClearColor(0.8f, 0.8f, 0.8f, 1.0f);  // 배경색 설정 (밝은 회색)
//
//    glutDisplayFunc(display);  // 디스플레이 콜백 설정
//    glutReshapeFunc(reshape);  // 윈도우 크기 변경 콜백 설정
//    glutMouseFunc(mouseClick);  // 마우스 클릭 콜백 설정
//
//    // 메인 메뉴 생성
//    GLint MyMainMenuID = glutCreateMenu(MyMainMenu);
//    glutAddMenuEntry("start", 0);
//    glutAddMenuEntry("score", 1);
//    glutAddMenuEntry("exit", 2);
//    glutAttachMenu(GLUT_RIGHT_BUTTON);  // 오른쪽 마우스 버튼에 메뉴 연결
//
//    glutTimerFunc(1000, startGame, 0);  // 1초 후 게임 시작
//
//    glutMainLoop();  // 이벤트 루프 시작
//    return 0;
//}