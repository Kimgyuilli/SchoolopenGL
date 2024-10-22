//#include <GL/glut.h>
//#include <GL/GL.h>
//#include <GL/GLU.h>
//#include <stdlib.h> // rand() 함수 사용
//#include <time.h>   // 난수 생성을 위한 시간 초기화
//#include <iostream>
//// 색상 및 회전 각도 설정
//GLfloat red = 0.0f, green = 0.0f, blue = 1.0f;
//GLfloat angle = 0.0f;
//int tick_count = 0;
//int is_running = 0; // 시계 작동 여부를 나타내는 변수 (1: 작동, 0: 정지)
//int numberOfBoxes = 3; // 네모 개수
//int boxSize = 10; // 네모 크기 (10x10 픽셀)
//float boxPositions[6]; // 각 네모의 x 좌표를 저장하는 배열
//int boxFinish[6];
//float Distance = 1.0f; // 네모 이동거리
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
//
//// 화면을 그리는 함수
//void DisplayMultiple() {
//    glClear(GL_COLOR_BUFFER_BIT); // 화면을 지움
//    // 좌측에 6개의 네모를 그리기 (각각 10x10 픽셀)
//    for (int i = 0; i < numberOfBoxes; i++) {
//        float y = 780 + boxPositions[i]; // 각 네모의 y 좌표
//        float x = (i + 1) * (boxSize + 50); // 각 네모 간 50픽셀 간격으로 좌에서 우로 위치 설정
//        glColor3f(red, green, blue); // 네모를 파란색으로 설정
//        if (boxFinish[i]) { // 박스가 한바퀴 돌았으면
//            glColor3f(1, 0, 0); // 네모를 붉은색으로 설정
//        }
//        glPushMatrix(); // 현재 행렬 상태 저장
//        glTranslatef(x, y, 0.0f); // 네모를 x, y 좌표로 이동
//        glBegin(GL_POLYGON); // 다각형(사각형) 그리기 시작
//        glVertex2f(0.0f, 0.0f); // 좌측 하단
//        glVertex2f(0.0f, boxSize); // 좌측 상단
//        glVertex2f(boxSize, boxSize); // 우측 상단
//        glVertex2f(boxSize, 0.0f); // 우측 하단
//        glEnd(); // 다각형 그리기 끝
//        glPopMatrix(); // 이전 행렬 상태 복원
//    }
//
//    glutSwapBuffers(); // 화면을 교체 (더블 버퍼링)
//}
//
//void MyKeyboard(unsigned char KeyPressed, int X, int Y) { //키보드 입력
//    switch (KeyPressed) {
//    case 'i': // i 입력시 속도 증가
//        Distance += 1; break;
//    case 'm': // m 입력시 속도 감소
//        Distance -= 1; break;
//    case 'p':
//        is_running = false; break;
//    case 'g':
//        is_running = true; break;
//    case 's':
//        is_running = true; break;
//    }
//    glutPostRedisplay();
//}
//
//void MyMouseClick(GLint Button, GLint State, GLint X, GLint Y) {
//
//    if (Button == GLUT_LEFT_BUTTON && State == GLUT_DOWN) {
//        std::cout << Y << std::endl;
//        // OpenGL 좌표계에서 Y 좌표 변환 (원점이 왼쪽 하단)
//        float clickY = 800 - Y; // 클릭한 Y 좌표 변환 (OpenGL에서는 왼쪽 하단이 원점)
//
//        // 클릭한 위치의 X 좌표가 어떤 네모의 범위에 있는지 확인
//        for (int i = 0; i < numberOfBoxes; i++) {
//            float boxX = (i + 1) * (boxSize + 50); // 각 네모의 X 좌표 계산
//
//            // 클릭한 X 좌표가 네모의 X 범위에 있는지 확인
//            if (X >= boxX && X <= boxX + boxSize && !boxFinish[i]) {
//                // 클릭한 네모의 Y 좌표를 클릭한 Y 좌표로 변경
//                boxPositions[i] = clickY - 780; // 클릭한 Y 좌표로 업데이트 (boxPositions은 780에서 시작)
//                std::cout << "Box " << i << " moved to Y position: " << boxPositions[i] << std::endl;
//                break; // 첫 번째 해당하는 네모만 이동 후 루프 종료
//            }
//        }
//
//        glutPostRedisplay(); // 화면을 다시 그리도록 요청
//    }
//}
//
//
//// 타이머 함수 (0.01초마다 호출됨)
//void timer(int value) {
//    if (is_running) {
//        // 0.01초마다 임의의 네모 하나를 아래로 이동
//        int randomBox = rand() % numberOfBoxes; // 0부터 numberOfBoxes-1 사이의 임의의 네모 선택
//        if (boxPositions[randomBox] <= -800) { // Y 좌표가 0에 도달하면
//            boxPositions[randomBox] = 0.0f; // 도착 위치를 0으로 설정
//            boxFinish[randomBox] = 1; // 완주 표시
//        }
//        if (!boxFinish[randomBox]) // 완주하지 못한 네모만 이동
//        {
//            boxPositions[randomBox] -= Distance; // 네모를 아래로 Distance만큼 이동
//        }
//        glutPostRedisplay(); // 화면을 다시 그리도록 요청
//    }
//
//    glutTimerFunc(10, timer, 0); // 0.01초(10밀리초)마다 타이머 함수 다시 호출
//}
//
//
//void MyMainMenu(int entryID){				
//    if(entryID == 0) 
//		exit(0);							//프로그램 종료
//    glutPostRedisplay(); 
//}	
//
//void MyColorMenu(int entryID) {
//    if (entryID == 0) {
//        red = 1.0;
//        green = 0.0;
//        blue = 0.0;
//    }
//    else if (entryID == 1) {
//        red = 0.0;
//        green = 1.0;
//        blue = 0.0;
//    }
//    else {
//        red = 0.0;
//        green = 0.0;
//        blue = 1.0;
//    }
//    glutPostRedisplay();
//}
//
//void MySpeedMenu(int entryID) {
//    if (entryID == 0)
//        Distance += 1;
//    else if (entryID == 1)
//        Distance -= 1;
//
//    glutPostRedisplay();
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
//    glutInitWindowSize(400, 800); // 창 크기 설정
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
//
//    GLint MySubSpeedID = glutCreateMenu(MySpeedMenu);
//        glutAddMenuEntry("Up", 0);
//        glutAddMenuEntry("Down", 1);
//
//
//    GLint MySubColorID = glutCreateMenu(MyColorMenu);
//        glutAddMenuEntry("Red", 0);
//        glutAddMenuEntry("Green", 1);
//        glutAddMenuEntry("Blue", 2);
//
//    GLint MyMainMenuID = glutCreateMenu(MyMainMenu);
//        glutAddSubMenu("Change Speed", MySubSpeedID);		
//        glutAddSubMenu("Change Color", MySubColorID);
//        glutAddMenuEntry("exit", 0);
//        glutAttachMenu(GLUT_RIGHT_BUTTON);
//
//    glutMainLoop(); // 이벤트 처리 루프 시작 (프로그램이 종료될 때까지 실행)
//    return 0;
//}
