#include <stdbool.h>

/**
 * ADT for representing a date.
 */
typedef struct {
    int day;
    int month;
    int year;
} date;

/**
 * Function for setting the date of a given date.
 * @param a_date Pointer to the date to be updated.
 * @param day Integer representing the day.
 * @param month Integer representing the month.
 * @param year Integer representing the year.
 * @returns true if date valid, false otherwise.
 */
bool set_date (date* a_date, int day, int month, int year);

/**
 * Function for checking if a date is valid.
 * @param a_date The date to be checked.
 * @returns true if date valid, false otherwise.
 */
bool is_valid(date a_date);

/**
 * Function for checking if a date is on a leap year.
 * @param a_date The date to check
 * @returns true if the date is on a leap year.
 */
bool is_leap_year (date a_date);

/** 
 * Function for printing a date in Finnish standard format
 * @param a_date The date to print.
 */
void print_fi_std (date a_date);

/** 
 * Function for printing a date in ISO standard format
 * @param a_date The date to print.
 */
void print_iso_std (date a_date);

/**
 * Function for comparing if two dates are equal.
 * @param date1 The first date to compare.
 * @param date2 The second date to compare.
 * @returns true if dates are the same date, false otherwise.
 */
bool dates_equal(date date1, date date2);

/** 
 * Function for comparing two dates to see if one is before the other.
 * @param first The date we want to check if it is first in time.
 * @param second The date we want to check if it is after the first in time.
 * @returns true if first is before second, false otherwise.
 */
bool is_before (date first, date second);

/**
 * Function for retrieving the date before a given day.
 * @param a_date The starting date.
 * @returns The day before the give date.
 */
date get_previous_day(date a_date);

/**
 * Function for retrieving the date a given number of days before the given date.
 * @param a_date The starting date.
 * @param days The number of days to go back.
 * @returns The searched for date.
 */
date get_n_days_previous (date a_date, int days);

/**
 * Function for setting a date to today's date.
 * @param a_date Pointer to the date to be set to today's date.
 */
void set_to_today (date * a_date);
