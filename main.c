/*
made by : C PROGRAMMING

this is a very simple login system
it will create a new file for each user
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// our variables
char newAccount[20], first[20], last[20], age[20];

// welcome the user and give him the menu
void menu()
{
    printf("Hello and welcome to my application\n");
    printf("Enter 1 if you already have an account\n");
    printf("Enter 2 for create new account\n");
    printf("Enter -1 to exit\n");
}

// get the choice from the user
int choose()
{
    int input;
    printf("\nWhat do you want: ");
    scanf("%d", &input);

    return input;
}

// get the name of the account that user have
char * getAccount()
{
    char *account = (char *)malloc(20);
    printf("\nEnter the name of the account: ");
    scanf("%s", account);
    return account;
}

// read the file of the account
char * read(char *account)
{
    FILE *f = fopen(account, "r");
    // to get the numbers of bytes of the file
    fseek(f, 0, SEEK_END);
    unsigned int size = ftell(f);
    fseek(f, 0, SEEK_SET);

    char *data = (char *)malloc(size);

    fread(data, sizeof(char), size, f);
    return data;
}

void getNewAcc()
{
    printf("Enter the new account name: ");
    scanf("%s", newAccount);

    printf("Enter your first name: ");
    scanf("%s", first);

    printf("Enter you last name: ");
    scanf("%s", last);

    printf("Enter you age: ");
    scanf("%s", age);
}

void createAccount()
{
    FILE *f = fopen(newAccount, "w");

    // write the name of the account in the file
    fwrite("\nAccount Name: ", sizeof(char), strlen("\nAccount Name: "), f);
    fwrite(newAccount, sizeof(char), strlen(newAccount), f);

    // write the first name in the file
    fwrite("\nFirst Name: ", sizeof(char), strlen("\nFirst Name: "), f);
    fwrite(first, sizeof(char), strlen(first), f);

    // write the last name of the file
    fwrite("\nLast Name: ", sizeof(char), strlen("\nLast Name: "), f);
    fwrite(last, sizeof(char), strlen(last), f);

    // write the age in the account
    fwrite("\nAge: ", sizeof(char), strlen("\nAge: "), f);
    fwrite(age, sizeof(char), strlen(age), f);

    fwrite("\n", sizeof(char), strlen("\n"), f);

    fclose(f);
}

// the main function that have all things
int main()
{
    menu();  // print the menu

    int choice;

    while (choice != -1)
    {
        choice = choose();  // get the choice from the user

        // check what the user choose
        if (choice == 1)
        {
            char *file = getAccount();  // get the name of the account

            FILE *f = fopen(file, "r");  // open the file

            // check if the file is already exist
            if (f == NULL)
            {
                printf("There isn't an account has this name %s\n", file);
            }

            // read and print the file
            char *acc = read(file);
            printf("%s", acc);

            // clear and close the file we worked in
            fclose(f);
        }
        else if (choice == 2)
        {
            getNewAcc();
            createAccount();
        }
        else if (choice == -1)
        {
            exit(1);
        }
        else
        {
            printf("INVALID INPUT !!!\n\n");
            main();
        }
    }

    return 0;
}
