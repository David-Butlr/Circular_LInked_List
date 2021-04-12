// CircListSorted.cpp (implementation file for the CircListSorted)

#include "CircListSorted.h"

void CircListSorted::sortCircList()   // sorts the circular linked list alphabetically
{
    node *curr = nullptr;   // declares a pointer called curr
    node *prev = nullptr;   // declares a pointer called prev
    bool swapped = true;    // initializes swapped to true

    // for loop that sorts the linked list
    for (int i = 0; swapped && i < size(); i++)
    {
        prev = first;       // assigns first to prev
        curr = first->link; // assigns the link following first, to curr
        swapped = false;    // sets swapped to false

        for(int j = 0; j < size() - i - 1; j++)
        {
            if (prev->info > curr->info)   // if statement that swaps the data in two nodes if one of them is not in the right place in the list
            {
                swapped = swapData(curr, prev); // calls sawpData and assigns the true to swapped
            }
            curr = curr -> link;    // advances curr to next node
            prev = prev -> link;    // advances prev to next node
        }
    }
}

bool CircListSorted::swapData(node *curr, node *prev)    // swapData is used to exchange all data between nodes and return true
{
     string temp;   // declares a temporary string to hold info from node
     temp = prev -> info;   // assigns info from node that prev is pointing to temp
     prev -> info = curr -> info;   // assigns info from node that curr is pointing at, to node that prev is pointing at
     curr -> info = temp;   // assigns temp to node that curr is pointing at
     return true;   // returns true
}
