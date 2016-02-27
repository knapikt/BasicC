//
//  BinaryNode.c
//  InterviewJustC
//
//  Created by Timothy Knapik on 2/25/16.
//  Copyright © 2016 Tim. All rights reserved.
//

#include "BinaryNode.h"
#include <stdio.h>
#include <stdlib.h>

void BinaryNodeCountRecursive(BinaryNode* head, int* count);

BinaryNode* BinaryNodeMake(int data) {
    BinaryNode* node = malloc(sizeof(*node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void BinaryNodeFree(BinaryNode* head) {
    if (head == NULL) {
        return;
    }
    
    BinaryNodeFree(head->left);
    BinaryNodeFree(head->right);
    head->left = NULL;
    head->right = NULL;
    free(head);
}

void BinaryNodeInsert(BinaryNode** head, int data) {
    if (*head == NULL) {
        *head = BinaryNodeMake(data);
        return;
    }
    
    BinaryNode *search = *head;
    
    while (true) {
        if (search->data == data) {
            return;
        }
        
        if (data < search->data) {
            if (search->left == NULL) {
                search->left = BinaryNodeMake(data);
                return;
            }
            search = search->left;
        } else {
            if (search->right == NULL) {
                search->right = BinaryNodeMake(data);
                return;
            }
            search = search->right;
        }
        
    }
}

void BinaryNodeDelete(BinaryNode** head, int data) {
    if (*head == NULL) {
        return;
    }
    
    BinaryNode* previous = NULL;
    BinaryNode* current = *head;
    BinaryNode* deleting = NULL;
    
    while (current != NULL) {
        if (data == current->data) {
            deleting = current;
            break;
        }
        
        previous = current;
        if (data < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    
    if (deleting == NULL) {
        return;
    }
    
    // Only right side of deleting node is a subtree.
    // hook deleting node's right subtree to previous node
    // if previous is null subtree to the head
    if (deleting->left == NULL && deleting->right != NULL) {
        if (previous == NULL) {
            *head = deleting->right;
        } else {
            if (previous->right == deleting) {
                previous->right = deleting->right;
            } else {
                previous->left = deleting->right;
            }
        }
        
        deleting->right = NULL;
        BinaryNodeFree(deleting);
        return;
    }
    
    // only left side of deleting node is a subtree
    // hook deleting node's left subtree to previous node
    // if previous is null subtree to the head
    if (deleting->left != NULL && deleting->right == NULL) {
        if (previous == NULL) {
            *head = deleting->left;
        } else {
            if (previous->right == deleting) {
                previous->right = deleting->left;
            } else {
                previous->left = deleting->left;
            }
        }
        
        deleting->left = NULL;
        BinaryNodeFree(deleting);
        return;
    }
    
    // deleting node has no left or right subtree
    // disconnect deleting node from previous
    // if there is no previous node then head should be nulled
    if (deleting->left == NULL && deleting->right == NULL) {
        if (previous == NULL) {
            *head = NULL;
        } else {
            if (previous->right == deleting) {
                previous->right = NULL;
            } else {
                previous->left = NULL;
            }
        }
        
        BinaryNodeFree(deleting);
        return;
    }
    
    // left and right are not null
    // find the smallest value on the right side
    BinaryNode* leftMostPrevious = deleting;
    BinaryNode* leftMost = deleting->right;
    while (leftMost->left != NULL) {
        leftMostPrevious = leftMost;
        leftMost = leftMost->left;
    }
    
    deleting->data = leftMost->data;
    if (deleting == leftMostPrevious) {
        deleting->right = leftMost->right;
    } else {
        leftMostPrevious->left = leftMost->right;
    }
    
    leftMost->right = NULL;
    BinaryNodeFree(leftMost);
}

bool BinaryNodeContains(BinaryNode* head, int data) {
    if (head == NULL) {
        return false;
    }
    
    while (head != NULL) {
        if (data == head->data) {
            return true;
        }
        
        if (data < head->data) {
            head = head->left;
        } else {
            head = head->right;
        }
    }
    
    return false;
}

int BinaryNodeCount(BinaryNode* head) {
    int count = 0;
    BinaryNodeCountRecursive(head, &count);
    return count;
}

void BinaryNodeCountRecursive(BinaryNode* head, int* count) {
    if (head == NULL) {
        return;
    }
    (*count)++;
    BinaryNodeCountRecursive(head->left, count);
    BinaryNodeCountRecursive(head->right, count);
}

void BinaryNodePrintInOrder(BinaryNode* head) {
    if (head == NULL) {
        return;
    }
    
    BinaryNodePrintInOrder(head->left);
    printf("In Order: %d\n", head->data);
    BinaryNodePrintInOrder(head->right);
}

void BinaryNodePrintPreOrder(BinaryNode* head) {
    if (head == NULL) {
        return;
    }
    
    printf("Pre Order: %d\n", head->data);
    BinaryNodePrintPreOrder(head->left);
    BinaryNodePrintPreOrder(head->right);
}

void BinaryNodePrintPostOrder(BinaryNode* head) {
    if (head == NULL) {
        return;
    }
    
    BinaryNodePrintPostOrder(head->left);
    BinaryNodePrintPostOrder(head->right);
    printf("Post Order: %d\n", head->data);
}


