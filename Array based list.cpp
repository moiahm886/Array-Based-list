#include<iostream>
using namespace std;
class List
{
	int* list;
	int length;
	int size;
public:
	List(int x)
	{
		size = x;
		list = new int[size];
		length = 0;

	}
	void addtoempty(int value)
	{
		if (length == 0)
		{
			list[length] = value;
			length++;
		}
		else
		{
			addtoend(value);
		}

	}
	void isfull()
	{
		if (length == size)
		{
			int* Arr;
			Arr = new int[size + 10];
			for (int i = 0; i < length; i++)
			{
				Arr[i] = list[i];	
			}
			delete[]list;
			list = Arr;
			Arr = NULL;
		}
	}
	void addtoend(int value)
	{
		if (length == 0)
		{
			addtoempty(value);
		}
		else
		{
			list[length] = value;
			length++;
		}

	}
	void addinbetween(int position, int value)
	{
		if (position < 0 || position >= length)
		{
			cout << "Position is not right\n";
		}
		else
		{
			if (length == 0)
			{
				addtoempty(value);
			}
			else
			{
				for (int i = length; i > position; i--)
				{
					list[i] = list[i - 1];
				}
				list[position] = value;
				length++;
			}
		}

	}
	void deletion(int position)
	{
		if(position<=0||position>length)
		{
			cout << "Position is not right\n";
		}
		else
		{
			for (int i = position;i<length; i++)
			{
				list[i] = list[i+1];
			}
			length--;
		}
	}
	void display()
	{
		cout << "Values in the list are as follows\n";
		for (int i = 0; i < length; i++)
		{
			cout << list[i] << "\t";
		}

	}
};
int main()
{
	List l(7);
	l.addtoempty(23);
	l.deletion(1);
	l.addtoend(8);
	l.addtoend(45);
	l.addtoend(34);
	l.addtoend(4);
	l.addtoend(57);
	l.addtoend(47);
	l.addtoend(178);
	l.addtoend(79);
	l.addinbetween(4, 69);
	l.display();
}