#include <stdio.h>
#define MAXLINE 100
#define COL 6
#define FIL 6
#include "repaso.h"

int main()
{
    int a[10] = {1,3,5};
    int b[10] = {0,3,5};
    int ce1 = 3;
    int ce2 = 3;
    void* c = a;
    void* d = b;
    void *pi = unionVectores(c,ce1,d,ce2,sizeof(int),cmp);
    free(pi);
    return 0;
}
