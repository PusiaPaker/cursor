#include <string>
#include <unistd.h> 
#include <cstring> 
#include <stdlib.h>
#include <format>

#include "cursor.hpp"

namespace cur {
    Cursor cout;

    Cursor& Cursor::operator<<(std::string_view str) {
        c_strWrite(str.data());
        return *this;
    }

    Cursor& endl(Cursor& cur) {
        cur << "\n";
        return cur;
    }

    Cursor& clearStyle(Cursor& cur) {
        cur << CLEAR_STYLE;
        return cur;
    }

    void Cursor::c_strWrite(const char* c_str) const {
        write(STDOUT_FILENO, c_str, strlen(c_str));
    }

    Cursor& Cursor::move(int row, int col) {
        std::string str = std::format("\033[{};{}H", row, col);
        c_strWrite(str.c_str());
        return (*this);
    }

    Cursor& Cursor::clear() {
        const char* c_str = "\033[2J\0";
        c_strWrite(c_str);
        return (*this);
    }
}
