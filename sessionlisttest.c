#include "sessionlist.h"
#include <stdio.h>

#define TEST_CASE(name) printf("RUNNING CASE: %s\n", name)
#define VERIFY(cond, msg) if (cond) printf("SUCCESS: %s\n", msg); else printf("FAIL: %s\n", msg);

int main(){
    sessionlist my_list;
    session_data session1;
    date date1, date2;

    TEST_CASE("Create list");
    my_list = list_create();
    VERIFY(list_is_empty(my_list), "list is empty")

    TEST_CASE("Insert element");
    set_date(&date1, 1, 2, 2021);
    session1.date = date1;
    session1.duration = 25;
    session1.exercise_type = 3;
    list_insert(&my_list, session1);
    VERIFY(!list_is_empty(my_list), "list is not empty");

    TEST_CASE("Insert second element");
    session1.duration = 40;
    session1.date = get_previous_day (date1);
    list_insert(&my_list, session1);
    VERIFY(!list_is_empty(my_list), "list is not empty");

    TEST_CASE("Print all");
    list_print_all(my_list);    

    TEST_CASE("Insert more elements");
    for(int i = 0; i < 10; i++){
        date1 = get_previous_day (date1);
        session1.date = date1;
        session1.duration = i*10;
        list_insert(&my_list, session1);
    }
    list_print_all(my_list);

    TEST_CASE("Print after 25.1.2021");
    set_date(&date2, 26, 1, 2021);
    list_print_partial(my_list, date2);

    TEST_CASE("Print seven days back");
    set_to_today(&date2);
    printf ("Today is: ");
    print_fi_std(date2);
    printf("\n");
    date2 = get_n_days_previous(date2, 7);
    list_print_partial (my_list, date2);

    TEST_CASE("Print seven days back, using function");
    list_print_last_seven_days(my_list);

    TEST_CASE("Delete all of type 3, which is entire list");
    remove_all_of_type(&my_list, 3);
    VERIFY(list_is_empty(my_list), "list is empty");

    TEST_CASE("Insert more elements with different exercise types");
    for(int i = 0; i < 10; i++){
        date1 = get_previous_day (date1);
        session1.date = date1;
        session1.duration = i*10;
        session1.exercise_type = i % 3;
        list_insert(&my_list, session1);
    }
    list_print_all(my_list);

    TEST_CASE ("Delete all of type 2");
    remove_all_of_type(&my_list, 2);
    VERIFY(!list_is_empty(my_list), "list is not empty");
    list_print_all(my_list);
    
    TEST_CASE ("Delete all of type 0, to get the last element deleted");
    remove_all_of_type(&my_list, 0);
    VERIFY(!list_is_empty(my_list), "list is not empty");
    list_print_all(my_list);

    TEST_CASE("Destroy list");
    list_destroy(&my_list);
    VERIFY(list_is_empty(my_list), "list is empty");
    list_print_all(my_list);


}
