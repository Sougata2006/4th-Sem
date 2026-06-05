#include <stdio.h>
#include <stdlib.h>

int x[8]; // x[i] stores column position of queen in row i

// Check whether queen can be placed at row k, column i
int place(int k, int i) {
    int j;

    for (j = 0; j < k; j++) {
        if (x[j] == i || abs(x[j] - i) == abs(j - k))
            return 0;
    }
    return 1;
}

// Solve 8-Queen problem
void queen(int k) {
    int i, j;

    for (i = 0; i < 8; i++) {
        if (place(k, i)) {
            x[k] = i;

            if (k == 7) {
                printf("\nSolution:\n");
                for (j = 0; j < 8; j++)
                    printf("Row %d -> Column %d\n", j + 1, x[j] + 1);
            }
            else {
                queen(k + 1);
            }
        }
    }
}

int main() {
    queen(0);
    return 0;
}
