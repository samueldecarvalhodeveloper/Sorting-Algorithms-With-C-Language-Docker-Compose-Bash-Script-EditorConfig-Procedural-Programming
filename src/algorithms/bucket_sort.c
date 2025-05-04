#include <stdlib.h>
#include "./insertion_sort.h"
#include "../utilities/list_printer.h"
#include "../constants/lists.h"

typedef struct bucket
{
    int *list_of_elements;
    int list_of_elements_size;
} bucket;

void initialize_list_of_buckets(bucket *list_of_buckets, const int list_size)
{
    for (int current_bucket = 0; current_bucket < list_size; current_bucket++)
    {
        list_of_buckets[current_bucket].list_of_elements = (int *)malloc(list_size * sizeof(int));

        list_of_buckets[current_bucket].list_of_elements_size = 0;
    }
}

void place_values_into_its_correct_bucket(bucket *list_of_buckets, int list_to_be_sorted[], const int list_size, const int highest_value_from_list)
{
    for (int current_index = 0; current_index < list_size; current_index++)
    {
        int bucket_index = (list_to_be_sorted[current_index] * list_size) / (highest_value_from_list + 1);

        list_of_buckets[bucket_index].list_of_elements[list_of_buckets[bucket_index].list_of_elements_size++] = list_to_be_sorted[current_index];
    }
}

void sort_buckets(bucket *list_of_buckets, const int list_size)
{
    for (int current_bucket = 0; current_bucket < list_size; current_bucket++)
        sort_with_insertion_sort(list_of_buckets[current_bucket].list_of_elements, list_of_buckets[current_bucket].list_of_elements_size);
}

void gather_sorted_buckets(const bucket *list_of_buckets, int list_to_be_sorted[], const int list_size)
{
    int current_list_to_be_sorted_index = 0;

    for (int current_bucket_index = 0; current_bucket_index < list_size; current_bucket_index++)
    {
        for (int current_value_index = 0; current_value_index < list_of_buckets[current_bucket_index].list_of_elements_size; current_value_index++)
        {
            list_to_be_sorted[current_list_to_be_sorted_index++] = list_of_buckets[current_bucket_index].list_of_elements[current_value_index];
        }
    }
}

int get_highest_value_from_list(int list_to_be_sorted[], const int list_size)
{
    int highest_value_from_list = list_to_be_sorted[0];

    for (int i = 1; i < list_size; i++)
    {
        if (list_to_be_sorted[i] > highest_value_from_list)
            highest_value_from_list = list_to_be_sorted[i];
    }

    return highest_value_from_list;
}

void sort_with_bucket_sort(int list_to_be_sorted[], const int list_size)
{
    int highest_value_from_list = get_highest_value_from_list(list_to_be_sorted, list_size);

    bucket *list_of_buckets = malloc(list_size * sizeof(bucket));

    initialize_list_of_buckets(list_of_buckets, list_size);

    place_values_into_its_correct_bucket(list_of_buckets, list_to_be_sorted, list_size, highest_value_from_list);

    sort_buckets(list_of_buckets, list_size);

    gather_sorted_buckets(list_of_buckets, list_to_be_sorted, list_size);

    for (int i = 0; i < list_size; i++)
        free(list_of_buckets[i].list_of_elements);

    free(list_of_buckets);
}

void execute_bucket_sort_client()
{
    sort_with_bucket_sort(UNORDERED_LIST, LIST_SIZE);

    print_list(UNORDERED_LIST, LIST_SIZE);
}
