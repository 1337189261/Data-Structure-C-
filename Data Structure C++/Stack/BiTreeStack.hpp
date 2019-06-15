//
//  Stack.hpp
//  Data Structure C++
//
//  Created by 陈浩宇 on 2019/5/11.
//  Copyright © 2019 陈浩宇. All rights reserved.
//

#ifndef Stack_hpp
#define Stack_hpp

#include <stdio.h>
#include "BiTNode.hpp"
#include "Macro.h"

#define STACK_INIT_SIZE  100
#define STACKINCREMENT  10

typedef BiTree SElemType;

typedef struct {
    SElemType *base;
    SElemType *top;
    int stacksize;
}BiTreeStack;

Status InitStack(BiTreeStack &S);
Status GetTop(BiTreeStack S, SElemType &e);
Status Push(BiTreeStack &S, SElemType e);
Status Pop(BiTreeStack &S, SElemType &e);
Status StackEmpty(BiTreeStack S);


#endif /* Stack_hpp */

