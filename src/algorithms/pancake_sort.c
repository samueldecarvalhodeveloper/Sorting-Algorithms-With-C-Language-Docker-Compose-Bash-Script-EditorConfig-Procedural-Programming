#include "../utilities/list_printer.h"
#include "../constants/lists.h"

void flip_list(int list[], int current_value_index)
{
    int list_first_index = 0;

    while (list_first_index < current_value_index)
    {
        const int item_to_be_swopt = list[list_first_index];

        list[list_first_index] = list[current_value_index];
        list[current_value_index] = item_to_be_swopt;

        list_first_index++;
        current_value_index--;
    }
}

int get_list_highest_value_index(int list[], const int list_size)
{
    int list_highest_value_index = 0;

    for (int current_value_index = 1; current_value_index < list_size; current_value_index++)
        if (list[current_value_index] > list[list_highest_value_index])
            list_highest_value_index = current_value_index;

    return list_highest_value_index;
}

void sort_with_pancake_sort(int list_to_be_sorted[], const int list_size)
{
    for (int curr_size = list_size; curr_size > 1; curr_size--)
    {
        const int list_highest_value_index = get_list_highest_value_index(list_to_be_sorted, curr_size);

        if (list_highest_value_index != curr_size - 1)
        {
            flip_list(list_to_be_sorted, list_highest_value_index);

            flip_list(list_to_be_sorted, curr_size - 1);
        }
    }
}

void execute_pancake_sort_client()
{
    sort_with_pancake_sort(UNORDERED_LIST, LIST_SIZE);

    print_list(UNORDERED_LIST, LIST_SIZE);
}
