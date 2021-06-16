#include <stdio.h>
#include <stdlib.h>
#include  <string.h>
typedef struct list
{
    char bookname[100];9
    int id;
    char author[100];
    float price;
} List;

struct listNode
{
    List l;
    struct listNode *nextPtr;
};
typedef struct listNode ListNode;
typedef ListNode *ListNodePtr;


char delete(ListNodePtr *sPtr, int id);
void FreeData();
void Reset();
ListNodePtr startPtr = NULL; // initially there are no nodes

// delete a list element
char delete(ListNodePtr *sPtr, int id)

    if (id == (*sPtr)->l.id)
    {
        ListNodePtr tempPtr = *sPtr; // hold onto node being removed
        *sPtr = (*sPtr)->nextPtr; // de-thread the node
        free(tempPtr); // free the de-threaded node
        return id;
    }
    else
    {
        ListNodePtr previousPtr = *sPtr;
        ListNodePtr currentPtr = (*sPtr)->nextPtr;

// loop to find the correct location in the list
        while (currentPtr != NULL && currentPtr->l.id != id)
        {
            previousPtr = currentPtr;  // walk to ...
            currentPtr = currentPtr->nextPtr; // ... next node
        }

// delete node at currentPtr
        if (currentPtr != NULL)
        {
            ListNodePtr tempPtr = currentPtr;
            previousPtr->nextPtr = currentPtr->nextPtr;
            free(tempPtr);
            return id;
        }
    }
    return '\0';
}

void FreeData()
{
    if (startPtr == NULL)
    {
        printf("\n\t\t\tlinked list is empty.\n");
    }
    else
    {
        ListNode* first_book = startPtr;
        startPtr = startPtr->nextPtr;
        free(first_book);
    }
}

void Reset()
{
    do
    {
        FreeData();
    }
    while(startPtr != NULL);
    system("cls");
    headMessage("MAIN MENU");
    printf("\n\n\t\t\tSystem has been reseted\n");
    system("pause");
    system("cls");
}
