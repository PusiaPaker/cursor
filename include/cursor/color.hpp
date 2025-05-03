#pragma once

namespace cur {
    class Cursor;

    enum class ColorMode { Background, Foreground };

    Cursor& applyColor(Cursor& c, ColorMode mode, int r, int g, int b);

    inline auto backgroundColor(int r, int g, int b) {
        return [=](Cursor& c) -> Cursor& {
            return applyColor(c, ColorMode::Background, r, g, b);
        };
    }

    inline auto foregroundColor(int r, int g, int b) {
        return [=](Cursor& c) -> Cursor& {
            return applyColor(c, ColorMode::Foreground, r, g, b);
        };
    }

}