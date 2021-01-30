#include "sessionlist.h"
#include <stdio.h>

#define TEST_CASE(name) printf("RUNNING CASE: %s\n", name)
#define VERIFY(cond, msg) if (cond) printf("SUCCESS: %s\n", msg); else printf("FAIL: %s\n", msg);

int main(){
    sessionlist my_list;
    
    TEST_CASE("Create list");
    my_list = list_create();
    VERIFY(list_is_empty(my_list), "list is empty")


}
