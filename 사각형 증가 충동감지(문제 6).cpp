//#include <GL/glut.h>
//#include <GL/GL.h>
//#include <GL/GLU.h>
//#include <stdlib.h>
//#include <time.h>
//#include <corecrt_math.h>
//
//// 색상 및 회전 각도 설정
//GLfloat red = 1.0f, green = 0.0f, blue = 0.0f;
//GLfloat angle = 0.0f;
//int tick_count = 0;
//int is_running = 1;
//int numberOfBoxes = 2; // 화면에 표시할 사각형의 개수
//float boxSize[2] = { 10.0f, 10.0f }; // 각 사각형의 크기
//float boxPositions[2][2]; // 각 사각형의 x, y 좌표를 저장하는 2D 배열
//float boxSpeeds[2][2]; // 각 사각형의 x, y 방향 속도를 저장하는 2D 배열
//float Distance = 1.0f;
//float speed = 0.1f; // 사각형 크기 증가 속도
//float margin = 5.0f; // 충돌 판정 여유값
//
//// 창의 크기가 바뀔 때 호출되는 함수
//void reshape(int width, int height) {
//    glViewport(0, 0, width, height); // 뷰포트 설정
//    glMatrixMode(GL_PROJECTION); // 투영 행렬 모드로 변경
//    glLoadIdentity(); // 투영 행렬 초기화
//    gluOrtho2D(-100.0, width, -100.0, height); // 2D 직교 투영 설정
//    glMatrixMode(GL_MODELVIEW); // 다시 모델뷰 행렬 모드로 변경
//}
//
//// 화면을 그리는 함수
//void DisplayMultiple() {
//    glClear(GL_COLOR_BUFFER_BIT); // 화면을 지움
//
//    for (int i = 0; i < numberOfBoxes; i++) {
//        if (is_running) {
//            boxSize[i] += speed; // 사각형 크기 증가
//            // 두 사각형이 겹치는지 확인
//            for (int j = i + 1; j < numberOfBoxes; j++) {
//                float dx = boxPositions[i][0] - boxPositions[j][0];
//                float dy = boxPositions[i][1] - boxPositions[j][1];
//                float distance = sqrt(dx * dx + dy * dy); // 두 사각형 간 거리 계산
//                if (distance < boxSize[i] + boxSize[j] - margin) { // 겹치면
//                    red = 1.0f; // 빨간색으로 변경
//                    green = 0.0f;
//                    blue = 0.0f;
//                    is_running = false;
//                    break;
//                }
//                else { // 겹치지 않으면
//                    red = 0.0f; // 파란색으로 변경
//                    green = 0.0f;
//                    blue = 1.0f;
//                }
//            }
//        }
//        // 사각형 그리기
//        glColor3f(red, green, blue);
//        glPushMatrix();
//        glTranslatef(boxPositions[i][0], boxPositions[i][1], 0.0f); // 사각형 위치로 이동
//        glRotatef(0.3f, 1.0f, 1.0f, 0.0f); // 사각형 회전
//        glBegin(GL_POLYGON);
//        glVertex2f(-boxSize[i], -boxSize[i]); // 좌측 하단
//        glVertex2f(-boxSize[i], boxSize[i]); // 좌측 상단
//        glVertex2f(boxSize[i], boxSize[i]); // 우측 상단
//        glVertex2f(boxSize[i], -boxSize[i]); // 우측 하단
//        glEnd();
//        glPopMatrix();
//    }
//    glutSwapBuffers(); // 화면 교체
//}
//
//void MyKeyboard(unsigned char KeyPressed, int X, int Y) { //키보드 입력
//    switch (KeyPressed) {
//    case 'i': // i 입력시 속도 증가
//        speed += 0.01; break;
//    case 'm': // m 입력시 속도 감소
//        speed = (speed > 0.01) ? speed - 0.01 : 0.01; // 최소 속도 제한
//        break;
//    }
//    glutPostRedisplay();
//}
//
//// 마우스 클릭 이벤트 처리 함수
//void MyMouseClick(GLint Button, GLint State, GLint X, GLint Y) {
//    if (Button == GLUT_LEFT_BUTTON && State == GLUT_DOWN) { // 마우스 왼쪽 버튼을 누르면
//        // 사각형의 위치를 랜덤으로 변경
//        for (int i = 0; i < numberOfBoxes; i++) {
//            boxPositions[i][0] = rand() % 630;
//            boxPositions[i][1] = rand() % 470;
//            boxSize[i] = 10.0f;
//        }
//        is_running = true;
//        glutPostRedisplay(); // 화면을 다시 그리도록 요청
//    }
//}
//
//// 타이머 함수 (0.01초마다 호출됨)
//void timer(int value) {
//    DisplayMultiple(); // 화면 그리기 함수 호출
//    glutTimerFunc(1, timer, 0); // 0.01초(10밀리초)마다 타이머 함수 다시 호출
//}
//
//// 메인 함수
//int main(int argc, char** argv) {
//    srand(time(0)); // 난수 생성을 위한 시드 초기화
//
//    // 사각형의 초기 위치와 속도를 랜덤으로 설정
//    for (int i = 0; i < numberOfBoxes; i++) {
//        boxPositions[i][0] = rand() % 630;
//        boxPositions[i][1] = rand() % 470;
//        boxSpeeds[i][0] = rand() % 4 - 2;
//        boxSpeeds[i][1] = rand() % 4 - 2;
//    }
//
//    glutInit(&argc, argv); // GLUT 초기화
//    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // 더블 버퍼링과 RGB 모드 설정
//    glutInitWindowSize(640, 480); // 창 크기 설정
//    glutInitWindowPosition(0, 0); // 창의 초기 위치 설정
//    glutCreateWindow("2020E7008 with Viewport"); // 창 생성 및 제목 설정
//    glClearColor(1.0, 1.0, 1.0, 1.0); // 배경 색상 설정 (흰색)
//    glutDisplayFunc(DisplayMultiple); // 디스플레이 함수 등록
//    glutReshapeFunc(reshape); // 창 크기 변경 시 호출될 함수 등록
//    glutMouseFunc(MyMouseClick); // 마우스 클릭 이벤트 처리 함수 등록
//    glutKeyboardFunc(MyKeyboard); // 키보드 함수 등록
//    glutTimerFunc(10, timer, 0); // 0.01초마다 타이머 함수 호출 시작
//    glutMainLoop(); // 이벤트 처리 루프 시작
//    return 0;
//}
