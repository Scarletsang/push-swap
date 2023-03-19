#include <stdio.h>
#include <stdlib.h>

typedef void	(*t_printer)(int groups[][2], int numGroups, const int amount);

void printStacks(int groups[][2], int numGroups, const int amount) {
	int	*stack;
	int i;
	stack = malloc(sizeof(int) * amount);
	for (i = 0; i < numGroups; i++) {
		stack[groups[i][0] - 1] = i * 2;
		stack[groups[i][1] - 1] = (i * 2) + 1;
	}
	for (i = 0; i < (amount - 1); i++) {
		printf("%d ", stack[i]);
	}
	printf("%d", stack[i]);
	printf("\n");
	free(stack);
}

void printGroups(int groups[][2], int numGroups, const int amount) {
    int i;
    printf("(");
    for (i = 0; i < numGroups; i++) {
        printf("(%d, %d)", groups[i][0], groups[i][1]);
        if (i < numGroups - 1) {
            printf(", ");
        }
    }
    printf(")\n");
}

void generateGroups(int groups[][2], int numGroups, int numbers[], const int amount, int used[], t_printer printer) {
    if (numGroups == ((amount + 1) / 2)) {
        printer(groups, numGroups, amount);
        return;
    }
    int i, j;
    for (i = 0; i < amount; i++) {
        if (!used[i]) {
			printf("hi%d %d\n", numGroups, i);
            for (j = i + 1; j < amount; j++) {
                if (!used[j]) {
                    groups[numGroups][0] = numbers[i];
                    groups[numGroups][1] = numbers[j];
                    used[i] = 1;
                    used[j] = 1;
                    generateGroups(groups, numGroups + 1, numbers, amount, used, printer);
                    used[i] = 0;
                    used[j] = 0;
                }
            }
        }
    }
}

int main(int argc, char **argv) {
	if (argc != 3) {return 1;}
	t_printer printers[2] = {printStacks, printGroups};
	const int amount = atoi(argv[1]);
    int numbers[6] = {1, 2, 3, 4, 5, 6};
    int used[6] = {0};
    int groups[(amount + 1)/ 2][2];
    generateGroups(groups, 0, numbers, amount, used, printers[atoi(argv[2])]);
    return 0;
}
