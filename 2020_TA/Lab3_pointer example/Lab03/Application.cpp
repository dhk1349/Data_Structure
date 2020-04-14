#include "pch.h"
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
		case 4:	//search by binary search.
			SearchByID_BinaryS();
			break;
		case 5:		// display all the records in list on screen.
			DisplayAllItem();
			break;
		case 6:		// make empty list.
			MasterList.MakeEmpty();
			break;
		case 7:		// load list data from a file.
			ReadDataFromFile();
			break;
		case 8:		// save list data into a file.
			WriteDataToFile();
			break;
		case 9:
			AddtItem();
			break;
		case 10:
			DequeueFromtItemList();
			break;
		case 11:
			PrinttItemList();
			break;
		case 12:		// save list data into a file.
			AddPhoto();
			break;
		case 13:
			DeletePhoto();
			break;
		case 14:
			DisplayAllPhoto();
			break;
		case 15:
			DisplayAllsItem();
			break;
		case 16:
			DisplayAllDetailsItem();
			break;
		case 17:
			Reorganizetlist();
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
	cout << "\t--num--- Command ----- " << endl;
	cout << "\t-------MasterList----- " << endl;
	cout << "\t   1 : Add item" << endl;
	cout << "\t   2 : Delete item" << endl;
	cout << "\t   3 : Replace item" << endl;
	cout << "\t   4 : Search item by Binary Search" << endl;
	cout << "\t   5 : Print all on screen" << endl;
	cout << "\t   6 : Make empty list" << endl;
	cout << "\t   7 : Get from file" << endl;
	cout << "\t   8 : Put to file " << endl;
	cout << "\t-------TempList------- " << endl;
	cout << "\t   9 : AddtItem" << endl;
	cout << "\t   10 : DequeueFromtItemList" << endl;
	cout << "\t   11 : PrinttItemList" << endl;
	cout << "\t-------ContainerList-- " << endl;
	cout << "\t   12 : AddPhoto" << endl;
	cout << "\t   13 : DeletePhoto" << endl;
	cout << "\t   14 : DisplayAllPhoto" << endl;
	cout << "\t   15 : DisplayAllsItem" << endl;
	cout << "\t   16 : DisplayAllDetailsItem" << endl;
	cout << "\t---------------------- " << endl;
	cout << "\t   17 : Temp list �����ϱ�" << endl;
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

	ItemType* item;
	item = new ItemType;

	item->SetRecordFromKB();
	MasterList.Add(item);

	//dhk1349
	//Checking whether to put item in the Container or templist
	if (item->GetContainerID() == -1) {
		AddtItem(item);
	}
	else {
		ContainerType tmpContainer;
		tmpContainer.SetId(item->GetContainerID());
		SimpleItemType tmpsItem=item->GetSimpleData();
		//tmpsItem.SetId(item->GetId());
		//tmpsItem.SetName(item->GetName());

		if (ContainerList.Get(tmpContainer) == 1) { //Container �����Ҷ�
			tmpContainer.AddsItem(tmpsItem);
			ContainerList.Replace(tmpContainer);
		}
		else { //Container �������� ������
			tmpContainer.AddsItem(tmpsItem);
			ContainerList.Add(tmpContainer);
		}
	}
	return 1;
}

int Application::AddItem(ItemType* item)
{
	//dhk1349
	//�� �κ��� titemlist���� dequeue�� item�� Container�� �ִ� �Լ��̱� ������ MasterList�ʹ� ������ ���� �Լ��̴�. 
	//MasterList���� �̹� Item�� �����Ѵ�. 

	// �Է¹��� ���ڵ带 ����Ʈ�� add, ����Ʈ�� full�� ���� add���� �ʰ� 0�� ����
	/*
	if (MasterList.IsFull())
	{
		cout << "List is full" << endl;
		return 0;
	}
	
	MasterList.Add(item);
	*/

	//dhk1349
	//check whether to put item into container or templist.
	if (item->GetContainerID()==-1) {
		AddtItem(item);
	}
	else {
		ContainerType tmpContainer;
		tmpContainer.SetId(item->GetContainerID());
		SimpleItemType tmpsItem=item->GetSimpleData();
		//tmpsItem.SetId(item->GetId());
		//tmpsItem.SetName(item->GetName());

		if (ContainerList.Get(tmpContainer) == 1) { //Container �����Ҷ�
			tmpContainer.AddsItem(tmpsItem);
			ContainerList.Replace(tmpContainer);
		}
		else { //Container �������� ������
			tmpContainer.AddsItem(tmpsItem);
			ContainerList.Add(tmpContainer);
		}
	}
	return 1;
}

