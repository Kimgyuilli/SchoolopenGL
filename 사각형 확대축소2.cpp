#include <GL/glut.h>
#include <cstdlib>  // rand() 함수를 위한 헤더
#include <ctime>    // time() 함수를 위한 헤더

int posX1, posY1;       // 첫 번째 사각형의 위치
int posX2, posY2;       // 두 번째 사각형의 위치
int squareSize = 2;     // 사각형의 초기 크기
int sizeIncrement = 1;  // 사각형이 커지는 속도(한번에 증가하는 픽셀 수)
float backgroundColor[3] = { 1.0f, 1.0f, 1.0f };  // 초기 배경색 (흰색)

void initialize() {
    // 프로그램이 시작될 때 랜덤한 위치를 설정합니다.
    posX1 = rand() % 638;  // 640보다 작은 범위로 제한하여 화면을 벗어나지 않게 합니다.
    posY1 = rand() % 478;

    posX2 = rand() % 638;
    posY2 = rand() % 478;

    squareSize = 2;        // 사각형 크기를 초기화
    sizeIncrement = 1;     // 크기 증가 속도를 초기화
    backgroundColor[0] = 1.0f;  // 배경색을 흰색으로 초기화
    backgroundColor[1] = 1.0f;
    backgroundColor[2] = 1.0f;
}

void reshape(int width, int height) {
    glViewport(0, 0, 640, 480);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 640, 0, 480);  // 2D 정사각형 투영 설정
}

bool checkCollision() {
    // 두 사각형의 경계를 비교하여 충돌 여부를 확인
    return !(posX1 + squareSize < posX2 || posX2 + squareSize < posX1 ||
        posY1 + squareSize < posY2 || posY2 + squareSize < posY1);
}

void display() {
    glClearColor(backgroundColor[0], backgroundColor[1], backgroundColor[2], 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // 첫 번째 사각형: 랜덤 위치에서 증가하는 크기
    glBegin(GL_QUADS);
    glColor3f(0.0f, 1.0f, 0.0f);  // 녹색
    glVertex2i(posX1, posY1);                          // 왼쪽 아래
    glVertex2i(posX1 + squareSize, posY1);             // 오른쪽 아래
    glVertex2i(posX1 + squareSize, posY1 + squareSize); // 오른쪽 위
    glVertex2i(posX1, posY1 + squareSize);             // 왼쪽 위
    glEnd();

    // 두 번째 사각형: 다른 랜덤 위치에서 증가하는 크기
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 1.0f);  // 파란색
    glVertex2i(posX2, posY2);                          // 왼쪽 아래
    glVertex2i(posX2 + squareSize, posY2);             // 오른쪽 아래
    glVertex2i(posX2 + squareSize, posY2 + squareSize); // 오른쪽 위
    glVertex2i(posX2, posY2 + squareSize);             // 왼쪽 위
    glEnd();

    glutSwapBuffers();
}

void updateSize(int value) {
    if (sizeIncrement != 0) { // 증가가 멈추지 않았을 때만 실행
        squareSize += sizeIncrement;

        if (checkCollision()) {
            // 충돌 시 배경색을 빨간색으로 설정하고 크기 증가 멈춤
            backgroundColor[0] = 1.0f;
            backgroundColor[1] = 0.0f;
            backgroundColor[2] = 0.0f;
            sizeIncrement = 0;
        }
        else {
            // 충돌하지 않으면 배경색을 흰색으로 유지
            backgroundColor[0] = 1.0f;
            backgroundColor[1] = 1.0f;
            backgroundColor[2] = 1.0f;
        }
    }

    glutPostRedisplay();          // 화면을 다시 그리도록 요청
    glutTimerFunc(10, updateSize, 0);  // 0.01초 후에 updateSize 호출
}

void handleKeyPress(unsigned char key, int x, int y) {
    if (key == 'i') {
        sizeIncrement += 1;  // 'i'가 눌리면 증가 속도를 1씩 증가
    }
    else if (key == 'm') {
        if (sizeIncrement >= 0) {
            sizeIncrement -= 1;  // 'm'이 눌리면 증가 속도를 1씩 감소, 최소값 1
        }
    }
}

void handleMouseClick(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        initialize(); // 좌클릭 시 초기 상태로 재설정
        glutPostRedisplay(); // 화면을 다시 그리도록 요청
    }
}

int main(int argc, char** argv) {
    srand(static_cast<unsigned>(time(0)));  // 실행할 때마다 다른 시드로 랜덤 초기화

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(640, 480);
    glutCreateWindow("OpenGL Expanding Random Positioned Squares");

    initialize();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(handleKeyPress);      // 키보드 입력 처리 함수 등록
    glutMouseFunc(handleMouseClick);       // 마우스 클릭 처리 함수 등록
    glutTimerFunc(10, updateSize, 0);      // 0.01초 후에 updateSize 처음 호출
    glutMainLoop();
    return 0;
}
