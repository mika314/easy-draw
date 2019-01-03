#pragma once
#include <memory>
#include <sdlpp/sdlpp.hpp>

struct Texture
{
private:
  std::unique_ptr<sdl::Surface> tmpSurf;

public:
  Texture(const std::string &fileName) noexcept(false);
  sdl::Texture texture;
  int width;
  int height;
};
