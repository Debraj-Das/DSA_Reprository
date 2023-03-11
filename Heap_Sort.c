#include <stdio.h>
#include <stdlib.h>

void solve();

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    // scanf("%d",&t);
    while (t--)
        solve();

    return 0;
}

void heapify(int arr[], int n, int index)   //# This Case index Start With 1 not Zero for Calculation Purpose
{
    // if index is leaf node then return
    if ((2 * index) > n)
        return;
    // find out the min vaule index from the right and left child of the index node
    int min_index = (2 * index == n) ? 2 * index : (arr[2 * index - 1] > arr[2 * index]) ? (2 * index)
                                                                                         : (2 * index + 1);
    // Swap the index with min_index if the min_index vaule in bigger than the index
    if (arr[index - 1] < arr[min_index - 1])
    {
        int temp = arr[index - 1];
        arr[index - 1] = arr[min_index - 1];
        arr[min_index - 1] = temp;
    }

    // Calling the heapify function for min_index
    heapify(arr, n, min_index);
    return;
}

void build_heap(int arr[], int n)
{
    // Try see all the index is satisfy the heap property so run heapify for all element
    for (int i = n; i > 0; i--)
        heapify(arr, n, i);

    return;
}

void Heap_Sort(int arr[], int n)
{
    build_heap(arr, n); // Max Heap convert
    for (int i = 1, temp; i < n; i++)
    {
        // Exchange of the First element and last unsorted element
        temp = arr[n - i];
        arr[n - i] = arr[0];
        arr[0] = temp;
        // Heapify the Zeroth element because of exchange
        heapify(arr, n - i, 1);
    }
    return;
}

void solve()
{
    // n number of the element and take those element as input from user
    int n;
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    for (size_t i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Sort the element by Heap Sort Method, Time Complexity is O(n*ln(n)) and Space Complexity O(1)
    Heap_Sort(arr, n);

    // print the heap
    printf("Heap Sort ::\n\t");
    for (size_t i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    free(arr);
    return;
}

