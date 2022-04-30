#include "Arbore.h"
#include<iostream>
using namespace std;
int max(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}

Arbore::Node* Arbore::AdaugareFrunza(int val) {
	Node* n = new Node;
	n->val = val;
	n->st = NULL;
	n->dr = NULL;

	return n;
}

Arbore::Arbore()
{
	radacina = NULL;
}

Arbore::Arbore(const Arbore& B)
{
	this->nr_noduri = B.nr_noduri;
	this->radacina = B.radacina;
}

Arbore::~Arbore()
{
}

int Arbore::GetNrNod()
{
	return nr_noduri;
}

void Arbore::ParcurgerePre(Node* a)
{
	if (a->dr != nullptr && a->st != nullptr)
	{
		std::cout << a->val;
		ParcurgerePre(a->st);
		ParcurgerePre(a->dr);
	}
	else
		return;

}

void Arbore::ParcurgereIn(Node* a)
{
	if (a->dr != nullptr && a->st != nullptr)
	{
		ParcurgereIn(a->st);
		std::cout << a->val;
		ParcurgereIn(a->dr);
	}
	else
		return;
}

void Arbore::ParcurgerePost(Node* a)
{
	if (a->dr != nullptr && a->st != nullptr)
	{
		ParcurgerePost(a->st);
		ParcurgerePost(a->dr);
		std::cout << a->val;
	}
	else
		return;
}


int Arbore::DetNivel(Node* a, int x, int nivel)
{
	if (a == NULL)
		return 0;

	if (a->val == x)
		return nivel;

	int downlevel = DetNivel(a->st, x, nivel + 1);
	if (downlevel != 0)
		return downlevel;

	downlevel = DetNivel(a->dr, x, nivel + 1);
	return downlevel;
}

void Arbore::AfisareNoduriNivel(Node* a, int nivel, int max)
{
	if (a->dr != nullptr && a->st != nullptr && (nivel < max))
	{
		AfisareNoduriNivel(a->st, nivel + 1, max);
		if (nivel == max)
			std::cout << a->val;
		AfisareNoduriNivel(a->dr, nivel + 1, max);
	}
	else
		return;
}

void Arbore::AfisareFrunze()
{
	ParcurgerePre(radacina);
}

void Arbore::InsertNode(int x, Node* a)
{
	if (a->st)
		InsertNode(x, a->st);
	if (a->dr)
		InsertNode(x, a->dr);
	if (a == nullptr)
	{
		Node* p = nullptr;
		a->st = p;
		a->dr = p;
		a->val = x;
	}

}

int Arbore::Inaltime(Node* a)
{
	if (a == NULL)
		return 0;

	else {
		// Find the height of left, right subtrees
		int left_height = Inaltime(a->st);
		int right_height = Inaltime(a->dr);

		// Find max(subtree_height) + 1 to get the height of the tree
		return max(left_height, right_height) + 1;
	}
}

istream& operator>>(istream& is, Arbore& B)
{
	int nrEl, numar;
	B.nr_noduri = 0;
	is >> nrEl;
	B.nr_noduri = nrEl;

	for (int i = 0; i < B.nr_noduri; i++)
	{
		is >> numar;
		B.InsertNode(numar, B.radacina);
	}
	return is;

}


ostream& operator<<(ostream& os, Arbore& B)
{
	//Pana unde se duc nr in vect de frecv.
	os << B.radacina->val << ' ';
	if (B.radacina->st != nullptr)
	{
		B.radacina = B.radacina->st;
		operator<< (os, B);
	}
	if (B.radacina->dr != nullptr)
	{
		B.radacina = B.radacina->dr;
		operator<< (os, B);
	}
	return os;
}