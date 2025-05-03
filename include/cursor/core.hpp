#pragma once

#include <string>
#include <string_view>

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

        Cursor& operator<<(std::string_view);

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

}
