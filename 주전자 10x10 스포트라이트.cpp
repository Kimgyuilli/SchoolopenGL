#define _USE_MATH_DEFINES
#include <gl/glut.h>
#include <gl/gl.h>
#include <gl/glu.h>
#include <math.h>

float wide = 300.0;
float tiles = 100.0;

// 전역 변수로 광원의 위치와 방향을 정의
GLfloat LightPosition0[] = { 0.0, 20.0, -50.0, 1.0 }; // 0번 광원의 위치 (점광원)
GLfloat LightPosition1[] = { -100.0, 50.0, -50.0, 1.0 }; // 바닥 중심 위에 스포트라이트 위치
GLfloat LightDirection1[] = { 50.0, -30.0, -10.0 };    // 아래 방향
GLfloat LightPosition2[] = { 100.0, 50.0, -50.0, 1.0 }; // 바닥 중심 위에 스포트라이트 위치
GLfloat LightDirection2[] = { -50.0, -30.0, -10.0 };    // 아래 방향

// 0번 광원 초기화 함수 (점광원)
void InitLight0() {
    // 광원의 각 특성을 설정
    GLfloat light0_ambient[] = { 0.2, 0.2, 0.2, 1.0 }; // 약한 주변광 (전체적인 기본 밝기)
    GLfloat light0_diffuse[] = { 0.8, 0.8, 0.8, 1.0 }; // 강한 확산광 (물체 표면의 밝기)
    GLfloat light0_specular[] = { 0.3, 0.3, 0.3, 1.0 }; // 강한 반사광 (반짝임 효과)

    glEnable(GL_LIGHT0); // 0번 광원 활성화
    //glLightfv(GL_LIGHT0, GL_AMBIENT, light0_ambient); // 주변광 설정
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light0_diffuse); // 확산광 설정
    glLightfv(GL_LIGHT0, GL_SPECULAR, light0_specular); // 반사광 설정
    glLightfv(GL_LIGHT0, GL_POSITION, LightPosition0); // 광원의 위치 설정
}

void InitLight1() {
    GLfloat light1_ambient[] = { 0.0, 0.0, 0.0, 1.0 }; // 주변광 제거
    GLfloat light1_diffuse[] = { 10.0, 10.0, 10.0, 1.0 }; // 강한 확산광
    GLfloat light1_specular[] = { 10.0, 10.0, 10.0, 1.0 }; // 강한 반사광

    glEnable(GL_LIGHT1);
    glLightfv(GL_LIGHT1, GL_AMBIENT, light1_ambient);  // 주변광 제거
    glLightfv(GL_LIGHT1, GL_DIFFUSE, light1_diffuse);  // 확산광 설정
    glLightfv(GL_LIGHT1, GL_SPECULAR, light1_specular); // 반사광 설정
    glLightfv(GL_LIGHT1, GL_POSITION, LightPosition1); // 위치 설정
    glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, LightDirection1); // 방향 설정

    glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 45.0);   // 좁은 확산 각도
    glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 50.0); // 집중도 증가
}
void InitLight2() {
    GLfloat light2_ambient[] = { 0.0, 0.0, 0.0, 1.0 }; // 주변광 제거
    GLfloat light2_diffuse[] = { 10.0, 10.0, 10.0, 1.0 }; // 강한 확산광
    GLfloat light2_specular[] = { 10.0, 10.0, 10.0, 1.0 }; // 강한 반사광

    glEnable(GL_LIGHT2);
    glLightfv(GL_LIGHT2, GL_AMBIENT, light2_ambient);  // 주변광 제거
    glLightfv(GL_LIGHT2, GL_DIFFUSE, light2_diffuse);  // 확산광 설정
    glLightfv(GL_LIGHT2, GL_SPECULAR, light2_specular); // 반사광 설정
    glLightfv(GL_LIGHT2, GL_POSITION, LightPosition2); // 위치 설정
    glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, LightDirection2); // 방향 설정

    glLightf(GL_LIGHT2, GL_SPOT_CUTOFF, 30.0);   // 좁은 확산 각도
    glLightf(GL_LIGHT2, GL_SPOT_EXPONENT, 50.0); // 집중도 증가
}

