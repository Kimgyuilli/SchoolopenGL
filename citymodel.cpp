#define PROGRAM_TITLE "Interactive OpenGL Game"

#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>

/*****************Global Variables Start*****************/
GLUquadricObj* t;
float mapBoundary = 100; // Increased map size for larger view
float Window_Width = 1280; // Optimized window width
float Window_Height = 720; // Optimized window height
/*****************Global Variables End*******************/

GLvoid Transform(GLfloat Width, GLfloat Height)
{
	glViewport(0, 0, Width, Height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, Width / Height, 0.1, 1000.0); // Increased far clipping plane
	glMatrixMode(GL_MODELVIEW);
}

GLvoid InitGL(GLfloat Width, GLfloat Height)
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glLineWidth(2.0);              /* Add line width, ditto */
	Transform(Width, Height);      /* Perform the transformation */
	t = gluNewQuadric();
	gluQuadricDrawStyle(t, GLU_FILL);
}

// draws rectangular building with windows
void drawRectangleBuilding(int i, int j, int sel) {
	glMatrixMode(GL_MODELVIEW);
	glCullFace(GL_BACK);

	glPushMatrix();
	//middle
	switch (sel)
	{
	case 0:	
		glTranslatef(i + 8, 7.0f, j + 8.0);
		break;
	case 1:
		glTranslatef(i + 8, 7.0f, j + 17.0);
		break;
	default:
		break;
	}
	//glTranslatef(i + 8, 7.0f, j + 8.0);
	glScalef(3, 3, 3);

	glColorMaterial(GL_FRONT, GL_DIFFUSE);
	glBegin(GL_QUADS);
	// Top face (y = 1.0f)
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(1.0f, 2.5f, -1.0f);
	glVertex3f(-1.0f, 2.5f, -1.0f);
	glVertex3f(-1.0f, 2.5f, 1.0f);
	glVertex3f(1.0f, 2.5f, 1.0f);

	// Front face  (z = 1.0f)
	glColor3f(0.25f, 0.25f, 0.25f);
	glVertex3f(1.0f, 2.5f, 1.0f);
	glVertex3f(-1.0f, 2.5f, 1.0f);
	glVertex3f(-1.0f, -2.5f, 1.0f);
	glVertex3f(1.0f, -2.5f, 1.0f);

	// Back face (z = -1.0f)
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(1.0f, -2.5f, -1.0f);
	glVertex3f(-1.0f, -2.5f, -1.0f);
	glVertex3f(-1.0f, 2.5f, -1.0f);
	glVertex3f(1.0f, 2.5f, -1.0f);

	// Left face (x = -1.0f)
	glColor3f(0.75f, 0.75f, 0.75f);
	glVertex3f(-1.0f, 2.5f, 1.0f);
	glVertex3f(-1.0f, 2.5f, -1.0f);
	glVertex3f(-1.0f, -2.5f, -1.0f);
	glVertex3f(-1.0f, -2.5f, 1.0f);

	// Right face (x = 1.0f)
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(1.0f, 2.5f, -1.0f);
	glVertex3f(1.0f, 2.5f, 1.0f);
	glVertex3f(1.0f, -2.5f, 1.0f);
	glVertex3f(1.0f, -2.5f, -1.0f);

	glEnd();  // End of drawing rectangle building

	glPopMatrix();

}

// draws sphere building with small cylinder on top
void drawSphereBuilding(int i, int j)
{
	glMatrixMode(GL_MODELVIEW);
	glCullFace(GL_BACK);

	// draw sphere on bottom
	glPushMatrix();
	glTranslatef(i, 4.0f, j+8);
	glScalef(2, 2, 2);


	glColor3f(0, 0, 0);
	glutSolidSphere(2, 30, 30);

	glPopMatrix();
	// end draw sphere
}


void drawGround()
{
	// Ground
	glPushMatrix();
	glColor3f(0.5f, 0.5f, 0.5f);
	glTranslatef(0.0f, 0.0f, 0.0f);

	glBegin(GL_QUADS);
	glVertex3f(-mapBoundary * 2, 0.0f, -mapBoundary * 2);
	glVertex3f(-mapBoundary * 2, 0.0f, mapBoundary * 2);
	glVertex3f(mapBoundary * 2, 0.0f, mapBoundary * 2);
	glVertex3f(mapBoundary * 2, 0.0f, -mapBoundary * 2);
	glEnd();

	glPopMatrix();
}

