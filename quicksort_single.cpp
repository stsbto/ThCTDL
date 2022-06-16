
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};
class List
{
public:
    Node *head;
    Node *tail;
    List()
    {
        this->head = NULL;
        this->tail = NULL;
    }
    void insert(int value)
    {

        Node *node = new Node(value);
        if (this->head == NULL)
        {
            this->head = node;
            this->tail = node;
        }
        else
        {

            this->tail->next = node;
            this->tail = node;
        }
    }
    void printList()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    Node *last_node()
    {
        Node *temp = this->head;
        while (temp != NULL && temp->next != NULL)
        {
            temp = temp->next;
        }
        return temp;
    }
    Node *parition(Node *first, Node *last)
    {
        Node *pivot = first;
        Node *front = first;
        int temp = 0;
        while (front != NULL && front != last)
        {
            if (front->data < last->data)
            {
                pivot = first;
                temp = first->data;
                first->data = front->data;
                front->data = temp;
                first = first->next;
            }
            front = front->next;
        }
        temp = first->data;
        first->data = last->data;
        last->data = temp;
        return pivot;
    }
    void quick_sort(Node *first, Node *last)
    {
        if (first == last)
        {
            return;
        }
        Node *pivot = this->parition(first, last);
        if (pivot != NULL && pivot->next != NULL)
        {
            this->quick_sort(pivot->next, last);
        }
        if (pivot != NULL && first != pivot)
        {
            this->quick_sort(first, pivot);
        }
    }
};
int main()
{
    List l;
    l.insert(41);
    l.insert(5);
    l.insert(7);
    l.insert(22);
    l.insert(28);
    l.insert(63);
    l.insert(4);
    l.insert(8);
    l.insert(2);
    l.insert(11);
    l.printList();
    l.quick_sort(l.head, l.last_node());
    l.printList();
    return 0;
}