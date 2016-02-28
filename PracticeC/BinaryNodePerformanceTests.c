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

const int maxLinearNodes = 1000;

void ContainsTest(int numberNodes, int numberRepeatContains);
void TimeContains(BinaryNode* head, int numberNodes, int numberRepeatContains, bool preBalance, char* message);
void PrintElapsedTime(clock_t start, clock_t end, char* messsage);

void RunBinaryNodePerformanceTests() {
    ContainsTest(10, 100000);
    ContainsTest(100, 10000);
    ContainsTest(1000, 10000);
    ContainsTest(10000, 1000);
    ContainsTest(20000, 5000);
    getchar();
}

void ContainsTest(int numberNodes, int numberRepeatContains) {
    printf("Number of nodes: %d, Number of inserts: %d\n", numberNodes, numberNodes * numberRepeatContains);
    
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
    
    if (numberNodes <= maxLinearNodes) {
        TimeContains(linearNode, numberNodes, numberRepeatContains, false,  "Contains   (Linear)");
    }
    
    TimeContains(randomNode, numberNodes, numberRepeatContains, false,  "Contains   (Random)");
    TimeContains(balancedNode, numberNodes, numberRepeatContains, true, "Contains (Balanced)");
    printf("\n");
    
    BinaryNodeFree(linearNode);
    BinaryNodeFree(randomNode);
    BinaryNodeFree(balancedNode);
    free(numbers);
}

void TimeContains(BinaryNode* head, int numberNodes, int numberRepeatContains, bool preBalance, char* message) {
    clock_t start = clock();
    if (preBalance) {
        BinaryNodeBalance(&head);
    }
    
    for (int i = 0; i < numberNodes; i++) {
        for (int j = 0; j < numberRepeatContains; j++) {
            BinaryNodeContains(head, i);
        }
    }
    
    clock_t end = clock();
    PrintElapsedTime(start, end, message);
}

void PrintElapsedTime(clock_t start, clock_t end, char* message) {
    printf("%s: %f seconds\n", message, (double)(end - start) / CLOCKS_PER_SEC);
}
