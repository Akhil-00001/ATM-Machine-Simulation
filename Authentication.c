#include <stdio.h>
#include "Structure_Template.c"
int check(struct User t, int acc_no, int PIN)
{
    for (int i = 0; i < 10; i++)
    {

        if (acc_no == t.Acc_No)
        {
            if (t.PIN == PIN)
            {
                return 1;
            }
        }
    }
    return 0;
} 