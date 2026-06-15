#include "../utilities/list_printer.h"
#include "../constants/lists.h"

int get_correct_item_index(const int current_item_index, const int current_list_gap, const int item_to_be_swopt,
                           int list_to_be_sorted[])
{
    int correct_item_index = current_item_index;

    while (correct_item_index >= current_list_gap && list_to_be_sorted[correct_item_index - current_list_gap] >
                                                         item_to_be_swopt)
    {
        list_to_be_sorted[correct_item_index] = list_to_be_sorted[correct_item_index - current_list_gap];

        correct_item_index -= current_list_gap;
    }

    return correct_item_index;
}

void execute_insertion_sort(const int current_list_gap, const int list_size, int list_to_be_sorted[])
{
    for (int current_item_index = current_list_gap; current_item_index < list_size; current_item_index++)
    {
        const int item_to_be_swopt = list_to_be_sorted[current_item_index];

        const int current_item_correct_index = get_correct_item_index(current_item_index, current_list_gap,
                                                                      item_to_be_swopt, list_to_be_sorted);

        list_to_be_sorted[current_item_correct_index] = item_to_be_swopt;
    }
}

void sort_with_shell_sort(int list_to_be_sorted[], const int list_size)
{
    for (int current_list_gap = list_size / 2; current_list_gap > 0; current_list_gap /= 2)
        execute_insertion_sort(
            current_list_gap, list_size, list_to_be_sorted);
}

void execute_shell_sort_client()
{
    sort_with_shell_sort(UNORDERED_LIST, LIST_SIZE);

    print_list(UNORDERED_LIST, LIST_SIZE);
}
