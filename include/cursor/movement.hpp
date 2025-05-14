#pragma once

namespace cur {
    class Cursor;

    enum class Direction { up, down, left, right };

    Cursor& applyMove(Cursor&, int, int);
    Cursor& applyMove(Cursor&, Direction, int);

    inline auto move(int row, int col) {
        return [=](Cursor& c) -> Cursor& {
            return applyMove(c, row, col);
        };
    }

    inline auto move(Direction dir, int distance) {
        return [=](Cursor& c) -> Cursor& {
            return applyMove(c, dir, distance);
        };
    }
}