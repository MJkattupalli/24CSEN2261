#include <stdio.h>
#include <string.h>

struct Account {
    int accountNumber;
    char name[50];
    float balance;
};

void createAccount(struct Account *acc) {
    printf("Enter account number: ");
    scanf("%d", &acc->accountNumber);
    printf("Enter account holder name: ");
    getchar(); // To clear the newline character from input buffer
    fgets(acc->name, 50, stdin);
    acc->name[strcspn(acc->name, "\n")] = '\0'; // Removing the newline character from name
    acc->balance = 0;
    printf("Account created successfully.\n");
}

void deposit(struct Account *acc) {
    float amount;
    printf("Enter amount to deposit: ");
    scanf("%f", &amount);
    acc->balance += amount;
    printf("Deposit successful. Current balance: %.2f\n", acc->balance);
}

void withdraw(struct Account *acc) {
    float amount;
    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);
    if (amount <= acc->balance) {
        acc->balance -= amount;
        printf("Withdrawal successful. Current balance: %.2f\n", acc->balance);
    } else {
        printf("Insufficient balance!\n");
    }
}

void displayAccount(struct Account acc) {
    printf("\nAccount Details:\n");
    printf("Account Number: %d\n", acc.accountNumber);
    printf("Account Holder: %s\n", acc.name);
    printf("Balance: %.2f\n", acc.balance);
}

int main() {
    struct Account acc;
    int choice;

    while (1) {
        printf("\nBank Management System\n");
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. View Account\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount(&acc);
                break;
            case 2:
                deposit(&acc);
                break;
            case 3:
                withdraw(&acc);
                break;
            case 4:
                displayAccount(acc);
                break;
            case 5:
                printf("Exiting system.\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}
