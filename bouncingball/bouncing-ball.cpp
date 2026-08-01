#include "raylib.h"
#include <Eigen/Dense>

int main() {
    InitWindow(800, 600, "bouncing ball");
    SetTargetFPS(17);

    Eigen::Vector2f pos(100.0f, 100.0f);
    Eigen::Vector2f vel(300.0f, 0.0f);
    Eigen::Vector2f grav(0.0f, 600.0f);

    const float radius = 25.0f;
    const float bounce = 0.85f;

    while (!WindowShouldClose()) {
        float dt = GetFrameTime();

        vel += grav * dt;
        pos += vel * dt;

        if (pos.y() > (600 - radius)) {
            pos.y() = 600 - radius;
            vel.y() = -vel.y() * bounce;
        }
        if (pos.x() > (800 - radius)) {
            pos.x() = 800 - radius;
            vel.x() = -vel.x() * bounce;
        }
        else if (pos.x() < radius) {
            pos.x() = radius;
            vel.x() = -vel.x() * bounce;
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText(TextFormat("oX: %.1f  oY: %.1f", pos.x(), pos.y()), 20, 50, 20, GRAY);
        DrawCircle((int)pos.x(), (int)pos.y(), radius, MAROON);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
