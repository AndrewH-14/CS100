// #include<stdio.h>
// #include <string.h>
// #include <stdbool.h>

// int main(void) {

//    char userInput[100];
//    char userInput2[100];
//    char userInput3[100];
//    int comma = 0;
//    bool inputDone = false;

//     printf("Enter input string:\n");
//     fgets(userInput, 100, stdin);

//     while (userInput != "q") {

//       while (!inputDone) {
//          // printf("Enter input string:\n");
//          // fgets(userInput, 100, stdin);

//          for (int i = 0; i < strlen(userInput); i++) {
//             if (userInput[i] == ',') {
//             comma++;
//             }
//          }
//          if (comma != 0) {
//             inputDone = true;
//          }
//          if (comma == 0) {
//             printf("Error: No comma in string.\n");
//          }
//       }
//       sscanf(userInput, "%s,%s", userInput2, userInput3);
//       printf("First word: %s\n", userInput2);
//       printf("Second word: %s\n\n", userInput3);

//       printf("Enter input string:\n");
//       fgets(userInput, 100, stdin);
//       comma = 0;
//       }

//    return 0;
// }
// Include the required header files.

#include <stdio.h>

#include <stdlib.h>

#include <string.h>

// Define the main() function.

int main(int argv, char** args)

{

      // Declare the required variables.

      char *s1;

      char s2[50], s3[50];

      size_t size = 50;

      int flag = 0;

      // Allocate the memory.

      s1 = (char *)malloc(size * sizeof(char));

      // Prompt the user to enter the input.

      printf("Enter input string:\n");

      getline(&s1, &size, stdin);

      // Start the loop.

      while (1)

      {

            // Check if the user wants to quit.

            if (strlen(s1) == 2)

            {

                  if (s1[0] == 'q')

                  {

                        // Exit the program.

                        exit(0);

                  }

            }

            int i, j = 0;

            // Start the loop till end of the string.

            for (i = 0; s1[i] != '\0'; i++)

            {

                  // Break the loop if comma is found.

                  if (s1[i] == ',')

                  {

                        // Set the flag and break the loop.

                        flag = 1;

                        break;

                  }

                  // Otherwise, enter the character in the

// new string.

                  if (s1[i] != ' ' && s1[i] != ',')

                  {

                        s2[j++] = s1[i];

                  }

            }

           

// Insert the null character.

            s2[j] = '\0';

            // Update the values.

            i++;

            j = 0;

            // Check the value of the flag.

            if (flag == 1)

            {

                  // Start the loop till end of the string.

                  while (s1[i] != '\0')

                  {

                        // Enter the characeter in the new string.

                        if (s1[i] != ' ')

                        {

                              s3[j++] = s1[i];

                        }

                        i++;

                  }

                  // Insert the null character.

                  s3[j] = '\0';

                  // Display the strings.

                  printf("First word: %s", s2);

                  printf("\nSecond word: %s", s3);

            }

            // Otherwise, display the error message.

            else

            {

                  printf("Error: No comma in string.");

            }

            // Prompt the user to enter another string.

            printf("\n\nEnter input string:\n");

            getline(&s1, &size, stdin);

      }

}