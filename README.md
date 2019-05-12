# easy-draw
Simple drawing library based on SDL2, useful for quick hacking or fun studying C++

# Quick Example

```c++
#include <easy_draw/easy_draw.hpp>

int main(int, char**)
{
  line({100, 100}, {200, 200}, Color::White);
  run();
  return 0;
}
```

This sample will draw white diagonal line on black background.

# API

## void run() noexcept;
This function starts event processing infinite loop. From this point your application will start process mouse and keyboard inputs.

## void clear(Color c) noexcept;
This function clears the screen with given color ```c```.

### Example:
```C++
clear(Color::Blue);
```

## void line(const Point &p1, const Point &p2, Color c, int alpha = 0xff) noexcept;
This function draws line from point ```p1``` to point ```p2``` with color ```c``` and optional transperancy ```alpha```.
Alpha 0 means line is fully transparent.

### Example:
```C++
line({100, 100}, {200, 200}, Color::White);
```

## void point(const Point &p, Color c, int alpha = 0xff) noexcept;
This function draws point on coordinates ```p``` with color ```c``` and optional transparency alpha.
Alpha 0 means point is fully transparent.

### Example:
```C++
point({300, 300}, Color::Green);
```

## void rect(const Rect &r, Color c, int alpha = 0xff) noexcept;
This function draws rectangle with rectangle corners specified in ```r```, color ```c``` and optional transparancy ```alpha```.
Alpha 0 means rectangle is fully transparent.

### Example:
```C++
rect({{300, 300}, {500, 400}}, Color::Green);
```

## void fillRect(const Rect &, Color, int alpha = 0xff) noexcept;
This function draws filled rectangle with rectangle corners specified in ```r```, color ```c``` and optional transparancy ```alpha```.
Alpha 0 means rectangle is fully transparent.

### Example:
```C++
fillRect({{300, 300}, {500, 400}}, Color::Green);
```

## void img(const std::string &fileName, const Point &p, float scale = 1.0f, float rotate = 0.0f, const Point & rotatePoint = {0, 0}) noexcept(false);
This function draws image from file specified in ```fileName``` at the point ```p``` with optional parameters ```scale```,
rotation ```rotate``` and ```rotatePoint```.

Supported formats: bmp.

### Example:
```C++
img("img.bmp", {100, 100});
```

## void onMouseLeft(std::function<void(Point)> cb) noexcept;
This function registers callback ```cb``` on left mouse clicks.

### Example:
```C++
onMouseLeft([](Point p) {
  point(p, Color::White);
});
```

## void onMouseRight(std::function<void(Point)>) noexcept;
This function registers callback ```cb``` on right mouse clicks.

### Example:
```C++
onMouseRight([](Point p) {
  point(p, Color::White);
});
```

## void onMouseMove(std::function<void(Point)>) noexcept;
This function registers callback ```cb``` on mouse movements.

### Example:
```C++
onMouseMove([](Point p) {
  point(p, Color::White);
});
```

## void onMouseMoveLeft(std::function<void(Point)>) noexcept;
This function registers callback ```cb``` on mouse movements while left button is pressed.

### Example:
```C++
onMouseMoveLeft([](Point p) {
  point(p, Color::White);
});
```

## void onMouseMoveRight(std::function<void(Point)>) noexcept;
This function registers callback ```cb``` on mouse movements while right button is pressed.

### Example:
```C++
onMouseMoveRight([](Point p) {
  point(p, Color::White);
});
```

## void onFrame(std::function<void()>) noexcept;
This function registers callback ```cb``` on every frame update.

### Example:
```C++
onFrame([](Point p) {
  point({rand() % 300, rand() % 300}, Color::White);
});
```

## bool isPressed(Keys k) noexcept;
This function returns true if key ```k``` is pressed, false if key ```k``` is not pressed.

```C++
if (isPressed(Keys::Space))
  std::cout << "Space is pressed\n";
```
