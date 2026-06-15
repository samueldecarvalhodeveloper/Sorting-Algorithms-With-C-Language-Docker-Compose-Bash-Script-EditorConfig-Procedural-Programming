#ifndef INSERTION_SORT_HEADER
#define INSERTION_SORT_HEADER

#include "../utilities/list_printer.h"
#include "../constants/lists.h"

void shift_item_to_list_right_position(int list_to_be_sorted[], const int current_item, const int current_item_index)
{
    int current_value_index = current_item_index;

    while (current_value_index > 0 && list_to_be_sorted[current_value_index - 1] > current_item)
    {
        list_to_be_sorted[current_value_index] = list_to_be_sorted[current_value_index - 1];

        current_value_index--;
    }

    list_to_be_sorted[current_value_index] = current_item;
}

void sort_with_insertion_sort(int list_to_be_sorted[], const int list_size)
{
    for (int current_item_index = 1; current_item_index < list_size; current_item_index++)
    {
        const int current_item = list_to_be_sorted[current_item_index];

        shift_item_to_list_right_position(list_to_be_sorted, current_item, current_item_index);
    }
}

void execute_insertion_sort_client()
{
    sort_with_insertion_sort(UNORDERED_LIST, LIST_SIZE);

    print_list(UNORDERED_LIST, LIST_SIZE);
}

#endif
