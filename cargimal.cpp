//#include <gl/glut.h>
//#include <gl/gl.h>
//#include <gl/glu.h>
//int Width, Height;
//
//void Init() {
//	glClearColor(1.0, 1.0, 1.0, 1.0);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	glOrtho(-2.0, 2.0, -2.0, 2.0, 0.5, 5.0);
//
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//	//glMatrixMode(GL_MODELVIEW);
//	//glLoadIdentity( );
//}
//
//void InitLight() {
//	GLfloat mat_diffuse[] = { 0.5, 0.4, 0.3, 1.0 };
//	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
//	GLfloat mat_ambient[] = { 0.5, 0.4, 0.3, 1.0 };
//	GLfloat mat_shininess[] = { 15.0 };
//	GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
//	GLfloat light_diffuse[] = { 0.8, 0.8, 0.8, 1.0 };
//	GLfloat light_ambient[] = { 0.3, 0.3, 0.3, 1.0 };
//	GLfloat light_position[] = { -3, 6, 3.0, 0.0 };
//	glShadeModel(GL_SMOOTH);
//	glEnable(GL_DEPTH_TEST);
//	glEnable(GL_LIGHTING);
//	glEnable(GL_LIGHT0);
//	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
//	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
//	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
//	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
//	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
//	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
//	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
//	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
//}
//
//void DrawScene() {
//	glColor3f(0.7, 0.7, 0.7);
//	glPushMatrix();
//	glTranslatef(0.0, -1.0, 0.0);
//	glBegin(GL_QUADS);
//	glVertex3f(2.0, 0.0, 2.0);
//	glVertex3f(2.0, 0.0, -2.0);
//	glVertex3f(-2.0, 0.0, -2.0);
//	glVertex3f(-2.0, 0.0, 2.0);
//	glEnd();
//	glPopMatrix();
//
//	glColor3f(0.3, 0.3, 0.7);
//
//	glPushMatrix();
//	glTranslatef(0.0, 0.0, -0.5);
//	glutWireTeapot(1.0);
//	glPopMatrix();
//}
//
//void MyDisplay() {
//	glClear(GL_COLOR_BUFFER_BIT);
//	glColor3f(1.0, 1.0, 1.0);
//
//	float w = Width / 3;
//
//
//
//
//	glViewport(0 * w, 0, w, Height);
//	glPushMatrix();
//	gluLookAt(0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
//	DrawScene();
//	glPopMatrix();
//
//
//	glViewport(1 * w, 0, w, Height);
//	glPushMatrix();
//	gluLookAt(5.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
//	DrawScene();
//	glPopMatrix();
//
//	glViewport(2 * w, 0, w, Height);
//	glPushMatrix();
//	gluLookAt(0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -1.0);
//	DrawScene();
//	glPopMatrix();
//
//
//	glFlush();
//}
//
//void MyReshape(int w, int h) {
//	Width = w;   Height = h;
//}
//
//int main(int argc, char** argv) {
//	glutInit(&argc, argv);
//	Width = 1500; Height = 500;
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
//	glutInitWindowSize(Width, Height);
//	glutInitWindowPosition(0, 0);
//	glutCreateWindow("OpenGL Sample Drawing");
//	Init();
//
//	//InitLight( );
//
//	glutDisplayFunc(MyDisplay);
//	glutReshapeFunc(MyReshape);
//	glutMainLoop();
//	return 0;
//}
