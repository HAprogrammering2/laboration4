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
 * Struct for storing session list node data.
 */

struct sessionlist_node_struct {
    session_data data;
    sessionlist_node_struct * next;
};

/** 
 * Datatype for a list node.
 */
typedef struct sessionlist_node_struct sessionlist_node;

/**
 * Datatype for a session list.
 */
typedef sessionlist_node * sessionlist;

