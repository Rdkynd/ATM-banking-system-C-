/*
 * File    : atm_banking_system.c
 * Author  : Arda
 * Created : 23.01.2026
 * Desc    :
 */

#include <stdio.h>
#include <stdlib.h>
#define INITIAL_BALANCE 1500.00
#define MAX_CHOICE 4
#define MIN_CHOICE 1
#define MIN_AMOUNT 0.0
int main()
{

    double balance = INITIAL_BALANCE;
    double amount;
    int option = 0;
    while (option != 4)
    {
        printf("Welcome to the Arda ATM.");
        printf("\n---- MENU ----");
        printf("\n1 - Balance Inquiry\n2 - Deposit Money\n3 - Withdraw Money\n4 - Exit");
        
        do
        {
            printf("\nSelect an option: ");
            scanf(" %d", &option);
            if(option < MIN_CHOICE || option > MAX_CHOICE) 
                printf("\nInvalid selection. Please choose between 1 and 4.");
            
        } while (option < MIN_CHOICE || option > MAX_CHOICE);
        
        

        switch (option)
        {
        case 1:
            printf("\nCurrent Balance: %.2lf", balance);
            break;
        case 2:
            do
            {

                printf("\nEnter amount to deposit: ");
                scanf("%lf", &amount);
                if (amount <= MIN_AMOUNT)

                    printf("\nInvalid amount. Enter a positive value.");

            } while (amount <= MIN_AMOUNT);
            balance += amount;
            printf("\nDeposit successful. New balance: %.2lf", balance);
            break;
        case 3:
            do
            {
                printf("\nEnter amount to withdraw: ");
                scanf("%lf", &amount);
                if (amount <= MIN_AMOUNT)

                    printf("\nInvalid amount. Enter a positive value.");
                else if (amount > balance)
                    printf("\nInsufficient balance;");

            } while (amount <= MIN_AMOUNT || amount > balance);
            balance -= amount;
            printf("\nWithdraw successful. New balance: %.2lf", balance);
        case 4:
            printf("\nThank you for using the ATM.");            
        }
    }
    return 0;
}