#include <stdio.h>
#include <cs50.h>

void print_chars(string character, int count);

int main(void)
{
    string hash = "#";
    string space = " ";


    int height = 0;
    do {
        height = get_int("What's height: ");
    } while (height < 0);

    for (int row = 1; row <= height; row++)
    {

        print_chars(space, height-row);
        print_chars(hash, row);

        printf("  ");

        print_chars(hash, row);

        printf("\n");
    }
}


void print_chars(string character, int count)
{
    for (int i = 0; i < count; i++)
    {
        printf("%s", character);
    }
}

