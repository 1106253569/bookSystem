#include "System.h"
using namespace std;
void System::menu() //���˵�
{
	cout << "=======================================================" << endl;
	cout << "\t��ӭ����ͼ�������ϵͳ" << endl;
	cout << "\t1.ϵͳά��" << endl;
	cout << "\t2.����ͼ��" << endl;
	cout << "\t3.չʾȫ��ͼ��" << endl;
	cout << "\t4.����չʾͼ��" << endl;
	cout << "\t5.ͼ�������ȡ" << endl;
	cout << "\t6.�˳�ϵͳ" << endl;
	cout << endl;
	cout << "=======================================================" << endl;
	
	cout << "��������Ĳ�������:";
	char n; //������Ϊint���ͣ�������Ż��ֻ�ˢ����ȱ���ǲ��ܽ�����λ���ϵ��ַ�
	cin >> n;
	while (n < '1' || n > '6')
	{
		cout << "�����������������" << endl;
		cout << "��������Ĳ�������:";
		cin >> n;
	}
	switch (n) //����ָ��ѡ���ܺ���
	{
	case '1':
		maintenance();
		break;
	case '2':
		findBook();
		break;

	case '3':
		showBook();
		break;
	case '4':
		typebook();
		break;
	case '6':
		saveFile();
		cout << "�����˳�" << endl;
		Sleep(3000);
		exit(0);
	case '5':
		typeSave();
		break;
	}
}
void System::maintenance() //�Ӳ˵�
{
	system("cls");
	cout << "=======================================================" << endl;
	cout << "\tϵͳά��" << endl;
	cout << "\t1.����ͼ��" << endl;
	cout << "\t2.�޸�ͼ��" << endl;
	cout << "\t3.ɾ��ͼ��" << endl;
	cout << "\t4.����ͼ��" << endl;
	cout << "\t5.������һ��" << endl;

	cout << "=======================================================" << endl;
	cout << "��������Ĳ�������:";
	char n; //������Ϊint���ͣ�������Ż��ֻ�ˢ����ȱ���ǲ��ܽ�����λ���ϵ��ַ�
	cin >> n;
	while (n < '1' || n > '5')
	{
		cout << "�����������������" << endl;
		cout << "��������Ĳ�������:";
		cin >> n;
	}
	switch (n) //����ָ��ѡ���ܺ���
	{
	case '1':
		addBook();
		break;
	case '2':
		editBookInformation();
		break;
	case '3':
		deleteBook();
		break;
	case '4':
		sortBooks();
		break;
	case '5':
		cout << "���ڷ���" << endl;
		Sleep(3000);
		system("cls");
		menu();
		exit(0);
	}
}
int System::readBookInformation() //���ļ���ȡ���ݣ�����ֵֻΪ���жϺ���
{
	cout << "Reading......" << endl;
	ifstream infile("library.txt", ios::in);
	if (!infile)
	{
		cout << "ͼ���ļ�������,�����ļ���......" << endl; //�ļ�������
		Sleep(300);
		system("cls");
		return 0;
	}
	size_t i = 0;
	book temp;
	while (!infile.eof())
	{
		infile >> temp;
		if (checkId(temp)==0 && checkType(temp)==0)
			bookList.push_back(temp);
		i = bookList.size();	
	}
	cout << "add over" << endl;
	infile.close();
	
	if (i == 0)
		cout << "��ǰͼ���б�Ϊ��......" << endl;
	else
		printAllBook();
	Sleep(3000);
	system("cls");
	return 1;
}
void System::addBook() //������ķ�ʽ���ͼ��
{
	char n;
	cout << "������ͼ����Ϣ�����ֻ��Ϊ��ѧ�����������������������" << endl;
	book newBook;
	cout << "���\t\t\t����\t\t\t����\t\t\t������\t\t\t���\t\t\t���\t\t\t�����" << endl;
	cin >> newBook;
	if (checkId(newBook)) //�����ӵ�ͼ�����Ƿ��ͻ
	{
		cout << "����ͼ�����ظ�" << endl;
		cout << "���ڷ���" << endl;
		Sleep(3000);
		system("cls");
		maintenance();
		exit(0);
	}
	if (checkType(newBook)) //�����ӵ�ͼ������Ƿ����
	{
		cout << "����ͼ���������(��ѧ�������������������)" << endl;
		cout << "���ڷ���" << endl;
		Sleep(3000);
		system("cls");
		maintenance();
		exit(0);
	}
	bookList.push_back(newBook);
	cout << "¼��ɹ����Ƿ������ӣ���y��n):";
	cin >> n;
	while (n != 'n' && n != 'y')
	{
		cout << "����������������루y��n)��" << endl;
		cin >> n;
	}
	if (n == 'y')
	{
		addBook();
		exit(0);
	}
	else
	{
		cout << "���ڷ���......" << endl;
		Sleep(3000);
		system("cls");
		maintenance();
		exit(0);
	}
}
void System::showBook() //չʾͼ���б�
{
	const vector<book>& bl = bookList;
	printAllBook();
	system("pause");
	cout << "���ڷ���" << endl;
	Sleep(300);
	system("cls");
	menu();
	exit(0);
}
void System::editBookInformation() //�޸�ͼ����Ϣ
{
	const vector<book>& bl = bookList;
	string bookId;
	book* temp = nullptr;
	book wantBook;
	char n;
	cout << "��������޸ĵ�ͼ����(���롰cancel��ȡ��):";
	cin >> bookId;
	if (bookId == "cancel")
	{
		system("cls");
		maintenance();
		exit(0);
	}				  //���ز˵�
	for (book i : bl)
		if (i.getId() == bookId)
			temp = &i;
	if (temp==nullptr)
	{
		cout << "��ѯ������ͼ��" << endl;
		cout	<< "���ڷ���" << endl;
		Sleep(3000);
		editBookInformation();
		exit(0);
	}
	else
	{
		system("cls");
		wantBook = *temp;
		cout << "Ŀǰ��ͼ����ϢΪ" << endl;
		cout << "���\t\t\t����\t\t\t����\t\t\t������\t\t\t���\t\t\t���\t\t\t�����" << endl;
		cout << *temp << endl;
		cout << "====================================================" << endl;
		cout << "1.���" << endl;
		cout << "2.����" << endl;
		cout << "3.����" << endl;
		cout << "4.������" << endl;
		cout << "5.���" << endl;
		cout << "6.���" << endl;
		cout << "7.�����" << endl;
		cout << "8.������һ��" << endl;
		cout << "��ѡ��Ҫ�޸ĵ�ͼ�����ݣ�";
		cin >> n;

		while (n < '1' || n > '8')
		{
			cout << "�����������������" << endl;
			cout << "��ѡ��Ҫ�޸ĵ�ͼ�����ݣ�";
			cin >> n;
		}
		if (n == '8')
		{
			cout << "���ڷ���" << endl;
			Sleep(3000);
			editBookInformation();
			exit(0);
		}
		cout << "�����޸ĺ�����ݣ����ֻ��Ϊ��ѧ�����������������������" << endl;

		switch (n) // tempΪ��ʱ��������Ϊ��ź������Ҫ�����ж�
		{
		case '1':
			wantBook.setId();
			break;
		case '2':
			wantBook.setName();
			break;
		case '3':
			wantBook.setWriter();
			break;
		case '4':
			wantBook.setHome();
			break;
		case '5':
			wantBook.setMoney();
			break;
		case '6':
			wantBook.setType();
			break;
		case '7':
			wantBook.setSl();
			break;
		}
		if (n == '1') //�ظ�id���
		{
			if (checkId(wantBook))
			{
				cout << "����ͼ�����ظ�,";
				editBookInformation();
				exit(0);
			}
			else
			{
				*temp = wantBook;
			}
		}
		if (n == '6') //�������Ƿ���ȷ
		{
			if (checkType(wantBook))
			{
				cout << "����ͼ�����������ѧ�������������������)" << endl;
				editBookInformation();
				exit(0);
			}
			else
			{
				*temp = wantBook;
			}
		}
		cout << "Ŀǰ��ͼ����ϢΪ" << endl;
		cout << "���\t\t\t����\t\t\t����\t\t\t������\t\t\t���\t\t\t���\t\t\t�����" << endl;
		cout << *temp << endl;
		system("pause");
		cout << "���ڷ���" << endl;
		Sleep(3000);
		system("cls");
		maintenance();
		exit(0);
	}
};

