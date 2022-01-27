#include <stdbool.h>
#include "date.h"

/**
 * Datatype for storing session data, i.e. date, duration in minutes and exercise type.
 */
typedef struct session_data_struct {
    date date;
    int duration;
    int exercise_type;
} session_data;

/**
 * Datatype for one node in the session list.
 */
typedef struct sessionlist_node_struct sessionlist_node;

/**
 * Datatype for a session list.
 */
typedef sessionlist_node * sessionlist;

/**
 * Function for creating a session list.
 * @returns the new, empty list.
 */
sessionlist list_create ();

/**
 * Function for destroying a session list. Deletes all elements.
 * @param list The list to be emptied.
 */
void list_destroy (sessionlist * list);

/**
 * Function for testing if a list is empty.
 * @returns true if empty, false otherwise.
 */
bool list_is_empty (sessionlist list);

/**
 * Function for storing session data in the list.
 * @param listptr A pointer to a list. Will be updated.
 * @param data The data to be inserted. 
 */
void list_insert (sessionlist * listptr, session_data data);

/**
 * Function for printing entire list.
 * @param list A list that will be printed. 
 */
void list_print_all (sessionlist list);

/**
 * Function for printing partial list. 
 * @param list The list to be partially printed.
 * @param cutoff The last date to be printed.
 */
void list_print_partial (sessionlist list, date cutoff);

/** 
 * Function for printing the last seven days.
 * @param list The list to be partially printed.
 */
void list_print_last_seven_days (sessionlist list);

/**
 * Function for removing all sessions for a given exercise type.
 * @param listptr Pointer to the list to be updated.
 * @param exercise_type The type of sessions to be removed.
 */
void remove_all_of_type (sessionlist * listptr, int exercise_type);

