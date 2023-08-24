
#include "Choice_Handler/choice_handler.h"

int main()
{
    customer_node_t* head_customer = NULL;

    int selected_choice;

    printf("\t*****************************************\n\
        *             Bank DataBase             *\n\
        *****************************************\n\n");

    while(1){
        printf("\t**********************************\n");
        printf("- Please, select the operation from 1 to 7....\n");
        printf("1) Create new customer.\n");
        printf("2) Edit customer name.\n");
        printf("3) Delete a customer.\n");
        printf("4) Transfer Cash from customer to another.\n");
        printf("5) Print a customer.\n");
        printf("6) Print all customers.\n");
        printf("7) Exit.\n");
        printf("\t*********************************\n");

        printf("\n-->Enter Your choice: ");
        scanf("%d", &selected_choice);

        choice(selected_choice, &head_customer);
    }

    return 0;
}
