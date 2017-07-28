/*
    Amit Kumar
    28-July-2017
*/


#include<stdio.h> 
#include<iostream>
#include<cstring>

using namespace std;

int main(){ 
    int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; 
    char week[7][10];
    int date, mon, year, i, r, s = 0; 
    
    strcpy(week[0], "Sunday"); 
    strcpy(week[1], "Monday"); 
    strcpy(week[2], "Tuesday"); 
    strcpy(week[3], "Wednesday"); 
    strcpy(week[4], "Thursday"); 
    strcpy(week[5], "Friday"); 
    strcpy(week[6], "Saturday"); 
    printf("Enter a valid date (dd/mm/yyyy): "); 
    scanf("%d / %d / %d", &date, &mon, &year); 
    if( (year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0)) )       //condition for leap year
        month[1] = 29; 
    for(i = 0 ; i < mon - 1 ; i++)
        s = s + month[i];
    s = s + (date + year + (year / 4) - 2);
    s = s % 7;
    printf("\nThe day is : %s\n", week[s]);
}




/*
        Explanation of above program 

    In this program we have several variables let take a look at each first -
    month[12] - This is an array of type integer and its size is 12 i.e. 12 different integers can be stored in this array. 
    This array is also initialized at the time of declaration. 
    Each value of this array represents the number of days in a particular month e.g. first value 31 represents that January has 31 days.
    char[7][10] - This is another array but unlike the above month[12] array, this array is a multidimensional array of the type character. 
    This array can have 7 values and length of each value must be less than or equal to 10. 
    This array represents the days e.g. Sunday, Monday and so on.
    date, month and year - These are integers and are used to store date, month and year entered by the user.
    i, r and s - This are some other integers used for intermediate calculations. 

    Note: Here, rather than initializing the char[7][10] array at the time of declaration like we did with month[12] array, we’re making use of C language’s string copy function strcpy(). 

    With the help of strcpy() function, week[7][10] is initialized. Now we ask the user to enter the input in a preformatted manner. Notice inside scanf() we’ve separated each integer by a “/”, so when user enters the date in a format like dd/mm/yyyy all three values are automatically get stored in their respective variable. 

    Next, the if condition is for checking whether the year that user entered is a leap year or not. If the year is indeed a leap year the number of days in the February month is set to 29 by month[1] = 29; 

    Remember: The index of an array starts at 0, so in order to access the second value we have to refer to the index 1. That’s what we did here in the above expression - month[1] = 29

    After checking for the leap year, we enters inside a for loop. The for loops runs for the values of loop variable i = 0 to mon - 2 (in loop i < mon - 1), adding all the days of months that are before the month that user entered to the variable s e.g. suppose user entered mon = 3, so the for loop will run for i = 0 to 1. So s = s + month[i] or in this case s = month[0] + month[1].

    After that outside the loop, we further update the value of s by -

    s = s + (date + year + (year / 4) - 2) ; and then s = s % 7. 

    After the above process, s will contain an index to the week array which can be accessed as - week[s] and this value shows the day on the given date.

    Note: “%s” in printf() is used to print the string value of week[s].

*/