/* Task description:
See the code below. The program builds a singly linked list from the content of the array, head points to the beginning of the list.

Write a loop that prints the values stored in the list! You should get this output:

27 18 7 4 22 6 10 9 15 2 11 3 5 16 19 1 17 13 14 8

Why are the values reversed?

*/


#include <stdlib.h>

typedef struct ListEl {
    int data;
    struct ListEl *nxt;
} ListEl;


/* creates a new list from the array elements */
ListEl *list_build(void) {
    int values[] = { 8, 14, 13, 17, 1, 19, 16, 5, 3, 11, 2,
                     15, 9, 10, 6, 22, 4, 7, 18, 27, -15 };
    ListEl *lis = NULL;

    int i;
    for (i = 0; values[i] > -1; ++i) {
        ListEl *u;
        u = (ListEl*) malloc(sizeof(ListEl));
        u->nxt = lis;
        u->data = values[i];
        lis = u;
    }
    return lis;
}


int main(void) {
    ListEl *head;
    
    head = list_build();
    
    //here print the list!
    
    return 0;   
}
