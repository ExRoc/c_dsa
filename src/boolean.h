// 对应原 c1.h 文件，开头的一堆 include 应该放在需要被 include 的地方（即 *.c）文件中，不应该放在这里，Status 类型是不必要的

#ifndef BOOLEAN_H
#define BOOLEAN_H

/**
 * Boolean 枚举值定义头文件
 */

// 推荐用枚举值，在与类型、常量的操作中，能不用 define 尽量不用，能得到更安全的编译保障
typedef enum {
    FALSE = 0,
    TRUE = 1
} Boolean;

#endif // BOOLEAN_H
