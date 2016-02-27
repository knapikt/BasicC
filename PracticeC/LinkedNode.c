//
//  LinkedNode.c
//  InterviewJustC
//
//  Created by Timothy Knapik on 2/24/16.
//  Copyright © 2016 Tim. All rights reserved.
//

#include "LinkedNode.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

LinkedNode* MakeLinkedNode(int data) {
    LinkedNode* node = malloc(sizeof(*node));
    node->data = data;
    node->next = NULL;
    return node;
}

void FreeLinkedNode(LinkedNode* head) {
    if (head == NULL) {
        return;
    }
    FreeLinkedNode(head->next);
    head->next = NULL;
    free(head);
}

void PushFront(LinkedNode** headReference, int data) {
    LinkedNode* node = MakeLinkedNode(data);
    node->next = *headReference;
    *headReference = node;
}

void PushEnd(LinkedNode** headReference, int data) {
    LinkedNode* node = MakeLinkedNode(data);
    
    if (*headReference == NULL) {
        *headReference = node;
        return;
    }
    
    LinkedNode* current = *headReference;
    while (current->next != NULL) {
        current = current->next;
    }
    
    current->next = node;
}

void PopFront(LinkedNode** headReference) {
    if (*headReference == NULL) {
        return;
    }
    
    LinkedNode* nextNode = (*headReference)->next;
    (*headReference)->next = NULL;
    free(*headReference);
    *headReference = nextNode;
}

void PopEnd(LinkedNode** headReference) {
    if (*headReference == NULL) {
        return;
    }
    
    if ((*headReference)->next == NULL) {
        free(*headReference);
        *headReference = NULL;
        return;
    }
    
    LinkedNode* beforeCurrent = NULL;
    LinkedNode* current = *headReference;
    
    while (current->next != NULL) {
        beforeCurrent = current;
        current = current->next;
    }
    
    beforeCurrent->next = NULL;
    free(current);
}

void Delete(LinkedNode** headReference, int data) {
    if (*headReference == NULL) {
        return;
    }
    
    LinkedNode* previous = NULL;
    LinkedNode* current = *headReference;
    
    while (current != NULL) {
        if (current->data != data) {
            previous = current;
            current = current->next;
            continue;
        }
    
        if (previous == NULL) {
            *headReference = current->next;
            free(current);
            current = *headReference;
        } else {
            previous->next = current->next;
            free(current);
            current = previous->next;
        }
    }
}

bool Contains(LinkedNode* head, int data) {
    if (head == NULL) {
        return false;
    }
    
    while (head != NULL) {
        if (head->data == data) {
            return true;
        }
        head = head->next;
    }
    
    return false;
}

int Length(LinkedNode* head) {
    if (head == NULL) {
        return 0;
    }
    
    int length = 1;
    
    while (head->next != NULL) {
        head = head->next;
        length++;
    }
    
    return length;
}

void PrintLinkedNode(LinkedNode* head) {
    if (head == NULL) {
        printf("Null linked node\n");
        return;
    }
    
    printf("Head: %d\n", head->data);
    while (head->next != NULL) {
        head = head->next;
        printf("Children: %d\n", head->data);
    }
}