#include <iostream>
#include <fstream>
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
    int getMax()
    {
        Node *temp = head;
        int max = temp->data;

        while (temp != NULL)
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
    // 56  78  12  36  199 14  67  62
    void countingSort(int place)
    {
        int count[10] = {};
        int *output = new int[100]; // list

        for (Node *i = head; i != NULL; i = i->next)
        {
            count[(i->data / place) % 10]++;
        }
        for (int i = 1; i <= 9; i++)
        {
            count[i] = count[i] + count[i - 1];
        }
        for (Node *i = tail; i != NULL; i = i->prev)
        {
            output[count[(i->data / place) % 10] - 1] = i->data;
            count[(i->data / place) % 10]--;
        }
        Node *temp = head;
        for (int i = 0; i < getLenght(); i++)
        {
            temp->data = output[i];
            temp = temp->next;
        }
    }
    void radixSort()
    {
        for (int place = 1; 199 / place > 0; place *= 10)
        {
            countingSort(1000);
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
    l.radixSort();
    cout << "radixSort: " << endl;
    l.printList();
    writeFile(l);
    return 0;
}