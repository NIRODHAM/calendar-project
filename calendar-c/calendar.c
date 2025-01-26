#include <stdio.h>

#define TRUE 1
#define FALSE 0

int days_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
char *month[] = {
    "",
    "\n\n\nJanuary",
    "\n\n\nFebruary",
    "\n\n\nMarch",
    "\n\n\nApril",
    "\n\n\nMay",
    "\n\n\nJune",
    "\n\n\nJuly",
    "\n\n\nAugust",
    "\n\n\nSeptember",
    "\n\n\nOctober",
    "\n\n\nNovember",
    "\n\n\nDecember"
};

int input_year(void) {
    int year;
    printf("Please enter a year: ");
    scanf("%d", &year);
    return year;
}

int determine_leap_year(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        days_month[2] = 29;
        return TRUE;
    } else {
        days_month[2] = 28;
        return FALSE;
    }
}

int determine_day_code(int year) {
    int daycode;
    int d1, d2, d3;
    d1 = (year - 1) / 4;
    d2 = (year - 1) / 100;
    d3 = (year - 1) / 400;
    daycode = (year + d1 - d2 + d3) % 7;
    return daycode;
}

void display_calendar(int year, int daycode) {
    int month_index, day;

    for (month_index = 1; month_index <= 12; month_index++) {
        printf("%s", month[month_index]);
        printf("\n\nSun Mon Tue Wed Thu Fri Sat\n");

        for (int space = 0; space < daycode; space++) {
            printf("    ");
        }

        for (day = 1; day <= days_month[month_index]; day++) {
            printf("%3d ", day);

            if ((day + daycode) % 7 == 0) {
                printf("\n");
            }
        }

        daycode = (daycode + days_month[month_index]) % 7;
        printf("\n");
    }
}

int main(void) {
    int year, daycode, leapyear;

    year = input_year();
    leapyear = determine_leap_year(year);
    daycode = determine_day_code(year);
    display_calendar(year, daycode);

    return 0;
}
