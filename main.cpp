/*
	Input Validation with Ref Functions 
	Source: http://stackoverflow.com/questions/514420/how-to-validate-numeric-input-c

	Teacher: Dr. Tyson McMillan, Ph.D. COSC 1436 
  STUDENT (McMillanite): Chet Lockwood
  Purpose: First N Ordinals
  IDE: Repl.it
*/

#include <cstdlib>  // Provides EXIT_SUCCESS
#include <iostream>  // Provides cout, cerr, endl
#include "Input_Validation_Extended.h" // Provides getValidatedInput<T>(), a header File with a Template Class
#include <string> //for string manipulation
#include <sstream> //for string manipulation and comparison

string ordinal(int); //ordinal function prototype

//Main function *********************************************************************************************
int main() 
{
  int maxNum = -1; //user input variable

  //Color code variables, reset, and clear
  string cRed = "\x1b[1;91m";
  string cGreen = "\x1b[1;32m";
  string cUnderL = "\x1b[4m";
  string cReset = "\x1b[0m";
  string cClear = "\033[2J\033[1;1H";
  
  //Prompt user for a number to give ordinals up to
  cout << cUnderL << "Input a number to find out the ordinals up to it" << cReset << endl;

  //Input: receive input, validate, and prevent a negative number from stopping the program
  while (maxNum < 0)
  {
  validateInt(maxNum);
  }
  
  //for loop to output numbers up to and including the number given by the user *****************************
  for (int i = 0; i <= maxNum; i++)
  {
    //output of ordinals (using ordinal function) of numbers except for 11, 12, 13 in all cases
    if (i % 100 < 11 || i % 100 > 13)
    cout << "\n" << cRed << i << cReset << ordinal(i % 10) << " Hello" << endl;

    //output of ordinals for 11, 12, 13 in all places
    else
    cout << "\n" << cRed << i << cReset << cGreen << "th" << cReset << " Hello" << endl;
  }
  return 0;
}

//string passing function for the ordinals*******************************************************************
string ordinal(int n)
{
  if (n == 0 || n > 3)
  {
    return "\x1b[1;32mth\x1b[0m";
  }
  else if (n == 1)
  {
    return "\x1b[1;93mst\x1b[0m";
  }
  else if (n == 2)
  {
    return "\x1b[1;34mnd\x1b[0m";
  }

  return "\x1b[1;36mrd\x1b[0m";
}