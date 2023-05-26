#include <stdio.h>
#include <stdlib.h>
/*
Linked List implementation by Shane Menzigian
Started on 5/23/23
Description: A linked list contains nodes, each one pointing to another node. Combined, they somewhat follow a list.
The linked list's head is the first item in the list, which then points to the next node, which points to the next, and so on.
This program has methods for adding and deleting the first node, searching for the first instance of specific values, and adding and deleting a node at the end of the chain.
*/
struct node{
    //A single item in the list. Recursively calls itself for the next node attribute.
    int data;
    struct node* next;
    };

struct node *head = NULL;

void print_list(){
    //Goes through every item in the list and prints what is there.
    struct node *p = head;
    printf("[");
    while(p){
        if(p->next == NULL){
            printf("%d",p->data);
        }else{
        printf("%d, ",p->data);}
        p = p->next;}
    printf("]\n");
    }

void insert_at_start(int data){
    //Inserts item to head node. If there is a head already, it is moved down one spot.
    struct node *to_add = (struct node*) malloc(sizeof(struct node));
    to_add->data = data;
    to_add->next = head;
    head = to_add;
           }

void delete_first(){
    //Deletes the first item in the list. Every other item is then moved up one spot, creating a new head.
    if(head){
    struct node *to_delete = head;
    struct node *new_head = to_delete -> next;
    to_delete->next = NULL;
    head = new_head;}
    }
void delete_last(){
    //Deletes the last item in the list by transversing the list with two temp nodes. The first temp node's ->next is removed, while the data from the second node is removed.
    if(head){
    struct node *to_delete = head;
    struct node *pointer_remove = head;
    while (to_delete->next){
        pointer_remove = to_delete;
        to_delete = to_delete-> next;
    }
    pointer_remove->next = NULL;
    to_delete = NULL;}
    }

void insert_at_end(int data){
    //Inserts an item to the final node by transversing the list, then adding a new node.
    struct node *to_add = malloc(sizeof(struct node));
    to_add->data = data;
    to_add ->next = NULL;
    if(head!=NULL){
        struct node *first = head;
        while(first->next!=NULL){
            first = first ->next;
        }
    first->next = to_add;
    print_list();}
    else{
        head = to_add;
        print_list();
    }
    }
int pop(){
    //Removes and returns final item in list.
    struct node *final_node = head;
    if(head){
        while(final_node->next != NULL){
            final_node = final_node->next;

        }
        int deleted = final_node->data;
        delete_last();
    return deleted;
    }
    return 0;
    }


int isin(int target){
    //Checks to see if an integer is in the list.
    struct node *current = head;
    while(current){
        if(current->data == target){
            return 1;
        }else{current = current->next;}
        }
    return 0;
    }
int search_for_first(int target){
    //Searches for the first instance of a number in the list. Returns the index of the number. -1 is used to show there is no number in the list.
    int counter = 0;
    if(isin(target)==1){
        struct node *current =head;
        while(current){
            if(current->data == target){
                return counter;
            }
            else{
            current = current ->next;
            counter ++;}
        }
    }
    else{
        return -1;
    }
}


void main(){
    //Essentially the driver function. Shows the processes in the command prompt and such.
    int length;
    printf("How long will your list be?\n");
    scanf("%d",&length);
    for(int i = 0; i<length; i++){
        int thing;
        printf("Insert integer to append: \n");
        scanf("%d", &thing);
        insert_at_end(thing);
        }
    printf("Here is your list! ");
    print_list();
    int bonus;
    printf("Enter an integer to insert at the beginning: \n");
    scanf("%d",&bonus);
    insert_at_start(bonus);
    print_list();
    delete_first();
    printf("Deleted the first item.\n");
    print_list();
    delete_last();
    printf("Deleted the last item.\n");
    print_list();
    printf("%d was popped.",pop());
    print_list();
    printf("Enter a number to search for: ");
    int to_search;
    scanf("%d",&to_search);
    if(isin(to_search)==1){
        printf("%d is in the list.\n",to_search);
        }
        else{
        printf("%d is not in the list.\n",isin(to_search));
    }

    printf("%d is at index spot %d.\n",to_search,search_for_first(to_search));
    }



