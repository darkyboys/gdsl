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
#include <components/util.hh>

namespace gdsl_int{
    int string_to_int(std::string_view s) noexcept {
        const char* p = s.data();
        const char* end = p + s.size();

        bool neg = false;
        if (p != end && *p == '-') {
            neg = true;
            ++p;
        }

        int value = 0;
        while (p != end) {
            // Convert digit without branching
            value = value * 10 + (*p - '0');
            ++p;
        }

        return neg ? -value : value;
    }

    float string_to_float(std::string_view s) noexcept {
        const char* p = s.data();
        const char* end = p + s.size();
        
        bool neg = false;
        if (p != end && *p == '-') {
            neg = true;
            ++p;
        }
    
        float value = 0.0f;
    
        // Parse integer part
        while (p != end && *p != '.') {
            value = value * 10.0f + (*p - '0');
            ++p;
        }
    
        // Parse fractional part
        if (p != end && *p == '.') {
            ++p;
            float frac = 0.0f;
            float div = 1.0f;
        
            while (p != end) {
                frac = frac * 10.0f + (*p - '0');
                div *= 10.0f;
                ++p;
            }
        
            value += frac / div;
        }
    
        return neg ? -value : value;
    }

    bool is_string_integer(std::string_view s) noexcept {
        const char* p = s.data();
        const char* end = p + s.size();

        if (p == end) return false; // empty string

        if (*p == '-' || *p == '+') ++p; // optional sign
        if (p == end) return false; // only sign, no digits

        while (p != end) {
            if (*p < '0' || *p > '9')
                return false;
            ++p;
        }
        return true;
    }

    bool is_string_float(std::string_view s) noexcept {
        const char* p = s.data();
        const char* end = p + s.size();
        
        if (p == end) return false; // empty string
        
        if (*p == '-' || *p == '+') ++p; // optional sign
        if (p == end) return false;
        
        bool has_digit = false;
        bool has_dot = false;
        
        while (p != end) {
            if (*p >= '0' && *p <= '9') {
                has_digit = true;
            } else if (*p == '.') {
                if (has_dot) return false; // multiple dots
                has_dot = true;
            } else {
                return false; // invalid character
            }
            ++p;
        }
    
        // must have at least one digit (before or after '.')
        return has_digit;
    }
}