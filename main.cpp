#include "list.h"
#include "finout.h"

int main()
{
    List l;
    readFile(l);
    l.printList();

    // l.insertionSort();
    // l.selectionSort();
    // l.insertionSort();
    // l.quickSort(l.getHead(), l.getTail());
    l.shellSort();

    l.printList();
    return 0;
}