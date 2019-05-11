//
//  BiTNode.cpp
//  Data Structure C++
//
//  Created by 陈浩宇 on 2019/5/11.
//  Copyright © 2019 陈浩宇. All rights reserved.
//

#include "BiTNode.hpp"
#include "Stack.hpp"
#include <cstdlib>
#include <iostream>

Status PrintElement(TElemType e) {
    printf("%c\n", e);
    return OK;
}

Status PreOrderTraverse(BiTree T, Status(* Visit)(TElemType e)) {
    if (T) {
        if (Visit(T->data))
            if (PreOrderTraverse(T->lchild, Visit) )
                if (PreOrderTraverse(T, Visit))  return OK;
        return ERROR;
    } else {
        return OK;
    }
}

Status InOrderTraversal(BiTree T, Status(* Visit)(TElemType e)) {
    SqStack S;
    BiTree p = T;
    InitStack(S);
    while (p || !StackEmpty(S)) {
        if (p) {
            Push(S, p);
            p = p->lchild;
        } else {
            Pop(S, p);
            if (!Visit(p->data)) {
                return ERROR;
            }
            p = p->rchild;
        }
    }
    return OK;
}

Status CreateBiTree(BiTree &T) {
    char ch;
    scanf(" %c",&ch);
    if (ch == '#') {
        T = NULL;
    } else {
        if(!(T = (BiTree)malloc(sizeof(TElemType)))) exit(OVERFLOW);
        T -> data = ch;
        CreateBiTree(T -> lchild);
        CreateBiTree(T -> rchild);
    }
    return OK;
}
