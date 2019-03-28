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

#ifndef _HETERLIST_H
#define _HETERLIST_H

/*heterList node defination*/
typedef struct Node_S ListNode_S;
typedef ListNode_S *pstList;
struct Node_S
{
    void *pData;
    int lType;
    ListNode_S *pstNext;
};

/*List data type*/
enum Type
{
    INT,
    DOUBLE,
    CHAR,
    STRING
};

/*create a list and initialize it*/
pstList CreateList();
/*return the length of the list*/
int GetLenth(pstList pstL);                                                
/*print the list node by node*/
void PrintList(pstList pstL); 
/* insert a node by position(0 for head and -1 for tail)*/
void InsertNode(pstList pstL, void *pAddress, int lType, int lPosition); 
/*
delete a node by a given position
position: 0 for head, -1 for tail
*/
void DeleteByPosition(pstList pstL, int lPosition);    
/*
delete a node by value, delete all the node contain that value, 
address is the address of that value, 
and l_type is the type of that value  
*/                  
void DeleteByValue(pstList pstL, void *lAddress, int lType);
/*reverse the input list*/              
void ReverseList(pstList pstL);
/* merge the input lists, and return the merged list pointer*/
pstList MergeList(pstList pstA, pstList pstB);
/*disccard a list*/
void DiscardList(pstList pstL);

#endif