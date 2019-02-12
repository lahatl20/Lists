#include <iostream>
#include <ctype.h>
#include <iomanip>
#include "dlist.h"
using namespace std;

void menu(char &user);
void HeadInsert(DList<int> &list);
void TailInsert(DList<int> &list);
void AccessItem(DList<int> &list);
void Delete(DList<int> &list);
void PrintList(DList<int> &list);
void PrintLength(DList<int> &list);
void FindandMove(DList<int> &list, int num);

int main()
{
  DList<int> list;
  char user;
  
  cout << "Welcome to the Adjustable List Program!\n\n";
  
  do
  {
    menu(user);
    switch(toupper(user))
    {
      case 'H': HeadInsert(list);  break;
      case 'T': TailInsert(list);  break;
      case 'A': AccessItem(list);  break;
      case 'D': Delete(list);  break;
      case 'P': PrintList(list);  break;
      case 'L': PrintLength(list);  break;
      case 'Q': cout << "\tExiting program...\n";  break;
      default: cout << "\tInvalid response. Try again.\n\n";
    }
    
  } while(toupper(user) != 'Q');

  return 0;
}

void menu(char &user)
{
  cout << "---------------------- Menu ----------------------\n";
  cout << "| H: Insert item at the head of the list" << setw(11) << "|\n";
  cout << "| T: Insert item at the end of the list" << setw(12) << "|\n";
  cout << "| A: Access an item in the list" << setw(20) << "|\n";
  cout << "| D: Delete an item or all items in the list" << setw(7) << "|\n";
  cout << "| P: Print the list" << setw(32) << "|\n";
  cout << "| L: Print the length of the list" << setw(18) << "|\n";
  cout << "| Q: Exit the program" << setw(30) << "|\n";
  cout << "--------------------------------------------------\n\n";
  cout << "Select an option above: ";
  cin >> user;
}

void HeadInsert(DList<int> &list)
{
  int num;
  do
  {
    cout << "Enter the number you wish to add at the front of the list: ";
    cin >> num;
    
    if(list.inList(num))
      cout << "This value is already in the list.\n\n";
  }while(list.inList(num));
  
  list.insertHead(num);
}

void TailInsert(DList<int> &list)
{
  int num;

  cout << "Enter the number you wish to add at the end of the list: ";
  cin >> num;
  
  if(list.inList(num))
    cout << "This value is already in the list.\n\n";
  else
    list.appendTail(num);
}

void AccessItem(DList<int> &list)
{
  int num;
  
  cout << "Enter the number you would like to access in the list: ";
  cin >> num;
  
  if(list.isEmpty())
    cout << "The list is empty.\n\n";
  else
  {
    if(list.inList(num))
      FindandMove(list, num);
    else
      cout << "This item is not in the list\n\n";
  }
}

void Delete(DList<int> &list)
{
  int num;
  
  if(list.isEmpty())
    cout << "The list is empty.\n\n";
  else
  {
    cout << "Enter the item you wish to delete: ";
    cin >> num;
    if(list.inList(num))
    {
      list.deleteItem(num);
      cout << "The item has been deleted from the list\n\n";
    }
    else
      cout << "Item is not in the list.\n";
  }
}

void PrintList(DList<int> &list)
{
  if(list.isEmpty())
    cout << "The list is empty.\n\n";
  else
    list.print();
}

void PrintLength(DList<int> &list)
{
  cout << "The length of the list is " << list.lengthIs() << "\n\n";
}

void FindandMove(DList<int> &list, int num)
{
  list.deleteItem(num);
  list.insertHead(num);
  cout << "Item has been found and moved to the front.\n\n";
}