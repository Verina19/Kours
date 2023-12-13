#pragma once
//#include "MyForm.h"

namespace CulinaryBook {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm2
	/// </summary>
	public ref class MyForm2 : public System::Windows::Forms::Form
	{
	private: System::Windows::Forms::Form^ otherform;
	public:
		String^ Str1() {
			return bludo->Text;
		}
		String^ Str2() {
			return receipt->Text;
		}
		String^ Str3() {
			return pictureBox1->ImageLocation;
		}
		MyForm2(System::Windows::Forms::Form^ o)
		{
			otherform = o;
			InitializeComponent();

			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm2()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::RichTextBox^ receipt;
	protected:
	public: System::Windows::Forms::RichTextBox^ bludo;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ btnSave;

	private: System::Windows::Forms::Button^ btnCancel;

	public: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;


	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm2::typeid));
			this->receipt = (gcnew System::Windows::Forms::RichTextBox());
			this->bludo = (gcnew System::Windows::Forms::RichTextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->btnSave = (gcnew System::Windows::Forms::Button());
			this->btnCancel = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// receipt
			// 
			this->receipt->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->receipt->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->receipt->Font = (gcnew System::Drawing::Font(L"Arial Black", 8.25F));
			this->receipt->ForeColor = System::Drawing::SystemColors::Menu;
			this->receipt->Location = System::Drawing::Point(423, 39);
			this->receipt->Name = L"receipt";
			this->receipt->Size = System::Drawing::Size(444, 498);
			this->receipt->TabIndex = 0;
			this->receipt->Text = L"";
			// 
			// bludo
			// 
			this->bludo->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->bludo->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->bludo->Font = (gcnew System::Drawing::Font(L"Arial Black", 8.25F));
			this->bludo->ForeColor = System::Drawing::SystemColors::Menu;
			this->bludo->Location = System::Drawing::Point(65, 39);
			this->bludo->Name = L"bludo";
			this->bludo->Size = System::Drawing::Size(294, 152);
			this->bludo->TabIndex = 1;
			this->bludo->Text = L"";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial Black", 12, System::Drawing::FontStyle::Bold));
			this->label1->ForeColor = System::Drawing::SystemColors::Menu;
			this->label1->Location = System::Drawing::Point(65, 16);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(169, 23);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Название блюда:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->label2->Font = (gcnew System::Drawing::Font(L"Arial Black", 12, System::Drawing::FontStyle::Bold));
			this->label2->ForeColor = System::Drawing::SystemColors::Menu;
			this->label2->Location = System::Drawing::Point(423, 16);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(79, 23);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Рецепт:";
			// 
			// btnSave
			// 
			this->btnSave->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->btnSave->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->btnSave->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnSave->Font = (gcnew System::Drawing::Font(L"Arial Black", 10, System::Drawing::FontStyle::Bold));
			this->btnSave->ForeColor = System::Drawing::SystemColors::Menu;
			this->btnSave->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnSave.Image")));
			this->btnSave->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnSave->Location = System::Drawing::Point(68, 555);
			this->btnSave->Name = L"btnSave";
			this->btnSave->Size = System::Drawing::Size(120, 42);
			this->btnSave->TabIndex = 4;
			this->btnSave->Text = L"Сохранить";
			this->btnSave->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->btnSave->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
			this->btnSave->UseVisualStyleBackColor = false;
			this->btnSave->Click += gcnew System::EventHandler(this, &MyForm2::Save_Click);
			// 
			// btnCancel
			// 
			this->btnCancel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->btnCancel->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->btnCancel->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnCancel->Font = (gcnew System::Drawing::Font(L"Arial Black", 10, System::Drawing::FontStyle::Bold));
			this->btnCancel->ForeColor = System::Drawing::SystemColors::Menu;
			this->btnCancel->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnCancel.Image")));
			this->btnCancel->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnCancel->ImeMode = System::Windows::Forms::ImeMode::On;
			this->btnCancel->Location = System::Drawing::Point(239, 555);
			this->btnCancel->Name = L"btnCancel";
			this->btnCancel->Size = System::Drawing::Size(120, 42);
			this->btnCancel->TabIndex = 5;
			this->btnCancel->Text = L"Выход";
			this->btnCancel->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->btnCancel->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
			this->btnCancel->UseVisualStyleBackColor = false;
			this->btnCancel->Click += gcnew System::EventHandler(this, &MyForm2::btnCancel_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->pictureBox1->ImageLocation = L"CulinareBook.jpg";
			this->pictureBox1->Location = System::Drawing::Point(112, 221);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(194, 180);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 6;
			this->pictureBox1->TabStop = false;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Arial Black", 10, System::Drawing::FontStyle::Bold));
			this->button1->ForeColor = System::Drawing::SystemColors::Menu;
			this->button1->Location = System::Drawing::Point(153, 407);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(111, 39);
			this->button1->TabIndex = 7;
			this->button1->Text = L"Картинка";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm2::button1_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// MyForm2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1024, 632);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->btnCancel);
			this->Controls->Add(this->btnSave);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->bludo);
			this->Controls->Add(this->receipt);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(1040, 670);
			this->MinimumSize = System::Drawing::Size(1040, 670);
			this->Name = L"MyForm2";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Редактор рецепта";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Save_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void btnCancel_Click(System::Object^ sender, System::EventArgs^ e) {
		//this->Hide();
		//otherform->Show();
	}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

	String^ fileName;
	openFileDialog1->Filter = "txt files (*.txt)|*.txt|All files (*.*)|*.*";
	openFileDialog1->FilterIndex = 2;
	openFileDialog1->RestoreDirectory = true;
	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		fileName = openFileDialog1->SafeFileName;
		//fileName = openFileDialog1->FileName;
		pictureBox1->ImageLocation = "img\\" + fileName;
	}
}
private: System::Void openFileDialog1_FileOk(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e) {
}
};
}
