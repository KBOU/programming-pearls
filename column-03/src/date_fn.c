#include <stdio.h>

#define MIN_YEAR 1999
#define MAX_YEAR 9999
#define DAYS_IN_YEAR 365

int DAYS_IN_MONTH[12] = {
	31,
	28,
	31,
	30,
	31,
	30,
	31,
	31,
	30,
	31,
	30,
	31
};

typedef struct date {
	int yyyy;
	int mm;
	int dd;
} Date;

int isleap(int year) {
	if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0) ) {
		return 1;
	}
	return 0;
}

int daysinyear(Date d) {
	int days = 0;
	int m = 0;
	for (; m < d.mm; m++) {
		days += DAYS_IN_MONTH[m];
		if (m == 1) {
			if (isleap(d.yyyy)) {
				days++;
			}
		}
	}
	return days + d.dd;
}

int validate(Date d) {
	if (d.yyyy < MIN_YEAR || d.yyyy > MAX_YEAR) {
		return 0;
	} else if (d.mm < 0 || d.mm > 11) {
		return 0;
	} else {
		int upper = DAYS_IN_MONTH[d.mm];
		if (isleap(d.yyyy) && d.mm == 1) {
			upper += 1;
		}
		if (d.dd < 0 || d.dd > upper) {
			return 0;
		}
	}
	return 1;
}

int datediff(Date d1, Date d2) {
	int diff = 0;
	if (d2.yyyy != d1.yyyy) {
		diff += (d2.yyyy - d1.yyyy) * DAYS_IN_YEAR;
		int ystart;
		int yend;
		if (d2.yyyy > d1.yyyy) {
			ystart = d1.yyyy;
			yend = d2.yyyy;
		} else {
			ystart = d2.yyyy;
			yend = d1.yyyy;
		}
		for (; ystart < yend; ystart++) {
			if (isleap(ystart)) {
				diff++;
			}
		}
	}

	int day2 = daysinyear(d2);
	int day1 = daysinyear(d1);

	return day2 - day1 + diff;
}

int getday(Date d) {
	// Sun=0, Mon=1, Tue=2, Wed=3, Thu=4, Fri=5, Sat=6
	// 2000/1/2 Sun
	Date start;
	start.yyyy = 2000;
	start.mm = 0;
	start.dd = 2;
	int diff = datediff(start, d);
	if (diff < 0) {
		diff += 7;
	}

	return diff %= 7;
}

void calendar(int yyyy, int mm) {
	Date start;
	start.yyyy = yyyy;
	start.mm = mm;
	start.dd = 1;
	int startday = getday(start);
	int enddate = DAYS_IN_MONTH[mm];
	if (isleap(yyyy) && mm == 1) {
		enddate++;
	}

	printf("    %d/%d    \n", yyyy, mm+1);
	printf("Sun Mon Tue Wed Thu Fri Sat\n");
	int i;
	for (i = 0; i < startday; i++) {
		printf("    ");
	}
	for (i = 1; i <= enddate; i++) {
		printf(" %02d ", i);
		startday++;
		if (startday % 7 == 0) {
			printf("\n");
		}
	}
	printf("\n");
}

int main(int argc, char *argv[]) {
	calendar(2013, 05);
	return 0;
}
