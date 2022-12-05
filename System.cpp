#include "System.h"
using namespace std;
void System::menu() //主菜单
{
	cout << "=======================================================" << endl;
	cout << "\t欢迎进入图书库存管理系统" << endl;
	cout << "\t1.系统维护" << endl;
	cout << "\t2.查找图书" << endl;
	cout << "\t3.展示全部图书" << endl;
	cout << "\t4.分类展示图书" << endl;
	cout << "\t5.图书类别提取" << endl;
	cout << "\t6.退出系统" << endl;
	cout << endl;
	cout << "=======================================================" << endl;
	
	cout << "请输入你的操作命令:";
	char n; //若定义为int类型，输入符号或汉字会刷屏，缺点是不能接受两位以上的字符
	cin >> n;
	while (n < '1' || n > '6')
	{
		cout << "输入错误，请重新输入" << endl;
		cout << "请输入你的操作命令:";
		cin >> n;
	}
	switch (n) //根据指令选择功能函数
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
		cout << "正在退出" << endl;
		Sleep(3000);
		exit(0);
	case '5':
		typeSave();
		break;
	}
}
void System::maintenance() //子菜单
{
	system("cls");
	cout << "=======================================================" << endl;
	cout << "\t系统维护" << endl;
	cout << "\t1.增加图书" << endl;
	cout << "\t2.修改图书" << endl;
	cout << "\t3.删除图书" << endl;
	cout << "\t4.排序图书" << endl;
	cout << "\t5.返回上一级" << endl;

	cout << "=======================================================" << endl;
	cout << "请输入你的操作命令:";
	char n; //若定义为int类型，输入符号或汉字会刷屏，缺点是不能接受两位以上的字符
	cin >> n;
	while (n < '1' || n > '5')
	{
		cout << "输入错误，请重新输入" << endl;
		cout << "请输入你的操作命令:";
		cin >> n;
	}
	switch (n) //根据指令选择功能函数
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
		cout << "正在返回" << endl;
		Sleep(3000);
		system("cls");
		menu();
		exit(0);
	}
}
int System::readBookInformation() //从文件读取数据，返回值只为了中断函数
{
	cout << "Reading......" << endl;
	ifstream infile("library.txt", ios::in);
	if (!infile)
	{
		cout << "图书文件不存在,创建文件中......" << endl; //文件不存在
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
		cout << "当前图书列表为空......" << endl;
	else
		printAllBook();
	Sleep(3000);
	system("cls");
	return 1;
}
void System::addBook() //用链表的方式添加图书
{
	char n;
	cout << "请输入图书信息（类别只能为文学，教育，管理，生活，艺术）：" << endl;
	book newBook;
	cout << "编号\t\t\t书名\t\t\t作者\t\t\t出版社\t\t\t金额\t\t\t类别\t\t\t库存量" << endl;
	cin >> newBook;
	if (checkId(newBook)) //检测添加的图书编号是否冲突
	{
		cout << "输入图书编号重复" << endl;
		cout << "正在返回" << endl;
		Sleep(3000);
		system("cls");
		maintenance();
		exit(0);
	}
	if (checkType(newBook)) //检测添加的图书类别是否符合
	{
		cout << "输入图书类别有误(文学，教育，管理，生活，艺术)" << endl;
		cout << "正在返回" << endl;
		Sleep(3000);
		system("cls");
		maintenance();
		exit(0);
	}
	bookList.push_back(newBook);
	cout << "录入成功，是否继续添加？（y或n):";
	cin >> n;
	while (n != 'n' && n != 'y')
	{
		cout << "输入错误，请重新输入（y或n)：" << endl;
		cin >> n;
	}
	if (n == 'y')
	{
		addBook();
		exit(0);
	}
	else
	{
		cout << "正在返回......" << endl;
		Sleep(3000);
		system("cls");
		maintenance();
		exit(0);
	}
}
void System::showBook() //展示图书列表
{
	const vector<book>& bl = bookList;
	printAllBook();
	system("pause");
	cout << "正在返回" << endl;
	Sleep(300);
	system("cls");
	menu();
	exit(0);
}
void System::editBookInformation() //修改图书信息
{
	const vector<book>& bl = bookList;
	string bookId;
	book* temp = nullptr;
	book wantBook;
	char n;
	cout << "请输入待修改的图书编号(输入“cancel”取消):";
	cin >> bookId;
	if (bookId == "cancel")
	{
		system("cls");
		maintenance();
		exit(0);
	}				  //返回菜单
	for (book i : bl)
		if (i.getId() == bookId)
			temp = &i;
	if (temp==nullptr)
	{
		cout << "查询不到该图书" << endl;
		cout	<< "正在返回" << endl;
		Sleep(3000);
		editBookInformation();
		exit(0);
	}
	else
	{
		system("cls");
		wantBook = *temp;
		cout << "目前该图书信息为" << endl;
		cout << "编号\t\t\t书名\t\t\t作者\t\t\t出版社\t\t\t金额\t\t\t类别\t\t\t库存量" << endl;
		cout << *temp << endl;
		cout << "====================================================" << endl;
		cout << "1.编号" << endl;
		cout << "2.书名" << endl;
		cout << "3.作者" << endl;
		cout << "4.出版社" << endl;
		cout << "5.金额" << endl;
		cout << "6.类别" << endl;
		cout << "7.库存量" << endl;
		cout << "8.返回上一级" << endl;
		cout << "请选择要修改的图书数据：";
		cin >> n;

		while (n < '1' || n > '8')
		{
			cout << "输入错误，请重新输入" << endl;
			cout << "请选择要修改的图书数据：";
			cin >> n;
		}
		if (n == '8')
		{
			cout << "正在返回" << endl;
			Sleep(3000);
			editBookInformation();
			exit(0);
		}
		cout << "输入修改后的数据（类别只能为文学，教育，管理，生活，艺术）：" << endl;

		switch (n) // temp为临时变量，因为编号和类别需要二次判断
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
		if (n == '1') //重复id检测
		{
			if (checkId(wantBook))
			{
				cout << "输入图书编号重复,";
				editBookInformation();
				exit(0);
			}
			else
			{
				*temp = wantBook;
			}
		}
		if (n == '6') //检测类别是否正确
		{
			if (checkType(wantBook))
			{
				cout << "输入图书类别有误（文学，教育，管理，生活，艺术)" << endl;
				editBookInformation();
				exit(0);
			}
			else
			{
				*temp = wantBook;
			}
		}
		cout << "目前该图书信息为" << endl;
		cout << "编号\t\t\t书名\t\t\t作者\t\t\t出版社\t\t\t金额\t\t\t类别\t\t\t库存量" << endl;
		cout << *temp << endl;
		system("pause");
		cout << "正在返回" << endl;
		Sleep(3000);
		system("cls");
		maintenance();
		exit(0);
	}
};

void System::saveFile() //把链表数据存入文件
{
	char r='n';
	cout << "是否保存 ? （y or n）" << endl;
	cin >> r;
	while (r != 'y' && r != 'n')
	{
		cout << "输入错误，请重新输入" << endl;
		cout << "是否保存 ? （y or n）" << endl;
		cin >> r;
	}
	if (r == 'y')
	{
		cout << "正在保存......" << endl;
		vector<book>& bl = bookList;
		fstream outfile("library.txt", ios::out);
		if (!outfile)
		{
			cout << "文件保存失败" << endl;
			exit(0);
		}
		else
		{
			for (book& b : bl)
				outfile << b;
			cout << "文件保存成功!" << endl;
		}
		outfile.close();
	}
}

void System::findBook() //查找图书
{
	char n;
	cout << "请选择搜索方式(1.编号\t2.书名):" << endl;
	cin >> n;
	while (n != '1' && n != '2')
	{
		cout << "输入错误，请重新输入" << endl;
		cout << "请选择搜索方式(1.编号\t2.书名):" << endl;
		cin >> n;
	}
	if (n == '1')
	{
		string s;
		book* t=nullptr;
		cout << "请输入待查找的图书编号(输入“cancel”取消):";
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
			cout << "查询不到该图书" << endl;
			cout << "正在返回" << endl;
			Sleep(300);
			findBook();
			exit(0);
		}
		else
		{
			cout << "目前该图书信息为" << endl;
			cout << "编号\t\t\t书名\t\t\t作者\t\t\t出版社\t\t\t金额\t\t\t类别\t\t\t库存量" << endl;
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
		cout << "请输入待修改的图书名字(输入“cancel”取消):";
		cin >> s;
		if (s == "cancel")
		{
			system("cls");
			menu();
			exit(0);
		}
		cout << "编号\t\t\t书名\t\t\t作者\t\t\t出版社\t\t\t金额\t\t\t类别\t\t\t库存量" << endl;
		for (book& b : bookList)
			if (b.getName() == s)
				t = &b;
		if (t == nullptr)
		{
			cout << "查询不到该图书" << endl;
			cout << "正在返回" << endl;
			Sleep(300);
			findBook();
			exit(0);
		}
		else
		{
			cout << "目前该图书信息为" << endl;
			cout << "编号\t\t\t书名\t\t\t作者\t\t\t出版社\t\t\t金额\t\t\t类别\t\t\t库存量" << endl;
			cout << *t << endl;
			system("pause");
			system("cls");
			menu();
			exit(0);
		}
	}
}
void System::deleteBook() //删除图书
{
	vector<book>& bl = bookList;
	string s;
	book* t=nullptr;
	char n;
	auto pos = bookList.begin();
	cout << "请输入待删除的图书编号(输入“cancel”取消):";
	cin >> s;
	if (s == "cancel")
	{
		system("cls");
		maintenance();
		exit(0);
	}
	for (book i : bl) //遍历书库，查找书籍
	{
		if (i.getId() == s)
			t = &i;
		pos++;
	}
		
	if (t!=nullptr) //判断是否有该书
	{
		cout << "该图书信息为：" << endl;
		cout << "编号\t\t\t书名\t\t\t作者\t\t\t出版社\t\t\t金额\t\t\t类别\t\t\t库存量" << endl;
		cout << *t;
		cout << "删除后不可恢复，是否删除？（y或n):";
		cin >> n;
		while (n != 'n' && n != 'y')
		{
			cout << "输入错误，请重新输入（n或y)：" << endl;
			cin >> n;
		}
		if (n == 'y')
		{
			bookList.erase(pos);
			cout << "删除成功，正在返回......" << endl;
			Sleep(300);
			system("cls");
			maintenance();
			exit(0);
		}
		else
		{
			cout << "正在返回......" << endl;
			Sleep(300);
			system("cls");
			maintenance();
			exit(0);
		}
	}
	else
	{
		cout << "查询不到该图书" << endl;
		cout << "正在返回" << endl;
		Sleep(300);
		deleteBook();
		exit(0);
	}
}
int System::checkId(book& p) //图书重复id检测
{
	for (book i : bookList)
		if (i.getId() == p.getId())
			return 1; //重复则返回1
	return 0;
}
int System::checkType(book& p) //类别检测
{
	if (p.getType() == "文学" || p.getType() == "教育" || p.getType() == "管理"
		|| p.getType() == "生活" || p.getType() == "艺术")
		return 0; //符合返回0
	else
		return 1;
}
void System::typebook() //类别打印
{
	char t;
	int n = 0;	
	string s;
	cout << "请输入要查看的图书类别" << endl;
	cout << "1.文学" << endl;
	cout << "2.教育" << endl;
	cout << "3.管理" << endl;
	cout << "4.生活" << endl;
	cout << "5.艺术" << endl;
	cout << "6.返回上一级" << endl;
	cin >> t;
	while (t < '1' || t > '6')
	{
		cout << "输入错误，请重新输入" << endl;
		cout << "请选择要查看的图书类别";
		cin >> t;
	}
	if (t == '6')
	{
		cout << "正在返回......" << endl;
		Sleep(300);
		system("cls");
		menu();
		exit(0);
	}
	switch (t)
	{
	case '1':
		s = "文学";
		break;
	case '2':
		s = "教育";
		break;
	case '3':
		s = "管理";
		break;
	case '4':
		s = "生活";
		break;
	case '5':
		s = "艺术";
		break;
	}
	cout << "编号\t\t\t书名\t\t\t作者\t\t\t出版社\t\t\t金额\t\t\t类别\t\t\t库存量" << endl;
	for (book i : bookList)
		if (i.getType() == s)
		{
			cout << i;
			n += 1;
		}
	cout << s << "类的图书总共有" << n << "本" << endl;
	system("pause");
	cout << "正在返回" << endl;

	Sleep(300);
	system("cls");
	menu();
	exit(0);
}

void System::printAllBook()
{
	cout << "编号\t\t\t书名\t\t\t作者\t\t\t出版社\t\t\t金额\t\t\t类别\t\t\t库存量" << endl;
	char n = '1';
	int page = 1;
	for(book& b:bookList)
	{
		cout << b;
		page++;
		if (page%10==0)
		{
			cout << "第" <<page/10<< "页" << endl;
			cout << "0:exit,1:next >> ";
			cin >> n;
			while (n != '1' && n != '0')
			{
				cout << "输入错误，请重新输入（0 或 1)：" << endl;
				cin >> n;
			}
			if (n == '0')
				break;
			else
			{
				system("cls");
				cout << "编号\t\t\t书名\t\t\t作者\t\t\t出版社\t\t\t金额\t\t\t类别\t\t\t库存量" << endl;
			}
		}
	}
	cout << "一共有" << bookList.size() << "本图书" << endl;
}


void System::typeSave() //按类保存
{
	vector<book>& bl = bookList;
	char t;
	string s;
	int i = 0;
	cout << "请输入要提取的图书类别(多次提取仅保留最后一次保存的数据)" << endl;
	cout << "1.文学" << endl;
	cout << "2.教育" << endl;
	cout << "3.管理" << endl;
	cout << "4.生活" << endl;
	cout << "5.艺术" << endl;
	cout << "6.返回上一级" << endl;
	cin >> t;
	while (t < '1' || t > '6')
	{
		cout << "输入错误，请重新输入" << endl;
		cout << "请选择要提取的图书类别";
		cin >> t;
	}
	if (t == '6')
	{
		cout << "正在返回......" << endl;
		Sleep(3000);
		system("cls");
		menu();
		exit(0);
	}
	switch (t)
	{
	case '1':
		s = "文学";
		break;
	case '2':
		s = "教育";
		break;
	case '3':
		s = "管理";
		break;
	case '4':
		s = "生活";
		break;
	case '5':
		s = "艺术";
		break;
	}
	string fileName = s + ".txt";
	fstream outfile(fileName, ios::out);
	if (!outfile)
	{
		cout << "文件保存失败" << endl;
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
	cout << "提取成功，" << s << "类的图书总共有" << i << "本" << endl;
	system("pause");
	cout << "正在返回" << endl;

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

void System::sortBooks() //按需排序图书
{
	vector<book>& bl = bookList;
	char n;
	cout << "1.价格降序" << endl;
	cout << "2.价格升序" << endl;
	cout << "3.库存降序" << endl;
	cout << "4.库存升序" << endl;
	cout << "5.返回上一级" << endl;
	cout << "请选择排序方式：";
	cin >> n;
	while (n < '1' || n > '5')
	{
		cout << "输入错误，请重新输入" << endl;
		cout << "请输入你的操作命令:";
		cin >> n;
	}
	if (n == '5')
	{
		cout << "正在返回" << endl;
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
	cout << "图书排序成功" << endl;
	system("pause");
	cout << "正在返回" << endl;
	Sleep(300);
	system("cls");
	maintenance();
	exit(0);
}

