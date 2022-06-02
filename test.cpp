#include <iostream>
using namespace std;
void chagne(int *n)
{
    *n = 3;
}
int main()
{
    int a = 4;
    chagne(&a);
    cout << a;
    return 0;
}