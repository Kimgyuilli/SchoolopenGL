//#include <GL/glut.h>
//#include <GL/GL.h>
//#include <GL/GLU.h>
//
//// 색상 상태를 저장하는 변수
//GLfloat red = 1.0f, green = 1.0f, blue = 0.0f;
//
//void DisplayMultiple() {
//    glClear(GL_COLOR_BUFFER_BIT);
//
//    // 첫 번째 도형: 다각형
//    glColor3f(red, green, blue); // 현재 색상
//    glBegin(GL_POLYGON);
//    glVertex3f(-0.5, -0.5, 0.0);
//    glVertex3f(0.5, -0.5, 0.0);
//    glVertex3f(0.5, 0.4, 0.0);
//    glVertex3f(-0.5, 0.4, 0.0);
//    glVertex3f(0.0, 0.0, 0.5);
//    glEnd();
//
//    // 두 번째 도형: 삼각형
//    glColor3f(0.0f, 0.0f, 1.0f); // 파란색
//    glBegin(GL_TRIANGLES);
//    glVertex3f(-0.7, -0.7, 0.0);
//    glVertex3f(-0.4, -0.1, 0.0);
//    glVertex3f(-0.1, -0.7, 0.0);
//    glEnd();
//
//    // 세 번째 도형: 사각형
//    glColor3f(1.0f, 0.0f, 0.0f); // 빨간색
//    glBegin(GL_QUADS);
//    glVertex3f(0.2, 0.2, 0.0);
//    glVertex3f(0.6, 0.2, 0.0);
//    glVertex3f(0.6, 0.6, 0.0);
//    glVertex3f(0.2, 0.6, 0.0);
//    glEnd();
//
//    glFlush();
//}
//
//// 키보드 입력 처리
//void Keyboard(unsigned char key, int x, int y) {
//    switch (key) {
//    case 'r': // 'r' 키 입력 시 빨간색으로 변경
//        red = 1.0f; green = 0.0f; blue = 0.0f;
//        break;
//    case 'g': // 'g' 키 입력 시 초록색으로 변경
//        red = 0.0f; green = 1.0f; blue = 0.0f;
//        break;
//    case 'b': // 'b' 키 입력 시 파란색으로 변경
//        red = 0.0f; green = 0.0f; blue = 1.0f;
//        break;
//    case 'y': // 'y' 키 입력 시 노란색으로 변경
//        red = 1.0f; green = 1.0f; blue = 0.0f;
//        break;
//    }
//    glutPostRedisplay(); // 화면 다시 그리기 요청
//}
//
//void main(int argc, char** argv) {
//    glutInit(&argc, argv);
//    glutCreateWindow("OpenGL Multiple Shapes & Keyboard Interaction");
//    glutDisplayFunc(DisplayMultiple);
//    glutKeyboardFunc(Keyboard); // 키보드 입력 콜백 함수 설정
//    glutMainLoop();
//}
