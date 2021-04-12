/*---------------------------------|
David Butler                       |
CSC 210                            |
4/4/2019                           |
This program uses a circular linked|
list to display a rigged lottery   |
and writes the results to a file   |
----------------------------------*/

#include <iostream> //used to access input and output stream
#include <cassert>  //used for the assert
#include <fstream>  //used for file input and output stream
#include <stdlib.h> //used for std library
#include <iomanip>  //used for output manipulation
#include <ctime>    //used for getting time
#include <string>   //used for string options

using namespace std;
#include "Circlist.cpp"         //implementation file used to create our object
#include "CircListSorted.cpp"   //implementation file that performs sorting of our object

ifstream fin ("CircInput.txt");    //input file
ofstream fout("CircOutput.txt");   //output file

void title(string &myName);     //function that prints out the title and stores a name to the variable myName
void date(string &myName);      //function that gets the date and prints it
void originalList (CircListSorted &list1, CircListSorted &list2, string msg);   //function that prints the two original list
void process(CircListSorted list2, int numDelete, string name);     //function that performs all processing for the lottery and prints results


int main()
{
    string myName;      //declares a string variable that holds myName to be used in the title function and for the math in the date function
    CircListSorted list1, list2;     //creates two objects
    fin >> list1;      // reads in all data from input file and assigns it to list 1, the insertion operator is overloaded in the implementation file
    list2 = list1;     // assigns values from list 1 to list 2, the = operator is overloaded in the implementation file
    title(myName);     // calls title function
    date(myName);      // calls date function
    originalList(list1, list2, "Main original unsorted ");  // calls originalList function the first time
    process(list2, 2, "Baker");     // calls process function the first time
    cout << "\n\n";     // displays to end lines
    process(list1, 7, "Kiley");     // calls process function the second time
    cout << "\n\n";     // displays to end lines
    originalList(list1, list2, "Main original ");   // calls originalList function the second time
    fin.close();
    fout.close();

   return 0;
}


void title(string &myName)
{
    myName = "David Butler";    // assigns my name to the myName variable

    //prints title to console
    cout << "A   C I R C U L A R L Y   L I N K E D   L I S T   ( T H E   J O S E P H U S   P R O B L E M )" << "\n\n";
    cout << "Twelve prisoners are captured and put into a cave.  They form a circle and choose who starts."
         << endl << "A lottery is made to skip some prisoners and determine who is to be executed. Counting right,"
         << endl << "every prisoner that reaches this multiple must be executed.   A mutual agreement is made that"
         << endl << "the last remaining prisoner must commit suicide. However, the last prisoner decides to escape"
         << endl << "by stealing a horse.   This deviously rigged lottery and escape is planned by Josephus.  This"
         << endl << "C++ program will simulate two of Josephus' devious plans and map each result to console/file.";
    cout << endl << endl;
    cout << setw(45) << "By" << "\n\n";
    cout << setw(50) << myName << "\n\n";   // prints myName to console


    //writes title to the output file
    fout << "A   C I R C U L A R L Y   L I N K E D   L I S T   ( T H E   J O S E P H U S   P R O B L E M )" << "\n\n";
    fout << "Twelve prisoners are captured and put into a cave.  They form a circle and choose who starts."
         << endl << "A lottery is made to skip some prisoners and determine who is to be executed. Counting right,"
         << endl << "every prisoner that reaches this multiple must be executed.   A mutual agreement is made that"
         << endl << "the last remaining prisoner must commit suicide. However, the last prisoner decides to escape"
         << endl << "by stealing a horse.   This deviously rigged lottery and escape is planned by Josephus.  This"
         << endl << "C++ program will simulate two of Josephus' devious plans and map each result to console/file.";
    fout << endl << endl;
    fout << setw(45) << "By" << "\n\n";
    fout << setw(50) << myName << "\n\n";   // writes myName to output file
}


void date(string &myName)
{
    time_t t = time(0);     // declares a variable to access time
    struct tm * timeStruct = localtime(&t); // declares a struct pointer that points at the local time
    int month = timeStruct->tm_mon+1;   // initializes month to hold the number of the month
    string dmonth = "empty";    // intializes dmonth with empty which will later hold the month and the rest of the date
    int counter = 0;        // initalizes counter with 0 which later will help with calculating the centering of the date

    // switch statement to help change month from number to name of month
    switch (month)
    {
        case 1:
                dmonth = "January";   // assigns January to dmonth if month is 1
                break;
        case 2:
                dmonth = "February";  // assigns February to dmonth if month is 2
                break;
        case 3:
                dmonth = "March";     // assigns March to dmonth if month is 3
                break;
        case 4:
                dmonth = "April";     // assigns April to dmonth if month is 4
                break;
        case 5:
                dmonth = "May";       // assigns May to dmonth if month is 5
                break;
        case 6:
                dmonth = "June";      // assigns June to dmonth if month is 6
                break;
        case 7:
                dmonth = "July";      // assigns July to dmonth if month is 7
                break;
        case 8:
                dmonth = "August";    // assigns August to dmonth if month is 8
                break;
        case 9:
                dmonth = "September"; // assigns September to dmonth if month is 9
                break;
        case 10:
                dmonth = "October";   // assigns October to dmonth if month is 10
                break;
        case 11:
                dmonth = "November";  // assigns November to dmonth if month is 11
                break;
        case 12:
                dmonth = "December";  // assigns December to dmonth if month is 12
                break;
    }

    // assigns the whole date to dmonth including day, month, and year;
    dmonth =  "Current Date: " + dmonth + " " + to_string(timeStruct->tm_mday) + ", " +  to_string(timeStruct->tm_year + 1900) + "\n\n";

    // takes length of dmonth - myName and then divides it by 2, this is the equation that determines the centering of the date
    counter =  (dmonth.length() - myName.length())/2;

    // for loop, that adds the necessary spaces to dmonth in order to center the date
    for (int i = 0; i < 39-counter; i++)
    {
        dmonth = " " + dmonth;  // adds spaces to dmonth which contains the date
    }
    cout << dmonth; // displays date to console
    fout << dmonth; // writes date to the output file
}


