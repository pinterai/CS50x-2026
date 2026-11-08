#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height = get_int("What's height? ");

    while (height < 0)
    {
        height = get_int("What's height? ");
    }

    for (int row = 1; row <= height; row++)
    {
        for (int spaces = 0; spaces < height-row; spaces++)
        {
            printf(" ");
        }
        for (int hashes = 0; hashes < row; hashes++)
        {
            printf("#");
        }

        printf("\n");
    }
}
