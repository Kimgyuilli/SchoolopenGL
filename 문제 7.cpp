//#include <gl/glut.h>					
//#include <gl/gl.h>						
//#include <gl/glu.h>	
//GLfloat xDelta = 0.0;	
//GLfloat yDelta = 0.0;
//GLboolean Right = true;
//GLboolean Up = true;
//GLfloat x = 0.0;
//GLfloat y = 0.0;
//void MyDisplay( ){	
//    glClear(GL_COLOR_BUFFER_BIT);				  
//    glBegin(GL_POLYGON);   
//    	glRotatef(30.0f, 1.0f, 1.0f, 0.0f);
//        glColor3f(0.0, 0.5, 0.8);
//        glVertex3f(-1.0 + xDelta -x, -0.5 + yDelta -y, 0.0);
//        glVertex3f(0.0 + xDelta + x, -0.5 + yDelta -y, 0.0);
//        glVertex3f(0.0 + xDelta + x, 0.5 + yDelta + y, 0.0);
//        glVertex3f(-1.0 + xDelta - x, 0.5 + yDelta + y, 0.0);
//
//
//
//
//    glEnd( );
//    glutSwapBuffers( );						
//}				
//
//void MyIdle( ){
//    if (Right == true && xDelta > 0.99)
//        Right = false;
//    if (Right == false && xDelta < 0.01)
//        Right = true;
//    if (Up == true && yDelta > 0.5)
//        Up = false;
//    if (Up == false && yDelta < -0.5)
//        Up = true;
//    if (Right == false) {
//        xDelta = xDelta - 0.0002;
//    } else
//        xDelta = xDelta + 0.0002;
//    if (Up == false) {
//        yDelta = yDelta - 0.0002;
//    } else
//        yDelta = yDelta + 0.0002;	
//
//    glutPostRedisplay( );						
//}
//
//int main(int argc, char** argv) {
//    glutInit(&argc,argv); 				
//    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);		    
//    glutInitWindowSize(640, 480);    	
//    glutInitWindowPosition(0, 0); 
//    glutCreateWindow("OpenGL Drawing Example");
//
//    glClearColor (1.0, 1.0, 1.0, 1.0);
//    glMatrixMode(GL_PROJECTION);    
//    glLoadIdentity();    
//    glOrtho(-1.0, 1.0,   -1.0, 1.0,   -1.0, 1.0); 
//
//    glutDisplayFunc(MyDisplay); 			
//    glutIdleFunc(MyIdle); 
//
//    glutMainLoop( );
//    return 0;		
//}
