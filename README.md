Cursor Library
==============

A lightweight, header-first C++ library for ANSI cursor and text styling in terminal applications.

Structure
---------
```
include/
└── cursor/
    ├── core.hpp         - Cursor class and stream interface
    ├── color.hpp        - RGB foreground/background color functions
    ├── movement.hpp     - Relative and absolute movement functions
    ├── style.hpp        - Bold, italic, underline, etc.
    └── cursor.hpp       - Umbrella header that includes all of the above

src/
├── core.cpp             - Cursor method definitions
├── color.cpp            - Color implementation
├── movement.cpp         - Movement implementation
└── style.cpp            - Style code generator

test/
└── main.cpp             - Demonstration test file
```

Build Instructions
------------------

To build and run the test:

    mkdir build
    cd build
    cmake ..
    cmake --build .
    ./test/cursor_test

Usage
-----

To use in your own project, include:

    #include <cursor/cursor.hpp>

Then you can do things like:

    using namespace cur;
    cout.clear();
    cout.move(1, 1) << foregroundColor(255, 100, 100) << "Hello, world!" << endl;
