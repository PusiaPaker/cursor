#pragma once

#include <string>

namespace cur {
    class Cursor;

    extern Cursor cout;
    Cursor& endl(Cursor&);

    class Cursor {
    public:
        void move(int col, int row) const;
        void clear() const;

        Cursor& operator<<( std::string_view);
        Cursor& operator<<(Cursor& (*)(Cursor&));
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