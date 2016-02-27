//
//  BinaryNodeTests.c
//  InterviewJustC
//
//  Created by Timothy Knapik on 2/27/16.
//  Copyright © 2016 Tim. All rights reserved.
//

#include "BinaryNodeTests.h"
#include "BinaryNode.h"

void TestFunction(char* testName, bool (*f)());
bool CountTest();
bool DeleteTest1();
bool DeleteTest2();
bool DeleteTest3();
bool DeleteTest4();
bool DeleteTest5();
bool DeleteTest6();
bool DeleteTest7();

void RunBinaryNodeTests() {
    TestFunction("Count test", CountTest);
    TestFunction("Delete single node", DeleteTest1);
    TestFunction("Delete inner node with no right child", DeleteTest2);
    TestFunction("Delete inner node with no left child", DeleteTest3);
    TestFunction("Delete root that has left and right children #1", DeleteTest4);
    TestFunction("Delete root that has left and right children #2", DeleteTest5);
    TestFunction("Delete inner node that has left and right children #1", DeleteTest6);
    TestFunction("Delete inner node that has left and right children #2", DeleteTest7);
}

void TestFunction(char* testName, bool (*f)()) {
    if (f()) {
        printf("%s: %s\n", testName, "passed");
    } else {
        printf("%s: %s\n", testName, "failed");
    }
}

bool CountTest() {
    BinaryNode* head = NULL;
    if (BinaryNodeCount(head) != 0) {
        return false;
    }
    return true;
}

bool DeleteTest1() {
    int number = 10;
    BinaryNode* head = MakeBinaryNode(number);
    BinaryNodeDelete(&head, number);
    
    bool success = head == NULL && BinaryNodeCount(head) == 0;
    FreeBinaryNode(head);
    return success;
}

bool DeleteTest2() {
    BinaryNode* head = MakeBinaryNode(5);
    Insert(&head, 6);
    Insert(&head, 4);
    Insert(&head, 2);
    Insert(&head, 1);
    Insert(&head, 3);
    BinaryNodeDelete(&head, 4);
    
    bool success = BinaryNodeCount(head) == 5 && !BinaryNodeContains(head, 4);
    FreeBinaryNode(head);
    return success;
}

bool DeleteTest3() {
    BinaryNode* head = MakeBinaryNode(2);
    Insert(&head, 1);
    Insert(&head, 3);
    Insert(&head, 5);
    Insert(&head, 4);
    Insert(&head, 6);
    BinaryNodeDelete(&head, 3);
    
    bool success = BinaryNodeCount(head) == 5 && !BinaryNodeContains(head, 3);
    FreeBinaryNode(head);
    return success;
}

bool DeleteTest4() {
    BinaryNode* head = MakeBinaryNode(4);
    Insert(&head, 2);
    Insert(&head, 1);
    Insert(&head, 3);
    Insert(&head, 6);
    Insert(&head, 5);
    Insert(&head, 7);
    BinaryNodeDelete(&head, 4);
    
    // the smallest value on the right subtree should be promoted
    // the value being promoted should be 5
    bool success = BinaryNodeCount(head) == 6 && !BinaryNodeContains(head, 4) && head->data == 5;
    FreeBinaryNode(head);
    return success;
}

bool DeleteTest5() {
    BinaryNode* head = MakeBinaryNode(4);
    Insert(&head, 2);
    Insert(&head, 1);
    Insert(&head, 3);
    Insert(&head, 100);
    Insert(&head, 5);
    Insert(&head, 10);
    Insert(&head, 7);
    Insert(&head, 9);
    Insert(&head, 200);
    BinaryNodeDelete(&head, 4);
    
    // the smallest value on the right subtree should be promoted
    // the value being promoted should be 5
    bool success = BinaryNodeCount(head) == 9 && !BinaryNodeContains(head, 4) && head->data == 5;
    FreeBinaryNode(head);
    return success;
}

bool DeleteTest6() {
    BinaryNode* head = MakeBinaryNode(4);
    Insert(&head, 2);
    Insert(&head, 1);
    Insert(&head, 3);
    Insert(&head, 100);
    Insert(&head, 5);
    Insert(&head, 200);
    Insert(&head, 150);
    Insert(&head, 110);
    Insert(&head, 175);
    Insert(&head, 300);
    BinaryNodeDelete(&head, 200);
    
    bool success = BinaryNodeCount(head) == 10 && !BinaryNodeContains(head, 200);
    FreeBinaryNode(head);
    return success;
}

bool DeleteTest7() {
    BinaryNode* head = MakeBinaryNode(4);
    Insert(&head, 2);
    Insert(&head, 1);
    Insert(&head, 3);
    Insert(&head, 100);
    Insert(&head, 5);
    Insert(&head, 200);
    Insert(&head, 300);
    Insert(&head, 290);
    Insert(&head, 280);
    Insert(&head, 270);
    Insert(&head, 275);
    BinaryNodeDelete(&head, 200);
    
    bool success = BinaryNodeCount(head) == 11 && !BinaryNodeContains(head, 200);
    FreeBinaryNode(head);
    return success;
}

