#pragma once
#include "book.h"

class System//ϵͳ 
{
protected:
	int readBookInformation();//���ļ���ȡͼ����Ϣ ok
	
	void menu();//ϵͳ�˵� 
	void maintenance();//ά���˵�

	void addBook();//���ͼ�� ok
	void deleteBook();//ɾ��ͼ�� ok
	void showBook();//չʾͼ�� ok
	void editBookInformation();//�޸�ͼ�� ok
	void findBook();//����ͼ�鲢��ʾ��Ϣ ok
	
	int checkId(book& p); //ͼ���ظ�id��� ok
	int checkType(book& p);//ͼ������������ ok
	
	void typeSave();//��ͼ������ౣ�浽�µ��ļ� ok
	void saveFile();//��ͼ����Ϣ�����ļ� ok

	void sortBooks(); //����ͼ�� ok
    void typebook();//ͼ�����չʾ ok 

	void printAllBook();//��ҳ��ӡͼ��

private:
	vector<book> bookList; //������book[]

public:
	System()//����ϵͳʱ�����鵥��չʾ�˵� 
	{
		readBookInformation();
		menu();
	}
};