void Application::DisplayAllItem()
{
	ItemType* data;
	data = new ItemType;

	cout << "\n\tCurrent list" << endl;

	// list�� ��� �����͸� ȭ�鿡 ���
	MasterList.ResetList();
	int length = MasterList.GetLength();
	int curIndex = MasterList.GetNextItem(data);
	while (curIndex < length && curIndex != -1)
	{
		cout << data;
		curIndex = MasterList.GetNextItem(data);
	}
}

int Application::OpenInFile(char * fileName)
{
	m_InFile.open(fileName);	// file open for reading.

	// ���� ���¿� �����ϸ� 1, �׷��� �ʴٸ� 0�� ����.
	if (!m_InFile)	return 0;
	else	return 1;
}

int Application::OpenOutFile(char * fileName)
{
	m_OutFile.open(fileName);	// file open for writing.

	// ���� ���¿� �����ϸ� 1, �׷��� �ʴٸ� 0�� ����.
	if (!m_OutFile)	return 0;
	else	return 1;
}

int Application::ReadDataFromFile()
{
	int index = 0;
	ItemType* data;	// �б�� �ӽ� ����
	data = new ItemType;

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
		data->ReadDataFromFile(m_InFile);
		MasterList.Add(data);
	}

	m_InFile.close();	// file close

	// ���� list ���
	//DisplayAllItem();

	return 1;
}

int Application::WriteDataToFile()
{
	ItemType* data;	// ����� �ӽ� ����
	data = new ItemType;

	char filename[FILENAMESIZE];
	cout << "\n\tEnter Output file Name : ";
	cin >> filename;

	// file open, open error�� �߻��ϸ� 0�� ����
	if (!OpenOutFile(filename))
		return 0;

	// list �����͸� �ʱ�ȭ
	MasterList.ResetList();

	// list�� ��� �����͸� ���Ͽ� ����
	int length = MasterList.GetLength();
	int curIndex = MasterList.GetNextItem(data);
	while (curIndex < length && curIndex != -1)
	{
		data->WriteDataToFile(m_OutFile);
		curIndex = MasterList.GetNextItem(data);
	}

	m_OutFile.close();	// file close

	return 1;
}

int Application::SearchById_SequenS()
{
	ItemType* item;
	item = new ItemType;

	item->SetIdFromKB(); //id�Է¹޴´�.

	if (MasterList.Get(item)) //0�� �ƴϸ�(ã����)
	{
		cout << "<============ Item FOUND !==========>" << endl;
		cout << item;
		cout << "<====================================>" << endl;
		return 1;	//����(1)�� ����
	}
	cout << "<======== ITEM Not Found!==========>" << endl;
	return 0;	//����(0)�� ����
}

int Application::DeleteItem()
{
	int pre = MasterList.GetLength();//���� item������ �޾ƿ´�.
	ItemType* item;
	item = new ItemType;
	item->SetIdFromKB();

	MasterList.Delete(item);

	//Container ����ȭ
	ContainerType tmpContainer;
	tmpContainer.SetId(item->GetContainerID());
	SimpleItemType tmpsItem;
	tmpsItem.SetId(item->GetId());
	ContainerList.Get(tmpContainer);
	tmpContainer.DeletesItem(tmpsItem);
	ContainerList.Replace(tmpContainer);
	
	if (pre > MasterList.GetLength()) //���� item�������� ���� item������ �������� ���ż���
	{
		cout << "<========DELETE SUCCESS !===========>" << endl;
		return 1;
	}

	cout << "<========DELETE FAIL !=======>" << endl;
	return 0;
}

