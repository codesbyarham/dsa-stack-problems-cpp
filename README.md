# DSA Stack Problems in C++

Classic Data Structure problems solved using a custom-built Stack in C++. No STL stack used. All stack operations are implemented from scratch.

---

## Problems

### Task 1 — Rat in a Maze
### Task 2 — Infix to Postfix Conversion

---

## Task 1 — Rat in a Maze

A rat starts at the top-left cell `maze[0][0]` and needs to reach the bottom-right cell `maze[N-1][N-1]`. The maze is an N×N binary matrix where `1` means the cell is walkable and `0` means it is a dead end. The rat can move in four directions: up, down, left, and right.

The program uses an iterative DFS approach with a custom stack to find the path. Visited cells are marked as `-1`. If a path is found, the solution matrix is written to the output file. If no path exists, `PATH NOT FOUND` is written instead.

**Input file:** `input.txt`
**Output file:** `output.txt`

#### Sample Input (`input.txt`)
```
1 0 0 0
1 1 0 1
0 1 0 0
1 1 1 1
```

#### Sample Output (`output.txt`)
```
1 0 0 0
1 1 0 0
0 1 0 0
0 1 1 1
```

#### How to Run
```bash
g++ task1_maze.cpp -o maze
./maze
```
Make sure `input.txt` is in the same directory as the executable.

---

## Task 2 — Infix to Postfix Conversion

Takes a fully parenthesized infix expression and converts it to postfix (Reverse Polish Notation) using a custom stack. Supports multi-digit numbers and single-letter variables. No negative numbers.

**Input file:** `infix.txt`
**Output file:** `postfix.txt`

#### Sample Input (`infix.txt`)
```
( ( ( 12 + 13 ) * ( 20 - 30 ) ) / ( 811 + 99 ) )
```

#### Sample Output (`postfix.txt`)
```
12 13 + 20 30 - * 811 99 + /
```

#### How to Run
```bash
g++ task2_infix_to_postfix.cpp -o postfix
./postfix
```
Make sure `infix.txt` is in the same directory as the executable.

---

## Topics Covered

| Topic | Task |
|---|---|
| Custom Stack Implementation | Both |
| Iterative DFS | Task 1 |
| Backtracking | Task 1 |
| 2D Array Manipulation | Task 1 |
| Path Tracing via Parent Array | Task 1 |
| Expression Parsing & Tokenization | Task 2 |
| Infix to Postfix Algorithm | Task 2 |
| Manual String Handling (no strcpy/strlen) | Task 2 |
| File I/O | Both |

---

## Requirements

- C++ compiler (g++ recommended)
- No external libraries needed

---

## Course

**Data Structures and Algorithms**
Faculty of Information Technology — University of Central Punjab
