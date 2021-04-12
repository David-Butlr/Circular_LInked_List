// CircList.cpp (implementation file for the CircList)

#include "CircList.h"

// default constructor
CircList::CircList()
{
    first = nullptr;                // set first pointer to nullptr
    last = nullptr;                 // set last pointer to nullptr
    count = 0;                      // zero's the count
}


// destructor destroys all nodes that were allocated
CircList::~CircList()
{
   destroyList();                   // calls the private destroyList function
   // cout << "List is destroyed...." << endl << endl; // commented out because it was for demonstration only
}//end destructor


// copy constructor creates a "deep copy" of the other list
CircList::CircList(const CircList & otherList)
{
   	first = nullptr;                // sets first pointer to nullptr
    copyList(otherList);            // calls copyList to get deep copy of otherList
}//end copy constructor


//overloads the assignment operator
const CircList & CircList::operator= (const CircList & otherList)
{
    if (this != &otherList)         // if statement to prevent overwriting the original list
    {
        copyList(otherList);        // calls the copyList function
    }
     return *this;                  // now, left side has the assigned list
}


void CircList::initializeList()
{
	destroyList();                  // calls destroyList
}


// implies building the list from left to right (newest last)
void CircList:: addNode(string item) // building the list "forwards"
{
    node *newNode;                  //pointer to create the new node
    newNode = new node;             //creates the new node

    newNode->info = item;           //stores the new item in the node
    newNode->link = nullptr;        //sets the link field of newNode to nullptr

    if (first == nullptr)           //if list is empty, newNode is both first & last node
    {
        first = newNode;            //assign the new node pointer to first
        last = newNode;             //assign the new node pointer to last
        first -> link = first;      //makes link from first node, point to itself

    }
    else                         //the list is not empty, insert newNode after last
    {
        last -> link = newNode; //sets last link to the new node
        last = newNode;        //assigns last to newNode
        last -> link = first;  //sets last link pointing to the first
    }
    count++;                        // increments count
}//end insertLast


string CircList::deleteNthNode(int nth)  // function deletes the nth node and returns the name of the prisoner in that node
{
    string result;  // declares a string called result which will hold the deleted prisoners name
    node *curr = first; // initializes curr pointer to first
    node *prev = last;  // initializes prev pointer to last
    count --;   // decrements count


    if(first == nullptr)    // if statement to test if a list has anything in it
    {
        result = "Cannot delete from an empty list";    // assigns error message to result
        //return result;
    }
    else    // list is not empty
    {
        for (int i = nth-1; i > 0; i--)  // for loop to find nth node to delete
        {
            prev = prev -> link;    // advances prev
            curr = curr -> link;    // advances curr
        }
        result = curr -> info;      // assigns name of prisoner to be deleted, to result

        if(curr == first)   // if statement to check if node to be deleted is the first node
        {
            first = curr->link; // assigns link following curr to fist
        }
        else    // node to be deleted is not the first node
        {
            if(curr == last) // if statement to check if curr is the same as last
            {
                last = prev;    // assigns prev to last
            }
        }
        prev -> link = curr ->link; // sets prev link to point at the same thing as curr link
        first = prev -> link;   // sets first to prev link
        last = prev;    // sets last to prev
        delete curr;    // deallocates memory that curr is pointing at
        curr = nullptr; // sets curr pointer to null pointer
    }
    return result;  // returns prisoners name

}//end deleteNode


bool CircList::find(string name)  // reset pointers based upon name to start lottery
{
    string temp;    // declares temp
    bool answer = false; // initializes answer to true
    node *curr = first;  // declares curr pointer and sets it to first
    node *prev = last;  // declares prev pointer and sets it to last
    int counter = 0;    // initializes counter to 0

    while (answer == false && counter < 12)  // while loop to search list for name
    {
        temp = curr -> info;    // assigns curr info to temp
        if (temp == name)   // if statement, to set up list correctly if name is found
        {
            first = curr;   // sets first to curr
            last = prev;    // sets last to prev
            answer = true;  // sets answer to true
        }
        else    // name was not found in curr node so advance to next one
        {
            curr = curr -> link;    // advances curr
            prev = prev -> link;    // advances prev
            counter ++;  // increments counter
        }
    }

    if (answer != true) // if statement to display error message if name is not found
    {
        cout << " Name To Find Does Not Exist!! \n\n";  // displays error message to console
    }

    return answer;  // returns answer
}


