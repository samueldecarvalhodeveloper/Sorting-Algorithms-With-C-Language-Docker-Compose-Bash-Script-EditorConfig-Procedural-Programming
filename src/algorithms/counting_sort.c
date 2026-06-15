#include <stdlib.h>
#include "../utilities/list_printer.h"
#include "../constants/lists.h"

int get_list_highest_value(int list[], const int list_size)
{
    int list_highest_value = list[0];

    for (int current_value_index = 1; current_value_index < list_size; current_value_index++)
        if (list[current_value_index] > list_highest_value)
            list_highest_value = list[current_value_index];

    return list_highest_value;
}

void populate_list_of_value_frequencies(int list_to_be_sorted[], int list_of_value_frequencies[], const int list_size)
{
    for (int current_value_index = 0; current_value_index < list_size; current_value_index++)
        list_of_value_frequencies[list_to_be_sorted[current_value_index]]++;
}

void populate_list_of_value_frequencies_with_fequencies_cumulative_sume(int *list_of_value_frequencies,
                                                                        const int list_highest_value)
{
    for (int current_value_index = 1; current_value_index <= list_highest_value; current_value_index++)
        list_of_value_frequencies[current_value_index] += list_of_value_frequencies[current_value_index - 1];
}

void build_list_of_sorted_values(int list_of_sorted_values[], int list_of_value_frequencies[], int list_to_be_sorted[],
                                 const int list_size)
{
    for (int current_value_index = list_size - 1; current_value_index >= 0; current_value_index--)
    {
        list_of_sorted_values[list_of_value_frequencies[list_to_be_sorted[current_value_index]] - 1] = list_to_be_sorted[current_value_index];

        list_of_value_frequencies[list_to_be_sorted[current_value_index]]--;
    }
}

void copy_back_sorted_values_to_list_to_be_sorted(int list_to_be_sorted[], const int *list_of_sorted_values,
                                                  const int list_size)
{
    for (int current_value_index = 0; current_value_index < list_size; current_value_index++)
        list_to_be_sorted[current_value_index] = list_of_sorted_values[current_value_index];
}

void sort_with_counting_sort(int list_to_be_sorted[], const int list_size)
{
    const int list_highest_value = get_list_highest_value(list_to_be_sorted, list_size);
    int *list_of_value_frequencies = (int *)calloc(list_highest_value + 1, sizeof(int));
    int *list_of_sorted_values = (int *)malloc(list_size * sizeof(int));

    populate_list_of_value_frequencies(list_to_be_sorted, list_of_value_frequencies, list_size);

    populate_list_of_value_frequencies_with_fequencies_cumulative_sume(list_of_value_frequencies, list_highest_value);

    build_list_of_sorted_values(list_of_sorted_values, list_of_value_frequencies, list_to_be_sorted, list_size);

    copy_back_sorted_values_to_list_to_be_sorted(list_to_be_sorted, list_of_sorted_values, list_size);

    free(list_of_value_frequencies);
    free(list_of_sorted_values);
}

void execute_counting_sort_client()
{
    sort_with_counting_sort(UNORDERED_LIST, LIST_SIZE);

    print_list(UNORDERED_LIST, LIST_SIZE);
}
