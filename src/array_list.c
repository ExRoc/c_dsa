// 对应原 bo2-1.c 文件

#include "array_list.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// 内部函数，该函数只能在本文件内被调用，无法被其它文件调用
inline static size_t minSizeT(size_t a, size_t b) {
    return a < b ? a : b;
}

inline static size_t maxSizeT(size_t a, size_t b) {
    return a > b ? a : b;
}

static void fill(ElementType* elements, size_t count, const ElementType element) {
    int i;
    for (i = 0; i < count; ++i) {
        elements[i] = element;
    }
}

static void doubleIncreaseCapacityLeast(ArrayList* arrayList, size_t count) {
    if (arrayList->capacity >= count) {
        return ;
    }

    size_t newCapacity = maxSizeT(arrayList->capacity << 1, 1);
    ElementType* newElements = realloc(arrayList->elements, sizeof(ElementType) * newCapacity);
    assert(newElements != NULL);
    arrayList->elements = newElements;
    arrayList->capacity = newCapacity;
}

static void swapSizeT(size_t* a, size_t* b) {
    size_t c = *a;
    *a = *b;
    *b = c;
}

ArrayList* newArrayList() {
    ArrayList* arrayList = (ArrayList*) malloc(sizeof(ArrayList));
    if (arrayList == NULL) {
        return NULL;
    }

    arrayList->elements = (ElementType*) malloc(0);
    arrayList->length = 0;
    arrayList->capacity = 0;

    return arrayList;
}

ArrayList* newArrayListWithNElements(size_t count, const ElementType element) {
    ArrayList* arrayList = (ArrayList*) malloc(sizeof(ArrayList));
    if (arrayList == NULL) {
        return NULL;
    }

    arrayList->elements = (ElementType*) malloc(sizeof(ElementType) * count);
    if (arrayList->elements == NULL) {
        free(arrayList);
        return NULL;
    }

    arrayList->length = count;
    arrayList->capacity = count;
    fill(arrayList->elements, count, element);

    return arrayList;
}

ArrayList* cloneArrayList(const ArrayList* const other) {
    ArrayList* arrayList = (ArrayList*) malloc(sizeof(ArrayList));
    if (arrayList == NULL) {
        return NULL;
    }

    arrayList->elements = (ElementType*) malloc(sizeof(ElementType) * other->length);
    if (arrayList->elements == NULL) {
        free(arrayList);
        return NULL;
    }

    arrayList->length = other->length;
    arrayList->capacity = other->length;
    memcpy(arrayList->elements, other->elements, sizeof(ElementType) * other->length);

    return arrayList;
}

void destructArrayList(ArrayList* arrayList) {
    free(arrayList->elements);
    free(arrayList);
}

ArrayList* assignArrayList(ArrayList* arrayList, const ArrayList* const other) {
    if (arrayList->capacity >= other->capacity) {
        arrayList->length = other->length;
        memcpy(arrayList->elements, other->elements, sizeof(ElementType) * other->length);
        return arrayList;
    }

    ElementType* newElements = realloc(arrayList->elements, sizeof(ElementType) * other->length);
    if (newElements == NULL) {
        return NULL;
    }

    arrayList->length = other->length;
    arrayList->capacity = other->length;
    arrayList->elements = newElements;
    memcpy(arrayList->elements, other->elements, sizeof(ElementType) * other->length);
    return arrayList;
}

void assignArrayListWithNElements(ArrayList* arrayList, size_t count, const ElementType element) {
    if (arrayList->capacity >= count) {
        arrayList->length = count;
        fill(arrayList->elements, count, element);
        return ;
    }

    ElementType* newElements = realloc(arrayList->elements, sizeof(ElementType) * count);
    if (newElements == NULL) {
        return ;
    }

    arrayList->length = count;
    arrayList->capacity = count;
    arrayList->elements = newElements;
    fill(arrayList->elements, count, element);
    return ;
}

ElementType elementAtArrayList(ArrayList* arrayList, size_t pos) {
    assert(pos < arrayList->length);
    return arrayList->elements[pos];
}

ElementType frontElementAtArrayList(ArrayList* arrayList) {
    assert(arrayList->length > 0);
    return arrayList->elements[0];
}

ElementType backElementAtArrayList(ArrayList* arrayList) {
    assert(arrayList->length > 0);
    return arrayList->elements[arrayList->length - 1];
}

Boolean arrayListIsEmpty(ArrayList* arrayList) {
    return arrayList->length == 0 ? TRUE : FALSE;
}

size_t arrayListSize(ArrayList* arrayList) {
    return arrayList->length;
}

void reserveArrayList(ArrayList* arrayList, size_t newCap) {
    if (arrayList->capacity >= newCap) {
        return ;
    }

    ElementType* newElements = realloc(arrayList->elements, sizeof(ElementType) * newCap);
    assert(newElements != NULL);
    arrayList->elements = newElements;
    arrayList->capacity = newCap;
}

size_t arrayListCapacity(ArrayList* arrayList) {
    return arrayList->capacity;
}

void shrinkArrayListToFit(ArrayList* arrayList) {
    arrayList->elements = realloc(arrayList->elements, sizeof(ElementType) * arrayList->length);
    arrayList->capacity = arrayList->length;
}

void clearArrayList(ArrayList* arrayList) {
    arrayList->length = 0;
}

void insertIntoArrayList(ArrayList* arrayList, size_t pos, const ElementType element) {
    assert(pos < arrayList->length);
    doubleIncreaseCapacityLeast(arrayList, arrayList->length + 1);

    int i;
    for (i = arrayList->length; i > pos; --i) {
        arrayList->elements[i] = arrayList->elements[i - 1];
    }

    arrayList->elements[pos] = element;
    ++arrayList->length;
}

void eraseArrayListAt(ArrayList* arrayList, size_t pos) {
    assert(pos < arrayList->length);
    --arrayList->length;

    int i;
    for (i = pos; i < arrayList->length; ++i) {
        arrayList->elements[i] = arrayList->elements[i + 1];
    }
}

void eraseArrayListRange(ArrayList* arrayList, size_t first, size_t last) {
    assert(first <= last);
    first = minSizeT(first, arrayList->length);
    last = minSizeT(last, arrayList->length);
    if (first == last) {
        return ;
    }

    int i;
    for (i = first; i + last - first < arrayList->length; ++i) {
        arrayList->elements[i] = arrayList->elements[i + last - first];
    }
    arrayList->length -= last - first;
}

void pushBackArrayList(ArrayList* arrayList, const ElementType element) {
    doubleIncreaseCapacityLeast(arrayList, arrayList->length + 1);
    arrayList->elements[arrayList->length] = element;
    ++arrayList->length;
}

void popBackArrayList(ArrayList* arrayList) {
    assert(arrayList->length != 0);
    --arrayList->length;
}

void swapArrayList(ArrayList* arrayList, ArrayList* other) {
    swapSizeT(&(arrayList->capacity), &(other->capacity));
    swapSizeT(&(arrayList->length), &(other->length));

    ElementType *temp = arrayList->elements;
    arrayList->elements = other->elements;
    other->elements = temp;
}
