#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std; 
void display( int *val)
{
   cout << val;
   printf("\n");
}


int main()
{
    int val =12345;
    display(&val);
}
