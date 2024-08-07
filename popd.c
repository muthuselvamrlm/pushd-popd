#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

#define MAX_DIR_LENGTH 1024
#define FILENAME "dir_stack.txt"



void popd() {
    // Remove top directory from stack
    FILE* file = fopen(FILENAME, "r+");
    if (file == NULL) {
        fprintf(stderr, "Stack is empty\n");
        return;
    }
    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    fseek(file, size - 2, SEEK_SET);
    fprintf(file, "\n");
    fclose(file);
}



int main(int argc, char* argv[]) {
     if (argc != 2) {
        fprintf(stderr, "Usage: %s pushd directory\n", argv[1]);
        return 1;
    }
    
    popd(argv[1]);

    return 0;
}


