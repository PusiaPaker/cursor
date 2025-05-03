#include "cursor/movement.hpp"
#include "cursor/core.hpp"

#include <format>

namespace cur {
    Cursor& applyMove(Cursor& c, int col, int row) {
        std::string str = std::format("\033[{};{}H", row, col);
        c << str.c_str();
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
            std::string str = std::format("\033[{}{}", distance, chr);
            c << str.c_str();
            return c;
    }
}