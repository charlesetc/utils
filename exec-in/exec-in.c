#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: ./program <directory> <command>\n");
        return 1;
    }
    
    char *dir = argv[1];
    chdir(dir);
    
    // Shift the arguments to remove the directory from the argument list
    for (int i = 1; i < argc - 1; i++) {
        argv[i] = argv[i + 1];
    }
    
    argv[argc - 1] = NULL;  // Set the last argument to NULL for exec
    
    execvp(argv[1], &argv[1]);
    
    // The code will only reach this point if execvp fails
    perror("execvp");
    return 1;
}
