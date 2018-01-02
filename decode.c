#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 256

// Error messages
#define USAGE "Usage: decode textfile codefile\n"
#define INVALID_LINE "Invalid line number\n"
#define EMPTY "Document is empty\n"
#define INVALID_POSITION "Invalid character position for this line\n"
#define LENGTH "Invalid chunk size"


int main(int argc, char *argv[]) {
    // If the user did not enter the correct number of arguments then exit
    if(argc != 3) {
        fprintf(stderr, USAGE);
        exit(1);
        // The argument of 1 is a convention indicating the program failed
    }

    FILE *tf; // File pointer for the text document
    FILE *cf; // File pointer for the code file

    /* Open both files for reading. Terminate if there is any problem
     * opening the files */
    if((tf = fopen(argv[1], "r")) == NULL) {
        perror("fopen");
        exit(1);
    }

    if((cf = fopen(argv[2], "r")) == NULL) {
        perror("fopen");
        exit(1);
    }

    // We will assume that lines read from the text file and the code file
    // will never exceed MAXLINE-1 characters.
    char code_line[MAXLINE];
    char text_line[MAXLINE];

    // Add your implmeentation below.

    // Iterating through each line in the code file
    // The line number we want the charactersfrom
    int line_num;
    // The starting char index
    int char_index;
    // The length of the string we want from the line
    int str_length;
    // Reference to the left over values when we convert from string to integer
    char *left_over;
    // A reference to the current line we are parsing
    int text_line_number = 0;
    // Check if code is empty
    int empty = 1;
    while(fgets(code_line, MAXLINE, cf)!=NULL){
        empty = 0;
        // Reading the code to determine which parts of the text to read
        line_num = strtol(code_line, &left_over, 10);
        char_index = strtol(left_over, &left_over, 10);
        str_length = strtol(left_over, NULL, 10);

        if (str_length<0){
            fprintf(stderr, LENGTH);
            exit(1);
        }
        for (int iterator = text_line_number; iterator<= line_num; iterator++){

            // Iterating char based on input
            if (fgets(text_line, MAXLINE, tf)==NULL){
                // If reading the line number does not exist
                // print error and exit code 1
                fprintf(stderr, INVALID_LINE);
                exit(1);
            }
            text_line_number++;
        }
	
        // Array to store the message
        char message[str_length];
        if (text_line[char_index] == '\0'){
            fprintf(stderr, INVALID_POSITION);
            exit(1);
        }
        for (int index = 0; index < str_length; index++){

            if (text_line[char_index+index] != '\0'){
                //printf("%c \n", text_line[char_index+index]);
                message[index] = text_line[char_index+index];
            }else{
                fprintf(stderr, LENGTH);
                exit(1);
            }
        }
        // Printing the message
        for (int index =0; index<str_length; index++){
            printf("%c", message[index]);
        }

    }
    // Error message that prints if the code is empty.
    if (empty){
        fprintf(stderr, EMPTY);
        exit(1);
    }


    // Print a newline after the end of the message so the prompt appears on
    // the next line.
    printf("\n");
    return 0;
}
