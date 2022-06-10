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

    void selectionSort()
    {
        for (Node *i = head; i != tail; i = i->next)
        {
            Node *min = i;
            for (Node *j = i->next; j != NULL; j = j->next)
            {
                if (min->data > j->data)
                {
                    min = j;
                }
            }
            swapNode(i, min);
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
    l.selectionSort();
    cout << "selectionSort: " << endl;
    l.printList();
    writeFile(l);
    return 0;
}