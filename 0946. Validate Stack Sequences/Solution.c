#include <stdbool.h>

bool validateStackSequences(int* pushed, int pushedSize, int* popped, int poppedSize)
{
    int stack[pushedSize];
    int tp = 0, j = 0;
    for (int i = 0; i < pushedSize; ++i) {
        stack[tp++] = pushed[i];
        while (tp && stack[tp - 1] == popped[j]) {
            --tp;
            ++j;
        }
    }
    return !tp;
}
