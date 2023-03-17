#include <stdio.h>

typedef void	(*t_printer)(int groups[][2], int numGroups);

void printStacks(int groups[][2], int numGroups) {
	int	stack[6] = {0};
	int i;
	for (i = 0; i < numGroups; i++) {
		stack[groups[i][0] - 1] = i * 2;
		stack[groups[i][1] - 1] = (i * 2) + 1;
	}
	for (i = 0; i < 5; i++) {
		printf("%d ", stack[i]);
	}
	printf("%d", stack[i]);
	printf("\n");
}

void printGroups(int groups[][2], int numGroups) {
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

void generateGroups(int groups[][2], int numGroups, int numbers[], int used[], t_printer printer) {
    if (numGroups == 3) {
        printer(groups, numGroups);
        return;
    }

    int i, j;
    for (i = 0; i < 6; i++) {
        if (!used[i]) {
            for (j = i + 1; j < 6; j++) {
                if (!used[j]) {
                    groups[numGroups][0] = numbers[i];
                    groups[numGroups][1] = numbers[j];
                    used[i] = 1;
                    used[j] = 1;
                    generateGroups(groups, numGroups + 1, numbers, used, printer);
                    used[i] = 0;
                    used[j] = 0;
                }
            }
        }
    }
}

int main() {
    int numbers[6] = {1, 2, 3, 4, 5, 6};
    int used[6] = {0};
    int groups[3][2];
    generateGroups(groups, 0, numbers, used, printStacks);
    return 0;
}
