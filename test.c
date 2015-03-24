#include<stdio.h>
#include<stdlib.h>
int main()
{
int ar[10];
int i;
for(i=0; i<10; i++)
        ar[i]=rand() % 33;

for(i=0; i<12; i++)
        printf("%d ", ar[i]);

return 0;
}

