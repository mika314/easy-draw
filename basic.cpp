#include "basic.hpp"
#include <chrono>
#include <sdlpp/sdlpp.hpp>

namespace
{
  sdl::Init init{SDL_INIT_EVERYTHING};
  sdl::Window win{"Basic", 64, 100, ScreenWidth, ScreenHeight, 0};
  sdl::Renderer rend{win.get(), -1, SDL_RENDERER_TARGETTEXTURE};
  sdl::Texture texture{rend.get(),
                       SDL_PIXELFORMAT_RGB24,
                       SDL_TEXTUREACCESS_TARGET,
                       ScreenWidth,
                       ScreenHeight};
  std::function<void(Point)> mouseLeftCb;
  std::function<void(Point)> mouseRightCb;
  std::function<void(Point)> mouseMoveCb;
  std::function<void(Point)> mouseMoveLeftCb;
  std::function<void(Point)> mouseMoveRightCb;
  std::function<void()> frameCb;
  std::chrono::high_resolution_clock::time_point drawTime{
    std::chrono::high_resolution_clock::now()};

  constexpr void lock() noexcept {}
  void unlock() noexcept
  {
    const auto now = std::chrono::high_resolution_clock::now();
    if (now > drawTime)
    {
      rend.setTarget(nullptr);
      rend.copy(texture.get(), nullptr, nullptr);
      rend.present();
      rend.setTarget(texture.get());
    }
    using namespace std::chrono_literals;
    while (now > drawTime)
      drawTime += 16667us;
  }

  struct FinalInit
  {
    FinalInit()
    {
      rend.setTarget(texture.get());
      rend.setDrawBlendMode(SDL_BLENDMODE_BLEND);
    }
  } finalInit;

  class Locker
  {
  public:
    Locker() noexcept { lock(); }
    ~Locker() noexcept { unlock(); }
  };
} // namespace

void run() noexcept
{
  rend.setTarget(nullptr);
  sdl::EventHandler ev;
  auto done = false;
  ev.quit = [&done](const SDL_QuitEvent &) { done = true; };
  ev.mouseButtonDown = [](const SDL_MouseButtonEvent &e) {
    Locker l;
    switch (e.button)
    {
    case SDL_BUTTON_LEFT:
      if (mouseLeftCb)
        mouseLeftCb(Point{1.0f * e.x, 1.0f * e.y});
      break;
    case SDL_BUTTON_RIGHT:
      if (mouseRightCb)
        mouseRightCb(Point{1.0f * e.x, 1.0f * e.y});
      break;
    }
  };
  ev.mouseMotion = [](const SDL_MouseMotionEvent &e) {
    Locker l;
    if (e.state == 0 && mouseMoveCb)
      mouseMoveCb(Point{1.0f * e.x, 1.0f * e.y});
    if ((e.state & SDL_BUTTON_LMASK) != 0 && mouseMoveLeftCb)
      mouseMoveLeftCb(Point{1.0f * e.x, 1.0f * e.y});
    if ((e.state & SDL_BUTTON_RMASK) != 0 && mouseMoveRightCb)
      mouseMoveRightCb(Point{1.0f * e.x, 1.0f * e.y});
  };
  auto frameTime = std::chrono::high_resolution_clock::now();
  using namespace std::chrono_literals;
  while (!done)
  {
    rend.setTarget(texture.get());
    auto now = std::chrono::high_resolution_clock::now();
    while (ev.poll())
      ;
    while (frameTime <= now)
    {
      frameTime += 16667us;
      if (frameCb)
        frameCb();
    }
    rend.setTarget(nullptr);
    rend.copy(texture.get(), nullptr, nullptr);
    rend.present();
  }
}

void clear(Color color) noexcept
{
  rend.setDrawColor(toRed(color), toGreen(color), toBlue(color), 0xff);
  rend.clear();
}

void line(const Point &p1, const Point &p2, Color color, int alpha) noexcept
{
  Locker l;
  rend.setDrawColor(toRed(color), toGreen(color), toBlue(color), alpha);
  rend.drawLine(p1.x, p1.y, p2.x, p2.y);
}

void point(const Point &p, Color color, int alpha) noexcept
{
  Locker l;
  rend.setDrawColor(toRed(color), toGreen(color), toBlue(color), alpha);
  rend.drawPoint(p.x, p.y);
}

void rect(const Rect &rect, Color color, int alpha) noexcept
{
  Locker l;
  rend.setDrawColor(toRed(color), toGreen(color), toBlue(color), alpha);
  SDL_Rect r;
  r.x = rect.p1.x;
  r.y = rect.p1.y;
  r.w = rect.p2.x - rect.p1.x;
  r.h = rect.p2.y - rect.p1.y;
  rend.drawRect(&r);
}

void fillRect(const Rect &rect, Color color, int alpha) noexcept
{
  Locker l;
  rend.setDrawColor(toRed(color), toGreen(color), toBlue(color), alpha);
  SDL_Rect r;
  r.x = rect.p1.x;
  r.y = rect.p1.y;
  r.w = rect.p2.x - rect.p1.x;
  r.h = rect.p2.y - rect.p1.y;
  rend.fillRect(&r);
}

void onMouseLeft(std::function<void(Point)> cb) noexcept
{
  mouseLeftCb = std::move(cb);
}

void onMouseRight(std::function<void(Point)> cb) noexcept
{
  mouseRightCb = std::move(cb);
}

void onMouseMove(std::function<void(Point)> cb) noexcept
{
  mouseMoveCb = std::move(cb);
}

void onMouseMoveLeft(std::function<void(Point)> cb) noexcept
{
  mouseMoveLeftCb = std::move(cb);
}

void onMouseMoveRight(std::function<void(Point)> cb) noexcept
{
  mouseMoveRightCb = std::move(cb);
}

void onFrame(std::function<void()> cb) noexcept
{
  frameCb = std::move(cb);
}
