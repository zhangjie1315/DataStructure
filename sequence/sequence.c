#include"sequence.h"
void SeqListInit(SeqList *seqlist)
{
	if(seqlist==NULL)
	{
		return;
	}
	seqlist->size=0;
}
void SeqListPushFront(SeqList *seqlist,SeqListType value)
{
	if(seqlist==NULL)
	{//非法输入
		return;
	}
	if(seqlist->size >= SeqListMaxSize)
	{//顺序表已经满了
		return;
	}
	++seqlist->size;
	size_t i = seqlist->size -1;
	for(;i>0;--i)
	{
		seqlist->data[i] = seqlist->data[i -1];
	}
	seqlist->data[0]=value;
	return;
}



void SeqListPopBack(SeqList *seqlist)
{
	if(seqlist==NULL)
	{
		//非法输入
		return;
	}
	if(seqlist->size==0)
	{
		//空顺序表
		return;
	}
	--seqlist->size;
	return;
}
void SeqListPopFront(SeqList *seqlist)
{
	if(seqlist==NULL)
	{//非法输入
		return;
	}
	if(seqlist->size == 0)
	{//空顺序表
		return;
	}
	size_t i = 0;
	for(;i<seqlist->size-1;++i)
	{
		seqlist->data[i] = seqlist->data[i+1];
	}
	--seqlist->size;
	return;
}



void SeqListPushBack(SeqList *seqlist,SeqListType value)
{
	if(seqlist==NULL)
	{
		//非法输入
		return;
	}
	if(seqlist->size==SeqListMaxSize)
	{
		//顺序表已满
		return;
	}
	seqlist->data[seqlist->size]=value;
	++seqlist->size;
	return;
}
void SeqListInsert(SeqList *seqlist,size_t pos,SeqListType value)
{
	if(seqlist==NULL)
	{
		//非法输入
		return;
	}
	//pos->[0,size]
	if(pos > seqlist->size)
	{
		//pos越界
		return;
	}
	if(seqlist->size >=SeqListMaxSize)
	{
		//顺序表已经满了
		return;
	}

	if(pos==0)
	{
		SeqListPushFront(seqlist,value);
		return;
	}

	++seqlist->size;
	size_t i = seqlist->size -1;
	for(;i-1 >=pos;--i)
	{
		seqlist->data[i]=seqlist->data[i-1];
	}
	seqlist->data[pos]=value;
	return;
}


void SeqListErase(SeqList *seqlist,size_t pos)
{
	if(seqlist==NULL)
	{
		//非法输入
		return;
	}
	if(seqlist->size==0)
	{
		//顺序表以为空
		return;
	}

	if(pos >=seqlist->size)
	{
		//pos值已经越界
		return;
	}
	size_t i=pos;
	for(;i<seqlist->size-1;++i)
	{
		seqlist->data[i]=seqlist->data[i+1];
	}
	--seqlist->size;
	return;
}


void SeqListSet(SeqList *seqlist,size_t pos,SeqListType value)
{
	if(seqlist==NULL)
	{
		//非法输入
		return;
	}
	//pos->[0,size]
	if(pos > seqlist->size)
	{
		//pos越界
		return;
	}
	if(seqlist->size >=SeqListMaxSize)
	{
		//顺序表已经满了
		return;
	}

	seqlist->data[pos]=value;
	return;
}



int SeqListGet(SeqList *seqlist,size_t pos,SeqListType *value)
{
	if(seqlist==NULL)
	{
		//非法输入
		return 0;
	}
	if(pos >= seqlist->size)
	{
		//非法输入
		return 0;
	}
	*value =seqlist->data[pos];
	return 1;
}

size_t SeqListFind(SeqList *seqlist,SeqListType to_find)
{
	size_t i=0;
	for(;i <seqlist->size;i++)
	{
		if(seqlist->data[i]==to_find)
		{
			return i;
		}
	}
	return -1;
}

void SeqListRemove(SeqList *seqlist,SeqListType to_remove)
{
	if(seqlist==NULL)
	{
		return;
	}
	size_t pos = SeqListFind(seqlist,to_remove);
	if(pos==(size_t)-1)
	{
		return;
	}
	SeqListErase(seqlist,pos);
	return;
}

