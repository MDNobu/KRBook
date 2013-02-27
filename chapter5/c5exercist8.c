#include "stdio.h"

static int days[2][13] = { {0,31,28,31,30,31,30,31,31,30,31,30,31}, 
	{0,31,29,31,30,31,30,31,31,30,31,30,31}};

int day_of_years(int year, int month, int day) {
	int i,leap = 0;
	int result = 0;

	leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
	if(month < 0 || month > 12 || day > days[leap][month]) {
		printf("data is error");
		return -1;
	}

	for(i = 1; i <  month; i++) {
		result += days[leap][i];
	}
	result += day;
	return result;
}

void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;
    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
	if((leap == 1 && yearday > 366) || (leap == 0 && yearday > 355 ) || yearday < 0 ) {
		printf("data is error");
		return;
	}
    for (i = 1; yearday > days[leap][i]; i++)
        yearday -= days[leap][i];
    *pmonth = i;
	*pday = yearday;
}

