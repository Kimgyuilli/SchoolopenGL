//#include <GL/glut.h>
//#include <GL/GL.h>
//#include <GL/GLU.h>
//#include <iostream>
//GLfloat angle1 =30.0f;
//GLfloat angle2 = 30.0f;
//GLfloat posX1 = 320.0f; // 사각형1 초기 X 위치
//GLfloat posY1 = 240.0f; // 사각형1 초기 Y 위치
//GLfloat speedX1 = 0.1f; // X 방향 속도
//GLfloat speedY1 = 0.1f; // Y 방향 속도
//GLfloat posX2 = 370.0f; // 사각형2 초기 X 위치
//GLfloat posY2 = 250.0f; // 사각형2 초기 Y 위치
//GLfloat speedX2 = -0.1f; // X 방향 속도
//GLfloat speedY2 = -0.1f; // Y 방향 속도
//GLfloat rectSize = 20.0f; // 사각형 초기 크기
//GLfloat rotspeed1 = 0.1; //회전 방향, 속도
//GLfloat rotspeed2 = -0.1;
//GLfloat speed = 0.03f; //크기 변화 속도
//
//// 윈도우 크기 변경 시 호출되는 함수 (뷰포트 크기 설정)
//void ResizeViewport(int w, int h) {
//    if (h == 0) h = 1;
//    glViewport(0, 0, w, h);
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluOrtho2D(0.0, w, 0.0, h);
//    glMatrixMode(GL_MODELVIEW);
//}
//
//// 사각형의 위치와 크기를 업데이트하고 벽 충돌 처리
//void UpdatePosition() {
//    // 위치 업데이트
//    posX1 += speedX1;
//    posY1 += speedY1;
//    posX2 += speedX2;
//    posY2 += speedY2;
//
//    // 벽에 부딪히면 반대 방향으로 이동
//    if (posX1 < 0) {
//        posX1 = 0; // 왼쪽 벽에 맞았을 때 위치 조정
//        speedX1 = -speedX1; // X 방향 반전
//        rotspeed1 = -rotspeed1;
//    }
//    if (posX1 > 640 - rectSize) {
//        posX1 = 640 - rectSize; // 오른쪽 벽에 맞았을 때 위치 조정
//        speedX1 = -speedX1; // X 방향 반전
//        rotspeed1 = -rotspeed1;
//    }
//    if (posY1 < 0) {
//        posY1 = 0; // 아래 벽에 맞았을 때 위치 조정
//        speedY1 = -speedY1; // Y 방향 반전
//        rotspeed1 = -rotspeed1;
//    }
//    if (posY1 > 480 - rectSize) {
//        posY1 = 480 - rectSize; // 위쪽 벽에 맞았을 때 위치 조정
//        speedY1 = -speedY1; // Y 방향 반전
//        rotspeed1 = -rotspeed1;
//    }
//
//    // 벽에 부딪히면 반대 방향으로 이동
//    if (posX2 < 0) {
//        posX2 = 0; // 왼쪽 벽에 맞았을 때 위치 조정
//        speedX2 = -speedX2; // X 방향 반전
//        rotspeed2 = -rotspeed2;
//    }
//    if (posX2 > 640 - rectSize) {
//        posX2 = 640 - rectSize; // 오른쪽 벽에 맞았을 때 위치 조정
//        speedX2 = -speedX2; // X 방향 반전
//        rotspeed2 = -rotspeed2;
//    }
//    if (posY2 < 0) {
//        posY2 = 0; // 아래 벽에 맞았을 때 위치 조정
//        speedY2 = -speedY2; // Y 방향 반전
//        rotspeed2 = -rotspeed2;
//    }
//    if (posY2 > 480 - rectSize) {
//        posY2 = 480 - rectSize; // 위쪽 벽에 맞았을 때 위치 조정
//        speedY2 = -speedY2; // Y 방향 반전
//        rotspeed2 = -rotspeed2;
//    }
//
//    // 사각형 크기 증가
//    rectSize += speed; // 매 업데이트마다 1픽셀씩 증가
//    angle1 += rotspeed1;
//    angle2 -= rotspeed2;
//    if (angle1 == 360) {
//        angle1 = 0.0;
//    }
//    if (angle2 == 360) {
//        angle2 = 0.0;
//    }
//}
//
//// 화면을 그리는 함수
//void Display() {
//    // 화면을 흰색으로 클리어
//    glClear(GL_COLOR_BUFFER_BIT);
//    for (int i = 0; i < 2; i++) {
//
//        // 변환 초기화 및 행렬 저장
//        glLoadIdentity();
//        glPushMatrix();
//
//        // 사각형의 중심을 기준으로 회전시키기 위해 사각형 위치 이동 후 회전 적용
//        if (i == 0) {
//            glTranslatef(posX1 + rectSize / 2, posY1 + rectSize / 2, 0.0f);  // 사각형 중심으로 이동
//            glRotatef(angle1, 0.0, 0.0, 1.0);  // Z축을 기준으로 회전
//        }
//        else {
//            glTranslatef(posX2 + rectSize / 2, posY2 + rectSize / 2, 0.0f);  // 사각형 중심으로 이동
//            glRotatef(angle2, 0.0, 0.0, 1.0);  // Z축을 기준으로 회전
//        }
//        glTranslatef(-rectSize / 2, -rectSize / 2, 0.0f);  // 회전 후 사각형을 원래 위치로 되돌리기
//        // 파란색 사각형 그리기
//        glColor3f(0.0f, 0.0f, 1.0f); // 파란색
//        glBegin(GL_QUADS);
//        glVertex2f(0.0f, 0.0f);                   // 좌하단
//        glVertex2f(rectSize, 0.0f);               // 우하단
//        glVertex2f(rectSize, rectSize);           // 우상단
//        glVertex2f(0.0f, rectSize);               // 좌상단
//        glEnd();
//
//        glPopMatrix();  // 행렬 복원
//
//    }
//    // 버퍼를 교체하여 그린 내용을 화면에 표시
//    glutSwapBuffers();
//}
//
//
//// 타이머 함수로 애니메이션을 업데이트
//void Timer(int value) {
//    UpdatePosition(); // 위치 및 크기 업데이트
//    glutPostRedisplay(); // 화면 갱신 요청
//    glutTimerFunc(1, Timer, 0); // 10밀리초 간격으로 타이머 설정
//}
//
//void MyKeyboard(unsigned char KeyPressed, int X, int Y) { //키보드 입력
//    switch (KeyPressed) {
//    case 'i': // i 입력시 속도 증가
//        speed += 0.01; break;
//    case 'm': // m 입력시 속도 감소
//        speed -= 0.01;
//        break;
//    }
//    glutPostRedisplay();
//}
//
//int main(int argc, char** argv) {
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
//    glutInitWindowSize(640, 480); // 윈도우 크기
//    glutInitWindowPosition(100, 100); // 윈도우 시작 위치
//    glutCreateWindow("OpenGL Rectangle Growth");
//
//    // 배경색을 흰색으로 설정
//    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
//
//    // 디스플레이 콜백 함수 등록
//    glutDisplayFunc(Display);
//
//    // 윈도우 크기 변경 시 호출될 콜백 함수 등록
//    glutReshapeFunc(ResizeViewport);
//    glutKeyboardFunc(MyKeyboard); // 키보드 함수 등록
//
//    // 타이머 함수 등록
//    glutTimerFunc(0, Timer, 0);
//
//    // 메인 루프 실행
//    glutMainLoop();
//    return 0;
//}
