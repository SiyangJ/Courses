#include <cctype>

using namespace std;

bool anyUppercase(const char a[], int n)
{
    if (n<=0)
        return false;
    else if (n==1)
        return isupper(a[0]);
    return (anyUppercase(a, n/2) || anyUppercase(a+n/2, n-n/2));
}

int countUppercase(const char a[], int n)
{
    if (n<=0)
        return 0;
    else if (n==1)
        return isupper(a[0]);
    return countUppercase(a, n/2)+countUppercase(a+n/2, n-n/2);
}

int firstUppercase(const char a[], int n)
{
    if (n<=0)
        return -1;
    if (isupper(a[0]))
        return 0;
    return (firstUppercase(a+1, n-1)==-1 ? -1:1+firstUppercase(a+1, n-1));
}

int indexOfLeast(const char a[], int n)
{
    if (n<=0)
        return -1;
    if (n==1)
        return 0;
    int i1 = indexOfLeast(a, n/2);
    int i2 = indexOfLeast(a+n/2, n-n/2);
    if (a[i1]<=a[n/2+i2])
        return i1;
    else return i2+n/2;
}