#include <iostream>
#include <fstream>
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
    int getLength()
    {
        int len = 0;
        for (Node *i = head; i != NULL; i = i->next)
        {
            len++;
        }
        return len;
    }
    void shellSort()
    {
        int len = getLength();
        int step = 0;
        Node *temp = head;
        while (2 * (3 * step + 1) <= len)
        {
            step = 3 * step + 1; // step = 4
        }
        for (step; step > 0; step = step / 3)
        {
            for (int i = step; i > 0; i--) //
            {
                for (int j = step - i; j < len; j = j + step)
                {
                    Node *p = head;
                    int k = 0;
                    for (k = 0; k < j; k++)
                    {
                        p = p->next;
                    }
                    Node *c = p;
                    int temp = k + step;
                    for (temp; temp < len; temp += step)
                    {
                        for (k; k < temp; k++)
                        {
                            c = c->next;
                        }
                        if (c != NULL)
                        {
                            if (c->data <= p->data)
                            {
                                swapNode(c, p);
                            }
                        }
                    }
                }
            }
        }
    }
};
void readFile(List &l)
{
    cout << "Da doc file txt: " << endl;
    int data;
    ifstream myfile("./input.txt");
    while (!myfile.eof())
    {
        myfile >> data;
        l.push_back(data);
    }
    myfile.close();
}
void writeFile(List &l)
{
    ofstream myfile("output.txt");
    Node *temp = l.getHead();
    while (temp)
    {
        myfile << temp->data << " ";
        temp = temp->next;
    }
    myfile.close();
}
int main()
{
    List l;
    readFile(l);
    l.printList();
    l.shellSort();
    cout << "shellSort: " << endl;
    l.printList();
    writeFile(l);
    return 0;
}