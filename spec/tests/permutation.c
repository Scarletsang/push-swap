#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y) {
    int temp = *x;

    *x = *y;
    *y = temp;
}

void permute(int n) {
    int i, j, k;
    int arr[n];

    for (i = 0; i < n; i++) arr[i] = i + 1;
    while (1) {
        for (i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        i = n - 2;
        while (i >= 0 && arr[i] > arr[i+1]) {
            i--;
        }
        if (i < 0) {
            break;
        }
        j = n - 1;
        while (arr[i] > arr[j]) {
            j--;
        }
        swap(&arr[i], &arr[j]);
        k = i + 1;
        j = n - 1;
        while (k < j) {
            swap(&arr[k], &arr[j]);
            k++;
            j--;
        }
    }
}

int	main(int argc, const char **argv) {
	if (argc == 2)
	{
		permute(atoi(argv[1]));
	}
    return (EXIT_SUCCESS);
}