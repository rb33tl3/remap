
#include <stdio.h>

int visited[11][8][5];
int capacity[3] = {10, 7, 4};

int solve(int a, int b, int c)
{
    int x[1000], y[1000], z[1000];
    int front = 0, rear = 0;
    int i, j, amount;
    int v[3], next[3];

    x[rear] = a;
    y[rear] = b;
    z[rear++] = c;

    visited[a][b][c] = 1;

    while (front < rear)
    {
        a = x[front];
        b = y[front];
        c = z[front++];

        printf("(%d, %d, %d)\n", a, b, c);

        if (b == 2 || c == 2)
        {
            printf("Goal reached!\n");
            return 1;
        }

        v[0] = a;
        v[1] = b;
        v[2] = c;

        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                if (i == j)
                    continue;

                amount = v[i];

                if (capacity[j] - v[j] < amount)
                    amount = capacity[j] - v[j];

                if (amount == 0)
                    continue;

                next[0] = v[0];
                next[1] = v[1];
                next[2] = v[2];

                next[i] -= amount;
                next[j] += amount;

                if (!visited[next[0]][next[1]][next[2]])
                {
                    visited[next[0]][next[1]][next[2]] = 1;

                    x[rear] = next[0];
                    y[rear] = next[1];
                    z[rear++] = next[2];
                }
            }
        }
    }

    printf("Goal not found!\n");
    return 0;
}

int main()
{
    printf("States visited:\n");
    solve(0, 7, 4);

    return 0;
}
