#include "MyForm.h"
#include "MyForm11.h"


using namespace CulinaryBook; // �������� ������� 



//[STAThreadAttribute]
[STAThread]
//int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
int main(array<System::String^>^ args){
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MyForm11);
	if (!pas) return 0;// ������ �� ������

	Application::Run(gcnew MyForm);





	return 0;
}

