#ifndef __LinkedList_H__
#define __LinkedList_H__
#include "Tools.h" //Iostream & Typedef

template<class TYPE>
struct NodeList //Struct: everything is public (by default)
{	
	NodeList<TYPE>* Prev, Next = NULL; //Private and GETs
	TYPE Data; //Public

	NodeList(const TYPE& Data): Data(Data){} //Constructor
	//Destr is created by default
};


template<class TYPE>
class List
{
public:
	NodeList<TYPE>* Start, End = NULL; 
	//Erase END and do it another time (start private and getstart (torna punter constant)

	List(){} //Constructor
	//Falta destr

	void PushBack(const TYPE& Data) //PushBack
	{
		ListNode<TYPE>* NewNode = new NodeList<TYPE>(Data);

		if (Data != NULL)
		{
			End->Next = NewNode;
			End = End->Next;
		}
		else
			Start = End = NewNode;
	}

	bool Empty() const //CheckEmpty
	{
		return Start == NULL;
	}

	void Clear() //Clear
	{
		NodeList<TYPE>* Tmp = End;

		for (uint i = Size(); i > 0; i--)
		{
			Tmp = Tmp->Prev;
			delete Tmp->Next;
		}
		Start = End = NULL;
	}

	uint Size() const //Size
	{
		NodeList<TYPE>* Tmp = Start;
		uint Ret = 0;

		while (Tmp)
		{
			++Ret;
			Tmp = Tmp->Next;
		}
		return Ret;
	}
};
#endif //__LinkedList_H__

//NEXT DAY: 
/*
-front() un get del start (tornen nodes constants)
-back() un get de l'ultim
-PushFront() 
-popback(tornen el qe sa eliminat)
-popfront (que torni el valor que s'ha eliminat)
-insert afegeix un node en alguna posicio que tu vulguis
-remove agafa un node i el treu (no retornem la data que eliminem)

*/