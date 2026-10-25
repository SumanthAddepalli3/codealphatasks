#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store account details
typedef struct {
    int accountNo;
    char accountHolderName[50];
    float accountBalance;
} Account;

#define MAX_ACCOUNTS 100

Account accounts[MAX_ACCOUNTS];
int totalAccounts = 0;

// Function declarations
void createAccount();
void depositMoney();
void withdrawMoney();
void checkBalance();
void displayAllAccounts();

int main() {
    int menuChoice;

    while (1) {
        printf("\n=== BANKING SYSTEM MANAGEMENT ===");
        printf("\n1. Create New Account");
        printf("\n2. Deposit Money");
        printf("\n3. Withdraw Money");
        printf("\n4. Check Balance");
        printf("\n5. Display All Accounts");
        printf("\n6. Exit");
        printf("\nEnter your choice (1-6): ");

        if (scanf("%d", &menuChoice) != 1) {
            printf("\nInvalid input! Please enter a number.\n");
            return 1;
        }

        switch (menuChoice) {
            case 1:
                createAccount();
                break;
            case 2:
                depositMoney();
                break;
            case 3:
                withdrawMoney();
                break;
            case 4:
                checkBalance();
                break;
            case 5:
                displayAllAccounts();
                break;
            case 6:
                printf("\nThank you for using the Banking System!\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }

    return 0;
}

void createAccount() {
    if (totalAccounts >= MAX_ACCOUNTS) {
        printf("\nBank capacity reached. Cannot create more accounts.\n");
        return;
    }

    Account account;

    printf("\nEnter Account Number: ");
    if (scanf("%d", &account.accountNo) != 1) {
        printf("\nInvalid account number!\n");
        return;
    }

    // Check for duplicate account numbers
    for (int index = 0; index < totalAccounts; index++) {
        if (accounts[index].accountNo == account.accountNo) {
            printf("\nError: Account number already exists!\n");
            return;
        }
    }

    printf("Enter Account Holder Name: ");
    getchar();

    if (fgets(account.accountHolderName,
              sizeof(account.accountHolderName), stdin) == NULL) {
        printf("\nError reading account holder name!\n");
        return;
    }

    account.accountHolderName[
        strcspn(account.accountHolderName, "\n")] = '\0';

    printf("Enter Initial Deposit Amount: ");
    if (scanf("%f", &account.accountBalance) != 1) {
        printf("\nInvalid deposit amount!\n");
        return;
    }

    if (account.accountBalance < 0) {
        printf("\nInitial deposit cannot be negative!\n");
        return;
    }

    accounts[totalAccounts] = account;
    totalAccounts++;

    printf("\nAccount created successfully!\n");
}

void depositMoney() {
    int searchAccountNo;
    float depositAmount;

    printf("\nEnter Account Number: ");
    if (scanf("%d", &searchAccountNo) != 1) {
        printf("\nInvalid account number!\n");
        return;
    }

    for (int index = 0; index < totalAccounts; index++) {
        if (accounts[index].accountNo == searchAccountNo) {
            printf("Enter Amount to Deposit: ");

            if (scanf("%f", &depositAmount) != 1) {
                printf("\nInvalid amount!\n");
                return;
            }

            if (depositAmount <= 0) {
                printf("\nAmount must be greater than zero.\n");
                return;
            }

            accounts[index].accountBalance += depositAmount;

            printf("\nSuccessfully deposited $%.2f."
                   " New Balance: $%.2f\n",
                   depositAmount,
                   accounts[index].accountBalance);
            return;
        }
    }

    printf("\nAccount not found!\n");
}

void withdrawMoney() {
    int searchAccountNo;
    float withdrawalAmount;

    printf("\nEnter Account Number: ");
    if (scanf("%d", &searchAccountNo) != 1) {
        printf("\nInvalid account number!\n");
        return;
    }

    for (int index = 0; index < totalAccounts; index++) {
        if (accounts[index].accountNo == searchAccountNo) {
            printf("Enter Amount to Withdraw: ");

            if (scanf("%f", &withdrawalAmount) != 1) {
                printf("\nInvalid amount!\n");
                return;
            }

            if (withdrawalAmount <= 0) {
                printf("\nAmount must be greater than zero!\n");
                return;
            }

            if (withdrawalAmount >
                accounts[index].accountBalance) {
                printf("\nInsufficient balance!"
                       " Current Balance: $%.2f\n",
                       accounts[index].accountBalance);
                return;
            }

            accounts[index].accountBalance -= withdrawalAmount;

            printf("\nSuccessfully withdrew $%.2f."
                   " New Balance: $%.2f\n",
                   withdrawalAmount,
                   accounts[index].accountBalance);
            return;
        }
    }

    printf("\nAccount not found!\n");
}

void checkBalance() {
    int searchAccountNo;

    printf("\nEnter Account Number: ");
    if (scanf("%d", &searchAccountNo) != 1) {
        printf("\nInvalid account number!\n");
        return;
    }

    for (int index = 0; index < totalAccounts; index++) {
        if (accounts[index].accountNo == searchAccountNo) {
            printf("\n--- Account Details ---");
            printf("\nAccount Number: %d",
                   accounts[index].accountNo);
            printf("\nHolder Name   : %s",
                   accounts[index].accountHolderName);
            printf("\nBalance       : $%.2f\n",
                   accounts[index].accountBalance);
            return;
        }
    }

    printf("\nAccount not found!\n");
}

void displayAllAccounts() {
    if (totalAccounts == 0) {
        printf("\nNo accounts registered in the system.\n");
        return;
    }

    printf("\n==================================================");
    printf("\n%-15s %-20s %-10s",
           "Acc Number", "Name", "Balance");
    printf("\n==================================================");

    for (int index = 0; index < totalAccounts; index++) {
        printf("\n%-15d %-20s $%-10.2f",
               accounts[index].accountNo,
               accounts[index].accountHolderName,
               accounts[index].accountBalance);
    }

    printf("\n==================================================\n");
}