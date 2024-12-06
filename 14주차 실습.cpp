//#define _USE_MATH_DEFINES
//#include <gl/glut.h>
//#include <gl/gl.h>
//#include <gl/glu.h>
//#include <stdio.h>
//#include <cmath>
//
//float angleX = 0.0f;  // X�� ȸ�� ����
//float angleY = 0.0f;  // Y�� ȸ�� ����
//float angleThetaX = 0.0f; // ī�޶� �¿� ȸ�� ����
//float angleThetaY = 0.0f; // ī�޶� ���� ȸ�� ����
//
//GLfloat radius = 3.0; // ī�޶��� ������(��ü���� �Ÿ�)
//GLfloat eX, eY = 0.0, eZ; // ī�޶� ��ġ ���� ����
//GLfloat aX = 0.0, aY = 0.0, aZ = 0.0; // ��ü �߽� ��ġ
//GLfloat uX = 0.0, uY = 1.0, uZ = 0.0; // ī�޶� ��� ����
//
//// ���� ������ü�� ���� (0-7) + �ﰢ���� ������ (8)
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
//    // ������ Ȱ��ȭ�ϰ� Ư�� ���� �ҽ��� Ȱ��ȭ
//    glEnable(GL_LIGHTING); // OpenGL���� ���� ��� Ȱ��ȭ
//    glEnable(GL_LIGHT0);   // �⺻ ���� �ҽ�(GL_LIGHT0) Ȱ��ȭ
//
//    // ���� �Ӽ��� ����
//    GLfloat light_ambient[] = { 0.2f, 0.2f, 0.2f, 1.0f };  // �ֺ��� (ambient light): ���� ��ü�� ���� �ִ� �ε巯�� ��
//    GLfloat light_diffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };  // Ȯ�걤 (diffuse light): ��ü ǥ�鿡 �����ϰ� ������ ��
//    GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f }; // �ݻ籤 (specular light): ǥ�鿡�� �ݻ�Ǿ� ��¦�̴� ��
//    GLfloat light_position[] = { 6.0f, -6.0f, 6.0f, 1.0f }; // ������ ��ġ (x, y, z, w). w�� 1�̸� ������, 0�̸� ���Ɽ��
//
//    // ������ ���� �Ӽ��� GL_LIGHT0�� ����
//    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);  // GL_LIGHT0�� �ֺ��� ����
//    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);  // GL_LIGHT0�� Ȯ�걤 ����
//    //glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular); // GL_LIGHT0�� �ݻ籤 ����
//    glLightfv(GL_LIGHT0, GL_POSITION, light_position); // GL_LIGHT0�� ��ġ ����
//
//    // ���� ����(Color Material) ��� Ȱ��ȭ: ��ü�� ����� ������ ������ �����ϱ� ���� ���
//    glEnable(GL_COLOR_MATERIAL); // GL_COLOR_MATERIAL Ȱ��ȭ
//    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE); // �ո� �����￡ ���� �ֺ��� �� Ȯ�걤�� ���� ���
//
//    // ��ü�� ���� Ư���� ����
//    glMaterialfv(GL_FRONT, GL_SPECULAR, light_specular); // ��ü �ո��� �ݻ籤 ���� ����
//    glMateriali(GL_FRONT, GL_SHININESS, 50); // ��ü �ո��� ���õ� ���� (0~128, �������� ���� ���������� �ݻ��)
//}
//
//
//// ���� ���� �Լ� �߰�
//float lerp(float a, float b, float t) {
//    return a + t * (b - a);
//}
//
//void UpdateCameraPosition() {
//    // ���� ������ 180���� Ȯ�� (�� ����)
//    const float maxAngleY = M_PI - 0.1f;
//    angleThetaY = std::fmax(std::fmin(angleThetaY, maxAngleY), -maxAngleY);
//
//    // ī�޶� ��ġ ���
//    eX = radius * cos(angleThetaY) * cos(angleThetaX);
//    eZ = radius * cos(angleThetaY) * sin(angleThetaX);
//    eY = radius * sin(angleThetaY);
//
//    // UP ���� ���� ����
//    // ī�޶� �������� �� UP ���͵� �Բ� ����
//    if (angleThetaY > M_PI_2 || angleThetaY < -M_PI_2) {
//        uY = -1.0; // UP ���͸� ����
//    }
//    else {
//        uY = 1.0;  // �⺻ UP ����
//    }
//
//    // �߰����� �������� ���� ����
//    // 90�� �αٿ����� �Ҿ����� ó��
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
