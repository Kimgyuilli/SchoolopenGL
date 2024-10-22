//#include <GL/glut.h>
//#include <GL/GL.h>
//#include <GL/GLU.h>
//#include <string.h>
//#include <math.h>
//
//GLfloat red = 1.0f, green = 0.0f, blue = 0.0f;
//int is_running = 0;
//int change = true;
//void DisplayMultiple() {
//    glClear(GL_COLOR_BUFFER_BIT);
//
//    // 배경 사각형
//    if (change)
//        glColor3f(1, 0, 0); // 노란색
//    else  glColor3f(0, 0, 1); // 파란색
//    glBegin(GL_POLYGON);        	//사각형
//    glVertex3f(-1.0, 1.0, 0.0); // 좌하단 좌표
//    glVertex3f(-1.0, -1.0, 0.0);  // 좌상단 좌표
//    glVertex3f(0.0, -1.0, 0.0);   // 우상단 좌표
//    glVertex3f(0.0, 1.0, 0.0);  // 우하단 좌표	
//    glEnd();
//    if (change)
//        glColor3f(0, 0, 1); // 파란색
//    else  glColor3f(1, 0, 0); // 노란색
//    glBegin(GL_POLYGON);        	//사각형
//    glVertex3f(0.0, -1.0, 0.0); // 좌하단 좌표
//    glVertex3f(0.0, 1.0, 0.0);  // 좌상단 좌표
//    glVertex3f(1.0, 1.0, 0.0);   // 우상단 좌표
//    glVertex3f(1.0, -1.0, 0.0);  // 우하단 좌표	
//    glEnd();
//
//
//    glFlush();
//    glutSwapBuffers();
//}
//
//void timer(int value) {
//    if (is_running) {
//        change = !change;
//        glutPostRedisplay();
//    }
//    glutTimerFunc(500, timer, 0);
//}
//
//void MyMainMenu(int entryID){				
//    if (entryID == 0)
//        is_running = 1;
//    else if (entryID == 1)
//        is_running = 0;
//    else if (entryID == 2)
//        is_running = 1;
//    glutPostRedisplay(); 
//}	
//
//
//int main(int argc, char** argv) {
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
//    glutInitWindowSize(640, 480);
//    int screenWidth = glutGet(GLUT_SCREEN_WIDTH);
//    int screenHeight = glutGet(GLUT_SCREEN_HEIGHT);
//    glutInitWindowPosition(0, 0);
//    glutCreateWindow("2020E7008");
//    glClearColor(1.0, 1.0, 1.0, 1.0); // 배경색 설정
//    glutDisplayFunc(DisplayMultiple);
//    glutTimerFunc(0, timer, 0);
//
//    GLint MyMainMenuID = glutCreateMenu(MyMainMenu);
//        glutAddMenuEntry("start", 0);
//        glutAddMenuEntry("pause", 1);
//        glutAddMenuEntry("go", 2);
//        glutAttachMenu(GLUT_RIGHT_BUTTON);
//    glutMainLoop();
//    return 0;
//}
