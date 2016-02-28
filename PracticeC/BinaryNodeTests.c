//
//  BinaryNodeTests.c
//  InterviewJustC
//
//  Created by Timothy Knapik on 2/27/16.
//  Copyright © 2016 Tim. All rights reserved.
//

#include "BinaryNodeTests.h"
#include "BinaryNode.h"

#include <stdlib.h>

void TestFunction(char* testName, bool (*f)());
bool ZeroCountTest();
bool DeleteTest1();
bool DeleteTest2();
bool DeleteTest3();
bool DeleteTest4();
bool DeleteTest5();
bool DeleteTest6();
bool DeleteTest7();
bool InsertDeleteTest1();

void RunBinaryNodeTests() {
    TestFunction("Zero Count test", ZeroCountTest);
    TestFunction("Delete single node", DeleteTest1);
    TestFunction("Delete inner node with no right child", DeleteTest2);
    TestFunction("Delete inner node with no left child", DeleteTest3);
    TestFunction("Delete root that has left and right children #1", DeleteTest4);
    TestFunction("Delete root that has left and right children #2", DeleteTest5);
    TestFunction("Delete inner node that has left and right children #1", DeleteTest6);
    TestFunction("Delete inner node that has left and right children #2", DeleteTest7);
    TestFunction("Mass inserts and deletes", InsertDeleteTest1);
    printf("\n");
}

void TestFunction(char* testName, bool (*f)()) {
    if (f()) {
        printf("%s: %s\n", testName, "passed");
    } else {
        printf("%s: %s\n", testName, "failed");
    }
}

bool ZeroCountTest() {
    BinaryNode* head = NULL;
    if (BinaryNodeCount(head) != 0) {
        return false;
    }
    return true;
}

bool DeleteTest1() {
    int number = 10;
    BinaryNode* head = BinaryNodeMake(number);
    BinaryNodeDelete(&head, number);
    
    bool success = head == NULL && BinaryNodeCount(head) == 0;
    BinaryNodeFree(head);
    return success;
}

bool DeleteTest2() {
    BinaryNode* head = BinaryNodeMake(5);
    BinaryNodeInsert(&head, 6);
    BinaryNodeInsert(&head, 4);
    BinaryNodeInsert(&head, 2);
    BinaryNodeInsert(&head, 1);
    BinaryNodeInsert(&head, 3);
    BinaryNodeDelete(&head, 4);
    
    bool success = BinaryNodeCount(head) == 5 && !BinaryNodeContains(head, 4);
    BinaryNodeFree(head);
    return success;
}

bool DeleteTest3() {
    BinaryNode* head = BinaryNodeMake(2);
    BinaryNodeInsert(&head, 1);
    BinaryNodeInsert(&head, 3);
    BinaryNodeInsert(&head, 5);
    BinaryNodeInsert(&head, 4);
    BinaryNodeInsert(&head, 6);
    BinaryNodeDelete(&head, 3);
    
    bool success = BinaryNodeCount(head) == 5 && !BinaryNodeContains(head, 3);
    BinaryNodeFree(head);
    return success;
}

bool DeleteTest4() {
    BinaryNode* head = BinaryNodeMake(4);
    BinaryNodeInsert(&head, 2);
    BinaryNodeInsert(&head, 1);
    BinaryNodeInsert(&head, 3);
    BinaryNodeInsert(&head, 6);
    BinaryNodeInsert(&head, 5);
    BinaryNodeInsert(&head, 7);
    BinaryNodeDelete(&head, 4);
    
    // the smallest value on the right subtree should be promoted
    // the value being promoted should be 5
    bool success = BinaryNodeCount(head) == 6 && !BinaryNodeContains(head, 4) && BinaryNodeData(head) == 5;
    BinaryNodeFree(head);
    return success;
}

bool DeleteTest5() {
    BinaryNode* head = BinaryNodeMake(4);
    BinaryNodeInsert(&head, 2);
    BinaryNodeInsert(&head, 1);
    BinaryNodeInsert(&head, 3);
    BinaryNodeInsert(&head, 100);
    BinaryNodeInsert(&head, 5);
    BinaryNodeInsert(&head, 10);
    BinaryNodeInsert(&head, 7);
    BinaryNodeInsert(&head, 9);
    BinaryNodeInsert(&head, 200);
    BinaryNodeDelete(&head, 4);
    
    // the smallest value on the right subtree should be promoted
    // the value being promoted should be 5
    bool success = BinaryNodeCount(head) == 9 && !BinaryNodeContains(head, 4) && BinaryNodeData(head) == 5;
    BinaryNodeFree(head);
    return success;
}

bool DeleteTest6() {
    BinaryNode* head = BinaryNodeMake(4);
    BinaryNodeInsert(&head, 2);
    BinaryNodeInsert(&head, 1);
    BinaryNodeInsert(&head, 3);
    BinaryNodeInsert(&head, 100);
    BinaryNodeInsert(&head, 5);
    BinaryNodeInsert(&head, 200);
    BinaryNodeInsert(&head, 150);
    BinaryNodeInsert(&head, 110);
    BinaryNodeInsert(&head, 175);
    BinaryNodeInsert(&head, 300);
    BinaryNodeDelete(&head, 200);
    
    bool success = BinaryNodeCount(head) == 10 && !BinaryNodeContains(head, 200);
    BinaryNodeFree(head);
    return success;
}

bool DeleteTest7() {
    BinaryNode* head = BinaryNodeMake(4);
    BinaryNodeInsert(&head, 2);
    BinaryNodeInsert(&head, 1);
    BinaryNodeInsert(&head, 3);
    BinaryNodeInsert(&head, 100);
    BinaryNodeInsert(&head, 5);
    BinaryNodeInsert(&head, 200);
    BinaryNodeInsert(&head, 300);
    BinaryNodeInsert(&head, 290);
    BinaryNodeInsert(&head, 280);
    BinaryNodeInsert(&head, 270);
    BinaryNodeInsert(&head, 275);
    BinaryNodeDelete(&head, 200);
    
    bool success = BinaryNodeCount(head) == 11 && !BinaryNodeContains(head, 200);
    BinaryNodeFree(head);
    return success;
}

// seed the tree with a bunch of inserts
// insert value, check value is contained
// delete value, check value is not contained
// repeat X times
bool InsertDeleteTest1() {
    int initialInserts = 10000;
    int insertAndDeletes = 10000;
    int maxNumber = 100000;
    bool success = true;
    BinaryNode* head = NULL;
    
    for (int i = 0; i < initialInserts; i++) {
        int randomValue = rand() % maxNumber;
        BinaryNodeInsert(&head, randomValue);
    }
    
    for (int i = 0; i < insertAndDeletes; i++) {
        int randomValue = rand() % maxNumber;
        BinaryNodeInsert(&head, randomValue);
        
        if (!BinaryNodeContains(head, randomValue)) {
            success = false;
            break;
        }
        
        BinaryNodeDelete(&head, randomValue);
        
        if (BinaryNodeContains(head, randomValue)) {
            success = false;
            break;
        }
    }
    BinaryNodeFree(head);
    return success;
}
