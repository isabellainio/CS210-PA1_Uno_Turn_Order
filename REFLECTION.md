# Reflection Questions 

# 1. Why does concat only need to work between two lists of the same representation? What would you have to do differently, or what would go wrong, if you tried to make it work between a LinkedList and an ArrayList?

concat only works between two lists of the same representation because an ArrayList stores its elements in an array 
while a LinkedList stores them in connected nodes. In my code, I use dynamic_cast to check that the other list 
is the same type before accessing its data. 
If the types do not match, my program prints an error and returns without changing either list.

# 2. Walk through reverse() on your linked list: name the three pointers you need alive at once, and explain why losing track of any one of them mid-loop corrupts the list.

My LinkedList reverse uses three pointers: previous, current, and next. 
The next pointer saves where I need to go before I change current's next pointer to point backwards at previous. 
If I did not save next first, I could lose access to the rest of the linked list.

# 3. addAnywhere and deleteAnywhere both need a bounds check. What's the valid range for position in each, and what does your implementation do if a caller passes a position outside it?

For addAnywhere, a valid position is from 0 through size because an 
element can also be added at the very end. For deleteAnywhere, the valid positions are 0 through size - 1 because I can only delete an element that already exists. 
In my implementation, an invalid position prints "Invalid position." and returns without changing the list.

# 4. In LinkedList::concat, why did you need to walk to the end of the list first, when addFront and deleteFront never needed to? What would change about concat's performance if LinkedList still tracked a tail pointer, and what would you have to keep updated elsewhere if you added one back?

I have to walk through the LinkedList during concat because I only have a head pointer and need to find the final node before connecting the other list. 
addFront and deleteFront do not need this because they only work with the head. 
If I had a tail pointer, concat could access the end directly, but I would also have to make sure the tail was updated correctly whenever the list changed.

# 5. Pick either addAnywhere or deleteAnywhere in ArrayList and explain, in your own words, what has to shift and in which direction, and why shifting in the wrong direction would overwrite data you still need.

For my ArrayList addAnywhere, I shift the existing elements to the right to create an empty position for the new value. 
I start at the end of the list and move backwards toward the insertion position. 
If I started at the insertion position and shifted forward instead, I could overwrite an element before I had a chance to move it.

# 6. Point to the exact line in your main.cpp where a Reverse card actually changes the direction of play, and explain what would visibly break in the game if that call were missing.

The line that actually changes the turn order is table->reverse();. 
Isabella plays the Blue Reverse card right before this line, so reverse() makes the turn order match what happened in the game. 
Without this call, the Reverse card would print as being played, but the players would stay in the same order.