void SeqListRemoveAll(SeqList *seqlist,SeqListType to_remove)
{
	if(seqlist==NULL)
	{
		return;
	}
	while(1)
	{
		size_t pos =SeqListFind(seqlist,to_remove);
		if(pos==(size_t)-1)
		{
			break;
		}
		SeqListErase(seqlist,pos);

	}
}

void Swap(SeqListType *a,SeqListType *b)
{
	SeqListType tmp=*a;
	*a=*b;
	*b=tmp;
}
void SeqListBubbleSort(SeqList *seqlist)
{
	if(seqlist==NULL)
	{
		return;
	}
	size_t count=0;
	for(;count < seqlist->size;++count)
	{
		size_t cur=0;
		for(;cur <seqlist->size -1-count;++cur)
		{
			if(seqlist->data[cur]>seqlist->data[cur+1])
			{
				Swap(&seqlist->data[cur],&seqlist->data[cur+1]);
			}
		}
	}
	return;
}
void SeqListBubbleSortEx(SeqList *seqlist,Cmp cmp)
{
	if(seqlist==NULL)
	{
		return;
	}
	size_t count=0;
	for(;count < seqlist->size;++count)
	{
		size_t cur=0;
		for(;cur <seqlist->size -1-count;++cur)
		{
			if(!cmp(seqlist->data[cur],seqlist->data[cur+1]))
			{
				Swap(&seqlist->data[cur],&seqlist->data[cur+1]);
			}
		}
	}
	return;
}

void SeqListSelectSort(SeqList* seqlist)
{
	if(seqlist==NULL)
	{
		return;
	}
	if(seqlist->size <= 1)
	{
		return;
	}
	size_t bound = 0;
	for(;bound < seqlist ->size -1;++bound)
	{
		size_t cur = bound+1;
		for(;cur <seqlist->size;++cur)
		{
			if(seqlist->data[cur]<seqlist->data[bound])
			{
				Swap(&seqlist->data[cur],&seqlist->data[bound]);
			}
		}

	}
	return;
}

size_t SeqListSize(SeqList* seq)
{
	return seq->size;

}
int SeqListEmpty(SeqList* seq)
{
	if(seq == NULL)
	{
		return -1;
	}
	if(seq->size == 0)
	{
		return 1;
	}
	return 0;
}
///////////////////////////////////////////
//以下为测试代码
///////////////////////////////////////////
#include<stdio.h>
#define TEST_HEADER printf("\n============================%s==========================\n",__FUNCTION__);

void SeqListPrintChar(SeqList *seqlist,const char *msg)
{
	if(seqlist==NULL)
	{
		printf("非法输入\n");
		return;
	}
	printf("[%s]\n",msg);
	size_t i=0;
	for(;i<seqlist->size;++i)
	{
		printf("[%c]",seqlist->data[i]);
	}
}
void TestInit()
{
	TEST_HEADER;
	SeqList seqlist;
	SeqListInit(&seqlist);
	printf("seqlist.size expect 0,acturl %lu\n",seqlist.size);
}

void TestPushBack()
{
	TEST_HEADER;
	SeqList seqlist;
	SeqListInit(&seqlist);
	SeqListPushBack(&seqlist,'a');
	SeqListPushBack(&seqlist,'b');
	SeqListPushBack(&seqlist,'c');
	SeqListPushBack(&seqlist,'d');

	SeqListPrintChar(&seqlist,"对空顺序表进行尾插");
}



void TestPopBack()
{
	TEST_HEADER;
	SeqList seqlist;
	SeqListInit(&seqlist);
	SeqListPopBack(&seqlist);
	SeqListPrintChar(&seqlist,"对空顺序表进行尾删");

	SeqListPushBack(&seqlist,'a');
	SeqListPushBack(&seqlist,'b');
	SeqListPushBack(&seqlist,'c');
	SeqListPushBack(&seqlist,'d');
	SeqListPopBack(&seqlist);
	SeqListPopBack(&seqlist);
	SeqListPrintChar(&seqlist,"尾删两个元素");
}

