#include "Application.h"
void Application::Run()
{
	while (1)
	{
		int m_Command = GetCommand();

		switch (m_Command)
		{
		case 1:		// �� ������ �Է� �޾� ����Ʈ�� �߰�					
			AddMusic();
			break;
		case 2:		// ���� ������ȣ�� �Է� �޾� ����Ʈ���� ����					
			DeleteMusic();
			break;
		case 3:		// �� ������ �Է� �޾Ƽ� ����Ʈ���� �ش� �� ������ ����			
			ReplaceMusic();
			break;
		case 4:		// �Էµ� ������ ����Ʈ���� ���� ã�Ƽ� ȭ�鿡 ���				
			RetrieveMusic();
			break;
		case 5:		// ����Ʈ�� ����� ��� ���� ȭ�鿡 ���
			DisplayAllMusic();
			break;
		case 6: 		// ����Ʈ�� �Էµ� ��� ���� ����
			MakeEmpty();
			break;
		case 7:		// load list data from a file.
			ReadDataFromFile();
			break;
		case 8:		// save list data into a file.
			WriteDataToFile();
			break;
		case 0:
			return;
		default:
			cout << "\tIllegal selection...\n";
			break;
		}
	}
}

int Application::GetCommand() {

}

void Application::AddMusic() {

}

void Application::DeleteMusic(){

}

void Application::DisplayAllMusic() {

}

void Application::MakeEmpty() {

}

void Application::ReadDataFromFile() {

}

void Application::ReplaceMusic() {

}

void Application::RetrieveMusic() {


}

void Application::WriteDataToFile() {

}
