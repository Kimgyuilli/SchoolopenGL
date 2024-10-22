//#include <GL/glut.h>
//#include <GL/GL.h>
//#include <GL/GLU.h>
//#include <string.h>
//#include <math.h>
//
//GLfloat red = 1.0f, green = 0.0f, blue = 0.0f;
//
//void DisplayMultiple() {
//    glClear(GL_COLOR_BUFFER_BIT);
//
//    // 배경 사각형
//    glColor3f(0, 0, 0); // 노란색
//    glBegin(GL_POLYGON);        	//사각형
//    glVertex3f(-1.0, 1.0, 0.0); // 좌하단 좌표
//    glVertex3f(-1.0, 0.0, 0.0);  // 좌상단 좌표
//    glVertex3f(1.0, 0.0, 0.0);   // 우상단 좌표
//    glVertex3f(1.0, 1.0, 0.0);  // 우하단 좌표	
//    glEnd();
//    glColor3f(1, 1, 1); // 노란색
//    glBegin(GL_POLYGON);        	//사각형
//    glVertex3f(-1.0, -1.0, 0.0); // 좌하단 좌표
//    glVertex3f(-1.0, 0.0, 0.0);  // 좌상단 좌표
//    glVertex3f(1.0, 0.0, 0.0);   // 우상단 좌표
//    glVertex3f(1.0, -1.0, 0.0);  // 우하단 좌표	
//    glEnd();
//
//
//    glFlush();
//    glutSwapBuffers();
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
//
//    glutMainLoop();
//    return 0;
//}
