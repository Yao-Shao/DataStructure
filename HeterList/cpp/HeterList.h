/**
 * @Copyright (C) 2019.
 * @version 1.0
 * @author Yao Shao
 * @date June 2019
 * @file Heterlist.h
 *
 * @brief Implementation of Heterogeneous Linked List
 * This file complement the heterogeneous list and its basic operations. 
 * This program is free software; you can redistribute it and/or modify
 * it.
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
**/ 



#ifndef __Heter__List__H__
#define __Heter__List__H__
#include<string> 
using namespace std;

/* node 基类*/
class Node													
{
public:
	Node();
	virtual ~Node() {}																	
	virtual void print() const = 0;							
	virtual void merge(Node* a) const = 0;				
	Node* next;		/* 下一个结点指针 */										
};

/* int 类*/
class IntNode :public Node									
{
private:
	int data;											
public:
	IntNode(int a);											
	~IntNode() {}											
	virtual void merge(Node* a) const;					
	virtual void print() const;								
};

/* string 类*/
class StringNode :public Node								
{
private:
	string data;											
public:
	StringNode(string a);									
	~StringNode();											
	virtual void merge(Node* a) const;					
	virtual void print() const;								
};

/* double 类*/
class DoubleNode :public Node								
{
private:
	double data;										
public:
	DoubleNode(double a);									
	~DoubleNode() {}									
	virtual void merge(Node* a) const;			
	virtual void print() const;							
};

/* 异质链表类*/
class HeterList
{
private:
	Node *head; /* 头结点*/
	Node *tail; /* 尾结点*/
	int length; /* 长度*/
public:
	HeterList();
	virtual ~HeterList();

	const int getLength() const;									
	void insert(int a, int pos);							 
	void insert(double a, int pos);							 
	void insert(string a, int pos);	
	void deleteByPos(int pos);													
	void reverse();																						
	void merge(const HeterList& a);
	void print() const;	
	void destory();
};

#endif