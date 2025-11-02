/*
 * Copyright (c) ghgltggamer 2025
 * GDLS Int - Goblin's Demonic Scripting Language Interpreter
 * Written by ghgltggamer
 * Licensed under the MIT License
 * Checkout the README.md for more information
 * This interpreter is made for the GDSL Specs 25.00
 */

// This is the lexer header for the gdsl-int
// C++ Headers
#include <components/lexer.hh>

namespace gdsl_int{
    std::vector <std::vector <std::string>> lexer(std::string code){
        std::vector <std::vector <std::string>> tokens;
        bool is_string_open = false,
             is_keyword_defined = false,
             is_comment_started = false,
             is_line_started = false;
        std::string buffer; // Read / Write will be performed in this variable
        std::vector <std::string> current_token; // This will simply hold the current generated token to write inside the tokens
        for (unsigned long long i = 0;i < code.length();i++){
            if (code[i] == '\n' and is_comment_started){
                is_comment_started = false;
                continue;
            }
            if (is_comment_started)
                continue;
            if (code[i] == '#' and not is_string_open and not is_comment_started){
                is_comment_started = true;
                continue;
            }
            if (code[i] != ' ' and not is_line_started) is_line_started = true; // start the line if as non-spaced character is found and the line isn't even started
            if (code[i] == '"'){
                if (is_string_open and code[i-1] == '\\'){
                    buffer[buffer.length()-1] = '"';
                    continue;
                }                    
                is_string_open = not (is_string_open);
            }

            // keyword tokenization
            if (code[i] == ' ' and not is_string_open and is_line_started and not is_keyword_defined){
                current_token.push_back(buffer); // Add the keyword
                buffer.clear(); // Simply clear the buffer afterwards
                is_line_started = false; // Tell the lexer that the line is not started because we don't want to include spaces in our buffer data unless the data is string
                is_keyword_defined = true; // Tell the lexer that our keyword was already defined
            }

            if (code[i] == ',' and not is_string_open and is_line_started and is_keyword_defined){
                current_token.push_back(buffer); // Add the values
                buffer.clear(); // Simply clear the buffer afterwards
                is_line_started = false;  // Tell the lexer that the line is not started because we don't want to include spaces in our buffer data unless the data is string
            }

            if (code[i] == '\n' and not is_string_open and is_keyword_defined){
                current_token.push_back(buffer); // Add the values
                buffer.clear(); // Simply clear the buffer afterwards
                is_keyword_defined = false;
                is_line_started = false;
                tokens.push_back(current_token); // Add the token to the current token
                current_token.clear(); // clear the current token too
                continue;
            }
            if (code[i] == '\n' and not is_string_open and not is_keyword_defined){
                tokens.push_back({"", ""}); // Push empty lines
                buffer.clear(); // Simply clear the buffer afterwards
                is_keyword_defined = false;
                is_line_started = false;
                current_token.clear(); // clear the current token too
                continue;
            }

            // code management
            if (is_line_started)
                buffer += code[i];
        }
        return tokens;
    }
}