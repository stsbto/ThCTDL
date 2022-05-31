#include <iostream>
#pragma once
using namespace std;
class Node
{
public:
    int data;
    Node *prev;
    Node *next;
    Node(int data)
    {
        this->data = data;
        prev = NULL;
        next = NULL;
    }
};
class List
{
private:
    Node *head;
    Node *tail;

public:
    List()
    {
        head = NULL;
        tail = NULL;
    }
    void push_back(int data)
    {
        Node *n = new Node(data);
        if (head == NULL)
        {
            head = tail = n;
        }
        else
        {
            tail->next = n;
            n->prev = tail;
            tail = n;
        }
    }
    Node *getHead()
    {
        return head;
    }
    Node *getTail()
    {
        return tail;
    }
    void printList()
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void swapNode(Node *a, Node *b)
    {
        int data = a->data;
        a->data = b->data;
        b->data = data;
    }
    void interchangeSort()
    {
        cout << "interchangeSort: ";
        Node *pos = head;
        while (pos)
        {
            Node *jump = pos->next;
            while (jump)
            {
                if (pos->data > jump->data)
                {
                    swapNode(pos, jump);
                }
                jump = jump->next;
            }
            pos = pos->next;
        }
    }
    void selectionSort()
    {
        cout << "selectionSort: ";
        Node *temp = head;

        while (temp)
        {
            Node *pos = temp->next;
            if (!pos)
            {
                return;
            }
            Node *min = pos;
            while (pos)
            {
                if (min->data > pos->data)
                {
                    min = pos;
                }
                pos = pos->next;
            }
            swapNode(min, temp);
            temp = temp->next;
        }
    }
    void insertionSort()
    {
        cout << "insertionSort: ";
        Node *pos = head->next;
        while (pos)
        {
            Node *sorted = pos->prev;
            int data = pos->data;
            while (sorted && sorted->data > data)
            {
                sorted->next->data = sorted->data;
                sorted = sorted->prev;
            }
            if (sorted)
            {
                sorted->next->data = data;
            }
            else
            {
                head->data = data;
            }
            pos = pos->next;
        }
    }
    void quickSort(Node *left, Node *right)
    {
        if (left == right)
        {
            return;
        }
        Node *pivot = right;
        Node *i = left;
        Node *j = left;

        while (j != pivot)
        {
            if (j->data <= pivot->data)
            {
                swapNode(i, j);
                i = i->next;
            }
            j = j->next;
        }
        swapNode(i, pivot);
        if (i != left)
        {
            quickSort(left, i->prev);
        }
        if (i != right)
        {
            quickSort(i->next, right);
        }
    }
    void shellSort()
    {
        cout << "shellSort: ";
        int len, step = 0;
        Node *p = head;
        while (p)
        {
            len++;
            p = p->next;
        }
        while (2 * (3 * step + 1) < len)
        {
            step = 3 * step + 1;
        }
        for (step; step > 0; step /= 3)
        {
            for (int i = step; i > 0; i--)
            {
                for (int j = step - i; j < len; j += step)
                {
                    int k = 0;
                    Node *p = head;
                    while (k < j)
                    {
                        p = p->next;
                        k++;
                    }
                    Node *c = p;
                    int jump = k + step;
                    while (jump < len)
                    {
                        while (k < jump)
                        {
                            c = c->next;
                            k++;
                        }
                        if (c->data < p->data)
                        {
                            swapNode(c, p);
                        }
                        jump += step;
                    }
                }
            }
        }
    }
    void mergeSort()
    {
    }
};