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
//    // ��� �簢��
//    glColor3f(0, 0, 0); // �����
//    glBegin(GL_POLYGON);        	//�簢��
//    glVertex3f(-1.0, 1.0, 0.0); // ���ϴ� ��ǥ
//    glVertex3f(-1.0, 0.0, 0.0);  // �»�� ��ǥ
//    glVertex3f(1.0, 0.0, 0.0);   // ���� ��ǥ
//    glVertex3f(1.0, 1.0, 0.0);  // ���ϴ� ��ǥ	
//    glEnd();
//    glColor3f(1, 1, 1); // �����
//    glBegin(GL_POLYGON);        	//�簢��
//    glVertex3f(-1.0, -1.0, 0.0); // ���ϴ� ��ǥ
//    glVertex3f(-1.0, 0.0, 0.0);  // �»�� ��ǥ
//    glVertex3f(1.0, 0.0, 0.0);   // ���� ��ǥ
//    glVertex3f(1.0, -1.0, 0.0);  // ���ϴ� ��ǥ	
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
//    glClearColor(1.0, 1.0, 1.0, 1.0); // ���� ����
//    glutDisplayFunc(DisplayMultiple);
//
//    glutMainLoop();
//    return 0;
//}
