#pragma once

struct Point
{
  constexpr Point(float x = 0.0f, float y = 0.0f) noexcept : x(x), y(y) {}
  float x;
  float y;
};
