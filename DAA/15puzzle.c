#include <stdio.h>

#define N 4

int puzzle[N][N] = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9,10,11,12},
    {13,14, 0,15}
};

void display() {
    int i, j;

    printf("\n");
    for(i = 0; i < N; i++) {
        for(j = 0; j < N; j++) {
            if(puzzle[i][j] == 0)
                printf("   ");
            else
                printf("%2d ", puzzle[i][j]);
        }
        printf("\n");
    }
}

void findBlank(int *row, int *col) {
    int i, j;

    for(i = 0; i < N; i++)
        for(j = 0; j < N; j++)
            if(puzzle[i][j] == 0) {
                *row = i;
                *col = j;
                return;
            }
}

void move(char direction) {
    int r, c;
    findBlank(&r, &c);

    switch(direction) {

        case 'U':
            if(r > 0) {
                puzzle[r][c] = puzzle[r-1][c];
                puzzle[r-1][c] = 0;
            }
            break;

        case 'D':
            if(r < N-1) {
                puzzle[r][c] = puzzle[r+1][c];
                puzzle[r+1][c] = 0;
            }
            break;

        case 'L':
            if(c > 0) {
                puzzle[r][c] = puzzle[r][c-1];
                puzzle[r][c-1] = 0;
            }
            break;

        case 'R':
            if(c < N-1) {
                puzzle[r][c] = puzzle[r][c+1];
                puzzle[r][c+1] = 0;
            }
            break;
    }
}

int isSolved() {
    int goal[N][N] = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,0}
    };

    int i, j;

    for(i = 0; i < N; i++)
        for(j = 0; j < N; j++)
            if(puzzle[i][j] != goal[i][j])
                return 0;

    return 1;
}

int main() {
    char moveDir;

    printf("15 Puzzle Game\n");

    while(1) {
        display();

        if(isSolved()) {
            printf("\nPuzzle Solved!\n");
            break;
        }

        printf("\nEnter move (U/D/L/R): ");
        scanf(" %c", &moveDir);

        move(moveDir);
    }

    return 0;
}
