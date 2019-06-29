/**
 * @Copyright (C) 2019 .
 * @version 1.0
 * @author Yao Shao
 * @date March 2019
 * @file Heterlist.h
 *
 * @brief Implementation of Heterogeneous List
 * This file complement the heterogeneous list and its basic operations. 
 * This program is free software; you can redistribute it and/or modify
 * it.
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
**/ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "HeterList.h"

/*create a list and set its type to -1*/
pstList CreateList()
{
    pstList pstHead = (pstList)malloc(sizeof(ListNode_S));
    if (NULL == pstHead)
    {
        printf("Out Of Space");
    }
    else
    {
        pstHead->lType = -1;
        pstHead->pData = pstHead->pstNext = NULL;
    }
    return pstHead;
}

/*  input: pointer to st
    output the length ofthe list
*/
int GetLenth(pstList pstL)
{
    int lLen = 0;
    if (NULL != pstL && NULL != pstL->pstNext)
    {
        pstList pstNode = pstL->pstNext;
        while (pstNode)
        {
            lLen++;
            pstNode = pstNode->pstNext;
        }
    }
    return lLen;
}

/*print the list node by node*/
void PrintList(pstList pstL)
{
    if (NULL != pstL)
    {
        pstList pstNode = pstL->pstNext;
        while (pstNode)
        {
            switch (pstNode->lType)
            {
            case INT:
                printf("%d ", *((int *)pstNode->pData));
                break;
            case CHAR:
                printf("%c ", *((char *)pstNode->pData));
                break;
            case DOUBLE:
                printf("%f ", *((double *)pstNode->pData));
                break;
            case STRING:
                printf("%s ", (char *)pstNode->pData);
                break;
            default:
                break;
            }
            pstNode = pstNode->pstNext;
        }
        printf("\n");
    }
}

/* insert a node into the list
    lPosition :
        0 for head node
        * for a randome node
        -1 for tail
*/
void InsertNode(pstList pstL, void *pAddress, int lType, int lPosition)
{
    if (NULL == pstL)
    {
        pstL = CreateList();
    }
    if (0 == lPosition)
    { //insert at the front
        pstList pstNewNode = (pstList)malloc(sizeof(ListNode_S));
        pstNewNode->pData = pAddress;
        pstNewNode->lType = lType;
        pstNewNode->pstNext = pstL->pstNext;
        pstL->pstNext = pstNewNode;
    }
    else if (-1 == lPosition)
    { // insert at the pstRear pstNode
        pstList pstRear = pstL;
        while (pstRear->pstNext)
        {
            pstRear = pstRear->pstNext;
        }
        pstList pstNewNode = (pstList)malloc(sizeof(ListNode_S));
        pstNewNode->pData = pAddress;
        pstNewNode->lType = lType;
        pstNewNode->pstNext = NULL;
        pstRear->pstNext = pstNewNode;
    }
    else if (0 < lPosition)
    {
        pstList pstInsertPos = pstL;
        while (NULL != pstInsertPos->pstNext && 0 < lPosition)
        {
            pstInsertPos = pstInsertPos->pstNext;
            lPosition--;
        }
        pstList pstNewNode = (pstList)malloc(sizeof(ListNode_S));
        pstNewNode->pData = pAddress;
        pstNewNode->lType = lType;
        pstNewNode->pstNext = pstInsertPos->pstNext;
        pstInsertPos->pstNext = pstNewNode;
    }
}

/* delete a node by position
    lposition : -1 0 1;
*/
void DeleteByPosition(pstList pstL, int lPosition)
{
    if (NULL != pstL || NULL != pstL->pstNext)
    {
        if (-1 < lPosition)
        {
            pstList pstDeleteNode = pstL; // the previous pstNode of the node to be deleted
            while (NULL != pstDeleteNode->pstNext && 0 < lPosition)
            {
                pstDeleteNode = pstDeleteNode->pstNext;
                lPosition--;
            }
            pstList pstDeletedNode = pstDeleteNode->pstNext;
            if (NULL != pstDeletedNode)
            {
                pstDeleteNode->pstNext = pstDeletedNode->pstNext;
            }
            else
            {
                pstDeleteNode->pstNext = NULL;
            }
            if (NULL != pstDeletedNode)
            {
                free(pstDeletedNode);
            }
        }
        else if (-1 == lPosition)
        {
            pstList pstDeleteNode = pstL;
            while (NULL != pstDeleteNode->pstNext->pstNext)
            {
                pstDeleteNode = pstDeleteNode->pstNext;
            }
            pstList pstDeletedNode = pstDeleteNode->pstNext;
            pstDeleteNode->pstNext = NULL;
            if (NULL != pstDeletedNode)
            {
                free(pstDeletedNode);
            }
        }
    }
}

/* delete a node by value 
   all the nodes containing that value will be deleted
*/
void DeleteByValue(pstList pstL, void *lAddress, int lType)
{
    if (NULL == pstL || NULL == pstL->pstNext)
        return;
    pstList pstNode = pstL->pstNext, pstPreNode = pstL;

    int lDeleted = 0;

    while (NULL != pstNode)
    {
        if (lType == pstNode->lType)
        {
            switch (pstNode->lType)
            {
            case INT:
            {
                if (*(int *)pstNode->pData == *(int *)lAddress)
                    lDeleted = 1;
                break;
            }
            case CHAR:
            {
                if (*(char *)pstNode->pData == *(char *)lAddress)
                    lDeleted = 1;
                break;
            }
            case DOUBLE:
            {
                if (*(double *)pstNode->pData == *(double *)lAddress)
                    lDeleted = 1;
                break;
            }
            case STRING:
            {
                if (0 == strcmp((char *)pstNode->pData, (char *)lAddress))
                    lDeleted = 1;
                break;
            }
            default:
                break;
            }
        }
        if (1 == lDeleted)
        {
            pstPreNode->pstNext = pstNode->pstNext;
            free(pstNode);
        }
        lDeleted = 0;
        pstPreNode = pstNode;
        pstNode = pstNode->pstNext;
    }
}

/*reverse a list*/
void ReverseList(pstList pstL)
{
    if (NULL == pstL || NULL == pstL->pstNext || NULL == pstL->pstNext->pstNext)
        return;
    else
    {
        pstList pstA = pstL->pstNext;
        pstList pstB = pstA->pstNext;
        pstList pstC = pstB->pstNext;
        while (NULL != pstC)
        {
            pstB->pstNext = pstC->pstNext;
            pstC->pstNext = pstA->pstNext;
            pstA->pstNext = pstC;
            pstC = pstB->pstNext;
            //            PrintList(pstL);
        }
        pstL->pstNext = pstA->pstNext;
        pstB->pstNext = pstA;
        pstA->pstNext = NULL;
    }
}

/*merge two list*/
pstList MergeList(pstList pstA, pstList pstB)
{
    pstList pstHead = pstA;
    if (NULL == pstB || NULL == pstB->pstNext)
        return pstA;
    if (NULL == pstA || NULL == pstA->pstNext)
    {
        return pstB;
    }
    else
    {
        while (NULL != pstA->pstNext)
        {
            pstA = pstA->pstNext;
        }
        pstA->pstNext = pstB->pstNext;
        free(pstB);
    }
    return pstHead;
}

/*discard two list*/
void DiscardList(pstList pstL)
{
    if (NULL == pstL)
    {
        return;
    }
    else if (NULL == pstL->pstNext)
    {
        pstList pstA = pstL, pstB = pstL->pstNext;
        free(pstA);
        while (NULL != pstB)
        {
            pstA = pstB;
            free(pstA);
            pstB = pstB->pstNext;
        }
    }
}
