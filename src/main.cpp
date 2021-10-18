#include <stdio.h>
#include <cstring>
#include <stdlib.h> 

#include "analisador_lexico.h"
#include "analisador_sintatico.hpp"
// #include "analisador_escopo.hpp"
#include <errno.h>

void ERROR_FUNC(){
    printf("Invalid arguments\nUsage: compilador [SCRIPT_NAME] -o [OUTPUT_FILE_NAME]\n");
    exit(1);
}

int main(int argc, char const *argv[])
{
    std::string input_file_name, output_file_name;
     if (argc == 4) {
        if (!strcmp(argv[2],"-o")) {
            input_file_name = argv[1];
            output_file_name = argv[3];
        } else {
            ERROR_FUNC();
        }
    } else {
        ERROR_FUNC();
    }
    printf("input_file_name: %s\noutput_file_name: %s\n", input_file_name.c_str(), output_file_name.c_str());

    program = fopen(input_file_name.c_str(), "r");
    if (!program) {
        fprintf(stderr, "Failed to open %s: %s\n", input_file_name.c_str(), strerror(errno));
    }
    parse();
    return 0;
}