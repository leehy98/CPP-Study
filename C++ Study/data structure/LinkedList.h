#pragma once
#include <assert.h>

// ���
template <typename T>
class CListNode
{
	template <typename T>
	friend class CLinkedList;

	template <typename T>
	friend class CListIterator;

	template <typename T>
	friend class CListReverseIterator;


private:
	CListNode()
	{
		m_pNext = nullptr;
		m_pPrev = nullptr;

	}
	~CListNode()
	{

	}

private:
	T						 m_Data;	// ���� ������ ���� ����
	CListNode<T>* m_pNext;	// ���� ��� �ּ� ���� ����
	CListNode<T>* m_pPrev;	// ���� ��� �ּ� ���� ����

};

// ����Ʈ ��� ��ȯ �ݺ���
template <typename T>
class CListIterator
{
	template <typename T>
	friend class CLinkedList;

public:
	CListIterator()
	{
		m_pNode = nullptr;
	}

	~CListIterator()
	{

	}

private:
	using PNODE = CListNode<T>*;

private:
	PNODE m_pNode;

public:
	bool operator == (const CListIterator<T>& iter)
	{
		return m_pNode == iter.m_pNode;
	}

	bool operator != (const CListIterator<T>& iter)
	{
		return m_pNode != iter.m_pNode;
	}

	void operator ++()
	{
		m_pNode = m_pNode->m_pNext;
	}

	void operator -- ()
	{
		m_pNode = m_pNode->m_pPrev;
	}

	T& operator * ()
	{
		return m_pNode->m_Data;
	}

};
// ����Ʈ ��� ����ȯ �ݺ���
template <typename T>
class CListReverseIterator
{
	template <typename T>
	friend class CLinkedList;

public:
	CListReverseIterator()
	{
		m_pNode = nullptr;
	}
	~CListReverseIterator()
	{

	}

private:
	using PNODE = CListNode<T>*;

private:
	PNODE m_pNode;

public:
	bool operator == (const CListReverseIterator<T>& iter)
	{
		return m_pNode == iter.m_pNode;

	}

	bool operator != (const CListReverseIterator<T>& iter)
	{
		return m_pNode != iter.m_pNode;

	}

	void operator ++()
	{
		m_pNode = m_pNode->m_pPrev;

	}

	void operator -- ()
	{
		m_pNode = m_pNode->m_pNext;

	}

	T& operator * ()
	{
		return m_pNode->m_Data;

	}

};

template <typename T>
class CLinkedList
{
public:
	CLinkedList()
	{
		m_pBegin = new NODE;
		m_pEnd = new NODE;
		m_pBegin->m_pNext = m_pEnd;
		m_pEnd->m_pPrev = m_pBegin;
		m_Isize = 0;

	}

	~CLinkedList()
	{
		// ���� �Ҵ�� ��� �޸� �Ҹ��ڿ��� ����
		NodeClear();
		delete m_pBegin;
		delete m_pEnd;

	}

private:
	using NODE = CListNode<T>;
	using PNODE = CListNode<T>*;

public:
	using Iterator = CListIterator<T>;
	using ReverseIterator = CListReverseIterator<T>;

private:
	PNODE m_pBegin;
	PNODE m_pEnd;
	int m_Isize;

public:
	// Begin �� End�� ������ ��带 �����ϴ� ���
	void NodeClear()
	{
		PNODE pNode = m_pBegin->m_pNext;

		while (pNode != m_pEnd)
		{
			// pNode�� ���� ���
			PNODE  pNext = pNode->m_pNext;
			// ���� ��� ����
			delete pNode;
			// ���� ��带 pNode�� �Ҵ� 
			pNode = pNext;

		}
		m_Isize = 0;

		//Begin End ����
		m_pBegin->m_pNext = m_pEnd;
		m_pEnd->m_pPrev = m_pBegin;

	}

	// Begin�� End ���̿� ���ο� ��带 �߰��ϴ� ���
	void PushBack(const T& data)
	{
		// �߰��� ���ο� ��� 
		PNODE pNode = new NODE;
		pNode->m_Data = data;

		// �ڿ� �߰��Ǳ� ������ End����� ���� ���(Begin)�� ������
		PNODE pPrev = m_pEnd->m_pPrev;

		// ���� ���(Begin)�� ���� ���(End)�� ���̿� ���ο� ���(pNode)�� �߰��Ѵ�
		pPrev->m_pNext = pNode;
		pNode->m_pPrev = pPrev;

		// End ����� �� ��带 pNode�� ����
		pNode->m_pNext = m_pEnd;
		m_pEnd->m_pPrev = pNode;

		// ��尡 �߰��Ǿ����� ������ ����
		++m_Isize;

	}

	// Begin�� End �߰��� ����� �տ� ���ο� ��带 �߰��ϴ� �Լ�
	void PushFront(const T& data)
	{
		PNODE pNode = new NODE;
		pNode->m_Data = data;

		// Begin�� ���� ����� �ּ�
		PNODE pNext = m_pBegin->m_pNext;

		// ���� ������ ����� ���� ��带 Begin�� ���� ���� ���� 
		pNode->m_pNext = pNext;
		// Begin�� ���� ����� ���� ���� ���� ������ ��带 ����
		pNext->m_pPrev = pNode;

		// Begin�� ���� ��带 ���� ������ ���� ����
		m_pBegin->m_pNext = pNode;
		// ���λ����� ����� ���� ��带 Begin���� ����
		pNode->m_pPrev = m_pBegin;

		++m_Isize;

	}

