// Link List.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "conio.h"
using namespace std;

class node
{
//protected:
//	node *next;
//	int data;
public:
	node *next;
	int data;

	node(int x, node *n)
	{
		data = x;
		next = n;
	}
};

class LinkList/*:public node*/
{
//private:
//	node *Head;
public:
	//node *friest() { return Head; }
	
	bool IsImpty(node *Head) { return Head == NULL; }
	
	void InsertInFriest(node *Head,int x)//درج به ابتدا
	{
		node *n = new node(x, NULL);
		n->next = NULL;
		Head = n;
	}

	void InsertInENDifX(node *Head, int x)//به شرطی یک داده را در لیست درج کند که داده در لیست نباشد
	{
		node *m = Head;
		node *n = new node(x, NULL);
		if (m != NULL)
		{
			while (m->next != NULL)
				if (m->data != x)
					m = m->next;
				else
					return;
			m->next = n;
		}
		else
			Head = n;
	}

	void InserInLN(node *Head, node *n, int x)//داده بعداز گره ورودی درج شود
	{
		node *m = new node(x, NULL);
		node *H = Head;
		if (H != NULL)
			while (H->next != NULL)
				if (H != n)
					H = H->next;
				else
				{
					m->next = n->next;
					n->next = m;
				}
		else
			Head = m;
	}

	void InsertInBN(node *Head, node *n, int x)//داده قبل از گره ورودی درج شود
	{
		node *m = new node(x, NULL);
		node *H = Head;
		if (H != NULL)
			while (H->next != NULL)
				if (H->next != n)
					H = H->next;
				else
				{
					m->next = n;
					H->next = m;
				}
		else
			Head = m;
	}

	void InsertInEnd(node *Head, int x)//درج به انتها
	{
		node *m = new node(x, NULL);
		node *n = Head;
		if (n != NULL)
		{
			while (n->next != NULL)
				n = n->next;
			n->next = m;
		}
		else
			Head = m;
	}

	void InsertInBeforeEnd(node *Head, int x)//داده قبل از گره آخر درج شود
	{
		node *n = new node(x, NULL);
		node *m = Head;
		if (m != NULL)
		{
			while (m->next->next != NULL)
				m = m->next;
			n->next = m->next;
			m->next = n;
		}
		else
			Head = n;
	}

	void InsertWithSort(node *Head, int x)
	{
		node *n = NULL;
		node *m = Head;
		while (m != NULL &&m->data < x)
		{
			n = m;
			m = m->next;
		}
		node *nodeX = new node(x, m);
		if (n != NULL)
			n->next = nodeX;
		else
			Head = nodeX;
	}

	void Print(node *Head)//چاپ لیست
	{
		node *n = Head;
		while (n != NULL)
		{
			cout << n->data;
			n = n->next;
		}
	}

	void recPrint(node *Head)//چاپ لیست به صورت بازگشتی
	{
		if (Head == NULL)
			return;
		else
		{
			cout << Head->data;
			recPrint(Head->next);
		}
	}

	void recPrint_1(node *Head)//چاپ لیست به صورت بازگشتی و معکوس
	{
		if (Head == NULL)
			return;
		else
		{
			recPrint_1(Head->next);
			cout << Head->data;
		}
	}

	int CountLX(node *Head, int x)//شمردن تعداد بزرگتراز یک داده در لیست
	{
		int count = 0;
		node *n = Head;
		while (n != NULL)
		{
			if (n->data > x)
				count++;
			n = n->next;
		}
		return count;
	}

	int recCountLX(node *Head, int x)
	{
		if (Head == NULL)
			return 0;
		else
		{
			if (Head->data > x)
				return 1 + recCountLX(Head->next, x);
			else
				return recCountLX(Head->next, x);
		}
	}

	int CountX(node *Head, int x)//تعداد تکرار داده در لیست
	{
		int count = 0;
		node *n = Head;
		while (n != NULL)
		{
			if (n->data == x)
				count++;
			n = n->next;
		}
		return count;
	}

	int recCountX(node *Head, int x)//تعداد تکرار داده در لیست به صورت بازگشتی
	{
		if (Head == NULL)
			return 0;
		else
			if (Head->data == x)
				return 1 + recCountX(Head->next, x);
			else
				return recCountX(Head->next, x);
	}

	void Rev(node *Head)
	{
		node *p = Head;
		node *q = NULL;
		while (p != NULL)
		{
			node *r = q;
			q = p;
			p = p->next;
			q->next = r;
		}
		Head = q;
		/*node *p = Head;
		node *r = NULL;
		node *q = p->next;
		while (p != NULL)
		{
			p->next = r;
			r = p;
			p = q;
			q = p->next;
		}
		Head = p;*/
	}

	node *recRev(node *Head)
	{
		/*if (Head == NULL && q != NULL)
		{
			Head = q;
			return;
		}
		else
		{
			node *r = q;
			q = Head;
			recRev(Head->next, q);
			q->next = r;
		}*/
		if ((Head == NULL && Head->next != NULL) || Head != NULL)
		{
			return Head;
		}
		else
		{
			node *q = Head->next;
			node *m = recRev(Head);
			q->next = Head;
			Head->next = NULL;
			return m;
		}
	}

	node *Copy(node *Head)//یک کپی از لیست
	{
		if (Head == NULL)
			return NULL;
		else
		{
			node *m = new node(Head->data, NULL);
			m->next = Copy(Head->next);
			return m;
		}
	}

	node *DeleteFriest(node *Head)//حدف از ابتدا
	{
		node *n = Head;
		Head = Head->next;
		return n;
	}

	int DeleteFirest(node *Head)//حذف از ابتدای لیست پیوندی
	{
		int temp;
		if (Head != NULL)
		{
			temp = Head->data;
			Head = Head->next;
			return temp;
		}
		else
			return -1;
	}

	int DeleteEnd(node *Head)//حذف از انتهای لیست پیوندی
	{
		if (Head == NULL || Head->next == NULL)
		{
			Head = NULL;
			return Head->data;
		}
		else
		{
			node *n = Head;
			while (n->next->next != NULL)
				n = n->next;
			int temp = n->data;
			node *Temp = n->next;
			n->next = NULL;
			delete Temp;
			return temp;
		}
	}

	void DeleteOfEnd(node *Head)//حذف از انتها
	{
		if (Head == NULL || Head->next == NULL)
			Head = NULL;
		else
		{
			node *n = Head;
			while (n->next->next == NULL)
				n = n->next;
			node *temp = n->next;
			n->next = NULL;
			delete temp;
		}
	}

	void DeleteX(node *Head, int x)
	{
		node *n = Head;
		if (n != NULL)
			while (n->next != NULL)
				if (n->next->data != x)
					n = n->next;
				else
				{
					node *temp = n->next;
					n->next = n->next->next;
					delete temp;
				}
	}

	void DeleteAX(node *Head, int x)
	{
		node *n = Head;
		if (n != NULL)
			while (n->next != NULL)
				if (n->data != x)
					n = n->next;
				else
				{
					node *temp = n->next;
					n->next = n->next->next;
					delete temp;
				}
	}
};

void main()
{
	LinkList LL;
	node *n = new node(1, NULL);
	//LL.InsertWithSort(n, 2);
	//LL.InsertWithSort(n, 3);
	LL.InsertInEnd(n, 5);
	//LL.InsertInLEnd(n, 8);
	LL.Print(n);
	LL.DeleteX(n, 2);
	//node *m = LL.recRev(n);
	LL.Print(n);
	_getch();
}