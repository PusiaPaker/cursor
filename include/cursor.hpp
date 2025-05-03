#pragma once

#include <string>
#include <format>


#define CLEAR_STYLE "\033[0m"
#define CLEAR_SCREEN "\033[2J"

namespace cur {
    class Cursor;

    extern Cursor cout;
    Cursor& endl(Cursor&);
    Cursor& clearStyle(Cursor&);

    class Cursor {
    public:
        Cursor& move(int col, int row);
        Cursor& clear();

        Cursor& operator<<( std::string_view);
        template <typename F>
        Cursor& operator<<(F func) requires requires(Cursor& c) { func(c); } {
            return func(*this);
        }
        template <typename T>
        Cursor& operator<<(T val) requires std::is_arithmetic_v<T> {
            std::string str = std::to_string(val);
            c_strWrite(str.c_str());
            return *this;
        }

    private:
        void c_strWrite(const char*) const;
    };


    inline auto move(int col, int row) {
        return [=](Cursor& c) -> Cursor& {
            std::string str = std::format("\033[{};{}H", row, col);
            c << str.c_str();
            return c;
        };
    }

    enum class Direction { up, down, left, right };
    inline auto move(Direction o, int distance) {
        return [=](Cursor& c) -> Cursor& {
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
        };
    }

    enum class ColorMode { Background, Foreground };

    inline auto color(ColorMode mode, int r, int g, int b) {
        return [=](Cursor& c) -> Cursor& {
            int code = (mode == ColorMode::Background) ? 48 : 38;
            std::string str = std::format("\033[{};2;{};{};{}m", code, r, g, b);
            c << str.c_str();
            return c;
        };
    }

    inline auto backgroundColor(int r, int g, int b) {
        return color(ColorMode::Background, r, g, b);
    }

    inline auto foregroundColor(int r, int g, int b) {
        return color(ColorMode::Foreground, r, g, b);
    }

    Cursor& sendStyleCursorCode(Cursor& c, bool cond, int escCode, int resetCode);

    inline auto setBold(bool opt) {
        return [=](Cursor& c) -> Cursor& {
            return sendStyleCursorCode(c, opt, 1, 22);
        };
    }

    inline auto setFaint(bool opt) {
        return [=](Cursor& c) -> Cursor& {
            return sendStyleCursorCode(c, opt, 2, 22);
        };
    }

    inline auto setItalic(bool opt) {
        return [=](Cursor& c) -> Cursor& {
            return sendStyleCursorCode(c, opt, 3, 23);
        };
    }

    inline auto setUnderline(bool opt) {
        return [=](Cursor& c) -> Cursor& {
            return sendStyleCursorCode(c, opt, 4, 24);
        };
    }

    inline auto setBlinking(bool opt) {
        return [=](Cursor& c) -> Cursor& {
            return sendStyleCursorCode(c, opt, 5, 25);
        };
    }

    inline auto setInverse(bool opt) {
        return [=](Cursor& c) -> Cursor& {
            return sendStyleCursorCode(c, opt, 7, 27);
        };
    }

    inline auto setHidden(bool opt) {
        return [=](Cursor& c) -> Cursor& {
            return sendStyleCursorCode(c, opt, 8, 28);
        };
    }

    inline auto setStrikethrough (bool opt) {
        return [=](Cursor& c) -> Cursor& {
            return sendStyleCursorCode(c, opt, 9, 29);
        };
    }

    inline auto setCursorVisibility(bool opt) {
        return [=](Cursor& c) -> Cursor& {
            char chr = opt ? 'h' : 'l';
            std::string str = std::format("\033[?25{}", chr);
            c << str.c_str();
            return c;
        };
    }

    
}