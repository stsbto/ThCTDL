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
    void printList()
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
    void swapNode(Node *a, Node *b)
    {
        int data = a->data;
        a->data = b->data;
        b->data = data;
    }
    void interchangeSort()
    {
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
};