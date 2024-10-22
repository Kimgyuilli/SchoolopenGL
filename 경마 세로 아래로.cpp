//#include <GL/glut.h>
//#include <GL/GL.h>
//#include <GL/GLU.h>
//#include <stdlib.h> // rand() �Լ� ���
//#include <time.h>   // ���� ������ ���� �ð� �ʱ�ȭ
//#include <iostream>
//// ���� �� ȸ�� ���� ����
//GLfloat red = 0.0f, green = 0.0f, blue = 1.0f;
//GLfloat angle = 0.0f;
//int tick_count = 0;
//int is_running = 0; // �ð� �۵� ���θ� ��Ÿ���� ���� (1: �۵�, 0: ����)
//int numberOfBoxes = 3; // �׸� ����
//int boxSize = 10; // �׸� ũ�� (10x10 �ȼ�)
//float boxPositions[6]; // �� �׸��� x ��ǥ�� �����ϴ� �迭
//int boxFinish[6];
//float Distance = 1.0f; // �׸� �̵��Ÿ�
//
//
//// â ũ�Ⱑ ����� �� ȣ��Ǵ� �Լ�
//void reshape(int width, int height) {
//    glViewport(0, 0, width, height); // ���ο� â ũ�⿡ ���� ����Ʈ ����
//    glMatrixMode(GL_PROJECTION); // ���� ��� ���� ����
//    glLoadIdentity(); // ���� ��� �ʱ�ȭ
//    gluOrtho2D(0.0, width, 0.0, height); // 2D ���� ���� ���� (��ǥ�踦 â ũ�⿡ ����)
//    glMatrixMode(GL_MODELVIEW); // �ٽ� �𵨺� ��� ���� ����
//}
//
//// ȭ���� �׸��� �Լ�
//void DisplayMultiple() {
//    glClear(GL_COLOR_BUFFER_BIT); // ȭ���� ����
//    // ������ 6���� �׸� �׸��� (���� 10x10 �ȼ�)
//    for (int i = 0; i < numberOfBoxes; i++) {
//        float y = 780 + boxPositions[i]; // �� �׸��� y ��ǥ
//        float x = (i + 1) * (boxSize + 50); // �� �׸� �� 50�ȼ� �������� �¿��� ��� ��ġ ����
//        glColor3f(red, green, blue); // �׸� �Ķ������� ����
//        if (boxFinish[i]) { // �ڽ��� �ѹ��� ��������
//            glColor3f(1, 0, 0); // �׸� ���������� ����
//        }
//        glPushMatrix(); // ���� ��� ���� ����
//        glTranslatef(x, y, 0.0f); // �׸� x, y ��ǥ�� �̵�
//        glBegin(GL_POLYGON); // �ٰ���(�簢��) �׸��� ����
//        glVertex2f(0.0f, 0.0f); // ���� �ϴ�
//        glVertex2f(0.0f, boxSize); // ���� ���
//        glVertex2f(boxSize, boxSize); // ���� ���
//        glVertex2f(boxSize, 0.0f); // ���� �ϴ�
//        glEnd(); // �ٰ��� �׸��� ��
//        glPopMatrix(); // ���� ��� ���� ����
//    }
//
//    glutSwapBuffers(); // ȭ���� ��ü (���� ���۸�)
//}
//
//void MyKeyboard(unsigned char KeyPressed, int X, int Y) { //Ű���� �Է�
//    switch (KeyPressed) {
//    case 'i': // i �Է½� �ӵ� ����
//        Distance += 1; break;
//    case 'm': // m �Է½� �ӵ� ����
//        Distance -= 1; break;
//    case 'p':
//        is_running = false; break;
//    case 'g':
//        is_running = true; break;
//    case 's':
//        is_running = true; break;
//    }
//    glutPostRedisplay();
//}
//
//void MyMouseClick(GLint Button, GLint State, GLint X, GLint Y) {
//
//    if (Button == GLUT_LEFT_BUTTON && State == GLUT_DOWN) {
//        std::cout << Y << std::endl;
//        // OpenGL ��ǥ�迡�� Y ��ǥ ��ȯ (������ ���� �ϴ�)
//        float clickY = 800 - Y; // Ŭ���� Y ��ǥ ��ȯ (OpenGL������ ���� �ϴ��� ����)
//
//        // Ŭ���� ��ġ�� X ��ǥ�� � �׸��� ������ �ִ��� Ȯ��
//        for (int i = 0; i < numberOfBoxes; i++) {
//            float boxX = (i + 1) * (boxSize + 50); // �� �׸��� X ��ǥ ���
//
//            // Ŭ���� X ��ǥ�� �׸��� X ������ �ִ��� Ȯ��
//            if (X >= boxX && X <= boxX + boxSize && !boxFinish[i]) {
//                // Ŭ���� �׸��� Y ��ǥ�� Ŭ���� Y ��ǥ�� ����
//                boxPositions[i] = clickY - 780; // Ŭ���� Y ��ǥ�� ������Ʈ (boxPositions�� 780���� ����)
//                std::cout << "Box " << i << " moved to Y position: " << boxPositions[i] << std::endl;
//                break; // ù ��° �ش��ϴ� �׸� �̵� �� ���� ����
//            }
//        }
//
//        glutPostRedisplay(); // ȭ���� �ٽ� �׸����� ��û
//    }
//}
//
//
//// Ÿ�̸� �Լ� (0.01�ʸ��� ȣ���)
//void timer(int value) {
//    if (is_running) {
//        // 0.01�ʸ��� ������ �׸� �ϳ��� �Ʒ��� �̵�
//        int randomBox = rand() % numberOfBoxes; // 0���� numberOfBoxes-1 ������ ������ �׸� ����
//        if (boxPositions[randomBox] <= -800) { // Y ��ǥ�� 0�� �����ϸ�
//            boxPositions[randomBox] = 0.0f; // ���� ��ġ�� 0���� ����
//            boxFinish[randomBox] = 1; // ���� ǥ��
//        }
//        if (!boxFinish[randomBox]) // �������� ���� �׸� �̵�
//        {
//            boxPositions[randomBox] -= Distance; // �׸� �Ʒ��� Distance��ŭ �̵�
//        }
//        glutPostRedisplay(); // ȭ���� �ٽ� �׸����� ��û
//    }
//
//    glutTimerFunc(10, timer, 0); // 0.01��(10�и���)���� Ÿ�̸� �Լ� �ٽ� ȣ��
//}
//
//
//void MyMainMenu(int entryID){				
//    if(entryID == 0) 
//		exit(0);							//���α׷� ����
//    glutPostRedisplay(); 
//}	
//
//void MyColorMenu(int entryID) {
//    if (entryID == 0) {
//        red = 1.0;
//        green = 0.0;
//        blue = 0.0;
//    }
//    else if (entryID == 1) {
//        red = 0.0;
//        green = 1.0;
//        blue = 0.0;
//    }
//    else {
//        red = 0.0;
//        green = 0.0;
//        blue = 1.0;
//    }
//    glutPostRedisplay();
//}
//
//void MySpeedMenu(int entryID) {
//    if (entryID == 0)
//        Distance += 1;
//    else if (entryID == 1)
//        Distance -= 1;
//
//    glutPostRedisplay();
//}
//
//// ���� �Լ�
//int main(int argc, char** argv) {
//    srand(time(0)); // ���� ������ ���� �õ� �ʱ�ȭ (���� �ð� ���)
//
//    // �׸���� �ʱ� x ��ǥ�� 10�ȼ��� ���� (���� ������ 10�ȼ� ������ ��ġ)
//    for (int i = 0; i < numberOfBoxes; i++) {
//        boxPositions[i] = 10.0f;
//        boxFinish[i] = 0; //�ڽ� �ʱⰪ
//    }
//
//    glutInit(&argc, argv); // GLUT �ʱ�ȭ
//    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // ���� ���۸��� RGB ��� ����
//    glutInitWindowSize(400, 800); // â ũ�� ����
//    glutInitWindowPosition(0, 0); // â�� �ʱ� ��ġ ����
//    glutCreateWindow("2020E7008 with Viewport"); // â ���� �� ���� ����
//
//    glClearColor(1.0, 1.0, 1.0, 1.0); // ��� ���� ���� (���)
//
//    glutDisplayFunc(DisplayMultiple); // ���÷��� �Լ� ���
//    glutReshapeFunc(reshape); // â ũ�� ���� �� ȣ��� �Լ� ���
//    glutTimerFunc(10, timer, 0); // 0.01�ʸ��� Ÿ�̸� �Լ� ȣ�� ����
//    glutKeyboardFunc(MyKeyboard);
//    glutMouseFunc(MyMouseClick);
//
//    GLint MySubSpeedID = glutCreateMenu(MySpeedMenu);
//        glutAddMenuEntry("Up", 0);
//        glutAddMenuEntry("Down", 1);
//
//
//    GLint MySubColorID = glutCreateMenu(MyColorMenu);
//        glutAddMenuEntry("Red", 0);
//        glutAddMenuEntry("Green", 1);
//        glutAddMenuEntry("Blue", 2);
//
//    GLint MyMainMenuID = glutCreateMenu(MyMainMenu);
//        glutAddSubMenu("Change Speed", MySubSpeedID);		
//        glutAddSubMenu("Change Color", MySubColorID);
//        glutAddMenuEntry("exit", 0);
//        glutAttachMenu(GLUT_RIGHT_BUTTON);
//
//    glutMainLoop(); // �̺�Ʈ ó�� ���� ���� (���α׷��� ����� ������ ����)
//    return 0;
//}
