#include <stdio.h>

#include <string.h>

//Define the

//IntegerToReverseBinary().

void IntegerToReverseBinary(int integerValue,

char binaryValue[])

{

    //Declare the

    //required functions.

    int i=0;

   

    //Run the loop till

    //the value of the

    //integerValue is greater than 0.

    while(integerValue > 0)

    {

        binaryValue[i] = (integerValue % 2 + '0');

        integerValue = integerValue / 2;

        i++;

    }

   

    //Set null at

    //the last position.

    binaryValue[i] = '\0';

}

//Define the

//function ReverseString().

void ReverseString(char inputString[],

char reversedString[])

{

    //Declare the

    //required variables.

    int i = 0;

    int j = strlen(inputString) - 1;

   

    //Run the loop to access

    //all the values of the

    //array inputString.

    while(inputString[i] != '\0')

    {

        reversedString[j] = inputString[i];

        j--;

        i++;

    }

    reversedString[i] = '\0';

}

//Define the

//main() function.

int main(void) {

    //Declare the

    //required variables.

    int x;

    char reverse_binary[32];

    char binary_string[32];

    //Read and

    //store the input.

    scanf("%d", &x);

   

    //Define the function

    //IntegerToReverseBinary().

    IntegerToReverseBinary(x, reverse_binary);

   

    //Define the function

    //ReverseString().

    ReverseString(reverse_binary, binary_string);

   

    //Print the binary

    //equivalent string.

    printf("%s", binary_string);

   

    //Return from

    //the main() function.

    return 0;

}