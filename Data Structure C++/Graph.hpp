//
//  Graph.hpp
//  Data Structure C++
//
//  Created by 陈浩宇 on 2019/5/11.
//  Copyright © 2019 陈浩宇. All rights reserved.
//

#ifndef Graph_hpp
#define Graph_hpp

#include <stdio.h>
#include "Macro.h"
#define MAX_NUMBER 10

typedef struct
{
    char vex[MAX_NUMBER];
    int arcs[MAX_NUMBER][MAX_NUMBER];
    int arcnum, vexnum;
}Graph;

Status CreateGraph (Graph &G);
void DFSTraverse(Graph &G);

#endif /* Graph_hpp */
