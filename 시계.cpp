//#include <GL/glut.h>
//#include <GL/GL.h>
//#include <GL/GLU.h>
//#include <string.h>
//#include <math.h>
//
//GLfloat red = 1.0f, green = 0.0f, blue = 0.0f;
//GLfloat angle = 0.0f;
//int tick_count = 0;
//int is_running = 0; // 시계 작동 여부
//
//void drawText(float x, float y, const char* string, void* font) {
//    glRasterPos2f(x, y);
//    int len = (int)strlen(string);
//    for (int i = 0; i < len; i++) {
//        glutBitmapCharacter(font, string[i]);
//    }
//}
//
//void drawHand() {
//    glPushMatrix();
//    glRotatef(angle, 0.0f, 0.0f, 1.0f);
//    glBegin(GL_POLYGON);
//    glVertex3f(-0.01, 0, 0.0);
//    glVertex3f(0.01, 0, 0.0);
//    glVertex3f(0.01, 0.4, 0.0);
//    glVertex3f(-0.01, 0.4, 0.0);
//    glEnd();
//    glPopMatrix();
//}
//
//void DisplayMultiple() {
//    glClear(GL_COLOR_BUFFER_BIT);
//
//    // 배경 사각형
//    glColor3f(1, 1, 1);
//    glBegin(GL_POLYGON);
//    glVertex3f(-0.5, -0.5, 0.0);
//    glVertex3f(0.5, -0.5, 0.0);
//    glVertex3f(0.5, 0.5, 0.0);
//    glVertex3f(-0.5, 0.5, 0.0);
//    glEnd();
//
//    // 초침 출력
//    glColor3f(red, green, blue);
//    drawHand();
//
//    // 숫자 출력
//    glColor3f(0.0f, 0.0f, 0.0f);
//    drawText(-0.01f, 0.45f, "12", GLUT_BITMAP_TIMES_ROMAN_10);
//    drawText(0.45f, 0, "3", GLUT_BITMAP_TIMES_ROMAN_10);
//    drawText(-0.01f, -0.45f, "6", GLUT_BITMAP_TIMES_ROMAN_10);
//    drawText(-0.45f, 0, "9", GLUT_BITMAP_TIMES_ROMAN_10);
//
//    glutSwapBuffers();
//}
//
//void timer(int value) {
//    if (is_running) {
//        angle -= 90.0f;
//        if (angle <= -360.0f) {
//            angle = 0.0f;
//        }
//
//        tick_count++;
//        if (tick_count >= 4) {
//            tick_count = 0;
//            if (red == 1.0f) {
//                red = 0.0f; blue = 1.0f;
//            }
//            else {
//                red = 1.0f; blue = 0.0f;
//            }
//        }
//        glutPostRedisplay();
//    }
//    glutTimerFunc(500, timer, 0);
//}
//
//void menuFunc(int value) {
//    switch (value) {
//    case 1: // 시작
//        is_running = 1;
//        break;
//    case 2: // 멈춤
//        is_running = 0;
//        break;
//    case 3: // 초기화
//        is_running = 0;
//        angle = 0.0f;
//        tick_count = 0;
//        red = 1.0f; green = 0.0f; blue = 0.0f;
//        glutPostRedisplay();
//        break;
//    }
//}
//
//int main(int argc, char** argv) {
//    glutInit(&argc, argv);
//    glutInitWindowSize(480, 480);
//    int screenWidth = glutGet(GLUT_SCREEN_WIDTH);
//    int screenHeight = glutGet(GLUT_SCREEN_HEIGHT);
//    glutInitWindowPosition(screenWidth - 480, screenHeight - 480);
//    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
//    glutCreateWindow("2020E7008");
//
//    glutDisplayFunc(DisplayMultiple);
//    glutTimerFunc(0, timer, 0);
//
//    // 메뉴 생성
//    glutCreateMenu(menuFunc);
//    glutAddMenuEntry("Start", 1);
//    glutAddMenuEntry("Stop", 2);
//    glutAddMenuEntry("Reset", 3);
//    glutAttachMenu(GLUT_RIGHT_BUTTON);
//
//    glutMainLoop();
//    return 0;
//}