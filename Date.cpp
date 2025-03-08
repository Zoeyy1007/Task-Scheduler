#include "Date.h"

Date::Date(int month, int day) {
    weekday.tm_year = 2025 - 1900;
    weekday.tm_mon = month - 1;
    weekday.tm_mday = day;
    weekday.tm_hour = 12;
    weekday.tm_min = 0;
    weekday.tm_sec = 0;
    time_t time = mktime(&weekday);

    if (time == -1) {
        throw runtime_error("Invalid date.");
    }
}

int Date::day_in_week() {
    return weekday.tm_wday;
}
