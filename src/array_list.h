// 对应原 C2-1.H 文件，文件名通常用小写 + 下划线的方式（array_list.h），不推荐用大写 + 中划线（C2-1.H），需要见名知义

// ifndef + define + endif 是头文件通用用法，用于防止重复引用头文件造成冲突的问题
#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#include "boolean.h"
#include <stdio.h>

// 注意：文件级或者多行注释，建议用 "/** content */ "的方式（注意：里面是多行），单行注释建议用 "// content" 的方式，不建议单行注释用 "/* content */" 的方式
/**
 * array_list.h 基于数组实现的线性表
 */

// 取消 LIST_INIT_SIZE 常量定义，初始大小为 0
// 取消 LISTINCREMENT 常量定义，使用指数增长形式进行扩容（2 倍增长）

// 尽量不用缩写
typedef int ElementType;

// 单行注释用 "// content" 不用  "/* content */"，注释最好对齐
typedef struct {
    ElementType *elements;  // 存储空间基址
    size_t length;          // 列表被使用的长度
    size_t capacity;        // 容量，即 elements 实际指向空间的实际长度
} ArrayList;

// 函数声明应该在头文件中，函数定义应该在同名 .c 文件中（array_list.c），这样在使用时只需要看头文件信息就可以知道用法
ArrayList* newArrayList();
ArrayList* newArrayListWithNElements(size_t count, const ElementType element);
ArrayList* cloneArrayList(const ArrayList* const other);
void destructArrayList(ArrayList* arrayList);
ArrayList* assignArrayList(ArrayList* arrayList, const ArrayList* const other);
void assignArrayListWithNElements(ArrayList* arrayList, size_t count, const ElementType element);
ElementType elementAtArrayList(ArrayList* arrayList, size_t pos);
ElementType frontElementAtArrayList(ArrayList* arrayList);
ElementType backElementAtArrayList(ArrayList* arrayList);
Boolean arrayListIsEmpty(ArrayList* arrayList);
size_t arrayListSize(ArrayList* arrayList);
void reserveArrayList(ArrayList* arrayList, size_t newCap);
size_t arrayListCapacity(ArrayList* arrayList);
void shrinkArrayListToFit(ArrayList* arrayList);
void clearArrayList(ArrayList* arrayList);
void insertIntoArrayList(ArrayList* arrayList, size_t pos, const ElementType element);
void eraseArrayListAt(ArrayList* arrayList, size_t pos);
void eraseArrayListRange(ArrayList* arrayList, size_t first, size_t last);
void pushBackArrayList(ArrayList* arrayList, const ElementType element);
void popBackArrayList(ArrayList* arrayList);
void swapArrayList(ArrayList* arrayList, ArrayList* other);

#endif // ARRAY_LIST_H
