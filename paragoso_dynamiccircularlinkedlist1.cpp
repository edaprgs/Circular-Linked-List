/* Eda Grace J. Paragoso
CCC-CS2A - Laboratory Seat Exercise #1 */

#include <iostream>

using namespace std;

struct link
{
    int value;
    link *nextlink;
};

int main()
{
    // to create the first link as the head of the list
    link* firstlink = new link;

    firstlink->value = 1;
    firstlink->nextlink = NULL;

    link* temp = firstlink;

    int i;
    int N = 3;

    // a loop for the circular linked list
    for (i=2; i<=N; i++)
    {
        // allocating a memory space for the link list
        link* newlink = new link;

        newlink->value = i;
        newlink->nextlink = firstlink;

        temp->nextlink = newlink;

        temp = newlink;
    }

    // set the temp to the firstlink so we can start displaying from the first link
    temp = firstlink;

    // to display the links
    for (i=0; i<N*N+1; i++)
    {
        cout << temp->value << " ";
        temp = temp->nextlink;
    }

    // set the temp to the firstlink so we can start deleting from the first link
    temp = firstlink;

    // to deallocate the allocated memory
    for (i=0; i<N; i++)
    {
        link* deletelink = temp;
        temp = temp->nextlink;

        delete deletelink;
    }

    return 0;
}
