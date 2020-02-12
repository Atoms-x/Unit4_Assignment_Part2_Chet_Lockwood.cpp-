//From: http://stackoverflow.com/questions/514420/how-to-validate-numeric-input-c 
#include <ios>  // Provides ios_base::failure
#include <iostream>  // Provides cin
#include<string> //for string manipulation
#include<sstream> //for string manipulation and comparison
using namespace std; 

//Function Prototypes
int validateInt(int &); //use the validation method to vaildate and return a data type integer pass by reference &
double validateDouble(double &); //use the validation method to vaildate and return a data type double pass by reference &
char validateChar(char &); //use the validation method to vaildate and return a data type char pass by reference &
string validateString(string &); //use the validation method to vaildate and return a data type string pass by reference &

//color code global variables and clear
   string cRed = "\x1b[1;91m";
   string cGreen = "\x1b[1;32m";
   string cYellow = "\x1b[1;93m";
   string cBlue = "\x1b[1;34m";
   string cOrange = "\x1b[1;33m";
   string cCyan = "\x1b[1;36m";
   string cPurple = "\x1b[1;35m";
   string cItalic = "\x1b[3m";
   string cUnderL = "\x1b[4m";
   string cReset = "\x1b[0m";

template <typename T>
T getValidatedInput()
{
    // Get input of type T
    T result;
    cin >> result;

    // Check if the failbit has been set, meaning the beginning of the input
    // was not type T. Also make sure the result is the only thing in the input
    // stream, otherwise things like 2b would be a valid int.
    if (cin.fail() || cin.get() != '\n')
    {
        // Set the error state flag back to goodbit. If you need to get the input
        // again (e.g. this is in a while loop), this is essential. Otherwise, the
        // failbit will stay set.
        cin.clear();

        // Clear the input stream using and empty while loop.
        while (cin.get() != '\n')
            ;

        // Throw an exception. Allows the caller to handle it any way you see fit
        // (exit, ask for input again, etc.)
        throw ios_base::failure("\x1b[1;91m Invalid input. \x1b[0m");
    }

    return result;
}

//Function Definitions
int validateInt(int &intInput)
{
	while (true)
    {
        
        try
        {
            intInput = getValidatedInput<int>();
        }
        catch (exception e)
        {
            cerr << e.what() << cRed << " -INVALID INPUT-"<< cReset << endl;
            continue;
        }

        break;
    }
    
    return intInput; 
}

double validateDouble(double &doubleInput)
{
	while (true)
    {
        
        try
        {
            doubleInput = getValidatedInput<double>();
        }
        catch (exception e)
        {
            cerr << e.what() << cRed << " -INVALID INPUT-"<< cReset << endl;
            continue;
        }

        break;
    }
    
    return doubleInput; 
}

char validateChar(char &charInput)
{ 
    while (true)
    {
    
        try
        {
            charInput = getValidatedInput<char>();
        }
        catch (exception e)
        {
            cerr << e.what() << cRed << " -INVALID INPUT-"<< cReset << endl;
            continue;
        }

        break;
    }
    
    return charInput; 
}

string validateString(string &stringInput)
{
    while (true) //use cin, getline() for this 
    {
       
        try
        {
            stringInput  = getValidatedInput<string>();
        }
        catch (exception e)
        {
            cerr << e.what() << cRed << " -INVALID INPUT-"<< cReset << endl;
            continue;
        }

        break;
    }
    
    return stringInput; 
}
