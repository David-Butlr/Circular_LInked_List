// CircListSorted.h class header file (specification).
// derived from CircList class file

#ifndef H_List_Sorted
#define H_List_Sorted

class CircListSorted : public CircList
{
  public:
    void sortCircList();                // sorts the circular linked list alphabetically

  private:
   	bool swapData(node *, node *);      // swapData used to exchange all data between nodes
};
#endif
