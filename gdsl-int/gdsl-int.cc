/*
 * Copyright (c) ghgltggamer 2025
 * GDLS Int - Goblin's Demonic Scripting Language Interpreter
 * Written by ghgltggamer
 * Licensed under the MIT License
 * Checkout the README.md for more information
 * This interpreter is made for the GDSL Specs 25.00
 */

// This is the main interpreter CLI Interface file
#include <components/lexer.hh>
#include <components/parser.hh>
#include <components/log.hh>

#include <fstream>

int main(int argc, char* argv[]){
    // test
    // gdsl_int::write("Running MOV A, B\n", gdsl_int::WRITE_LOG);
    // std::string program = "MOV A, B, \"Cd\",\"C \n  \\\"d\"\nBLOCK C\n";
    // auto tokens = gdsl_int::lexer(program);
    // std::cout << "Size of tokens: "<<tokens.size()<<"\n";
    // for (std::vector <std::string> token : tokens){
    //     for (std::string keyword : token){
    //         gdsl_int::write(keyword, gdsl_int::WRITE_WARN);
    //     }
    // }

    // DEF TEST
    // std::string program = "DEF INT, A\nDEF UINT, B\nMVI A, 9\nMVI B, 9\nMVI A, 9\nDEF INT2, C\nMVI C, 1\nDEF DOUBLE, D\n";
    // auto tokens = gdsl_int::lexer(program);
    // gdsl_int::parse(tokens);
    // for (std::vector <std::string> token : gdsl_int::blocks){
    //     for (std::string keyword : token){
    //         gdsl_int::write(keyword, gdsl_int::WRITE_WARN);
    //     }
    // }
    // gdsl_int::write("Exiting...\n", gdsl_int::WRITE_LOG);

    // Main program
    if (argc < 2){
        gdsl_int::write("Need the file to execute! NO FILE WAS PASSED", gdsl_int::WRITE_ERR);
        return 3;
    }

    if (std::string (argv[1]) == "--version"){
        std::cout << "GDSL-INT V(BETA)0.0.1\n";
    }

    std::ifstream ifile (argv[1]);
    if (ifile.is_open()){
        std::string code, temp;
        while (std::getline(ifile, temp)){
            code += temp + "\n";
        }
        auto tokens = gdsl_int::lexer(code);
        gdsl_int::parse(tokens);
            for (std::vector <std::string> token : gdsl_int::blocks){
                for (std::string keyword : token){
                    gdsl_int::write(keyword, gdsl_int::WRITE_WARN);
                }
            }
    }
    else {
        gdsl_int::write("File couldn't be opened", gdsl_int::WRITE_ERR);
        return 3;
    }
}