#include "cursor.hpp"

int main() {
    using cur::cout;
    using cur::endl;

    // Clear the screen and position cursor
    cout.clear();
    cout.move(0, 0);
    cout << "=== Cursor Test Start ===" << endl;

    // Test: basic text and numbers
    cout.move(1, 0);
    cout << "String test: " << "Hello, world!" << endl;

    cout.move(2, 0);
    cout << "Integer test: " << 42 << endl;

    cout.move(3, 0);
    cout << "Double test: " << 3.1415926535 << endl;

    // Test: chaining
    cout.move(4, 0);
    cout << "Chained: " << "foo" << " + " << 123 << " + " << 4.56 << endl;

    // Test: ASCII art / Wide Unicode Characters
    cout.move(6, 10);
    cout << "┌────┐" << endl;
    cout.move(7, 10);
    cout << "│ :) │" << endl;
    cout.move(8, 10);
    cout << "└────┘" << endl;

    // Test: cursor movement and overwriting
    cout.move(10, 0);
    cout << "Overwriting test: wait..." << endl;

    cout.move(10, 0);
    cout << "✓ Overwritten!" << endl;

    // Final cursor move (to bottom so prompt doesn't overwrite output)
    cout.move(11, 20);
    cout << "=== Cursor Test End ===" << endl;
}
