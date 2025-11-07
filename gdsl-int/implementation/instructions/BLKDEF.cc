/*
 * Note - This file doesn't contains any of the implementation information with it , Please refer the .cc file for it
 * Copyright (c) ghgltggamer 2025
 * GDLS Int - Goblin's Demonic Scripting Language Interpreter
 * Written by ghgltggamer
 * Licensed under the MIT License
 * Checkout the README.md for more information
 * This interpreter is made for the GDSL Specs 25.00
 */

// This is the DEF Instruction header for the gdsl-int
// C++ Headers
#include <instructions/DEF.hh>
#include <components/util.hh>

namespace gdsl_int {
    std::string BLKDEF(std::string name, std::string type, std::string size, std::vector <std::vector <std::string>> &blocks){
        bool is_defined = false;
        std::string err = "";
        for (std::vector <std::string> current_block : blocks){
            for (std::string current_block_name : current_block){
                if (current_block_name == name){
                    is_defined = true;
                    break;
                }
            }
            if (is_defined){
                break;
            }
        }


        if (is_defined){
            return err;
        }

        if (not gdsl_int::is_string_integer(size)){
            err = ("BLKDEF size can't be a non integer value");
            return err;
        }

        if (type == "INT"){
            blocks.push_back({name, "INT"});
            blocks[blocks.size()-1].resize(gdsl_int::string_to_int(size)+2);// +2 is to store variable name and type
        }

        else if (type == "INT2"){
            blocks.push_back({name, "INT2"});
            blocks[blocks.size()-1].resize(gdsl_int::string_to_int(size)+2);// +2 is to store variable name and type
        }

        else if (type == "UINT"){
            blocks.push_back({name, "UINT"});
            blocks[blocks.size()-1].resize(gdsl_int::string_to_int(size)+2);// +2 is to store variable name and type
        }

        else if (type == "FLOAT"){
            blocks.push_back({name, "FLOAT"});
            blocks[blocks.size()-1].resize(gdsl_int::string_to_int(size)+2);// +2 is to store variable name and type
        }

        else if (type == "STR"){
            blocks.push_back({name, "STR"});
            blocks[blocks.size()-1].resize(gdsl_int::string_to_int(size)+2);// +2 is to store variable name and type
        }
        else {
            err = "Unknown data type passed to DEF!!!";
        }
        return err;
    }
}