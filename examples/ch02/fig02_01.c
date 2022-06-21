// Fig. 2.1: fig02_01.c
// A first program in C 
#include <stdio.h>

// function main begins program execution 
int main( void )
{
	int length = 0;
	int width = 0;
	unsigned int area = 0;
    int scanRtn = 0;
    int divResult = 0;
    //Multiplication
    do {
        puts("Enter the length\n");
        scanRtn = scanf("%d", &length);
        while (getchar() != '\n'); //Clear input buffer
    } while (scanRtn != 1 && length >= 0); 

    do {
        puts("Enter the width\n");
        scanRtn = scanf("%u", &width);
        while (getchar() != '\n'); //Clear input buffer
    } while (scanRtn != 1 && width >= 0);

    area = length * width;
    printf("Length: %u width: %u and area is %u\n", length, width, area);

    //Division
    if (width != 0) {
        divResult = length / width;
        printf("Quotient: %d Remainder: %d\n", divResult, length - (width * divResult));
    }
    else {
        puts("Width value is 0. Cannot divide\n");
    }
    return 0;
} // end function main 


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
