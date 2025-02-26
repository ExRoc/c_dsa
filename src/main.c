/* main.c 检验 array_list.c 的主程序 */

#include "array_list.h"
#include <stdlib.h>
#include <time.h>

void printArrayList(ArrayList *arrayList, char *str) {
    if (arrayList == NULL) {
        printf("Null arrayList\n");
        return ;
    }

    int i;
    printf("%s\n", str);
    printf("Size: %d, capacity: %d\n", arrayListSize(arrayList), arrayListCapacity(arrayList));
    printf("elements: [");
    for (i = 0; i < arrayListSize(arrayList); ++i) {
        printf("%d ", elementAtArrayList(arrayList, i));
    }
    printf("]\n\n");
}

int main() {
    srand(time(NULL));

    ArrayList* list1 = newArrayList();
    printArrayList(list1, "ArrayList* list1 = newArrayList();");

    size_t count = rand() % 10 + 1;
    ElementType element = rand() % 20;
    printf("count = %d, element = %d\n", count, element);
    ArrayList* list2 = newArrayListWithNElements(count, element);
    printArrayList(list2, "ArrayList* list2 = newArrayListWithNElements(count, element);");

    ArrayList* list3 = cloneArrayList(list2);
    printArrayList(list3, "ArrayList* list3 = cloneArrayList(list2);");

    assignArrayList(list1, list2);
    printArrayList(list1, "assignArrayList(list1, list2);");

    clearArrayList(list1);
    printArrayList(list1, "clearArrayList(list1);");

    shrinkArrayListToFit(list1);
    printArrayList(list1, "shrinkArrayListToFit(list1);");

    int n = rand() % 10 + 1;
    int i;
    for (i = 0; i < n; ++i) {
        pushBackArrayList(list1, rand() % 20);
    }
    printArrayList(list1, "rand push back list1");

    element = frontElementAtArrayList(list1);
    printf("ElementType element = frontElementAtArrayList(list1);\nelement: %d\n", element);

    element = backElementAtArrayList(list1);
    printf("element = backElementAtArrayList(list1);\nelement: %d\n", element);
    printf("arrayListIsEmpty(list1): %d\n", arrayListIsEmpty(list1));
    printf("arrayListSize(list1): %d\n", arrayListSize(list1));
    printf("arrayListCapacity(list1): %d\n\n", arrayListCapacity(list1));

    n = rand() % 10;
    reserveArrayList(list1, n);
    printf("n = %d\n", n);
    printArrayList(list1, "reserveArrayList(list1, n);");

    size_t pos = rand() % arrayListSize(list1);
    element = rand() % 20;
    printf("pos = %d, element = %d\n", pos, element);
    insertIntoArrayList(list1, pos, element);
    printArrayList(list1, "insertIntoArrayList(list1, pos, element);");

    pos = rand() % arrayListSize(list1);
    printf("pos = %d\n", pos);
    eraseArrayListAt(list1, pos);
    printArrayList(list1, "eraseArrayListAt(list1, pos);");

    size_t first = rand() % arrayListSize(list1);
    size_t last = rand() % (arrayListSize(list1) - first) + first;
    printf("first = %d, last = %d\n", first, last);
    eraseArrayListRange(list1, first, last);
    printArrayList(list1, "eraseArrayListRange(list1, first, last);");

    popBackArrayList(list1);
    printArrayList(list1, "popBackArrayList(list1);");

    swapArrayList(list1, list2);
    printArrayList(list1, "swapArrayList(list1, list2);\nlist1:");
    printArrayList(list2, "list2:");

    destructArrayList(list1);
    destructArrayList(list2);
    destructArrayList(list3);

    return 0;
}
