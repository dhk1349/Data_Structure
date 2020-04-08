#include "Application.h"
void Application::Run()
{
	while (1)
	{
		int m_Command = GetCommand();

		switch (m_Command)
		{
		case 1:		// 곡 정보를 입력 받아 리스트에 추가					
			AddMusic();
			break;
		case 2:		// 곡의 고유번호를 입력 받아 리스트에서 삭제					
			DeleteMusic();
			break;
		case 3:		// 곡 정보를 입력 받아서 리스트에서 해당 곡 정보를 갱신			
			ReplaceMusic();
			break;
		case 4:		// 입력된 정보로 리스트에서 곡을 찾아서 화면에 출력				
			RetrieveMusic();
			break;
		case 5:		// 리스트에 저장된 모든 곡을 화면에 출력
			DisplayAllMusic();
			break;
		case 6: 		// 리스트에 입력된 모든 곡을 삭제
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
