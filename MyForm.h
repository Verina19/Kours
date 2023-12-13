#pragma once
#include <iostream>

#include <string>
#include <Windows.h> 
#include "Hash.h"
#include "MyForm2.h"
//#include "MyForm11.h"
#include <msclr\marshal_cppstd.h>
using namespace msclr::interop;

hashbase Salat; // хэш-таблица Салат
hashbase Hot; // хэш-таблица Салат
hashbase Cool; // хэш-таблица Салат
hashbase First; // хэш-таблица Первое
hashbase Second; // хэш-таблица Второе
hashbase Third; // хэш-таблица Третье
hashbase Cake; // хэш-таблица Выпечка
hashbase Also; // хэш-таблица Разное

char SalatF[20] = "Salat.txt";
char HotF[20] = "Hot.txt";
char CoolF[20] = "Cool.txt";
char FirstF[20] = "First.txt";
char SecondF[20] = "Second.txt";
char ThirdF[20] = "Third.txt";
char CakeF[20] = "Cake.txt";
char AlsoF[20] = "Alse.txt";

hashbase* Base = &First;
char* FileR = FirstF;
void Init() {// заполнение таблиц из файлов
Openfile(&Salat, SalatF);
Openfile(&Hot, HotF);
Openfile(&Cool, CoolF);
Openfile(&First, FirstF);
Openfile(&Second, SecondF);
Openfile(&Third, ThirdF);
Openfile(&Cake, CakeF);
Openfile(&Also, AlsoF);
}

namespace CulinaryBook {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form {
	public:
		//String^ Bludo() {
		//	return 	listBox1->SelectedItem->ToString();
		//}
		//String^ Recept() {
		//	return 	label1->Text;
		//}
		//String^ Img() {
		//	return 	pictureBox1->ImageLocation;
		//}



