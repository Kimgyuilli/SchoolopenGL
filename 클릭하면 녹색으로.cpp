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
//    // ��
//    glColor3f(0, 0, 0); //������
//    if(up) glColor3f(0, 1, 0);
//    glBegin(GL_POLYGON);        	//�簢��
//    glVertex3f(-1.0, 1.0, 0.0); // ���ϴ� ��ǥ
//    glVertex3f(-1.0, 0.0, 0.0);  // �»�� ��ǥ
//    glVertex3f(1.0, 0.0, 0.0);   // ���� ��ǥ
//    glVertex3f(1.0, 1.0, 0.0);  // ���ϴ� ��ǥ	
//    glEnd();
//    //�Ʒ�
//    glColor3f(1, 1, 1); // ���
//    if (down) glColor3f(0, 1, 0);
//    glBegin(GL_POLYGON);        	//�簢��
//    glVertex3f(-1.0, -1.0, 0.0); // ���ϴ� ��ǥ
//    glVertex3f(-1.0, 0.0, 0.0);  // �»�� ��ǥ
//    glVertex3f(1.0, 0.0, 0.0);   // ���� ��ǥ
//    glVertex3f(1.0, -1.0, 0.0);  // ���ϴ� ��ǥ	
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
//    glClearColor(1.0, 1.0, 1.0, 1.0); // ���� ����
//    glutDisplayFunc(DisplayMultiple);
//    glutMouseFunc(MyMouseClick);	
//    glutMainLoop();
//    return 0;
//}
