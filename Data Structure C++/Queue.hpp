//
//  Queue.hpp
//  Data Structure C++
//
//  Created by 陈浩宇 on 2019/6/15.
//  Copyright © 2019 陈浩宇. All rights reserved.
//

#ifndef Queue_hpp
#define Queue_hpp

#include "CommonHeader.hpp"

typedef int QElemType;

typedef struct QNode {
    QElemType data;
    struct QNode *next;
}QNode, *QueuePtr;

typedef struct {
    QueuePtr front;
    QueuePtr rear;
}LinkQueue;

Status InitQueue(LinkQueue &Q);
Status DestroyQueue(LinkQueue &Q);
Status Enqueue(LinkQueue &Q, QElemType e);
Status DeQueue(LinkQueue &Q, QElemType &e);

#endif /* Queue_hpp */
