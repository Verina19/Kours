#pragma once
#include <fstream>
#include <msclr\marshal_cppstd.h>
using namespace msclr::interop;

#define TABLE_SIZE 200// TABLE_SIZE - ������ ���-�������
struct Pass {
	char login[TABLE_SIZE][51];
	char passw[TABLE_SIZE][51];
};
char FileName[] = { "pass.bin" };
Pass pass;
FILE* file3;
bool pas = false;
// ������� ������ � ����
void SavefileP() {
	if (!fopen_s(&file3, FileName, "w")) { // ������ ���� � ����
		for (int i = 0; i < TABLE_SIZE; i++) {
			if (strcmp(pass.login[i], "\0")) {// ���������� ������ ����������� ������ � ������� ����;��������
				fputs(pass.login[i], file3); // ������ ������ �����
				fputs(";", file3); // ��������� �����������
				fputs(pass.passw[i], file3); // ������ ������ ������
				fputs("\n", file3); // ��������� ����� ������
			}
		}
		fclose(file3);
	}
}

// ���-������� ��� ���������� ������� � ���-�������. 
// ��������� �������� ASCII-����� �������� ����� � ���������� ������� �� ������� �� ������ ���-�������
int hash1P(char* key) {
	int hash_value = 0;
	for (int i = 0; key[i] != '\0'; i++) {
		hash_value += (unsigned char)key[i];
	}
	return hash_value % TABLE_SIZE;
}

// ���-������� ��� ���������� ������� � ���-�������. 
// ��������� �������� ASCII-����� �������� ����� � ���������� �������� ���, � ���������� ������� �� ������� �� ������ ���-�������
int hash2P(int hash_value, char* key) {
	for (int i = 0; key[i] != '\0'; i++) {
		hash_value += (unsigned char)key[i];
	}
	return hash_value % (TABLE_SIZE - 1) + 1;
}

// ������� �������� ������� �������� � ����
int FindP(char* key) {
	int index = hash1P(key);// ��������� ������ (���)
	if (!strcmp(pass.login[index], key)) {// ��������� ��� ������� ����� ����������� ������
		return index;
	}
	else {
		int count = 0;// ���� ������ ���� ������ ���������� �� ������ �����������
		while (1) {
			index = hash2P(index, key);
			if (!strcmp(pass.login[index], key)) {// ��������� ��� ������� ����� ����������� ������
				return index;
			}
			count++;
			if (count > TABLE_SIZE) break;
		}
		return -1;
	}
}
// ������� ��������� ����� ������ � ���-�������
int AddP(char* key, char* element) {
	if (FindP(key) >= 0) {
		return 1;
	}
	int index = hash1P(key); // ��������� ������ (���)
	if (!strcmp(pass.login[index], "\0")) { // ��������� ��� ������ ������
		strcpy_s(pass.login[index], 50, key); // �������� ����
		strcpy_s(pass.passw[index], 50, element); // �������� ������
		return 0;
	}
	else {// ���� ������ ���� ������ ���������� �� ������ �����������
		while (1) {
			index = hash2P(index, key);
			if (!strcmp(pass.login[index], "\0")) { // ��������� ��� ������ ������
				strcpy_s(pass.login[index], 50, key); // �������� ����
				strcpy_s(pass.passw[index], 50, element); // �������� ������
				return 0;
			}
		};
	}
	return 1; // ������, ��� ������
}

// ������� ������� ������ �� �������
void RemoveP(char* key, char* filename) {
	int index = FindP(key); // ���� ����� ����
	if (index >= 0) {// ���� ����� �������
		strcpy_s(pass.login[index], 50, "\0"); // ������� ������ �����
		strcpy_s(pass.passw[index], 50, "\0"); // ������� ������ ������
		SavefileP();
	}
	//else { printf("����� ������� �����������\n"); }// �� �����
}


void OpenfileP() {
	char element[50];
	char key[50];
	if (!fopen_s(&file3, FileName, "r")) { // ������ ���� � ����
		char f[11002];
		int i, j, k;
		while ((fgets(f, 10000, file3)) != NULL) {
			for (i = 0; i < strlen(f); i++) {
				if ((unsigned char)f[i] == ';') { key[i] = '\0';  break; }
				else key[i] = f[i];
			}
			i++;
			for (j = 0; j < strlen(f) - i; j++) {
				if ((unsigned char)f[j + i] == ';') { element[j] = '\0'; break; }
				else element[j] = f[i + j];
			}
			j++;
			if (element[strlen(f) - i - 1] == '\n') {
				element[strlen(f) - i - 1] = '\0';
			}
			else element[strlen(f) - i] = '\0';
			AddP(key, element);
		}
		fclose(file3);
	}
	else printf("������ �������� �����. ��������� ������������ ����� ����� �����\n");
}


