//#include <GL/glut.h>
//#include <math.h>
//#include <iostream>
//#include <chrono>  // 시간 측정을 위한 헤더 파일
//#include <vector>
//
//// 설정 변수
//const int totalPixels = 1700000;   // 전체 그릴 픽셀 수
//const int lineSpacing = 3;         // 라인 간 간격
//int maxLines;                      // 총 라인 수 (자동 계산됨)
//int mode = 1;                      // 기본 모드는 1(선형 보간)
//
//// 픽셀 좌표를 저장하기 위한 구조체
//struct Pixel {
//    int x, y; // 픽셀의 x, y 좌표
//};
//
//// ** 선형 보간(Linearly Interpolation) 방식으로 픽셀 계산 **
//// x 좌표를 기준으로 y 값을 선형 보간 방식으로 계산하여 픽셀 좌표를 저장
//void CalculateLinePixelsLinear(int x1, int y1, int x2, int y2, std::vector<Pixel>& linePixels) {
//    float y, m;
//    int dx, dy;
//    dx = x2 - x1;              // x 좌표 변화량
//    dy = y2 - y1;              // y 좌표 변화량
//    m = (float)dy / dx;        // 기울기 계산
//
//    float x = x1;              // x 시작점
//    while (x <= x2) {          // x가 x2를 넘지 않을 때까지
//        y = m * (x - x1) + y1; // y = mx + c 형태로 y 계산
//        linePixels.push_back({ (int)x, (int)round(y) }); // 픽셀 좌표 저장
//        x += 1;                // x를 1씩 증가
//    }
//}
//
//// ** DDA(Digital Differential Analyzer) 방식으로 픽셀 계산 **
//// x와 y의 증분을 계산하여 픽셀 좌표를 저장
//void CalculateLinePixelsDDA(int x1, int y1, int x2, int y2, std::vector<Pixel>& linePixels) {
//    int dx = x2 - x1; // x 변화량
//    int dy = y2 - y1; // y 변화량
//    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy); // 더 큰 축을 기준으로 스텝 수 결정
//
//    float xIncrement = dx / (float)steps; // x 증분
//    float yIncrement = dy / (float)steps; // y 증분
//
//    float x = x1; // 시작 x 좌표
//    float y = y1; // 시작 y 좌표
//
//    for (int i = 0; i <= steps; i++) {
//        linePixels.push_back({ (int)round(x), (int)round(y) }); // 현재 좌표 저장
//        x += xIncrement; // x 값 증가
//        y += yIncrement; // y 값 증가
//    }
//}
//
//// ** 브레젠햄 알고리즘(Bresenham's Line Algorithm)으로 픽셀 계산 **
//// 정수 연산 기반의 효율적인 선 그리기 알고리즘
//void CalculateLinePixelsBresenham(int x1, int y1, int x2, int y2, std::vector<Pixel>& linePixels) {
//    int dx = abs(x2 - x1), dy = abs(y2 - y1); // x, y 변화량의 절대값
//    int sx = (x1 < x2) ? 1 : -1; // x 증가 방향 결정
//    int sy = (y1 < y2) ? 1 : -1; // y 증가 방향 결정
//    int err = dx - dy;           // 초기 오차 값
//
//    while (true) {
//        linePixels.push_back({ x1, y1 }); // 현재 픽셀 좌표 저장
//        if (x1 == x2 && y1 == y2) break; // 종료 조건: 목적지 도달
//
//        int e2 = 2 * err; // 현재 오차 값을 두 배로 확장
//        if (e2 > -dy) {   // x 방향으로 이동
//            err -= dy;
//            x1 += sx;
//        }
//        if (e2 < dx) {    // y 방향으로 이동
//            err += dx;
//            y1 += sy;
//        }
//    }
//}
//
//// ** 라인 픽셀 그리기 **
//// 계산된 픽셀 좌표를 OpenGL을 이용해 화면에 그리는 함수
//void DrawLine(const std::vector<Pixel>& linePixels) {
//    for (const auto& pixel : linePixels) {
//        glBegin(GL_POINTS);          // 점 그리기 시작
//        glVertex2f(pixel.x, pixel.y); // 픽셀의 좌표 전달
//        glEnd();
//    }
//    glFinish(); // GPU 작업 완료를 보장
//}
//
//// ** 디스플레이 함수 **
//// OpenGL의 렌더링 루프에서 호출되며, 전체 픽셀을 라인 단위로 계산하고 그리는 작업 수행
//void Display() {
//    int remainingPixels = totalPixels;          // 남은 총 픽셀 수
//    float x1 = 0, y1 = 500, x2 = 500, y2 = 200; // 선의 시작과 끝 좌표
//    int currentLine = 0;
//    float g = 0.0, b = 0.0;                     // 색상 초기화
//
//    glColor3d(1.0, g, b); // 초기 색상 설정 (빨강)
//
//    auto start = std::chrono::high_resolution_clock::now(); // 시간 측정 시작
//
//    // 남은 픽셀이 있는 동안 라인 단위로 작업 반복
//    while (remainingPixels > 0) {
//        // 현재 라인의 y 좌표 계산
//        float currentY1 = y1 - lineSpacing * currentLine;
//        float currentY2 = y2 - lineSpacing * currentLine;
//
//        // y 좌표가 0 이하로 내려가면 처음 위치로 돌아감
//        if (currentY1 < 0 || currentY2 < 0) {
//            currentLine = 0; // 첫 번째 라인으로 초기화
//            g += 0.3;        // 색상 변화
//            b += 0.3;
//
//            // 색상이 1.0을 넘지 않도록 제한
//            if (g > 1.0) g = 0.0;
//            if (b > 1.0) b = 0.0;
//
//            glColor3d(1.0, g, b); // 색상 업데이트
//            continue;
//        }
//
//        // 현재 라인의 픽셀 좌표 계산
//        std::vector<Pixel> linePixels;
//        if (mode == 1) {
//            CalculateLinePixelsLinear(x1, currentY1, x2, currentY2, linePixels);
//        }
//        else if (mode == 2) {
//            CalculateLinePixelsDDA(x1, currentY1, x2, currentY2, linePixels);
//        }
//        else if (mode == 3) {
//            CalculateLinePixelsBresenham(x1, currentY1, x2, currentY2, linePixels);
//        }
//
//        // 라인 그리기
//        DrawLine(linePixels);
//
//        // 남은 픽셀 수 갱신
//        remainingPixels -= linePixels.size();
//        currentLine++;
//    }
//
//    auto end = std::chrono::high_resolution_clock::now(); // 시간 측정 종료
//    std::chrono::duration<double> duration = end - start; // 총 소요 시간 계산
//    std::cout << "실행시간: " << duration.count() << " seconds" << std::endl;
//}
//
//// ** 메인 함수 **
//// 프로그램의 시작점으로, 사용자 입력을 받아 모드 설정 후 OpenGL 초기화 및 실행
//int main(int argc, char** argv) {
//    // 사용자 입력 받아 모드 설정
//    std::cout << "모드 선택:\n";
//    std::cout << "1: Linear Interpolation\n";
//    std::cout << "2: DDA\n";
//    std::cout << "3: Bresenham\n";
//    std::cin >> mode;
//
//    // 잘못된 입력 처리
//    if (mode < 1 || mode > 3) {
//        std::cerr << "잘못된 입력입니다.\n";
//        mode = 1;
//    }
//
//    // 총 라인 수 계산
//    maxLines = (500 - 200) / lineSpacing + 1; // 라인 수 계산
//
//    // OpenGL 초기화
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // 단일 버퍼, RGB 모드
//    glutInitWindowSize(640, 380);               // 창 크기 설정
//    glutCreateWindow("OpenGL Pixel Drawing");   // 창 생성
//    glClearColor(1.0, 1.0, 1.0, 1.0);           // 배경 색상 설정 (흰색)
//    glOrtho(0.0, 500.0, 0.0, 500.0, -1.0, 1.0); // 2D orthographic projection 설정
//
//    glutDisplayFunc(Display); // 디스플레이 콜백 함수 등록
//    glutMainLoop();           // OpenGL 이벤트 루프 시작
//    return 0;
//}
