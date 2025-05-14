#pragma once

namespace cur {
    class Cursor;
    extern Cursor cout;

    Cursor& sendStyleCursorCode(Cursor& c, bool cond, int escCode, int resetCode);
    Cursor& applyCursorVisibility(Cursor& c, bool cond);

    #define DEFINE_STYLE(name, escCode, resetCode) \
        struct name##_t { \
            bool opt; \
            name##_t(bool o) : opt(o) {} \
            Cursor& operator()(Cursor& c) const { \
                return sendStyleCursorCode(c, opt, escCode, resetCode); \
            } \
            operator auto() const { \
                bool localOpt = opt; \
                return [localOpt](Cursor& c) -> Cursor& { \
                    return sendStyleCursorCode(c, localOpt, escCode, resetCode); \
                }; \
            } \
        }; \
        inline name##_t name(bool opt) { return name##_t(opt); }

    DEFINE_STYLE(setBold, 1, 22)
    DEFINE_STYLE(setFaint, 2, 22)
    DEFINE_STYLE(setItalic, 3, 23)
    DEFINE_STYLE(setUnderline, 4, 24)
    DEFINE_STYLE(setBlinking, 5, 25)
    DEFINE_STYLE(setInverse, 7, 27)
    DEFINE_STYLE(setHidden, 8, 28)
    DEFINE_STYLE(setStrikethrough, 9, 29)

    struct setCursorVisibility_t {
        bool opt;
        setCursorVisibility_t(bool o) : opt(o) {}
        Cursor& operator()(Cursor& c) const {
            return applyCursorVisibility(c, opt);
        }
        operator auto() const {
            bool localOpt = opt;
            return [localOpt](Cursor& c) -> Cursor& {
                return applyCursorVisibility(c, localOpt);
            };
        }
    };
    inline setCursorVisibility_t setCursorVisibility(bool opt) { return {opt}; }

    #undef DEFINE_STYLE
}
