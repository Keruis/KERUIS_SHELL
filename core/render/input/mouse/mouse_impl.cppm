module;

#include "../../../utils/attributes.h"

module ks.core.render.input:mouse_impl;

import :mouse;

namespace ks::core::render::input {

Mouse::Mouse(int screenWidth_, int screenHeight_) {
    screenWidth = screenWidth_;
    screenHeight = screenHeight_;
}

void Mouse::BindWindow(platform::IWindow* window_) {
    window = window_;
}

void Mouse::BindCursorController(platform::ICursorController* cursorController) {
    cursor_controller = cursorController;
}

bool Mouse::frame() KS_NOEXCEPT {
    bool result = cursor_controller->ReadMouseState();
    if (!result) {
        return false;
    }

    const auto cursorPos = cursor_controller->GetMouseStatePosition();
    position.x += cursorPos.x;
    position.y += cursorPos.y;

    current.buttons = cursor_controller->GetMouseStateButton();

    scroll_delta = cursor_controller->GetMouseStateScrollDelta();

    if (position.x < 0) position.x = 0;
    if (position.y < 0) position.y = 0;
    if (position.x > screenWidth) position.x = screenWidth;
    if (position.y > screenHeight) position.y = screenHeight;

    update();

    return true;
}

void Mouse::update() KS_NOEXCEPT {
    previous = current;

    last_position = position;

    scroll_delta = 0.f;
}

bool Mouse::isButtonDown(MouseButton button) KS_CONST KS_NOEXCEPT {
    return current.buttons[static_cast<int>(button)];
}

bool Mouse::isButtonPressed(MouseButton button) KS_CONST KS_NOEXCEPT {
    return current.buttons[static_cast<int>(button)] && !previous.buttons[static_cast<int>(button)];
}

bool Mouse::isButtonReleased(MouseButton button) KS_CONST KS_NOEXCEPT {
    return !current.buttons[static_cast<int>(button)] && previous.buttons[static_cast<int>(button)];
}

MousePosition Mouse::getPosition() KS_CONST KS_NOEXCEPT {
    return position;
}

MousePosition Mouse::getDelta() KS_CONST KS_NOEXCEPT {
    return MousePosition(position.x - last_position.x, position.y - last_position.y);
}

mouse_scroll_t Mouse::getScrollDelta() KS_CONST KS_NOEXCEPT {
    return scroll_delta;
}

void Mouse::setCursorMode(CursorMode mode) KS_NOEXCEPT {
    cursor_mode = mode;
    if (cursor_controller) {
        cursor_controller->SetCursorMode(mode);
    }
}

CursorMode Mouse::getCursorMode() KS_CONST KS_NOEXCEPT {
    return cursor_mode;
}

void Mouse::_onButtonDown(MouseButton button) KS_NOEXCEPT {
    current.buttons[static_cast<int>(button)] = true;
}

void Mouse::_onButtonUp(MouseButton button) KS_NOEXCEPT {
    current.buttons[static_cast<int>(button)] = false;
}

void Mouse::_onMove(mouse_coord_t x, mouse_coord_t y) KS_NOEXCEPT {
    position.x = x;
    position.y = y;
}

void Mouse::_onScroll(mouse_scroll_t delta) KS_NOEXCEPT {
    scroll_delta += delta;
}

bool Mouse::readMouse() KS_CONST KS_NOEXCEPT {
    return cursor_controller->ReadMouseState();
}


}