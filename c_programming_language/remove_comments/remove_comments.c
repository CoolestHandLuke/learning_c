#include <stdio.h>
#include <stdbool.h>
#define MAXLINE 1000

void getLine(char line[], int maxline);
void removeComments(char line[]);

int main(int argc, char *argv[]) {

    // User must provide the name of the file they wish to remove comments from, nothing else
    // Check to make sure we have CL arguments. If not, exit the program
    if (argc < 2) {
        printf("You must provide a file to read from.\n");
        return 1;
    }

    char buffer[MAXLINE];
    
    // Open File to read and write to
    FILE *intput_file = fopen(argv[1], "r");
    FILE *output_file = fopen("output.txt", "w");

    // Run through each line checking for comments, deleting as needed
    // Write each line to the output file during each iteration
    while(fgets(buffer, MAXLINE, intput_file) != 0) {
        removeComments(buffer);
        fputs(buffer, output_file);
    }
    // Close all files to prevent memory leaks
    fclose(intput_file);
    fclose(output_file);
    
    return 0;
}

void removeComments(char line[]) {

    bool comment = false;
    for (int i = 0; i < MAXLINE - 1 && line[i] != '\0'; i++) {
        if (line[i] == '\n' && i > 0) {
            // fall through
        } else if (comment && line[i] != '\n') {
            line[i] = '\0';
        } else if (line[i] == '/' && i > 0 && line[i - 1] == '/') {
            line[i - 1] = '\n';
            line[i] = '\0';
            comment = true;
        }

    }
}