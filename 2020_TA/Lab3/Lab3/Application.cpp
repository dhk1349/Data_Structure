#include "Application.h"


Application::Application()
{
	m_Command = 0;
}


Application::~Application()
{
}

void Application::Run()
{
	while (1)
	{
		GetCommand();

		switch (m_Command)
		{
		case 1:		// read a record and add to list.
			AddItem();
			break;
		case 2:		//delete
			DeleteItem();
			break;
		case 3:		//replace
			ReplaceItem();
			break;
		case 4:		//search by id.
			SearchById_SequenS();
			break;
		case 5:	//search by binary search.
			SearchByID_BinaryS();
			break;
		case 6:		//search by name.
			SearchByName();
			break;
		case 7:		// display all the records in list on screen.
			DisplayAllItem();
			break;
		case 8:		// make empty list.
			m_MusicList.MakeEmpty();
			break;
		case 9:		// load list data from a file.
			ReadDataFromFile();
			break;
		case 10:		// save list data into a file.
			WriteDataToFile();
			break;
		case 11:
			AddPlayItem();
			break;
		case 12:
			DeletePlayItem();
			break;
		case 13:
			PrintAllPlayItem();
			break;
		case 0:
			return;
		default:
			cout << "\tIllegal selection...\n";
			break;
		}
	}
}

void Application::GetCommand()
{
	cout << endl << endl;
	cout << "\t---ID -- Command ----- " << endl;
	cout << "\t   1 : Add item" << endl;
	cout << "\t   2 : Delete item" << endl;
	cout << "\t   3 : Replace item" << endl;
	cout << "\t   4 : Search item by ID" << endl;
	cout << "\t   5 : Search item by Binary Search" << endl;
	cout << "\t   6 : Search item by name" << endl;
	cout << "\t   7 : Print all on screen" << endl;
	cout << "\t   8 : Make empty list" << endl;
	cout << "\t   9 : Get from file" << endl;
	cout << "\t   10 : Put to file " << endl;
	cout << "\t   11 : Add play item" << endl;
	cout << "\t   12 : Delete play item" << endl;
	cout << "\t   13 : Print play item on screen" << endl;
	cout << "\t   0 : Quit" << endl;

	cout << endl << "\t Choose a Command--> ";
	cin >> m_Command;
	cout << endl;
}

int Application::AddItem()
{
	// �Է¹��� ���ڵ带 ����Ʈ�� add, ����Ʈ�� full�� ���� add���� �ʰ� 0�� ����
	if (MasterList.IsFull())
	{
		cout << "List is full" << endl;
		return 0;
	}

	ItemType item;
	item.SetRecordFromKB();
	SimpleItemType s_item(item.GetData());
	MasterList.Add(item);
	

	return 1;
}

void Application::DisplayAllItem()
{
	ItemType data;

	cout << "\n\tCurrent list" << endl;

	// list�� ��� �����͸� ȭ�鿡 ���
	m_MusicList.ResetList();
	int length = m_MusicList.GetLength();
	int curIndex = m_MusicList.GetNextItem(data);
	while (curIndex < length && curIndex != -1)
	{
		data.DisplayRecordOnScreen();
		curIndex = m_MusicList.GetNextItem(data);
	}
}

int Application::OpenInFile(char* fileName)
{
	m_InFile.open(fileName);	// file open for reading.

	// ���� ���¿� �����ϸ� 1, �׷��� �ʴٸ� 0�� ����.
	if (!m_InFile)	return 0;
	else	return 1;
}

int Application::OpenOutFile(char* fileName)
{
	m_OutFile.open(fileName);	// file open for writing.

	// ���� ���¿� �����ϸ� 1, �׷��� �ʴٸ� 0�� ����.
	if (!m_OutFile)	return 0;
	else	return 1;
}

int Application::ReadDataFromFile()
{
	int index = 0;
	ItemType data;	// �б�� �ӽ� ����

	char filename[FILENAMESIZE];
	cout << "\n\tEnter Input file Name : ";
	cin >> filename;

	// file open, open error�� �߻��ϸ� 0�� ����
	if (!OpenInFile(filename))
		return 0;

	// ������ ��� ������ �о� list�� �߰�
	while (!m_InFile.eof())
	{
		// array�� �л����� ������ ����ִ� structure ����
		data.ReadDataFromFile(m_InFile);
		m_MusicList.Add(data);
	}

	m_InFile.close();	// file close

	// ���� list ���
	//DisplayAllItem();

	return 1;
}

