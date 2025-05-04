#ifndef LISTS_PRINTER_HEADER
#define LISTS_PRINTER_HEADER

#include <stdio.h>

void print_list(int list[], const int list_size)
{
    printf("[ ");

    for (int i = 0; i < list_size; i++)
    {
        if (i == list_size - 1)
        {
            printf("%d", list[i]);
        }
        else
        {
            printf("%d, ", list[i]);
        }
    }

    printf(" ]");
}

#endif
