#include "turtle.hpp"
#include "easy_draw.hpp"

Turtle::Turtle() : sprite("turtle")
{
  sprite.pos = {pos.x - sprite.width / 2, pos.y - sprite.height / 2};
  sprite.rotate = -rotate;
}

void Turtle::down() noexcept
{
  isDown = true;
  point(pos, color);
}

void Turtle::forward(float value) noexcept
{
  auto old = pos;
  pos.x = old.x + value * cos((rotate - 90.0f) / 360.0f * 2.0f * 3.1415926f);
  pos.y = old.y + value * sin((rotate - 90.0f) / 360.0f * 2.0f * 3.1415926f);
  sprite.pos = {pos.x - sprite.width / 2, pos.y - sprite.height / 2};
  if (isDown)
    line(old, pos, color);
}

void Turtle::back(float value) noexcept
{
  forward(-value);
}
