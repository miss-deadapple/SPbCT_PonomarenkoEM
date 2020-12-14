#pragma once
#pragma once
#include "table.h"
#include <ctime>
#include <iostream>
#include "strochka.h"
#include "autotable.h"
#include "sorttable.h"

namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ������ ��� MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ N;
	private: System::Windows::Forms::TextBox^ M;
	private: System::Windows::Forms::TextBox^ Sto;



	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ Stroka;


	private: System::Windows::Forms::DataGridView^ Table;
	private: System::Windows::Forms::DataGridView^ Table1;
	private: System::Windows::Forms::DataGridView^ Table2;



	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;

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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->N = (gcnew System::Windows::Forms::TextBox());
			this->M = (gcnew System::Windows::Forms::TextBox());
			this->Sto = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->Stroka = (gcnew System::Windows::Forms::TextBox());
			this->Table = (gcnew System::Windows::Forms::DataGridView());
			this->Table1 = (gcnew System::Windows::Forms::DataGridView());
			this->Table2 = (gcnew System::Windows::Forms::DataGridView());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Table))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Table1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Table2))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(588, 582);
			this->button1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(100, 28);
			this->button1->TabIndex = 1;
			this->button1->Text = L"���������";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(31, 465);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(131, 17);
			this->label1->TabIndex = 2;
			this->label1->Text = L"���������� �����:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(31, 503);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(155, 17);
			this->label2->TabIndex = 3;
			this->label2->Text = L"���������� ��������:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(31, 543);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(104, 17);
			this->label3->TabIndex = 4;
			this->label3->Text = L"����� ������:";
			// 
			// N
			// 
			this->N->Location = System::Drawing::Point(217, 462);
			this->N->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->N->Name = L"N";
			this->N->Size = System::Drawing::Size(132, 22);
			this->N->TabIndex = 5;
			// 
			// M
			// 
			this->M->Location = System::Drawing::Point(217, 503);
			this->M->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->M->Name = L"M";
			this->M->Size = System::Drawing::Size(132, 22);
			this->M->TabIndex = 6;
			// 
			// Sto
			// 
			this->Sto->Location = System::Drawing::Point(217, 543);
			this->Sto->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->Sto->Name = L"Sto";
			this->Sto->Size = System::Drawing::Size(132, 22);
			this->Sto->TabIndex = 7;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(631, 467);
			this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(116, 17);
			this->label4->TabIndex = 8;
			this->label4->Text = L"������ �������";
			// 
			// Stroka
			// 
			this->Stroka->Location = System::Drawing::Point(634, 488);
			this->Stroka->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->Stroka->Name = L"Stroka";
			this->Stroka->Size = System::Drawing::Size(244, 22);
			this->Stroka->TabIndex = 9;
			// 
			// Table
			// 
			this->Table->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->Table->Location = System::Drawing::Point(16, 78);
			this->Table->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->Table->Name = L"Table";
			this->Table->RowHeadersWidth = 51;
			this->Table->Size = System::Drawing::Size(610, 361);
			this->Table->TabIndex = 10;
			// 
			// Table1
			// 
			this->Table1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->Table1->Location = System::Drawing::Point(634, 78);
			this->Table1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->Table1->Name = L"Table1";
			this->Table1->RowHeadersWidth = 51;
			this->Table1->Size = System::Drawing::Size(610, 360);
			this->Table1->TabIndex = 11;
			// 
			// Table2
			// 
			this->Table2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->Table2->Location = System::Drawing::Point(1252, 79);
			this->Table2->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->Table2->Name = L"Table2";
			this->Table2->RowHeadersWidth = 51;
			this->Table2->Size = System::Drawing::Size(610, 360);
			this->Table2->TabIndex = 12;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(264, 57);
			this->label5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(65, 17);
			this->label5->TabIndex = 13;
			this->label5->Text = L"�������";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(891, 58);
			this->label6->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(158, 17);
			this->label6->TabIndex = 14;
			this->label6->Text = L"������� � ����������";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(1443, 58);
			this->label7->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(250, 17);
			this->label7->TabIndex = 15;
			this->label7->Text = L"������� � ����������� �� ��������";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1924, 818);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->Table2);
			this->Controls->Add(this->Table1);
			this->Controls->Add(this->Table);
			this->Controls->Add(this->Stroka);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->Sto);
			this->Controls->Add(this->M);
			this->Controls->Add(this->N);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Table))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Table1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Table2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		Stroka->Text = " ";
		try {
			srand(time(NULL));
			int n, m, sto;

			n = Convert::ToInt32(N->Text);
			m = Convert::ToInt32(M->Text);
			//////////////////////////
			int** tab = new int* [n];
			for (int i = 0; i < n; i++)
				tab[i] = new int[m];
			table t1(tab, n, m);
			tab[n - 1][m] = t1.filltable(&tab[0]);
			Table->ColumnCount = m;
			Table->RowCount = n;
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++)
					this->Table->Rows[i]->Cells[j]->Value = Convert::ToString(tab[i][j]);
			//////////////////////////
			sto = Convert::ToInt32(Sto->Text);
			int* s = new int[m];
			strochka s1(tab, n, m, sto, s);
			s[m] = s1.fillstroka(&s[0]);
			for (int i = 0; i < m; i++)
				Stroka->Text += " " + s[i];
			//////////////////////////
			m = m + 1;
			int** tab1 = new int* [n];
			for (int i = 0; i < n; i++)
				tab1[i] = new int[m];
			autotable t2(tab, n, m, tab1);
			tab1[n - 1][m] = t2.fillautotable(&tab1[0]);
			Table1->ColumnCount = m;
			Table1->RowCount = n;
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++)
					this->Table1->Rows[i]->Cells[j]->Value = Convert::ToString(tab1[i][j]);
			//////////////////////////
			m = m - 1;
			int** tab2 = new int* [n];
			for (int i = 0; i < n; i++)
				tab2[i] = new int[m];
			sorttable t3(tab, n, m, tab2);
			tab2[n - 1][m] = t3.fillsorttable(&tab2[0]);
			Table2->ColumnCount = m;
			Table2->RowCount = n;
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++)
					this->Table2->Rows[i]->Cells[j]->Value = Convert::ToString(tab2[i][j]);
		}
		catch (System::FormatException^ ex) {
			MessageBox::Show("��������� ��� ����.", "������!",
				MessageBoxButtons::OK,
				MessageBoxIcon::Exclamation);
		}
	}

	private: System::Void M_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		if (e->KeyChar >= '0' && e->KeyChar <= '9') return;
		if (Char::IsControl(e->KeyChar)) {
			if (e->KeyChar == (Char)Keys::Enter)
				button1->Focus();
			return;
		}
		e->Handled = true;
	}

	private: System::Void N_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		if (e->KeyChar >= '0' && e->KeyChar <= '9') return;
		if (Char::IsControl(e->KeyChar)) {
			if (e->KeyChar == (Char)Keys::Enter)
				button1->Focus();
			return;
		}
		e->Handled = true;
	}

	private: System::Void Sto_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		if (e->KeyChar >= '0' && e->KeyChar <= '9') return;
		if (Char::IsControl(e->KeyChar)) {
			if (e->KeyChar == (Char)Keys::Enter)
				button1->Focus();
			return;
		}
		e->Handled = true;
	}
	};
}