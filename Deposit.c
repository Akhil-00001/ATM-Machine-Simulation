#include <stdio.h>
#include "Withdraw.c"
struct User s2[10];
void deposit(int idx){
    FILE *p = fopen("data.txt", "r");
    if (!p) {
        printf("Memory Not Allocated.");
        return; 
    }
    int count = 0;
    while (count < 10 && fscanf(p, "%d %d %d %s\n", &s2[count].Acc_No, &s2[count].PIN, &s2[count].Balance, s2[count].name) == 4){
        count++;
    }
    fclose(p);

    int money;
    printf("How much money do you want to Deposit : ");
    scanf("%d", &money);

    if (idx < 0 || idx >= count) {
        printf("Invalid user index.\n");
        return;
    }
    s2[idx].Balance += money;

    // Write all users back to file (overwrite)
    p = fopen("data.txt", "w");
    if (!p) {
        printf("Could not open file for writing.\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        // Example for writing user data
fprintf(p, "%d %d %d %s\n", s2[i].Acc_No, s2[i].PIN, s2[i].Balance, s2[i].name);
    }
    fclose(p);
    printf("Account Holder : %s\n", s2[idx].name);
    printf("Transaction successful.\nPlease collect receipt.\n");
    printf("The Balance is : %d\n", s2[idx].Balance);
}
