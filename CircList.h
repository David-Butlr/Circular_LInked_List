/* CircList.h  Specifications and Base Class Definitions for Lab 3
   Header file for the base class Circular Linked List lab assignment
   Implements the Josephus problem as an abstract data type (ADT)
   These member names must be used in your class without modification.
*/

#ifndef CircList_H
#define CircList_H

struct node
{
    string info;                            // holds name of the prisoner
    node *link;                             // link points to the next node
};

class CircList
{
    // operator overloading for insertion & extraction streams
    friend ostream& operator<< (ostream &, const CircList & );
    friend istream& operator>> (istream &, CircList & );

    public:
        CircList();                         // constructor for linked list
        ~CircList();                        // destructor for linked list
        CircList(const CircList & source);  // copy constructor
        const CircList& operator= (const CircList &);  // * overload assignment op *

        void initializeList();              // initialize the list to an empty state.
        void addNode(string);               // adds a node with data name
        string deleteNthNode(int);          // deletes node every nth prisoner
        bool find(string);       		    // reset pointers based upon lottery
        string getLeader()const;            // gets the first prisoner in the list
        bool isEmpty() const;               // returns true if list is empty
        int size() const;                   // returns number of nodes in list
        // void printList(ostream &);          // temporary. not used in finished Lab 3
        // void readData(istream &);           // temporary. not used in finished Lab 3

   protected:
        node *first;                        // points to head of list in circ. order
        node *last;                         // points to last node (before first)
        int  count;                         // keeps count of # nodes in the list
        void copyList(const CircList &);    // a private copy function
     	void destroyList();                 // deletes the entire list
};

#endif
