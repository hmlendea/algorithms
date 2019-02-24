#include <stdio.h>

char maze[100001][100001];
int size_x, size_y;

int start_x, start_y;
int finish_x, finish_y;

int dir_x[4] = { 0, 1, 0, -1 };
int dir_y[4] = { -1, 0, 1, 0 };

void read_maze()
{
    FILE *f;
    int x, y;

    f = fopen("maze.in", "r");
    fscanf(f, "%d %d\n", &size_y, &size_x);

    for (x = 0; x < size_y; x++)
    {
        for (y = 0; y < size_x; y++)
        {
            fscanf(f, "%c", &maze[x][y]);

            if (maze[x][y] == 'H')
            {
                start_x = x;
                start_y = y;
            }
            else if (maze[x][y] == 'S')
            {
                finish_x = x;
                finish_y = y;
            }
        }
        fgetc(f);
    }
}

void print_maze()
{
    int x, y;
    for (x = 0; x < size_y; x++)
    {
        for (y = 0; y < size_x; y++)
            printf("%c", maze[x][y]);
        printf("\n");
    }
}

int can_escape(int x, int y)
{
    if (x < 0 || x >= size_x || y < 0 || y >= size_y)
        return 0;

    if (maze[x][y] == 'W')
        return 0;
    else if (maze[x][y] == 'S')
        return 1;
    else
        maze[x][y] = 'W';

    int i;
    for (i = 0; i < 4; i++)
        if (can_escape(x + dir_x[i], y + dir_y[i]))
            return 1;
    return 0;
}

int main(void)
{
    read_maze();
    print_maze();

    if (can_escape (start_x, start_y) == 1)
        printf("This maze is escapable!");
    else
        printf("This maze is NOT escapable!");

    return 0;
}

