#include "../utilities/list_printer.h"
#include "../constants/lists.h"

int get_list_lowest_value(int list_to_be_sorted[], const int current_item_index, const int list_size)
{
    int list_lowest_element_index = current_item_index;

    for (int current_index = current_item_index + 1; current_index < list_size; current_index++)
        if (list_to_be_sorted[current_index] < list_to_be_sorted[list_lowest_element_index])
            list_lowest_element_index =
                current_index;

    return list_lowest_element_index;
}

void sort_with_selection_sort(int list_to_be_sorted[], const int list_size)
{
    for (int current_item_index = 0; current_item_index < list_size - 1; current_item_index++)
    {
        const int list_lowest_element_index = get_list_lowest_value(list_to_be_sorted, current_item_index, list_size);

        if (list_lowest_element_index != current_item_index)
        {
            const int item_to_be_swopt = list_to_be_sorted[current_item_index];

            list_to_be_sorted[current_item_index] = list_to_be_sorted[list_lowest_element_index];

            list_to_be_sorted[list_lowest_element_index] = item_to_be_swopt;
        }
    }
}

void execute_selection_sort_client()
{
    sort_with_selection_sort(UNORDERED_LIST, LIST_SIZE);

    print_list(UNORDERED_LIST, LIST_SIZE);
}
