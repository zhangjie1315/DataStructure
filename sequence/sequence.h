/*************************************************************************
	> File Name: sequence.h
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: 2018年03月13日 星期二 05时39分34秒
 ************************************************************************/
#pragma once

#include<stddef.h>
#define SeqListMaxSize 1000

typedef char SeqListType;

typedef struct Seqlist
{
	SeqListType data[SeqListMaxSize];
	size_t size;
}SeqList;

void SeqListInit(SeqList *seqlist);
void SeqListPushBack(SeqList *seqlist,SeqListType value);
void SeqListPushFront(SeqList *seqlist,SeqListType value);
void SeqListPopFront(SeqList *seqlist);
void SeqListInsert(SeqList *seqlist,size_t pos,SeqListType value);
void SeqListErase(SeqList *seqlist,size_t pos);
void SeqListPopBack(SeqList *seqlist);
void SeqListPrintChar(SeqList *seqlist,const char *msg);

void SeqListSet(SeqList *seqlist,size_t pos,SeqListType value);
int SeqListGet(SeqList *seqlist,size_t pos,SeqListType* value);
size_t SeqListFind(SeqList *seqlist,SeqListType to_find);

void SeqListRemoveAll(SeqList *seqlist,SeqListType to_remove);
void SeqListRemove(SeqList *seqlist,SeqListType to_remove);

void SeqListBubbleSort(SeqList *seqlist);
typedef int (*Cmp)(SeqListType a,SeqListType b);
void SeqListBubbleSortEx(SeqList *seqlist,Cmp cmp);
void SeqListSelectSort(SeqList* seqlist);

size_t SeqListSize(SeqList* seq);

int SeqListEmpty(SeqList* seq);
