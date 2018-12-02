#pragma once
#include "point.hpp"

struct Rect
{
  Rect(const Point &p1 = Point{}, const Point &p2 = Point{}) : p1(p1), p2(p2) {}
  Point p1;
  Point p2;
};
