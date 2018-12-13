#pragma once
#include "WritePlan.h"
#include "LoadPlan.h"

namespace Project2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	/// <summary>
	/// SimPlanner에 대한 요약입니다.
	/// </summary>
	public ref class SimPlanner : public System::Windows::Forms::Form
	{
	public:
		SimPlanner(void)
		{
			InitializeComponent();
			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			//
			LoadPlan Plan_daily = LoadPlan(this->DailyPlan->Name, this->monthCalendar->SelectionStart.Year, this->monthCalendar->SelectionStart.Month, this->monthCalendar->SelectionStart.Day);
			LoadPlan Plan_important = LoadPlan(this->Important->Name, this->monthCalendar->SelectionStart.Year, this->monthCalendar->SelectionStart.Month, this->monthCalendar->SelectionStart.Day);
			string* planInformation = Plan_daily.PlanInfo();
			System::String^ TextForDaily = ViewController(Plan_daily.get_index(), planInformation);
			this->DailyPlanText->Text = TextForDaily;
			planInformation = Plan_important.PlanInfo();
			System::String^ TextForImportant = ViewController(Plan_important.get_index(), planInformation);
			this->ImpotantText->Text = TextForImportant;
			if (System::IO::File::Exists("Memo.txt")) {
				StreamReader^ reader = gcnew StreamReader("Memo.txt");
				System::String^ TextForMemo = gcnew String("");
				while (reader->Peek() >= 0) {
					TextForMemo += reader->ReadLine() + "\r\n";
				}
				this->MemoText->Text = TextForMemo;
				reader->Close();
			}
		}

	protected:
		/// <summary>
		/// 사용 중인 모든 리소스를 정리합니다.
		/// </summary>
		~SimPlanner()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MonthCalendar^  monthCalendar;
	protected:


	private: System::Windows::Forms::Label^  Important;

	protected:

	private: System::Windows::Forms::Label^  DailyPlan;
	private: System::Windows::Forms::Button^  Add;
	private: System::Windows::Forms::Button^  Delete;

	private: System::Windows::Forms::Label^  Memo;

	private: System::Windows::Forms::RichTextBox^  DailyPlanText;
	private: System::Windows::Forms::RichTextBox^  ImpotantText;
	private: System::Windows::Forms::Button^  Save;

	private: System::Windows::Forms::TextBox^  TextForDelete;
	private: System::Windows::Forms::CheckBox^  DailyPlanCheck;
	private: System::Windows::Forms::CheckBox^  ImportantCheck;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::RichTextBox^  MemoText;




	private:
		/// <summary>
		/// 필수 디자이너 변수입니다.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 디자이너 지원에 필요한 메서드입니다. 
		/// 이 메서드의 내용을 코드 편집기로 수정하지 마세요.
		/// </summary>
		void InitializeComponent(void)
		{
			this->monthCalendar = (gcnew System::Windows::Forms::MonthCalendar());
			this->Important = (gcnew System::Windows::Forms::Label());
			this->DailyPlan = (gcnew System::Windows::Forms::Label());
			this->Add = (gcnew System::Windows::Forms::Button());
			this->Delete = (gcnew System::Windows::Forms::Button());
			this->Memo = (gcnew System::Windows::Forms::Label());
			this->DailyPlanText = (gcnew System::Windows::Forms::RichTextBox());
			this->ImpotantText = (gcnew System::Windows::Forms::RichTextBox());
			this->Save = (gcnew System::Windows::Forms::Button());
			this->TextForDelete = (gcnew System::Windows::Forms::TextBox());
			this->DailyPlanCheck = (gcnew System::Windows::Forms::CheckBox());
			this->ImportantCheck = (gcnew System::Windows::Forms::CheckBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->MemoText = (gcnew System::Windows::Forms::RichTextBox());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// monthCalendar
			// 
			this->monthCalendar->Location = System::Drawing::Point(18, 48);
			this->monthCalendar->MaxSelectionCount = 1;
			this->monthCalendar->Name = L"monthCalendar";
			this->monthCalendar->TabIndex = 0;
			this->monthCalendar->DateChanged += gcnew System::Windows::Forms::DateRangeEventHandler(this, &SimPlanner::monthCalendar_DateChanged);
			// 
			// Important
			// 
			this->Important->AutoSize = true;
			this->Important->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->Important->Font = (gcnew System::Drawing::Font(L"나눔고딕", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->Important->Location = System::Drawing::Point(941, 48);
			this->Important->Name = L"Important";
			this->Important->Size = System::Drawing::Size(154, 37);
			this->Important->TabIndex = 2;
			this->Important->Text = L"Important";
			// 
			// DailyPlan
			// 
			this->DailyPlan->AutoSize = true;
			this->DailyPlan->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->DailyPlan->Font = (gcnew System::Drawing::Font(L"나눔고딕", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->DailyPlan->Location = System::Drawing::Point(445, 48);
			this->DailyPlan->Name = L"DailyPlan";
			this->DailyPlan->Size = System::Drawing::Size(149, 37);
			this->DailyPlan->TabIndex = 2;
			this->DailyPlan->Text = L"Daily Plan";
			// 
			// Add
			// 
			this->Add->Font = (gcnew System::Drawing::Font(L"나눔고딕", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->Add->Location = System::Drawing::Point(47, 267);
			this->Add->Name = L"Add";
			this->Add->Size = System::Drawing::Size(183, 42);
			this->Add->TabIndex = 3;
			this->Add->Text = L"계획 추가하기";
			this->Add->UseVisualStyleBackColor = true;
			this->Add->Click += gcnew System::EventHandler(this, &SimPlanner::button1_Click);
			// 
			// Delete
			// 
			this->Delete->Font = (gcnew System::Drawing::Font(L"나눔고딕", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->Delete->Location = System::Drawing::Point(172, 139);
			this->Delete->Name = L"Delete";
			this->Delete->Size = System::Drawing::Size(95, 42);
			this->Delete->TabIndex = 3;
			this->Delete->Text = L"삭제";
			this->Delete->UseVisualStyleBackColor = true;
			this->Delete->Click += gcnew System::EventHandler(this, &SimPlanner::Delete_Click);
			// 
			// Memo
			// 
			this->Memo->AutoSize = true;
			this->Memo->Font = (gcnew System::Drawing::Font(L"나눔고딕", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->Memo->Location = System::Drawing::Point(64, 15);
			this->Memo->Name = L"Memo";
			this->Memo->Size = System::Drawing::Size(105, 35);
			this->Memo->TabIndex = 2;
			this->Memo->Text = L"Memo";
			this->Memo->Click += gcnew System::EventHandler(this, &SimPlanner::Memo_Click);
			// 
			// DailyPlanText
			// 
			this->DailyPlanText->HideSelection = false;
			this->DailyPlanText->Location = System::Drawing::Point(309, 103);
			this->DailyPlanText->Name = L"DailyPlanText";
			this->DailyPlanText->ReadOnly = true;
			this->DailyPlanText->Size = System::Drawing::Size(434, 535);
			this->DailyPlanText->TabIndex = 6;
			this->DailyPlanText->Text = L"";
			// 
			// ImpotantText
			// 
			this->ImpotantText->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->ImpotantText->Location = System::Drawing::Point(803, 103);
			this->ImpotantText->Name = L"ImpotantText";
			this->ImpotantText->ReadOnly = true;
			this->ImpotantText->Size = System::Drawing::Size(434, 289);
			this->ImpotantText->TabIndex = 6;
			this->ImpotantText->Text = L"";
			// 
			// Save
			// 
			this->Save->Font = (gcnew System::Drawing::Font(L"나눔고딕", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->Save->Location = System::Drawing::Point(88, 610);
			this->Save->Name = L"Save";
			this->Save->Size = System::Drawing::Size(95, 42);
			this->Save->TabIndex = 3;
			this->Save->Text = L"저장";
			this->Save->UseVisualStyleBackColor = true;
			this->Save->Click += gcnew System::EventHandler(this, &SimPlanner::Save_Click);
			// 
			// TextForDelete
			// 
			this->TextForDelete->Location = System::Drawing::Point(2, 93);
			this->TextForDelete->Name = L"TextForDelete";
			this->TextForDelete->Size = System::Drawing::Size(434, 25);
			this->TextForDelete->TabIndex = 7;
			// 
			// DailyPlanCheck
			// 
			this->DailyPlanCheck->AutoSize = true;
			this->DailyPlanCheck->Checked = true;
			this->DailyPlanCheck->CheckState = System::Windows::Forms::CheckState::Checked;
			this->DailyPlanCheck->Location = System::Drawing::Point(810, 475);
			this->DailyPlanCheck->Name = L"DailyPlanCheck";
			this->DailyPlanCheck->Size = System::Drawing::Size(95, 19);
			this->DailyPlanCheck->TabIndex = 8;
			this->DailyPlanCheck->Text = L"Daily Plan";
			this->DailyPlanCheck->UseVisualStyleBackColor = true;
			this->DailyPlanCheck->CheckedChanged += gcnew System::EventHandler(this, &SimPlanner::DailyPlanCheck_CheckedChanged);
			// 
			// ImportantCheck
			// 
			this->ImportantCheck->AutoSize = true;
			this->ImportantCheck->Location = System::Drawing::Point(1029, 475);
			this->ImportantCheck->Name = L"ImportantCheck";
			this->ImportantCheck->Size = System::Drawing::Size(88, 19);
			this->ImportantCheck->TabIndex = 8;
			this->ImportantCheck->Text = L"Important";
			this->ImportantCheck->UseVisualStyleBackColor = true;
			this->ImportantCheck->CheckedChanged += gcnew System::EventHandler(this, &SimPlanner::ImportantCheck_CheckedChanged);
			// 
			// panel1
			// 
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Controls->Add(this->TextForDelete);
			this->panel1->Controls->Add(this->Delete);
			this->panel1->Location = System::Drawing::Point(803, 431);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(441, 207);
			this->panel1->TabIndex = 9;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::SystemColors::Window;
			this->panel2->Controls->Add(this->Memo);
			this->panel2->Controls->Add(this->MemoText);
			this->panel2->Location = System::Drawing::Point(18, 354);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(248, 236);
			this->panel2->TabIndex = 10;
			// 
			// MemoText
			// 
			this->MemoText->BackColor = System::Drawing::SystemColors::Window;
			this->MemoText->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->MemoText->Location = System::Drawing::Point(3, 68);
			this->MemoText->Name = L"MemoText";
			this->MemoText->Size = System::Drawing::Size(242, 165);
			this->MemoText->TabIndex = 11;
			this->MemoText->Text = L"";
			// 
			// SimPlanner
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(1281, 664);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->Save);
			this->Controls->Add(this->ImportantCheck);
			this->Controls->Add(this->DailyPlanCheck);
			this->Controls->Add(this->Important);
			this->Controls->Add(this->DailyPlan);
			this->Controls->Add(this->ImpotantText);
			this->Controls->Add(this->DailyPlanText);
			this->Controls->Add(this->Add);
			this->Controls->Add(this->monthCalendar);
			this->Controls->Add(this->panel1);
			this->Name = L"SimPlanner";
			this->Text = L"SimPlanner";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		WritePlan^ dlg = gcnew WritePlan();
		dlg->ShowDialog();
		dlg->Close();
		LoadPlan Plan_daily = LoadPlan(this->DailyPlan->Name, this->monthCalendar->SelectionStart.Year, this->monthCalendar->SelectionStart.Month, this->monthCalendar->SelectionStart.Day);
		LoadPlan Plan_important = LoadPlan(this->Important->Name, this->monthCalendar->SelectionStart.Year, this->monthCalendar->SelectionStart.Month, this->monthCalendar->SelectionStart.Day);
		string* planInformation = Plan_daily.PlanInfo();
		System::String^ TextForDaily = ViewController(Plan_daily.get_index(), planInformation);
		this->DailyPlanText->Text = TextForDaily;
		planInformation = Plan_important.PlanInfo();
		System::String^ TextForImportant = ViewController(Plan_important.get_index(), planInformation);
		this->ImpotantText->Text = TextForImportant;
	}

private: System::String^ ViewController(int index, string* planInfo) {
	int customIndex = index / 4;
	System::String^ Str = gcnew String("");
	for (int i = 0; i < customIndex; i++) {
		Str += PlanView(planInfo[i*4], planInfo[(i * 4) + 1], planInfo[(i * 4) + 2]);
	}
	return Str;
}

private: System::String^ PlanView(string period, string title, string detail) {
	if (period == "") {
		System::String^ Str = gcnew String("");
		return Str;
	}
	string str = "";
	string startYear = "";
	string startMonth = "";
	string startDay = "";
	string startTime = "";
	string endYear = "";
	string endMonth = "";
	string endDay = "";
	string endTime = "";
	int index = 0;
	while (period[index] != '~') {
		if (period[index] >= '0' && period[index] <= '9') {
			str += period[index];
		}
		else if (period[index] == '/') {
			startYear += str;
			str = "";
		}
		else if (period[index] == '-') {
			startMonth += str;
			str = "";
		}
		else if (period[index] == '_') {
			startDay += str;
			str = "";
		}
		index++;
	}
	str.insert(str.length() - 2, ":");
	startTime = str;
	str = "";
	while (period[index] != NULL) {
		if (period[index] >= '0' && period[index] <= '9') {
			str += period[index];
		}
		else if (period[index] == '/') {
			endYear = str;
			str = "";
		}
		else if (period[index] == '-') {
			endMonth = str;
			str = "";
		}
		else if (period[index] == '_') {
			endDay = str;
			str = "";
		}
		index++;
	}
	str.insert(str.length() - 2, ":");
	endTime = str;
	string startDate = "[";
	string endDate = "~ ";
	if (startYear != "") {
		startDate += startYear + "년 ";
		endDate += endYear + "년 ";
	}
	if (startMonth != "") {
		startDate += startMonth + "월 " + startDay + "일 ";
		endDate += endMonth + "월 " + endDay + "일 ";
	}
	startDate += startTime + " ";
	endDate += endTime + "]";
	period = startDate + endDate;
	index = detail.length() - 1;
	string temp = detail;
	detail = "";
	if (index + 1 > 9) {
		while (index != 9) {
			if (temp[index] != ' ') {
				detail = temp + "\r\n";
				break;
			}
			index--;
		}
	} 
	System::String^ Period = gcnew String(period.c_str());
	System::String^ Title = gcnew String(title.c_str());
	System::String^ Detail = gcnew String(detail.c_str());
	return Period + "\r\n" + Title + "\r\n" + Detail + "\r\n";
}
private: System::Void monthCalendar_DateChanged(System::Object^  sender, System::Windows::Forms::DateRangeEventArgs^  e) {
	LoadPlan Plan_daily = LoadPlan(this->DailyPlan->Name, this->monthCalendar->SelectionStart.Year, this->monthCalendar->SelectionStart.Month, this->monthCalendar->SelectionStart.Day);
	LoadPlan Plan_important = LoadPlan(this->Important->Name, this->monthCalendar->SelectionStart.Year, this->monthCalendar->SelectionStart.Month, this->monthCalendar->SelectionStart.Day);
	string* planInformation = Plan_daily.PlanInfo();
	System::String^ TextForDaily = ViewController(Plan_daily.get_index(), planInformation);
	this->DailyPlanText->Text = TextForDaily;
	planInformation = Plan_important.PlanInfo();
	System::String^ TextForImportant = ViewController(Plan_important.get_index(), planInformation);
	this->ImpotantText->Text = TextForImportant;
}

private: System::Void Delete_Click(System::Object^  sender, System::EventArgs^  e) {
	LoadPlan Plan_delete = LoadPlan(this->DailyPlan->Name, this->monthCalendar->SelectionStart.Year, this->monthCalendar->SelectionStart.Month, this->monthCalendar->SelectionStart.Day);
	if(this->ImportantCheck->Checked) {
		Plan_delete = LoadPlan(this->Important->Name, this->monthCalendar->SelectionStart.Year, this->monthCalendar->SelectionStart.Month, this->monthCalendar->SelectionStart.Day);
	}
	if (Plan_delete.DeleteText(this->TextForDelete->Text)) {
		MessageBox::Show("삭제가 완료 되었습니다.");
	}
	else {
		MessageBox::Show("일치하는 항목이 없습니다.");
	}
	LoadPlan Plan_daily = LoadPlan(this->DailyPlan->Name, this->monthCalendar->SelectionStart.Year, this->monthCalendar->SelectionStart.Month, this->monthCalendar->SelectionStart.Day);
	LoadPlan Plan_important = LoadPlan(this->Important->Name, this->monthCalendar->SelectionStart.Year, this->monthCalendar->SelectionStart.Month, this->monthCalendar->SelectionStart.Day);
	string* planInformation = Plan_daily.PlanInfo();
	System::String^ TextForDaily = ViewController(Plan_daily.get_index(), planInformation);
	this->DailyPlanText->Text = TextForDaily;
	planInformation = Plan_important.PlanInfo();
	System::String^ TextForImportant = ViewController(Plan_important.get_index(), planInformation);
	this->ImpotantText->Text = TextForImportant;
}

private: System::Void DailyPlanCheck_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	if (!this->DailyPlanCheck->Checked) {
		if (!this->ImportantCheck->Checked) {
			this->DailyPlanCheck->Checked = true;
		}
	}
	else {
		this->ImportantCheck->Checked = false;
	}
}
private: System::Void ImportantCheck_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	if (!this->ImportantCheck->Checked) {
		if (!this->DailyPlanCheck->Checked) {
			this->ImportantCheck->Checked = true;
		}
	}
	else {
		this->DailyPlanCheck->Checked = false;
	}
}
private: System::Void Memo_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void Save_Click(System::Object^  sender, System::EventArgs^  e) {
	StreamWriter^ File = gcnew StreamWriter("Memo.txt");
	File->Write(this->MemoText->Text);
	File->Close();
	if (System::IO::File::Exists("Memo.txt")) {
		StreamReader^ reader = gcnew StreamReader("Memo.txt");
		System::String^ TextForMemo = gcnew String("");
		while (reader->Peek() >= 0) {
			TextForMemo += reader->ReadLine() + "\r\n";
		}
		this->MemoText->Text = TextForMemo;
		reader->Close();
	}
}
};
}
