#include <GL/glut.h>
#include <vector>
#include <chrono>
#include <iostream>
#include <iomanip>
#include <cmath>

int windowWidth = 1500;
int windowHeight = 800;
int numLines = 1000;
int totalPixels = 100000000;

struct Point {
    float x, y;
    Point(float _x, float _y) : x(_x), y(_y) {}
};

// 각 알고리즘별로 선 데이터를 저장할 구조
struct LineData {
    std::vector<Point> points;
    float executionTime;
    std::string algorithmName;

    LineData(const std::string& name) : executionTime(0.0f), algorithmName(name) {}
};

std::vector<LineData> algorithms = {
    LineData("Linear Interpolation"),
    LineData("DDA"),
    LineData("Bresenham")
};

// 선형 보간 방식
void DrawLinearInterpolation(LineData& data, int targetPixels) {
    auto startTime = std::chrono::high_resolution_clock::now();

    for (int line = 0; line < numLines; ++line) {
        float startX = line * (windowWidth / static_cast<float>(numLines));
        float startY = 0;
        float endX = 0;
        float endY = line * (windowHeight / static_cast<float>(numLines));

        int steps = targetPixels / numLines;
        for (int i = 0; i <= steps; ++i) {
            float t = static_cast<float>(i) / steps;
            float x = startX + t * (endX - startX);
            float y = startY + t * (endY - startY);
            data.points.emplace_back(x, y);
        }
    }

    auto endTime = std::chrono::high_resolution_clock::now();
    data.executionTime = std::chrono::duration<float>(endTime - startTime).count();
}

// DDA 방식
void DrawDDA(LineData& data, int targetPixels) {
    auto startTime = std::chrono::high_resolution_clock::now();

    for (int line = 0; line < numLines; ++line) {
        float startX = line * (windowWidth / static_cast<float>(numLines));
        float startY = 0;
        float endX = 0;
        float endY = line * (windowHeight / static_cast<float>(numLines));

        float dx = endX - startX;
        float dy = endY - startY;
        float steps = std::max(std::abs(dx), std::abs(dy));

        float xIncrement = dx / steps;
        float yIncrement = dy / steps;

        float x = startX;
        float y = startY;

        for (int i = 0; i <= steps; ++i) {
            data.points.emplace_back(x, y);
            x += xIncrement;
            y += yIncrement;
        }
    }

    auto endTime = std::chrono::high_resolution_clock::now();
    data.executionTime = std::chrono::duration<float>(endTime - startTime).count();
}

// Bresenham 방식
void DrawBresenham(LineData& data, int targetPixels) {
    auto startTime = std::chrono::high_resolution_clock::now();

    for (int line = 0; line < numLines; ++line) {
        int startX = line * (windowWidth / numLines);
        int startY = 0;
        int endX = 0;
        int endY = line * (windowHeight / numLines);

        int dx = std::abs(endX - startX);
        int dy = std::abs(endY - startY);
        int sx = (startX < endX) ? 1 : -1;
        int sy = (startY < endY) ? 1 : -1;
        int err = dx - dy;

        while (true) {
            data.points.emplace_back(startX, startY);

            if (startX == endX && startY == endY) break;

            int e2 = 2 * err;
            if (e2 > -dy) {
                err -= dy;
                startX += sx;
            }
            if (e2 < dx) {
                err += dx;
                startY += sy;
            }
        }
    }

    auto endTime = std::chrono::high_resolution_clock::now();
    data.executionTime = std::chrono::duration<float>(endTime - startTime).count();
}

void RenderScene() {
    glClear(GL_COLOR_BUFFER_BIT);

    // 각 알고리즘의 결과를 다른 색상으로 표시
    const float colors[][3] = {
        {1.0f, 0.0f, 0.0f}, // 빨강 - 선형 보간
        {0.0f, 1.0f, 0.0f}, // 초록 - DDA
        {0.0f, 0.0f, 1.0f}  // 파랑 - Bresenham
    };

    for (size_t i = 0; i < algorithms.size(); ++i) {
        glColor3fv(colors[i]);
        glBegin(GL_LINES);
        for (size_t j = 1; j < algorithms[i].points.size(); j += 2) {
            glVertex2f(algorithms[i].points[j - 1].x, algorithms[i].points[j - 1].y);
            glVertex2f(algorithms[i].points[j].x, algorithms[i].points[j].y);
        }
        glEnd();
    }

    glutSwapBuffers();

    // 결과 출력
    std::cout << "\n====================\n";
    std::cout << "Performance Results:\n";
    std::cout << totalPixels << "pxel\n";
    for (const auto& algorithm : algorithms) {
        std::cout << algorithm.algorithmName << " 실행 시간: "
            << std::fixed << std::setprecision(6) << algorithm.executionTime << "초\n";
    }
    std::cout << "====================\n";
}

void Init() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, windowWidth, 0.0, windowHeight);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(windowWidth, windowHeight);
    glutCreateWindow("Line Drawing Algorithms Comparison");

    Init();

    // 각 알고리즘 실행
    DrawLinearInterpolation(algorithms[0], totalPixels / 3);
    DrawDDA(algorithms[1], totalPixels / 3);
    DrawBresenham(algorithms[2], totalPixels / 3);

    glutDisplayFunc(RenderScene);
    glutMainLoop();

    return 0;
}