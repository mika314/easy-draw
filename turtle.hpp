#pragma once
#include "color.hpp"
#include "consts.hpp"
#include "point.hpp"
#include "sprite.hpp"

class Turtle
{
public:
  Turtle();
  constexpr void hide() noexcept { sprite.isVisible = false; }
  constexpr void show() noexcept { sprite.isVisible = true; }
  constexpr void up() noexcept { isDown = false; }
  void down() noexcept;
  constexpr void left(float value) noexcept
  {
    rotate -= value;
    sprite.rotate = rotate;
  }
  constexpr void right(float value) noexcept
  {
    rotate += value;
    sprite.rotate = rotate;
  }
  void forward(float) noexcept;
  void back(float) noexcept;
  constexpr void setColor(Color value) noexcept { color = value; }

  void u() noexcept { up(); }
  void d() noexcept { down(); }
  void l(float value) noexcept { left(value); }
  void r(float value) noexcept { right(value); }
  void f(float value) noexcept { forward(value); }
  void b(float value) noexcept { back(value); }

private:
  Sprite sprite;
  bool isDown = true;
  Point pos = {Width / 2, Height / 2};
  float rotate = 0;
  Color color = Color::White;
};
