//#include <GL/glut.h>
//#include <GL/GL.h>
//#include <GL/GLU.h>
//#include <string.h>
//#include <math.h>
//#include <iostream>
//
//GLfloat red = 0.0f, green = 0.0f, blue = 0.0f;
//int up = 0;
//int down = 0;
//void DisplayMultiple() {
//    glClear(GL_COLOR_BUFFER_BIT);
//
//    // À§
//    glColor3f(0, 0, 0); //°ËÀº»ö
//    if(up) glColor3f(0, 1, 0);
//    glBegin(GL_POLYGON);        	//»ç°¢Çü
//    glVertex3f(-1.0, 1.0, 0.0); // ÁÂÇÏ´Ü ÁÂÇ¥
//    glVertex3f(-1.0, 0.0, 0.0);  // ÁÂ»ó´Ü ÁÂÇ¥
//    glVertex3f(1.0, 0.0, 0.0);   // ¿ì»ó´Ü ÁÂÇ¥
//    glVertex3f(1.0, 1.0, 0.0);  // ¿ìÇÏ´Ü ÁÂÇ¥	
//    glEnd();
//    //¾Æ·¡
//    glColor3f(1, 1, 1); // Èò»ö
//    if (down) glColor3f(0, 1, 0);
//    glBegin(GL_POLYGON);        	//»ç°¢Çü
//    glVertex3f(-1.0, -1.0, 0.0); // ÁÂÇÏ´Ü ÁÂÇ¥
//    glVertex3f(-1.0, 0.0, 0.0);  // ÁÂ»ó´Ü ÁÂÇ¥
//    glVertex3f(1.0, 0.0, 0.0);   // ¿ì»ó´Ü ÁÂÇ¥
//    glVertex3f(1.0, -1.0, 0.0);  // ¿ìÇÏ´Ü ÁÂÇ¥	
//    glEnd();
//
//    glFlush();
//    glutSwapBuffers();
//}
//
//void MyMouseClick(GLint Button, GLint State, GLint X, GLint Y) {
//    if (Button == GLUT_LEFT_BUTTON && State == GLUT_DOWN) {
//        std::cout << Y << std::endl;
//        if (Y < 200) {
//            up = true;
//            down = false;
//        }
//        else {
//            down = true;
//            up = false;
//        }
//    }
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
//    glClearColor(1.0, 1.0, 1.0, 1.0); // ¹è°æ»ö ¼³Á¤
//    glutDisplayFunc(DisplayMultiple);
//    glutMouseFunc(MyMouseClick);	
//    glutMainLoop();
//    return 0;
//}
