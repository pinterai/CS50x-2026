#include <stdio.h>
#include <cs50.h>

int calculate_coins(int change, int unit);

int main(void)
{
    int change = 0;
    int coins = 0;

    const int quarters = 25;
    const int dimes = 10;
    const int nickels = 5;
    const int pennies = 1;

    do {
        change = get_int("Enter change: ");
    } while (change < 0);

    coins += calculate_coins(change, quarters);
    change %= quarters;

    coins += calculate_coins(change, dimes);
    change %= dimes;

    coins += calculate_coins(change, nickels);
    change %= nickels;

    coins += change;

    printf("%i\n", coins);
}

int calculate_coins(int change, int unit)
{
    return change / unit;
}
