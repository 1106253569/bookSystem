#pragma once
#include<iostream>  
#include<string>
#include<windows.h> 
#include<fstream>
#include<stdio.h>
#include<iomanip>
#include<vector>
#include<string>
#include <algorithm>  
using namespace std;

class book//ͼ���� 
{	
	friend ostream& operator <<(ostream& out, book& b);//������� 
	friend istream& operator >>(istream& in, book& b);//�������� 

private:
	string id;//��� 
	string name;//ͼ������ 
	string  writer;//���� 
	string home;//������ 
	double  price=0.0 ;//���    
	string  type;//��� 
	int  sl=0 ;//���

public:

	const string getId() { return id; }
	const string getName() { return name; }
	const string getWriter() { return writer; }
	const string getHome() { return home; }
	const double getPrice() { return price; }
	const string getType() { return type; }
	const int getSl() { return sl; }

	void setId() { cin >> id; }
	void setName() { cin >> name; }
	void setWriter() { cin >> writer; }
	void setHome() { cin >> home; }
	void setMoney() { cin >> price; }
	void setType() { cin >> type; }
	void setSl() { cin >> sl; }

	~book() {}
};