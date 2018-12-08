#include <string.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
typedef struct student {
	int data;
	struct student *next;
}Student;

/*
1 创建带有头节点的单向链表，
2 循环创建节点，节点的数据域中的值通过从键盘输入，
3 以-1作为输入结束
4 链表的头结点地址由函数返回。
5 输出链表各节点的数据域的数据。

*/
Student *St_Create();//链表创建
void St_Print(Student *pHead);//链表遍历
int St_NodeInsert(Student *pHead, int x, int y);//x-节点数据为x， y-新插入节点数据为y
int St_DeleteNode(Student *pHead, int x);//删除数据为x的节点
void St_SortNode(Student *pHead); //链表节点排序.
int St_Reverse(Student *pHead); //链表逆置


Student *St_Create()//链表创建
{
	Student *pHead;//头节点指针
	Student *pCur;//指向当前节点指针
	Student *pM;//指向新建节点指针.
	int mdata = 1;

	pHead = (Student *)malloc(sizeof(Student));//创建头节点
	if (pHead == NULL) {
		return NULL;
	}
	pHead->data = 0;
	pHead->next = NULL;
	
	pCur = pHead;
	//新节点创建
	cout << "input data:" << endl; 
	//cin >> mdata;
	//std::cin >> "input data:" >> &mdata >> endl;

	while (mdata != 0) {
		cin >> mdata;
		cout << "mdata1:" << mdata << endl;
		if(mdata == 0)
			break;
		pM = (Student *)malloc(sizeof(Student));//1 、创建新节点
		if (pM == NULL) {
			return NULL;
		}

		pM->data = mdata;
		pM->next = NULL;
		
		pCur->next = pM;//2、新节点入链表.

		pCur = pM;  // 3、当前节点指针往后移，新节点变成当前节点。
		
	}

  return pHead;
}

/*
遍历链表
*/
void St_Print(Student *pHead)//链表遍历
{
    Student *tmp;
    if (pHead == NULL)
        return;
     tmp = pHead->next;

     while (tmp) {
     	std::cout << "data=" << tmp->data << endl;

	tmp=tmp->next;
     }
}

/*
链表节点插入：
1、新节点创建
2、链表遍历，找到合适的插入点。
3、节点插入
*/

int St_NodeInsert(Student *pHead, int x, int y)//x-节点数据为x， y-新插入节点数据为y
{
	Student *pPre=pHead;
	Student *pCur=pHead->next;
	Student *PM;//新节点指针


	
	//2、链表遍历
	while (pCur != NULL) {
		if(pCur->data == x){ //如果找到数据为x的节点，则退出循环。
			break;
		}

		pPre = pCur;
		pCur = pCur->next;
	}
	if(pCur == NULL) {
//		free(PM);
			//PM = NULL;
		return -1;

	}
	//1、新建节点
	PM = (Student *)malloc(sizeof(Student));
	if(PM == NULL)
		return -1;

	PM->next = NULL;
	PM->data = y;
	//3 插入新的节点 (节点前插和后插)
		//pPre = pCur;
		//pCur = pCur->next;
		/*
		pPre->next = PM; //如果使用这种方式，会使链表断开。
		PM->next = pCur;*/

		// 链表是单向的，当前节点的位置保存在 前驱节点的next域中.
		PM->next = pCur;//这种方式链表不会断开.
		pPre->next = PM;

return 0;
}
/*
链表节点删除；
1、遍历链表，找到需要删除的节点
2、删除节点后，重新连接链表。
*/
int St_DeleteNode(Student *pHead, int x)//删除数据为x的节点
{
	Student *pPre = pHead;
	Student *pCur = pHead->next;

	while (pCur->next != NULL) {//链表遍历
		pPre = pCur;
		pCur = pCur->next;
		if(pCur->data == x)
			break;
	}

	//删除节点
	if (pCur == NULL)
		return -1;
	pPre->next = pCur->next; 

	free(pCur);
	
return 0;
}

void St_Destory(Student *pHead)
{
	Student *temp;

	if(pHead == NULL)
		return ;

	while (pHead != NULL) {
		temp = pHead->next;
		free(pHead);
		pHead=temp;
	}
}

/*
链表排序；
1、遍历链表，
2、节点数据的排序。
*/
void St_SortNode(Student *pHead) //链表节点排序.
{
	Student *pPre = pHead;
	Student *pCur = pHead->next;
	Student *pPretemp= NULL, *pCurtemp = NULL;
	int temp;

	while (pCur->next != NULL) {
		pPre = pCur;
		pCur = pCur->next;
		
		/*if(pPre->data < pCur->data){
			temp = pPre->data;
			pPre->data = pCur->data;
			pCur->data = temp;
		}*/

		pPretemp = pPre;
		pCurtemp = pCur;
		//大 -> 小
		while (pCurtemp != NULL) {
		if(pPretemp->data < pCurtemp->data){
			temp = pPretemp->data;
			pPretemp->data = pCurtemp->data;
			pCurtemp->data = temp;

		}
		pPretemp = pCurtemp;
		pCurtemp = pCurtemp->next;
			/*if(pHead->next->data < pCurtemp->data){
				temp = pCurtemp->data;
				pCurtemp->data= pHead->next->data;
				pHead->next->data = pPretemp->data;
				pPretemp->data = temp;
			}
			if((pHead->next->data > pCurtemp->data) && (pHead->next->data < pPretemp->data) ){
				temp = pPretemp->data;
				pPretemp->data = pHead->next->data;
				pHead->next->data = temp;
			}*/
		}

	}

}
/*
void St_bubbleSort(Student *pHead)
{
	if(pHead->next == NULL || pHead->next->next == NULL)
		return;

	Student *p1, *p2, *prep1, *prep2, *temp;

	prep1=pHead->next;//pre
	p1 = prep1->next; //pCur
}*/

/**
	链表逆置:
	1、需要一个一个节点逆置，
	2、从第一个节点开始逆置，不要从最后一个开始逆置
**/
int St_Reverse(Student *pHead)
{
	Student *pPre;
	Student *pCur;
	Student *pNext;

	if(pHead == NULL || pHead->next == NULL)//只有一个节点不需要逆置
		return 0;

	pPre=pHead->next;
	pCur = pHead->next->next;
		//cout << "data 1 = " << pCur->data << endl;
	

	while (pCur->next) {
		pNext = pCur->next;//保存下一个节点
		pCur->next = pPre; //逆置

		pPre = pCur; //后移下一个节点
		pCur = pNext;
		//cout << "data = " << pCur->data << endl;
	
	}
	//cout << "pCur data = " << pCur->data << endl;
	//
	pCur->next = pPre; //逆最后一个节点.

	pHead->next->next = NULL;//原来的第一个节点的next指向NULL
	pHead->next = pCur; //改变头节点的指向.

	return 0;
}


int main(void)
{
	Student *st;

	cout << "Create node"<< endl;
	st = St_Create();
	cout << "INsert Node"<< endl;
	St_NodeInsert(st, 10, 20);
	St_Print(st);
	cout << "delete node"<< endl;
	St_DeleteNode(st, 20);
	St_Print(st);
	cout << "sort node" << endl;
	St_SortNode(st);
	St_Print(st);
	cout << "reverse node" << endl;
	St_Reverse(st);
	St_Print(st);
	cout << "Destory:" << endl;
	St_Destory(st);
	St_Print(st);

	return 0;

}
