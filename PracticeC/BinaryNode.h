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

BinaryNode* BinaryNodeMake(int data);
void BinaryNodeFree(BinaryNode* head);
void BinaryNodeInsert(BinaryNode** head, int data);
void BinaryNodeDelete(BinaryNode** head, int data);
bool BinaryNodeContains(BinaryNode* head, int data);
int BinaryNodeCount(BinaryNode* head);
void BinaryNodeBalance(BinaryNode** headReference);
void BinaryNodePrintInOrder(BinaryNode* head);
void BinaryNodePrintPreOrder(BinaryNode* head);
void BinaryNodePrintPostOrder(BinaryNode* head);

#endif /* BinaryNode_h */