void drawVerticalStreet(int j)
{
	float xint = 9.5;
	glPushMatrix();

	glTranslatef(0, 0.01f, j - 2.2);
	glScalef(5, 0, 5);

	glBegin(GL_TRIANGLE_STRIP);

	// Road center (grey)
	glColor3f(0.3, 0.3, 0.3);
	glVertex3f(-mapBoundary / (xint + 0), 0.1, 0);
	glVertex3f(mapBoundary / (xint + 8.7), 0.1, 0);

	glVertex3f(-mapBoundary / (xint + 0), 0.1, 1);
	glVertex3f(mapBoundary / (xint + 8.7), 0.1, 1);

	glEnd();

	// Median strip (orange)
	glEnable(GL_POLYGON_OFFSET_FILL); // Enable polygon offset
	glPolygonOffset(-1.0, -1.0);      // Offset for depth fighting prevention

	glBegin(GL_TRIANGLE_STRIP);

	glColor3f(1.0, 0.75, 0.0); // Bright orange
	glVertex3f(-mapBoundary / (xint + 0.4), 0.101, 0.45); // Slightly above the road
	glVertex3f(mapBoundary / (xint + 10.4), 0.101, 0.45);
	glVertex3f(-mapBoundary / (xint + 0.4), 0.101, 0.55);
	glVertex3f(mapBoundary / (xint + 10.4), 0.101, 0.55);

	glEnd();

	glDisable(GL_POLYGON_OFFSET_FILL); // Disable polygon offset

	glPopMatrix();
}

void drawHorizontalStreet(int j)
{
	float yint = 9.5;
	glPushMatrix();

	glTranslatef(j - 2.5, 0.02f, 0.0);
	glScalef(5, 0, 5);
	glRotatef(90, 0, 1, 0);

	glBegin(GL_TRIANGLE_STRIP);

	// Road center (grey)
	glColor3f(0.3, 0.3, 0.3);
	glVertex3f(-mapBoundary / (yint + 10.5), 0.1, 0);
	glVertex3f(mapBoundary / (yint + 0.5), 0.1, 0);

	glVertex3f(-mapBoundary / (yint + 10.5), 0.1, 1);
	glVertex3f(mapBoundary / (yint + 0.5), 0.1, 1);

	glEnd();

	// Median strip (orange)
	glEnable(GL_POLYGON_OFFSET_FILL); // Enable polygon offset
	glPolygonOffset(-1.0, -1.0);      // Offset for depth fighting prevention
	glBegin(GL_TRIANGLE_STRIP);

	glColor3f(1.0, 0.75, 0.0);
	glVertex3f(-mapBoundary / (yint + 10.4), 0.101, 0.45);
	glVertex3f(mapBoundary / (yint + 0.4), 0.101, 0.45);

	glVertex3f(-mapBoundary / (yint + 10.4), 0.101, 0.55);
	glVertex3f(mapBoundary / (yint + 0.4), 0.101, 0.55);

	glEnd();
	glDisable(GL_POLYGON_OFFSET_FILL); // Disable polygon offset
	glPopMatrix();
}


void generateCity()
{
	// Draw the streets
	for (int i = -2; i < 2; i++)
	{
		for (int j = -2; j < 2; j++)
		{
			// Vertical and Horizontal streets are separated by 25 units
			drawVerticalStreet(25 * i);
			drawHorizontalStreet(25 * j);
		}
	}
}

void processLookAtView()
{
	glLoadIdentity();
	glRotatef(-45, 0, 0, 1);
	gluLookAt(30.0, 60.0, 30.0, 0.0, 0.0, 0.0, 0.0, 0.0, -1.0); // Optimized camera position
	glPushMatrix();
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(1.0, 1.0, 1.0, 1.0);
	InitGL(Window_Width, Window_Height);
	processLookAtView();
	generateCity();
	drawGround();
	for (int z = 0; z < 3; z++) {
		for (int i = 0; i < 2; i++) {
			drawRectangleBuilding(0, z * (-25), i);
			drawSphereBuilding(17, i*10);
		}
	}
	glutSwapBuffers();
}

void reshape(GLsizei width, GLsizei height)
{
	if (height == 0)
		height = 1; // To prevent divide by 0
	GLfloat aspect = (GLfloat)width / (GLfloat)height;

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0f, aspect, 0.1f, 1000.0f); // Increased far clipping plane
}

/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv)
{
	glutInit(&argc, argv);						 // Initialize GLUT
	glutInitDisplayMode(GLUT_DOUBLE);			 // Enable double buffered mode
	glutInitWindowSize(Window_Width, Window_Height); // Set the window's initial width & height
	glutInitWindowPosition(50, 50);				 // Position the window's initial top-left corner
	glutCreateWindow(PROGRAM_TITLE);			 // Create window with the given title
	glutDisplayFunc(display);					 // Register callback handler for window re-paint event
	glutIdleFunc(display);						 // If nothing to do, refresh screen
	glutReshapeFunc(reshape);					 // Register callback handler for window re-size event

	glEnable(GL_DEPTH_TEST);					 // Enable depth testing
	glutMainLoop();								 // Enter the infinite event-processing loop
	return 0;
}
