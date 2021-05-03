#include <stdio.h>
#include <string.h>

//Start the execution of the main() method.

int main(void) {

//Declare required 1D and 2D character arrays to

//store input strings and to store them as an array

//of strings.

char input_line[50];

char input_str_arr[10][50];

//Declare required integer variables to store

//indicies of the array and loops.

int i, j, index, input_str_len;

index = input_str_len = 0;

//Start an infinite while loop.

while(1) {

    //Prompt the user to enter a string using fgets.

    fgets(input_line, 50, stdin);

    //Get the length of the input string.

    input_str_len = strlen(input_line);

    //Discard the new line character from the string

    //entered by fgets and place null character at the

    //end of the string.

    //input_line[input_str_len - 1] = '\0';
    if (input_line[input_str_len - 1] == '\n') {
      input_line[input_str_len - 1] = '\0';
   }

    //If the entered string is Quit, quit, or q, then

    //break the loop.

    if(strcmp(input_line, "Quit") == 0 || strcmp(input_line, "quit") == 0 || strcmp(input_line, "q") == 0) {

      break;

    }

    //Copy the entered string to the 2d array of

    //characters at appropriate row position.

    strcpy(input_str_arr[index], input_line);

    //Increment the value of the index variable by 1.

    index++;

}
//Start a for loop till the row index of the 2d

//array of characters.

for(i = 0; i < index; i++)

{

    //Start a for loop from the last index to the

    //0th index of the string stored at the current

    //row position in the 2D array of characters.

    for(j = strlen(input_str_arr[i]) - 1; j >= 0; j--) {

      //Display each character of the strings stored

      //in the 2D array of characters as per the

      //indicies of the for loops.

      printf("%c", input_str_arr[i][j]);

    }

    //Display new line character.

    printf("\n");

}

return 0;

}