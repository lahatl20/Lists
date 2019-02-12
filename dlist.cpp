#include <cstddef> 
#include <iostream>

using namespace std;

template<class ItemType>
struct NodeType
{
	ItemType info;
	NodeType<ItemType>*	next;
	NodeType<ItemType>*	back;
};

template <class ItemType>		
DList<ItemType>::DList()		// Class constructor
{
    length = 0;
    head = NULL;
}

template <class ItemType>
DList<ItemType>::~DList   ()		
{
	// Post: List is empty; All items have been deallocated.
  makeEmpty();
}

template <class ItemType>
void DList<ItemType>::makeEmpty()
{
    // Post: List is empty; all items have been deallocated.
    for(int i = 0; i < length; i++)
    {
      deleteLocation(head);
    }
    head = NULL;
}

template <class ItemType>
void DList<ItemType>::deleteItem (ItemType item)	
{
	//  Pre :  item to be deleted is passed in via parameter 
        // Post :  item is deleted if it exists in list 
 
  deleteLocation(location(item));
}

template <class ItemType>
bool DList<ItemType>::inList (ItemType item) const
{
	//  Pre :  item to be located is passed in via parameter 
        // Post :  function returns bool value if item is found 
  return(location(item) != NULL);

}

template <class ItemType>
bool DList<ItemType>::isEmpty() const		
{
	// Post : function returns true if list is empty, false otherwise
  return (length == 0);
}

template <class ItemType>
void DList<ItemType>::print() const	
{
	// Pre  : List is not empty 
	// Post : Items in List have been printed to screen
  NodeType<ItemType>* temp = new NodeType<ItemType>;
  temp = head;

  cout << "Printing the list:\n";
  for(int i = 0; i < length; i++)
  {
    cout << temp -> info << "\n";
    temp = temp -> next;
  }

}
	
template <class ItemType>
void DList<ItemType>::insertHead(ItemType item)	
{
	//  Pre : item to be inserted is passed in via parameter
        // Post : item is inserted at head of list;  Former first node is 
        //        linked back to this new one via double link;
        //        Length incremented;  Special case handled if list is empty 
        
  NodeType<ItemType>* newNode = new NodeType<ItemType>;
  
  newNode -> info = item;
  newNode -> back = NULL;
  
  if(head == NULL)
    newNode -> next = NULL;
  else
  {
    head -> back = newNode;
    newNode -> next = head;
  }
  
  head = newNode;  length++;
	
}

template <class ItemType>
void DList<ItemType>::appendTail(ItemType item)
{
	//  Pre :  item to be inserted is passed in via parameter
        // Post :  item is added to tail of list; Former last node
        //         is linked to this new one via double link 

  NodeType<ItemType>* newNode = new NodeType<ItemType>;
  
  newNode -> info = item;
  newNode -> next = NULL;
  
  if(head == NULL)
    newNode -> back = NULL;
  else
  {
    newNode -> back = last();
    newNode -> back -> next = newNode;
  }
  length++;
}

template <class ItemType>
int DList<ItemType>::lengthIs() const	
{
	// Post : Function returns current length of list  
 return length;
}

template <class ItemType>
NodeType<ItemType>* DList<ItemType>::location(ItemType item) const	
{
	//  Pre : item to be located is passed in via parameter 
        // Post : function returns address of item being searched for --
        //        if not found, NULL is returned

  NodeType<ItemType>* temp = new NodeType<ItemType>;
  temp = head;
  
  for(int i = 0; i < length; i++)
  {
    if(temp -> info == item)
    {
      return temp;
    }
    else
      temp = temp -> next;   
  }
  
  return NULL;
}

template <class ItemType>
NodeType<ItemType>* DList<ItemType>::last() const	
{
	// Post : Function returns location of current last item in list
  if(length == 0)
    return NULL;
  else
  {
    NodeType<ItemType>* temp = new NodeType<ItemType>;
    temp = head;
  
    for(int i = 1; i < length; i++)
    {
      temp = temp -> next;
    }
    
    return temp;
  }
}

template <class ItemType>
void DList<ItemType>::deleteLocation (NodeType<ItemType>* delPtr)	
{

	//  Pre : Item to be deleted exits in list and its location
        //        is passed in via parameter
                   
	// Post : Location passed in is removed from list;  Length
        //        is decremented, and location is deallocated 

        // Special Cases Handled for Deleting Only One Item in List,
        // The Head Item of List, and the Tail Item of List
  NodeType<ItemType>* temp = new NodeType<ItemType>;
  
  if(length == 1)
  {
    head = NULL;
    delete delPtr;
  }
  else if(head == delPtr)
  {
    delPtr -> next -> back = NULL;
    head = delPtr -> next;
    delete delPtr;
  }
  else if(delPtr -> next == NULL)
  {
    delPtr -> back -> next = NULL;
    delete delPtr;
  }
  else
  {
    delPtr -> next -> back = delPtr -> back;
    delPtr -> back -> next = delPtr -> next;
    delete delPtr;
  }
  length--;
}
