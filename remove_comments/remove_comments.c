#include <stdio.h>
#include <stdbool.h>
#define MAXLINE 1000

// Comment 1
void getLine(char line[], int maxline);
void removeComments(char line[]);

int main() {

    int len;
    int max;
    char line[MAXLINE];

    max = 0;
    while(getchar() != EOF) {
        getLine(line, MAXLINE);
        //printf("%s", line);
    }
    // Comment 2
    
    return 0;
}

void getLine(char s[], int lim) {

    int c, i;
    // Comment 3
    for (int j = 0; j < MAXLINE - 1; j++) {
        s[j] = '\0';
    }
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
        s[i] = c;
    }
    // Comment 4
    if (c == '\n') {
        s[i] = c;
        i++;       
    }
    
    s[i] = '\0';
    removeComments(s);    
}

void removeComments(char line[]) {

    bool comment = false;
    for (int i = 0; i < MAXLINE - 1 && line[i] != '\0' && line[i] != '\n'; i++) {
        if (line[i] == '/' && i > 0 && line[i - 1] == '/') {
            line[i - 1] = '\0';
            comment = true;
        }
        if (comment) {
            line[i] = '\0';
        }
    }
}

// Comment 6



