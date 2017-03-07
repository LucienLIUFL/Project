//
// Created by maples on 1/28/17.
//

#include "Maples.h"

void adjustDown(int * const heap, int root, int len) {
    int rootValue = heap[root];
    for (int i = 2 * root + 1; i < len; ++i) {
        i = ((i < len - 1) && (heap[i] < heap[i + 1])) ? i + 1 : i;
        if (rootValue < heap[i]) {
            rootValue = heap[i];
            root = i;
        }
    }
    heap[root] = rootValue;
}