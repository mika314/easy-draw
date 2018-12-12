#pragma once
#include "color.hpp"
#include "consts.hpp"
#include "keys.hpp"
#include "point.hpp"
#include "rect.hpp"
#include <functional>
#include <string>

void run() noexcept;

void clear(Color) noexcept;
void line(const Point &p1, const Point &p2, Color, int alpha = 0xff) noexcept;
void point(const Point &, Color, int alpha = 0xff) noexcept;
void rect(const Rect &, Color, int alpha = 0xff) noexcept;
void fillRect(const Rect &, Color, int alpha = 0xff) noexcept;
void img(const std::string &fileName,
         const Point &,
         float scale = 1.0f,
         float rotate = 0.0f,
         const Point & = {0, 0}) noexcept(false);

void onMouseLeft(std::function<void(Point)>) noexcept;
void onMouseRight(std::function<void(Point)>) noexcept;
void onMouseMove(std::function<void(Point)>) noexcept;
void onMouseMoveLeft(std::function<void(Point)>) noexcept;
void onMouseMoveRight(std::function<void(Point)>) noexcept;
void onFrame(std::function<void()>) noexcept;
bool isPressed(Keys) noexcept;