void System::saveFile() //���������ݴ����ļ�
{
	char r='n';
	cout << "�Ƿ񱣴� ? ��y or n��" << endl;
	cin >> r;
	while (r != 'y' && r != 'n')
	{
		cout << "�����������������" << endl;
		cout << "�Ƿ񱣴� ? ��y or n��" << endl;
		cin >> r;
	}
	if (r == 'y')
	{
		cout << "���ڱ���......" << endl;
		vector<book>& bl = bookList;
		fstream outfile("library.txt", ios::out);
		if (!outfile)
		{
			cout << "�ļ�����ʧ��" << endl;
			exit(0);
		}
		else
		{
			for (book& b : bl)
				outfile << b;
			cout << "�ļ�����ɹ�!" << endl;
		}
		outfile.close();
	}
}

void System::findBook() //����ͼ��
{
	char n;
	cout << "��ѡ��������ʽ(1.���\t2.����):" << endl;
	cin >> n;
	while (n != '1' && n != '2')
	{
		cout << "�����������������" << endl;
		cout << "��ѡ��������ʽ(1.���\t2.����):" << endl;
		cin >> n;
	}
	if (n == '1')
	{
		string s;
		book* t=nullptr;
		cout << "����������ҵ�ͼ����(���롰cancel��ȡ��):";
		cin >> s;
		if (s == "cancel")
		{
			system("cls");
			menu();
			exit(0);
		}
		for (book& b : bookList)
			if (b.getId() == s)
				t = &b;

		if (t == nullptr)
		{
			cout << "��ѯ������ͼ��" << endl;
			cout << "���ڷ���" << endl;
			Sleep(300);
			findBook();
			exit(0);
		}
		else
		{
			cout << "Ŀǰ��ͼ����ϢΪ" << endl;
			cout << "���\t\t\t����\t\t\t����\t\t\t������\t\t\t���\t\t\t���\t\t\t�����" << endl;
			cout << *t << endl;
			system("pause");
			system("cls");
			menu();
			exit(0);
		}
	}
	else
	{
		string s;
		book* t=nullptr;
		int i = 0;
		cout << "��������޸ĵ�ͼ������(���롰cancel��ȡ��):";
		cin >> s;
		if (s == "cancel")
		{
			system("cls");
			menu();
			exit(0);
		}
		cout << "���\t\t\t����\t\t\t����\t\t\t������\t\t\t���\t\t\t���\t\t\t�����" << endl;
		for (book& b : bookList)
			if (b.getName() == s)
				t = &b;
		if (t == nullptr)
		{
			cout << "��ѯ������ͼ��" << endl;
			cout << "���ڷ���" << endl;
			Sleep(300);
			findBook();
			exit(0);
		}
		else
		{
			cout << "Ŀǰ��ͼ����ϢΪ" << endl;
			cout << "���\t\t\t����\t\t\t����\t\t\t������\t\t\t���\t\t\t���\t\t\t�����" << endl;
			cout << *t << endl;
			system("pause");
			system("cls");
			menu();
			exit(0);
		}
	}
}
void System::deleteBook() //ɾ��ͼ��
{
	vector<book>& bl = bookList;
	string s;
	book* t=nullptr;
	char n;
	auto pos = bookList.begin();
	cout << "�������ɾ����ͼ����(���롰cancel��ȡ��):";
	cin >> s;
	if (s == "cancel")
	{
		system("cls");
		maintenance();
		exit(0);
	}
	for (book i : bl) //������⣬�����鼮
	{
		if (i.getId() == s)
			t = &i;
		pos++;
	}
		
	if (t!=nullptr) //�ж��Ƿ��и���
	{
		cout << "��ͼ����ϢΪ��" << endl;
		cout << "���\t\t\t����\t\t\t����\t\t\t������\t\t\t���\t\t\t���\t\t\t�����" << endl;
		cout << *t;
		cout << "ɾ���󲻿ɻָ����Ƿ�ɾ������y��n):";
		cin >> n;
		while (n != 'n' && n != 'y')
		{
			cout << "����������������루n��y)��" << endl;
			cin >> n;
		}
		if (n == 'y')
		{
			bookList.erase(pos);
			cout << "ɾ���ɹ������ڷ���......" << endl;
			Sleep(300);
			system("cls");
			maintenance();
			exit(0);
		}
		else
		{
			cout << "���ڷ���......" << endl;
			Sleep(300);
			system("cls");
			maintenance();
			exit(0);
		}
	}
	else
	{
		cout << "��ѯ������ͼ��" << endl;
		cout << "���ڷ���" << endl;
		Sleep(300);
		deleteBook();
		exit(0);
	}
}
int System::checkId(book& p) //ͼ���ظ�id���
{
	for (book i : bookList)
		if (i.getId() == p.getId())
			return 1; //�ظ��򷵻�1
	return 0;
}
int System::checkType(book& p) //�����
{
	if (p.getType() == "��ѧ" || p.getType() == "����" || p.getType() == "����"
		|| p.getType() == "����" || p.getType() == "����")
		return 0; //���Ϸ���0
	else
		return 1;
}
void System::typebook() //����ӡ
{
	char t;
	int n = 0;	
	string s;
	cout << "������Ҫ�鿴��ͼ�����" << endl;
	cout << "1.��ѧ" << endl;
	cout << "2.����" << endl;
	cout << "3.����" << endl;
	cout << "4.����" << endl;
	cout << "5.����" << endl;
	cout << "6.������һ��" << endl;
	cin >> t;
	while (t < '1' || t > '6')
	{
		cout << "�����������������" << endl;
		cout << "��ѡ��Ҫ�鿴��ͼ�����";
		cin >> t;
	}
	if (t == '6')
	{
		cout << "���ڷ���......" << endl;
		Sleep(300);
		system("cls");
		menu();
		exit(0);
	}
	switch (t)
	{
	case '1':
		s = "��ѧ";
		break;
	case '2':
		s = "����";
		break;
	case '3':
		s = "����";
		break;
	case '4':
		s = "����";
		break;
	case '5':
		s = "����";
		break;
	}
	cout << "���\t\t\t����\t\t\t����\t\t\t������\t\t\t���\t\t\t���\t\t\t�����" << endl;
	for (book i : bookList)
		if (i.getType() == s)
		{
			cout << i;
			n += 1;
		}
	cout << s << "���ͼ���ܹ���" << n << "��" << endl;
	system("pause");
	cout << "���ڷ���" << endl;

	Sleep(300);
	system("cls");
	menu();
	exit(0);
}

