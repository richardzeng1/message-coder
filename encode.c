#include <stdio.h>
#include <stdlib.h>

#include <string.h>  // Only used for strlen


#define MAXLINE 256

// Error messages
#define USAGE "Usage: encode chunksize textfile msg\n"
#define ENCODE_FAILED "Could not encode message.\n"


int main(int argc, char *argv[]) {
    // Check to make sure the user entered the correct number of arguments
    if(argc != 4) {
        fprintf(stderr, USAGE);
        exit(1);
        // The argument of 1 is a convention indicating the program failed
    }

    FILE *tf; // File pointer for the text document

    // determine message chunks size
    int chunk_size = strtol(argv[1], NULL, 0);
    if(chunk_size == 0) {
        fprintf(stderr, "Invalid chunk size\n");
        exit(1);
    }

    if((tf = fopen(argv[2], "r")) == NULL) {
        perror("fopen");
        exit(1);
    }

    // The message to encode is in argv[3].  We will use a pointer to char
    // to give it a better name.
    char *message = argv[3];
    int msg_length = strlen(message);  // only allowed use of string functions
    // Char array to store text line currently being processed
    char current_line[MAXLINE];
    // Text line number
    int text_line = -1;;
    // Starting char index
    int char_index;
    // Boolean to keep track if the message chunk is found
    int found;
    // Adder to char_index
    int index_addition;

    int new_chunk_size=msg_length % chunk_size;
    int num_full_chunk = msg_length / chunk_size;

    // Iterating for every chunk_size of the message
    for (int index = 0; index<msg_length; index+=chunk_size){
        if (num_full_chunk==0){
            chunk_size = new_chunk_size;
        }
        // Checking current line if it contains the message chunk
        found = 0;

        // Reading each line of the text file
        while(fgets(current_line, MAXLINE, tf)!=NULL){
            char_index =0;
            text_line++;
            while(current_line[char_index]!='\0'){
                index_addition = 0;
                while (index_addition<chunk_size){
                    if (current_line[char_index+index_addition] == message[\
                        index + index_addition]){
                        if (index_addition == chunk_size-1){
                            found =1;
                            printf("%d %d %d\n", text_line, char_index,\
                            chunk_size);
                            break;
                        }
                    }else{
                        break;
                    }
                    index_addition++;
                }
                if (found==1){
                    break;
                }
                char_index++;
            }

            if (found==1){
                break;
            }

        }

        if (found==0){
            fprintf(stderr, ENCODE_FAILED);
            exit(1);
        }

        num_full_chunk--;

    }



    return 0;
}
