
#include "database_functions.h"

/* Creating customer account */
customer_node_t* create_new_customer(customer_node_t* head_customer, char *name, double cash){

    customer_node_t *new_customer = (customer_node_t*) malloc(sizeof(customer_node_t));

    if(NULL == new_customer){
        printf("There is no free memory!\n\n");
    }
    else{
        number_of_customers++;

        new_customer->link = head_customer;
        strcpy(new_customer->customer.name, name);
        new_customer->customer.cash = cash;

        if(-1 != reUse_id_index){
            new_customer->customer.id = reUse_id[reUse_id_index--];
        }
        else{
            new_customer->customer.id = customer_id++;
        }

        head_customer = new_customer;

        printf("+ Customer created successfully with ID: %d.\n\n", new_customer->customer.id);

    }

    return head_customer;

}

/* Editing customer name */
void edit_customer(customer_node_t* head_customer, int id, char* name){

    if(check_entered_information_validity(head_customer, id)){

        customer_node_t *ptr_search_for_customer = head_customer;

        while(NULL != ptr_search_for_customer){

            if(id == ptr_search_for_customer->customer.id){
                strcpy(ptr_search_for_customer->customer.name, name);
                printf("Name changed successfully to: %s\n\n", ptr_search_for_customer->customer.name);

                return;
            }

            ptr_search_for_customer = ptr_search_for_customer->link;
        }
        if(NULL == ptr_search_for_customer){
            printf("Error, There are no customers with ID: %d!\n\n", id);
        }

    }
}

/* Deleting customer account */
customer_node_t* delete_customer(customer_node_t* head_customer, int id){

    if(check_entered_information_validity(head_customer, id)){
        if(head_customer->customer.id == id){
            reUse_id[++reUse_id_index] = id;

            printf("- Customer:%s, deleted successfully.\n\n", head_customer->customer.name);
            head_customer = head_customer->link;
            number_of_customers--;
        }
        else{
            customer_node_t *ptr_search_for_customer = head_customer;

            while(NULL != ptr_search_for_customer->link){

                if(id == (ptr_search_for_customer->link->customer.id)){
                    reUse_id[++reUse_id_index] = id;

                    printf("- Customer:%s, deleted successfully.\n\n", ptr_search_for_customer->link->customer.name);
                    ptr_search_for_customer->link = ptr_search_for_customer->link->link;
                    number_of_customers--;

                    return head_customer;
                }

                ptr_search_for_customer = ptr_search_for_customer->link;

            }

            if(NULL == ptr_search_for_customer->link){
                printf("Error, There are no customers with ID: %d!\n\n", id);
            }
        }

    }

    return head_customer;
}

/* Transfer Cash from customer to another */
void cash_transfer_from_customer_to_customer(customer_node_t* head_customer, int from_id, int to_id, double cash){

    if(check_entered_information_validity(head_customer, from_id)
         && check_entered_information_validity(head_customer, to_id)){

        // Transfer From
        customer_node_t *ptr_search_for_customer = head_customer;

        while(NULL != ptr_search_for_customer){
            if(from_id == ptr_search_for_customer->customer.id){
                if(cash > ptr_search_for_customer->customer.cash){
                    printf("Error, Invalid amount of cash, Customer cash: %0.2lf!\n\n", ptr_search_for_customer->customer.cash);
                    return;
                }
                else{
                    ptr_search_for_customer->customer.cash -= cash;
                }
                break;
            }
            ptr_search_for_customer = ptr_search_for_customer->link;
        }
        if(NULL == ptr_search_for_customer){
            printf("Error, There are no customers with ID: %d!\n\n", from_id);
            return;
        }

        // Transfer To
        ptr_search_for_customer = head_customer;

        while(NULL != ptr_search_for_customer){
            if(to_id == ptr_search_for_customer->customer.id){
                ptr_search_for_customer->customer.cash += cash;
                printf("$ Cash Transfered Successfully.\n");
                printf("Customer cash: %0.2lf\n\n", ptr_search_for_customer->customer.cash);
                return;
            }
            ptr_search_for_customer = ptr_search_for_customer->link;
        }
        if(NULL == ptr_search_for_customer){
            printf("Error, There are no customers with ID: %d!\n\n", to_id);
        }

    }
}

/* Print single customer data */
void print_customer(customer_node_t* head_customer, int id){

    if(check_entered_information_validity(head_customer, id)){
        while(NULL != head_customer){
            if(id == head_customer->customer.id){
                printf("Name: %-25s - ID: %-10d - Cash: %-12.2lf\n\n", head_customer->customer.name, head_customer->customer.id, head_customer->customer.cash);
                return;
            }
            head_customer = head_customer->link;
        }
    }
}

/* Print all customers data */
void print_all_customers(customer_node_t* head_customer){

    if(NULL == head_customer){
        printf("Error, There are no customers!\n\n");
    }
    else{
        int customers_counter = 0;
        printf("There are %d Customers.\n", number_of_customers);
        printf("   <Name>\t\t\t<ID>\t\t<Cash>\n");

        while(NULL != head_customer){
            printf("%2d) %-27s %-15d %-12.2lf\n", ++customers_counter, head_customer->customer.name, head_customer->customer.id, head_customer->customer.cash);
            head_customer = head_customer->link;
        }
        printf("\n");
    }
}

/* Checking if entered information is valid */
bool check_entered_information_validity(customer_node_t* head_customer, int id){

    bool is_valid = false;

    if(NULL == head_customer){
        printf("Error, There are no customers!\n\n");
    }
    else{
        if((FIRST_ID > id) || (customer_id <= id)){
            printf("Error, There are no customers with ID: %d!\n\n", id);
        }
        else{
            is_valid = true;
        }
    }

    return is_valid;
}
