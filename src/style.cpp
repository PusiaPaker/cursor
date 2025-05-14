#include "cursor/style.hpp"
#include "cursor/core.hpp"

namespace cur {
    Cursor& sendStyleCursorCode(Cursor& c, bool cond, int escCode, int resetCode) {
        int code = cond ? escCode : resetCode;
        char buf[32];
        int len = std::snprintf(buf, sizeof(buf), "\033[%dm", code);
        c << buf;
        return c;
    }

    Cursor& applyCursorVisibility(Cursor& c, bool cond) {
        char chr = cond ? 'h' : 'l';
        char buf[16];
        int len = std::snprintf(buf, sizeof(buf), "\033[?25%c", chr);
        c << buf;
        return c;
    }
}