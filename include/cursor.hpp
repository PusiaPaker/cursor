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
}