namespace CulinaryBook {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/// <summary>
	/// ������ ��� MyForm1
	/// </summary>
	//public value class pp {
	//	String^ log[200];
	//	String^ pas[200];
	//};
	public ref class MyForm11 : public System::Windows::Forms::Form
	{
	public:

		MyForm11(void)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~MyForm11()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ login;

	protected:


	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::TextBox^ password;


	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm11::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->login = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->password = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::WhiteSmoke;
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial Black", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(54, 35);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(55, 19);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Login:";
			// 
			// login
			// 
			this->login->Font = (gcnew System::Drawing::Font(L"Tahoma", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->login->Location = System::Drawing::Point(115, 33);
			this->login->MaxLength = 20;
			this->login->Name = L"login";
			this->login->Size = System::Drawing::Size(161, 24);
			this->login->TabIndex = 2;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::WhiteSmoke;
			this->label2->Font = (gcnew System::Drawing::Font(L"Arial Black", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(21, 101);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(88, 19);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Password:";
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::WhiteSmoke;
			this->button1->Font = (gcnew System::Drawing::Font(L"Arial Black", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(50, 144);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(101, 38);
			this->button1->TabIndex = 4;
			this->button1->Text = L"�����";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm11::button1_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::WhiteSmoke;
			this->button2->Font = (gcnew System::Drawing::Font(L"Arial Black", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(230, 144);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(101, 38);
			this->button2->TabIndex = 5;
			this->button2->Text = L"�����������";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm11::button2_Click);
			// 
			// password
			// 
			this->password->Font = (gcnew System::Drawing::Font(L"Tahoma", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->password->Location = System::Drawing::Point(115, 99);
			this->password->MaxLength = 10;
			this->password->Name = L"password";
			this->password->PasswordChar = '*';
			this->password->Size = System::Drawing::Size(161, 24);
			this->password->TabIndex = 3;
			// 
			// MyForm11
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(384, 211);
			this->Controls->Add(this->password);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->login);
			this->Controls->Add(this->label1);
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(400, 250);
			this->MinimumSize = System::Drawing::Size(400, 250);
			this->Name = L"MyForm11";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"�����������";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
//->ToString()
		std::string s1 = marshal_as<std::string>(this->login->Text);
		if (s1 == "") {
			System::Windows::Forms::MessageBox::Show("������� �����.", "��������", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		OpenfileP();
		char key[50];
		char element[50];
		strcpy_s(key, 50, s1.c_str());
		int index = FindP(key);
		if (index >= 0) {
			System::Windows::Forms::MessageBox::Show("����� ������������ ��� ����.", "��������", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		s1 = marshal_as<std::string>(this->password->Text);
		strcpy_s(element, 50, s1.c_str());
		AddP(key, element);
		SavefileP();
		System::Windows::Forms::MessageBox::Show("�� ���������������� � �������, ������ �������������.", "��������", MessageBoxButtons::OK, MessageBoxIcon::Information);
		this->login->Text = "";
		this->password->Text = "";
		//try {
		//	FileStream^ fs = gcnew FileStream(fileName, FileMode::Open);
		//	BinaryReader^ br = gcnew BinaryReader(fs);
		//	Console::WriteLine("contents of {0}:", fileName);
		//	while (br->BaseStream->Position < br->BaseStream->Length)
		//		Console::WriteLine(br->ReadInt32().ToString());
		//	fs->Close();
		//}
		//catch (Exception^ e) {
		//	if (dynamic_cast<FileNotFoundException^>(e))
		//		System::Windows::Forms::MessageBox::Show("File not found.", "��������", MessageBoxButtons::OK, MessageBoxIcon::Error);
		//	else
		//		System::Windows::Forms::MessageBox::Show("������ �������� �����", "��������", MessageBoxButtons::OK, MessageBoxIcon::Error);
		//}
	}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	std::string s1 = marshal_as<std::string>(this->login->Text);
	if (s1 == "") {
		System::Windows::Forms::MessageBox::Show("������� �����.", "��������", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}
	OpenfileP();
	char key[50];
	char element[50];
	strcpy_s(key, 50, s1.c_str());
	int index = FindP(key);
	if (index < 0) {
		System::Windows::Forms::MessageBox::Show("����� ������������ �� ������.", "��������", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}
	s1 = marshal_as<std::string>(this->password->Text);
	strcpy_s(element, 50, s1.c_str());
	if (strcmp(pass.passw[index], element)) {// ��������� ��� ������� ����� ����������� ������
		System::Windows::Forms::MessageBox::Show("�������� ������.", "��������", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return ;
	}
	pas = true;
	//Application::Exit();
	Close();



}
};
}