int Application::WriteDataToFile()
{
	ItemType data;	// ����� �ӽ� ����

	char filename[FILENAMESIZE];
	cout << "\n\tEnter Output file Name : ";
	cin >> filename;

	// file open, open error�� �߻��ϸ� 0�� ����
	if (!OpenOutFile(filename))
		return 0;

	// list �����͸� �ʱ�ȭ
	m_MusicList.ResetList();

	// list�� ��� �����͸� ���Ͽ� ����
	int length = m_MusicList.GetLength();
	int curIndex = m_MusicList.GetNextItem(data);
	while (curIndex < length && curIndex != -1)
	{
		data.WriteDataToFile(m_OutFile);
		curIndex = m_MusicList.GetNextItem(data);
	}

	m_OutFile.close();	// file close

	return 1;
}

int Application::SearchById_SequenS()
{
	ItemType item;
	item.SetIdFromKB(); //id�Է¹޴´�.

	if (m_MusicList.Get(item)) //0�� �ƴϸ�(ã����)
	{
		cout << "<============ Item FOUND !==========>" << endl;
		item.DisplayRecordOnScreen(); //�ش� item�� ����Ѵ�.
		cout << "<====================================>" << endl;
		return 1;	//����(1)�� ����
	}
	cout << "<======== ITEM Not Found!==========>" << endl;
	return 0;	//����(0)�� ����
}

int Application::SearchByName()
{
	ItemType item;
	item.SetNameFromKB(); //name�� �Է¹޴´�.

	if (SearchAllItmeByName(item)) //0�� �ƴϸ�(ã����)
		return 1;	//����(1)�� ����
	return 0;	//����(0)�� ����
}

int Application::SearchAllItmeByName(ItemType& inData)
{
	ItemType tmp;
	int result = 0;

	m_MusicList.ResetList();//iterator �ʱ�ȭ
	while (m_MusicList.GetNextItem(tmp) != -1) //����Ʈ�� ���������� �ݺ�
	{
		if (tmp.GetName().find(inData.GetName()) != -1) //���� �ش� ����Ʈ�� �̸��� inData�� �̸��� �����ϸ�
		{
			if (result == 0) //ó�� ã�� �����
				cout << "<============I FOUND ITEM !==========>" << endl;
			tmp.DisplayRecordOnScreen();
			result = 1;	//����(1)
		}
	}
	if (result)	//�߰��� ���
		cout << "<====================================>" << endl;
	else	//�߰� ���ϴ� ���
		cout << "<========I CAN'T FIND ITEM !==========>" << endl;
	return result;
}

int Application::DeleteItem()
{
	int pre = m_MusicList.GetLength();//���� item������ �޾ƿ´�.
	ItemType item;
	item.SetIdFromKB();

	m_MusicList.Delete(item);

	if (pre > m_MusicList.GetLength()) //���� item�������� ���� item������ �������� ���ż���
	{
		cout << "<========DELETE SUCCESS !===========>" << endl;
		return 1;
	}

	cout << "<========DELETE FAIL !=======>" << endl;
	return 0;
}

int Application::ReplaceItem()
{
	ItemType item;
	item.SetRecordFromKB(); //Ű����κ��� ������ �Է¹���

	m_MusicList.Replace(item); //�ش� item�� id�� ��ġ�ϴ� ���� ã�� �ٲ۴�.
	//this->DisplayAllItem();
	return 0;
}

int Application::SearchByID_BinaryS()
{
	ItemType item;

	item.SetIdFromKB();	//id�� �Է¹޴´�
	if (m_MusicList.GetByBinarySearch(item))	//����Ž���� �����ߴٸ�
	{
		cout << "<============I FOUND ITEM !==========>" << endl;
		item.DisplayRecordOnScreen();
		cout << "<====================================>" << endl;
		return 1;	//����(1)�� ��ȯ
	}
	//�߰� ���ҽ�
	cout << "<========I CAN'T FIND ITEM !==========>" << endl;
	return 0;	//����(0)�� ��ȯ
}

void Application::AddPlayItem()
{
	PlayItemType item;
	ItemType tmpItem;

	item.SetRecordFromKB();
	tmpItem.SetId(item.GetId());
	if (!m_MusicList.Get(tmpItem)) {
		cout << "<============I NOT FOUND ITEM !==========>" << endl;
		return;
	}
	m_PlayList.EnQueue(item);
	cout << item;
	return;
}

void Application::DeletePlayItem()
{
	PlayItemType item;
	m_PlayList.DeQueue(item);
	return;
}

void Application::PrintAllPlayItem()
{
	m_PlayList.PlayInsertOrder();
}
