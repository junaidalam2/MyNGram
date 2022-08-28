#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>



void counter(int start_char, int end_char, int* count_array, char *string){

    for(int i = 0; string[i] != '\0'; i++) {  // loop through string parameter and count characters

        for(int j = start_char; j <end_char + 1; j++) {
            if(string[i] == j){
                count_array[j-start_char]++;
            }
        }

    }

    return;
}


void printer(int start_char, int num, int* count_array){

    for(int i = 0; i<num ; i++) {  // print number of characters

        char c = i + start_char;

        if(count_array[i] !=0) {

        printf("%c:%d\n", c, count_array[i]);

        }
    }

    return;
}


int main(int argc, char *argv[])
{

    if(argc<2){
        printf("Error. Please provide input.");
    }

    int start_char = 32; // starting ASCII character is a space
    int end_char = 126; // ending ASCII character is ~

    int array_size = end_char - start_char + 1;

    int count_array[array_size];  // contains results of count

    for(int i = 0; i < array_size; i++) {  // set all values in array to 0
        count_array[i] = 0;
    }

    for(int i = 1; i< argc; i++){
        counter(start_char, end_char, count_array, argv[i]);
    }

    printer(start_char, array_size, count_array);

    return 0;
}

