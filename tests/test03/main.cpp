#include <easy_draw/easy_draw.hpp>

int main()
{
  Sprite s("sprite.bmp");
  s.rotate = 45;

  Turtle t;

  t.d();
  for (int j = 0; j < 360 / 5; ++j)
  {
    for (int i = 0; i < 4; ++i)
    {
      t.f(200);
      t.r(90);
    }
    t.r(5);
  }

  run();
}
