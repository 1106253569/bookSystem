#pragma once
#include "book.h"

class System//系统 
{
protected:
	int readBookInformation();//从文件读取图书信息 ok
	
	void menu();//系统菜单 
	void maintenance();//维护菜单

	void addBook();//添加图书 ok
	void deleteBook();//删除图书 ok
	void showBook();//展示图书 ok
	void editBookInformation();//修改图书 ok
	void findBook();//查找图书并显示信息 ok
	
	int checkId(book& p); //图书重复id检测 ok
	int checkType(book& p);//图书类别命名检测 ok
	
	void typeSave();//把图书根据类保存到新的文件 ok
	void saveFile();//把图书信息存入文件 ok

	void sortBooks(); //排序图书 ok
    void typebook();//图书分类展示 ok 

	void printAllBook();//分页打印图书

private:
	vector<book> bookList; //类似于book[]

public:
	System()//构造系统时生成书单并展示菜单 
	{
		readBookInformation();
		menu();
	}
};