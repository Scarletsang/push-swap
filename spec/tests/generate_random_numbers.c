#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <number of non-repeating numbers to generate>\n", argv[0]);
    return 1;
  }

  int n = atoi(argv[1]);
  if (n <= 0) {
    printf("Please enter a positive integer.\n");
    return 1;
  }

  int i, j, temp;
  int	*nums;

  nums = malloc(n * sizeof(int));

  // Initialize the array with values 1 to n
  for (i = 0; i < n; i++) {
    nums[i] = i + 1;
  }

  // Shuffle the array using the Fisher-Yates algorithm
  srand(time(NULL));
  for (i = n-1; i > 0; i--) {
    j = rand() % (i+1);
    temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
  }

  // Print the first n elements of the shuffled array
  for (i = 0; i < n; i++) {
    printf("%d ", nums[i]);
  }
  free(nums);
  return 0;
}
