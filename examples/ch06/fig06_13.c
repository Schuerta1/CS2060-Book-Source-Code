// Fig. 6.13: fig06_13.c
// Passing arrays and individual array elements to functions.
#include <stdio.h>
#define SIZE 5
#define ROWS 3
#define COLS 4

// function prototypes
void modifyArray(int b[], size_t size);
void modifyElement(int e);               
void printArray(const int b[], size_t size);
void init2dArray(int b[ROWS][COLS]);
void print2DArray(const int b[][COLS], size_t sizeRows, size_t sizeCols);

// function main begins program execution
int main(void)
{
   int a[SIZE] = { 0, 1, 2, 3, 4 }; // initialize array a
   int b[ROWS][COLS]; // declare array b

   //Print memory address
   printf("Value of '&a[0]': %p\n", &a[0]);
   printf("Value of '&a': %p\n", &a);
   printf("Value of 'a': %p\n\n", a);


   puts("Effects of passing entire array by reference:\n\nThe "
      "values of the original array are:");

   // output original array
   for (size_t i = 0; i < SIZE; ++i) { 
      printf("%3d", a[i]);
   } 

   puts(""); // outputs a newline

   modifyArray(a, SIZE); // pass array a to modifyArray by reference                         
   puts("The values of the modified array are:");

   // output modified array
   for (size_t i = 0; i < SIZE; ++i) {
      printf("%3d", a[i]);
   } 

   // output value of a[3]
   printf("\n\n\nEffects of passing array element "
      "by value:\n\nThe value of a[3] is %d\n", a[3]);
   
   modifyElement(a[3]); // pass array element a[3] by value

   // output value of a[3]
   printf("The value of a[3] is %d\n\n", a[3]);

   //Print array contents
   printArray(a, SIZE);

   //Tell user to set 2D array
   init2dArray(b);
   print2DArray(b, ROWS, COLS);
   puts("");
}

// in function modifyArray, "b" points to the original array "a" 
// in memory                                                     
void modifyArray(int b[], size_t size)                               
{                                                                   
   // multiply each array element by 2                         
   for (size_t j = 0; j < size; ++j) {                                 
      b[j] *= 2; // actually modifies original array               
   }                                                 
} 

// in function modifyElement, "e" is a local copy of array element
// a[3] passed from main                                     
void modifyElement(int e)                                       
{                                                                 
   // multiply parameter by 2                                  
   printf("Value in modifyElement is %d\n", e *= 2);            
} 

// in function printArray, "b" points to the original array "a" 
// in memory. Principle of least privilege: array is const and thus not modifiable                                  
void printArray(const int b[], size_t size)
{            
    printf("%s", "Array contents:");
    for (unsigned int i = 0; i < size; i++) {
        printf(" [%d]", b[i]);
    }
    puts("");
}

// in function init2dArray, "b" points to the original 2d array "b" 
// in memory. 
void init2dArray(int b[ROWS][COLS])
{
    int scanRtn = 0;
    int userInput = 0;
    for (unsigned int i = 0; i < ROWS; i++) {
        for (unsigned int j = 0; j < COLS; j++) {
            do {
                printf("Row %u Col %u Value = ", i, j); //Ask user for value
                scanRtn = scanf("%d", &userInput);
                while (getchar() != '\n'); //Clear input buffer
            } while (scanRtn != 1);
            b[i][j] = userInput;
        }
    }
}

// in function print2DArray, "b" points to the original array b" 
// in memory. Principle of least privilege: array is const and thus not modifiable                                  
void print2DArray(const int b[][COLS], size_t sizeRows, size_t sizeCols)
{
    puts("Array contents:");
    for (unsigned int i = 0; i < sizeRows; i++) {
        for (unsigned int j = 0; j < sizeCols; j++) {
            printf("[%d]\t", b[i][j]);
        }
        puts(""); //newline aka next row
    }
}
                          




/**************************************************************************
 * (C) Copyright 1992-2015 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 *************************************************************************/

