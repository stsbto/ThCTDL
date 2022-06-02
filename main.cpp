#include "list.h"
#include "finout.h"
int main()
{
    List l;
    readFile(l);
    l.printList();
    l.printList();
    // l.insertionSort();
    // l.selectionSort();
    // l.insertionSort();
    // l.quickSort(l.getHead(), l.getTail());
    // l.shellSort();
    // l.radixSort();
    // l.MergeSort(l.getHead());
    // l.printList();
    return 0;
}