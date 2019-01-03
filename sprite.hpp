#pragma once
#include "point.hpp"
#include "texture.hpp"
#include <functional>
#include <string>

class Sprite
{
public:
  friend void run() noexcept;
  Sprite(const std::string &fileName);
  ~Sprite();
private:
  std::reference_wrapper<const Texture> texture;

public:
  bool isVisible = true;
  int width = 0;
  int height = 0;
  Point pos = {0, 0};
  float scale = 1.0f;
  float rotate = 0.0f;
  Point center = {0, 0};
};
