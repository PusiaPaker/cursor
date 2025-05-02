#include "cursor.hpp"

using namespace cur;

// Because windows hates us, and UTF8 is something to hard to implement
#if _WIN32
    #include <windows.h>
#endif

int main() {
    #if _WIN32
        SetConsoleOutputCP(CP_UTF8);
    #endif

    // Clear the screen and position cursor
    cout.clear();
    cout.move(1, 0);
    cout << backgroundColor(100, 0, 0) << "=== Cursor Test Start ===" << endl;

    // Basic text and numbers
    cout.move(2, 0);
    cout << foregroundColor(255, 136, 80) << "String test: " 
         << backgroundColor(0, 50, 78) 
         << foregroundColor(50, 222, 96) 
         << "Hello, world!" << endl << clearStyle;

    cout.move(3, 0);
    cout << "Integer test: " << 42 << endl;

    cout.move(4, 0);
    cout << "Double test: " << 3.1415926535 << endl;

    // Chaining test
    cout.move(5, 0);
    cout << "Chained: " << "foo" << " + " << 123 << " + " << 4.56 << endl;

    // ASCII art / Unicode
    cout.move(7, 10);
    cout << "┌────┐" << endl;
    cout.move(8, 10);
    cout << "│ :) │" << endl;
    cout.move(9, 10);
    cout << "└────┘" << endl;

    // Cursor movement and overwrite
    cout.move(11, 0);
    cout << "Overwriting test: wait..." << endl;
    cout.move(11, 0);
    cout << "✓ Overwritten!" << endl;

    // Color Gradient Test
    cout.move(13, 0);
    cout << "Color Gradient (Red to Green):" << endl;
    for (int i = 0; i <= 50; ++i) {
        int r = 255 - (i * 5);
        int g = i * 5;
        cout << backgroundColor(r, g, 0) << " ";
    }
    cout << clearStyle << endl << endl;

    // Checkerboard Test
    cout.move(15, 0);
    cout << "Checkerboard Pattern:" << endl;
    for (int y = 0; y < 8; ++y) {
        cout.move(17 + y, 0);
        for (int x = 0; x < 8; ++x) {
            bool isDark = (x + y) % 2 == 0;
            if (isDark)
                cout << backgroundColor(30, 30, 30) << "   ";
            else
                cout << backgroundColor(200, 200, 200) << "   ";
        }
        cout << clearStyle << endl;
    }

    // Foreground & Background Grid Test
    cout.move(26, 0);
    cout << "Foreground / Background Color Grid:" << endl;
    for (int i = 0; i < 6; ++i) {
        cout.move(27 + i, 0);
        for (int j = 0; j < 12; ++j) {
            int r = (i * 40 + 40) % 256;
            int g = (j * 20 + 60) % 256;
            int b = (i * j * 5) % 256;
            cout << backgroundColor(r, g, b) 
                 << foregroundColor(255 - r, 255 - g, 255 - b) 
                 << " T " 
                 << clearStyle;
        }
        cout << endl;
    }

    // Final cursor move
    cout.move(35, 0);
    cout << "=== Cursor Test End ===" << endl;
}
