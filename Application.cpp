#include "Application.h"


// Program driver.
void Application::Run()
{
	while(1)
	{
		m_Command = GetCommand();

		switch(m_Command)
		{
		case 1:		// read a record and add to list.
			NewFolder();
			break;
		case 2:		//search by id.
			RetrieveFolderByName();
			break;
		case 3:	//search by binary search.
			DeleteFolder();
			break;
		case 4:		//search by name.
			DisplayProperty();
			break;
		case 5:		//delete
			ReadDataFromFile();
			break;
		case 6:		//replace
			WriteDataToFile();
			break;
		case 7:		// display all the records in list on screen.
			DisplayAllFolders();
			break;
		case 0:
			return;
		default:
			cout << "\tIllegal selection...\n";
			break;
		}
	}
}
int Application::DisplayAllFolders() {
	Folder.DisplayAllFolderName();
	return 1;
}


// Display command on screen and get a input from keyboard.
int Application::GetCommand()
{
	int command;
	cout << endl << endl;
	cout << "\t---ID -- Command ----- " << endl;
	cout << "\t   1 : New Folder" << endl;
	cout << "\t   2 : Retrieve Folders By Name" << endl;
	cout << "\t   3 : Delete Folder" << endl;
	cout << "\t   4 : Display Property" << endl;
	cout << "\t   5 : Read Data From File" << endl;
	cout << "\t   6 : Write Data To File" << endl;
	cout << "\t   7 : Display All Items" << endl;
	cout << "\t   0 : Quit" << endl; 

	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;

	return command;
}

int Application::NewFolder() 
{
	int result = Folder.AddFolder();
	return result;
}
int Application:: RetrieveFolderByName() 
{
	int result=Folder.RetrieveFoldersByName();
	return result;
}
//Delete����
int Application::DisplayProperty() 
{
	Folder.DisplayRecordOnScreen();
	return 1;
}


// Add new record into list.
int Application::AddItem()
{
	// �Է¹��� ���ڵ带 ����Ʈ�� add, ����Ʈ�� full�� ���� add���� �ʰ� 0�� ����
	if(m_List.IsFull())
	{
		cout << "List is full" << endl;
		return 0;
	}

	ItemType item;

	item.SetRecordFromKB();
	m_List.Add(item);

	// ���� list ���
	DisplayAllItem();

	return 1;
}

int Application::DeleteFolder() {
	int result=Folder.DeleteFolders();
	return result;
}


//id�� item�� ã�� ����Ѵ�.
int Application::SearchItemById()
{
	ItemType item;
	item.SetNameFromKB(); //id�Է¹޴´�.
	
	if(m_List.Get(item)) //0�� �ƴϸ�(ã����)
	{
		cout<<"<============I FOUND ITEM !==========>"<<endl;
		item.DisplayRecordOnScreen(); //�ش� item�� ����Ѵ�.
		cout<<"<====================================>"<<endl;
		return 1;	//����(1)�� ����
	}
	cout<<"<========I CAN'T FIND ITEM !==========>"<<endl;
	return 0;	//����(0)�� ����
}

//�̸��� �Է¹��� item���� ����Ʈ���� item�� ã�Ƽ� ����Ѵ�.
int Application::RetriveRecordByMemberName()
{
	ItemType item;
	item.SetNameFromKB(); //name�� �Է¹޴´�.

	if(SearchListByMemberName(item)) //0�� �ƴϸ�(ã����)
		return 1;	//����(1)�� ����
	return 0;	//����(0)�� ����
}

//�̸����� item�� ã�Ƽ� ����Ѵ�.
int Application::SearchListByMemberName( ItemType &inData )
{
	ItemType tmp;
	int result=0;

	m_List.ResetList();//iterator �ʱ�ȭ
	while(m_List.GetNextItem(tmp)!=-1) //����Ʈ�� ���������� �ݺ�
	{
		if(tmp.GetName().find(inData.GetName())!=-1) //���� �ش� ����Ʈ�� �̸��� inData�� �̸��� �����ϸ�
		{
			if(result==0) //ó�� ã�� �����
				cout<<"<============I FOUND ITEM !==========>"<<endl;
			tmp.DisplayRecordOnScreen();
			result=1;	//����(1)
		}
	}
	if(result)	//�߰��� ���
		cout<<"<====================================>"<<endl;
	else	//�߰� ���ϴ� ���
		cout<<"<========I CAN'T FIND ITEM !==========>"<<endl;
	return result;
}

