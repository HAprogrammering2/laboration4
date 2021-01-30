#include "date.h"
#include <stdio.h>
#include <time.h>

bool set_date (date* a_date, int day, int month, int year){
    a_date->day = day;
    a_date->month = month;
    a_date->year = year; 

    return is_valid(*a_date);
}

int days_per_month[13] = {0, 31, 28, 31, 30, 31, 31, 30, 31, 30, 31, 30, 31};

/**
 * Get the number of days for the month of the given date
 * @param a_date The date to check.
 * @returns an integer representing the maximum number of days in the given month.
 */
int get_days_per_month(date a_date){
    if ((a_date.month == 2) && (is_leap_year(a_date))){
        return 29;
    }
    else {
        return days_per_month[a_date.month];
    }
}

bool is_valid (date a_date){
    if (a_date.day > 31 || 
        a_date.day < 1 ||
        a_date.month > 12 ||
        a_date.month < 1) {
            return false;
        }
    else {
        if ((a_date.month == 2) && is_leap_year(a_date)){ // February on a leap year
            return a_date.day <= 29;
        }
        else { // Not leap year, or leap year and not February
            return a_date.day <= days_per_month[a_date.month];
        }
    }
}

bool is_leap_year (date a_date){
    if (a_date.year % 4 > 0){
        // Not divisible by 4, not a leap year
        return false;
    }
    else if (a_date.year % 100 == 0){
        if (a_date.year % 400 == 0){
            // Divisible by 400 --> not leap year
            return false;
        }
        else {
            // Divisible by 100 but not 400 --> leap year
            return true;
        }
    }
    else {
        // Divisible by 4 but not 100
        return true;
    }
}

void print_fi_std (date a_date){
    printf("%d.%d.%d", a_date.day, a_date.month, a_date.year);
}

void print_iso_std (date a_date){
    printf("%d-%d-%d", a_date.year, a_date.month, a_date.day);
}

bool dates_equal(date date1, date date2)
{
    if (date1.day == date2.day &&
        date1.month == date2.month &&
        date1.year == date2.year){
        return true;
    }
    else {
        return false;
    }
}

bool is_before (date first, date second){

    if(first.year < second.year) {
        return true;
    }
    else if (first.year > second.year){
        return false;
    }
    else if (first.month < second.month) { // first.year == second.year
        return true;
    }
    else if (first.month > second.month) {
        return false;
    }
    else if (first.day < second.day) {  // first.month == second.month
        return true;
    } 
    else { // first.day > second.day OR dates_equal
        return false;
    }
}

date get_previous_day(date a_date){
    
    if (a_date.day == 1) {
        // Beginning of month, get previous month
        a_date.month = a_date.month - 1;

        if (a_date.month == 0){
            // Beginning of year, skip to December previous year
            a_date.year -= 1;
            a_date.month = 12;
        }
        // Update the day to the last day of the previous month (now in a_date)
        a_date.day = get_days_per_month(a_date);
    }
    else {
        // Not in beginning of month, just decrease day.
        a_date.day -= 1;
    }

    return a_date;
}

date get_n_days_previous (date a_date, int days){
    date index_date = a_date;

    while (days > 0){
        days--;
        index_date = get_previous_day(index_date);
    }
    return index_date;
}

void set_to_today(date * a_date){
    time_t today_in_seconds;
    struct tm * timeinfo;

    today_in_seconds = time(NULL);
    timeinfo = localtime(&today_in_seconds);

    a_date->day = timeinfo->tm_mday;
    a_date->month = timeinfo->tm_mon + 1;    //tm_mon is months since January
    a_date->year = timeinfo->tm_year + 1900; //tm_year years since 1900
}
