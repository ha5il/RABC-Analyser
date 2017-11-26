#pragma once

namespace RABCAnalyserGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for HomeScreenForm
	/// </summary>
	public ref class HomeScreenForm : public System::Windows::Forms::Form
	{
	public:
		HomeScreenForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~HomeScreenForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  close_Btn;
	private: System::Windows::Forms::Label^  label_Heading;

	protected:


	private: System::Windows::Forms::TextBox^  GUI_RABC_Location;
	private: System::Windows::Forms::Label^  label_Select_RABC;



	private: System::Windows::Forms::Button^  GUI_RABC_Browse_Btn;


	private: System::Windows::Forms::Button^  GUI_Analise_Btn;



	private: System::Windows::Forms::ProgressBar^  progressBar1;



	private: System::Windows::Forms::CheckBox^  GUI_Export_CSV;
	private: System::Windows::Forms::Button^  GUI_CSV_Browse_Btn;
	private: System::Windows::Forms::TextBox^  GUI_CSV_Location;
	private: System::Windows::Forms::Button^  Hasil_Bth;
	private: System::Windows::Forms::Label^  label_CSV_path;








	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(HomeScreenForm::typeid));
			this->close_Btn = (gcnew System::Windows::Forms::Button());
			this->label_Heading = (gcnew System::Windows::Forms::Label());
			this->GUI_RABC_Location = (gcnew System::Windows::Forms::TextBox());
			this->label_Select_RABC = (gcnew System::Windows::Forms::Label());
			this->GUI_RABC_Browse_Btn = (gcnew System::Windows::Forms::Button());
			this->GUI_Analise_Btn = (gcnew System::Windows::Forms::Button());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->GUI_Export_CSV = (gcnew System::Windows::Forms::CheckBox());
			this->GUI_CSV_Browse_Btn = (gcnew System::Windows::Forms::Button());
			this->GUI_CSV_Location = (gcnew System::Windows::Forms::TextBox());
			this->Hasil_Bth = (gcnew System::Windows::Forms::Button());
			this->label_CSV_path = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// close_Btn
			// 
			this->close_Btn->BackColor = System::Drawing::Color::Transparent;
			this->close_Btn->FlatAppearance->BorderSize = 0;
			this->close_Btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->close_Btn->Font = (gcnew System::Drawing::Font(L"Lucida Handwriting", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->close_Btn->Location = System::Drawing::Point(483, 12);
			this->close_Btn->Name = L"close_Btn";
			this->close_Btn->Size = System::Drawing::Size(64, 23);
			this->close_Btn->TabIndex = 0;
			this->close_Btn->Text = L"Close";
			this->close_Btn->UseVisualStyleBackColor = false;
			this->close_Btn->Click += gcnew System::EventHandler(this, &HomeScreenForm::button1_Click);
			// 
			// label_Heading
			// 
			this->label_Heading->AutoSize = true;
			this->label_Heading->BackColor = System::Drawing::SystemColors::Info;
			this->label_Heading->Font = (gcnew System::Drawing::Font(L"Lucida Handwriting", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_Heading->Location = System::Drawing::Point(150, 62);
			this->label_Heading->Name = L"label_Heading";
			this->label_Heading->Size = System::Drawing::Size(264, 27);
			this->label_Heading->TabIndex = 1;
			this->label_Heading->Text = L"RABC Files Analyser";
			this->label_Heading->Click += gcnew System::EventHandler(this, &HomeScreenForm::label1_Click);
			// 
			// GUI_RABC_Location
			// 
			this->GUI_RABC_Location->Location = System::Drawing::Point(210, 121);
			this->GUI_RABC_Location->Name = L"GUI_RABC_Location";
			this->GUI_RABC_Location->ReadOnly = true;
			this->GUI_RABC_Location->Size = System::Drawing::Size(230, 20);
			this->GUI_RABC_Location->TabIndex = 2;
			this->GUI_RABC_Location->TextChanged += gcnew System::EventHandler(this, &HomeScreenForm::RABC_Location_TextChanged);
			// 
			// label_Select_RABC
			// 
			this->label_Select_RABC->AutoSize = true;
			this->label_Select_RABC->Font = (gcnew System::Drawing::Font(L"Lucida Handwriting", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_Select_RABC->Location = System::Drawing::Point(23, 121);
			this->label_Select_RABC->Name = L"label_Select_RABC";
			this->label_Select_RABC->Size = System::Drawing::Size(177, 21);
			this->label_Select_RABC->TabIndex = 3;
			this->label_Select_RABC->Text = L"Select RABC Folder";
			this->label_Select_RABC->Click += gcnew System::EventHandler(this, &HomeScreenForm::label2_Click);
			// 
			// GUI_RABC_Browse_Btn
			// 
			this->GUI_RABC_Browse_Btn->BackColor = System::Drawing::Color::Transparent;
			this->GUI_RABC_Browse_Btn->FlatAppearance->BorderSize = 0;
			this->GUI_RABC_Browse_Btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->GUI_RABC_Browse_Btn->Font = (gcnew System::Drawing::Font(L"Lucida Handwriting", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->GUI_RABC_Browse_Btn->Location = System::Drawing::Point(461, 118);
			this->GUI_RABC_Browse_Btn->Name = L"GUI_RABC_Browse_Btn";
			this->GUI_RABC_Browse_Btn->Size = System::Drawing::Size(68, 27);
			this->GUI_RABC_Browse_Btn->TabIndex = 4;
			this->GUI_RABC_Browse_Btn->Text = L"Browse...";
			this->GUI_RABC_Browse_Btn->UseVisualStyleBackColor = false;
			this->GUI_RABC_Browse_Btn->Click += gcnew System::EventHandler(this, &HomeScreenForm::GUI_RABC_Browse_Btn_Click);
			// 
			// GUI_Analise_Btn
			// 
			this->GUI_Analise_Btn->BackColor = System::Drawing::Color::Transparent;
			this->GUI_Analise_Btn->FlatAppearance->BorderSize = 0;
			this->GUI_Analise_Btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->GUI_Analise_Btn->Font = (gcnew System::Drawing::Font(L"Lucida Handwriting", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->GUI_Analise_Btn->Location = System::Drawing::Point(314, 206);
			this->GUI_Analise_Btn->Name = L"GUI_Analise_Btn";
			this->GUI_Analise_Btn->Size = System::Drawing::Size(172, 42);
			this->GUI_Analise_Btn->TabIndex = 5;
			this->GUI_Analise_Btn->Text = L"^_^ Analyse ^_^";
			this->GUI_Analise_Btn->UseVisualStyleBackColor = false;
			this->GUI_Analise_Btn->Click += gcnew System::EventHandler(this, &HomeScreenForm::GUI_Analise_Btn_Click);
			// 
			// progressBar1
			// 
			this->progressBar1->Location = System::Drawing::Point(65, 264);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(430, 23);
			this->progressBar1->TabIndex = 6;
			// 
			// GUI_Export_CSV
			// 
			this->GUI_Export_CSV->AutoSize = true;
			this->GUI_Export_CSV->Font = (gcnew System::Drawing::Font(L"Lucida Handwriting", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->GUI_Export_CSV->Location = System::Drawing::Point(97, 217);
			this->GUI_Export_CSV->Name = L"GUI_Export_CSV";
			this->GUI_Export_CSV->Size = System::Drawing::Size(121, 21);
			this->GUI_Export_CSV->TabIndex = 10;
			this->GUI_Export_CSV->Text = L"Export to CSV";
			this->GUI_Export_CSV->UseVisualStyleBackColor = true;
			this->GUI_Export_CSV->Click += gcnew System::EventHandler(this, &HomeScreenForm::Export_to_CSV_Clicked);
			// 
			// GUI_CSV_Browse_Btn
			// 
			this->GUI_CSV_Browse_Btn->BackColor = System::Drawing::Color::Transparent;
			this->GUI_CSV_Browse_Btn->FlatAppearance->BorderSize = 0;
			this->GUI_CSV_Browse_Btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->GUI_CSV_Browse_Btn->Font = (gcnew System::Drawing::Font(L"Lucida Handwriting", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->GUI_CSV_Browse_Btn->Location = System::Drawing::Point(461, 166);
			this->GUI_CSV_Browse_Btn->Name = L"GUI_CSV_Browse_Btn";
			this->GUI_CSV_Browse_Btn->Size = System::Drawing::Size(68, 26);
			this->GUI_CSV_Browse_Btn->TabIndex = 12;
			this->GUI_CSV_Browse_Btn->Text = L"Browse...";
			this->GUI_CSV_Browse_Btn->UseVisualStyleBackColor = false;
			this->GUI_CSV_Browse_Btn->Visible = false;
			this->GUI_CSV_Browse_Btn->Click += gcnew System::EventHandler(this, &HomeScreenForm::GUI_CSV_Browse_Btn_Click);
			// 
			// GUI_CSV_Location
			// 
			this->GUI_CSV_Location->Location = System::Drawing::Point(210, 169);
			this->GUI_CSV_Location->Name = L"GUI_CSV_Location";
			this->GUI_CSV_Location->ReadOnly = true;
			this->GUI_CSV_Location->Size = System::Drawing::Size(230, 20);
			this->GUI_CSV_Location->TabIndex = 11;
			this->GUI_CSV_Location->Visible = false;
			// 
			// Hasil_Bth
			// 
			this->Hasil_Bth->BackColor = System::Drawing::Color::Transparent;
			this->Hasil_Bth->FlatAppearance->BorderSize = 0;
			this->Hasil_Bth->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->Hasil_Bth->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->Hasil_Bth->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Hasil_Bth->Font = (gcnew System::Drawing::Font(L"Lucida Handwriting", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Hasil_Bth->Location = System::Drawing::Point(2, 17);
			this->Hasil_Bth->Name = L"Hasil_Bth";
			this->Hasil_Bth->Size = System::Drawing::Size(107, 20);
			this->Hasil_Bth->TabIndex = 13;
			this->Hasil_Bth->UseVisualStyleBackColor = false;
			this->Hasil_Bth->Click += gcnew System::EventHandler(this, &HomeScreenForm::Hasil_Btn_Click);
			// 
			// label_CSV_path
			// 
			this->label_CSV_path->AutoSize = true;
			this->label_CSV_path->Font = (gcnew System::Drawing::Font(L"Lucida Handwriting", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_CSV_path->Location = System::Drawing::Point(45, 169);
			this->label_CSV_path->Name = L"label_CSV_path";
			this->label_CSV_path->Size = System::Drawing::Size(155, 21);
			this->label_CSV_path->TabIndex = 14;
			this->label_CSV_path->Text = L"Path to save CSV";
			this->label_CSV_path->Visible = false;
			// 
			// HomeScreenForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Info;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(560, 326);
			this->Controls->Add(this->label_CSV_path);
			this->Controls->Add(this->Hasil_Bth);
			this->Controls->Add(this->GUI_CSV_Browse_Btn);
			this->Controls->Add(this->GUI_CSV_Location);
			this->Controls->Add(this->GUI_Export_CSV);
			this->Controls->Add(this->progressBar1);
			this->Controls->Add(this->GUI_Analise_Btn);
			this->Controls->Add(this->GUI_RABC_Browse_Btn);
			this->Controls->Add(this->label_Select_RABC);
			this->Controls->Add(this->GUI_RABC_Location);
			this->Controls->Add(this->label_Heading);
			this->Controls->Add(this->close_Btn);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"HomeScreenForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"RABC Analyser";
			this->Load += gcnew System::EventHandler(this, &HomeScreenForm::HomeScreenForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		Close();
	}
	private: System::Void HomeScreenForm_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void RABC_Location_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}

private: System::Void GUI_RABC_Browse_Btn_Click(System::Object^  sender, System::EventArgs^  e) 
{
	FolderBrowserDialog^ fbd;
	fbd = gcnew System::Windows::Forms::FolderBrowserDialog;
	fbd->Description = "Choose the RABC folder from the Washer Extractor!";

	// Show the FolderBrowserDialog.
	System::Windows::Forms::DialogResult result = fbd->ShowDialog();
	if (result == System::Windows::Forms::DialogResult::OK)
	{
		GUI_RABC_Location->Text = fbd->SelectedPath;
	}
}
private: System::Void GUI_Analise_Btn_Click(System::Object^  sender, System::EventArgs^  e) {
	MessageBox::Show(GUI_RABC_Location->Text);

}

private: System::Void Export_to_CSV_Clicked(System::Object^  sender, System::EventArgs^  e) {

	if (GUI_Export_CSV->Checked == true)
	{
		GUI_CSV_Location->Visible = true;
		GUI_CSV_Browse_Btn->Visible = true;
		label_CSV_path->Visible = true;
	}

	else
	{
		GUI_CSV_Location->Visible = false;
		GUI_CSV_Browse_Btn->Visible = false;
		label_CSV_path->Visible = false;
	}
	
}


private: System::Void GUI_CSV_Browse_Btn_Click(System::Object^  sender, System::EventArgs^  e) {
		FolderBrowserDialog^ fbd;
		fbd = gcnew System::Windows::Forms::FolderBrowserDialog;
		fbd->Description = "Choose the folder to save the CSV file!";

		// Show the FolderBrowserDialog.
		System::Windows::Forms::DialogResult result = fbd->ShowDialog();
		if (result == System::Windows::Forms::DialogResult::OK)
		{
			GUI_CSV_Location->Text = fbd->SelectedPath;
		}
}

private: System::Void Hasil_Btn_Click(System::Object^  sender, System::EventArgs^  e) {
	MessageBox::Show("Version 1.0\n\nDeveloped and Managed by Hasil Paudyal \n\nhttp://hasilpaudyal.com.np");
}
};
}
