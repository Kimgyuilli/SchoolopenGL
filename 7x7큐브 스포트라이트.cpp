#include <gl/glut.h>
#include <gl/gl.h>
#include <gl/glu.h>

// 전역 변수로 광원의 위치와 방향을 정의
GLfloat LightPosition0[] = { 0.0, 10.0, 10.0, 1.0 }; // 0번 광원의 위치 (점광원)
GLfloat LightPosition1[] = { 0, 5, 20.0, 1.0 }; // 스포트라이트 위치 (중앙 큐브 위)
GLfloat LightDirection1[] = { 0.0, 0.0, -1.0 };       // 스포트라이트 방향 (아래로)

// 0번 광원 초기화 함수 (점광원)
void InitLight0() {
    // 광원의 각 특성을 설정
    GLfloat light0_ambient[] = { 0.2, 0.2, 0.2, 1.0 }; // 약한 주변광 (전체적인 기본 밝기)
    GLfloat light0_diffuse[] = { 0.8, 0.8, 0.8, 1.0 }; // 강한 확산광 (물체 표면의 밝기)
    GLfloat light0_specular[] = { 1.0, 1.0, 1.0, 1.0 }; // 강한 반사광 (반짝임 효과)

    glEnable(GL_LIGHT0); // 0번 광원 활성화
    glLightfv(GL_LIGHT0, GL_AMBIENT, light0_ambient); // 주변광 설정
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light0_diffuse); // 확산광 설정
    glLightfv(GL_LIGHT0, GL_SPECULAR, light0_specular); // 반사광 설정
    glLightfv(GL_LIGHT0, GL_POSITION, LightPosition0); // 광원의 위치 설정
}

void InitLight1() {
    GLfloat light1_ambient[] = { 0.1, 0.1, 0.1, 1.0 }; // 약한 주변광
    GLfloat light1_diffuse[] = { 1.0, 1.0, 1.0, 1.0 }; // 밝은 확산광
    GLfloat light1_specular[] = { 1.0, 1.0, 1.0, 1.0 }; // 밝은 반사광

    glEnable(GL_LIGHT1); // 1번 광원 활성화
    //glLightfv(GL_LIGHT1, GL_AMBIENT, light1_ambient); // 주변광 설정
    glLightfv(GL_LIGHT1, GL_DIFFUSE, light1_diffuse); // 확산광 설정
    glLightfv(GL_LIGHT1, GL_SPECULAR, light1_specular); // 반사광 설정

    glPushMatrix();
    glLoadIdentity();
    glLightfv(GL_LIGHT1, GL_POSITION, LightPosition1);     // 위치 설정
    glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, LightDirection1); // 방향 설정
    glPopMatrix();

    glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 15.0);  // 스포트라이트 원뿔 각도
    glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 10.0); // 스포트라이트 집중도
}

// 재질(Material) 초기화 함수
void InitMaterial() {
    // 물체 표면의 각 재질 특성을 설정
    GLfloat material_ambient[] = { 0.3, 0.3, 0.3, 1.0 }; // 약한 주변광 반사
    GLfloat material_diffuse[] = { 0.7, 0.7, 0.7, 1.0 }; // 확산광 반사 (밝기)
    GLfloat material_specular[] = { 1.0, 1.0, 1.0, 1.0 }; // 강한 반사광 (반짝임 효과)
    GLfloat material_shininess[] = { 50.0 };              // 반짝임 정도 (값이 클수록 반짝임이 세밀함)

    glMaterialfv(GL_FRONT, GL_AMBIENT, material_ambient);  // 주변광 반사 설정
    glMaterialfv(GL_FRONT, GL_DIFFUSE, material_diffuse);  // 확산광 반사 설정
    glMaterialfv(GL_FRONT, GL_SPECULAR, material_specular);// 반사광 설정
    glMaterialfv(GL_FRONT, GL_SHININESS, material_shininess); // 반짝임 정도 설정
}