void TestPopFront()
{
	TEST_HEADER;
	SeqList seqlist;
	SeqListInit(&seqlist);
	SeqListPopFront(&seqlist);
	SeqListPrintChar(&seqlist,"对空顺序表进行头删");

	SeqListPushBack(&seqlist,'a');
	SeqListPushBack(&seqlist,'b');
	SeqListPushBack(&seqlist,'c');
	SeqListPushBack(&seqlist,'d');
	SeqListPopFront(&seqlist);
	SeqListPopFront(&seqlist);
	SeqListPrintChar(&seqlist,"头删两个元素");
}



void TestPushFront()
{
	TEST_HEADER;
	SeqList seqlist;
	SeqListInit(&seqlist);
	SeqListPopFront(&seqlist);
	SeqListPrintChar(&seqlist,"对空顺序表进行头插");

	SeqListPushBack(&seqlist,'Z');
	SeqListPushBack(&seqlist,'X');
	SeqListPushBack(&seqlist,'Y');
	SeqListPushBack(&seqlist,'n');
	SeqListPushFront(&seqlist,'a');
	SeqListPushFront(&seqlist,'b');
	SeqListPrintChar(&seqlist,"头插两个元素");
}

void TestInsert()
{
	TEST_HEADER;
	SeqList seqlist;
	SeqListInit(&seqlist);
	SeqListPushBack(&seqlist,'a');
	SeqListPushBack(&seqlist,'b');
	SeqListPushBack(&seqlist,'c');
	SeqListPushBack(&seqlist,'d');

	SeqListInsert(&seqlist,1,'x');
	SeqListPrintChar(&seqlist,"在1位置插入x");

}
void TestErase()
{
	TEST_HEADER;
	SeqList seqlist;
	SeqListInit(&seqlist);
	SeqListPushBack(&seqlist,'a');
	SeqListPushBack(&seqlist,'b');
	SeqListPushBack(&seqlist,'c');
	SeqListPushBack(&seqlist,'d');

	SeqListErase(&seqlist,1);
	SeqListPrintChar(&seqlist,"在1位置删除字符");


}
void TestSet()
{
	TEST_HEADER;
	SeqList seqlist;
	SeqListInit(&seqlist);
	SeqListPushBack(&seqlist,'a');
	SeqListPushBack(&seqlist,'b');
	SeqListPushBack(&seqlist,'c');
	SeqListPushBack(&seqlist,'d');

	SeqListSet(&seqlist,1,'x');
	SeqListType value;
	int ret = SeqListGet(&seqlist,1,&value);

	printf("ret expected 1,actual %d\n",ret);
	printf("value expected x,actual %c\n",value);


}
void TestGet()
{
	TEST_HEADER;
	SeqList seqlist;
	SeqListInit(&seqlist);
	SeqListPushBack(&seqlist,'a');
	SeqListPushBack(&seqlist,'b');
	SeqListPushBack(&seqlist,'c');
	SeqListPushBack(&seqlist,'d');

	SeqListType value;
	int ret = SeqListGet(&seqlist,0,&value);
	printf("value expected a,actual %c\n",value);
	printf("ret expected 1,actual %d\n",ret);

}

void TestFind()
{
	TEST_HEADER;
	SeqList seqlist;
	SeqListInit(&seqlist);
	SeqListPushBack(&seqlist,'a');
	SeqListPushBack(&seqlist,'b');
	SeqListPushBack(&seqlist,'c');
	SeqListPushBack(&seqlist,'d');
	
	size_t pos=SeqListFind(&seqlist,'x');
	printf("pos expected -1,actual %ld\n",pos);

}

int Greater(SeqListType a,SeqListType b)
{
	return a > b? 1:0;
}

void TestBubbleSort()
{

	TEST_HEADER;
	SeqList seqlist;
	SeqListInit(&seqlist);
	SeqListPushBack(&seqlist,'c');
	SeqListPushBack(&seqlist,'b');
	SeqListPushBack(&seqlist,'d');
	SeqListPushBack(&seqlist,'a');
	
	SeqListBubbleSort(&seqlist);
	SeqListPrintChar(&seqlist,"冒泡排序");
}

