// read, save and show all records of customers

#include <stdio.h>
#include <stdlib.h>

#define FILENAME "CtomerAccountrecords.dat"

struct customerAccountDetails
{
	char bankAccountNumber[10];
    char customerName[15];
    int balance;
};
typedef struct customerAccountDetails UserDetails;

int saveRecord();
int showAllRecords();

FILE *fp;
UserDetails Customer;
int main()
{
	int choice;
	while(1)
	{
		printf("1.Open an account\n2.Show All Records\n3.Exit\n");
		printf("Enter your option: ");
		scanf("%d", &choice);
		switch(choice)
		{
		case 1:
			saveRecord();
			break;
		case 2:
			showAllRecords();
			break;
		case 3:
			printf("Exiting program\n");
			return 0;
		default:
			printf("Enter valid choice.");
		}
	}
}

int saveRecord()
{
	fp = fopen(FILENAME, "a");
	printf("Enter Account Number: ");
    scanf("%s", Customer.bankAccountNumber);
    printf("Enter Customer Name: ");
    scanf("%s", Customer.customerName);
    printf("Enter Balance: ");
    scanf("%d", &Customer.balance);
    fwrite(&Customer, sizeof(Customer), 1, fp);
    printf("Record saved\n");
    fclose(fp);
}
int showAllRecords()
{
	int counter;
	fp = fopen(FILENAME, "r");
	fseek(fp, 0, SEEK_END);
	int size = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	int records = size / sizeof(Customer);
	printf("\nCustomer Records:\n");
	for(counter = 0; counter < records; counter++)
	{
		fread(&Customer, sizeof(Customer), 1, fp);
		printf("The customer%d details are: \n", counter+1);
		printf("Account Number: %s\n", Customer.bankAccountNumber);
        printf("Customer Name: %s\n", Customer.customerName);
        printf("Balance: %d\n\n", Customer.balance);
	}
	fclose(fp);
}