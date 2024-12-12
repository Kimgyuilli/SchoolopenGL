//#define _USE_MATH_DEFINES
//#include <gl/glut.h>
//#include <gl/gl.h>
//#include <gl/glu.h>
//#include <math.h>
//
//
//// 전역 변수로 광원의 위치와 방향을 정의
//GLfloat LightPosition0[] = { 0.0, 10.0, 10.0, 1.0 }; // 0번 광원의 위치 (점광원)
//
//bool is_running = true;
//float wide = 100.0, tiles = 10.0;
//float move = 0;
//// 카메라 방향 변수 (초기값: z축 -방향)
//float cameraDirectionX = 0.0f;
//float cameraDirectionZ = -1.0f;
//
//// 카메라 위치 변수
//float cameraPosX = -90.0f + 9.0f;
//float cameraPosZ = 90.0f - 9.0f;
//
//// 0번 광원 초기화 함수 (점광원)
//void InitLight0() {
//    // 광원의 각 특성을 설정
//    GLfloat light0_ambient[] = { 0.2, 0.2, 0.2, 1.0 }; // 약한 주변광 (전체적인 기본 밝기)
//    GLfloat light0_diffuse[] = { 0.8, 0.8, 0.8, 1.0 }; // 강한 확산광 (물체 표면의 밝기)
//    GLfloat light0_specular[] = { 1.0, 1.0, 1.0, 1.0 }; // 강한 반사광 (반짝임 효과)
//
//    glEnable(GL_LIGHT0); // 0번 광원 활성화
//    glLightfv(GL_LIGHT0, GL_AMBIENT, light0_ambient); // 주변광 설정
//    glLightfv(GL_LIGHT0, GL_DIFFUSE, light0_diffuse); // 확산광 설정
//    glLightfv(GL_LIGHT0, GL_SPECULAR, light0_specular); // 반사광 설정
//    glLightfv(GL_LIGHT0, GL_POSITION, LightPosition0); // 광원의 위치 설정
//}
//
//
//// 재질(Material) 초기화 함수
//void InitMaterial() {
//    // 물체 표면의 각 재질 특성을 설정
//    GLfloat material_ambient[] = { 0.3, 0.3, 0.3, 1.0 }; // 약한 주변광 반사
//    GLfloat material_diffuse[] = { 0.7, 0.7, 0.7, 1.0 }; // 확산광 반사 (밝기)
//    GLfloat material_specular[] = { 1.0, 1.0, 1.0, 1.0 }; // 강한 반사광 (반짝임 효과)
//    GLfloat material_shininess[] = { 50.0 };              // 반짝임 정도 (값이 클수록 반짝임이 세밀함)
//
//    glMaterialfv(GL_FRONT, GL_AMBIENT, material_ambient);  // 주변광 반사 설정
//    glMaterialfv(GL_FRONT, GL_DIFFUSE, material_diffuse);  // 확산광 반사 설정
//    glMaterialfv(GL_FRONT, GL_SPECULAR, material_specular);// 반사광 설정
//    glMaterialfv(GL_FRONT, GL_SHININESS, material_shininess); // 반짝임 정도 설정
//}
//
//// 조명 초기화 함수
//void InitLighting() {
//    glEnable(GL_LIGHTING);     // 조명 활성화
//    glEnable(GL_DEPTH_TEST);   // 깊이 테스트 활성화
//    glEnable(GL_COLOR_MATERIAL); // 조명과 색상 조화
//    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
//
//    InitLight0();              // 0번 광원 초기화 (점광원)
//    InitMaterial();            // 물체 재질 초기화
//}
//
//void DrawDividedFloor(float width, float depth, int rows, int cols) {
//    float cellWidth = width / cols; // 각 셀의 너비
//    float cellDepth = depth / rows; // 각 셀의 깊이
//    float c = 0.0;
//    for (int i = 0; i < rows; i++) {
//        for (int j = 0; j < cols; j++) {
//            // 각 셀의 시작 좌표 계산
//            float x_start = -width / 2 + j * cellWidth;
//            float z_start = -depth / 2 + i * cellDepth;
//
//            // 셀 그리기
//            glBegin(GL_QUADS);
//            glNormal3f(0.0f, 1.0f, 0.0f); // 법선 벡터 (위쪽 방향)
//            glColor3f(c, c, c); // 셀 색상 (밝은 회색)
//
//            glVertex3f(x_start, -0.1f, z_start);                   // 왼쪽 아래
//            glVertex3f(x_start + cellWidth, -0.1f, z_start);       // 오른쪽 아래
//            glVertex3f(x_start + cellWidth, -0.1f, z_start + cellDepth); // 오른쪽 위
//            glVertex3f(x_start, -0.1f, z_start + cellDepth);       // 왼쪽 위
//
//            glEnd();
//            if (c < 1) {
//                c += 0.2;
//            }
//            else {
//                c = 0.0;
//            }
//        }
//    }
//}
//
//void MyDisplay() {
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//    glMatrixMode(GL_MODELVIEW);
//    glLoadIdentity();
//
//    // 카메라 설정
//    gluLookAt(cameraPosX, 10.0f, cameraPosZ,                     // 카메라 위치
//        cameraPosX + cameraDirectionX, 10.0f, cameraPosZ + cameraDirectionZ, // 카메라가 바라보는 방향
//        0.0, 1.0, 0.0);  
//
//    glPushMatrix();
//    DrawDividedFloor(wide, wide, tiles, tiles); // 너비 180, 깊이 180, 10x10 그리드
//    glPopMatrix();
//
//    // 큐브 배열 생성
//    for (int i = -4; i < 6; i++) {
//        for (int j = -4; j < 6; j++) {
//            glPushMatrix();
//            glTranslated(i * 10 - 5, 0, j * 10 - 5); // 큐브 위치
//            glScalef(1.5, 1.5, 1.5); // 큐브 크기 조정
//
//            glutSolidTeapot(1.0); // 크기 10의 Teapot 생성
//
//            glPopMatrix();
//        }
//    }
//    glFlush();
//}
//
//// 타이머 함수 (전진)
//void TimerFunc(int value) {
//    if (is_running) {
//        // 카메라를 현재 방향으로 전진
//        cameraPosX += cameraDirectionX * (wide / tiles);
//        cameraPosZ += cameraDirectionZ * (wide / tiles);
//    }
//    glutPostRedisplay();       // 화면 갱신 요청
//    glutTimerFunc(1000, TimerFunc, 0); // 1초 후에 다시 호출
//}
//
//// 마우스 클릭 처리 함수
//void MyMouseClick(GLint Button, GLint State, GLint X, GLint Y) {
//    if (Button == GLUT_LEFT_BUTTON && State == GLUT_DOWN) {
//        is_running = !is_running; // 마우스 클릭 시 움직임 토글
//
//        glutPostRedisplay(); // 화면 갱신 요청
//    }
//}
//
//// 키보드 입력 처리 함수 (좌회전 및 우회전)
//void KeyboardFunc(unsigned char key, int x, int y) {
//    float angle; // 회전 각도 (라디안)
//    float newDirX, newDirZ;
//
//    switch (key) {
//    case 'd': // 우회전
//        angle = M_PI / 2; // 90도 (라디안)
//        newDirX = cameraDirectionX * cos(angle) - cameraDirectionZ * sin(angle);
//        newDirZ = cameraDirectionX * sin(angle) + cameraDirectionZ * cos(angle);
//        cameraDirectionX = newDirX;
//        cameraDirectionZ = newDirZ;
//        break;
//
//    case 'a': // 좌회전
//        angle = -M_PI / 2; // -90도 (라디안)
//        newDirX = cameraDirectionX * cos(angle) - cameraDirectionZ * sin(angle);
//        newDirZ = cameraDirectionX * sin(angle) + cameraDirectionZ * cos(angle);
//        cameraDirectionX = newDirX;
//        cameraDirectionZ = newDirZ;
//        break;
//    }
//    glutPostRedisplay(); // 화면 갱신 요청
//}
//
//void MyReshape(int w, int h) {
//    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
//    glMatrixMode(GL_PROJECTION); // 투상 행렬
//    glLoadIdentity();            // 항등 행렬 로드
//    gluPerspective(60.0, (GLdouble)w / h, 0.1, 1000.0); // 원근 투영 설정
//}
//
//int main(int argc, char** argv) {
//    glutInit(&argc, argv);
//    glutInitWindowSize(800, 800);
//    glutInitWindowPosition(100, 100);
//    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
//    glutCreateWindow("OpenGL Cube with Orthographic Projection");
//
//    InitLighting(); // 조명 초기화
//    glutDisplayFunc(MyDisplay);
//    glutReshapeFunc(MyReshape);
//    glutTimerFunc(500, TimerFunc, 0); // 타이머 콜백 함수 등록
//    glutMouseFunc(MyMouseClick); // 마우스 클릭 처리 함수 등록
//    glutKeyboardFunc(KeyboardFunc); // 키보드 입력 처리 함수 등록
//    glutMainLoop();
//    return 0;
//}
