/*
 * Note - This file doesn't contains any of the implementation information with it , Please refer the .cc file for it
 * Copyright (c) ghgltggamer 2025
 * GDLS Int - Goblin's Demonic Scripting Language Interpreter
 * Written by ghgltggamer
 * Licensed under the MIT License
 * Checkout the README.md for more information
 * This interpreter is made for the GDSL Specs 25.00
 */

// This is the utility header for the programs
// C++ Headers
#include <cstdint>
#include <string_view>

namespace gdsl_int{
    int string_to_int(std::string_view s) noexcept;
    float string_to_float(std::string_view s) noexcept;

    bool is_string_integer(std::string_view s) noexcept;
    bool is_string_float(std::string_view s) noexcept;
}