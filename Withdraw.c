#include <stdio.h>
#include "Authentication.c"
struct User s1[10];

void withdraw(int idx){
    FILE *p = fopen("data.txt", "r");
    if (!p){
        printf("Memory Not Allocated.");
        return;
    }
    // Read all users from file (text mode)
    int count = 0;
    while (count < 10 && fscanf(p, "%d %d %d %s\n", &s1[count].Acc_No, &s1[count].PIN, &s1[count].Balance, s1[count].name) == 4){ 
        count++;
    }
    fclose(p);

    int money;
    printf("How much money do you want to withdraw : ");
    scanf("%d", &money);

    if (idx < 0 || idx >= count){
        printf("Invalid user index.\n");
        return;
    }
    if (s1[idx].Balance < money){
        printf("Insufficient balance.\n");
        return;
    }
    s1[idx].Balance -= money;

    // Write all users back to file (overwrite)
    p = fopen("data.txt", "w");
    if (!p) {
        printf("Could not open file for writing.\n");
        return;
    }
    for (int i = 0; i < count; i++){
        fprintf(p, "%d %d %d %s\n", s1[i].Acc_No, s1[i].PIN, s1[i].Balance, s1[i].name);
    }
    fclose(p);
    printf("Account Holder : %s\n", s1[idx].name);
    printf("The Balance is : %d\n", s1[idx].Balance);
    printf("Transaction successful.\nPlease collect receipt.\n");
}
