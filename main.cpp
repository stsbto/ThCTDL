#include "list.h"
#include "data.h"
void root();
void pressAnykey();
int main()
{
    root();
    return 0;
}
void root()
{
    List l;
    readFile(l);
    l.printList();
    int key;
    while (true)
    {
        cout << endl
             << "Menu: " << endl;
        cout << "1. interchangeSort" << endl;
        cout << "2. selectionSort" << endl;
        cout << "3. insertionSort" << endl;
        cout << "4. quickSort" << endl;
        cout << "5. mergeSort" << endl;
        cout << "6. shellSort" << endl;
        cout << "7. radixSort" << endl;
        cout << "8. heapSort" << endl;
        cout << "9. shakerSort" << endl;
        cout << "lua chon: ";
        cin >> key;
        if (key == 1)
        {
            l.interchangeSort();
            cout << "1. interchangeSort: ";
        }
        else if (key == 2)
        {
            l.selectionSort();
            cout << "2. selectionSort: ";
        }
        else if (key == 3)
        {
            l.insertionSort();
            cout << "3. insertionSort: ";
        }
        else
        {
            break;
        }
        l.printList();
        pressAnykey();
    }
}

void pressAnykey()
{
    cout << endl;
    system("pause");
    system("cls");
}