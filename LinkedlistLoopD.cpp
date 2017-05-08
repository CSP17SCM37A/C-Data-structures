// C++ program to detect and remove loop
#include<bits/stdc++.h>
using namespace std;
 
struct Node
{
    int key;
    struct Node *next;
};
 
Node *newNode(int key)
{
    Node *temp = new Node;
    temp->key = key;
    temp->next = NULL;
    return temp;
}
 
// A utility function to print a linked list
void printList(Node *head)
{
    while (head != NULL)
    {
        cout << head->key << " ";
        head = head->next;
    }
    cout << endl;
}
 
void detectAndRemoveLoop(Node *head)
{
    Node *slow = head;
    Node *fast = head->next;
 //cout<<slow->key<<" "<<fast->key<<"\n";
    // Search for loop using slow and fast pointers
    while (fast && fast->next)
    {
        if (slow == fast)
            break;
            cout<<slow->key<<" "<<fast->key<<"\n";
        slow = slow->next;
        fast = fast->next->next;
    }
 cout<<slow->key<<" "<<fast->key<<"\n";
    /* If loop exists */
    if (slow == fast)
    {
        slow = head;
        while (slow != fast->next)
        {   cout<<" h  "<<slow->key<<" "<<fast->key<<"\n";
            slow = slow->next;
            fast = fast->next;
            cout<<" h  "<<slow->key<<" "<<fast->key<<"\n";
        }
 
        /* since fast->next is the looping point */
        fast->next = NULL; /* remove loop */
    }
}
 
/* Driver program to test above function*/
int main()
{
    Node *head = newNode(50);
    head->next = newNode(20);
    head->next->next = newNode(15);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(10);
    head->next->next->next->next->next = newNode(8);
 
    /* Create a loop for testing */
    head->next->next->next->next->next->next = head->next->next;
 
    detectAndRemoveLoop(head);
 
    printf("Linked List after removing loop \n");
    printList(head);
 
    return 0;
}
