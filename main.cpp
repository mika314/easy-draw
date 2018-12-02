#include "basic.hpp"
#include <chrono>
#include <cmath>
#include <cstdlib>
#include <thread>
#include <utility>

using Velosity = Point;
struct P
{
  constexpr P(const Point &p, const Velosity &v, Color c) noexcept : p(p), v(v), c(c) {}
  Point p;
  Velosity v;
  Color c;
};

int main()
{
  std::vector<P> points;
  onMouseLeft([&points](Point p) {
    point(p, Color::White);
    for (int i = 0; i < 100; ++i)
      points.emplace_back(p,
                          Velosity{rand() % 100 / 100.0f - 0.5f, rand() % 100 / 100.0f - 0.5f},
                          fromRgb(rand() % 0x100, rand() % 0x100, rand() % 0x100));
  });
  int c = 0;
  onFrame([&c, &points]() {
    fillRect({{0, 0}, {ScreenWidth, ScreenHeight}}, Color::Black, 0x40);
    for (auto &p : points)
    {
      fillRect({{p.p.x - 2, p.p.y - 2}, {p.p.x + 2, p.p.y + 2}}, p.c);
      p.p.x += p.v.x;
      p.p.y += p.v.y;
      p.v.y += 0.001f;
    }
    points.erase(std::remove_if(std::begin(points),
                                std::end(points),
                                [](const P &p) { return p.p.y > ScreenHeight || p.p.y < 0; }),
                 std::end(points));

    if (c++ % 20 == 0)
    {
      for (int i = 0; i < 36; ++i)
        points.emplace_back(
          Point{ScreenWidth / 2, ScreenHeight / 2},
          Velosity{cosf(i * 2 * 3.1415926f / 36), sinf(i * 2 * 3.1415926f / 36) - 1.0f},
          fromRgb(rand() % 0x100, rand() % 0x100, rand() % 0x100));
    }
  });
  run();
}
