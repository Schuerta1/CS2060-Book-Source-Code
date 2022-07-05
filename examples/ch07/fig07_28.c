// Fig. 7.28: fig07_28.c
// Demonstrating an array of pointers to functions.
#include <stdio.h>
#include <stdbool.h>

// prototypes
float add(double a, double b);
float subtract(double a, double b);
float multiply(double a, double b);
float divide(double a, double b);

int main(void)
{
    // initialize array of 3 pointers to functions that each take an
    float (*f[4])(double, double) = { add, subtract, multiply, divide };
    float funcReturn = 0;
    size_t choice; // variable to hold user's choice
    double num1 = 0;
    double num2 = 0;
    bool programDone = false;
    unsigned int scanReturn = 0;

    // process user's choice
    while (!programDone){
        do {
            printf("%s", "Enter 0 (+), 1 (-), 2 (*), 3 (/), 4 to end: ");
            scanReturn = scanf("%llu", &choice);
        } while (scanReturn != 1 || choice <0 || choice > 4);
        while (getchar() != '\n'); //Clear input buffer
        if (choice != 4) {
            do {
                puts("Enter 2 values: ");
                scanReturn = scanf("%lf %lf", &num1, &num2);
            } while (scanReturn != 2);
            funcReturn = (*f[choice])(num1, num2);
            printf("Result: %f\n", funcReturn);
        }
        while (getchar() != '\n'); //Clear input buffer
    }
   puts("Program execution completed.");
} 

float add(double a, double b) //Add
{
    return a + b;
}

float subtract(double a, double b) //subtract
{
    return a - b;
}

float multiply(double a, double b) //multiply
{
    return a * b;
}
float divide(double a, double b) //divide
{
    return a/b;
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

