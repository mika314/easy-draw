#include "easy_draw/easy_draw.hpp"

int main()
{
  img("img.bmp", {100.0f, 100.0f}, 2.0f, 45.0f, {128.0f, 128.0f});
  fillRect({{98.0f + 128.0f, 98.0f + 128.0f}, {102.0f + 128.0f, 102.0f + 128.0f}}, Color::Blue);
  run();
}
