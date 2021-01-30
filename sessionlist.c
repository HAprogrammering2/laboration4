#include "date.h"

/**
 * Datatype for storing session data, i.e. date, duration in minutes and exercise type.
 */
typedef struct session_data_struct {
    date date;
    int duration;
    int exercise_type;
} session_data;

