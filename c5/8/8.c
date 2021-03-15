/*Exercise 5−8. There is no error checking in day_of_year or month_day. Remedy this defect.*/


#include<stdio.h>
static char daytab[2][13]={
    {0,31,28,31,30,31,30,31,31,30,31,30,31},
    {0,31,29,31,30,31,30,31,31,30,31,30,31}
};

int day_of_year(int year,int month,int day);		// To get day of year
void month_day(int year,int yearday);			// To get month day

int main(void)
{
    int day,mo,dat;

    day=day_of_year(1988,02,29);
    printf("%d\n",day);
    month_day(1988,60);
    return 0;
}

// day_of_year: set day of year from month & day 

int day_of_year(int year,int month,int day)
{
    int i,leap;

    leap = year % 4 == 0 && year%100 != 0 || year%400 == 0;		// If given year is a leap year than value of leap is non zero(1) else 0
    
    for(i=1;i<month;i++)		// To calculate total number of days
        day += daytab[leap][i];

    return day;
}

// month_day: set month,day from day of year 

void month_day(int year,int yearday)
{
    int i,leap;

    leap = year % 4 == 0 && year%100 != 0 || year%400 == 0;
		// If given year is a leap year than value of leap is non zero(1) else 0
    for(i=1;yearday > daytab[leap][i];i++)		// To calculate month day from the day of year
        yearday -= daytab[leap][i];

    printf("Month: %d, Day: %d\n", i, yearday);

}

/* Output:-

60
Month: 2, Day: 29

*/