void System::printAllBook()
{
	cout << "���\t\t\t����\t\t\t����\t\t\t������\t\t\t���\t\t\t���\t\t\t�����" << endl;
	char n = '1';
	int page = 1;
	for(book& b:bookList)
	{
		cout << b;
		page++;
		if (page%10==0)
		{
			cout << "��" <<page/10<< "ҳ" << endl;
			cout << "0:exit,1:next >> ";
			cin >> n;
			while (n != '1' && n != '0')
			{
				cout << "����������������루0 �� 1)��" << endl;
				cin >> n;
			}
			if (n == '0')
				break;
			else
			{
				system("cls");
				cout << "���\t\t\t����\t\t\t����\t\t\t������\t\t\t���\t\t\t���\t\t\t�����" << endl;
			}
		}
	}
	cout << "һ����" << bookList.size() << "��ͼ��" << endl;
}


void System::typeSave() //���ౣ��
{
	vector<book>& bl = bookList;
	char t;
	string s;
	int i = 0;
	cout << "������Ҫ��ȡ��ͼ�����(�����ȡ���������һ�α��������)" << endl;
	cout << "1.��ѧ" << endl;
	cout << "2.����" << endl;
	cout << "3.����" << endl;
	cout << "4.����" << endl;
	cout << "5.����" << endl;
	cout << "6.������һ��" << endl;
	cin >> t;
	while (t < '1' || t > '6')
	{
		cout << "�����������������" << endl;
		cout << "��ѡ��Ҫ��ȡ��ͼ�����";
		cin >> t;
	}
	if (t == '6')
	{
		cout << "���ڷ���......" << endl;
		Sleep(3000);
		system("cls");
		menu();
		exit(0);
	}
	switch (t)
	{
	case '1':
		s = "��ѧ";
		break;
	case '2':
		s = "����";
		break;
	case '3':
		s = "����";
		break;
	case '4':
		s = "����";
		break;
	case '5':
		s = "����";
		break;
	}
	string fileName = s + ".txt";
	fstream outfile(fileName, ios::out);
	if (!outfile)
	{
		cout << "�ļ�����ʧ��" << endl;
		exit(0);
	}
	else
	{
		for (book& b : bl)
			if (b.getType() == s)
			{
				outfile << b;
				i += 1;
			}
	}
	outfile.close();
	cout << "��ȡ�ɹ���" << s << "���ͼ���ܹ���" << i << "��" << endl;
	system("pause");
	cout << "���ڷ���" << endl;

	Sleep(300);
	system("cls");
	menu();
	exit(0);
}

