//
//  BinaryNode.h
//  InterviewJustC
//
//  Created by Timothy Knapik on 2/25/16.
//  Copyright © 2016 Tim. All rights reserved.
//

#ifndef BinaryNode_h
#define BinaryNode_h

#include <stdbool.h>

typedef struct BinaryNode {
    int data;
    struct BinaryNode* left;
    struct BinaryNode* right;
} BinaryNode;

BinaryNode* MakeBinaryNode(int data);
void FreeBinaryNode(BinaryNode* head);
void Insert(BinaryNode** head, int data);
void BinaryNodeDelete(BinaryNode** head, int data);
bool BinaryNodeContains(BinaryNode* head, int data);
int BinaryNodeCount(BinaryNode* head);
void Balance(BinaryNode* head);
int Depth(BinaryNode* head);
void PrintInOrder(BinaryNode* head);
void PrintPreOrder(BinaryNode* head);
void PrintPostOrder(BinaryNode* head);

#endif /* BinaryNode_h */
