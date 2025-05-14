#include "cursor/color.hpp"
#include "cursor/core.hpp"

namespace cur {
    Cursor& applyColor(Cursor& c, ColorMode mode, int r, int g, int b){
        int code = (mode == ColorMode::Background) ? 48 : 38;
        r = r % 256;
        g = g % 256;
        b = b % 256;
        char buf[32];
        int len = std::snprintf(buf, sizeof(buf), "\033[%d;2;%d;%d;%dm", code, r, g, b);
        c << buf;
        return c;
    }
}