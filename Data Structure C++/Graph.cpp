//
//  Graph.cpp
//  Data Structure C++
//
//  Created by 陈浩宇 on 2019/5/11.
//  Copyright © 2019 陈浩宇. All rights reserved.
//

#include "Graph.hpp"

int visited[MAX_NUMBER];
Status (*VisitFunc)(int v);

int FirstAdjvex(Graph G, int v) {
    for (int i = 0;i < G.vexnum; i ++) {
        if (G.arcs[v][i] == 1)
            return i;
    }
    return -1;
}

int NextAdjvex(Graph G, int v, int w) {
    for (int i = w + 1;i < G.vexnum; i ++) {
        if (G.arcs[v][i] == 1)
            return i;
    }
    return -1;
}

Status Visit(int v) {
    printf("遍历第%d个顶点\n",v + 1);
    return 0;
}

Status LocateAdj(Graph G, char c) {
    for (int i = 0; i < G.vexnum; i ++) {
        if (c == G.vex[i]) {
            return i;
        }
    }
    return -1;
}

void DFS(Graph &G, int &v) {
    int w;
    visited[v] = TRUE;
    VisitFunc(v);
    for (w = FirstAdjvex(G, v); w >= 0; w = NextAdjvex(G,v,w)) {
        if (!visited[w]) DFS(G,w);
    }
}

void DFSTraverse(Graph &G, Status(* Visit)(int v)) {
    printf("开始遍历\n");
    VisitFunc = Visit;
    // 初始化数组
    for (int v = 0; v < G.vexnum; ++v){
        visited[v] = FALSE;
    }
    for (int v = 0; v < G.vexnum; ++v)
        if(! visited[v]) DFS(G, v);
}

Status CreateGraph (Graph &G) {
    for (int i = 0; i < MAX_NUMBER; i++) {
        visited[i] = false;
    }
    printf("请输入顶点数量\n");
    scanf("%d",&G.vexnum);
    printf("请输入弧的数量\n");
    scanf("%d",&G.arcnum);
    for (int i = 0; i < G.vexnum; i ++) {
        printf("输入第%d个顶点\n", i + 1);
        scanf(" %c",&G.vex[i]);
    }
    for (int i = 0; i < G.vexnum; i ++) {
        for (int j = 0; j < G.vexnum; j ++) {
            G.arcs[i][j] = 0;
        }
    }
    for (int k = 0; k < G.arcnum; k ++) {
        char vex1, vex2;
        int  i, j;
        printf("输入第%d个弧的第一个顶点\n",k+1);
        scanf(" %c",&vex1);
        printf("输入第%d个弧的第二个顶点\n",k+1);
        scanf(" %c",&vex2);
        i = LocateAdj(G, vex1);
        j = LocateAdj(G, vex2);
        if ((i >= 0) && (j >= 0)) {
            G.arcs[i][j] = 1;
            G.arcs[j][i] = 1;
        }
    }
    return 0;
}