// 재질(Material) 초기화 함수
void InitMaterial() {
    GLfloat material_ambient[] = { 0.0, 0.0, 0.0, 1.0 }; // 주변광 제거
    GLfloat material_diffuse[] = { 0.7, 0.7, 0.7, 1.0 }; // 확산광 반사
    GLfloat material_specular[] = { 1.0, 1.0, 1.0, 1.0 }; // 강한 반사광
    GLfloat material_shininess[] = { 50.0 };              // 반짝임 정도

    glMaterialfv(GL_FRONT, GL_AMBIENT, material_ambient);  // 주변광 제거
    glMaterialfv(GL_FRONT, GL_DIFFUSE, material_diffuse);  // 확산광 반사 설정
    glMaterialfv(GL_FRONT, GL_SPECULAR, material_specular);// 반사광 설정
    glMaterialfv(GL_FRONT, GL_SHININESS, material_shininess); // 반짝임 설정
}

// 조명 초기화 함수
void InitLighting() {
    glEnable(GL_LIGHTING);      // 조명 활성화
    glEnable(GL_DEPTH_TEST);    // 깊이 테스트 활성화
    glEnable(GL_COLOR_MATERIAL); // 색상과 조명 연동
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
    GLfloat global_ambient[] = { 0.0, 0.0, 0.0, 1.0 };
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient); //전역 주변광 제거

    InitLight0();               // 0번 광원 활성화 제거
    InitLight1();               // 1번 광원 (스포트라이트) 활성화 좌에서 우
    InitLight2();               // 2번 광원 (스포트라이트) 활성화 우에서 좌
    InitMaterial();             // 재질 초기화
}

void DrawDividedFloor(float width, float depth, int rows, int cols) {
    float cellWidth = width / cols; // 각 셀의 너비
    float cellDepth = depth / rows; // 각 셀의 깊이

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // 각 셀의 시작 좌표 계산
            float x_start = -width / 2 + j * cellWidth;
            float z_start = -depth / 2 + i * cellDepth;

            // 셀 그리기
            glBegin(GL_QUADS);
            glNormal3f(0.0f, 1.0f, 0.0f); // 법선 벡터 (위쪽 방향)
            glColor3f(1.0f, 1.0f, 0.5f); // 셀 색상 (밝은 회색)

            glVertex3f(x_start, -0.1f, z_start);                   // 왼쪽 아래
            glVertex3f(x_start + cellWidth, -0.1f, z_start);       // 오른쪽 아래
            glVertex3f(x_start + cellWidth, -0.1f, z_start + cellDepth); // 오른쪽 위
            glVertex3f(x_start, -0.1f, z_start + cellDepth);       // 왼쪽 위

            glEnd();
        }
    }
}


void MyDisplay() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // 카메라 설정
    gluLookAt(0.0, 20.0, 50.0,  // 카메라 위치
        0.0, 0.0, 0.0,     // 카메라가 바라보는 중심점
        0.0, 1.0, 0.0);    // 위쪽 방향

    // 바닥 그리기
    glPushMatrix();
    DrawDividedFloor(wide, wide, tiles, tiles); // 너비 180, 깊이 180, 10x10 그리드
    glPopMatrix();

    GLfloat radius = 65.0; // 단지 중심이 위치할 원형 반지름

            // 주전자 배열 생성
    for (int i = -4; i < 6; i++) {
        for (int j = -4; j < 6; j++) {
            glPushMatrix();
            glTranslated(i * 30 - 11, 5, j * 30); // 큐브 위치
            glScalef(1.5, 1.5, 1.5); // 큐브 크기 조정
            glColor3f(1.0f, 0.0f, 0.0f); // 셀 색상 (밝은 회색)
            glutSolidTeapot(5.0); // 크기 10의 Teapot 생성

            glPopMatrix();
        }
    }
    glFlush();
}


void MyReshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION); // 투상 행렬
    glLoadIdentity();            // 항등 행렬 로드
    glOrtho(-200, 200, -200, 200, -50, 1000.0); // 평행 투상
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(100, 100);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
    glutCreateWindow("OpenGL Cube with Orthographic Projection");

    InitLighting(); // 조명 초기화
    glutDisplayFunc(MyDisplay);
    glutReshapeFunc(MyReshape);

    glutMainLoop();
    return 0;
}
   