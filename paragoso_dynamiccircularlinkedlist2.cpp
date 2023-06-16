/* Eda Grace J. Paragoso
CCC-CS2A - Laboratory Seat Exercise #1 */

/* A circular linked list where all links are connected and the last link points to the first  link. */

#include <iostream>                   // a preprocessor directive that includes iostream header file that contains definition of objects like cin and cout

using namespace std;                  // the identifiers of the c++ standard library are defined in a namespace called std

struct link                           // to group several related variables into one place
{
    int value;          // A link has a data, so we declare variable value
    link *nextlink;     // A circular linked list contains a link to the next link called nextlink
};

int main()              // Starting point for program execution
{
    // to create the firstlink, we separate this from the loop because we need to use it later to keep track of the linked list's execution
    link* firstlink = new link;     // allocate memory for firstlink

    firstlink->value = 1;    // to assign a value of the firstlink
    firstlink->nextlink = NULL;     // assigning NULL since the firstlink is not yet linked to the next link

    // to temporarily store the address of the firstlink to pointer temp
    link* temp = firstlink;

    // initializing variables
    int i;
    int N = 3;  // to assign how many times the loop will create a link

    // a loop for the circular linked list
    for (i=2;   // initializing a variable and is executed only once
    i<=N;       // if the condition is true the body of the for loop is executed
    i++)        // increments the value of the variable i by one and checks the condition for the next iteration
    {
        link* newlink = new link;   // allocating a memory for a new link

        newlink->value = i;     // the newlink is assigned a value

        // we set the nextlink of the newlink to the firstlink because we want to create a circular linked list
        // only the last link will have its nextlink set to the firstlink, the rest links will be set to the next link in the list
        newlink->nextlink = firstlink;

        // set the nextlink of the previous link(temp) to the new link
        temp->nextlink = newlink;

        // set the temp to the newlink so we can use it in the next iteration
        temp = newlink;
    }

    // set the temp to the firstlink so we can start displaying from the firstlink
    temp = firstlink;

    // to display the links
    for (i=0;   // starts from the first iteration and is executed only once
    i<N*N+1;    // checks the condition and if it is true the body of the for loop is executed
    i++)        // i is incremented by one
    {
        cout << temp->value << " "; // displays the value of the link
        temp = temp->nextlink;      // temp is assigned to the nextlink for it to be displayed in the next iteration
    }

    // set temp to the firstlink so we can start deleting from the firstlink
    temp = firstlink;

    for (i=0;   // starts from the first iteration and is executed only once
    i<N;        // checks the condition and if it is true the body of the for loop is executed
    i++)        // i is incremented by one
    {
        // to create a deletelink pointer to store the temp ptr
        link* deletelink = temp;
        
        temp = temp->nextlink;
        
        delete deletelink;
    }

    return 0;   // terminates the execution of main function
}
