#include <stdio.h>
#include "Structure_Template.c"
struct User t;
int main()
{
    FILE *p = fopen("data.txt", "r");
    if (!p)
    {
        printf("File could not be opened.\n");
        return 1;
    }
    int i = 0;
    // Read until end of file or 10 records
    while (i++ < 10 && fscanf(p, "%d %d %d", &t.Acc_No, &t.PIN, &t.Balance) == 3)
    {
        printf("%d %d %d\n", t.Acc_No, t.PIN, t.Balance);
    }
    fclose(p);
    return 0;
}