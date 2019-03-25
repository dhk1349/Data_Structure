#include "ItemType.h"

// Make list empty.
void ArrayList::MakeEmpty()
{
	m_Length = 0;
}


// Get a number of records in current list.
int ArrayList::GetLength()
{
	return m_Length;
}


// Check capacity of list is full.
bool ArrayList::IsFull()
{
	if(m_Length > size - 1)
		return true;
	else
		return false;
}


// add a new data into list.
int ArrayList::Add(ItemType inData)
{
	if (size == 0) {
		size += 5;
		m_Array = new ItemType[size];
	}
	if(!IsFull())
	{
		ItemType CurItem;
		ResetList();
		GetNextItem(CurItem);

		while(m_CurPointer<=m_Length) //ó������ ������
		{	
			if (CurItem.CompareByID(inData) == EQUAL)//���ٸ�
			{
				cout << "\t=====[ERROR]=====\n";
				cout << "\tThere is foler with same name!\n";
				return 0;
			}
			else if(CurItem.CompareByID(inData)==GREATER || m_CurPointer==m_Length)	//���� CurItem>inData�ϰ�� Ȥ�� �迭�� �������̶� �񱳴���� ���°��
			{
				for(int i=m_Length;i>m_CurPointer;i--)	//�ǵڿ��� ���� �ϳ��� �����.
					m_Array[i]=m_Array[i-1];	//�迭 �б�
				m_Array[m_CurPointer]=inData;	//�迭 ���� �� ���� �����Ϳ� ������ �ִ´�.
				m_Length++;	//���� ����
				break;
			}
			GetNextItem(CurItem);	//��������������
		}
	}
	else//�� �� ���
	{
		//�����Ҵ��� ũ�⸦ ������
		ItemType *temp;
		temp = new ItemType[size];
		for (int i = 0; i < size; i++) {
			temp[i] = m_Array[i];
		}
		delete[] m_Array;
		size += 5;
		m_Array = new ItemType[size];
		for (int i = 0; i < size-5; i++) {
			m_Array[i] = temp[i];
		}
		delete[] temp;


		//�� ������ �߰�
		ItemType CurItem;
		ResetList();
		GetNextItem(CurItem);

		while (m_CurPointer <= m_Length) //ó������ ������
		{
			if (CurItem.CompareByID(inData) == EQUAL)//���ٸ�
			{
				cout << "\t=====[ERROR]=====\n";
				cout << "\tThere is foler with same name!\n";
				return 0;
			}
			else if (CurItem.CompareByID(inData) == GREATER || m_CurPointer == m_Length)	//���� CurItem>inData�ϰ�� Ȥ�� �迭�� �������̶� �񱳴���� ���°��
			{
				for (int i = m_Length; i > m_CurPointer; i--)	//�ǵڿ��� ���� �ϳ��� �����.
					m_Array[i] = m_Array[i - 1];	//�迭 �б�
				m_Array[m_CurPointer] = inData;	//�迭 ���� �� ���� �����Ϳ� ������ �ִ´�.
				m_Length++;	//���� ����
				break;
			}
			GetNextItem(CurItem);	//��������������
		}
	}

	return 1;
}


// Initialize list iterator.
void ArrayList::ResetList()
{
	m_CurPointer = -1;
}


// move list iterator to the next item in list and get that item.
int ArrayList::GetNextItem(ItemType& data)
{
	m_CurPointer++;	// list pointer ����
	if(m_CurPointer == m_Length)	// end of list�̸� -1�� ����
		return -1;
	data = m_Array[m_CurPointer];	// ���� list pointer�� ���ڵ带 ����

	return m_CurPointer;
}

//id�� ��ġ�ϴ� item�� ã�Ƽ� ��ȯ��
int ArrayList::Get(ItemType& data)
{
	ItemType CurItem;
	
	ResetList();	//iterator �ʱ�ȭ
	GetNextItem(CurItem);	//ù������ ������
	while(m_CurPointer<m_Length)	//ó������ ������
	{
		switch(CurItem.CompareByID(data))	//�Է� �����۰� ���� �������� ��
		{
		case EQUAL:	//��ġ�ϸ�
			data=CurItem;	//data�� ���� �������� ��ȯ
			return 1;	//����(1)�� ����
			break;
		case GREATER:	//���� �������� id�� �� ũ��(���ĵ������Ƿ� �������� ã�°� ����)
			return 0;	//����(0)�� ����
			break;
		default:	//���� �������� id�� �� ������
			GetNextItem(CurItem);	//���� �������� �����´�.(��� Ž��)
			break;
		}
	}
	return 0; //���н�0
}

//id�� ��ġ�ϴ� item�� ã�Ƽ� ������
int ArrayList::Delete(ItemType data)
{
	if(Get(data))	//id�� ��ġ�ϴ� item�� �߰��Ѵٸ�(1)
	{
		for(int i=m_CurPointer;i<m_Length;i++)	//���� �����ͺ��� �Էµ� �迭 ������ �ݺ�
			m_Array[i]=m_Array[i+1];	//�迭 �ڿ��� ������ �ϳ��� ����
		m_Length--;	//������ ������ �ϳ� ����
		return 1;	//����(1)�� ����
	}
	return 0;	//id��ġ�ϴ� item�� ã�� ���Ѵٸ� ����(0)�� ����
}

//id�� ��ġ�ϴ� item�� ������ ��ü��Ŵ
int ArrayList::Replace(ItemType data)
{
	ItemType tmp(data);	//�Է¹��� item�� ���

	if(Get(data))	//��ġ�ϴ� �������� ã�� ���
	{
		m_Array[m_CurPointer]=tmp;	//�迭���� ���������Ͱ� ����Ű�� ���� ����ߴ� ���������� ��ü��Ŵ
		return 1;	//����(1)�� ����
	}
	return 0;	//id��ġ�ϴ� item�� ã�� ���Ѵٸ� ����(0)�� ����
}

//id�� ��ġ�ϴ� item�� ����Ž������ �˻��ؼ� ��ȯ�Ѵ�.
int ArrayList::GetBinarySearch( ItemType& data )
{
	if(m_Length==0)	//���� �迭�� ����ٸ�
		return 0;	//����(0)�� ����
	int currentPos=m_Length/2;	//�迭�� �߰����� ����
	while(1)
	{
		switch(m_Array[currentPos].CompareByID(data))
		{
		case EQUAL:	//���� �����۰� �Է� �������� id�� ��ġ�Ѵٸ�
			data=m_Array[currentPos];	//data�� �߰��� ���� ����
			return 1;	//����(1)�� ����
			break;
		case GREATER:	//���� �������� id�� �Է� �������� id���� ũ�ٸ�
			if(currentPos==0)	//ó�� �迭�� ������ �������
				return 0;	//����(0)�� ����
			currentPos/=2;	//�� ������ �ε����� ���ݷ� �̵�
			break;
		case LESS:	//���� �������� id�� �Է� �������� id���� �۴ٸ�
			if(currentPos==m_Length-1)	//������ �迭�� ������ ū���
				return 0;	//����(0)�� ����
			currentPos=(currentPos+m_Length)/2;	//�� ū�� �ε����� �������� �̵�
			break;
		}
	}
	return 0;	//ȣ��� �� ���� ����(WARNING ������)
}
