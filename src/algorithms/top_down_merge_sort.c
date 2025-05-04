#include <stdlib.h>
#include "../utilities/list_printer.h"
#include "../constants/lists.h"

void top_down_copy_values_to_half_lists(const int lowest_value_index, const int middle_value_index,
                                        int list_to_be_sorted[],
                                        int first_half_list_to_be_sorted[], int second_half_list_to_be_sorted[],
                                        const int first_half_list_to_be_sorted_size,
                                        const int second_half_list_to_be_sorted_size)
{
    for (int current_first_half_list_to_be_sorted_index = 0; current_first_half_list_to_be_sorted_index <
                                                             first_half_list_to_be_sorted_size;
         current_first_half_list_to_be_sorted_index++)
        first_half_list_to_be_sorted[current_first_half_list_to_be_sorted_index] = list_to_be_sorted[lowest_value_index + current_first_half_list_to_be_sorted_index];
    for (int current_second_half_list_to_be_sorted_index = 0; current_second_half_list_to_be_sorted_index <
                                                              second_half_list_to_be_sorted_size;
         current_second_half_list_to_be_sorted_index++)
        second_half_list_to_be_sorted[current_second_half_list_to_be_sorted_index] = list_to_be_sorted[middle_value_index + 1 + current_second_half_list_to_be_sorted_index];
}

void top_down_copy_sorted_half_lists_to_list_with_all_values(const int lowest_value_index, int list_to_be_sorted[],
                                                             int first_half_list_to_be_sorted[],
                                                             int second_half_list_to_be_sorted[],
                                                             const int first_half_list_to_be_sorted_size,
                                                             const int second_half_list_to_be_sorted_size)
{
    int current_first_half_list_to_be_sorted_index = 0;
    int current_second_half_list_to_be_sorted_index = 0;
    int current_middle_value_index = lowest_value_index;

    while (current_first_half_list_to_be_sorted_index < first_half_list_to_be_sorted_size &&
           current_second_half_list_to_be_sorted_index < second_half_list_to_be_sorted_size)
    {
        if (first_half_list_to_be_sorted[current_first_half_list_to_be_sorted_index] <= second_half_list_to_be_sorted[current_second_half_list_to_be_sorted_index])
        {
            list_to_be_sorted[current_middle_value_index] = first_half_list_to_be_sorted[current_first_half_list_to_be_sorted_index];

            current_first_half_list_to_be_sorted_index++;
        }
        else
        {
            list_to_be_sorted[current_middle_value_index] = second_half_list_to_be_sorted[current_second_half_list_to_be_sorted_index];

            current_second_half_list_to_be_sorted_index++;
        }

        current_middle_value_index++;
    }

    while (current_first_half_list_to_be_sorted_index < first_half_list_to_be_sorted_size)
    {
        list_to_be_sorted[current_middle_value_index] = first_half_list_to_be_sorted[current_first_half_list_to_be_sorted_index];

        current_first_half_list_to_be_sorted_index++;
        current_middle_value_index++;
    }

    while (current_second_half_list_to_be_sorted_index < second_half_list_to_be_sorted_size)
    {
        list_to_be_sorted[current_middle_value_index] = second_half_list_to_be_sorted[current_second_half_list_to_be_sorted_index];

        current_second_half_list_to_be_sorted_index++;
        current_middle_value_index++;
    }
}

void top_down_merge_half_sorted_lists(int list_to_be_sorted[], const int lowest_value_index,
                                      const int middle_value_index,
                                      const int highest_value_index)
{
    const int first_half_list_to_be_sorted_size = middle_value_index - lowest_value_index + 1;
    const int second_half_list_to_be_sorted_size = highest_value_index - middle_value_index;
    int *first_half_list_to_be_sorted = (int *)malloc(first_half_list_to_be_sorted_size * sizeof(int));
    int *second_half_list_to_be_sorted = (int *)malloc(second_half_list_to_be_sorted_size * sizeof(int));

    top_down_copy_values_to_half_lists(lowest_value_index, middle_value_index, list_to_be_sorted,
                                       first_half_list_to_be_sorted, second_half_list_to_be_sorted,
                                       first_half_list_to_be_sorted_size, second_half_list_to_be_sorted_size);

    top_down_copy_sorted_half_lists_to_list_with_all_values(lowest_value_index, list_to_be_sorted,
                                                            first_half_list_to_be_sorted, second_half_list_to_be_sorted,
                                                            first_half_list_to_be_sorted_size,
                                                            second_half_list_to_be_sorted_size);

    free(first_half_list_to_be_sorted);
    free(second_half_list_to_be_sorted);
}

void execute_top_down_merge_sort(int list_to_be_sorted[], const int lowest_value_index, const int highest_value_index)
{
    if (lowest_value_index < highest_value_index)
    {
        const int middle_value_index = lowest_value_index + (highest_value_index - lowest_value_index) / 2;

        execute_top_down_merge_sort(list_to_be_sorted, lowest_value_index, middle_value_index);
        execute_top_down_merge_sort(list_to_be_sorted, middle_value_index + 1, highest_value_index);

        top_down_merge_half_sorted_lists(list_to_be_sorted, lowest_value_index, middle_value_index,
                                         highest_value_index);
    }
}

void sort_with_top_down_merge_sort(int list_to_be_sorted[], const int list_size)
{
    execute_top_down_merge_sort(list_to_be_sorted, 0, list_size - 1);
}

void execute_top_down_merge_sort_client()
{
    sort_with_top_down_merge_sort(UNORDERED_LIST, LIST_SIZE);

    print_list(UNORDERED_LIST, LIST_SIZE);
}
