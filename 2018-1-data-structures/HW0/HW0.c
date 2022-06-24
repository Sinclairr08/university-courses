/*================================================================================
* Copyrights (C) 2018 by Lee Jun Hyuk. All rights reserved.
*
* Summary of the lab : Calculating the number of 13th Friday
*
* Project name : Pre-Working
* File names : main.c
*
* Writer : Lee Jun Hyuk,
*          School of Natural Science,
*          Department of Mathematics,
*          Sungkyunkwan University.
*
* Written date : 2018.03.10
* Lastest revised date : 2018.03.10
*
* Operation System : Windows 10
* Used compiler : Visual Studio 2017
*
* Modification histroy : None
*
* ==================================================================================*/

#include <stdio.h>
#include <stdlib.h>

enum Weekday {
	Mon, Tue, Wen, Thu, Fri, Sat, Sun
};

typedef enum{
	False, True
}bool;

// To check the leap year
inline bool is_leap(int year) {
	if (year % 4 == 0) {
		if (year % 100 == 0 && year % 400 != 0) // Every Hundered years are not leap, except for Four hundreds
			return False;

		else
			return True;
	}
	else
		return False;
}

int calcwd(int year);
int calcfr(int year, int months[]);

int main() {

	int first, last;		// First & Last years
	int sum = 0;

	int months[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};	// Days of every months

	scanf("%d", &first);
	scanf("%d", &last);

	if ((first < 1900) || last < first) {
		printf("Wrong input!\n");
		exit(-1);
	}

	while (first <= last)
		sum += calcfr(first++, months);

	printf("%d\n", sum);
	return 0;
}

// The function that returns the number of 13th friday of given year
int calcfr(int year, int months[]) {
	enum Weekday weekday = calcwd(year);
	int month = 1, day = 1;
	int ret = 0;				// return the number of 13th friday of given year
	
	while (month <= 12) {
		day += 12;				// 13th day
		weekday += 12;
		weekday %= 7;
		
		if (weekday == Fri)		// If it is 13th friday
			ret += 1;

		weekday += months[month - 1] - day + 1;
	
		if (month == 2 && is_leap(year))		// In the case of leap year
			weekday++;

		month++;
		day = 1;
		}

	return ret;

}

// The function that returns the first weekday of given year
int calcwd(int year) {
	int cnt = 1900;
	int ret_wd = 0;			// 1900.01.01 is monday

	while (cnt <= year) {
		if (is_leap(year))
			ret_wd += 2;	// 366 % 7 = 2
		else
			ret_wd += 1;	// 365 % 7 = 1
		
		cnt++;
	}

	return ret_wd % 7;
}