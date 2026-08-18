// INFO: Headers from the standard library should be inserted at the top via
// #include <LIBRARY_NAME>
#include <cmath>

// daily_rate calculates the daily rate given an hourly rate
double daily_rate(double hourly_rate) {
    return hourly_rate * 8.0;
}

// apply_discount calculates the price after a discount
double apply_discount(double before_discount, double discount) {
    double reduction{ before_discount * discount / 100.0 };
    return before_discount - reduction;
}

// monthly_rate calculates the monthly rate, given an hourly rate and a discount
// The returned monthly rate is rounded up to the nearest integer.
int monthly_rate(double hourly_rate, double discount) {
    double daily_value{ daily_rate(hourly_rate) };
    double monthly_value{ daily_value * 22 };
    double discount_value{ apply_discount(monthly_value, discount) };

    return std::ceil(discount_value);
}

// days_in_budget calculates the number of workdays given a budget, hourly rate,
// and discount The returned number of days is rounded down (take the floor) to
// the next integer.
int days_in_budget(int budget, double hourly_rate, double discount) {
    double daily_value{ daily_rate(hourly_rate) };
    double daily_discount{ apply_discount(daily_value, discount) };
    double budget_days{ budget / daily_discount };

    return std::floor(budget_days);
}
