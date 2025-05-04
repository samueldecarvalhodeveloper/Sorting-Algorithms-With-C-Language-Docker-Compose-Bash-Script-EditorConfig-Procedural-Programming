#include "../utilities/list_printer.h"
#include "../constants/lists.h"

void execute_three_way_quick_sort(int list_to_be_sorted[], const int lowest_value_index, const int highest_value_index)
{
    if (lowest_value_index >= highest_value_index)
        return;

    int lower_than_pivot_value_index = lowest_value_index;
    int greater_than_pivot_value_index = highest_value_index;
    int current_value_being_examined_index = lowest_value_index + 1;
    const int pivot_value_index = list_to_be_sorted[lowest_value_index];

    while (current_value_being_examined_index <= greater_than_pivot_value_index)
    {
        if (list_to_be_sorted[current_value_being_examined_index] < pivot_value_index)
        {
            const int item_to_be_swopt = list_to_be_sorted[current_value_being_examined_index];

            list_to_be_sorted[current_value_being_examined_index] = list_to_be_sorted[lower_than_pivot_value_index];

            list_to_be_sorted[lower_than_pivot_value_index] = item_to_be_swopt;

            lower_than_pivot_value_index++;
            current_value_being_examined_index++;
        }
        else if (list_to_be_sorted[current_value_being_examined_index] > pivot_value_index)
        {
            const int item_to_be_swopt = list_to_be_sorted[current_value_being_examined_index];

            list_to_be_sorted[current_value_being_examined_index] = list_to_be_sorted[greater_than_pivot_value_index];

            list_to_be_sorted[greater_than_pivot_value_index] = item_to_be_swopt;

            greater_than_pivot_value_index--;
        }
        else
            current_value_being_examined_index++;
    }

    execute_three_way_quick_sort(list_to_be_sorted, lowest_value_index, lower_than_pivot_value_index - 1);
    execute_three_way_quick_sort(list_to_be_sorted, greater_than_pivot_value_index + 1, highest_value_index);
}

void sort_with_three_way_quick_sort(int list_to_be_sorted[], const int list_size)
{
    execute_three_way_quick_sort(list_to_be_sorted, 0, list_size - 1);
}

void execute_three_way_quick_sort_client()
{
    sort_with_three_way_quick_sort(UNORDERED_LIST, LIST_SIZE);

    print_list(UNORDERED_LIST, LIST_SIZE);
}
