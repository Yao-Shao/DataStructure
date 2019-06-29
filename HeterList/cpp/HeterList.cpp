/**
 * @Copyright (C) 2019 .
 * @version 1.0
 * @author Yao Shao
 * @date June 2019
 * @file Heterlist.cpp
 *
 * @brief Implementation of Heterogeneous List
 * This file complement the heterogeneous list and its basic operations. 
 * This program is free software; you can redistribute it and/or modify
 * it.
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
**/ 
#include "HeterList.h"
#include<iostream>

/* 构造函数*/
HeterList::HeterList()
{
	head = tail = NULL;												
	length = 0;
}

/* 析构函数*/
HeterList::~HeterList()
{
	destory();
}

/* 打印 */
void HeterList::print() const
{
	Node* tmp = head;
	if (!tmp)
		cout << "Empty HeterList!" << endl;
	else
	{
		while (tmp)
		{
			tmp->print();										
			tmp = tmp->next;
		}
		cout << endl;
	}
}

/* 获得链表长度*/
const int HeterList::getLength() const
{
	return length;													
}

/* 
*	@info 插入函数
*	@para 插入元素的位置，0位头，-1为尾，取值[0,length-1]
*
*/
void HeterList::insert(int a, int pos)										
{
	if (pos < -1 ) { /* 越界判断 */
		cout << "out of index!" << endl;
		exit(-1);
	}
	if (tail == NULL)
		pos = 0;
	Node* tmp = new IntNode(a);
	if (pos == 0) {
		tmp->next = head;
		head = tmp;
		if (!tail)
			tail = tmp;
	}
	else if (pos == -1) {
		tail->next = tmp;
		tmp->next = NULL;
		tail = tmp;
	}
	else if(pos < length){
		int cnt = 1;
		Node* insertPos = head;
		while (cnt != pos) {
			insertPos = insertPos->next;
			cnt++;
		}
		tmp->next = insertPos->next;
		insertPos->next = tmp;
	}
	length++;
}

/* 
*	@info 插入函数
*	@para 插入元素的位置，0位头，-1为尾，取值[0,length-1]
*
*/
void HeterList::insert(double a, int pos)									
{
	if (pos < -1) {
		cout << "out of index!" << endl;
		exit(-1);
	}
	if (tail == NULL)
		pos = 0;
	Node* tmp = new DoubleNode(a);
	if (pos == 0) {
		tmp->next = head;
		head = tmp;
		if (!tail)
			tail = tmp;
	}
	else if (pos == -1) {
		tail->next = tmp;
		tmp->next = NULL;
		tail = tmp;
	}
	else if (pos < length) {
		int cnt = 1;
		Node* insertPos = head;
		while (cnt != pos) {
			insertPos = insertPos->next;
			cnt++;
		}
		tmp->next = insertPos->next;
		insertPos->next = tmp;
	}
	length++;
}

/* 
*	@info 插入函数
*	@para 插入元素的位置，0位头，-1为尾，取值[0,length-1]
*
*/
void HeterList::insert(string a, int pos)									
{
	if (pos < -1) {
		cout << "out of index!" << endl;
		exit(-1);
	}
	if (tail == NULL)
		pos = 0;
	Node* tmp = new StringNode(a);
	if (pos == 0) {
		tmp->next = head;
		head = tmp;
		if (!tail)
			tail = tmp;
	}
	else if (pos == -1) {
		tail->next = tmp;
		tmp->next = NULL;
		tail = tmp;
	}
	else if(pos < length) {
		int cnt = 1;
		Node* insertPos = head;
		while (cnt != pos) {
			insertPos = insertPos->next;
			cnt++;
		}
		tmp->next = insertPos->next;
		insertPos->next = tmp;
	}
	length++;
}

/* 
*	@info 删除函数
*	@para 删除元素的位置，0位头，-1为尾，取值[0,length-1]
*
*/
void HeterList::deleteByPos(int pos)											
{
	if (pos < -1 || pos >= length) {
		cout << "out of index!" << endl;
		exit(-1);
	}
	if (pos == -1)
	{
		pos = length - 1;
	}
	if (pos == 0)
	{
		Node *tmp = head;
		head = head->next;
		delete tmp;
	}
	else{
		int cnt = 0;
		Node* deletePos = head;
		while (cnt != pos-1) {
			deletePos = deletePos->next;
			cnt++;
		}
		
		if (pos == length - 1) {
			delete tail;
			tail = deletePos;
			tail->next = NULL;
		}
		else {
			Node* tmp = deletePos->next;
			deletePos->next = deletePos->next->next;
			delete tmp;
		}	
	}
	length--;
}

/* 
*	@info 逆置函数
*
*/
void HeterList::reverse()												
{
	if (1 >= length)
		return;
	Node * p = head;
	Node * q = head->next;
	while (q)
	{
		p->next = q->next;
		q->next = head;
		head = q;
		q = p->next;
	}
	tail = p;
}

/* 
*	@info 销毁函数
*
*/
void HeterList::destory()												
{
	Node* tmp = head;
	Node* T;
	while (tmp)
	{
		T = tmp;
		tmp = tmp->next;
		delete T;
	}
	head = tail = NULL;
	length = 0;
}

/* 
*	@info 合并函数
*	@para 要合并的异质链表的引用
*
*/
void HeterList::merge(const HeterList & a)									
{
	Node* List1 = tail;
	Node* List2 = a.head;
	while (List2)
	{
		List2->merge(List1);
		List2 = List2->next;
		List1 = List1->next;
	}
}

/* int 结点 构造函数*/
IntNode::IntNode(int a):data(a)									
{
}

/* int 结点合并函数*/
void IntNode::merge(Node * a) const								
{
	a->next = new IntNode(data);
	a->next->next = NULL;
}

/* int 结点打印函数*/
void IntNode::print() const											
	cout << data << " ";
}


/* double 结点 构造函数*/
DoubleNode::DoubleNode(double a):data(a)								
{
}

/* double 结点合并函数*/
void DoubleNode::merge(Node * a) const							
{
	a->next = new DoubleNode(data);
	a->next->next = NULL;
}

/* double 结点打印函数*/
void DoubleNode::print() const										
{
	cout << data << " ";
}

/* string 结点 构造函数*/
StringNode::StringNode(string a):data(a)									
{
}

/* string 结点析构函数*/
StringNode::~StringNode()											
{
}

/* string 结点合并函数*/
void StringNode::merge(Node * a) const							
{
	a->next = new StringNode(data);
	a->next->next = NULL;
}

/* string 结点打印函数*/
void StringNode::print() const										
{
	cout << data << " ";
}

/* inode 结点打印函数*/
Node::Node():next(NULL){}
