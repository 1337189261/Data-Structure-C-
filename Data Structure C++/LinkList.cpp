//
//  LinkList.cpp
//  Data Structure C++
//
//  Created by 陈浩宇 on 2019/5/12.
//  Copyright © 2019 陈浩宇. All rights reserved.
//

#include "LinkList.hpp"
#include <cstdlib>

Status GetElem_L(LinkList L, int i, ElemType &e) {
    LinkList p;
    p = L->next;
    int j = 1;
    while (p && j < 1) {
        p = p->next;
    }
    if (!p || j > i) {
        return ERROR;
    }
    e = p->data;
    return OK;
}

Status ListInsert_L(LinkList &L, int i, ElemType e) {
    LinkList p;
    p = L;
    int j = 0;
    while (p && j < i-1) {
        p = p->next;
        ++j;
    }
    if (!p || j > i-1) {
        return ERROR;
    }
    LinkList s = (LinkList)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}

Status ListDelete_L(LinkList &L, int i, ElemType &e) {
    LinkList p, q;
    p = L;
    int j = 0;
    while (p->next && j < i-1) {
        p = p->next;
        ++j;
    }
    if (!(p->next) || j > i-1) {
        return ERROR;
    }
    q = p->next;
    p->next = q->next;
    e = q->data;
    free(q);
    return OK;
}

void CreateList_L(LinkList &L, int n) {
    LinkList p;
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    for (int i = n; i > 0; --i) {
        p = (LinkList)malloc(sizeof(LNode));
        scanf("%d", &p->data);
        p->next = L->next;
        L->next = p;
    }
}

void MergeList_L(LinkList &La, LinkList &Lb, LinkList &Lc) {
    LinkList pa, pb, pc;
    pa = La->next;
    pb = Lb->next;
    Lc = pc = La;
    while (pa && pb) {
        if (pa->data <= pa->data) {
            pc->next = pa;
            pc = pa;
            pa = pa->next;
        } else {
            pc->next = pb;
            pc = pb;
            pb = pb->next;
        }
    }
    pc->next = pa ? pa : pb;
    free(Lb);
}

void Print_L(LinkList L) {
    LinkList p = L;
    if (p) {
        printf("%d\n", p->data);
        p = p->next;
    }
}

LinkList ReverseList_L(LinkList L) {
    if (L == NULL) {
        return NULL;
    }
    LinkList p = L;
    LinkList prev = NULL;
    LinkList curr = p;
    while (curr) {
        LinkList next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
