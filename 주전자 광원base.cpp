//#include <gl/glut.h>
//#include <gl/gl.h>
//#include <gl/glu.h>
//
//// 전역 변수로 광원의 위치와 방향을 정의
//GLfloat LightPosition0[] = { 0.0, 10.0, 10.0, 1.0 }; // 0번 광원의 위치 (점광원)
//GLfloat LightPosition1[] = { -5.0, 10.0, 10.0, 1.0 }; // 1번 광원의 위치 (스포트라이트)
//GLfloat LightDirection1[] = { 0.0, -1.0, -1.0 };      // 1번 광원의 방향 (아래로 비춤)
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
//// 1번 광원 초기화 함수 (스포트라이트)
//void InitLight1() {
//    // 광원의 각 특성을 설정
//    GLfloat light1_ambient[] = { 0.1, 0.1, 0.1, 1.0 }; // 약한 주변광 (전체적인 기본 밝기)
//    GLfloat light1_diffuse[] = { 1.0, 0.5, 0.5, 1.0 }; // 붉은 확산광 (빨간색 계열의 밝기)
//    GLfloat light1_specular[] = { 0.5, 0.5, 0.5, 1.0 }; // 약한 반사광 (희미한 반짝임 효과)
//
//    glEnable(GL_LIGHT1); // 1번 광원 활성화
//    glLightfv(GL_LIGHT1, GL_AMBIENT, light1_ambient); // 주변광 설정
//    glLightfv(GL_LIGHT1, GL_DIFFUSE, light1_diffuse); // 확산광 설정
//    glLightfv(GL_LIGHT1, GL_SPECULAR, light1_specular); // 반사광 설정
//    glLightfv(GL_LIGHT1, GL_POSITION, LightPosition1); // 광원의 위치 설정
//
//    // 스포트라이트 추가 설정
//    glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, LightDirection1); // 스포트라이트 방향 설정
//    glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 45.0); // 스포트라이트 원뿔의 각도 설정 (45도)
//    glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 2.0); // 스포트라이트 집중도 설정 (값이 클수록 중심이 더 밝음)
//}
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
//    glEnable(GL_DEPTH_TEST);   // 깊이 테스트 활성화 (3D 물체의 앞뒤 관계 처리)
//    glShadeModel(GL_SMOOTH);   // 구로 셰이딩 활성화 (부드러운 조명 효과)
//    InitLight0();              // 0번 광원 초기화 (점광원)
//    InitLight1();              // 1번 광원 초기화 (스포트라이트)
//    InitMaterial();            // 물체 재질 초기화
//}
//
//// 화면 출력 함수
//void MyDisplay() {
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // 화면 및 깊이 버퍼 초기화
//
//    glMatrixMode(GL_MODELVIEW); // 모델뷰 행렬 선택
//    glLoadIdentity();           // 행렬 초기화
//
//    // 카메라 설정 (뷰 변환)
//    gluLookAt(0.0, 20.0, 50.0,  // 카메라 위치 (x, y, z)
//              0.0, 0.0, 0.0,    // 카메라가 바라보는 점 (x, y, z)
//              0.0, 1.0, 0.0);   // 카메라의 위쪽 방향 (y축)
//
//    // Teapot(주전자) 그리기
//    glutSolidTeapot(10.0); // 크기 10의 Teapot 생성
//
//    glFlush(); // 렌더링 명령 실행
//}
//
//// 창 크기 변경 처리 함수
//void MyReshape(int w, int h) {
//    if (h == 0) h = 1; // 높이가 0인 경우 방지 (나눗셈 오류 방지)
//    glViewport(0, 0, w, h); // 뷰포트 설정 (윈도우 크기에 맞춤)
//    glMatrixMode(GL_PROJECTION); // 투영 행렬 선택
//    glLoadIdentity(); // 행렬 초기화
//    gluPerspective(45.0, (GLdouble)w / h, 1.0, 1000.0); // 원근 투영 설정
//    // 45도 시야각, 화면 비율 w/h, 근평면 1.0, 원평면 1000.0
//}
//
//// 메인 함수
//int main(int argc, char** argv) {
//    glutInit(&argc, argv); // GLUT 초기화
//    glutInitWindowSize(800, 800); // 창 크기 설정 (800x800)
//    glutInitWindowPosition(100, 100); // 창 위치 설정 (화면 왼쪽 위 기준)
//    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH); // 렌더링 모드 설정 (단일 버퍼, RGBA, 깊이 테스트)
//    glutCreateWindow("OpenGL Lighting Example"); // 창 생성 및 제목 설정
//
//    InitLighting(); // 조명 초기화
//    glutDisplayFunc(MyDisplay); // 디스플레이 콜백 등록 (화면 출력 함수)
//    glutReshapeFunc(MyReshape); // 리쉐이프 콜백 등록 (창 크기 변경 시 호출)
//
//    glutMainLoop(); // 이벤트 루프 실행
//    return 0; // 프로그램 종료 시 반환 값
//}
