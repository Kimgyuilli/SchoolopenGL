#include <GL/glut.h>
#include <GL/GL.h>
#include <GL/GLU.h>
#include <iostream>

GLfloat posX = 320.0f; // 사각형 초기 X 위치
GLfloat posY = 240.0f; // 사각형 초기 Y 위치
GLfloat speedX = 0.1f; // X 방향 속도
GLfloat speedY = 0.1f; // Y 방향 속도
GLfloat rectSize = 20.0f; // 사각형 초기 크기

// 윈도우 크기 변경 시 호출되는 함수 (뷰포트 크기 설정)
void ResizeViewport(int w, int h) {
    if (h == 0) h = 1;

    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, w, 0.0, h);
    glMatrixMode(GL_MODELVIEW);
}

// 사각형의 위치와 크기를 업데이트하고 벽 충돌 처리
void UpdatePosition() {
    // 위치 업데이트
    posX += speedX;
    posY += speedY;

    // 벽에 부딪히면 반대 방향으로 이동
    if (posX < 0) {
        posX = 0; // 왼쪽 벽에 맞았을 때 위치 조정
        speedX = -speedX; // X 방향 반전
    }
    if (posX > 640 - rectSize) {
        posX = 640 - rectSize; // 오른쪽 벽에 맞았을 때 위치 조정
        speedX = -speedX; // X 방향 반전
    }
    if (posY < 0) {
        posY = 0; // 아래 벽에 맞았을 때 위치 조정
        speedY = -speedY; // Y 방향 반전
    }
    if (posY > 480 - rectSize) {
        posY = 480 - rectSize; // 위쪽 벽에 맞았을 때 위치 조정
        speedY = -speedY; // Y 방향 반전
    }

    // 사각형 크기 증가
    rectSize += 0.03f; // 매 업데이트마다 1픽셀씩 증가
}

// 화면을 그리는 함수
void Display() {
    // 화면을 흰색으로 클리어
    glClear(GL_COLOR_BUFFER_BIT);

    // 파란색 사각형 그리기
    glColor3f(0.0f, 0.0f, 1.0f); // 파란색
    glBegin(GL_QUADS);
    glVertex2f(posX, posY);                     // 좌하단
    glVertex2f(posX + rectSize, posY);         // 우하단
    glVertex2f(posX + rectSize, posY + rectSize); // 우상단
    glVertex2f(posX, posY + rectSize);         // 좌상단
    glEnd();

    // 버퍼를 교체하여 그린 내용을 화면에 표시
    glutSwapBuffers();
}

// 타이머 함수로 애니메이션을 업데이트
void Timer(int value) {
    UpdatePosition(); // 위치 및 크기 업데이트
    glutPostRedisplay(); // 화면 갱신 요청
    glutTimerFunc(1, Timer, 0); // 10밀리초 간격으로 타이머 설정
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(640, 480); // 윈도우 크기
    glutInitWindowPosition(100, 100); // 윈도우 시작 위치
    glutCreateWindow("OpenGL Rectangle Growth");

    // 배경색을 흰색으로 설정
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    // 디스플레이 콜백 함수 등록
    glutDisplayFunc(Display);

    // 윈도우 크기 변경 시 호출될 콜백 함수 등록
    glutReshapeFunc(ResizeViewport);

    // 타이머 함수 등록
    glutTimerFunc(0, Timer, 0);

    // 메인 루프 실행
    glutMainLoop();
    return 0;
}
