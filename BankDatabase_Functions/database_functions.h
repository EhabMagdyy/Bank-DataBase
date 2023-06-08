
#ifndef BANK_DATABASE_H
#define BANK_DATABASE_H

/*  Includes  */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/*  Macro Declarations  */
// start id number for customers
#define FIRST_ID 19602

/*  Data Types Declarations  */
static int customer_id = 19602;
static int number_of_customers = 0;

// Store deleted customers id to reuse with the new customer
static int reUse_id[10];
static int reUse_id_index = -1;

// Customer Data
typedef struct{
    char name[30];
    int id;
    double cash;
} customer_t;

// Storing customers in a single linked list
typedef struct customer_node{
    customer_t customer;
    struct customer_node *link;
}customer_node_t;


/* Function Declarations  */
customer_node_t* create_new_customer(customer_node_t* head_customer, char *name, double cash);
void edit_customer(customer_node_t* head_customer, int id, char* name);
customer_node_t* delete_customer(customer_node_t* head_customer, int id);
void cash_transfer_from_customer_to_customer(customer_node_t* head_customer, int from_id, int to_id, double cash);
void print_customer(customer_node_t* head_customer, int id);
void print_all_customers(customer_node_t* head_customer);
bool check_entered_information_validity(customer_node_t* head_customer, int id);


#endif // BANK_DATABASE_H
