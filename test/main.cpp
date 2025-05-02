#include "cursor.hpp"

using namespace cur;

int main() {

    // Clear the screen and position cursor
    cout.clear();
    cout.move(1, 0);
    cout << backgroundColor(100,0 ,0) << "=== Cursor Test Start ===" << endl;

    // Test: basic text and numbers
    cout.move(2, 0);
    cout << foregroundColor(255, 136, 80) << "String test: " << foregroundColor(50, 222, 96) << "Hello, world!" << endl << clearStyle;

    cout.move(3, 0);
    cout << "Integer test: " << 42 << endl;

    cout.move(4, 0);
    cout << "Double test: " << 3.1415926535 << endl;

    // Test: chaining
    cout.move(5, 0);
    cout << "Chained: " << "foo" << " + " << 123 << " + " << 4.56 << endl;

    // Test: ASCII art / Wide Unicode Characters
    cout.move(7, 10);
    cout << "┌────┐" << endl;
    cout.move(8, 10);
    cout << "│ :) │" << endl;
    cout.move(9, 10);
    cout << "└────┘" << endl;

    // Test: cursor movement and overwriting
    cout.move(11, 0);
    cout << "Overwriting test: wait..." << endl;

    cout.move(11, 0);
    cout << "✓ Overwritten!" << endl;

    // Final cursor move (to bottom so prompt doesn't overwrite output)
    cout.move(12, 20);
    cout << "=== Cursor Test End ===" << endl;
}
