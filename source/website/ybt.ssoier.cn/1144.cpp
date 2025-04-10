#include <cstdio>
#include <stdio.h>

struct Stack {
    int   top = -1;
    char *data;

    void push(char x) { data[++top] = x; }

    char pop() { return data[top--]; }

    bool isEmpty() { return top == -1; }
};

int    sstop = -1;
Stack *sstack[500];

void newWord() {
    sstack[++sstop]     = new Stack;
    sstack[sstop]->data = new char[500];
    sstack[sstop]->top  = -1;
}

void printWord(Stack *s) {
    while (!s->isEmpty())
        putchar(s->pop());
    putchar(' ');

    delete[] s->data;
    delete s;
}

void push(char c) { sstack[sstop]->push(c); }

void input() {
    char c;
    newWord();
    while (true) {
        c = getchar();
        if (c == '\n' || c == '\r' || c == EOF)
            break;
        if (c == ' ')
            newWord();
        else
            push(c);
    }
}

void process() {}

void output() {
    for (int i = 0; i <= sstop; ++i)
        printWord(sstack[i]);
    printf("\n");
}

int main() {
    input();
    process();
    output();
    return 0;
}
