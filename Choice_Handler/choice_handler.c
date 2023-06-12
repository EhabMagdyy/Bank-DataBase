
#include "Choice_handler.h"

void choice(int selected_choice, customer_node_t** head_customer){
    if(1 > selected_choice || 7 < selected_choice){
        printf("Invalid input!\n\n");
    }
    else{
        if(create_customer_t == selected_choice){
            choice_create_customer(head_customer);
        }
        else if(edit_customer_t == selected_choice){
            choice_edit_customer(*head_customer);
        }
        else if(delete_customer_t == selected_choice){
            choice_delete_customer(head_customer);
        }
        else if(transfer_cash_t == selected_choice){
            choice_cash_transfer(*head_customer);
        }
        else if(print_customer_t == selected_choice){
            choice_print_customer(*head_customer);
        }
        else if(print_all_customers_t == selected_choice){
            choice_print_all_customers(*head_customer);
        }
        else{
            exit(1);
        }
    }
}

void choice_create_customer(customer_node_t** head_customer){
    char name[30];
    double cash;

    // To Clear Buffer
    fflush(stdin);

    printf("Enter The Name: ");
    scan_string(name);

    printf("Enter the amount of cash: ");
    scanf("%lf", &cash);

    *head_customer = create_new_customer(*head_customer, name, cash);
}


void choice_edit_customer(customer_node_t* head_customer){
    char name[30];
    int id;

    printf("Enter Customer ID: ");
    scanf("%d", &id);

    fflush(stdin);
    printf("Enter new name: ");
    scan_string(name);

    edit_customer(head_customer, id, name);
}


void choice_delete_customer(customer_node_t** head_customer){
    int id;
    printf("Enter Customer ID: ");
    scanf("%d", &id);

    *head_customer = delete_customer(*head_customer, id);
}


void choice_cash_transfer(customer_node_t* head_customer){
    int from_id;
    printf("Enter Customer ID(to transfer From): ");
    scanf("%d", &from_id);

    int to_id;
    printf("Enter Customer ID(to transfer To): ");
    scanf("%d", &to_id);

    double cash;
    printf("Enter amount of cash to transfer: ");
    scanf("%lf", &cash);

    cash_transfer_from_customer_to_customer(head_customer, from_id, to_id, cash);
}


void choice_print_customer(customer_node_t* head_customer){
    int id;
    printf("Enter Customer ID: ");
    scanf("%d", &id);

    print_customer(head_customer, id);
}


void choice_print_all_customers(customer_node_t* head_customer){
    print_all_customers(head_customer);
}

/* My scan function to read a whole string of only letters */
void scan_string(char name[]){
    int index = 0;
    char char_input;
    scanf("%c", &char_input);
    name[index++] = char_input;
    while('\n' != char_input){
        scanf("%c", &char_input);
        if(('A' <= char_input && 'Z' >= char_input) || ('a' <= char_input && 'z' >= char_input)
                                                    || (' ' == char_input  && ' ' != name[index-1])){
            name[index++] = char_input;
        }
        else{
            // neglect character if it's not a letter or a space
        }
    }
    name[index] = '\0';
}