//id�� item�� ã�Ƽ� �����Ѵ�.
int Application::DeleteItem()
{
	int pre = m_List.GetLength();//���� item������ �޾ƿ´�.
	ItemType item;
	item.SetNameFromKB();
	
	m_List.Delete(item);

	if(pre> m_List.GetLength()) //���� item�������� ���� item������ �������� ���ż���
	{
		cout<<"<========DELETE SUCCESS !===========>"<<endl;
		this->DisplayAllItem(); //��� item�� ����Ѵ�.
		return 1;
	}
	
	cout<<"<========DELETE FAIL !=======>"<<endl;
	this->DisplayAllItem();//��� item�� ����Ѵ�.
	return 0;
}

//�ش� id�� item�� �����Ѵ�.
int Application::ReplaceItem()
{
	ItemType item;
	item.SetRecordFromKB(); //Ű����κ��� ������ �Է¹���

	m_List.Replace(item); //�ش� item�� id�� ��ġ�ϴ� ���� ã�� �ٲ۴�.
	this->DisplayAllItem();
	return 0;
}


// Display all records in the list on screen.
void Application::DisplayAllItem()
{
	ItemType data;

	cout << "\n\tCurrent list" << endl;

	// list�� ��� �����͸� ȭ�鿡 ���
	m_List.ResetList();
	int length = m_List.GetLength();
	int curIndex = m_List.GetNextItem(data);
	while(curIndex < length && curIndex != -1)
	{
		data.DisplayRecordOnScreen();
		curIndex = m_List.GetNextItem(data);
	}
}


// Open a file by file descriptor as an input file.
int Application::OpenInFile(char *fileName)
{
	m_InFile.open(fileName);	// file open for reading.
	
	// ���� ���¿� �����ϸ� 1, �׷��� �ʴٸ� 0�� ����.
	if(!m_InFile)	return 0;
	else	return 1;
}


// Open a file by file descriptor as an output file.
int Application::OpenOutFile(char *fileName)
{
	m_OutFile.open(fileName);	// file open for writing.

	// ���� ���¿� �����ϸ� 1, �׷��� �ʴٸ� 0�� ����.
	if(!m_OutFile)	return 0;
	else	return 1;
}


// Open a file as a read mode, read all data on the file, and set list by the data.
int Application::ReadDataFromFile()
{
	int index = 0;
	ItemType data;	// �б�� �ӽ� ����
	
	char filename[FILENAMESIZE];
	cout << "\n\tEnter Input file Name : ";
	cin >> filename;

	// file open, open error�� �߻��ϸ� 0�� ����
	if(!OpenInFile(filename))
		return 0;

	// ������ ��� ������ �о� list�� �߰�
	while(!m_InFile.eof())
	{
		// array�� �л����� ������ ����ִ� structure ����
		data.ReadDataFromFile(m_InFile);
		m_List.Add(data);
	}

	m_InFile.close();	// file close

	// ���� list ���
	DisplayAllItem();

	return 1;
}


// Open a file as a write mode, and write all data into the file,
int Application::WriteDataToFile()
{
	ItemType data;	// ����� �ӽ� ����

	char filename[FILENAMESIZE];
	cout << "\n\tEnter Output file Name : ";
	cin >> filename;

	// file open, open error�� �߻��ϸ� 0�� ����
	if(!OpenOutFile(filename))
		return 0;

	// list �����͸� �ʱ�ȭ
	m_List.ResetList();

	// list�� ��� �����͸� ���Ͽ� ����
	int length = m_List.GetLength();
	int curIndex = m_List.GetNextItem(data);
	while(curIndex < length && curIndex != -1)
	{
		data.WriteDataToFile(m_OutFile);
		curIndex = m_List.GetNextItem(data);
	}

	m_OutFile.close();	// file close

	return 1;
}

int Application::SearchItemByBinarySearch()
{
	ItemType item;

	item.SetNameFromKB();	//id�� �Է¹޴´�
	if(m_List.GetBinarySearch(item))	//����Ž���� �����ߴٸ�
	{
		cout<<"<============I FOUND ITEM !==========>"<<endl;
		item.DisplayRecordOnScreen();
		cout<<"<====================================>"<<endl;
		return 1;	//����(1)�� ��ȯ
	}
	//�߰� ���ҽ�
	cout<<"<========I CAN'T FIND ITEM !==========>"<<endl;
	return 0;	//����(0)�� ��ȯ
	
}
