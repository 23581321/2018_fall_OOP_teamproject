#pragma once
#include <iostream>
#include <string>
#include "Plan.h"

namespace Project2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	using namespace System::Text;
	using namespace System::IO;
	using namespace std;

	/// <summary>
	/// WritePlan에 대한 요약입니다.
	/// </summary>
	public ref class WritePlan : public System::Windows::Forms::Form
	{
	public:
		WritePlan(void)
		{
			InitializeComponent();
			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			//
		}

	protected:
		/// <summary>
		/// 사용 중인 모든 리소스를 정리합니다.
		/// </summary>
		~WritePlan()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  Detail;
	protected:

	protected:
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::DateTimePicker^  Start;
	private: System::Windows::Forms::DateTimePicker^  End;



	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  Title;

	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::ComboBox^  StartTime;
	private: System::Windows::Forms::ComboBox^  EndTime;
	private: System::Windows::Forms::CheckBox^  Daily;



	private: System::Windows::Forms::CheckBox^  Important;

	private: System::Windows::Forms::Label^  label5;

	private: System::Windows::Forms::ComboBox^  Category;

	private: System::Windows::Forms::Label^  label6;










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
			this->Detail = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->Start = (gcnew System::Windows::Forms::DateTimePicker());
			this->End = (gcnew System::Windows::Forms::DateTimePicker());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->Title = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->StartTime = (gcnew System::Windows::Forms::ComboBox());
			this->EndTime = (gcnew System::Windows::Forms::ComboBox());
			this->Daily = (gcnew System::Windows::Forms::CheckBox());
			this->Important = (gcnew System::Windows::Forms::CheckBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->Category = (gcnew System::Windows::Forms::ComboBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// Detail
			// 
			this->Detail->ForeColor = System::Drawing::SystemColors::WindowText;
			this->Detail->Location = System::Drawing::Point(107, 224);
			this->Detail->Multiline = true;
			this->Detail->Name = L"Detail";
			this->Detail->Size = System::Drawing::Size(309, 179);
			this->Detail->TabIndex = 5;
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"나눔고딕", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->button1->Location = System::Drawing::Point(492, 339);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(97, 39);
			this->button1->TabIndex = 1;
			this->button1->Text = L"확인";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &WritePlan::button1_Click);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"나눔고딕", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->button2->Location = System::Drawing::Point(620, 339);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(97, 39);
			this->button2->TabIndex = 1;
			this->button2->Text = L"취소";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &WritePlan::button2_Click);
			// 
			// Start
			// 
			this->Start->Location = System::Drawing::Point(107, 38);
			this->Start->Name = L"Start";
			this->Start->Size = System::Drawing::Size(200, 25);
			this->Start->TabIndex = 0;
			this->Start->ValueChanged += gcnew System::EventHandler(this, &WritePlan::Start_ValueChanged);
			// 
			// End
			// 
			this->End->Location = System::Drawing::Point(107, 92);
			this->End->Name = L"End";
			this->End->Size = System::Drawing::Size(200, 25);
			this->End->TabIndex = 2;
			this->End->ValueChanged += gcnew System::EventHandler(this, &WritePlan::End_ValueChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::SystemColors::ControlLight;
			this->label1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label1->Font = (gcnew System::Drawing::Font(L"나눔고딕", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label1->Location = System::Drawing::Point(12, 37);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(60, 30);
			this->label1->TabIndex = 3;
			this->label1->Text = L"시작";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::SystemColors::ControlLight;
			this->label2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label2->Font = (gcnew System::Drawing::Font(L"나눔고딕", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label2->Location = System::Drawing::Point(12, 87);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(60, 30);
			this->label2->TabIndex = 3;
			this->label2->Text = L"종료";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::SystemColors::ControlLight;
			this->label3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label3->Font = (gcnew System::Drawing::Font(L"나눔고딕", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label3->Location = System::Drawing::Point(12, 142);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(60, 30);
			this->label3->TabIndex = 3;
			this->label3->Text = L"제목";
			// 
			// Title
			// 
			this->Title->ForeColor = System::Drawing::SystemColors::ControlDark;
			this->Title->Location = System::Drawing::Point(107, 142);
			this->Title->Multiline = true;
			this->Title->Name = L"Title";
			this->Title->Size = System::Drawing::Size(309, 60);
			this->Title->TabIndex = 4;
			this->Title->Text = L"제목은 필수 입력사항 입니다. (최대 30자)";
			this->Title->Enter += gcnew System::EventHandler(this, &WritePlan::Title_Enter);
			this->Title->Leave += gcnew System::EventHandler(this, &WritePlan::Title_Leave);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::SystemColors::ControlLight;
			this->label4->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label4->Font = (gcnew System::Drawing::Font(L"나눔고딕", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label4->Location = System::Drawing::Point(12, 224);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(60, 30);
			this->label4->TabIndex = 3;
			this->label4->Text = L"내용";
			// 
			// StartTime
			// 
			this->StartTime->DropDownHeight = 86;
			this->StartTime->FormattingEnabled = true;
			this->StartTime->IntegralHeight = false;
			this->StartTime->Items->AddRange(gcnew cli::array< System::Object^  >(48) {
				L"00:00", L"00:30", L"01:00", L"1:30", L"2:00",
					L"2:30", L"3:00", L"3:30", L"4:00", L"4:30", L"5:00", L"5:30", L"6:00", L"6:30", L"7:00", L"7:30", L"8:00", L"8:30", L"9:00",
					L"9:30", L"10:00", L"10:30", L"11:00", L"11:30", L"12:00", L"12:30", L"13:00", L"13:30", L"14:00", L"14:30", L"15:00", L"15:30",
					L"16:00", L"16:30", L"17:00", L"17:30", L"18:00", L"18:30", L"19:00", L"19:30", L"20:00", L"20:30", L"21:00", L"21:30", L"22:00",
					L"22:30", L"23:00", L"23:30"
			});
			this->StartTime->Location = System::Drawing::Point(327, 40);
			this->StartTime->Name = L"StartTime";
			this->StartTime->Size = System::Drawing::Size(121, 23);
			this->StartTime->TabIndex = 1;
			this->StartTime->Text = L"00:00";
			this->StartTime->SelectedIndexChanged += gcnew System::EventHandler(this, &WritePlan::StartTime_SelectedIndexChanged);
			// 
			// EndTime
			// 
			this->EndTime->DropDownHeight = 86;
			this->EndTime->FormattingEnabled = true;
			this->EndTime->IntegralHeight = false;
			this->EndTime->Items->AddRange(gcnew cli::array< System::Object^  >(48) {
				L"00:00", L"00:30", L"01:00", L"1:30", L"2:00", L"2:30",
					L"3:00", L"3:30", L"4:00", L"4:30", L"5:00", L"5:30", L"6:00", L"6:30", L"7:00", L"7:30", L"8:00", L"8:30", L"9:00", L"9:30",
					L"10:00", L"10:30", L"11:00", L"11:30", L"12:00", L"12:30", L"13:00", L"13:30", L"14:00", L"14:30", L"15:00", L"15:30", L"16:00",
					L"16:30", L"17:00", L"17:30", L"18:00", L"18:30", L"19:00", L"19:30", L"20:00", L"20:30", L"21:00", L"21:30", L"22:00", L"22:30",
					L"23:00", L"23:30"
			});
			this->EndTime->Location = System::Drawing::Point(327, 92);
			this->EndTime->Name = L"EndTime";
			this->EndTime->Size = System::Drawing::Size(121, 23);
			this->EndTime->TabIndex = 3;
			this->EndTime->Text = L"12:00";
			this->EndTime->SelectedIndexChanged += gcnew System::EventHandler(this, &WritePlan::EndTime_SelectedIndexChanged);
			// 
			// Daily
			// 
			this->Daily->AutoSize = true;
			this->Daily->Checked = true;
			this->Daily->CheckState = System::Windows::Forms::CheckState::Checked;
			this->Daily->Location = System::Drawing::Point(508, 113);
			this->Daily->Name = L"Daily";
			this->Daily->Size = System::Drawing::Size(90, 19);
			this->Daily->TabIndex = 6;
			this->Daily->Text = L"DailyPlan";
			this->Daily->UseVisualStyleBackColor = true;
			this->Daily->CheckedChanged += gcnew System::EventHandler(this, &WritePlan::Daily_CheckedChanged);
			// 
			// Important
			// 
			this->Important->AutoSize = true;
			this->Important->Location = System::Drawing::Point(597, 113);
			this->Important->Name = L"Important";
			this->Important->Size = System::Drawing::Size(88, 19);
			this->Important->TabIndex = 6;
			this->Important->Text = L"Important";
			this->Important->UseVisualStyleBackColor = true;
			this->Important->CheckedChanged += gcnew System::EventHandler(this, &WritePlan::Important_CheckedChanged);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::SystemColors::ControlLight;
			this->label5->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label5->Font = (gcnew System::Drawing::Font(L"나눔고딕", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label5->Location = System::Drawing::Point(557, 53);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(66, 30);
			this->label5->TabIndex = 3;
			this->label5->Text = L"Type";
			// 
			// Category
			// 
			this->Category->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->Category->FormattingEnabled = true;
			this->Category->Items->AddRange(gcnew cli::array< System::Object^  >(5) { L"Study", L"Work", L"Leisure", L"Event", L"etc" });
			this->Category->Location = System::Drawing::Point(533, 265);
			this->Category->Name = L"Category";
			this->Category->Size = System::Drawing::Size(121, 23);
			this->Category->TabIndex = 7;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::SystemColors::ControlLight;
			this->label6->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label6->Font = (gcnew System::Drawing::Font(L"나눔고딕", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label6->Location = System::Drawing::Point(533, 208);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(115, 30);
			this->label6->TabIndex = 3;
			this->label6->Text = L"Category";
			// 
			// WritePlan
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(743, 415);
			this->Controls->Add(this->Category);
			this->Controls->Add(this->Important);
			this->Controls->Add(this->Daily);
			this->Controls->Add(this->EndTime);
			this->Controls->Add(this->StartTime);
			this->Controls->Add(this->Title);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->End);
			this->Controls->Add(this->Start);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->Detail);
			this->Name = L"WritePlan";
			this->Text = L"WritePlan";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		this->Close();
	}

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		if ((!(this->Title->Text == "")) && this->Title->ForeColor == System::Drawing::SystemColors::WindowText) {
			int dateInformation[9];
			dateInformation[0] = this->Start->Value.Year;
			dateInformation[1] = this->Start->Value.Month;
			dateInformation[2] = this->Start->Value.Day;
			dateInformation[3] = this->End->Value.Year;
			dateInformation[4] = this->End->Value.Month;
			dateInformation[5] = this->End->Value.Day;
			System::String^ Title = this->Title->Text;
			System::String^ Detail = this->Detail->Text;
			System::String^ StartTime = this->StartTime->Text;
			System::String^ EndTime = this->EndTime->Text;
			System::String^ Category = this->Category->Text;
			System::String^ Type = gcnew String("");
			if (this->Daily->Checked) {
				Type = this->Daily->Text;
			}
			else if (this->Important->Checked) {
				Type = this->Important->Text;
				dateInformation[6] = dateInformation[0];
				dateInformation[7] = dateInformation[1];
				dateInformation[8] = dateInformation[2];
				dateInformation[0] = this->Start->Value.Now.Year;
				dateInformation[1] = this->Start->Value.Now.Month;
				dateInformation[2] = this->Start->Value.Now.Day;
			}
			Plan plan = Plan(dateInformation, Type, Title, Detail, StartTime, EndTime, Category);
			plan.makePlan();
			this->Close();
		}
		else {
			MessageBox::Show("제목을 입력해주세요.");
		}
	}

	private: System::Void Daily_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		if (!this->Daily->Checked) {
			if (!this->Important->Checked) {
				this->Daily->Checked = true;
			}
		}
		else {
			this->Important->Checked = false;
		}
	}

	private: System::Void Important_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		if (!this->Important->Checked) {
			if (!this->Daily->Checked) {
				this->Important->Checked = true;
			}
		}
		else {
			this->Daily->Checked = false;
		}
	}

	private: System::Void Start_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
		if (this->Start->Value.Year > this->End->Value.Year) {
			this->End->Value = this->Start->Value;
		}
		else if (this->Start->Value.Month > this->End->Value.Month) {
			if(this->Start->Value.Year == this->End->Value.Year) this->End->Value = this->Start->Value;
		}
		else if (this->Start->Value.Day > this->End->Value.Day) {
			if (this->Start->Value.Month == this->End->Value.Month) this->End->Value = this->Start->Value;
		}
	}

	private: System::Void End_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
		if (this->End->Value.Year < this->Start->Value.Year) {
			this->Start->Value = this->End->Value;
		}
		else if (this->End->Value.Month < this->Start->Value.Month) {
			if (this->End->Value.Year == this->Start->Value.Year) this->Start->Value = this->End->Value;
		}
		else if (this->End->Value.Day < this->Start->Value.Day) {
			if (this->End->Value.Month == this->Start->Value.Month) this->Start->Value = this->End->Value;
		}
	}
	private: System::Void StartTime_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		if ((this->Start->Value.Year == this->End->Value.Year) && (this->Start->Value.Month == this->End->Value.Month) && (this->Start->Value.Day == this->End->Value.Day)) {
			if (this->StartTime->SelectedIndex > this->EndTime->SelectedIndex) {
				this->EndTime->SelectedIndex = this->StartTime->SelectedIndex;
			}
		}
	}
	private: System::Void EndTime_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		if ((this->Start->Value.Year == this->End->Value.Year) && (this->Start->Value.Month == this->End->Value.Month) && (this->Start->Value.Day == this->End->Value.Day)) {
			if (this->EndTime->SelectedIndex < this->StartTime->SelectedIndex) {
				this->StartTime->SelectedIndex = this->EndTime->SelectedIndex;
			}
		}
	}
private: System::Void Title_Enter(System::Object^  sender, System::EventArgs^  e) {
	if (this->Title->Text == "제목은 필수 입력사항 입니다. (최대 30자)" && this->Title->ForeColor == System::Drawing::SystemColors::ControlDark) {
		this->Title->Text = "";
		this->Title->ForeColor = System::Drawing::SystemColors::WindowText;
	}
}
private: System::Void Title_Leave(System::Object^  sender, System::EventArgs^  e) {
	if (this->Title->Text == "") {
		this->Title->Text = "제목은 필수 입력사항 입니다. (최대 30자)";
		this->Title->ForeColor = System::Drawing::SystemColors::ControlDark;
	}
}
};
}
