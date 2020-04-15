#pragma once
#ifndef _SLWP_H
#define _SLWP_H
template <typename T>
class SortedList_p
{
private:
	T* m_Array;		///< list array.
	int m_Length;		///< number of elements in list.
	int m_CurPointer;	///< iterator pointer.
	int m_MaxSize;		///< max size.

public:
	SortedList_p();
	~SortedList_p();

	void MakeEmpty();
	int GetLength();
	bool IsFull();

	void ResetList();
	int GetNextItem(T& data);

	int Add( T inData);
	int Get(T& data);
	int Delete(T data);
	int Replace(const T data);

	int GetByBinarySearch(T data);
};


template<typename T>
SortedList_p<T>::SortedList_p()
{
	m_MaxSize = ADDSIZE;
	m_Length = 0;
	ResetList();
	m_Array = new T[m_MaxSize];
}

template<typename T>
SortedList_p<T>::~SortedList_p()
{
	delete[] m_Array;
}

template<typename T>
void SortedList_p<T>::MakeEmpty()
{
	m_Length = 0;
}

template<typename T>
int SortedList_p<T>::GetLength()
{
	return m_Length;
}

template<typename T>
bool SortedList_p<T>::IsFull()
{
	if (m_Length > m_MaxSize - 1)
		return true;
	else
		return false;
}

template<typename T>
void SortedList_p<T>::ResetList()
{
	m_CurPointer = -1;
}

template<typename T>
int SortedList_p<T>::GetNextItem(T& data)
{
	m_CurPointer++;
	if (m_CurPointer == m_Length)
		return -1;
	data = m_Array[m_CurPointer];

	return m_CurPointer;
}

template<typename T>
int SortedList_p<T>::Add( T inData)
{
	if (IsFull()) {
		T* tmpList = new T[m_Length];
		for (int i = 0; i < m_Length; ++i) {
			tmpList[i] = m_Array[i];
		}
		delete[] m_Array;
		m_MaxSize += ADDSIZE;
		m_Array = new T[m_MaxSize];
		for (int i = 0; i < m_Length; ++i) {
			m_Array[i] = tmpList[i];
		}
		delete[] tmpList;
	}

	if (m_Length == 0)
	{
		//cout << "Adding " << inData << endl;;
		//cout <<"ID: " <<inData->GetId() <<"=========\n"<< endl;
		m_Array[m_Length] = inData;
		//cout << "In the List:\n" << m_Array[m_Length] << endl;
		m_Length++;
		return 1;
	}
	else
	{
		for (int i = 0; i < m_Length; i++)
		{
			if (&m_Array[i] < &inData) {
				if (i == m_Length - 1)
				{
					m_Array[m_Length] = inData;
					m_Length++;
					return 1;
				}
			}
			else if (&m_Array[i] > &inData) {
				for (int j = m_Length; j > i; j--)
				{
					m_Array[j] = m_Array[j - 1];
				}
				m_Array[i] = inData;
				m_Length++;
				return 1;
			}
			else {
				return -1;
			}
		}
	}
	return 0;
}

template<typename T>
int SortedList_p<T>::Get(T& data)
{
	for (int i = 0; i < m_Length; i++)
	{
		//cout << "compare" << m_Array[i]->GetId() << " and " << data->GetId() << endl;
		if (m_Array[i]->GetId() == data->GetId())
		{
			cout << "addr: " << &m_Array[i] << endl;
			data = m_Array[i];
			return 1;
		}
	}
	return 0;
}

template<typename T>
int SortedList_p<T>::Delete(T data)
{
	for (int i = 0; i < m_Length; i++)
	{
		if (m_Array[i] == data)
		{
			for (int j = i; j < m_Length - 1; j++)
			{
				m_Array[j] = m_Array[j + 1];
			}
			m_Length--;
			return 1;
		}
	}
	return 0;
}

template<typename T>
int SortedList_p<T>::Replace(const T data)
{
	for (int i = 0; i < m_Length; i++)
	{
		if (m_Array[i] == data)
		{
			m_Array[i] = data;
			return 1;
		}
	}
	return 0;
}

template<typename T>
int SortedList_p<T>::GetByBinarySearch(T data)
{
	int first = 0;
	int last = m_Length - 1;
	bool found = false;
	while (first <= last && !found)
	{
		int mid = (first + last) / 2;
		if (data < m_Array[mid]) {
			last = mid - 1;
		}
		else if (data > m_Array[mid]) {
			first = mid + 1;
		}
		else {
			data = m_Array[mid];
			found = true;
			return 1;
		}
	}
	return 0;
}
#endif // !_SLWP_H