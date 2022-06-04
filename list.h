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
        int len, step = 0;
        Node *temp = head;
        while (temp)
        {
            len++;
            temp = temp->next;
        }
        while (2 * (3 * step + 1) <= len)
        {
            step = 3 * step + 1;
        }
        for (step; step > 0; step /= 3)
        {
            for (int i = step; i > 0; i--)
            {
                for (int j = step - i; j < len; j += step)
                {
                    Node *p = head;
                    int k = 0;
                    while (k < j)
                    {
                        p = p->next;
                        k++;
                    }
                    Node *c = p;
                    int temp = k + step;
                    while (temp <= len)
                    {
                        while (k < temp)
                        {
                            c = c->next;
                            k++;
                        }
                        if (c != NULL)
                        {
                            if (c->data <= p->data)
                            {
                                swapNode(c, p);
                            }
                        }
                        temp += step;
                    }
                }
            }
        }
    }
    int getMax()
    {
        Node *temp = head;
        int max = temp->data;

        while (temp)
        {
            if (max < temp->data)
            {
                max = temp->data;
            }
            temp = temp->next;
        }
        return max;
    }
    int getLenght()
    {
        Node *temp = head;
        int len = 0;
        while (temp)
        {
            len++;
            temp = temp->next;
        }
        return len;
    }
    void countingSort(int place)
    {
        Node *temp = head;
        const int max = 10;
        int count[max] = {};
        int output[getLenght()];
        while (temp)
        {
            count[(temp->data / place) % 10]++;
            temp = temp->next;
        }
        for (int i = 1; i < max; i++)
        {
            count[i] += count[i - 1];
        }
        temp = tail;
        while (temp)
        {
            output[count[(temp->data / place) % 10] - 1] = temp->data;
            count[(temp->data / place) % 10]--;
            temp = temp->prev;
        }
        temp = head;
        for (int i = 0; i < getLenght(); i++)
        {
            temp->data = output[i];
            temp = temp->next;
        }
    }
    void radixSort()
    {
        for (int place = 1; getMax() / place > 0; place *= 10)
        {
            countingSort(place);
        }
    }
};