# Lists

Object-Oriented Analysis & Design Discussion

1. DList Class Attributes:
	A. Templates: templates are being implemented to allow lists of any ADT to be used
	B. Structs: used to create NodeType pointers

2. DList Class Methods
	A. Private:
		I. location(): returns address of item being searched for. If not found , it returns null
		II. last(): returns location of current last item in list
		III. deleteLocation(): Location passed in is removed from list, length is decremented, and location is deallocated. 
Special cases handled for deleting only one item in list, the head item of list, and the tail item of list
	B. Public:
		I. makeEmpty(): All items in the list have been deallocated
		II. deleteItem(): Item that is passed in as a paramter is deleted if it exists in the list
		III. inList(): Returns true if the item passed in as a paramter is in the list
		IV. isEmpty(): Returns true if the list is empty, otherwise, it returns false
		V. print(): Prints the list
		VI. insertHead(): Item is added to the front of the list. The original first node is linked to new node, length is
incremented, and there is a special case for length being zero
		VII. appendTail(): Item is added to the back of the list. The original last node is linked to new node, length is
incremented, and there is a special case for length being zero
		VIII. lengthIs(): Returns the length of the list

3. The role of the move to front algorithm is so the user can see the items they most recently searched and 
so the program can search for those items more easily(like the google search bar)

4. The main algorithm calls a print method for the menu and calls the other methods in the client file depending on the user input. The
client program calls methods from the DList class to execute functions based on user input. Mainly, the client program uses Dlist class 
methods to can add items to the front and/or the end of a list, delete items from a list, print the list, print the length of the list,
and access items to the list(accessing an item in the list moves it to the front).
