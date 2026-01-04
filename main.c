/*    
Problem Statement 51: ATM Machine Simulation
Develop a C program to simulate an ATM with user authentication and basic banking
transactions. The system should require users to authenticate using a PIN before accessing their
accounts. Key functionalities include balance inquiry, cash withdrawal, and deposit
transactions. File handling should be used to store and update user account details securely.
The program ensures data persistence and secure transaction processing for a realistic ATM
simulation.    
*/
#include <stdio.h>
// #include "User.h"
#include "Deposit.c"
// #include "Withdraw.c"
#include <string.h> 
struct User s[10];

int main(){
    // Reading 10 users from a text file
    FILE *p = fopen("data.txt", "r");
    if (!p)
    {
        printf("File could not be opened.\n");
        return 1;
    }
    for (int i = 0; i < 10; i++)
{
    if (fscanf(p, "%d %d %d %s\n", &s[i].Acc_No, &s[i].PIN, &s[i].Balance, s[i].name) != 4)
    {
        break; // Stop if less than 10 records or format error
    }
}
    fclose(p);
    printf("                                       *****Welcome To ATM*****\n");
    int acc_no;
    printf("Enter the Account Number : ");
    scanf("%d", &acc_no);

    int pin;
    int attempts = 0;
    int authenticated = 0;
    struct User t;
    int c = 0;
    int i;

    while (attempts < 3) {
        printf("Enter the PIN : ");
        scanf("%d", &pin);
        for (i = 0; i < 10; i++) {
            if (check(s[i], acc_no, pin)) {
                printf("\nLogin Successfull. Welcome, %s \n\n", s[i].name);
                t = s[i]; // Store the logged-in user data
                c = 1;
                authenticated = 1;
                break;
            }
        }
        if (authenticated) break;
        attempts++;
        if (attempts < 3)
            printf("Incorrect PIN. Try again. Attempts left: %d\n", 3 - attempts);
    }

    if (!authenticated) {
        printf("Account locked due to 3 incorrect PIN attempts.\n");
        return 0;
    }
    printf("What you want to do :\n1.Check Balace\n2.Withdraw Cash\n3.Deposit Cash\n4.Exit\n");
    int ch;
    printf("Enter Choice : ");
    scanf("%d", &ch);
    while (ch != 4)
    {
        if (ch == 1)
        {
            printf("Account Holder : %s\n", t.name);
            printf("The Balance is : %d\n", t.Balance);
            printf("Transaction completed\nPlease take your receipt\n");
            break;
        }
        else if (ch == 2)
        {
            withdraw(i);
            break;
        }
        else if (ch == 3)
        {
            deposit(i);
            break;
        }
        else
        {
            printf("Invalid Choice.");
            printf("Enter Choice : ");
            scanf("%d", &ch);
        }
    }
    printf("                                       Thank you. Visit again.");
    return 0;
}