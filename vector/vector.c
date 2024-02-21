#include "vector.h"

vector createVector(size_t n) {
    vector v;
    v.data = malloc(n * sizeof(int));
    if (v.data == NULL && n != 0) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }
    v.size = 0;
    v.capacity = n;
    return v;
}

void reserve(vector *v, size_t newCapacity) {
    if (newCapacity == 0) {
        free(v->data);
        v->data = NULL;
    } else if (newCapacity > v->capacity) {
        int *newData = realloc(v->data, newCapacity * sizeof(int));
        if (newData == NULL) {
            fprintf(stderr, "bad alloc");
            exit(1);
        }
        v->data = newData;
        v->capacity = newCapacity;
    }
}

void clear(vector *v) {
    v->size = 0;
}

void shrinkToFit(vector *v) {
    v->data = realloc(v->data, v->size * sizeof(int));
    if (v->data == NULL && v->size != 0) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }
    v->capacity = v->size;
}

void deleteVector(vector *v) {
    free(v->data);
    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
}

bool isEmpty(vector *v) {
    return v->size == 0;
}

bool isFull(vector *v) {
    return v->size == v->capacity;
}

int getVectorValue(vector *v, size_t i) {
    return v->data[i];
}

void pushBack(vector *v, int x) {
    if (isFull(v)) {
        reserve(v, v->capacity * 2);
    }
    v->data[v->size++] = x;
}

void popBack(vector *v) {
    if (isEmpty(v)) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }
    v->size--;
}

int* atVector(vector *v, size_t index) {
    if (index >= v->size) {
        fprintf(stderr, "IndexError: a[index] is not exists");
        exit(1);
    }
    return &(v->data[index]);
}

int* back(vector *v) {
    if (isEmpty(v)) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }
    return &(v->data[v->size - 1]);
}

int* front(vector *v) {
    if (isEmpty(v)) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }
    return &(v->data[0]);
}