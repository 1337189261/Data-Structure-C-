//
//  Queue.cpp
//  Data Structure C++
//
//  Created by 陈浩宇 on 2019/6/15.
//  Copyright © 2019 陈浩宇. All rights reserved.
//

#include "Queue.hpp"

Status InitQueue(LinkQueue &Q) {
    Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
    if (!Q.front) {
        return OVERFLOW;
    }
    return OK;
}

Status DestroyQueue(LinkQueue &Q) {
    while (Q.front) {
        Q.rear = Q.front->next;
        free(Q.front);
        Q.front = Q.rear;
    }
    return OK;
}

Status Enqueue(LinkQueue &Q, QElemType e) {
    auto p = (QueuePtr)malloc(sizeof(QNode));
    if (!p) {
        exit(OVERFLOW);
    }
    p->data = e;
    p->next = NULL;
    Q.rear = p;
    return OK;
}

Status DeQueue(LinkQueue &Q, QElemType &e) {
    if (Q.front == Q.rear) {
        return ERROR;
    }
    auto p = Q.front->next;
    e = p->data;
    Q.front->next = p->next;
    if (Q.rear == p) {
        Q.rear = Q.front;
    }
    free(p);
    return OK;
}
