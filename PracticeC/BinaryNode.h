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

// hide implementation details, only access by core functions
typedef struct BinaryNode BinaryNode;

// core functions
BinaryNode* BinaryNodeMake(int data);
void BinaryNodeFree(BinaryNode* head);
void BinaryNodeInsert(BinaryNode** headReference, int data);
void BinaryNodeDelete(BinaryNode** headReference, int data);
bool BinaryNodeContains(BinaryNode* head, int data);
int BinaryNodeData(BinaryNode* head);
int BinaryNodeCount(BinaryNode* head);
void BinaryNodeBalance(BinaryNode** headReference);

// printing utilities
void BinaryNodePrintInOrder(BinaryNode* head);
void BinaryNodePrintPreOrder(BinaryNode* head);
void BinaryNodePrintPostOrder(BinaryNode* head);

#endif /* BinaryNode_h */
