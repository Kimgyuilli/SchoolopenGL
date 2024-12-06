//#define _USE_MATH_DEFINES
//#include <gl/glut.h>
//#include <gl/gl.h>
//#include <gl/glu.h>
//#include <stdio.h>
//#include <cmath>
//
//float angleX = 0.0f;  // X축 회전 각도
//float angleY = 0.0f;  // Y축 회전 각도
//float angleThetaX = 0.0f; // 카메라 좌우 회전 각도
//float angleThetaY = 0.0f; // 카메라 상하 회전 각도
//
//GLfloat radius = 3.0; // 카메라의 반지름(물체와의 거리)
//GLfloat eX, eY = 0.0, eZ; // 카메라 위치 계산용 변수
//GLfloat aX = 0.0, aY = 0.0, aZ = 0.0; // 물체 중심 위치
//GLfloat uX = 0.0, uY = 1.0, uZ = 0.0; // 카메라 상단 방향
//
//// 기존 정육면체의 정점 (0-7) + 삼각뿔의 꼭짓점 (8)
//GLfloat MyVertices[10][3] = {
//    {-0.25,-0.25,0.25}, {-0.25,0.25,0.25}, {0.25,0.25,0.25}, {0.25,-0.25,0.25},
//    {-0.25,-0.25,-0.25}, {-0.25,0.25,-0.25}, {0.25,0.25,-0.25}, {0.25,-0.25,-0.25},
//    {0.0, 0.75, -0.125}, {0.0,0.25,0.25},
//};
//
//GLfloat MyColors[9][3] = {
//    {0.5,0.5,0.5}, {0.5,0.5,0.5}, {0.5,0.5,0.5}, {0.5,0.5,0.5},
//    {0.5,0.5,0.5}, {0.5,0.5,0.5}, {0.5,0.5,0.5}, {0.5,0.5,0.5},
//    {0.5,0.5,0.5}
//};
//
//GLubyte MyVertexList[33] = {
//    0,4,7,3, 4,5,6,7, 0,1,5,4, 0,3,2,1, 2,3,7,6, 1,2,6,5,
//    5,8,6, 6,8,9, 9,8,5
//};
//
//void setupLighting()
//{
//    // 조명을 활성화하고 특정 조명 소스를 활성화
//    glEnable(GL_LIGHTING); // OpenGL에서 조명 기능 활성화
//    glEnable(GL_LIGHT0);   // 기본 조명 소스(GL_LIGHT0) 활성화
//
//    // 조명 속성을 정의
//    GLfloat light_ambient[] = { 0.2f, 0.2f, 0.2f, 1.0f };  // 주변광 (ambient light): 공간 전체에 퍼져 있는 부드러운 빛
//    GLfloat light_diffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };  // 확산광 (diffuse light): 물체 표면에 균일하게 퍼지는 빛
//    GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f }; // 반사광 (specular light): 표면에서 반사되어 반짝이는 빛
//    GLfloat light_position[] = { 6.0f, -6.0f, 6.0f, 1.0f }; // 조명의 위치 (x, y, z, w). w가 1이면 점광원, 0이면 방향광원
//
//    // 정의한 조명 속성을 GL_LIGHT0에 적용
//    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);  // GL_LIGHT0에 주변광 설정
//    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);  // GL_LIGHT0에 확산광 설정
//    //glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular); // GL_LIGHT0에 반사광 설정
//    glLightfv(GL_LIGHT0, GL_POSITION, light_position); // GL_LIGHT0의 위치 설정
//
//    // 색상 재질(Color Material) 기능 활성화: 물체의 색상과 조명을 간단히 연동하기 위해 사용
//    glEnable(GL_COLOR_MATERIAL); // GL_COLOR_MATERIAL 활성화
//    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE); // 앞면 폴리곤에 대해 주변광 및 확산광에 색상 사용
//
//    // 물체의 재질 특성을 설정
//    glMaterialfv(GL_FRONT, GL_SPECULAR, light_specular); // 물체 앞면의 반사광 재질 설정
//    glMateriali(GL_FRONT, GL_SHININESS, 50); // 물체 앞면의 광택도 설정 (0~128, 높을수록 빛이 집중적으로 반사됨)
//}
//
//
//// 선형 보간 함수 추가
//float lerp(float a, float b, float t) {
//    return a + t * (b - a);
//}
//
//void UpdateCameraPosition() {
//    // 각도 제한을 180도로 확장 (π 라디안)
//    const float maxAngleY = M_PI - 0.1f;
//    angleThetaY = std::fmax(std::fmin(angleThetaY, maxAngleY), -maxAngleY);
//
//    // 카메라 위치 계산
//    eX = radius * cos(angleThetaY) * cos(angleThetaX);
//    eZ = radius * cos(angleThetaY) * sin(angleThetaX);
//    eY = radius * sin(angleThetaY);
//
//    // UP 벡터 동적 조정
//    // 카메라가 뒤집어질 때 UP 벡터도 함께 조정
//    if (angleThetaY > M_PI_2 || angleThetaY < -M_PI_2) {
//        uY = -1.0; // UP 벡터를 반전
//    }
//    else {
//        uY = 1.0;  // 기본 UP 벡터
//    }
//
//    // 추가적인 안정성을 위한 보정
//    // 90도 부근에서의 불안정성 처리
//    if (fabs(angleThetaY) > M_PI_2 - 0.1f && fabs(angleThetaY) < M_PI_2 + 0.1f) {
//        float t = (fabs(angleThetaY) - (M_PI_2 - 0.1f)) / 0.2f;
//        uY = lerp(uY, 0.0f, t);
//    }
//}
//
//void MyDisplay() {
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//    glEnable(GL_DEPTH_TEST);
//    glFrontFace(GL_CCW);
//    glEnableClientState(GL_COLOR_ARRAY);
//    glEnableClientState(GL_VERTEX_ARRAY);
//
//    glColorPointer(3, GL_FLOAT, 0, MyColors);
//    glVertexPointer(3, GL_FLOAT, 0, MyVertices);
//
//    glMatrixMode(GL_MODELVIEW);
//    glLoadIdentity();
//    gluLookAt(eX, eY, eZ, aX, aY, aZ, uX, uY, uZ);
//
//    glRotatef(angleX, 1.0f, 0.0f, 0.0f);
//    glRotatef(angleY, 0.0f, 1.0f, 0.0f);
//
//    for (int i = 0; i < 6; i++) {
//        glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_BYTE, &MyVertexList[4 * i]);
//    }
//
//    glDisable(GL_DEPTH_TEST);
//    glFlush();
//    glutSwapBuffers();
//}
//
//void KB(unsigned char KeyPressed, int X, int Y) {
//    switch (KeyPressed) {
//    case 'a': case 'A': angleThetaX -= 0.1f; break;
//    case 'd': case 'D': angleThetaX += 0.1f; break;
//    case 'w': case 'W': angleThetaY -= 0.1f; break;
//    case 's': case 'S': angleThetaY += 0.1f; break;
//    }
//    UpdateCameraPosition();
//    printf("eye(%.2f, %.2f, %.2f) at(%.2f, %.2f, %.2f) up(%.2f, %.2f, %.2f)\n", eX, eY, eZ, aX, aY, aZ, uX, uY, uZ);
//    glutPostRedisplay();
//}
//
//void SpecialKeys(int key, int x, int y) {
//    switch (key) {
//    case GLUT_KEY_RIGHT: angleY += 5.0f; break;
//    case GLUT_KEY_LEFT: angleY -= 5.0f; break;
//    case GLUT_KEY_UP: angleX += 5.0f; break;
//    case GLUT_KEY_DOWN: angleX -= 5.0f; break;
//    }
//    glutPostRedisplay();
//}
//
//void SetupProjection() {
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluPerspective(45.0, 1.0, 1.0, 10.0);
//}
//
//int main(int argc, char** argv) {
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
//    glutInitWindowSize(500, 500);
//    glutInitWindowPosition(100, 100);
//    glutCreateWindow("OpenGL Rotating Cube with Circular Camera Movement");
//
//    glClearColor(0.0, 0.0, 0.0, 1.0);
//    setupLighting();
//    SetupProjection();
//    UpdateCameraPosition();
//    glutDisplayFunc(MyDisplay);
//    glutSpecialFunc(SpecialKeys);
//    glutKeyboardFunc(KB);
//    glutMainLoop();
//    return 0;
//}
