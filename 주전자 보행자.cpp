//#define _USE_MATH_DEFINES
//#include <gl/glut.h>
//#include <gl/gl.h>
//#include <gl/glu.h>
//#include <math.h>
//
//// 광원 위치 및 방향 설정
//GLfloat LightPosition0[] = { 0.0, 10.0, 10.0, 1.0 }; // 0번 광원의 위치
//GLfloat LightPosition1[] = { 0.0, 20.0, 10.0, 1.0 }; // 1번 광원의 위치
//GLfloat LightDirection1[] = { 0.0, -1.0, 0.0 };      // 1번 광원의 방향 (아래로 비춤)
//
//// 카메라 위치 및 회전 변수
//GLfloat cameraX = 0.0;         // 카메라 X축 위치
//GLfloat cameraZ = 50.0;        // 카메라 Z축 위치
//GLfloat cameraAngle = 0.0;     // 카메라 회전 각도 (도 단위)
//const GLfloat moveStep = 1.0;  // 카메라 전진 속도
//const GLfloat angleStep = 90.0; // 카메라 회전 각도 변화량
//bool is_running = 1;           // 카메라가 움직이는지 여부를 결정하는 변수
//
//// 광원 및 재질 초기화 함수
//void InitLighting() {
//    glEnable(GL_LIGHTING); // 조명 활성화
//    glEnable(GL_LIGHT0);   // 0번 광원 활성화
//    glEnable(GL_LIGHT1);   // 1번 광원 활성화
//    glEnable(GL_DEPTH_TEST); // 깊이 테스트 활성화 (3D 객체의 앞뒤 관계 처리)
//
//    // 0번 광원의 확산광 설정
//    GLfloat light0_diffuse[] = { 0.8, 0.8, 0.8, 1.0 };
//    glLightfv(GL_LIGHT0, GL_POSITION, LightPosition0);
//    glLightfv(GL_LIGHT0, GL_DIFFUSE, light0_diffuse);
//
//    // 1번 광원의 확산광 및 스포트라이트 설정
//    GLfloat light1_diffuse[] = { 1.0, 0.5, 0.5, 1.0 };
//    glLightfv(GL_LIGHT1, GL_POSITION, LightPosition1);
//    glLightfv(GL_LIGHT1, GL_DIFFUSE, light1_diffuse);
//    glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, LightDirection1);
//    glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 45.0); // 스포트라이트의 원뿔 각도 설정
//}
//
//// 화면 출력 함수
//void MyDisplay() {
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // 화면 및 깊이 버퍼 초기화
//
//    glMatrixMode(GL_MODELVIEW); // 모델뷰 행렬 설정
//    glLoadIdentity();           // 행렬 초기화
//
//    // 카메라 방향 계산
//    GLfloat lookX = cameraX + sin(cameraAngle * M_PI / 180.0); // 카메라가 바라보는 X축 방향
//    GLfloat lookZ = cameraZ - cos(cameraAngle * M_PI / 180.0); // 카메라가 바라보는 Z축 방향
//
//    // 카메라 위치 및 방향 설정
//    gluLookAt(cameraX, 5.0, cameraZ,  // 카메라 위치 (x, y, z)
//        lookX, 5.0, lookZ,      // 카메라가 바라보는 점 (x, y, z)
//        0.0, 1.0, 0.0);         // 카메라의 위쪽 방향 (y축)
//
//    // 화면에 Teapot(주전자) 그리기
//    glutSolidTeapot(10.0); // 크기 10의 Teapot 생성
//
//    glFlush(); // 렌더링 명령 실행
//}
//
//// 창 크기 변경 처리 함수
//void MyReshape(int w, int h) {
//    if (h == 0) h = 1; // 높이가 0인 경우 방지
//    glViewport(0, 0, w, h); // 뷰포트 설정
//    glMatrixMode(GL_PROJECTION); // 투영 행렬 선택
//    glLoadIdentity(); // 행렬 초기화
//    gluPerspective(45.0, (GLdouble)w / h, 0.1, 1000.0); // 원근 투영 설정
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
//// 타이머 함수 (0.5초마다 호출)
//void TimerFunc(int value) {
//    if (is_running) {
//        // 카메라를 바라보는 방향으로 전진
//        cameraX += moveStep * sin(cameraAngle * M_PI / 180.0); // X축 이동
//        cameraZ -= moveStep * cos(cameraAngle * M_PI / 180.0); // Z축 이동
//    }
//    glutPostRedisplay();       // 화면 갱신 요청
//    glutTimerFunc(500, TimerFunc, 0); // 500ms(0.5초) 후에 다시 호출
//}
//
//// 키보드 입력 처리 함수
//void KeyboardFunc(unsigned char key, int x, int y) {
//    switch (key) {
//    case 'd': // 카메라 우회전
//        cameraAngle += angleStep; // 회전 각도 증가
//        if (cameraAngle >= 360.0) cameraAngle -= 360.0; // 360도 초과 시 초기화
//        break;
//    case 'a': // 카메라 좌회전
//        cameraAngle -= angleStep; // 회전 각도 감소
//        if (cameraAngle < 0.0) cameraAngle += 360.0; // 0도 미만 시 초기화
//        break;
//    }
//    glutPostRedisplay(); // 화면 갱신 요청
//}
//
//// 메인 함수
//int main(int argc, char** argv) {
//    glutInit(&argc, argv); // GLUT 초기화
//    glutInitWindowSize(800, 800); // 창 크기 설정
//    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH); // 렌더링 모드 설정
//    glutCreateWindow("OpenGL Camera Movement Example"); // 창 생성
//
//    InitLighting(); // 광원 및 재질 초기화
//    glutDisplayFunc(MyDisplay); // 디스플레이 콜백 함수 등록
//    glutReshapeFunc(MyReshape); // 창 크기 변경 처리 함수 등록
//    glutKeyboardFunc(KeyboardFunc); // 키보드 입력 처리 함수 등록
//    glutTimerFunc(500, TimerFunc, 0); // 타이머 콜백 함수 등록
//    glutMouseFunc(MyMouseClick); // 마우스 클릭 처리 함수 등록
//    glutMainLoop(); // 이벤트 루프 실행
//    return 0;
//}
