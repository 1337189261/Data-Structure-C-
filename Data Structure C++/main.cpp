//
//  main.cpp
//  Data Structure C++
//
//  Created by 陈浩宇 on 2019/5/11.
//  Copyright © 2019 陈浩宇. All rights reserved.
//

#include <iostream>
#include "BiTNode.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    
    BiTree tree;
    CreateBiTree(tree);
    InOrderTraversal(tree, PrintElement);
    return 0;
}
