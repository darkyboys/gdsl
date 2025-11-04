/*
 * Note - This file doesn't contains any of the implementation information with it , Please refer the .cc file for it
 * Copyright (c) ghgltggamer 2025
 * GDLS Int - Goblin's Demonic Scripting Language Interpreter
 * Written by ghgltggamer
 * Licensed under the MIT License
 * Checkout the README.md for more information
 * This interpreter is made for the GDSL Specs 25.00
 */

// This is the EXEC Instruction header for the gdsl-int
// C++ Headers
#include <instructions/EXEC.hh>
#include <linuxtools/linuxtools.hh>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fstream>
#include <cstdio>   // for unlink

namespace gdsl_int {
    std::string EXEC(std::vector <std::string> commands, std::vector <std::vector <std::string>> &blocks){
        bool is_defined = false;
        std::string error;
        if (blocks.size() < 1){
            error = "EXEC Can't find any top level memory allocation to store the STDOUT and STDERR of the program";
            return error;
        }
        // process code
        pid_t process = fork();
        std::string file_path = linuxtools::get_home_directory() + "/.0000-xgdslint64-io-fd";
        if (process == 0){
            auto w_fd = open(file_path.c_str(), O_WRONLY | O_CREAT | O_TRUNC, 0644);
            if (w_fd < 0) {
                perror("EXEC ERR: open failed");
                _exit(1);
            }
            dup2(w_fd, 1);
            dup2(w_fd, 2);
            close(w_fd);
            std::vector <char*> arg_vec = {};
            for (auto &arg : commands)
                arg_vec.push_back(const_cast<char*>(arg.c_str()));

            arg_vec.push_back(nullptr);
            execvp(arg_vec[0], arg_vec.data());
            perror("EXEC ERR: execv failed");
            _exit(1);
        }
        else if (process < 0){
            error = "EXEC ERR: fork failed";
            return error;
        }
        
        int status;
        if (waitpid(process, &status, 0) == -1){
            error = "EXEC ERR: waitpid failed";
            return error;
        }
        std::ifstream ifile(file_path);
        if (!ifile.is_open()){
            error = "EXEC ERR: can not open the file ";
            return error;
        }
        std::string temp;
        while (std::getline(ifile, temp))
            blocks[0][2] += temp + '\n'; // write the data to EXEC_BUFFER
        unlink(file_path.c_str());
        return error;
    }
}