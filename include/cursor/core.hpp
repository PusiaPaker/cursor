#pragma once

#include <string>
#include <string_view>

inline constexpr const char* CLEAR_STYLE = "\033[0m";
inline constexpr const char* CLEAR_SCREEN = "\033[2J";

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
        std::enable_if_t<
            std::is_invocable_r_v<Cursor&, F, Cursor&> &&
            !std::is_arithmetic_v<F>, Cursor&>
        operator<<(F func) {
            return func(*this);
        }
        
        template <typename T>
        std::enable_if_t<std::is_arithmetic<T>::value, Cursor&>
        operator<<(T val) {
            std::string str = std::to_string(val);
            c_strWrite(str.c_str());
            return *this;
        }

    private:
        void c_strWrite(const char*) const;

        struct ResetOnExit {
            ~ResetOnExit() {
                std::fwrite("\033[0m", 1, 4, stdout);
                std::fflush(stdout);
            }
        };
    
        static ResetOnExit _reseter;
    };

    inline Cursor::ResetOnExit Cursor::_reseter{};
}