// 조명 초기화 함수
void InitLighting() {
    glEnable(GL_LIGHTING);     // 조명 활성화
    glEnable(GL_DEPTH_TEST);   // 깊이 테스트 활성화
    glEnable(GL_COLOR_MATERIAL); // 조명과 색상 조화
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

    //glEnable(GL_LIGHT0);       // 기본 점광원 활성화
    //InitLight0();              // 0번 광원 초기화 (점광원)
    InitLight1();              // 1번 광원 초기화 (스포트라이트)
    InitMaterial();            // 물체 재질 초기화
}


void MyDisplay() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // 카메라 설정
    gluLookAt(30.0, 70.0, 50.0,  // 카메라 위치
        30.0, 30.0, 0.0,   // 카메라가 바라보는 중심점 (중앙 큐브)
        0.0, 1.0, 0.0);    // 카메라의 위쪽 방향

    // 큐브 배열 생성
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            glPushMatrix();
            glTranslated(i * 10, j * 10, 0); // 큐브 위치
            glScalef(1.5, 1.5, 1.5); // 큐브 크기 조정

            glBegin(GL_QUADS);
            // 위쪽 면
            glColor3f(1.0f, 0.0f, 0.0f);
            glVertex3f(1.0f, 1.0f, -1.0f);
            glVertex3f(-1.0f, 1.0f, -1.0f);
            glVertex3f(-1.0f, 1.0f, 1.0f);
            glVertex3f(1.0f, 1.0f, 1.0f);

            // 아래쪽 면
            glColor3f(0.0f, 1.0f, 0.0f);
            glVertex3f(1.0f, -1.0f, 1.0f);
            glVertex3f(-1.0f, -1.0f, 1.0f);
            glVertex3f(-1.0f, -1.0f, -1.0f);
            glVertex3f(1.0f, -1.0f, -1.0f);

            // 앞쪽 면
            glColor3f(0.0f, 0.0f, 1.0f);
            glVertex3f(1.0f, 1.0f, 1.0f);
            glVertex3f(-1.0f, 1.0f, 1.0f);
            glVertex3f(-1.0f, -1.0f, 1.0f);
            glVertex3f(1.0f, -1.0f, 1.0f);

            // 뒤쪽 면
            glColor3f(1.0f, 1.0f, 0.0f);
            glVertex3f(1.0f, -1.0f, -1.0f);
            glVertex3f(-1.0f, -1.0f, -1.0f);
            glVertex3f(-1.0f, 1.0f, -1.0f);
            glVertex3f(1.0f, 1.0f, -1.0f);

            // 왼쪽 면
            glColor3f(0.0f, 1.0f, 1.0f);
            glVertex3f(-1.0f, 1.0f, 1.0f);
            glVertex3f(-1.0f, 1.0f, -1.0f);
            glVertex3f(-1.0f, -1.0f, -1.0f);
            glVertex3f(-1.0f, -1.0f, 1.0f);

            // 오른쪽 면
            glColor3f(1.0f, 0.0f, 1.0f);
            glVertex3f(1.0f, 1.0f, -1.0f);
            glVertex3f(1.0f, 1.0f, 1.0f);
            glVertex3f(1.0f, -1.0f, 1.0f);
            glVertex3f(1.0f, -1.0f, -1.0f);
            glEnd();

            glPopMatrix();
        }
    }
    glFlush();
}

void MyReshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION); // 투상 행렬
    glLoadIdentity();            // 항등 행렬 로드
    glOrtho(-50, 50, -50, 50, -1.0, 100.0); // 평행 투상
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(100, 100);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
    glutCreateWindow("OpenGL Cube with Orthographic Projection");

    InitLighting(); // 조명 초기화
    glutDisplayFunc(MyDisplay);
    glutReshapeFunc(MyReshape);

    glutMainLoop();
    return 0;
}
