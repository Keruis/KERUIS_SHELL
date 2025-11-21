module;

#include <utility>

export module ks.platform.common.IWindow;

export namespace ks::platform {

struct WindowSize {
    int screenWidth;
    int screenHeight;
};

class IWindow {
public:
    virtual bool Init(void* windowHandle) = 0;

    virtual ~IWindow() = default;

    virtual WindowSize GetWindowSize() const = 0;
};

}
