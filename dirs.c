#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

#define MAX_DIR_LENGTH 1024
#define FILENAME "dir_stack.txt"

void dirs() {
    // Print directory stack
    FILE* file = fopen(FILENAME, "r");
    if (file == NULL) {
        fprintf(stderr, "Stack is empty\n");
        return;
    }
    char line[MAX_DIR_LENGTH];
    while (fgets(line, MAX_DIR_LENGTH, file)) {
        printf("%s", line);
    }
    fclose(file);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s pushd directory\n", argv[1]);
        return 1;
    }
    dirs();
    return 0;
}


