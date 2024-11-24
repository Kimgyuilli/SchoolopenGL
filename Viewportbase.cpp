//#include <GL/glut.h>
//#include <GL/GL.h>
//#include <GL/GLU.h>
//#include <string.h>
//#include <math.h>
//
//GLfloat red = 1.0f, green = 0.0f, blue = 0.0f;
//GLfloat angle = 0.0f;
//
//// 윈도우 크기 변경 시 호출되는 함수 (뷰포트 크기 설정)
//void ResizeViewport(int w, int h) {
//    // 윈도우의 폭이나 높이가 0이 되는 것을 방지
//    if (h == 0) h = 1;
//
//    // 뷰포트 설정 (x, y, width, height)
//    glViewport(0, 0, w, h);
//
//    // 투영 행렬 초기화
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//
//    // 윈도우의 종횡비에 맞게 좌표계 설정
//    gluOrtho2D(0.0, w, 0.0, h);
//
//    // 모델뷰 행렬로 변경
//    glMatrixMode(GL_MODELVIEW);
//}
//
//void DisplayMultiple() {
//    // 화면을 흰색으로 클리어
//    glClear(GL_COLOR_BUFFER_BIT);
//
//
//
//    // 버퍼를 교체하여 그린 내용을 화면에 표시
//    glutSwapBuffers();
//}
//
//int main(int argc, char** argv) {
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
//    glutInitWindowSize(480, 480);  // 윈도우 크기
//    glutInitWindowPosition(100, 100);  // 윈도우 시작 위치
//    glutCreateWindow("OpenGL Viewport Example");
//
//    // 배경색을 흰색으로 설정
//    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
//
//    // 디스플레이 콜백 함수 등록
//    glutDisplayFunc(DisplayMultiple);
//
//    // 윈도우 크기 변경 시 호출될 콜백 함수 등록
//    glutReshapeFunc(ResizeViewport);
//
//    // 메인 루프 실행
//    glutMainLoop();
//    return 0;
//}
