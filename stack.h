#ifndef STACK_H
#define STACK_H
#include <iostream>
using namespace std;

// Stack template
template <typename T>
class Stack
{
private:
   // Structure for the stach nodes
   struct StackNode
   {
      T value;          // Value in the node
      StackNode *next;  // Pointer to next node
   };

   StackNode *top;     // Pointer to the stack top

public:
   //Constructor
   Stack()
   { top = NULL; }

   // Destructor
   ~Stack();

   // Stack operations
   void push(T);
   void pop(T &);
   void peek(T &);
   bool find(T);
   bool isEmpty();
};

//***************************************************
//  Destructor                                      *
//***************************************************
template <typename T>
Stack<T>::~Stack()
{
   StackNode *nodePtr, *nextNode;

   // Position nodePtr at the top of the stack.
   nodePtr = top;

   // Traverse the list deleting each node.
   while (nodePtr != NULL)
   {
      nextNode = nodePtr->next;
      delete nodePtr;
      nodePtr = nextNode;
   }
}

//*************************************************************
// Member function push pushes the argument onto              *
// the stack.                                                 *
//*************************************************************

template <typename T>
void Stack<T>::push(T item)
{
   StackNode *newNode = NULL; // Pointer to a new node

   // Allocate a new node and store num there.
   newNode = new StackNode;
   newNode->value = item;

   // If there are no nodes in the list
   // make newNode the first node.
   if (isEmpty())
   {
      top = newNode;
      newNode->next = NULL;
   }
   else  // Otherwise, insert NewNode before top.
   {
      newNode->next = top;
      top = newNode;
   }
}

template <typename T>
bool Stack<T>::find(T item)
{
   StackNode *tempNode = NULL; // Pointer to a new node

   tempNode = top;
   if(!isEmpty())
   {
       while(tempNode)
       {
           if(tempNode->value == item)
               return true;
           else
               tempNode = tempNode->next;
       }
   }

   return false;
}

//*************************************************************
// Member function pop pops the value at the top              *
// of the stack off, and copies it into the variable          *
// passed as an argument.                                     *
//*************************************************************

template <typename T>
void Stack<T>::pop(T &item)
{
   StackNode *temp = NULL; // Temporary pointer

   // First make sure the stack isn't empty.
   if (isEmpty())
   {
      cout << "The stack is empty.\n";
   }
   else  // pop value off top of stack
   {
      item = top->value;
      temp = top->next;
      delete top;
      top = temp;
   }
}

template <typename T>
void Stack<T>::peek(T &item)
{
    // First make sure the stack isn't empty.
   if (isEmpty())
   {
      cout << "The stack is empty.\n";
   }
   else  // peek value off top of stack
   {
      item = top->value;
   }
}

//*************************************************************
// Member function isEmpty returns true if the stack          *
// is empty, or false otherwise.                              *
//*************************************************************

template <typename T>
bool Stack<T>::isEmpty()
{
   bool status;

   if (!top)
      status = true;
   else
      status = false;

   return status;
}
#endif
