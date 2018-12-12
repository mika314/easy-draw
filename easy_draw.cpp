#include "easy_draw.hpp"
#include <cassert>
#include <chrono>
#include <memory>
#include <sdlpp/sdlpp.hpp>

namespace
{
  sdl::Init init{SDL_INIT_EVERYTHING};
  sdl::Window win{"Easy Draw", 64, 100, Width, Height, 0};
  sdl::Renderer rend{win.get(), -1, SDL_RENDERER_TARGETTEXTURE};
  sdl::Texture texture{rend.get(), SDL_PIXELFORMAT_RGB24, SDL_TEXTUREACCESS_TARGET, Width, Height};
  std::function<void(Point)> mouseLeftCb;
  std::function<void(Point)> mouseRightCb;
  std::function<void(Point)> mouseMoveCb;
  std::function<void(Point)> mouseMoveLeftCb;
  std::function<void(Point)> mouseMoveRightCb;
  std::function<void()> frameCb;
  std::chrono::high_resolution_clock::time_point drawTime{
    std::chrono::high_resolution_clock::now()};
  std::vector<bool> keys;

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

  void setKey(Keys value)
  {
    if (static_cast<size_t>(value) >= keys.size())
      keys.resize(static_cast<size_t>(value) + 1);
    keys[static_cast<size_t>(value)] = true;
  }
  void resetKey(Keys value)
  {
    if (static_cast<size_t>(value) >= keys.size())
      return;
    keys[static_cast<size_t>(value)] = false;
  }
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
  ev.keyDown = [](const SDL_KeyboardEvent &e) {
    switch (e.keysym.sym)
    {
    case SDLK_LEFT: setKey(Keys::Left); break;
    case SDLK_RIGHT: setKey(Keys::Right); break;
    case SDLK_UP: setKey(Keys::Up); break;
    case SDLK_DOWN: setKey(Keys::Down); break;
    case SDLK_RETURN: setKey(Keys::Enter); break;
    case SDLK_SPACE: setKey(Keys::Space); break;
    }
  };
  ev.keyUp = [](const SDL_KeyboardEvent &e) {
    switch (e.keysym.sym)
    {
    case SDLK_LEFT: resetKey(Keys::Left); break;
    case SDLK_RIGHT: resetKey(Keys::Right); break;
    case SDLK_UP: resetKey(Keys::Up); break;
    case SDLK_DOWN: resetKey(Keys::Down); break;
    case SDLK_RETURN: resetKey(Keys::Enter); break;
    case SDLK_SPACE: resetKey(Keys::Space); break;
    }
  };
  auto frameTime = std::chrono::high_resolution_clock::now();
  using namespace std::chrono_literals;
  while (!done)
  {
    rend.setTarget(texture.get());
    auto now = std::chrono::high_resolution_clock::now();
    if (now < frameTime)
    {
      try
      {
        ev.wait(std::chrono::duration_cast<std::chrono::milliseconds>(frameTime - now).count());
      }
      catch (...)
      {
      }
    }
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
    now = std::chrono::high_resolution_clock::now();
    using namespace std::chrono_literals;
    drawTime = now + 16667us;
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

namespace
{
  struct Texture
  {
  private:
    std::unique_ptr<sdl::Surface> tmpSurf;

  public:
    Texture(const std::string &fileName) noexcept(false)
      : tmpSurf(std::make_unique<sdl::Surface>(fileName)),
        texture(rend.get(), tmpSurf.get()->get()),
        width(tmpSurf.get()->get()->w),
        height(tmpSurf.get()->get()->h)
    {
      tmpSurf = nullptr;
    }
    sdl::Texture texture;
    int width;
    int height;
  };
  std::unordered_map<std::string, Texture> texLib;
  const Texture &loadTexture(const std::string &fileName) noexcept(false)
  {
    auto iter = texLib.find(fileName);
    if (iter != std::end(texLib))
      return iter->second;
    bool tmp;
    std::tie(iter, tmp) = texLib.emplace(fileName, Texture{fileName});
    assert(tmp);
    return iter->second;
  }
} // namespace

void img(const std::string &fileName,
         const Point &dest,
         float scale,
         float rotate,
         const Point &center) noexcept(false)
{
  Locker l;
  auto &tex = loadTexture(fileName);
  const SDL_Rect sdlDest{static_cast<int>(dest.x),
                         static_cast<int>(dest.y),
                         static_cast<int>(tex.width * scale),
                         static_cast<int>(tex.height * scale)};
  const SDL_Point sdlCenter{static_cast<int>(center.x), static_cast<int>(center.y)};
  rend.copyEx(const_cast<SDL_Texture *>(tex.texture.get()),
              nullptr,
              &sdlDest,
              rotate,
              &sdlCenter,
              SDL_FLIP_NONE);
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

bool isPressed(Keys value) noexcept
{
  if (static_cast<size_t>(value) >= keys.size())
    return false;
  return keys[static_cast<size_t>(value)];
}
