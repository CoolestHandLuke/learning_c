/* This program will check the general syntax of a C program for things like balanced curly and square brackets, parantheses, double and 
single quotes, and comments. I'll break it up in to chunks
1. Get it reading files and looking at them line by line, character by character
2. Check and verify balanced curly brackets
3. Check and verify balance square brackets, parantheses
4. Check and verify double and single quotes*/

#include <stdio.h>
#include <stdbool.h>

#define MAXLINE 1000
bool is_everything_closed(int, int);

int main(int argc, char *argv[]) {

    // Check to make sure user provided a file to check
    if (argc < 2) {
        printf("You must provide a file to check.\n");
        return 1;
    }

    char buffer[MAXLINE];

    // Attempt to open file
    FILE *input_file = fopen(argv[1], "r");

    // LOGIC: Set flags and counts for each thing. When we find a new thing, determine wheter it's legal based on 
    // everything else that is open and their counts. 
    bool curly_open = false;
    bool square_open = false;
    bool paranthese_open = false;
    int curly_open_count = 0; // Used to determine how many levels we are nested in
    int square_open_count = 0;
    int paranthese_open_count = 0;

    // Run through each line in the file
    while(fgets(buffer, MAXLINE, input_file) != 0) {
        for (int i = 0; i < MAXLINE - 1; i++) {
            // Break if we find a null character (EOL)
            if (buffer[i] == '\0') {
                break;
            } else if(buffer[i] == '{') {
                curly_open = true;
                curly_open_count++;
            } else if(buffer[i] == '[') {
                square_open = true;
                square_open_count++;
            } else if(buffer[i] == '(') {
                paranthese_open == true;
                paranthese_open_count++;
            } else if (buffer[i] == ']') {
                square_open = false;
                square_open_count--;
            } else if (buffer[i] == ')') {
                paranthese_open = false;
                paranthese_open_count--;
            } else if(buffer[i] == '}') {
                curly_open_count--;
            }
            

        }
    }
    printf("The amount of open (unbalanced) curly brackets is: %d\n", curly_open_count);
    printf("The amount of open (unbalanced) square brackets is: %d\n", square_open_count);
    printf("The amount of open (unbalanced) paranthese is: %d\n", paranthese_open_count);

    return 0;
}

bool is_everything_closed(int square_open_count, int paranthese_open_count) {
    if(square_open_count == 0 && paranthese_open_count == 0) {
        return true;
    } else {
        return false;
    }
}