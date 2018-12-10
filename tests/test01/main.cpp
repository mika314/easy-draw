#include "easy_draw/easy_draw.hpp"
#include <iostream>

int main()
{
  onFrame([]() {
    if (isPressed(Keys::Space))
    {
      std::cout << "space\n";
    }
  });
  run();
}