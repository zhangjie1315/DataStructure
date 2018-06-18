#if 1
#include"LinkList.h"
#include<stdlib.h>
#include<stdio.h>
LinkNode* CreatNode(LinkNodeType value)
{
	LinkNode* new_node = (LinkNode*)malloc(sizeof(LinkNode));
	new_node->data = value;
	new_node->next=NULL;
	return new_node;
}

void DestroyNode(LinkNode* node)
{
	free(node);
}
void LinkNodeInit(LinkNode** node)
{
	*node= NULL;
}
void LinkListDestroy(LinkNode** phead)
{
	if(phead == NULL)
	{
		return;
	}
	if(*phead == NULL)
	{
		return;
	}
	LinkNode* cur = *phead;
	while(cur != NULL)
	{
		LinkNode* to_delete = cur;
		cur = cur->next;
		DestroyNode(to_delete);
	}
	*phead = NULL;
	
}



void LinkListPushBack(LinkNode** phead,LinkNodeType value)
{
	if(phead == NULL)
	{
		//非法输入
		return;
	}
	if(*phead == NULL)
	{
		//空链表
		*phead=CreatNode(value);
		return;
	}
	//链表非空
	LinkNode* cur=*phead;
	while(cur->next != NULL)
	{
		cur=cur->next;
	}
	LinkNode* new_node = CreatNode(value);
	cur->next = new_node;
	return;
}

void LinkListPopBack(LinkNode** phead)
{
	if(phead == NULL)
	{
		//非法输入
		return;
	}
	if(*phead == NULL)
	{
		//空链表，无法删除
		return;
	}
	if((*phead)->next == NULL)
	{
		//只有一个元素 
	    DestroyNode(*phead);
		*phead = NULL;
		return;
	}
	LinkNode* pos = *phead;
	LinkNode* cur = NULL;
	while(pos->next != NULL)
	{
		cur = pos;
		pos = pos->next;
	}
	DestroyNode(pos);
	pos = NULL;
	cur->next = NULL;

	return;
}

void LinkListPushFront(LinkNode** phead,LinkNodeType value)
{
	if(phead == NULL)
	{
		//非法输入
		return;
	}
	LinkNode* new_node = CreatNode(value);
	new_node->next = *phead;
	*phead = new_node;
	return;
}
void LinkListPopFront(LinkNode** phead)
{
	if(phead == NULL)
	{
		//非法输入
		return;
	}
	if(*phead ==NULL)
	{
		//空链表，无法删除
		return;
	}
	LinkNode* to_erase = *phead;
	*phead = (*phead)->next;
	DestroyNode(to_erase);
	to_erase == NULL;
	return;
}


