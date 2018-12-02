#pragma once
#include <cstdint>

enum class Color : uint32_t {
  Red = 0xff0000,
  Orange = 0xffa500,
  Yellow = 0xffff00,
  Green = 0x00ff00,
  Cyan = 0x00ffff,
  Blue = 0x0000ff,
  Indigo = 0x4b0082,
  Violet = 0xee82ee,
  Purple = 0xa020f0,
  Magenta = 0xff00ff,
  Pink = 0xffc0cb,
  Brown = 0xa52a2a,
  White = 0xffffff,
  Gray = 0x808080,
  Black = 0x000000
};

constexpr Color fromRgb(int r, int g, int b) noexcept
{
  return static_cast<Color>((r << 16) | (g << 8) | b);
}

constexpr int toRed(Color color) noexcept
{
  return static_cast<uint32_t>(color) >> 16;
}

constexpr int toGreen(Color color) noexcept
{
  return (static_cast<uint32_t>(color) >> 8) & 0xff;
}

constexpr int toBlue(Color color) noexcept
{
  return static_cast<uint32_t>(color) & 0xff;
}
