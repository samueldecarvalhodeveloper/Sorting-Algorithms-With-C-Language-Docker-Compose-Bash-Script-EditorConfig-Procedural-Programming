#include "../utilities/list_printer.h"
#include "../constants/lists.h"

int get_pivot_element_correct_index(int list_to_be_sorted[], const int lowest_value_index,
                                    const int highest_value_index)
{
    const int pivot_value_index = list_to_be_sorted[highest_value_index];
    int current_lowest_value_index = lowest_value_index - 1;

    for (int current_value_index = lowest_value_index; current_value_index < highest_value_index; current_value_index++)
    {
        if (list_to_be_sorted[current_value_index] < pivot_value_index)
        {
            current_lowest_value_index++;

            const int item_to_be_swopt = list_to_be_sorted[current_lowest_value_index];

            list_to_be_sorted[current_lowest_value_index] = list_to_be_sorted[current_value_index];

            list_to_be_sorted[current_value_index] = item_to_be_swopt;
        }
    }

    const int item_to_be_swopt = list_to_be_sorted[current_lowest_value_index + 1];

    list_to_be_sorted[current_lowest_value_index + 1] = list_to_be_sorted[highest_value_index];

    list_to_be_sorted[highest_value_index] = item_to_be_swopt;

    return current_lowest_value_index + 1;
}

void execute_quick_sort(int list_to_be_sorted[], const int lowest_value_index, const int highest_value_index)
{
    if (lowest_value_index < highest_value_index)
    {
        const int pivot_value_index = get_pivot_element_correct_index(list_to_be_sorted, lowest_value_index,
                                                                      highest_value_index);

        execute_quick_sort(list_to_be_sorted, lowest_value_index, pivot_value_index - 1);

        execute_quick_sort(list_to_be_sorted, pivot_value_index + 1, highest_value_index);
    }
}

void sort_with_quick_sort(int list_to_be_sorted[], const int list_size)
{
    execute_quick_sort(list_to_be_sorted, 0, list_size - 1);
}

void execute_quick_sort_client()
{
    sort_with_quick_sort(UNORDERED_LIST, LIST_SIZE);

    print_list(UNORDERED_LIST, LIST_SIZE);
}
