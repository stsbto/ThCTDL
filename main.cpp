#include "list.h"
#include "finout.h"
int main()
{
    List l;
    readFile(l);
    l.printList();
    // l.selectionSort();
    // l.insertionSort();
    // l.quickSort(l.getHead(), l.getTail());
    // l.shellSort();
    l.radixSort();
    l.printList();
    writeFile(l);
    return 0;
}