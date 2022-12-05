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

class book//图书类 
{	
	friend ostream& operator <<(ostream& out, book& b);//重载输出 
	friend istream& operator >>(istream& in, book& b);//重载输入 

private:
	string id;//编号 
	string name;//图书名字 
	string  writer;//作者 
	string home;//出版社 
	double  price=0.0 ;//金额    
	string  type;//类别 
	int  sl=0 ;//库存

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