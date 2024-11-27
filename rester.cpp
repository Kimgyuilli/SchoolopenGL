//#include <GL/glut.h>
//#include <math.h>
//#include <iostream>
//#include <chrono>  // �ð� ������ ���� ��� ����
//#include <vector>
//
//// ���� ����
//const int totalPixels = 1700000;   // ��ü �׸� �ȼ� ��
//const int lineSpacing = 3;         // ���� �� ����
//int maxLines;                      // �� ���� �� (�ڵ� ����)
//int mode = 1;                      // �⺻ ���� 1(���� ����)
//
//// �ȼ� ��ǥ�� �����ϱ� ���� ����ü
//struct Pixel {
//    int x, y; // �ȼ��� x, y ��ǥ
//};
//
//// ** ���� ����(Linearly Interpolation) ������� �ȼ� ��� **
//// x ��ǥ�� �������� y ���� ���� ���� ������� ����Ͽ� �ȼ� ��ǥ�� ����
//void CalculateLinePixelsLinear(int x1, int y1, int x2, int y2, std::vector<Pixel>& linePixels) {
//    float y, m;
//    int dx, dy;
//    dx = x2 - x1;              // x ��ǥ ��ȭ��
//    dy = y2 - y1;              // y ��ǥ ��ȭ��
//    m = (float)dy / dx;        // ���� ���
//
//    float x = x1;              // x ������
//    while (x <= x2) {          // x�� x2�� ���� ���� ������
//        y = m * (x - x1) + y1; // y = mx + c ���·� y ���
//        linePixels.push_back({ (int)x, (int)round(y) }); // �ȼ� ��ǥ ����
//        x += 1;                // x�� 1�� ����
//    }
//}
//
//// ** DDA(Digital Differential Analyzer) ������� �ȼ� ��� **
//// x�� y�� ������ ����Ͽ� �ȼ� ��ǥ�� ����
//void CalculateLinePixelsDDA(int x1, int y1, int x2, int y2, std::vector<Pixel>& linePixels) {
//    int dx = x2 - x1; // x ��ȭ��
//    int dy = y2 - y1; // y ��ȭ��
//    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy); // �� ū ���� �������� ���� �� ����
//
//    float xIncrement = dx / (float)steps; // x ����
//    float yIncrement = dy / (float)steps; // y ����
//
//    float x = x1; // ���� x ��ǥ
//    float y = y1; // ���� y ��ǥ
//
//    for (int i = 0; i <= steps; i++) {
//        linePixels.push_back({ (int)round(x), (int)round(y) }); // ���� ��ǥ ����
//        x += xIncrement; // x �� ����
//        y += yIncrement; // y �� ����
//    }
//}
//
//// ** �극���� �˰���(Bresenham's Line Algorithm)���� �ȼ� ��� **
//// ���� ���� ����� ȿ������ �� �׸��� �˰���
//void CalculateLinePixelsBresenham(int x1, int y1, int x2, int y2, std::vector<Pixel>& linePixels) {
//    int dx = abs(x2 - x1), dy = abs(y2 - y1); // x, y ��ȭ���� ���밪
//    int sx = (x1 < x2) ? 1 : -1; // x ���� ���� ����
//    int sy = (y1 < y2) ? 1 : -1; // y ���� ���� ����
//    int err = dx - dy;           // �ʱ� ���� ��
//
//    while (true) {
//        linePixels.push_back({ x1, y1 }); // ���� �ȼ� ��ǥ ����
//        if (x1 == x2 && y1 == y2) break; // ���� ����: ������ ����
//
//        int e2 = 2 * err; // ���� ���� ���� �� ��� Ȯ��
//        if (e2 > -dy) {   // x �������� �̵�
//            err -= dy;
//            x1 += sx;
//        }
//        if (e2 < dx) {    // y �������� �̵�
//            err += dx;
//            y1 += sy;
//        }
//    }
//}
//
//// ** ���� �ȼ� �׸��� **
//// ���� �ȼ� ��ǥ�� OpenGL�� �̿��� ȭ�鿡 �׸��� �Լ�
//void DrawLine(const std::vector<Pixel>& linePixels) {
//    for (const auto& pixel : linePixels) {
//        glBegin(GL_POINTS);          // �� �׸��� ����
//        glVertex2f(pixel.x, pixel.y); // �ȼ��� ��ǥ ����
//        glEnd();
//    }
//    glFinish(); // GPU �۾� �ϷḦ ����
//}
//
//// ** ���÷��� �Լ� **
//// OpenGL�� ������ �������� ȣ��Ǹ�, ��ü �ȼ��� ���� ������ ����ϰ� �׸��� �۾� ����
//void Display() {
//    int remainingPixels = totalPixels;          // ���� �� �ȼ� ��
//    float x1 = 0, y1 = 500, x2 = 500, y2 = 200; // ���� ���۰� �� ��ǥ
//    int currentLine = 0;
//    float g = 0.0, b = 0.0;                     // ���� �ʱ�ȭ
//
//    glColor3d(1.0, g, b); // �ʱ� ���� ���� (����)
//
//    auto start = std::chrono::high_resolution_clock::now(); // �ð� ���� ����
//
//    // ���� �ȼ��� �ִ� ���� ���� ������ �۾� �ݺ�
//    while (remainingPixels > 0) {
//        // ���� ������ y ��ǥ ���
//        float currentY1 = y1 - lineSpacing * currentLine;
//        float currentY2 = y2 - lineSpacing * currentLine;
//
//        // y ��ǥ�� 0 ���Ϸ� �������� ó�� ��ġ�� ���ư�
//        if (currentY1 < 0 || currentY2 < 0) {
//            currentLine = 0; // ù ��° �������� �ʱ�ȭ
//            g += 0.3;        // ���� ��ȭ
//            b += 0.3;
//
//            // ������ 1.0�� ���� �ʵ��� ����
//            if (g > 1.0) g = 0.0;
//            if (b > 1.0) b = 0.0;
//
//            glColor3d(1.0, g, b); // ���� ������Ʈ
//            continue;
//        }
//
//        // ���� ������ �ȼ� ��ǥ ���
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
//        // ���� �׸���
//        DrawLine(linePixels);
//
//        // ���� �ȼ� �� ����
//        remainingPixels -= linePixels.size();
//        currentLine++;
//    }
//
//    auto end = std::chrono::high_resolution_clock::now(); // �ð� ���� ����
//    std::chrono::duration<double> duration = end - start; // �� �ҿ� �ð� ���
//    std::cout << "����ð�: " << duration.count() << " seconds" << std::endl;
//}
//
//// ** ���� �Լ� **
//// ���α׷��� ����������, ����� �Է��� �޾� ��� ���� �� OpenGL �ʱ�ȭ �� ����
//int main(int argc, char** argv) {
//    // ����� �Է� �޾� ��� ����
//    std::cout << "��� ����:\n";
//    std::cout << "1: Linear Interpolation\n";
//    std::cout << "2: DDA\n";
//    std::cout << "3: Bresenham\n";
//    std::cin >> mode;
//
//    // �߸��� �Է� ó��
//    if (mode < 1 || mode > 3) {
//        std::cerr << "�߸��� �Է��Դϴ�.\n";
//        mode = 1;
//    }
//
//    // �� ���� �� ���
//    maxLines = (500 - 200) / lineSpacing + 1; // ���� �� ���
//
//    // OpenGL �ʱ�ȭ
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // ���� ����, RGB ���
//    glutInitWindowSize(640, 380);               // â ũ�� ����
//    glutCreateWindow("OpenGL Pixel Drawing");   // â ����
//    glClearColor(1.0, 1.0, 1.0, 1.0);           // ��� ���� ���� (���)
//    glOrtho(0.0, 500.0, 0.0, 500.0, -1.0, 1.0); // 2D orthographic projection ����
//
//    glutDisplayFunc(Display); // ���÷��� �ݹ� �Լ� ���
//    glutMainLoop();           // OpenGL �̺�Ʈ ���� ����
//    return 0;
//}
