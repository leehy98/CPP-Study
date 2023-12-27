#pragma once
#include <assert.h>

// 노드
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
	T						 m_Data;	// 실제 데이터 저장 변수
	CListNode<T>* m_pNext;	// 다음 노드 주소 저장 변수
	CListNode<T>* m_pPrev;	// 이전 노드 주소 저장 변수

};

// 리스트 노드 순환 반복자
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
// 리스트 노드 역순환 반복자
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
		// 동적 할당된 모든 메모리 소멸자에서 해제
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
	// Begin 과 End를 제외한 노드를 삭제하는 기능
	void NodeClear()
	{
		PNODE pNode = m_pBegin->m_pNext;

		while (pNode != m_pEnd)
		{
			// pNode의 다음 노드
			PNODE  pNext = pNode->m_pNext;
			// 현재 노드 삭제
			delete pNode;
			// 다음 노드를 pNode에 할당 
			pNode = pNext;

		}
		m_Isize = 0;

		//Begin End 연결
		m_pBegin->m_pNext = m_pEnd;
		m_pEnd->m_pPrev = m_pBegin;

	}

	// Begin과 End 사이에 새로운 노드를 추가하는 기능
	void PushBack(const T& data)
	{
		// 추가될 새로운 노드 
		PNODE pNode = new NODE;
		pNode->m_Data = data;

		// 뒤에 추가되기 때문에 End노드의 이전 노드(Begin)를 가져옴
		PNODE pPrev = m_pEnd->m_pPrev;

		// 얻어온 노드(Begin)와 이전 노드(End)의 사이에 새로운 노드(pNode)를 추가한다
		pPrev->m_pNext = pNode;
		pNode->m_pPrev = pPrev;

		// End 노드의 전 노드를 pNode로 지정
		pNode->m_pNext = m_pEnd;
		m_pEnd->m_pPrev = pNode;

		// 노드가 추가되었으니 사이즈 증가
		++m_Isize;

	}

	// Begin과 End 추가된 노드의 앞에 새로운 노드를 추가하는 함수
	void PushFront(const T& data)
	{
		PNODE pNode = new NODE;
		pNode->m_Data = data;

		// Begin의 다음 노드의 주소
		PNODE pNext = m_pBegin->m_pNext;

		// 새로 생성한 노드의 다음 노드를 Begin의 다음 노드로 설정 
		pNode->m_pNext = pNext;
		// Begin의 다음 노드의 이전 노드로 새로 생성한 노드를 설정
		pNext->m_pPrev = pNode;

		// Begin의 다음 노드를 새로 생성한 노드로 설정
		m_pBegin->m_pNext = pNode;
		// 새로생성한 노드의 이전 노드를 Begin으로 설정
		pNode->m_pPrev = m_pBegin;

		++m_Isize;

	}

	// 뒤에서부터 노드를 삭제하는 기능
	void PopBack()
	{
		if (Empty())
			assert(false);
		// 삭제할 노드 주소
		PNODE pDeleteNode = m_pEnd->m_pPrev;

		// 지울 노드의 이전 노드 
		PNODE pPrev = pDeleteNode->m_pPrev;

		// 지울 노드의 이전 노드를 End와 연결
		pPrev->m_pNext = m_pEnd;
		// End의 이전 노드를 지울 노드의 이전 노드로 연결
		m_pEnd->m_pPrev = pPrev;

		delete pDeleteNode;

		//사이즈 감소
		--m_Isize;

	}

	// 앞에서부터 노드를 삭제하는 기능
	void PopFront()
	{
		if (Empty())
			assert(false);
		// 지울노드
		PNODE pDeleteNode = m_pBegin->m_pNext;
		// 지울노드의 다음 노드
		PNODE pNext = pDeleteNode->m_pNext;

		//Begin의 다음을 지울노드 다음 노드로 설정
		m_pBegin->m_pNext = pNext;
		// 지울노드의 다음 노드의 전 노드를 Begin으로 설정 
		pNext->m_pPrev = m_pBegin;

		delete pDeleteNode;

		--m_Isize;

	}

	// Begin의 다음 노드의 데이터 리턴
	T GetFrontData() const
	{
		if (Empty())
			assert(false);
		return m_pBegin->m_pNext->m_Data;

	}
	// End의 이전 노드의 데이터 리턴
	T GetRearData() const
	{
		if (Empty())
			assert(false);
		return m_pEnd->m_pPrev->m_Data;

	}
	// 리스트 크기를 반환
	int Size() const
	{
		return m_Isize;

	}

	// 노드가 비었으면(반환 조건이 참이면) true 아니면 false
	bool Empty() const
	{
		return m_Isize == 0;

	}

public:
	// 이터레이터 시작
	Iterator Begin() const
	{
		Iterator Iter;
		Iter.m_pNode = m_pBegin->m_pNext;
		return Iter;

	}
	// 이터레이터 끝
	Iterator End() const
	{
		Iterator Iter;
		Iter.m_pNode = m_pEnd;
		return Iter;

	}
	// 리버스 이터레이터의 시작
	ReverseIterator rBegin() const
	{
		ReverseIterator Iter;
		Iter.m_pNode = m_pEnd->m_pPrev;
		return Iter;

	}
	// 리버스 이터레이터의 끝
	ReverseIterator rEnd() const
	{
		ReverseIterator Iter;
		Iter.m_pNode = m_pBegin;
		return Iter;

	}

public:
	// 정렬, 포인터 함수를 매개변수로 받는다. cpp파일에 DataSort 참고 괄호를 바꿔주면 오름차순 내림차순 원하는 정렬방법을 정할수 있다.
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

	//뒤에서 부터 n번째 노드를 찾고 값을 출력
	T PrintNthFromEnd(T Nth) const
	{
		int count = 0;
		T N; // 데이터를 담을 변수
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

	//앞에서 부터 n번째 노드를 찾고 값을 출력
	T PrintNthFromBegin(T Nth) const
	{
		int count = 0;
		T N; // 데이터를 담을 변수
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

	//중복값 제거
	void RemoveDuplicates()
	{
		for (PNODE pNode = m_pBegin->m_pNext; pNode != m_pEnd; pNode = pNode->m_pNext)
		{
			PNODE NextNode = pNode->m_pNext;
			// 반복문 조건 : 다음 노드가 End가 아닐때까지
			while (NextNode != m_pEnd)
			{
				// 노드의 데이터가 같으면
				if (pNode->m_Data == NextNode->m_Data)
				{
					// 데이터가 같으면 다음 노드를 삭제후 현재 노드와 삭제한 노드의 다음 노드를 이어준다.
					PNODE NextNextNode = NextNode->m_pNext;
					
					if (NextNextNode) // 다음 노드의 다음 노드가 있으면
					{
						NextNextNode->m_pPrev = NextNode->m_pPrev; // 다음 다음 노드의 이전 노드를 다음 노드의 이전 노드로 설정 
					}
					NextNode->m_pPrev->m_pNext = NextNextNode;	// 다음 노드의 이전 노드의 다음 노드는 다음다음 노드로 지정
					
					delete NextNode; // 다음 노드 삭제
					NextNode = NextNextNode; // NextNode를 다음 노드로 업데이트
				}
				else
				{
					NextNode = NextNode->m_pNext; // 중복이 아니면 다음 노드로 이동
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