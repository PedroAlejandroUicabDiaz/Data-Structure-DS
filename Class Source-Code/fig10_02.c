/* Fig. 10.2: fig10_02.c
   Using the structure member and 
   structure pointer operators */
#include <stdio.h>

struct card { 
   char *face;
   char *suit;
};

int main()
{ 
   struct card a;
   struct card *aPtr;

   a.face = "Ace";
   a.suit = "Spades";
   aPtr = &a;
   printf( "%s%s%s\n%s%s%s\n%s%s%s\n", 
          a.face, " of ", a.suit,
          aPtr->face, " of ", aPtr->suit,
          ( *aPtr ).face, " of ", ( *aPtr ).suit );
   return 0;
}



/**************************************************************************
 * (C) Copyright 2000 by Deitel & Associates, Inc. and Prentice Hall.     *
 * All Rights Reserved.                                                   *
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