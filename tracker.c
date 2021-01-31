#include <stdbool.h>
#include <stdio.h>
#include "sessionlist.h"
#include "date.h"
#include "debug.h"

// Globals
sessionlist my_sessions;

void print_menu(){
    printf ("1. Add a new exercise session\n");
    printf ("2. Display all stored sessions\n");
    printf ("3. Forget exercise type\n");
    printf ("4. Quit\n\n");
}

void clear_buffer(){
    while (getchar() != '\n') {
    }
}

void print_prompt(){
    printf ("> ");
}

int prompt_user(){
    int selection; 
    print_prompt();
    while (scanf("%d", &selection) !=1){
        printf ("Incorrect input, please select a number from the menu.\n");
        clear_buffer();
        print_prompt();
    }
    return selection;
}

int read_exercise_type(){
    int exercise_type;
    printf("Type : ");
    while (!scanf("%d", &exercise_type)) {
        printf("Incorrect input, please input an integer for exercise type.\n");
        clear_buffer();
        printf("Type : ");
    }
    return exercise_type;
}

int read_duration (){
    int duration;
    printf("Duration : ");
    while (!scanf("%d", &duration)) {
        printf("Incorrect input, please input an integer for duration.\n");
        clear_buffer();
        printf("Duration : ");
    }
    return duration;
}

date read_date () {
    int day, month, year;
    date new_date;
    bool date_done = false;

    while (!date_done){
        printf ("Date : ");

        while ((scanf("%d.%d.%d", &day, &month, &year) < 3)){
            printf("Incorrect input, please input date in format dd.mm.yyyy\n");
            clear_buffer();
            printf("Date : ");

        }
        set_date(&new_date, day, month, year);
        if (!is_valid(new_date)){
            printf("Incorrect date, please input a valid date.\n");
        }
        else {
            date_done = true;
        }
    }

    return new_date;
}

void add_session(){
    DEBUG("adding new session");
    session_data new_session;

    new_session.date = read_date();
    new_session.exercise_type = read_exercise_type();
    new_session.duration = read_duration();

    list_insert(&my_sessions, new_session);
}

void print_sessions(){
    char * header = "--------------------------------\n";
    printf("%s          All sessions          \n%s", header, header);
    list_print_all(my_sessions);
    printf("%s", header);
}

int main(){
    bool done = false;
    int selection = 0;
    my_sessions = list_create();

    while (!done){
        print_menu();
        selection = prompt_user();

        switch (selection) {
            case 1:
                add_session();
                break;
            case 2:
                print_sessions();
                break;
            case 3:
                remove_all_of_type (&my_sessions, read_exercise_type());
                break;
            case 4:
                done = true;
                break;
            default:
                printf("Incorrect input %d\n", selection);
                break;
        }

    }
}
