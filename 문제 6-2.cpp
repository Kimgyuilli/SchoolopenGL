//#include <GL/glut.h>
//#include <GL/GL.h>
//#include <GL/GLU.h>
//#include <stdlib.h> // rand() 함수 사용
//#include <time.h>   // 난수 생성을 위한 시간 초기화
//
//// 색상 및 회전 각도 설정
//GLfloat red = 1.0f, green = 0.0f, blue = 0.0f;
//GLfloat angle = 0.0f;
//int tick_count = 0;
//int is_running = 1; // 시계 작동 여부를 나타내는 변수 (1: 작동, 0: 정지)
//int numberOfBoxes = 2; // 네모 개수
//float boxSize = 10; // 네모 크기 (10x10 픽셀)
//float boxPositions[6]; // 각 네모의 x 좌표를 저장하는 배열
//int boxFinish[6];
//float Distance = 1.0f; // 네모 이동거리
//float speed = 0.1f;
//float x1, y1, x2, y2;
//
//
//// 창 크기가 변경될 때 호출되는 함수
//void reshape(int width, int height) {
//    glViewport(0, 0, width, height); // 새로운 창 크기에 맞춰 뷰포트 설정
//    glMatrixMode(GL_PROJECTION); // 투영 행렬 모드로 변경
//    glLoadIdentity(); // 투영 행렬 초기화
//    gluOrtho2D(0.0, width, 0.0, height); // 2D 직교 투영 설정 (좌표계를 창 크기에 맞춤)
//    glMatrixMode(GL_MODELVIEW); // 다시 모델뷰 행렬 모드로 변경
//}
//// 화면을 그리는 함수
//void DisplayMultiple() {
//    glClear(GL_COLOR_BUFFER_BIT); // 화면을 지움
//
//    // 좌측에 6개의 네모를 그리기 (각각 10x10 픽셀)
//        //float x = 100 + i*200;
//        //float y = 100 + i*200;
//        glColor3f(0, 0, 1); // 네모를 파란색으로 설정
//
//    glPushMatrix(); // 현재 행렬 상태 저장
//    glTranslatef(x1, y1, 0.0f); // 네모를 x, y 좌표로 이동
//    glRotatef(0.3f, 1.0f, 1.0f, 0.0f);
//    glBegin(GL_POLYGON); // 다각형(사각형) 그리기 시작
//    glVertex2f(-boxSize, -boxSize); // 좌측 하단
//    glVertex2f(-boxSize, boxSize); // 좌측 상단
//    glVertex2f(boxSize, boxSize); // 우측 상단
//    glVertex2f(boxSize, -boxSize); // 우측 하단
//    glEnd(); // 다각형 그리기 끝
//    glPopMatrix(); // 이전 행렬 상태 복원
//
//    glutSwapBuffers(); // 화면을 교체 (더블 버퍼링)
//}
//
//void MyKeyboard(unsigned char KeyPressed, int X, int Y) { //키보드 입력
//    switch (KeyPressed) {
//    case 'i': // i 입력시 속도 증가
//        speed += 0.1; break;
//    case 'm': // m 입력시 속도 감소
//        speed -= 0.1; break;
//    }
//    glutPostRedisplay();
//}
//
//void MyMouseClick(GLint Button, GLint State, GLint X, GLint Y) {
//    if (Button == GLUT_LEFT_BUTTON && State == GLUT_DOWN) {
//        x1 = rand() % 640;
//        x2 = rand() % 640;
//        y1 = rand() % 480;
//        y2 = rand() % 480;
//        boxSize = 10;
//        glutPostRedisplay(); // 화면을 다시 그리도록 요청
//    }
//}
//
//// 타이머 함수 (0.01초마다 호출됨)
//void timer(int value) {
//     boxSize += speed;
//    glutPostRedisplay(); // 화면을 다시 그리도록 요청 (디스플레이 함수 호출)
//    glutTimerFunc(10, timer, 0); // 0.01초(10밀리초)마다 타이머 함수 다시 호출
//}
//
//// 메인 함수
//int main(int argc, char** argv) {
//    srand(time(0)); // 난수 생성을 위한 시드 초기화 (현재 시간 사용)
//
//    // 네모들의 초기 x 좌표를 10픽셀로 설정 (좌측 벽에서 10픽셀 떨어진 위치)
//    for (int i = 0; i < numberOfBoxes; i++) {
//        boxPositions[i] = 10.0f;
//        boxFinish[i] = 0; //박스 초기값
//    }
//
//    glutInit(&argc, argv); // GLUT 초기화
//    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // 더블 버퍼링과 RGB 모드 설정
//    glutInitWindowSize(640, 480); // 창 크기 설정
//    glutInitWindowPosition(0, 0); // 창의 초기 위치 설정
//    glutCreateWindow("2020E7008 with Viewport"); // 창 생성 및 제목 설정
//
//    glClearColor(1.0, 1.0, 1.0, 1.0); // 배경 색상 설정 (흰색)
//
//    glutDisplayFunc(DisplayMultiple); // 디스플레이 함수 등록
//    glutReshapeFunc(reshape); // 창 크기 변경 시 호출될 함수 등록
//    glutTimerFunc(10, timer, 0); // 0.01초마다 타이머 함수 호출 시작
//    glutKeyboardFunc(MyKeyboard);
//    glutMouseFunc(MyMouseClick);
//    glutTimerFunc(10, timer, 0); // 0.01초마다 타이머 함수 호출 시작
//    glutMainLoop(); // 이벤트 처리 루프 시작 (프로그램이 종료될 때까지 실행)
//    return 0;
//}
