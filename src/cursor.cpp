#include <string>
#include <unistd.h> 
#include <cstring> 
#include <stdlib.h>
#include <format>

#include "cursor.hpp"

#if _WIN32 

#include <windows.h>
#include <iostream>

#endif

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
        #ifdef _WIN32
            if (GetConsoleOutputCP() != CP_UTF8) {
                std::cerr << "Error: console is not in UTF-8 mode.\nInclude SetConsoleOutputCP(CP_UTF8); in your main";
                exit(0);
            }
        #endif
        write(STDOUT_FILENO, c_str, strlen(c_str));
    }

    Cursor& Cursor::move(int row, int col) {
        std::string str = std::format("\033[{};{}H", row, col);
        c_strWrite(str.c_str());
        return (*this);
    }

    Cursor& Cursor::clear() {
        const char* c_str = CLEAR_SCREEN;
        c_strWrite(c_str);
        return (*this);
    }

    Cursor& sendStyleCursorCode(Cursor& c, bool cond, int escCode, int resetCode) {
        int code = cond ? escCode : resetCode;
        std::string str = std::format("\033[{}m", code);
        c << str.c_str();
        return c;
    }
}
