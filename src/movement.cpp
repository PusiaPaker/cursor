#include "cursor/movement.hpp"
#include "cursor/core.hpp"

namespace cur {
    Cursor& applyMove(Cursor& c, int row, int col) {
        char buf[32];
        int len = std::snprintf(buf, sizeof(buf), "\033[%d;%dH", row, col);
        c << buf;
        return c;
    }

    Cursor& applyMove(Cursor& c, Direction o, int distance) {
        char chr;
            switch(o) {
                case Direction::up:
                    chr = 'A';
                    break;
                case Direction::down:
                    chr = 'B';
                    break;
                case Direction::left:
                    chr = 'C';
                    break;
                case Direction::right:
                    chr = 'D';
                    break;
            
            }
            char buf[32];
            int len = std::snprintf(buf, sizeof(buf), "\033[%d%c", distance, chr);
            c << buf;
            return c;
    }
}