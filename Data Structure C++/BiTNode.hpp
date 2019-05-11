//
//  BiTNode.hpp
//  Data Structure C++
//
//  Created by 陈浩宇 on 2019/5/11.
//  Copyright © 2019 陈浩宇. All rights reserved.
//

#ifndef BiTNode_hpp
#define BiTNode_hpp

#include <stdio.h>
#include "Macro.h"
#define MAX_TREE_SIZE 100

typedef char TElemType;

typedef TElemType SqBiTree[MAX_TREE_SIZE];

typedef struct BiTNode {
    TElemType data;
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

Status PrintElement(TElemType e);
Status InOrderTraversal(BiTree T, Status(* Visit)(TElemType e));
Status CreateBiTree(BiTree &T);


#endif /* BiTNode_hpp */
