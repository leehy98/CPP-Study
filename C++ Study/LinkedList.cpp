#include <iostream>
#include <time.h>
#include "LinkedList.h"

using namespace std;

struct TagData
{
	int iData;
};

bool DataSort(const TagData& tSrc, const TagData& Dest)
{
	return tSrc.iData > Dest.iData;
}


int main()
{
	CLinkedList<int> IntLinkedList;

	for (int IntLinkedListNode = 10; IntLinkedListNode < 20; ++IntLinkedListNode)
	{
		IntLinkedList.PushBack(IntLinkedListNode);

	}

	cout << "int size : " << IntLinkedList.Size() << endl;
	cout << IntLinkedList.PrintNthFromEnd(5) << endl;
	cout << IntLinkedList.PrintNthFromBegin(5) << endl;

	CLinkedList<int>::Iterator iter;
	CLinkedList<int>::Iterator iterEnd = IntLinkedList.End();

	for (iter = IntLinkedList.Begin(); iter != iterEnd; ++iter)
	{
		cout << *iter << " ";

	}
	cout << endl;

	CLinkedList<int>::ReverseIterator ReverseIter;
	CLinkedList<int>::ReverseIterator ReversetIterEnd = IntLinkedList.rEnd();

	for (ReverseIter = IntLinkedList.rBegin(); ReverseIter != ReversetIterEnd; ++ReverseIter)
	{
		cout << *ReverseIter << " ";

	}

	cout << endl;

	CLinkedList<TagData> DataList;
	cout << "================Data List==================" << endl;
	cout << endl;

	srand((unsigned int)time(0));

	for (int i = 0; i< 10; ++i)
	{
		TagData tData = {};

		tData.iData = rand() % 100;

		DataList.PushBack(tData);
		
		cout << tData.iData << " ";

	}

	cout << endl;
	cout << endl;

	cout << "==================sort================" << endl;
	cout << endl;

	DataList.Sort(DataSort);

	CLinkedList<TagData>::Iterator IterD;
	CLinkedList<TagData>::Iterator IterDEnd = DataList.End();

	for (IterD = DataList.Begin(); IterD != IterDEnd; ++IterD)
	{
		cout << (*IterD).iData << " ";

	}

	cout << endl;
	cout << endl;

	cout << "==================Reverse================" << endl;
	cout << endl;

	CLinkedList<TagData>::ReverseIterator rIterD;
	CLinkedList<TagData>::ReverseIterator rIterDEnd = DataList.rEnd();

	for (rIterD = DataList.rBegin(); rIterD != rIterDEnd; ++rIterD)
	{
		cout << (*rIterD).iData << " ";

	}

	cout << endl;
	cout << endl;

	cout << "==================Remove Duplicate================" << endl;

	cout << endl;

	CLinkedList<int> RemoveNode;
	RemoveNode.PushBack(1);
	RemoveNode.PushBack(2);
	RemoveNode.PushBack(3);
	RemoveNode.PushBack(1);
	RemoveNode.PushBack(1);
	

	CLinkedList<int>::Iterator RemoveIter;
	CLinkedList<int>::Iterator RemoveIterEnd = RemoveNode.End();

	for (RemoveIter = RemoveNode.Begin(); RemoveIter != RemoveIterEnd; ++RemoveIter)
	{
		
		cout << *RemoveIter<< " ";

	}
	RemoveNode.RemoveDuplicates();

	cout << endl;

	for (RemoveIter = RemoveNode.Begin(); RemoveIter != RemoveIterEnd; ++RemoveIter)
	{

		cout << *RemoveIter << " ";

	}

}
