#include <iostream>
#include <fstream>
using namespace std;

char stk[500][20];
int top = -1;

void push(char* s) {
    top++;
    int i = 0;
    while (s[i] != '\0') {
        stk[top][i] = s[i];
        i++;
    }
    stk[top][i] = '\0';
}

void pop(char* result) {
    int i = 0;
    while (stk[top][i] != '\0') {
        result[i] = stk[top][i];
        i++;
    }
    result[i] = '\0';
    top--;
}

void peek(char* result) {
    int i = 0;
    while (stk[top][i] != '\0') {
        result[i] = stk[top][i];
        i++;
    }
    result[i] = '\0';
}

bool isOperator(char* s) {
    return (s[1] == '\0' && (s[0] == '+' || s[0] == '-' || s[0] == '*' || s[0] == '/'));
}

bool isOpenBracket(char* s) {
    return (s[0] == '(' && s[1] == '\0');
}

bool isCloseBracket(char* s) {
    return (s[0] == ')' && s[1] == '\0');
}

bool isOperandChar(char ch) {
    return ((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'));
}

bool same(char* a, char* b) {
    int i = 0;
    while (a[i] != '\0' && b[i] != '\0') {
        if (a[i] != b[i]) return false;
        i++;
    }
    return (a[i] == '\0' && b[i] == '\0');
}

int main() {
    char line[1000];

    ifstream fin("infix.txt");
    int li = 0;
    char ch;
    while (fin.get(ch) && ch != '\n') {
        line[li++] = ch;
    }
    line[li] = '\0';
    fin.close();

    char tokens[500][20];
    int tokenCount = 0;

    int i = 0;
    while (line[i] != '\0') {
        if (line[i] == ' ') {
            i++;
            continue;
        }

        if (isOperandChar(line[i])) {
            int k = 0;
            while (line[i] != '\0' && line[i] != ' ' && line[i] != '(' && line[i] != ')' &&
                   line[i] != '+' && line[i] != '-' && line[i] != '*' && line[i] != '/') {
                tokens[tokenCount][k++] = line[i++];
            }
            tokens[tokenCount][k] = '\0';
            tokenCount++;
        } else {
            tokens[tokenCount][0] = line[i];
            tokens[tokenCount][1] = '\0';
            tokenCount++;
            i++;
        }
    }

    char output[500][20];
    int outCount = 0;

    for (int t = 0; t < tokenCount; t++) {
        char* token = tokens[t];

        if (!isOperator(token) && !isOpenBracket(token) && !isCloseBracket(token)) {
            int k = 0;
            while (token[k] != '\0') {
                output[outCount][k] = token[k];
                k++;
            }
            output[outCount][k] = '\0';
            outCount++;
        } else if (isOpenBracket(token)) {
            push(token);
        } else if (isOperator(token)) {
            push(token);
        } else if (isCloseBracket(token)) {
            char temp[20];
            while (top != -1) {
                peek(temp);
                if (isOpenBracket(temp)) {
                    pop(temp);
                    break;
                }
                pop(temp);
                int k = 0;
                while (temp[k] != '\0') {
                    output[outCount][k] = temp[k];
                    k++;
                }
                output[outCount][k] = '\0';
                outCount++;
            }
        }
    }

    while (top != -1) {
        char temp[20];
        pop(temp);
        int k = 0;
        while (temp[k] != '\0') {
            output[outCount][k] = temp[k];
            k++;
        }
        output[outCount][k] = '\0';
        outCount++;
    }

    ofstream fout("postfix.txt");
    for (int o = 0; o < outCount; o++) {
        if (o != 0) fout << " ";
        fout << output[o];
    }
    fout << "\n";
    fout.close();

    return 0;
}
