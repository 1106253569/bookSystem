#include "book.h"

ostream& operator <<(ostream& out, book& b)
{
	const int maxLong = 10;
	out << setw(maxLong) << setiosflags(ios::left) << b.getId() << "\t\t";
	out << setw(maxLong) << setiosflags(ios::left) << b.getName() << "\t\t";
	out << setw(maxLong) << setiosflags(ios::left) << b.getWriter() << "\t\t";
	out << setw(maxLong) << setiosflags(ios::left) << b.getHome() << "\t\t";
	out << setw(maxLong) << setiosflags(ios::left) << b.getPrice() << "\t\t";
	out << setw(maxLong) << setiosflags(ios::left) << b.getType() << "\t\t";
	out << setw(maxLong) << setiosflags(ios::left) << b.getSl() << endl;
	return out;
}

istream& operator >>(istream& in, book& b)
{
	in >> b.id >> b.name >> b.writer >> b.home >> b.price >> b.type >> b.sl;
	return in;
}

