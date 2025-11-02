/*
 * Copyright (c) ghgltggamer 2025
 * GDLS Int - Goblin's Demonic Scripting Language Interpreter
 * Written by ghgltggamer
 * Licensed under the MIT License
 * Checkout the README.md for more information
 * This interpreter is made for the GDSL Specs 25.00
 */

// This is the log header for the gdsl-int
// C++ Headers
#include <components/log.hh>

namespace gdsl_int{
    void write(const std::string& msg, int type) {
        // ANSI color codes for foreground/background
        const std::string reset = "\033[0m";
        std::string label;

        switch (type) {
            case 1:
                // [LOG] → white text on black background
                label = "\033[47;30m[LOG]\033[0m ";
                break;
            case 2:
                // [WARNING] → yellow text on black background
                label = "\033[43;30m[WARNING]\033[0m ";
                break;
            case 3:
                // [ERROR] → red background with white text
                label = "\033[41;37m[ERROR]\033[0m ";
                break;
            default:
                label = "[UNKNOWN] ";
                break;
        }

        std::cout << label << msg << std::endl;
    }
}