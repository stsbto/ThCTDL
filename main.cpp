#include "list.h"
#include "readwrite.h"
int main()
{
    List l;
    readFile(l);
    l.printList();
    // l.selectionSort();
    // l.insertionSort();
    // l.quickSort(l.getHead(), l.getTail());
    // l.shellSort();
    l.shakerSort();
    // l.radixSort();
    l.printList();
    writeFile(l);
    return 0;
}