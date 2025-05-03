#include "cursor/color.hpp"
#include "cursor/core.hpp"
#include <format>

namespace cur {
    Cursor& applyColor(Cursor& c, ColorMode mode, int r, int g, int b){
        int code = (mode == ColorMode::Background) ? 48 : 38;
        std::string str = std::format("\033[{};2;{};{};{}m", code, r, g, b);
        c << str.c_str();
        return c;
    }
}