// returns data at the head of the list
string CircList::getLeader() const
{
    assert(first != nullptr);       //error if the list is empty
    return first->info;             //return info of the first node
}//end front


bool CircList::isEmpty() const  // function to test if list is empty
{
    return(count == 0);
}


// size gets the size of the list
int CircList::size() const
{
    return count;                   // returns the # of nodes in the list
}


void CircList::destroyList()    // function to deallocate all the nodes in the list
{
    node *temp;    //declares temp pointer
    int pNum = 1;   // initializes pNum to 1

    while (count != 0)        //while there are nodes in the list
    {
        temp = first;               //set temp to the first node
        first = first->link;        //advance first to the next node
        delete temp;                //deallocate the memory occupied by temp
        cout << "prisoner " << setw(2) <<  pNum++ << " destroyed." << endl; // displays prisoner number deleted, to the console
        count--;                    //decrements count
    }
    last = nullptr;                 //initialize last to nullptr;
    count = 0;                      // zero the count
}


// makes a "deep copy" of the list
void CircList::copyList(const CircList & otherList)
{
    node *newNode;                  // local pointer to create a node
    node *current;                  // local pointer to traverse the list

    if (first != nullptr)           // if the list is not empty
    {
        destroyList();               // empty the list
    }


    if (otherList.first == nullptr) // otherList is empty
    {
        first = nullptr;            //reset pointers
        last = nullptr;             //  "      "
        count = 0;                  // zero the count
    }
    else                            // the otherList must have data
    {
        current = otherList.first;  // current points to the list to be copied
        count = otherList.count;    // set count equal to the same size as otherList

        //this section copies only the first node
        first = new node;           // create (allocate) the node

        first->info = current->info;// copy the info
        last = first;               // make last point to the first node
        last->link = last;          // circular list of 1 node
        first -> link = first;      // circular list of 1 node
        current = current->link;    // make current point to the next node

        //copy the remaining list
        while (current != otherList.first)
        {
            newNode = new node;     // create (allocate) the node
            newNode->info = current->info;  // copy the info
            newNode->link = first;  // set the link of newNode to first
            last->link = newNode;   // attach newNode after last
            last = newNode;         // make last point to the actual last node
            current = current->link;// make current point to the next node
        }
    }
}

// overloads insertion operator
istream& operator>> (istream & in, CircList &  obj)
{
    node *curr = nullptr;			// declare local current pointer
	string name;					// declare local data variable

    // read 1st item in the list to "prime the pump"
    in >> name;    				// read the first prisoner name
    while(in)   // while loop to read all data in
    {
        obj.addNode(name);  //calls add node function to add name to a new node
        in >> name; // read in next prisoner name
    }
    return in;  // returns input stream
}

// overloads extraction operator
ostream& operator<< (ostream & out, const CircList & obj)
{
    node *current;                  //pointer to traverse the list
    current = obj.first;                //set current so that it points to first node

    do  // do-while loop that outputs all data and stops when it reaches the beginning of the list
    {
        out << current->info << setw(8);   //view the data
        current = current->link;    // advance current pointer
    }while(current != obj.first);
    out << endl;    // outputs an end line
    return out; // returns output stream
}


//not used in final of lab 3, was instructed to comment this out
// non-class version reads data from file, creates single linked list. readData has one param.
//void CircList::readData(istream & in)
//{
//	node *curr = nullptr;			// declare local current pointer
//	string name;					// declare local data variable
//
//     read 1st item in the list to "prime the pump"
//    in >> name;    				// read the first prisoner
//    while(in)
//    {
//        addNode(name);
//        in >> name;
//    }
//}

//not used in final of lab 3, was instructed to comment this out
//// print simply prints first item, traverses, and repeats until the end is reached
//void CircList::printList(ostream & out)
//{
//    node *current;                  //pointer to traverse the list
//    current = first;                //set current so that it points to first node
//
//    do{
//        out << current->info << " ";   //view the data
//        current = current->link;    // advance current pointer
//    }while(current != first);
//    out << endl;
//}//end print
