#include "cursor/style.hpp"
#include "cursor/core.hpp"
#include <format>

namespace cur {
    Cursor& sendStyleCursorCode(Cursor& c, bool cond, int escCode, int resetCode) {
        int code = cond ? escCode : resetCode;
        std::string str = std::format("\033[{}m", code);
        c << str.c_str();
        return c;
    }

    Cursor& applyCursorVisibility(Cursor& c, bool cond) {
        char chr = cond ? 'h' : 'l';
        std::string str = std::format("\033[?25{}", chr);
        c << str.c_str();
        return c;
    }
}