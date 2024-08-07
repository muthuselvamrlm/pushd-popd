#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

#define MAX_DIR_LENGTH 1024
#define FILENAME "dir_stack.txt"

void pushd(const char* dir) {
    char oldDir[MAX_DIR_LENGTH];
    getcwd(oldDir, MAX_DIR_LENGTH);
   
    if (chdir(dir) != 0) {
        perror("chdir");
        return;
    }

    // Save old directory to file as a stack
    FILE* file = fopen(FILENAME, "r+");
    if (file == NULL) {
        file = fopen(FILENAME, "w");
    }
    fseek(file, 0, SEEK_END);
    fprintf(file, "%s\n", oldDir);
    fclose(file);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s pushd directory\n", argv[1]);
        return 1;
    }
    
    pushd(argv[1]);

    return 0;
}


