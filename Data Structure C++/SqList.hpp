//
//  SqList.h
//  Data Structure C++
//
//  Created by 陈浩宇 on 2019/6/10.
//  Copyright © 2019 陈浩宇. All rights reserved.
//

#ifndef SqList_h
#define SqList_h

#include "CommonHeader.hpp"

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

typedef int ElemType;

typedef struct {
    ElemType *elem;
    int length;
    int listsize;
}SqList;

Status InitList_Sq(SqList &L);

Status ListInsert_Sq(SqList &L, int i,ElemType e);

Status ListDelete_Sq(SqList &L, int i, ElemType &e);

int LocateElem_Sq(SqList L, ElemType e, Status(*compare)(ElemType, ElemType));

void MergeList_Sq(SqList La, SqList Lb, SqList &Lc);

#endif /* SqList_h */
