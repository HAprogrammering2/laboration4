#include <stdlib.h>
#include <stdio.h>
#include "sessionlist.h"
#include "debug.h"

sessionlist list_create (){
    sessionlist new_list;
    new_list.first = NULL;
    new_list.last = NULL;
    new_list.count = 0;
    return new_list;
}

bool list_is_empty (sessionlist list){
    if (list.first == NULL){
        return true;
    }
    else {
        return false;
    }
}

void list_insert(sessionlist * headnode, session_data data){
    sessionlist_node * new_node;

    // Allocate data for the node
    new_node = (sessionlist_node *) malloc(sizeof(sessionlist_node));

    // Add data to new node
    new_node->data = data;

    // Insert node into list
    // Case 1: list is empty
    if (headnode->first == NULL){
        DEBUG("list_insert, case 1 – empty list");
        headnode->first = new_node;
        headnode->last = new_node;
        new_node->next = NULL;
    }
    // Case 2: list has content
    else {
        DEBUG("list_insert, case 2 – list has content");
        new_node->next = headnode->first;
        headnode->first = new_node;
    }

    // Update the counter
    headnode->count++;

}

void print_session_data (session_data data){
    print_fi_std(data.date);
    printf(" type: %d duration: %d\n", data.exercise_type, data.duration);
}

void list_print_all(sessionlist list){
    sessionlist_node * current_node;
    DEBUG("list_print_all start");
    current_node = list.first;

    while (current_node != NULL){
        DEBUG("list_print_all inside loop");
        // Print the content of the node
        print_session_data(current_node->data);
        // Go to next node
        current_node = current_node->next;
    }
}


void list_print_partial (sessionlist list, date cutoff){
    
    while (list.first != NULL){
        DEBUG("list_print_partial inside loop");
        // Check if we should print this node
        if (!is_before(list.first->data.date, cutoff)){
            print_session_data(list.first->data);
        }
        else{
            DEBUG("list_print_partial, not printing");
        }

        // Go to next node
        list.first = list.first->next;
    }
}

void list_print_last_seven_days (sessionlist list){
    date today, seven_days_earlier;
    set_to_today(&today);
    seven_days_earlier = get_n_days_previous(today, 7);
    list_print_partial (list, seven_days_earlier);
}

void remove_all_of_type (sessionlist * listptr, int exercise_type){
    sessionlist_node * current_node;
    sessionlist_node * previous_node;

    current_node = listptr->first;
    previous_node = NULL;

    while(current_node != NULL){
        if (current_node->data.exercise_type == exercise_type){
            DEBUG("remove_all_of_type: found element to delete.");
            // This node should be deleted
            if (previous_node == NULL){
                DEBUG("remove_all_of_type: deleting first element");
                // First element deleted
                listptr->first = current_node->next;
                free(current_node);
                current_node = listptr->first;
            }
            else{
                // Other element deleted
                DEBUG("remove_all_of_type: deleting other element");
                previous_node->next = current_node->next;
                free(current_node);
                current_node = previous_node->next;
            }
            // Did we delete the last node?
            if (current_node == NULL){
                DEBUG("remove_all_of_type: deleted last node, updating last pointer");
                listptr->last = previous_node;
            }
            // Decrease count
            listptr->count--;
          
        }
        else{
            // This node should not be deleted
            DEBUG("remove_all_of_type: element should not be deleted");
            previous_node = current_node;
            current_node = current_node->next;
        }
    }
}

void list_destroy (sessionlist * listptr){
    sessionlist_node * current;
    sessionlist_node * tbdeleted;

    current = listptr->first;

    while (current != NULL){
        DEBUG("list_destroy: deleting element");
        // Store element to be deleted
        tbdeleted = current;

        // Move forward in list
        current = current->next;

        // Delete current element
        free (tbdeleted);
        tbdeleted = NULL;
    }

    listptr->first = NULL;
    listptr->last = NULL;
    listptr->count = 0;
}
