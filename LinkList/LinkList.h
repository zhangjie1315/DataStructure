/*************************************************************************
	> File Name: LinkList.h
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: 2018年03月16日 星期五 08时20分18秒
 ************************************************************************/
#pragma once

typedef char LinkNodeType;

typedef struct LinkNode
{
	LinkNodeType data;
	struct LinkNode* next;
}LinkNode;

typedef LinkNode* PLinkNode;
void LinkNodeInit(LinkNode** node);

LinkNode* CreatNode(LinkNodeType value);
void LinkNodeInit(LinkNode** node);


void LinkListPushBack(LinkNode** phead,LinkNodeType value);
void LinkListPopBack(LinkNode** phead);
void LinkListPushFront(LinkNode** phead,LinkNodeType value);
void LinkListPopFront(LinkNode** phead);

LinkNode* LinkListFind(LinkNode* head,LinkNodeType to_find);

void LinkListInsert(LinkNode* pos,LinkNodeType value);
void LinkListInsertBefore(LinkNode** phead,LinkNode* pos,LinkNodeType value);
void LinkListInsertBefore2(LinkNode* pos,LinkNodeType value);

void LinkListErase(LinkNode** phead,LinkNode* pos);
void LinkListErase2(LinkNode** phead,LinkNode* pos);

void LinkListRemove(LinkNode** phead,LinkNodeType to_delete);
void LinkListRemoveAll(LinkNode** phead,LinkNodeType value);

int LinkListEmpty(LinkNode* phead);
int LinkListSize(LinkNode* phead);
void LinkListReversePrint(LinkNode* phead);
LinkNode* JosephCircle(LinkNode* phead,int M);
