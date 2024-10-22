//#include <GL/glut.h>
//#include <GL/GL.h>
//#include <GL/GLU.h>
//#include <string.h>
//#include <math.h>
//
//GLfloat red = 1.0f, green = 0.0f, blue = 0.0f;
//int isRunning = 0;
//float centerX = 0.0; // 사각형의 중앙 X 좌표
//float centerY = 0.0; // 사각형의 중앙 Y 좌표
//
//void DisplayMultiple() {
//    glClear(GL_COLOR_BUFFER_BIT);
//
//    // 배경 사각형
//    glColor3f(1, 0, 0); // 빨간색
//    glBegin(GL_POLYGON); // 사각형
//    glVertex3f(centerX - 0.1, centerY + 0.1, 0.0); // 좌상단 좌표
//    glVertex3f(centerX - 0.1, centerY - 0.1, 0.0); // 좌하단 좌표
//    glVertex3f(centerX + 0.1, centerY - 0.1, 0.0); // 우하단 좌표
//    glVertex3f(centerX + 0.1, centerY + 0.1, 0.0); // 우상단 좌표	
//    glEnd();
//
//    glFlush();
//    glutSwapBuffers();
//}
//
//void MyMouseClick(GLint Button, GLint State, GLint X, GLint Y) {
//    if (Button == GLUT_LEFT_BUTTON && State == GLUT_DOWN) {
//        // 클릭한 위치를 OpenGL 좌표계로 변환
//        float normalizedX = (float)(X - 300) / 300; // 창의 중앙을 기준으로 X 좌표를 정규화
//        float normalizedY = (float)(300 - Y) / 300; // Y 좌표는 반전됨
//
//        if (isRunning) {
//            // 클릭한 방향으로 사각형 이동
//            if (fabs(normalizedX) > fabs(normalizedY)) {
//                // X 방향으로 이동
//                centerX += (normalizedX > 0) ? 0.1f : -0.1f;
//            }
//            else {
//                // Y 방향으로 이동
//                centerY += (normalizedY > 0) ? 0.1f : -0.1f;
//            }
//        }
//    }
//
//    if (Button == GLUT_RIGHT_BUTTON && State == GLUT_DOWN) {
//        isRunning = !isRunning; // 상태를 토글
//    }
//
//    glutPostRedisplay(); // 화면 다시 그리기
//}
//
//int main(int argc, char** argv) {
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
//    glutInitWindowSize(600, 400);
//    int screenWidth = glutGet(GLUT_SCREEN_WIDTH);
//    int screenHeight = glutGet(GLUT_SCREEN_HEIGHT);
//    glutInitWindowPosition(screenWidth - 600, screenHeight - 450);
//    glutCreateWindow("2020E7008");
//    glClearColor(1.0, 1.0, 1.0, 1.0); // 배경색 설정
//    glutDisplayFunc(DisplayMultiple);
//    glutMouseFunc(MyMouseClick);
//    glutMainLoop();
//    return 0;
//}
