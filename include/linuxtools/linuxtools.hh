/*
 * Copyright (c) ghgltggamer 2025
 * Written by ghgltggamer
 * Licensed under the MIT License
 * Checkout the README.md for more information about the project
 * LLAW - Open Linux Local Ai Wrapper Around LLama.cpp
*/

// Standard Libraries
#include <cstdlib>
#include <iostream>
#include <string>

namespace linuxtools {
    std::string get_home_directory();
    std::string to_bash(const std::string& input);
    std::string replaceAll(std::string str, const std::string& from, const std::string& to);
}