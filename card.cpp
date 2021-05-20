#include "card.h"
#include<iostream>
#include<iomanip>
#include<ctime>
using namespace std;
Card::Card()
{
	for (int i = 0; i < 52; i++)
	{
		card[i] = i;
	}
}
void Card::printallCard(int people, int player[][5],Point a[10],int*p,Player b[9])
{
	for (int i = 0; i <= people; i++)
	{
		if (i == people)
		{
			cout << "���a���P: ";
		}
		else
		{
			cout << "���a" << i+1 << "���P:";
		}
		for (int j = 0; j < 5; j++)
		{
			if (player[i][j] / 13==0)
			{
				cout << " ����";
			}
			else if (player[i][j] / 13 == 1)
			{
				cout << " �٧�";
			}
			else if (player[i][j] / 13 == 2)
			{
				cout << " �R��";
			}
			else
			{
				cout<< " �®�";
			}
			switch (player[i][j] % 13)
			{
			case 0:cout << " A";
				break;
			case 10:cout << " J";
				break;
			case 11:cout << " Q";
				break;
			case 12:cout << " K";
				break;
			default:cout << setw(2) << player[i][j] % 13 + 1;
				break;
			}
		}
		cout << "  ";
		a[i].printPoint();
		cout << "  ";
		if (i!=people)
		{
			a[i].comparePoint(a[people],i,b,p);
			if (b[i].getMoney() > 0)
			{
				cout<<" " << "�Ѿl���B:" << b[i].getMoney();
			}
			else
			{
				cout << " " << "�Ѿl���B:0";
			}
		}
		cout << endl << endl;
	}
}
void Card::Shuffle()
{
	int a, pos;
	srand(time(NULL));
	for (int i = 0; i != 52; ++i)
	{
		pos = rand()%52;
		a = card[i];
		card[i] = card[pos];
		card[pos] = a;
	}
}
void Card::Licensing(int people,int player[][5])
{
	for (int y = 0,a=0; y <= people; y++)
	{
		for (int i = 0; i < 5;i++,a++)
		{
			player[y][i] = card[a];
		}
	}
}
void Card::printCard(int position, int people, int player[][5], Point a[10], int* p, Player b[9])
{
	
		if (position == people)
		{
			cout << "���a���P: ";
		}
		else
		{
			cout << "���a" << position + 1 << "���P:";
		}
		for (int j = 0; j < 5; j++)
		{
			if (player[position][j] / 13 == 0)
			{
				cout << " ����";
			}
			else if (player[position][j] / 13 == 1)
			{
				cout << " �٧�";
			}
			else if (player[position][j] / 13 == 2)
			{
				cout << " �R��";
			}
			else
			{
				cout << " �®�";
			}
			switch (player[position][j] % 13)
			{
			case 0:cout << " A";
				break;
			case 10:cout << " J";
				break;
			case 11:cout << " Q";
				break;
			case 12:cout << " K";
				break;
			default:cout << setw(2) << player[position][j] % 13 + 1;
				break;
			}
		}
		cout << "  ";
		a[position].printPoint();
		cout << "  ";
		if (position != people)
		{
			a[position].comparePoint(a[people], position, b, p);
			if (b[position].getMoney() >0)
			{
				cout << " " << "�Ѿl���B:" << b[position].getMoney();
			}
			else
			{
				cout << " " << "�Ѿl���B:0";
			}
		}
		cout << endl << endl;
}