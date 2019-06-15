//
//  SqList.c
//  Data Structure C++
//
//  Created by 陈浩宇 on 2019/6/10.
//  Copyright © 2019 陈浩宇. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include "SqList.hpp"

Status InitList_Sq(SqList &L) {
    L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if (!L.elem) {
        exit(OVERFLOW);
    }
    L.length = 0;
    L.listsize = LIST_INIT_SIZE;
    return OK;
}

Status ListInsert_Sq(SqList &L, int i,ElemType e) {
    if (i < 1 || i > L.length + 1) {
        return ERROR;
    }
    if (L.length >= L.listsize) {
        auto newBase = (ElemType *)realloc(L.elem, (L.listsize + LIST_INIT_SIZE) * sizeof(ElemType));
        if (!newBase) {
            exit(OVERFLOW);
        }
        L.elem = newBase;
        L.listsize += LISTINCREMENT;
    }
    auto q = &(L.elem[i-1]);
    for (auto p = &(L.elem[L.length - 1]); p >= q; --p) {
        *(p + 1) = *p;
    }
    *q = e;
    ++L.length;
    return OK;
}

Status ListDelete_Sq(SqList &L, int i, ElemType &e) {
    if ((i < 1) || (i > L.length)) {
        return ERROR;
    }
    auto p = &(L.elem[i-1]);
    e = *p;
    auto q = L.elem + L.length - 1;
    for (++p; p <= q; ++p) {
        *(p-1) = *p;
    }
    --L.length;
    return OK;
}

int LocateElem_Sq(SqList L, ElemType e, Status(*compare)(ElemType, ElemType)) {
    int i = 1;
    auto p = L.elem;
    while (i <= L.length && !(*compare)(*p++, e)) {
        ++i;
    }
    if (i <= L.length) {
        return i;
    } else {
        return 0;
    }
    return 0;
}

void MergeList_Sq(SqList La, SqList Lb, SqList &Lc) {
    auto pa = La.elem;
    auto pb = Lb.elem;
    Lc.listsize = Lc.length = La.length + Lb.length;
    auto pc = Lc.elem = (ElemType *)malloc(Lc.listsize * sizeof(ElemType));
    if (!Lc.elem) {
        exit(OVERFLOW);
    }
    auto pa_last = La.elem + La.length - 1;
    auto pb_last = Lb.elem + Lb.length - 1;
    while (pa <= pa_last && pb <= pb_last) {
        if (*pa <= *pb) {
            *pc++ = *pa++;
        } else {
            *pc++ = *pb++;
        }
    }
    while (pa <= pa_last) {
        *pc++ = *pa++;
    }
    while (pb <= pb_last) {
        *pc++ = *pb++;
    }
}