void TestBubbleSortEx()
{
	TEST_HEADER;
	SeqList seqlist;
	SeqListInit(&seqlist);
	SeqListPushBack(&seqlist,'c');
	SeqListPushBack(&seqlist,'b');
	SeqListPushBack(&seqlist,'d');
	SeqListPushBack(&seqlist,'a');
	
	//如果要进行降序排序
	SeqListBubbleSortEx(&seqlist,Greater);
	SeqListPrintChar(&seqlist,"冒泡排序EX");

}


void TestSelectSort()
{

	TEST_HEADER;
	SeqList seqlist;
	SeqListInit(&seqlist);
	SeqListPushBack(&seqlist,'c');
	SeqListPushBack(&seqlist,'b');
	SeqListPushBack(&seqlist,'d');
	SeqListPushBack(&seqlist,'a');
	
	SeqListSelectSort(&seqlist);
	SeqListPrintChar(&seqlist,"选择排序");
}

void TestRemove()
{
	TEST_HEADER;
	SeqList seqlist;
	SeqListInit(&seqlist);
	SeqListPushBack(&seqlist,'c');
	SeqListPushBack(&seqlist,'a');
	SeqListPushBack(&seqlist,'b');
	SeqListPushBack(&seqlist,'a');
	SeqListPushBack(&seqlist,'d');
	SeqListPushBack(&seqlist,'a');

	SeqListRemove(&seqlist,'a');
	SeqListPrintChar(&seqlist,"删除顺序表中的指定元素，若存在多个，只删除第一个");

}

void TestRemoveAll()
{
	TEST_HEADER;
	SeqList seqlist;
	SeqListInit(&seqlist);
	SeqListPushBack(&seqlist,'c');
	SeqListPushBack(&seqlist,'a');
	SeqListPushBack(&seqlist,'b');
	SeqListPushBack(&seqlist,'a');
	SeqListPushBack(&seqlist,'d');
	SeqListPushBack(&seqlist,'a');

	SeqListRemoveAll(&seqlist,'a');
	SeqListPrintChar(&seqlist,"删除顺序表中的指定元素，若存在多个，全部删除");

}
void TestSize()
{
	TEST_HEADER;
	SeqList seqlist;
	SeqListInit(&seqlist);
	SeqListPushBack(&seqlist,'c');
	SeqListPushBack(&seqlist,'a');
	SeqListPushBack(&seqlist,'b');
	SeqListPushBack(&seqlist,'a');
	SeqListPushBack(&seqlist,'d');
	SeqListPushBack(&seqlist,'d');
	SeqListPushBack(&seqlist,'a');
	SeqListPushBack(&seqlist,'a');

	size_t a = SeqListSize(&seqlist);
	printf("%d个\n",a);

}

void TestEmpty()
{
	TEST_HEADER;
	SeqList seqlist;
	SeqListInit(&seqlist);
	int a = SeqListEmpty(&seqlist);
	printf("%d\n",a);

	SeqListPushBack(&seqlist,'c');
	SeqListPushBack(&seqlist,'a');
	SeqListPushBack(&seqlist,'b');
	SeqListPushBack(&seqlist,'a');
	SeqListPushBack(&seqlist,'d');
	SeqListPushBack(&seqlist,'d');
	SeqListPushBack(&seqlist,'a');
	SeqListPushBack(&seqlist,'a');
	int b = SeqListEmpty(&seqlist);
	printf("%d\n",b);

}
int main()
{
	TestInit();
	TestPushBack();
	TestPopBack();
	TestPushFront();
	TestPopFront();
	TestInsert();
	TestErase();
	TestGet();
	TestSet();
	TestFind();
	TestBubbleSort();
	TestBubbleSortEx();
	TestSelectSort();
	TestRemove();
	TestRemoveAll();
	TestSize();
	TestEmpty();
	return 0;
}
