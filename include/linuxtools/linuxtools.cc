/*
 * Copyright (c) ghgltggamer 2025
 * Written by ghgltggamer
 * Licensed under the MIT License
 * Checkout the README.md for more information about the project
 * LLAW - Open Linux Local Ai Wrapper Around LLama.cpp
*/

// Standard Libraries
#include "linuxtools.hh"

namespace linuxtools {
    std::string get_home_directory() {
        const char* home = std::getenv("HOME");
        if (home == nullptr || *home == '\0') {
            std::cerr << "Error -> HOME environment variable not set.\n";
            std::exit(3);
        }
        return std::string(home);
    }


    std::string to_bash(const std::string& input) {
        std::string result = "";

        for (char c : input) {
            switch (c) {
                case '\"': result += "\\\""; break;  // Escape double quote
                case '\\': result += "\\\\"; break;  // Escape backslash
                case '$':  result += "\\$";  break;  // Optional: escape $
                case '`':  result += "\\`";  break;  // Optional: escape backticks
                case '\n': result += "\\n";  break;  // Optional: escape newline
                case '\t': result += "\\t";  break;  // Optional: escape tab
                default:   result += c;
            }
        }

        result += "";  // End with a double quote
        return result;
    }


    std::string replaceAll(std::string str, const std::string& from, const std::string& to) {
        if (from.empty()) return str; // avoid infinite loop
    
        size_t start_pos = 0;
        while ((start_pos = str.find(from, start_pos)) != std::string::npos) {
            str.replace(start_pos, from.length(), to);
            start_pos += to.length(); // move past the replacement
        }
        return str;
    }

}