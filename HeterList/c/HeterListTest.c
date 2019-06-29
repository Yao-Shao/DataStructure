#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "HeterList.h"

// typedef struct Node_S Listnode_S;
// typedef Listnode_S *pstList;
// struct Node_S
// {
//     void *p_data;
//     int l_type;
//     Listnode_S *pst_next;
// };

// enum Type
// {
//     INT,
//     DOUBLE,
//     CHAR,
//     STRING
// };

// typedef char *string;

// pstList CreateList()
// {
//     pstList pst_head = (pstList)malloc(sizeof(Listnode_S));
//     if (pst_head == NULL)
//     {
//         printf("Out Of Space");
//     }
//     else
//     {
//         pst_head->l_type = -1;
//         pst_head->p_data = pst_head->pst_next = NULL;
//     }
//     return pst_head;
// }

// int GetLenth(pstList pst_L)
// {
//     int l_len = 0;
//     if (pst_L && pst_L->pst_next)
//     {
//         pstList pst_node = pst_L->pst_next;
//         while (pst_node)
//         {
//             l_len++;
//             pst_node = pst_node->pst_next;
//         }
//     }
//     return l_len;
// }

// void PrintList(pstList pst_L)
// {
//     if (pst_L)
//     {
//         pstList pst_node = pst_L->pst_next;
//         while (pst_node)
//         {
//             switch (pst_node->l_type)
//             {
//             case INT:
//                 printf("%d ", *((int *)pst_node->p_data));
//                 break;
//             case CHAR:
//                 printf("%c ", *((char *)pst_node->p_data));
//                 break;
//             case DOUBLE:
//                 printf("%f ", *((double *)pst_node->p_data));
//                 break;
//             case STRING:
//                 printf("%s ", (string)pst_node->p_data);
//                 break;
//             default:
//                 break;
//             }
//             pst_node = pst_node->pst_next;
//         }
//         printf("\n");
//     }
// }

// void InsertNode(pstList pst_L, void *p_address, int l_type, int l_position)
// {
//     if (pst_L == NULL)
//     {
//         pst_L = CreateList();
//     }
//     if (l_position == 0)
//     { //insert at the front
//         pstList pst_newNode = (pstList)malloc(sizeof(Listnode_S));
//         pst_newNode->p_data = p_address;
//         pst_newNode->l_type = l_type;
//         pst_newNode->pst_next = pst_L->pst_next;
//         pst_L->pst_next = pst_newNode;
//     }
//     else if (l_position == -1)
//     { // insert at the pst_rear pst_node
//         pstList pst_rear = pst_L;
//         while (pst_rear->pst_next)
//         {
//             pst_rear = pst_rear->pst_next;
//         }
//         pstList pst_newNode = (pstList)malloc(sizeof(Listnode_S));
//         pst_newNode->p_data = p_address;
//         pst_newNode->l_type = l_type;
//         pst_newNode->pst_next = NULL;
//         pst_rear->pst_next = pst_newNode;
//     }
//     else if (l_position > 0)
//     {
//         pstList pst_insertPos = pst_L;
//         while (pst_insertPos->pst_next && l_position > 0)
//         {
//             pst_insertPos = pst_insertPos->pst_next;
//             l_position--;
//         }
//         pstList pst_newNode = (pstList)malloc(sizeof(Listnode_S));
//         pst_newNode->p_data = p_address;
//         pst_newNode->l_type = l_type;
//         pst_newNode->pst_next = pst_insertPos->pst_next;
//         pst_insertPos->pst_next = pst_newNode;
//     }
// }

// void DeleteByPosition(pstList pst_L, int l_position)
// {
//     if (pst_L || pst_L->pst_next)
//     {
//         if (l_position > -1)
//         {
//             pstList pst_deleteNode = pst_L; // the previous pst_node of the node to be deleted
//             while (pst_deleteNode->pst_next && l_position > 0)
//             {
//                 pst_deleteNode = pst_deleteNode->pst_next;
//                 l_position--;
//             }
//             pstList pst_deletedNode = pst_deleteNode->pst_next;
//             if (pst_deletedNode)
//             {
//                 pst_deleteNode->pst_next = pst_deletedNode->pst_next;
//             }
//             else
//             {
//                 pst_deleteNode->pst_next = NULL;
//             }
//             if (pst_deletedNode)
//             {
//                 free(pst_deletedNode);
//             }
//         }
//         else if (l_position == -1)
//         {
//             pstList pst_deleteNode = pst_L;
//             while (pst_deleteNode->pst_next->pst_next)
//             {
//                 pst_deleteNode = pst_deleteNode->pst_next;
//             }
//             pstList pst_deletedNode = pst_deleteNode->pst_next;
//             pst_deleteNode->pst_next = NULL;
//             if (pst_deletedNode)
//             {
//                 free(pst_deletedNode);
//             }
//         }
//     }
// }

// void DeleteByValue(pstList pst_L, void *l_address, int l_type)
// {
//     if (pst_L == NULL || pst_L->pst_next == NULL)
//         return;
//     pstList pst_node = pst_L->pst_next, pst_preNode = pst_L;

//     int l_deleted = 0;

