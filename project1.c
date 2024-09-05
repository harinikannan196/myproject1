#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#define MAX 100

struct order 
{
	int orderNum;
    char itemName[50];
    float price;
    int quantity;
};
int i;
float amount=0;

void addOrder(struct order o[], int *numOrders);
void displayOrders(struct order o[], int numOrders);
int calculateTotal(struct order o[], int numOrders);
void menu(struct order o[],int *numOrders);
void delivery(struct order o[], int numOrders);
void calculate(struct order o[],float charge);

int main() 
{
	printf("\n\t\t\t\tORDER DETAIL MANAGEMENT SYSTEM\n");
    struct order o[MAX];
    int numOrders=0;  
    menu(o,&numOrders);
    return 0;
}
void menu(struct order o[], int *numOrders)
{
	    int choice;
    while(1) 
	{
        printf("\n1. Place an order\n"); 
        printf("2. Display all orders\n");
        printf("3. Calculate total price\n");
        printf("4. Exit\n"); 
        printf("Enter your choice:");
        scanf("%d",&choice);

        switch (choice) 
		{
            case 1:
                addOrder(o, numOrders);
                break;
            case 2:
                displayOrders(o, *numOrders);
                break;
            case 3:
                calculateTotal(o, *numOrders);
                break;
            case 4:
                exit(1);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } 
}

void addOrder(struct order o[], int *numOrders) 
{
     struct order s;
     int ch;
     while(1)
	 {
     	    printf("\n    ***NON-VEG MENU\t\t\t\tVEG MENU*\n\tNAME\t\tPRICE\t\t\t\tNAME\t\tPRICE\n1. Chiken Biriyani\tRs.160\t\t\t6. Veg Biriyani    \tRs.140\n2. Chicken Noodles\tRs.110\t\t\t7. Veg Noodle    \tRs.100\n3. Chicken fried rice\tRs.140\t\t\t8. Veg Fried rice     \tRs.120\n4. Mutton Biriyani    \tRs.180\t\t\t9. Mushroom Biriyani\tRs.130\n5. Fish Briyani    \tRs.160\t\t\t10.Mushroom Noodle\tRs.120\n\n\t\t\t\t  11.Exit\nEnter your choice:");
			scanf("%d",&ch);
       switch(ch)
	   {
       		case 1:
       		   strcpy(s.itemName,"Chicken Biriyani");
			   printf("Enter quantity: ");
               scanf("%d", &s.quantity);
               s.price=160*s.quantity;
               printf("price=%f\n",s.price);
               break;
               
        case 2:strcpy(s.itemName,"Chicken Noodles");
        	   printf("Enter quantity: ");
               scanf("%d", &s.quantity);
               s.price=110*s.quantity;
               printf("price=%f\n",s.price);
               break;
               
        case 3:strcpy(s.itemName,"Chicken Fried Rice");
        	   printf("Enter quantity: ");
               scanf("%d", &s.quantity);
               s.price=140*s.quantity;
               printf("price=%f\n",s.price);
               break;
               
		case 4:strcpy(s.itemName,"Mutton Briyani");
        	   printf("Enter quantity: ");
               scanf("%d", &s.quantity);
               s.price=180*s.quantity;
               printf("price=%f\n",s.price);
               break;
               
        case 5:strcpy(s.itemName,"Fish Briyani");
        	   printf("Enter quantity: ");
               scanf("%d", &s.quantity);
               s.price=160*s.quantity;
               printf("price=%f\n",s.price);
               break;
               
        case 6:strcpy(s.itemName,"Veg Briyani");
        	   printf("Enter quantity: ");
               scanf("%d", &s.quantity);
               s.price=140*s.quantity;
               printf("price=%f\n",s.price);
               break;
               
        case 7:strcpy(s.itemName,"Veg Noodles");
			   printf("Enter quantity: ");
               scanf("%d", &s.quantity);
               s.price=100*s.quantity;
               printf("price=%f\n",s.price);
               break;
               
        case 8:strcpy(s.itemName,"Veg Fried Rice");
        	   printf("Enter quantity: ");
               scanf("%d", &s.quantity);
               s.price=120*s.quantity;
               printf("price=%f\n",s.price);
               break;
               
        case 9:strcpy(s.itemName,"Mushroom Briyani");
        	   printf("Enter quantity: ");
               scanf("%d", &s.quantity);
               s.price=130*s.quantity;
               printf("price=%f\n",s.price);
               break;
               
		case 10:strcpy(s.itemName,"Mushroom Noodles");
        	   printf("Enter quantity: ");
               scanf("%d", &s.quantity);
               s.price=120*s.quantity;
               printf("price=%f\n",s.price);
               break; 
          
		case 11:
			menu(o, numOrders);
        	break;
        	
        default:
       		printf("Invalid operation");
       		break;
	   }
    amount+=s.price;
    	s.orderNum=*numOrders+1;
        o[*numOrders] = s;
        (*numOrders)++;
        printf("Order added successfully.\n");
    } 
}

void displayOrders(struct order o[], int numOrders) 
{
    printf("\nALL ORDERS:\n");
     printf("------------------------------------------------------------------------------\n");
    printf("Order Number\t|Item Name\t\t  |\tPrice\t  |   Quantity  |\n");
     printf("------------------------------------------------------------------------------\n");

    for (i = 0;i<numOrders; i++)
	{
        printf(" %d \t\t|%-25s|\t%-10.2f|\t%d\t|\n", o[i].orderNum, o[i].itemName, o[i].price, o[i].quantity);
	}
	 printf("------------------------------------------------------------------------------\n");

        calculateTotal(o,numOrders);
        printf("\nDELIVERY CHARGE=Rs.40\n\n");
        printf("VALUE ADDED TAX=12 percent \n\n");
        printf("GST=5 percent\n \n");
    	delivery(o,numOrders);
    	printf("\nYOUR ORDER HAS BEEN PLACED SUCCESSFULLY\n");
    	printf("\nYou order will be delivered in 30 minutes\n");
    	printf("\nOrdered Date:");
        printf(__DATE__);
        printf("\n");
        printf("Ordered Time:");
        printf(__TIME__);
        printf("\n\n");
    	printf("----------------------------------------------THANK YOU, VISIT AGAIN------------------------");
    	exit(1);
}

void delivery(struct order o[], int numOrders)
{
	float charge=40+(0.05*amount)+(0.12*amount);
	calculate(o,charge);
}

int calculateTotal(struct order o[], int numOrders)
{
    printf("\nTotal price = %f\n",amount);
    return amount;
}

void calculate(struct order o[],float charge)
{
	float totalamount;
	totalamount=amount+charge;
	printf("\nTotal Amount to be paid =%f\n",totalamount);
}
