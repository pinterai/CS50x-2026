#include <cs50.h>
#include <stdio.h>

void check_sum(long num, int length, string message);

int main(void)
{
    long num = get_long("Number: ");

    int length = 0;
    long num_test = num; // template of number for calculation
    long first_2 = num; // first 2 digits of number

    string message = "";

    while (num_test > 0) // calculate length
    {
        length++;
        num_test /= 10;
    }

    for (int i = 0; i < length - 2; i++) // calculate first 2 digits
    {
        first_2 /= 10;
    }

    if (length == 15 && (first_2 == 34 || first_2 == 37)) // potentially AMEX
    {
        message = "AMEX";
        check_sum(num, length, message);
    }
    else if (length == 16 && (first_2 == 51 || first_2 == 52 || first_2 == 53 || first_2 == 54 || first_2 == 55)) // potentially MASTERCARD
    {
        message = "MASTERCARD";
        check_sum(num, length, message);
    }
    else if ((length == 13 || length == 16) && first_2 / 10 == 4) // potentially VISA
    {
        message = "VISA";
        check_sum(num, length, message);
    }
    else
    {
        printf("%s\n", "INVALID");
    }
}

void check_sum(long num, int length, string message)
{
    int multiply = 0; // initially false as we start at second number
    int final_sum = 0;

    for (int i = 0; i < length; i++)
    {
        if (multiply == 0)
        {
            final_sum += num % 10;
            multiply = 1;
        }
        else
        {
            int multiplied = (num % 10) * 2;
            if (multiplied > 9)
            {
                final_sum += (multiplied % 10) + (multiplied / 10);
            }
            else
            {
                final_sum += multiplied;
            }
            multiply = 0;
        }
        num /= 10;
    }

    if (final_sum % 10 == 0)
    {
        printf("%s\n", message);
    }
    else
    {
        printf("%s\n", "INVALID");
    }
}
