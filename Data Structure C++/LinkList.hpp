//
//  LinkList.hpp
//  Data Structure C++
//
//  Created by 陈浩宇 on 2019/5/12.
//  Copyright © 2019 陈浩宇. All rights reserved.
//

#ifndef LinkList_hpp
#define LinkList_hpp

#include <stdio.h>
#include "Macro.h"

typedef int ElemType;
typedef struct LNode {
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;

Status GetElem_L(LinkList L, int i, ElemType &e);
Status ListInsert_L(LinkList &L, int i, ElemType e);
Status ListDelete_L(LinkList &L, int i, ElemType &e);
void CreateList_L(LinkList &L, int n);
void MergeList_L(LinkList &La, LinkList &Lb, LinkList &Lc);
void Print_L(LinkList L);
LinkList ReverseList_L(LinkList L);

#endif /* LinkList_hpp */
