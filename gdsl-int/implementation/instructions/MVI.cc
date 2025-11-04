/*
 * Note - This file doesn't contains any of the implementation information with it , Please refer the .cc file for it
 * Copyright (c) ghgltggamer 2025
 * GDLS Int - Goblin's Demonic Scripting Language Interpreter
 * Written by ghgltggamer
 * Licensed under the MIT License
 * Checkout the README.md for more information
 * This interpreter is made for the GDSL Specs 25.00
 */

// This is the MVI Instruction header for the gdsl-int
// C++ Headers
#include <instructions/MVI.hh>

namespace gdsl_int {
    std::string MVI(std::string name, std::string value, std::vector <std::vector <std::string>> &blocks){
        bool is_defined = false;
        std::string error;
        for (std::vector <std::string> &current_block : blocks){
            for (std::string current_block_name : current_block){
                if (current_block_name == name){
                    is_defined = true;
                    std::string type = current_block[1]; // data type
                    std::string& block_value = current_block[2]; // value / data block
                    if (type == "INT"){
                        // blocks.push_back({name, "INT", "0"});
                        if (gdsl_int::is_string_integer(value)){
                            block_value = value;
                        }
                        else {
                            error = "An INT can only store numbers like 0, 1, 2 ... But the data type passed was a non-integer type";
                        }
                    }
                
                    else if (type == "INT2"){
                        // blocks.push_back({name, "INT2", "0"});
                        if (value == "0" or value == "1"){
                            block_value = value;
                        }
                        else {
                            error = "An INT2 can only store 0 or 1, MVI Can not move any other value to it.";
                        }
                    }
                
                    else if (type == "UINT"){
                        // blocks.push_back({name, "UINT", "0"});
                        if (gdsl_int::is_string_integer(value) and gdsl_int::string_to_int(value) >= 0){
                            block_value = value;
                        }
                        else {
                            error = "An UINT can only store positive numbers like 0, 1, 2 ... But the data type passed was a non-integer type";
                        }
                    }
                
                    else if (type == "FLOAT"){
                        // blocks.push_back({name, "FLOAT", "0.0"});
                        if (gdsl_int::is_string_float(value)){
                            block_value = value;
                        }
                        else {
                            error = "A FLOAT can only store decimal numbers like 0.0, 1.0, 2.0 ... But the data type passed was a non-floating-point type";
                        }
                    }
                
                    else if (type == "STR"){
                        // blocks.push_back({name, "STR", ""});
                        if (value[0] == '"' and value[value.length()-1] == '"') // Always a string signature
                            block_value = value.substr(1, value.length()-2);
                        else
                            error = "A STR can only store characters inside \"\" like \"Hello world 2025\" ... But the data type passed was a non-string type";
                    }
                    else {
                        std::string msg = "Unknown type passed to MVI in block " + name + " , type:" + type;
                        error = msg;
                    }
                    break;
                }
            }
            if (is_defined){
                break;
            }
        }


        if (is_defined == false){
            error = "MVI Can not move a value to an undefined block.";
        }

        return error;
    }
}