int Application::ReplaceItem()
{
	ItemType* item;
	item = new ItemType;
	item->SetRecordFromKB(); //Ű����κ��� ������ �Է¹���

	ItemType* origin;
	origin = new ItemType;
	origin->SetId(item->GetId());
	MasterList.Get(origin); //�ش� item�� id�� ��ġ�ϴ� ���� �����´�. ��������� �񱳸� ����
	MasterList.Replace(item); //�ش� item�� id�� ��ġ�ϴ� ���� ã�� �ٲ۴�.

	//Container ����ȭ
	ContainerType tmpContainer;
	SimpleItemType tmpsItem;

	//���� ���� ����
	tmpContainer.SetId(origin->GetContainerID());
	tmpsItem.SetId(origin->GetId());
	ContainerList.Get(tmpContainer);
	tmpContainer.DeletesItem(tmpsItem);
	ContainerList.Replace(tmpContainer);

	//���� �� ���� �߰�
	tmpContainer.SetId(item->GetContainerID());
	tmpsItem.SetId(item->GetId());
	tmpsItem.SetName(item->GetName());
	if (ContainerList.Get(tmpContainer) == 1) { //Container �����Ҷ�
		tmpContainer.AddsItem(tmpsItem);
		ContainerList.Replace(tmpContainer);
	}
	else { //Container �������� ������
		tmpContainer.AddsItem(tmpsItem);
		ContainerList.Add(tmpContainer);
	}

	return 0;
}

int Application::SearchByID_BinaryS()
{
	ItemType* item;
	item = new ItemType;
	item->SetIdFromKB();	//id�� �Է¹޴´�
	if (MasterList.GetByBinarySearch(item))	//����Ž���� �����ߴٸ�
	{
		cout << "<============I FOUND ITEM !==========>" << endl;
		cout << item;
		cout << "<====================================>" << endl;
		return 1;	//����(1)�� ��ȯ
	}
	//�߰� ���ҽ�
	cout << "<========I CAN'T FIND ITEM !==========>" << endl;
	return 0;	//����(0)�� ��ȯ
}

void Application::AddtItem()
{
	ItemType* tmpItem;
	tmpItem = new ItemType;

	tmpItem->SetIdFromKB();
	tmpItem->SetKindFromKB();
	tmpItem->SetDateFromKB();
	tmpItem->SetNameFromKB();
	tmpItem->SetNumFromKB();
	TempList.AddtItem(tmpItem);
}

//dhk1349
void Application::AddtItem(ItemType* item)
{
	TempList.AddtItem(item);
}

void Application::DequeueFromtItemList()
{
	ItemType* tmpItem;
	tmpItem = new ItemType;

	TempList.DequeueFromtItemList(tmpItem);
	tmpItem->SetContainerIDFromKB();
	AddItem(tmpItem);
}

void Application::PrinttItemList()
{
	TempList.PrinttItemList();
}

void Application::AddPhoto()
{
	ContainerType tmpContainer;
	tmpContainer.SetIdFromKB();
	
	string photo;
	cout << "photo : ";
	cin >> photo;

	ContainerList.Get(tmpContainer);
	tmpContainer.AddPhoto(photo);

	ContainerList.Replace(tmpContainer);
}

void Application::DeletePhoto()
{
	ContainerType tmpContainer;
	tmpContainer.SetIdFromKB();

	string photo;
	cout << "photo : ";
	cin >> photo;

	ContainerList.Get(tmpContainer);
	tmpContainer.DeletePhoto(photo);

	ContainerList.Replace(tmpContainer);
}

void Application::DisplayAllPhoto()
{
	ContainerType tmpContainer;
	tmpContainer.SetIdFromKB();

	ContainerList.Get(tmpContainer);

	tmpContainer.DisplayAllPhoto();
}

void Application::DisplayAllsItem()
{
	ContainerType tmpContainer;
	tmpContainer.SetIdFromKB();

	ContainerList.Get(tmpContainer);

	tmpContainer.DisplayAllsItem();
}

void Application::DisplayAllDetailsItem()
{
	ContainerType tmpContainer;
	tmpContainer.SetIdFromKB();

	ContainerList.Get(tmpContainer);

	tmpContainer.DisplayAllDetailsItem(MasterList);
}

void Application::Reorganizetlist() {
	//temp list�� dequeue�ؼ� ContainerId �־��ֱ�.
	
}