	// �ڿ������� ��带 �����ϴ� ���
	void PopBack()
	{
		if (Empty())
			assert(false);
		// ������ ��� �ּ�
		PNODE pDeleteNode = m_pEnd->m_pPrev;

		// ���� ����� ���� ��� 
		PNODE pPrev = pDeleteNode->m_pPrev;

		// ���� ����� ���� ��带 End�� ����
		pPrev->m_pNext = m_pEnd;
		// End�� ���� ��带 ���� ����� ���� ���� ����
		m_pEnd->m_pPrev = pPrev;

		delete pDeleteNode;

		//������ ����
		--m_Isize;

	}

	// �տ������� ��带 �����ϴ� ���
	void PopFront()
	{
		if (Empty())
			assert(false);
		// ������
		PNODE pDeleteNode = m_pBegin->m_pNext;
		// �������� ���� ���
		PNODE pNext = pDeleteNode->m_pNext;

		//Begin�� ������ ������ ���� ���� ����
		m_pBegin->m_pNext = pNext;
		// �������� ���� ����� �� ��带 Begin���� ���� 
		pNext->m_pPrev = m_pBegin;

		delete pDeleteNode;

		--m_Isize;

	}

	// Begin�� ���� ����� ������ ����
	T GetFrontData() const
	{
		if (Empty())
			assert(false);
		return m_pBegin->m_pNext->m_Data;

	}
	// End�� ���� ����� ������ ����
	T GetRearData() const
	{
		if (Empty())
			assert(false);
		return m_pEnd->m_pPrev->m_Data;

	}
	// ����Ʈ ũ�⸦ ��ȯ
	int Size() const
	{
		return m_Isize;

	}

	// ��尡 �������(��ȯ ������ ���̸�) true �ƴϸ� false
	bool Empty() const
	{
		return m_Isize == 0;

	}

public:
	// ���ͷ����� ����
	Iterator Begin() const
	{
		Iterator Iter;
		Iter.m_pNode = m_pBegin->m_pNext;
		return Iter;

	}
	// ���ͷ����� ��
	Iterator End() const
	{
		Iterator Iter;
		Iter.m_pNode = m_pEnd;
		return Iter;

	}
	// ������ ���ͷ������� ����
	ReverseIterator rBegin() const
	{
		ReverseIterator Iter;
		Iter.m_pNode = m_pEnd->m_pPrev;
		return Iter;

	}
	// ������ ���ͷ������� ��
	ReverseIterator rEnd() const
	{
		ReverseIterator Iter;
		Iter.m_pNode = m_pBegin;
		return Iter;

	}

public:
	// ����, ������ �Լ��� �Ű������� �޴´�. cpp���Ͽ� DataSort ���� ��ȣ�� �ٲ��ָ� �������� �������� ���ϴ� ���Ĺ���� ���Ҽ� �ִ�.
	void Sort(bool(*pFunc)(const T&, const T&))
	{
		for (PNODE pFirst = m_pBegin->m_pNext; pFirst != m_pEnd; pFirst = pFirst->m_pNext)
		{
			for (PNODE pSecound = m_pBegin->m_pNext; pSecound != m_pEnd; pSecound = pSecound->m_pNext)
			{
				if (pFunc(pFirst->m_Data, pSecound->m_Data))
				{
					T temp = pFirst->m_Data;
					pFirst->m_Data = pSecound->m_Data;
					pSecound->m_Data = temp;

				}

			}

		}

	}

	//�ڿ��� ���� n��° ��带 ã�� ���� ���
	T PrintNthFromEnd(T Nth) const
	{
		int count = 0;
		T N; // �����͸� ���� ����
		for (PNODE NthNode = m_pEnd->m_pPrev; NthNode != m_pBegin->m_pNext; NthNode = NthNode->m_pPrev)
		{
			if (Nth == count) 
			{
				N = NthNode->m_Data;
				break;

			}
			count++;

		}
		return N;

	}

	//�տ��� ���� n��° ��带 ã�� ���� ���
	T PrintNthFromBegin(T Nth) const
	{
		int count = 0;
		T N; // �����͸� ���� ����
		for (PNODE NthNode = m_pBegin->m_pNext; NthNode != m_pEnd->m_pPrev; NthNode = NthNode->m_pNext)
		{
			if (Nth == count)
			{
				N = NthNode->m_Data;
				break;

			}
			count++;

		}
		return N;

	}

	//�ߺ��� ����
	void RemoveDuplicates()
	{
		for (PNODE pNode = m_pBegin->m_pNext; pNode != m_pEnd; pNode = pNode->m_pNext)
		{
			PNODE NextNode = pNode->m_pNext;
			// �ݺ��� ���� : ���� ��尡 End�� �ƴҶ�����
			while (NextNode != m_pEnd)
			{
				// ����� �����Ͱ� ������
				if (pNode->m_Data == NextNode->m_Data)
				{
					// �����Ͱ� ������ ���� ��带 ������ ���� ���� ������ ����� ���� ��带 �̾��ش�.
					PNODE NextNextNode = NextNode->m_pNext;
					
					if (NextNextNode) // ���� ����� ���� ��尡 ������
					{
						NextNextNode->m_pPrev = NextNode->m_pPrev; // ���� ���� ����� ���� ��带 ���� ����� ���� ���� ���� 
					}
					NextNode->m_pPrev->m_pNext = NextNextNode;	// ���� ����� ���� ����� ���� ���� �������� ���� ����
					
					delete NextNode; // ���� ��� ����
					NextNode = NextNextNode; // NextNode�� ���� ���� ������Ʈ
				}
				else
				{
					NextNode = NextNode->m_pNext; // �ߺ��� �ƴϸ� ���� ���� �̵�
				}
			}
		}
	}
	
	bool FindSycle()
	{

		return;
	}

	int Josephus()
	{
		return;
	}

	bool Palindrome()
	{

	}

};