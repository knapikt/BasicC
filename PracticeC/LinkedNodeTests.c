//
//  LinkedNodeTests.c
//  InterviewJustC
//
//  Created by Timothy Knapik on 2/25/16.
//  Copyright © 2016 Tim. All rights reserved.
//

#include "LinkedNodeTests.h"
#include "LinkedNode.h"

//int (*p[4]) (int x, int y);


bool CheckLength();

void RunLinkedNodeTests() {
    int n = 1;
    bool (*tests[n])();
    tests[0] = CheckLength;
    
    for (int i = 0; i < n; i++) {
        printf("Test: %d\n", (*tests[i])());
    }
}


bool CheckLength() {
    int length = 10;
    LinkedNode* head = MakeLinkedNode(1);
    
    for (int i = 2; i <= 10; i++) {
        PushEnd(&head, i);
    }
    
    return Length(head) == length;
}