		MyForm(void) {
			InitializeComponent();
			Init();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm() {
			if (components) {
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ exit;
	protected:

	protected:
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::TreeView^ treeView1;
	private: System::Windows::Forms::ListBox^ listBox1;
	private: System::Windows::Forms::Button^ btnAdd;



	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ btnEdit;
	private: System::Windows::Forms::Button^ btnDelete;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;








	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void) {
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			System::Windows::Forms::TreeNode^ treeNode21 = (gcnew System::Windows::Forms::TreeNode(L"Первые блюда"));
			System::Windows::Forms::TreeNode^ treeNode22 = (gcnew System::Windows::Forms::TreeNode(L"Вторые блюда"));
			System::Windows::Forms::TreeNode^ treeNode23 = (gcnew System::Windows::Forms::TreeNode(L"Третьи блюда"));
			System::Windows::Forms::TreeNode^ treeNode24 = (gcnew System::Windows::Forms::TreeNode(L"салаты"));
			System::Windows::Forms::TreeNode^ treeNode25 = (gcnew System::Windows::Forms::TreeNode(L"горячие закуски"));
			System::Windows::Forms::TreeNode^ treeNode26 = (gcnew System::Windows::Forms::TreeNode(L"холодные закуски"));
			System::Windows::Forms::TreeNode^ treeNode27 = (gcnew System::Windows::Forms::TreeNode(L"Салаты", gcnew cli::array< System::Windows::Forms::TreeNode^  >(3) {
				treeNode24,
					treeNode25, treeNode26
			}));
			System::Windows::Forms::TreeNode^ treeNode28 = (gcnew System::Windows::Forms::TreeNode(L"Выпечка"));
			System::Windows::Forms::TreeNode^ treeNode29 = (gcnew System::Windows::Forms::TreeNode(L"Разное"));
			System::Windows::Forms::TreeNode^ treeNode30 = (gcnew System::Windows::Forms::TreeNode(L"Кулинарная книга", gcnew cli::array< System::Windows::Forms::TreeNode^  >(6) {
				treeNode21,
					treeNode22, treeNode23, treeNode27, treeNode28, treeNode29
			}));
			this->exit = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->treeView1 = (gcnew System::Windows::Forms::TreeView());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->btnAdd = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btnEdit = (gcnew System::Windows::Forms::Button());
			this->btnDelete = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// exit
			// 
			this->exit->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->exit->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->exit->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->exit->Font = (gcnew System::Drawing::Font(L"Arial Black", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->exit->ForeColor = System::Drawing::SystemColors::Window;
			this->exit->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"exit.Image")));
			this->exit->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->exit->Location = System::Drawing::Point(1258, 582);
			this->exit->Name = L"exit";
			this->exit->Size = System::Drawing::Size(118, 35);
			this->exit->TabIndex = 0;
			this->exit->Text = L"Выход";
			this->exit->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->exit->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
			this->exit->UseVisualStyleBackColor = false;
			this->exit->Click += gcnew System::EventHandler(this, &MyForm::exit_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->pictureBox1->ImageLocation = L"Img\\CulinareBook.jpg";
			this->pictureBox1->Location = System::Drawing::Point(1100, 66);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(276, 273);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			// 
			// treeView1
			// 
			this->treeView1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->treeView1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->treeView1->Font = (gcnew System::Drawing::Font(L"Arial Black", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->treeView1->ForeColor = System::Drawing::SystemColors::Menu;
			this->treeView1->Location = System::Drawing::Point(24, 66);
			this->treeView1->Name = L"treeView1";
			treeNode21->Name = L"First";
			treeNode21->Tag = L"101";
			treeNode21->Text = L"Первые блюда";
			treeNode22->Name = L"Second";
			treeNode22->Tag = L"201";
			treeNode22->Text = L"Вторые блюда";
			treeNode23->Name = L"Third";
			treeNode23->Tag = L"301";
			treeNode23->Text = L"Третьи блюда";
			treeNode24->Name = L"salat";
			treeNode24->Tag = L"4001";
			treeNode24->Text = L"салаты";
			treeNode25->Name = L"hot";
			treeNode25->Text = L"горячие закуски";
			treeNode25->ToolTipText = L"4002";
			treeNode26->Name = L"cool";
			treeNode26->Tag = L"4003";
			treeNode26->Text = L"холодные закуски";
			treeNode27->Name = L"Salat";
			treeNode27->Tag = L"401";
			treeNode27->Text = L"Салаты";
			treeNode28->Name = L"Cake";
			treeNode28->Tag = L"501";
			treeNode28->Text = L"Выпечка";
			treeNode29->Name = L"Alse";
			treeNode29->Tag = L"601";
			treeNode29->Text = L"Разное";
			treeNode30->Name = L"Узел0";
			treeNode30->Tag = L"1";
			treeNode30->Text = L"Кулинарная книга";
			this->treeView1->Nodes->AddRange(gcnew cli::array< System::Windows::Forms::TreeNode^  >(1) { treeNode30 });
			this->treeView1->Size = System::Drawing::Size(258, 273);
			this->treeView1->TabIndex = 2;
			this->treeView1->AfterSelect += gcnew System::Windows::Forms::TreeViewEventHandler(this, &MyForm::treeView1_AfterSelect);
			// 
			// listBox1
			// 
			this->listBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->listBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->listBox1->Font = (gcnew System::Drawing::Font(L"Arial Black", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->listBox1->ForeColor = System::Drawing::SystemColors::Menu;
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 18;
			this->listBox1->Items->AddRange(gcnew cli::array< System::Object^  >(1) { L" " });
			this->listBox1->Location = System::Drawing::Point(305, 66);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(228, 396);
			this->listBox1->TabIndex = 3;
			this->listBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::listBox1_SelectedIndexChanged);
			this->listBox1->DoubleClick += gcnew System::EventHandler(this, &MyForm::btnEdit_Click);
			// 
			// btnAdd
			// 
			this->btnAdd->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->btnAdd->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnAdd->Font = (gcnew System::Drawing::Font(L"Arial Black", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnAdd->ForeColor = System::Drawing::SystemColors::Menu;
			this->btnAdd->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnAdd.Image")));
			this->btnAdd->Location = System::Drawing::Point(365, 485);
			this->btnAdd->Name = L"btnAdd";
			this->btnAdd->Size = System::Drawing::Size(113, 30);
			this->btnAdd->TabIndex = 5;
			this->btnAdd->Text = L"Добавить";
			this->btnAdd->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
			this->btnAdd->UseVisualStyleBackColor = false;
			this->btnAdd->Click += gcnew System::EventHandler(this, &MyForm::btnAdd_Click);
			// 
			// label1
			// 
			this->label1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial Black", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->ForeColor = System::Drawing::SystemColors::Menu;
			this->label1->Location = System::Drawing::Point(560, 66);
			this->label1->MaximumSize = System::Drawing::Size(700, 500);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(517, 404);
			this->label1->TabIndex = 6;
			// 
			// btnEdit
			// 
			this->btnEdit->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->btnEdit->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnEdit->Font = (gcnew System::Drawing::Font(L"Arial Black", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnEdit->ForeColor = System::Drawing::SystemColors::Window;
			this->btnEdit->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnEdit.Image")));
			this->btnEdit->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnEdit->Location = System::Drawing::Point(365, 533);
			this->btnEdit->Name = L"btnEdit";
			this->btnEdit->Size = System::Drawing::Size(113, 34);
			this->btnEdit->TabIndex = 7;
			this->btnEdit->Text = L"Изменить";
			this->btnEdit->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->btnEdit->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
			this->btnEdit->UseVisualStyleBackColor = false;
			this->btnEdit->Click += gcnew System::EventHandler(this, &MyForm::btnEdit_Click);
			// 
			// btnDelete
			// 
			this->btnDelete->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->btnDelete->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnDelete->Font = (gcnew System::Drawing::Font(L"Arial Black", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnDelete->ForeColor = System::Drawing::SystemColors::Menu;
			this->btnDelete->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnDelete.Image")));
			this->btnDelete->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->btnDelete->Location = System::Drawing::Point(365, 584);
			this->btnDelete->Name = L"btnDelete";
			this->btnDelete->Size = System::Drawing::Size(113, 33);
			this->btnDelete->TabIndex = 8;
			this->btnDelete->Text = L"Удалить";
			this->btnDelete->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
			this->btnDelete->UseVisualStyleBackColor = false;
			this->btnDelete->Click += gcnew System::EventHandler(this, &MyForm::btnDelete_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->label2->Font = (gcnew System::Drawing::Font(L"Arial Black", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->ForeColor = System::Drawing::SystemColors::Menu;
			this->label2->Location = System::Drawing::Point(25, 40);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(134, 28);
			this->label2->TabIndex = 9;
			this->label2->Text = L"Категории:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->label3->Font = (gcnew System::Drawing::Font(L"Arial Black", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->ForeColor = System::Drawing::SystemColors::Menu;
			this->label3->Location = System::Drawing::Point(305, 39);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(95, 28);
			this->label3->TabIndex = 10;
			this->label3->Text = L"Блюда:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->label4->Font = (gcnew System::Drawing::Font(L"Arial Black", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->ForeColor = System::Drawing::SystemColors::Menu;
			this->label4->Location = System::Drawing::Point(560, 38);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(96, 28);
			this->label4->TabIndex = 11;
			this->label4->Text = L"Рецепт:";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1394, 641);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->btnDelete);
			this->Controls->Add(this->btnEdit);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->btnAdd);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->treeView1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->exit);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(1410, 680);
			this->MinimumSize = System::Drawing::Size(1410, 680);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Рецепт бар";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void exit_Click(System::Object^ sender, System::EventArgs^ e) {
	Application::Exit();
}
//**** выбор меню в дереве
	private: System::Void treeView1_AfterSelect(System::Object^ sender, System::Windows::Forms::TreeViewEventArgs^ e) {
		TreeNode^ node = treeView1->SelectedNode;
		String^ s = " ";
		if (node->Text == "Кулинарная книга" || node->Text == "") {
			listBox1->Items->Clear();
			label1->Text = "";
			pictureBox1->ImageLocation =  "Img\\CulinareBook.jpg";
			return;
		}
		else if (node->Text == "Салаты") {
			listBox1->Items->Clear();
			label1->Text = "";
			pictureBox1->ImageLocation = "Img\\Salates.jpg";
		}
		else if (node->Text == "Первые блюда") {
			Base = &First;
			FileR = FirstF;
			label1->Text = "";
			pictureBox1->ImageLocation = "Img\\First.jpg";
		}
		else if (node->Text == "Вторые блюда") {
			Base = &Second;
			FileR = SecondF;
			label1->Text = "";
			pictureBox1->ImageLocation = "Img\\Second.jpg";
		}
		else if (node->Text == "Третьи блюда") {
			Base = &Third;
			FileR = ThirdF;
			label1->Text = "";
			pictureBox1->ImageLocation = "Img\\Third.jpg";
		}
		else if (node->Text == "салаты") {
			Base = &Salat;
			FileR = SalatF;
			label1->Text = "";
			pictureBox1->ImageLocation = "Img\\Salates.jpg";
		}
		else if (node->Text == "горячие закуски") {
			Base = &Hot;
			FileR = HotF;
			label1->Text = "";
			pictureBox1->ImageLocation = "Img\\Hot.jpg";
		}
		else if (node->Text == "холодные закуски") {
			Base = &Cool;
			FileR = CoolF;
			label1->Text = "";
			pictureBox1->ImageLocation = "Img\\Cool.jpg";
		}
		else if (node->Text == "Выпечка") {
			Base = &Cake;
			FileR = CakeF;
			label1->Text = "";
			pictureBox1->ImageLocation = "Img\\Cake.jpg";
		}
		else if (node->Text == "Разное") {
			Base = &Also;
			FileR = AlsoF;
			label1->Text = "";
			pictureBox1->ImageLocation = "Img\\Also.jpg";
		}
		else return;
		//Openfile(Base, File);
		listBox1->Items->Clear();
		std::string s1 = "";
		for (int i = 0; i < TABLE_SIZE; i++) {
			s = gcnew System::String(Base->key1[i]);
			if (s != "") {
				listBox1->Items->Add(s);
			}
		}
	}
//*** выбор блюда в списке
	private: System::Void listBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		if (listBox1->SelectedItem == nullptr) return;
		String^ s = "";// listBox1->SelectedItem->ToString();
		std::string s1 = marshal_as<std::string>(listBox1->SelectedItem->ToString());
		char key[401];
		strcpy_s(key, 400, s1.c_str());
		int index = Find(Base, key);
		if (index < 0) return;
		s = gcnew System::String(Base->url_image[index]);
		pictureBox1->ImageLocation = s;
		s = gcnew System::String(Base->value[index]);
		label1->Text = s;
	}
//*** кнопка Добавить
private: System::Void btnAdd_Click(System::Object^ sender, System::EventArgs^ e) {
	TreeNode^ node = treeView1->SelectedNode;
	if (node == nullptr|| node->Text == "Кулинарная книга") {// обработка ошибки на не выбранное меню
		System::Windows::Forms::MessageBox::Show("Выберите раздел в меню.", "Внимание", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}

	MyForm2^ f2 = gcnew MyForm2(this);
	this->Hide();
	if (f2->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		char key[401];
		char element[1001];
		char url[401];
		String^ str = f2->Str1();
		if (str == "") { this->Show(); return; }
		listBox1->Items->Add(str);// добавляем блюдо в список
		std::string s1 = marshal_as<std::string>(str);
		strcpy_s(key, 400, s1.c_str());
		str = f2->Str2();
		label1->Text = str;// добавляем рецепт
		s1 = marshal_as<std::string>(str);
		strcpy_s(element, 1000, s1.c_str());
		str = f2->Str3();
		pictureBox1->ImageLocation = str;// добавляем картинку
		s1 = marshal_as<std::string>(str);
		strcpy_s(url, 400, s1.c_str());
		AddElement(Base, key, element, url);
		Savefile(Base, FileR);


	}
	this->Show();

}
//*** кнопка Изменить
private: System::Void btnEdit_Click(System::Object^ sender, System::EventArgs^ e) {
	TreeNode^ node = this->treeView1->SelectedNode;
	if (node == nullptr || node->Text == "Кулинарная книга") {// обработка ошибки на не выбранное меню
		System::Windows::Forms::MessageBox::Show("Выберите раздел в меню.", "Внимание", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}
	if (this->listBox1->SelectedIndex == -1) {
		System::Windows::Forms::MessageBox::Show("Выберите блюдо в меню.", "Внимание", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}
	char key[401];
	char element[1001];
	char url[401];
	String^ str = this->listBox1->SelectedItem->ToString();
	if (str == "") { return; }
	std::string s1 = marshal_as<std::string>(str);
	strcpy_s(key, 400, s1.c_str());

	MyForm2^ f2 = gcnew MyForm2(this);

	f2->bludo->Text = this->listBox1->SelectedItem->ToString();
	f2->receipt->Text = this->label1->Text;
	f2->pictureBox1->ImageLocation = this->pictureBox1->ImageLocation;

	this->Hide();
	if (f2->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		str = f2->Str1();
		if (str == "") { this->Show(); return; }
		RemoveElement(Base, key, FileR);
		this->listBox1->SelectedItem = str;
		std::string s1 = marshal_as<std::string>(str);
		strcpy_s(key, 400, s1.c_str());

		str = f2->Str2();
		this->label1->Text = str;
		s1 = marshal_as<std::string>(str);
		strcpy_s(element, 1000, s1.c_str());
		str = f2->Str3();
		this->pictureBox1->ImageLocation = str;// добавляем картинку
		s1 = marshal_as<std::string>(str);
		strcpy_s(url, 400, s1.c_str());
		AddElement(Base, key, element, url);
		Savefile(Base, FileR);
	}
	this->Show();


}
//*** кнопка Удалить
private: System::Void btnDelete_Click(System::Object^ sender, System::EventArgs^ e) {
	char key[401];
	TreeNode^ node = treeView1->SelectedNode;
	if (node == nullptr || node->Text == "Кулинарная книга") {// обработка ошибки на не выбранное меню
		System::Windows::Forms::MessageBox::Show("Выберите раздел в меню.", "Внимание", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}
	if (listBox1->SelectedIndex == -1) {
		System::Windows::Forms::MessageBox::Show("Выберите блюдо в меню.", "Внимание", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}
		String^ str = this->listBox1->SelectedItem->ToString();
		if (str == "") { return; }
		String^ s = "Вы действительно хотите удалить " + str;
		System::Windows::Forms::DialogResult result = System::Windows::Forms::MessageBox::Show(s, "Внимание", MessageBoxButtons::YesNo, MessageBoxIcon::Question);
		if (result == System::Windows::Forms::DialogResult::Cancel) { return; }
		std::string s1 = marshal_as<std::string>(str);
		strcpy_s(key, 400, s1.c_str());
		RemoveElement(Base, key, FileR);
		this->listBox1->Items->Remove(this->listBox1->SelectedItem); 
		if (this->listBox1->Items->Count == 0) {
			this->listBox1->SelectedIndex = -1;
		}
		label1->Text = "Рецепт";
		pictureBox1->ImageLocation = "CulinareBook.jpg";

}
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
}
	public: void Set(String^ text1, String^ text2) {
		//listBox1->Items = text1;
		label1->Text = text2;
	}
};
}
