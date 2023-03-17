#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int compareGroups(int groups1[][2], int groups2[][2]) {
    // sort the groups in both arrays
    qsort(groups1, 3, sizeof(int[2]), 
        (int (*)(const void *, const void *)) memcmp);
    qsort(groups2, 3, sizeof(int[2]), 
        (int (*)(const void *, const void *)) memcmp);

    // compare the sorted groups
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 2; j++) {
            if (groups1[i][j] != groups2[i][j]) {
                return 0;
            }
        }
    }

    return 1;
}

void generateGroups(int groups[][2], int numGroups, int numbers[], int used[], int* numPrinted, int printed[][3][2]) {
    if (numGroups == 3) {
        // check if the groups have already been printed
        int i;
        for (i = 0; i < *numPrinted; i++) {
            if (compareGroups(groups, printed[i])) {
                return;
            }
        }

        // add the groups to the printed list and increment the count
        for (i = 0; i < 3; i++) {
            printed[*numPrinted][i][0] = groups[i][0];
            printed[*numPrinted][i][1] = groups[i][1];
        }
        (*numPrinted)++;

        // print the groups
        printGroups(groups, numGroups);
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
                    generateGroups(groups, numGroups + 1, numbers, used, numPrinted, printed);
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
    int numPrinted = 0;
    int printed[20][3][2];  // store up to 20 sets of groups

    generateGroups(groups, 0, numbers, used, &numPrinted, printed);

    return 0;
}
