#pragma once
#include "Node.h"
#include<iostream>
using namespace std;
class Arbore
{
private:
	struct Node
	{
		int val;
		Node* st;
		Node* dr;
	};
	int nr_noduri;
	

public:
	Arbore();
	Arbore(const Arbore&);
	~Arbore();
	Node* radacina;
	Node* AdaugareFrunza(int val);
	int GetNrNod();
	void ParcurgerePre(Node* a);
	void ParcurgereIn(Node* a);
	void ParcurgerePost(Node* a);
	int DetNivel(Node*, int, int);
	void AfisareNoduriNivel(Node* a, int, int);
	int Inaltime(Node*);
	void AfisareFrunze();
	void InsertNode(int x, Node* a);
	friend istream& operator>>(istream& is, Arbore&);
	friend ostream& operator<<(ostream& os, Arbore&);
};