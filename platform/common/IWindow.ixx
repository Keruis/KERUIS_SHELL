export module ks.platform.common.IWindow;
#include <utility>

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
