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
 * Struct for storing a session list node.
 */
struct sessionlist_node_struct {
    session_data data;
    struct sessionlist_node_struct * next;
};

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
 * Function for testing if a list is empty.
 * @returns true if empty, false otherwise.
 */
bool list_is_empty (sessionlist list);
