#include <iostream>
#include <fstream>
using namespace std;

int maze[10][10];
int solution[10][10];
int parentRow[10][10];
int parentCol[10][10];
int N;

struct Cell {
    int row, col;
};

Cell stk[100];
int top = -1;

void push(Cell c) {
    stk[++top] = c;
}

Cell pop() {
    return stk[top--];
}

bool isEmpty() {
    return top == -1;
}

bool isValid(int r, int c) {
    return (r >= 0 && r < N && c >= 0 && c < N && maze[r][c] == 1);
}

int main() {
    ifstream fin("input.txt");

    N = 0;
    int val;
    int row = 0, col = 0;

    while (fin >> val) {
        maze[row][col] = val;
        col++;
        if (col == 4) {
            col = 0;
            row++;
            N++;
        }
    }
    fin.close();

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            parentRow[i][j] = -1;
            parentCol[i][j] = -1;
            solution[i][j] = 0;
        }

    int dr[] = {1, 0, -1, 0};
    int dc[] = {0, 1, 0, -1};

    Cell start;
    start.row = 0;
    start.col = 0;
    push(start);
    maze[0][0] = -1;

    bool found = false;

    while (!isEmpty()) {
        Cell cur = pop();
        int r = cur.row;
        int c = cur.col;

        if (r == N - 1 && c == N - 1) {
            found = true;
            break;
        }

        for (int d = 0; d < 4; d++) {
            int nr = r + dr[d];
            int nc = c + dc[d];
            if (isValid(nr, nc)) {
                Cell next;
                next.row = nr;
                next.col = nc;
                push(next);
                maze[nr][nc] = -1;
                parentRow[nr][nc] = r;
                parentCol[nr][nc] = c;
            }
        }
    }

    ofstream fout("output.txt");

    if (!found) {
        fout << "PATH NOT FOUND";
    } else {
        int r = N - 1, c = N - 1;
        while (!(r == 0 && c == 0)) {
            solution[r][c] = 1;
            int pr = parentRow[r][c];
            int pc = parentCol[r][c];
            r = pr;
            c = pc;
        }
        solution[0][0] = 1;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (j != 0) fout << " ";
                fout << solution[i][j];
            }
            fout << "\n";
        }
    }

    fout.close();
    return 0;
}
