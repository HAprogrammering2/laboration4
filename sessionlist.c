#include <stdlib.h>
#include "sessionlist.h"

sessionlist list_create (){
    return NULL;
}

bool list_is_empty (sessionlist list){
    if (list == NULL){
        return true;
    }
    else {
        return false;
    }
}

