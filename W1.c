#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node List_node;
typedef List_node *List;
struct node{
    void *pData;
    int type;
    List_node *pNext;
};

enum
{
    my_int,
    my_double,
    my_char,
    my_string
};

typedef char *string;

List list_create(){
    List head = (List)malloc(sizeof(List));
    if(head == NULL){
        printf("Out Of Space");
    }else{
        head->type = -1;
        head->pData = head->pNext = NULL;        
    }
    return head;
}

int list_length(List L){
    int len = 0;
    if(L && L->pNext){
        List node = L->pNext;   
        while(node){
            len++;
            node = node->pNext;
        }
    }
    return len;
}

void list_print(List L){
    if(L){
        List node = L->pNext;
        while(node){
            switch(node->type){
                case my_int :
                    printf("%d ", *((int *)node->pData));
                    break;
                case my_char :
                    printf("%c ", *((char *)node->pData));
                    break;
                case my_double :
                    printf("%f ", *((double *)node->pData));
                    break;
                case my_string :
                    printf("%s ", (string)node->pData);
                    break;
                default:
                    break;
            }
            node = node->pNext; 
        }
        printf("\n");
    }
}

void list_insert(List L, void* address, int type, int position){
    if(L == NULL){
        L = list_create();
    }
    if(position == 0){//insert at the front
        List new_node = (List)malloc(sizeof(List));
        new_node->pData = address;
        new_node->type = type;
        new_node->pNext = L->pNext;
        L->pNext = new_node;
    }else if(position == -1){ // insert at the rear node
        List rear = L;
        while(rear->pNext){
            rear = rear->pNext;
        }
        List new_node = (List)malloc(sizeof(List));
        new_node->pData = address;
        new_node->type = type;
        new_node->pNext = NULL;
        rear->pNext = new_node;
    }else if(position > 0){
        List insert_pos = L;
        while(insert_pos->pNext && position>0){
            insert_pos = insert_pos->pNext;
            position--;
        }
        List new_node = (List)malloc(sizeof(List));
        new_node->pData = address;
        new_node->type = type;
        new_node->pNext = insert_pos->pNext;
        insert_pos->pNext = new_node;        
    }
}

void list_delete_by_position(List L, int position){
    if(L || L->pNext){
        if(position > -1){
            List delete_node = L;// the previous node of the node to be deleted
            while(delete_node->pNext && position > 0){
                delete_node = delete_node->pNext;
                position--;
            }
            List deleted_node = delete_node->pNext;
            if(deleted_node){
                delete_node->pNext = deleted_node->pNext;
            }else{
                delete_node->pNext = NULL;
            }
            if(deleted_node){
                free(deleted_node);
            }
        }else if(position == -1){
            List delete_node = L;
            while(delete_node->pNext->pNext){
                delete_node = delete_node->pNext;
            }
            List deleted_node = delete_node->pNext;
            delete_node->pNext = NULL;
            if(deleted_node){
                free(deleted_node);
            }
        }
    }
}

void list_delete_by_value(List L, void* addrass, int type){
    if(L==NULL || L->pNext == NULL)
        return;    
    List node = L->pNext, pre_node = L;

    int deleted = 0;

    while(node){
        if(type == node->type){
            switch(node->type){
                case my_int : {
                    if(*(int*)node->pData == *(int*)addrass)
                        deleted = 1;
                    break;
                }                
                case my_char : {
                    if(*(char*)node->pData == *(char*)addrass)
                        deleted = 1;
                    break;
                }
                case my_double : {
                    if(*(double*)node->pData == *(double*)addrass)
                        deleted = 1;
                    break;
                }
                case my_string : {
                    if(strcmp((char*)node->pData, (char*)addrass) == 0)
                        deleted = 1;
                    break;
                }  
                default:
                    break;
            }
        }
        if(deleted){
            pre_node->pNext = node->pNext;
            free(node);
        }
        deleted = 0;
        pre_node = node;
        node = node->pNext;
    }   
}

void list_reverse(List L){
    if(L==NULL || L->pNext == NULL || L->pNext->pNext == NULL)
        return;
    else{
        List a = L->pNext;
        List b = a->pNext;
        List c = b->pNext;
        while(c!=NULL){
            b->pNext = c->pNext;
            c->pNext = a->pNext;
            a->pNext = c;
            c = b->pNext;
//            list_print(L);
        }
        L->pNext = a->pNext;
        b->pNext = a;
        a->pNext = NULL;
    }
}

List list_merge(List a, List b){
    List head = a;
    if(b==NULL || b->pNext ==NULL)
        return a;
    if(a==NULL || a->pNext ==NULL){
        return b;
    }else{
        while(a->pNext){
            a = a->pNext;
        }
        a->pNext = b->pNext;
        free(b);
    }
    return head;
}

void list_discard(List L){
    if(L == NULL){
        return;
    }else if(L->pNext == NULL){
        List a = L, b = L->pNext;
        free(a);
        while(b){
            a = b;
            free(a);
            b = b->pNext;
        }
    }
}

int main(){
    // data
    int a = 1;
    char b = 'a';
    double c = 2.13;
    char d[6] = "apple";
    char e[11] = "I Love OOP";

    List my_list, your_list;
    my_list = list_create();
    your_list = list_create();
    list_insert(my_list, &a, my_int, 0);
    list_print(my_list);
    list_insert(my_list, &b, my_char, 0);
    list_print(my_list);
    printf("len = %d\n",list_length(my_list));
    list_insert(my_list, &c, my_double, -1);
    list_print(my_list);
    list_insert(your_list, d, my_string, 1);
    list_print(your_list);
    list_insert(your_list, e, my_string, 1);
    list_print(your_list);
    list_reverse(my_list);
    list_print(my_list);
    my_list = list_merge(my_list, your_list);
    list_print(my_list);
    list_delete_by_value(my_list, "apple", my_string);
    list_print(my_list);
    list_delete_by_value(my_list, &c, my_double);
    list_print(my_list);
    list_delete_by_position(my_list, 0);
    list_print(my_list);
    list_delete_by_position(my_list, 1);
    list_print(my_list);
    int len = list_length(my_list);
    printf("%d",len);
}
