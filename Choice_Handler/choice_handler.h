
#ifndef CHOICE_HANDLER_H
#define CHOICE_HANDLER_H

/*  Includes  */
#include "../BankDatabase_Functions/database_functions.h"

/*  Data Types Declarations  */
static customer_node_t *head_customer = NULL;

/* Function Declarations  */
void choice(int selected_choice, customer_node_t** head_customer);
void choice_create_customer(customer_node_t** head_customer);
void choice_edit_customer(customer_node_t* head_customer);
void choice_delete_customer(customer_node_t** head_customer);
void choice_cash_transfer(customer_node_t* head_customer);
void choice_print_customer(customer_node_t* head_customer);
void choice_print_all_customers(customer_node_t* head_customer);

#endif // CHOICE_HANDLER_H
