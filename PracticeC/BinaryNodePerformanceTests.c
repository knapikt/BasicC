//
//  BinaryNodePerformanceTests.c
//  PracticeC
//
//  Created by Timothy Knapik on 2/27/16.
//  Copyright © 2016 Tim. All rights reserved.
//

#include <stdlib.h>
#include <time.h>
#include "BinaryNodePerformanceTests.h"
#include "BinaryNode.h"

void ContainsTest(int numberNodes);
void TimeContains(BinaryNode* head, int numberNodes, bool preBalance, char* message);
void PrintElapsedTime(clock_t start, clock_t end, char* messsage);

void RunBinaryNodePerformanceTests() {
    ContainsTest(10000);
}

void ContainsTest(int numberNodes) {
    int* numbers = malloc(sizeof(int) * numberNodes);
    
    for (int i = 0; i < numberNodes; i++) {
        numbers[i] = i;
    }
    
    for (int i = 0; i < numberNodes; i++) {
        int swapIndex = rand() % numberNodes;
        int swapValue = numbers[swapIndex];
        numbers[swapIndex] = numbers[i];
        numbers[i] = swapValue;
    }
    
    clock_t start = clock();
   
    BinaryNode* balancedNode = BinaryNodeMake(numbers[0]);
    BinaryNode* randomNode = BinaryNodeMake(numbers[0]);
    BinaryNode* linearNode = BinaryNodeMake(0);
   
    for (int i = 1; i < numberNodes; i++) {
        BinaryNodeInsert(&balancedNode, numbers[i]);
        BinaryNodeInsert(&randomNode, numbers[i]);
        BinaryNodeInsert(&linearNode, i);
    }
    
    clock_t end = clock();
    PrintElapsedTime(start, end, "Allocation");
    
    TimeContains(linearNode, numberNodes, false,  "Contains   (Linear)");
    TimeContains(randomNode, numberNodes, false,  "Contains   (Random)");
    TimeContains(balancedNode, numberNodes, true, "Contains (Balanced)");
    
    BinaryNodeFree(linearNode);
    BinaryNodeFree(randomNode);
    //BinaryNodeFree(balancedNode);
    free(numbers);
}

void TimeContains(BinaryNode* head, int numberNodes, bool preBalance, char* message) {
    clock_t start = clock();
    if (preBalance) {
        BinaryNodeBalance(&head);
    }
    for (int j = 0; j < 10; j++) {
        for (int i = 0; i < numberNodes; i++) {
            BinaryNodeContains(head, i);
        }
    }
    clock_t end = clock();
    PrintElapsedTime(start, end, message);
}

void PrintElapsedTime(clock_t start, clock_t end, char* message) {
    printf("%s: %f seconds\n", message, (double)(end - start) / CLOCKS_PER_SEC);
}
