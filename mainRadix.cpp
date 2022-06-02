#include "radix.h"
int main()
{
    int array[10] = {};
    int n;
    readFile(array, &n);
    printArray(array, n);
    radixSort(array, n);
    printArray(array, n);
    return 0;
}