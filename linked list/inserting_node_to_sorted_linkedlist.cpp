/*
Given a sorted circular linked list, the task is to 
insert a new node in this circular list so that it remains a sorted circular linked list.
*/

// { Driver Code Starts
#include <bits/stdc++.h>
/* structure for a Node */
struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node *sortedInsert(struct Node *head, int x);

/* function to insert a new_Node in a list in sorted way.
   Note that this function expects a pointer to head Node
   as this can modify the head of the input linked list */

/* Function to print Nodes in a given linked list */
void printList(struct Node *start)
{
    struct Node *temp;

    if (start != NULL)
    {
        temp = start;
        do
        {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != start);
        printf("\n");
    }
}
/* Driver program to test above functions */
int main()
{
    int t, n, x;
    scanf("%d", &t);
    int arr;
    while (t--)
    {
        scanf("%d", &n);
        int list_size, i;

        /* start with empty linked list */
        struct Node *start = NULL;
        struct Node *temp, *r;

        /* Create linked list from the array arr[].
    Created linked list will be 1->2->11->56->12 */
        if (n > 0)
        {
            scanf("%d", &arr);

            temp = new Node(arr);
            start = temp;
            r = start;
        }
        for (i = 0; i < n - 1; i++)
        {
            scanf("%d", &arr);
            temp = new Node(arr);
            r->next = temp;
            r = r->next;
        }

        if (n > 0)
            temp->next = start;

        scanf("%d", &x);
        start = sortedInsert(start, x);
        printList(start);
        r = start;
        while (r != start->next)
        {

            temp = start;
            start = start->next;
            free(temp);
        }
        free(start);
    }
    return 0;
}
// } Driver Code Ends

// This function should return head of
// the modified list
Node *sortedInsert(Node *head, int data)
{
    Node *current = head;
    Node *new_node = new Node(data);

    if (head == NULL)
    {
        new_node->next = new_node;
        head = new_node;
        return new_node;
    }

    else if (head->data >= data)
    {
        while (current->next != head)
            current = current->next;
        current->next = new_node;
        new_node->next = head;
        head = new_node;
        return head;
    }

    else
    {
        while (current->next != head && current->next->data < data)
            current = current->next;
        new_node->next = current->next;
        current->next = new_node;
        return head;
    }
}