//     while (pst_node)
//     {
//         if (l_type == pst_node->l_type)
//         {
//             switch (pst_node->l_type)
//             {
//             case INT:
//             {
//                 if (*(int *)pst_node->p_data == *(int *)l_address)
//                     l_deleted = 1;
//                 break;
//             }
//             case CHAR:
//             {
//                 if (*(char *)pst_node->p_data == *(char *)l_address)
//                     l_deleted = 1;
//                 break;
//             }
//             case DOUBLE:
//             {
//                 if (*(double *)pst_node->p_data == *(double *)l_address)
//                     l_deleted = 1;
//                 break;
//             }
//             case STRING:
//             {
//                 if (strcmp((char *)pst_node->p_data, (char *)l_address) == 0)
//                     l_deleted = 1;
//                 break;
//             }
//             default:
//                 break;
//             }
//         }
//         if (l_deleted)
//         {
//             pst_preNode->pst_next = pst_node->pst_next;
//             free(pst_node);
//         }
//         l_deleted = 0;
//         pst_preNode = pst_node;
//         pst_node = pst_node->pst_next;
//     }
// }

// void ReverseList(pstList pst_L)
// {
//     if (pst_L == NULL || pst_L->pst_next == NULL || pst_L->pst_next->pst_next == NULL)
//         return;
//     else
//     {
//         pstList pst_a = pst_L->pst_next;
//         pstList pst_b = pst_a->pst_next;
//         pstList pst_c = pst_b->pst_next;
//         while (pst_c != NULL)
//         {
//             pst_b->pst_next = pst_c->pst_next;
//             pst_c->pst_next = pst_a->pst_next;
//             pst_a->pst_next = pst_c;
//             pst_c = pst_b->pst_next;
//             //            PrintList(pst_L);
//         }
//         pst_L->pst_next = pst_a->pst_next;
//         pst_b->pst_next = pst_a;
//         pst_a->pst_next = NULL;
//     }
// }

// pstList MergeList(pstList pst_a, pstList pst_b)
// {
//     pstList pst_head = pst_a;
//     if (pst_b == NULL || pst_b->pst_next == NULL)
//         return pst_a;
//     if (pst_a == NULL || pst_a->pst_next == NULL)
//     {
//         return pst_b;
//     }
//     else
//     {
//         while (pst_a->pst_next)
//         {
//             pst_a = pst_a->pst_next;
//         }
//         pst_a->pst_next = pst_b->pst_next;
//         free(pst_b);
//     }
//     return pst_head;
// }

// void DiscardList(pstList pst_L)
// {
//     if (pst_L == NULL)
//     {
//         return;
//     }
//     else if (pst_L->pst_next == NULL)
//     {
//         pstList pst_a = pst_L, pst_b = pst_L->pst_next;
//         free(pst_a);
//         while (pst_b)
//         {
//             pst_a = pst_b;
//             free(pst_a);
//             pst_b = pst_b->pst_next;
//         }
//     }
// }

int main()
{
    /* test data */
    int lData = 1;
    char cData = 'a';
    double dData = 2.13;
    char acData1[6] = "List";
    char acData2[11] = "I Love OOP";

    pstList pstList1, pstList2;
    /*test for creating list*/
    pstList1 = CreateList();
    pstList2 = CreateList();

    /*test for insert and printlist*/
    printf("Test for insertion:\n");
    printf("Insert %d (int) to the tail of list1:\n", lData);
    InsertNode(pstList1, &lData, INT, -1);
    PrintList(pstList1);
    printf("Insert %c (char) to the head of list1:\n", cData);    
    InsertNode(pstList1, &cData, CHAR, 0);
    PrintList(pstList1);
    printf("Insert %s (string) to the second node of list1:\n", acData1);
    InsertNode(pstList1, acData1, STRING, 1);
    PrintList(pstList1);
    printf("Insert %f (double) at the head of list2:\n", dData);
    InsertNode(pstList2, &dData, DOUBLE, 0);
    PrintList(pstList2);
    printf("Insert %s (string) to the head of list2:\n", acData2);
    InsertNode(pstList2, acData2, STRING, 0);
    PrintList(pstList2);
    printf("\n");

    /*test for reverse list*/
    printf("Test for reversing a list:\n");
    printf("Before reverse : ");
    PrintList(pstList1);
    ReverseList(pstList1);
    printf("After reverse : ");
    PrintList(pstList1);
    printf("\n");

    /*test for mergelist*/
    printf("Test for merge two lists:\n");
    printf("Before merging:\nList1: ");
    PrintList(pstList1);
    printf("List2: ");
    PrintList(pstList2);
    pstList1 = MergeList(pstList1, pstList2);
    printf("After merge:\nMerged list: ");
    PrintList(pstList1);
    printf("\n");

    /*test delete node*/
    printf("Test for deletion\nOriginal list: ");
    PrintList(pstList1);
    printf("Part1: Delete by value:\nDelete the node with value \"%s\"\n", acData1);
    DeleteByValue(pstList1, acData1, STRING);
    PrintList(pstList1);
    printf("Delete the node with value %f:\n",dData);
    DeleteByValue(pstList1, &dData, DOUBLE);
    PrintList(pstList1);
    printf("Part2: Delete by position:\nDelete head:\n");
    DeleteByPosition(pstList1, 0);
    PrintList(pstList1);
    printf("Delete the tail:\n");
    DeleteByPosition(pstList1, -1);
    PrintList(pstList1);
    printf("\n");

    /* test for getlength*/
    printf("Test for get length of a list\n");
    int lLengthOfList = GetLenth(pstList2);
    printf("The list is :\n");
    PrintList(pstList2);
    printf("The length is %d", lLengthOfList);
    printf("\n");

    /* test for discard list*/
    DiscardList(pstList1);
    DiscardList(pstList2);

    system("pause");
    return 0;
}