bool cmp1(book& lc, book& rc)
{
	return lc.getPrice() > rc.getPrice();
}
bool cmp2(book& lc, book& rc)
{
	return lc.getPrice() < rc.getPrice();
}
bool cmp3(book& lc, book& rc)
{
	return lc.getSl() > rc.getSl();
}
bool cmp4(book& lc, book& rc)
{
	return lc.getSl() < rc.getSl();
}

void System::sortBooks() //��������ͼ��
{
	vector<book>& bl = bookList;
	char n;
	cout << "1.�۸���" << endl;
	cout << "2.�۸�����" << endl;
	cout << "3.��潵��" << endl;
	cout << "4.�������" << endl;
	cout << "5.������һ��" << endl;
	cout << "��ѡ������ʽ��";
	cin >> n;
	while (n < '1' || n > '5')
	{
		cout << "�����������������" << endl;
		cout << "��������Ĳ�������:";
		cin >> n;
	}
	if (n == '5')
	{
		cout << "���ڷ���" << endl;
		Sleep(300);
		system("cls");
		maintenance();
		exit(0);
	}
	if(bl.size()!=0)
		switch (n)
		{
		case '1':
			sort(bookList.begin(), bookList.end(), cmp1);
			break;
		case '2':
			sort(bookList.begin(), bookList.end(), cmp2);
			break;
		case '3':
			sort(bookList.begin(), bookList.end(), cmp3);
			break;
		case '4':
			sort(bookList.begin(), bookList.end(), cmp4);
			break;
		}
	cout << "ͼ������ɹ�" << endl;
	system("pause");
	cout << "���ڷ���" << endl;
	Sleep(300);
	system("cls");
	maintenance();
	exit(0);
}

