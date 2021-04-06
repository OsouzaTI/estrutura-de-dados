#ifndef CIRCULAR_LIST_SIM_DUP
#define CIRCULAR_LIST_SIM_DUP

#include "list_sim.h"
int scInsertAtBegin(sList* l, int v){

    if(ISNULL(l)) return (0);
    sNode* newsNode = MALLOC(sNode);
    newsNode->value = v;
    /* primeiro elemento */
    if(ISNULL(l->first)){
        l->first = newsNode;
        newsNode->next = newsNode;
    }else{
        newsNode->next = l->first->next;
        l->first->next = newsNode;
    }
    
    return (1);
}

void scInfoList(sList* l){
    sNode* p = l->first->next;
    while(p != l->first){
        printf("%d\n", p->value);
        p = p->next;
    }
    printf("%d\n", p->value); /* ultimo valor */
}


#endif