LinkNode* LinkListFind(LinkNode* head,LinkNodeType to_find)
{
	if(head == NULL)
	{
		// 空链表
		return NULL;
	} 
	LinkNode* cur = head;
	while(cur != NULL)
	{
		if(cur->data == to_find)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}


void LinkListInsert(LinkNode* pos,LinkNodeType value)
{
	if(pos == NULL)
	{
		return;
	}
	LinkNode* new_node = CreatNode(value);
	new_node->next = pos->next;
	pos->next = new_node;
	return;
}


void LinkListInsertBefore(LinkNode** phead,LinkNode* pos,LinkNodeType value)
{
	if(phead == NULL || pos == NULL)
	{
		return;
	}
	if(*phead == pos)
	{
		LinkListPushFront(phead,value);
		return;
	}
	LinkNode* cur = *phead;
	for(;cur != NULL;cur=cur->next)
	{
		if(cur->next == pos)
		{
			break;
		}
	}
	if(cur == NULL)
	{
		return;
	}
	LinkListInsert(cur,value);
	return;

}
void LinkListInsertBefore2(LinkNode* pos,LinkNodeType value)
{
	if(pos == NULL)
	{
		return;
	}
	LinkListInsert(pos,pos->data);
	pos->data = value;
	return;
}
void LinkListErase(LinkNode** phead,LinkNode* pos)
{
	if(phead == NULL || pos == NULL)
	{
		return;
	}
	if(*phead == NULL)
	{
		return;
	}
	if(*phead == pos)
	{
		LinkListPopFront(phead);
	}
	LinkNode* cur = *phead;
	for(;cur != NULL; cur = cur->next)
	{
		if(cur ->next == pos)
		{
			cur->next = pos->next;
			DestroyNode(pos);
		}
	}
	return;
}
void LinkListErase2(LinkNode** phead,LinkNode* pos)
{
	if(phead == NULL || pos == NULL)
	{
		return;
	}
	if(*phead == NULL)
	{
		return;
	}
	if(pos->next == NULL)
	{
		//如果要删除的元素恰好是最后一个元素那就用为删
		LinkListPopBack(phead);
	}
	pos->data = pos->next->data;
	LinkNode* to_erase = pos->next;
	pos->next = to_erase->next;
	DestroyNode(to_erase);
	return;
}


void LinkListRemove(LinkNode** phead,LinkNodeType to_delete)
{
	if(phead == NULL)
	{
		return;
	}
	if(*phead == NULL)
	{
		return;
	}
	LinkNode* pos = *phead;
	while(pos->next != NULL)
	{
		if((pos == *phead) && (pos->data == to_delete))
		{
			LinkListPopFront(phead);
			return;
		}
		pos = pos->next;
		if(pos->data == to_delete)
		{
			LinkListErase(phead,pos);
			return;
		}
	}

}

void LinkListRemoveAll(LinkNode** phead,LinkNodeType value)
{
	if(phead == NULL)
	{
		return;
	}
	if(*phead == NULL)
	{
		return;
	}
	LinkNode* pos = *phead;
	while(1)
	{
		LinkNode* pos = LinkListFind(*phead,value);
		if(pos == NULL)
		{
			return;
		}
		LinkListErase(phead,pos);
	}
	return;

}

int LinkListEmpty(LinkNode* phead)
{
	if(phead == NULL)
	{
		return 1;
	}
	return 0;
}

int LinkListSize(LinkNode* phead)
{
	int count = 0;
	LinkNode* pos = phead;
	while(pos->next != NULL)
	{
		count++;
		pos = pos->next;
	}
	count++;
	return count;
}
void LinkListReversePrint(LinkNode* phead)
{
	if(phead == NULL)
	{
		return;
	}
	LinkNode* pos = phead;
	LinkListReversePrint(pos->next);
	printf("%c ",pos->data);
	return;
}
LinkNode* JosephCircle(LinkNode* phead,int M)
{
	if(phead == NULL)
	{
		return;
	}
	LinkNode* cur = phead;
	while(cur->next != cur)
	{
		int i = 1;
		for(;i<M;++i)
		{
			cur = cur->next;
		}
		printf("%c\n",cur->data);
		cur->data = cur->next->data;
		LinkNode* to_delete = cur->next;
		cur->next = to_delete->next;
		DestroyNode(to_delete);

	}
	return cur;

}
///////////////////////////////////////////
//以下为测试代码
//////////////////////////////////////////
#include<stdio.h>
#include<stdlib.h>
#define TEST_HEADER printf("\n=============================%s============================\n",__FUNCTION__);
void LinkListPrintChar(LinkNode* head,const char* msg)
{
	printf("[%s]\n",msg);
	LinkNode* cur = head;
	for(;cur != NULL;cur = cur->next)
	{
		printf("[%c|%p]",cur->data,cur);
	}
	printf("\n");
}
void TestInit()
{
	TEST_HEADER;
	LinkNode* head;
	LinkNodeInit(&head);
//	LinkNodeInit(NULL);
}

void TestPushBack()
{
	TEST_HEADER;
	LinkNode* head;
	LinkNodeInit(&head);
	LinkListPushBack(&head,'a');
	LinkListPushBack(&head,'b');
	LinkListPushBack(&head,'c');
	LinkListPushBack(&head,'d');
	LinkListPrintChar(head,"尾插四个元素");

}
void TestPopBack()
{
	TEST_HEADER;
	LinkNode* head;
	LinkNodeInit(&head);
	LinkListPopBack(&head);
	LinkListPrintChar(head,"对空链表进行删除");

	LinkListPushBack(&head,'a');
	LinkListPopBack(&head);
	LinkListPrintChar(head,"对只有一个元素的链表进行删除");

	LinkListPushBack(&head,'a');
	LinkListPushBack(&head,'b');
	LinkListPushBack(&head,'c');
	LinkListPushBack(&head,'d');
	LinkListPopBack(&head);
	LinkListPopBack(&head);
	LinkListPrintChar(head,"尾删两个元素");

}
void TestPushFront()
{
	TEST_HEADER;
	LinkNode* head;
	LinkNodeInit(&head);
	LinkListPushFront(&head,'a');
	LinkListPushFront(&head,'b');
	LinkListPushFront(&head,'c');
	LinkListPushFront(&head,'d');
	LinkListPrintChar(head,"头插四个元素");

}
void TestPopFront()
{
	TEST_HEADER;
	LinkNode* head;
	LinkNodeInit(&head);
	LinkListPushBack(&head,'a');
	LinkListPushBack(&head,'b');
	LinkListPushBack(&head,'c');
	LinkListPushBack(&head,'d');
	LinkListPopFront(&head);
	LinkListPopFront(&head);
	LinkListPrintChar(head," 头删两个元素");

}

void TestFind()
{
	TEST_HEADER;
	LinkNode* head;
	LinkNodeInit(&head);
	LinkListPushBack(&head,'a');
	LinkListPushBack(&head,'b');
	LinkListPushBack(&head,'c');
	LinkListPushBack(&head,'d');

	LinkNode* pos = LinkListFind(head,'a');
	printf("expect : %p  ,actual : %p\n",head,pos);
	LinkNode* pos2 = LinkListFind(head,'x');
	printf("expect :NULL  ,actual : %p\n",pos2);

}

void TestInsert()
{
	TEST_HEADER;
	LinkNode* head;
	LinkNodeInit(&head);
	LinkListPushBack(&head,'a');
	LinkListPushBack(&head,'b');
	LinkListPushBack(&head,'c');
	LinkListPushBack(&head,'d');
	
	LinkNode* pos = head->next;
	LinkListInsert(pos,'x');
	LinkListPrintChar(head," 在 b 后插入 x");
}

void TestInsertBefore()
{
	TEST_HEADER;
	LinkNode* head;
	LinkNodeInit(&head);
	LinkListPushBack(&head,'a');
	LinkListPushBack(&head,'b');
	LinkListPushBack(&head,'c');
	LinkListPushBack(&head,'d');
	
	LinkNode* pos =head;
	LinkListInsertBefore(&head,pos,'x');
	LinkListPrintChar(head," 在 a 前插入 x");
	LinkNode* pos2 =head->next->next;
	LinkListInsertBefore(&head,pos2,'x');
	LinkListPrintChar(head," 在 b 前插入 x");
}

void TestInsertBefore2()
{
	TEST_HEADER;
	LinkNode* head;
	LinkNodeInit(&head);
	LinkListPushBack(&head,'a');
	LinkListPushBack(&head,'b');
	LinkListPushBack(&head,'c');
	LinkListPushBack(&head,'d');
	
	LinkNode* pos =head;
	LinkListInsertBefore(&head,pos,'x');
	LinkListPrintChar(head," 在 a 前插入 x");
	LinkNode* pos2 =head->next->next;
	LinkListInsertBefore(&head,pos2,'x');
	LinkListPrintChar(head," 在 b 前插入 x");
}

void TestErase()
{
	TEST_HEADER;
	LinkNode* head;
	LinkNodeInit(&head);
	LinkListErase(&head,(LinkNode*)0x11);
	LinkListPrintChar(head,"对空链表进行删除");

	LinkListPushBack(&head,'a');
	LinkListPushBack(&head,'b');
	LinkListPushBack(&head,'c');
	LinkListPushBack(&head,'d');

	LinkNode* pos = head->next;
	LinkListErase(&head,pos);
	LinkListPrintChar(head,"删除元素 b ");

	LinkNode* pos2 = (LinkNode*)0x10;
	LinkListErase(&head,pos2);
	LinkListPrintChar(head,"尝试对一个不存在的数进行删除");
	
}
void TestErase2()
{
	TEST_HEADER;
	LinkNode* head;
	LinkNodeInit(&head);
	LinkListErase2(&head,(LinkNode*)0x11);
	LinkListPrintChar(head,"对空链表进行删除");

	LinkListPushBack(&head,'a');
	LinkListPushBack(&head,'b');
	LinkListPushBack(&head,'c');
	LinkListPushBack(&head,'d');

	LinkNode* pos3 = head->next;
	LinkListErase2(&head,pos3);
	LinkListPrintChar(head,"删除元素 b ");

//	LinkNode* pos4 = (LinkNode*)0x10;
//	LinkListErase2(&head,pos4);
//	LinkListPrintChar(head,"尝试对一个不存在的数进行删除");
	
}

void TestRemove()
{
	TEST_HEADER;
	LinkNode* head;
	LinkNodeInit(&head);
	LinkListPushBack(&head,'a');
	LinkListPushBack(&head,'b');
	LinkListPushBack(&head,'c');
	LinkListPushBack(&head,'d');
	LinkListPushBack(&head,'b');

	LinkListRemove(&head,'b');
	LinkListPrintChar(head,"删除链表中第一个值为 b 的元素");

}
void TestRemoveAll()
{
	TEST_HEADER;
	LinkNode* head;
	LinkNodeInit(&head);
	LinkListPushBack(&head,'b');
	LinkListPushBack(&head,'a');
	LinkListPushBack(&head,'b');
	LinkListPushBack(&head,'b');
	LinkListPushBack(&head,'c');
	LinkListPushBack(&head,'d');
	LinkListPushBack(&head,'b');

	LinkListRemoveAll(&head,'b');
	LinkListPrintChar(head,"删除链表中值为 b 的元素");

}

void TestEmpty()
{
	TEST_HEADER;
	LinkNode* head;
	LinkNodeInit(&head);
	int a = LinkListEmpty(head);
	printf("%d\n",a);
	LinkListPushBack(&head,'b');
	LinkListPushBack(&head,'a');
	LinkListPushBack(&head,'b');
	int b = LinkListEmpty(head);
	printf("%d\n",b);

}
void TestSize()
{
	TEST_HEADER;
	LinkNode* head;
	LinkNodeInit(&head);
	LinkListPushBack(&head,'b');
	LinkListPushBack(&head,'a');
	LinkListPushBack(&head,'b');
	LinkListPushBack(&head,'b');
	LinkListPushBack(&head,'c');
	LinkListPushBack(&head,'d');
	LinkListPushBack(&head,'b');

	LinkListPrintChar(head,"链表中的元素");
	int a = LinkListSize(head);
	printf("%d个\n",a);
}
void TestReversePrint()
{
	TEST_HEADER;
	LinkNode* head;
	LinkNodeInit(&head);
	LinkListPushBack(&head,'a');
	LinkListPushBack(&head,'b');
	LinkListPushBack(&head,'c');
	LinkListPushBack(&head,'d');

	LinkListReversePrint(head);
}

void TestJosephCircle()
{
	TEST_HEADER;
	LinkNode* a = CreatNode('a');
	LinkNode* b = CreatNode('b');
	LinkNode* c = CreatNode('c');
	LinkNode* d = CreatNode('d');
	LinkNode* e = CreatNode('e');
	LinkNode* f = CreatNode('f');
	LinkNode* g = CreatNode('g');
	LinkNode* h = CreatNode('h');
	a->next = b;
	b->next = c;
	c->next = d;
	d->next = e;
	e->next = f;
	f->next = g;
	g->next = h;
	h->next = a;
	LinkNode* survive = JosephCircle(a,5);
	printf("survive is %c\n",survive->data);

}
void TestDestroy()
{
	TEST_HEADER;
	LinkNode* head;
	LinkNodeInit(&head);
	LinkListPushBack(&head,'a');
	LinkListPushBack(&head,'b');
	LinkListPushBack(&head,'c');
	LinkListPushBack(&head,'d');
	LinkListDestroy(&head);
	LinkListPrintChar(head,"删除链表中的元素");


}
int main()
{
	TestInit();
	TestPopBack();
	TestPushBack();
	TestPushFront();
	TestPopFront();
	TestFind();
	TestInsert();
	TestInsertBefore();
	TestInsertBefore2();
	TestErase();
	TestErase2();
	TestRemove();
	TestRemoveAll();
	TestEmpty();
	TestSize();
	TestReversePrint();
	TestJosephCircle();
	TestDestroy();
	return 0;
}

#endif