void originalList (CircListSorted &list1, CircListSorted &list2, string msg)
{
        // displays original list 1 to the console
       cout << msg << "list1. List size = " << list1.size() << endl
            << "---------------------------------------------------------------------------------------------" << endl
            << list1
            << "---------------------------------------------------------------------------------------------" << "\n\n";

        // displays original list 2 to the console
       cout << msg << "list2. List size = " << list2.size() << endl
            << "---------------------------------------------------------------------------------------------" << endl
            << list2
            << "---------------------------------------------------------------------------------------------" << "\n\n";

        // writes original list 1 to the output file
       fout << msg << "list1. List size = " << list1.size() << endl
            << "---------------------------------------------------------------------------------------------" << endl
            << list1
            << "---------------------------------------------------------------------------------------------" << "\n\n";

        // writes original list 2 to the output file
       fout << msg << "list2. List size = " << list2.size() << endl
            << "---------------------------------------------------------------------------------------------" << endl
            << list2
            << "---------------------------------------------------------------------------------------------" << "\n\n";
}


void process(CircListSorted list2, int numDelete, string name)
{
    static int counter = 1; // initializes counter which keeps track of which lottery it's processing
    bool answer = true;    // initializes answer which determines whether the lottery can be processed
    string holdName;       // declares holdName which holds the name of people being deleted

    list2.sortCircList();  // sorts the list for the lottery

    // displays the sorted list to the console
    cout << "Sorted copy of list2. List size = " << list2.size() << endl
         << "---------------------------------------------------------------------------------------------" << endl
         << list2
         << "---------------------------------------------------------------------------------------------" << "\n\n";
    // writes the sorted list to the output file
    fout << "Sorted copy of list2. List size = " << list2.size() << endl
         << "---------------------------------------------------------------------------------------------" << endl
         << list2
         << "---------------------------------------------------------------------------------------------" << "\n\n";


    answer = list2.find(name);  // assigns the decision of whether the lottery can be processed, to answer

    // if statement, to check if lottery can be processed
    if (answer == true)
    {
        // displays where the starting point for the lottery is, to the console
        cout << "Lottery #" << counter << " starts with " << name << " and eliminates multiples of " << numDelete
             << " prisoners. List size = " << list2.size() << endl
             << "---------------------------------------------------------------------------------------------" << endl
             << list2
             << "---------------------------------------------------------------------------------------------" << "\n\n";

        // writes where the starting point for the lottery is, to the output file
        fout << "Lottery #" << counter << " starts with " << name << " and eliminates multiples of " << numDelete
             << " prisoners. List size = " << list2.size() << endl
             << "---------------------------------------------------------------------------------------------" << endl
             << list2
             << "---------------------------------------------------------------------------------------------" << "\n\n";

        // for loop to complete all but the last lines of the lottery
        for (int i = 0; i < 10; i++)
        {
            holdName = list2.deleteNthNode(numDelete);  // assigns the deleted prisoners name to  holdName

            // displays the list and deleted prisoners to the console
            cout << holdName << " is deleted. List size = " << list2.size() << endl
                 << "---------------------------------------------------------------------------------------------" << endl
                 << list2
                 << "---------------------------------------------------------------------------------------------" << "\n\n";

            // writes the list and deleted prisoners to the output file
            fout << holdName << " is deleted. List size = " << list2.size() << endl
                 << "---------------------------------------------------------------------------------------------" << endl
                 << list2
                 << "---------------------------------------------------------------------------------------------" << "\n\n";
        }

        holdName = list2.deleteNthNode(numDelete);  // assigns the deleted prisoners name to  holdName

        // displays the last line of the lottery to the console
        cout << holdName << " is deleted. List size = " << list2.size() << endl
             << "---------------------------------------------------------------------------------------------" << endl
             << list2
             << "---------------------------------------------------------------------------------------------" << "\n\n"
             << "Josef is the remaining prisoner that escapes on his horse!" << "\n\n";

        // writes the last line of the lottery to the output file
        fout << holdName << " is deleted. List size = " << list2.size() << endl
             << "---------------------------------------------------------------------------------------------" << endl
             << list2
             << "---------------------------------------------------------------------------------------------" << "\n\n"
             << "Josef is the remaining prisoner that escapes on his horse!" << "\n\n";
    }

    counter ++; // increments counter
}
