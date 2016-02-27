//
//  LinkedNode.h
//  InterviewJustC
//
//  Created by Timothy Knapik on 2/24/16.
//  Copyright © 2016 Tim. All rights reserved.
//

#ifndef LinkedNode_h
#define LinkedNode_h

#include <stdbool.h>

typedef struct LinkedNode {
    int data;
    struct LinkedNode* next;
    
} LinkedNode;

LinkedNode* MakeLinkedNode(int data);
void PushFront(LinkedNode** headReference, int data);
void PushEnd(LinkedNode** headReference, int data);
void PopFront(LinkedNode** head);
void PopEnd(LinkedNode** head);
void Delete(LinkedNode** headReference, int data);
bool Contains(LinkedNode* head, int data);
int Length(LinkedNode* head);
void PrintLinkedNode(LinkedNode* head);

#endif /* LinkedNode_h */
