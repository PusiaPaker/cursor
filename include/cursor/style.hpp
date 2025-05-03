#pragma once

namespace cur {
    class Cursor;

    Cursor& applyCursorVisibility(Cursor& c, bool cond);
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
            return applyCursorVisibility(c,opt);
        };
    }
}