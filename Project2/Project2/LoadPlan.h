#pragma once
#include <string>

using namespace std;
using namespace System;
using namespace System::IO;
using namespace System::Windows::Forms;

class LoadPlan {
private:
	string planInformation[100];
	string root;
	int index = 0;
	int year;
	int month;
	int day;
	
	void loadFile() {
		string yearStr = to_string(year);
		string monthStr = to_string(month);
		string dayStr = to_string(day);
		string path = root + "\\" + yearStr + "'s Plan\\" + monthStr + "'s Plan\\";
		string fileName = yearStr + "-" + monthStr + "-" + dayStr + "_Plan.txt";
		System::String^ Path = gcnew String(path.c_str());
		System::String^ FileName = gcnew String(fileName.c_str());
		if (System::IO::File::Exists(Path + FileName)) {
		StreamReader^ reader = gcnew StreamReader(Path + FileName);
		System::String^ Line = gcnew String("");
		while (reader->Peek() >= 0) {
			Line = reader->ReadLine();
			MarshalString(Line, planInformation[index]);
			index++;
		}
		reader->Close();
		}
	}

	void SortByTime() {
		int customIndex = index/4;
		for (int i = 0; i < customIndex - 1; i++) {
			for (int j = 0; j < customIndex - 1; j++) {
				bool flag = compareTime(planInformation[j * 4], planInformation[(j + 1) * 4]);
				if (flag) swap(j, j + 1);
			}
		}
	}

	bool compareTime(string a, string b) {
		int i = 0;
		int a_year = 10000, a_month = 13, a_day = 32, a_time = 0;
		string str = "";
		while (a[i] != '~') {
			if (a[i] >= '0' && a[i] <= '9') {
				str += a[i];
			}
			else if (a[i] == '/') {
				a_year = atoi(str.c_str());
				str = "";
			}
			else if (a[i] == '-') {
				a_month = atoi(str.c_str());
				str = "";
			}
			else if (a[i] == '_') {
				a_day = atoi(str.c_str());
				str = "";
			}
			i++;
		}
		a_time = atoi(str.c_str());

		i = 0;
		int b_year = 10000, b_month = 13, b_day = 32, b_time = 0;
		str = "";
		while (b[i] != '~') {
			if (b[i] >= '0' && b[i] <= '9') {
				str += b[i];
			}
			else if (b[i] == '/') {
				b_year = atoi(str.c_str());
				str = "";
			}
			else if (b[i] == '-') {
				b_month = atoi(str.c_str());
				str = "";
			}
			else if (b[i] == '_') {
				b_day = atoi(str.c_str());
				str = "";
			}
			i++;
		}
		b_time = atoi(str.c_str());

		bool flag = false;
		if (a_year > b_year) {
			flag = true;
		}
		else if (a_month > b_month) {
			if (a_year == b_year) flag = true;
		}
		else if(a_day > b_day){
			if (a_month == b_month) flag = true;
		}
		else if (a_time > b_time) {
			if (a_day == b_day) flag = true;
		}
		return flag;
	}

	void swap(int a, int b) {
		string tempPeriod = planInformation[a * 4];
		string tempTitle = planInformation[(a * 4) + 1];
		string tempDetail = planInformation[(a * 4) + 2];
		string tempCategory = planInformation[(a * 4) + 3];
		planInformation[a * 4] = planInformation[b * 4];
		planInformation[(a * 4) + 1] = planInformation[(b * 4) + 1];
		planInformation[(a * 4) + 2] = planInformation[(b * 4) + 2];
		planInformation[(a * 4) + 3] = planInformation[(b * 4) + 3];
		planInformation[b * 4] = tempPeriod;
		planInformation[(b * 4) + 1] = tempTitle;
		planInformation[(b * 4) + 2] = tempDetail;
		planInformation[(b * 4) + 3] = tempCategory;
	}

	void MarshalString(System::String^ s, string& str) {
		using namespace Runtime::InteropServices;
		IntPtr ptr = Marshal::StringToHGlobalAnsi(s);
		const char* c = static_cast<const char*>(ptr.ToPointer());
		str = c;
		Marshal::FreeHGlobal(IntPtr((void*)c));
	}

public:
	LoadPlan(System::String^ Type, int Year, int Month, int Day) {
		for (int i = 0; i < 100; i++) {
			planInformation[i] = "";
		}
		MarshalString(Type, root);
		year = Year;
		month = Month;
		day = Day;
	}

	string* PlanInfo() {
		loadFile();
		SortByTime();
		return planInformation;
	}

	bool DeleteText(System::String^ Text) {
		bool flag = false;
		string yearStr = to_string(year);
		string monthStr = to_string(month);
		string dayStr = to_string(day);
		string path = root + "\\" + yearStr + "'s Plan\\" + monthStr + "'s Plan\\";
		string fileName = yearStr + "-" + monthStr + "-" + dayStr + "_Plan.txt";
		System::String^ Path = gcnew String(path.c_str());
		System::String^ FileName = gcnew String(fileName.c_str());
		string keyText;
		string line[100];
		MarshalString(Text, keyText);
		int index = 0;
		if (System::IO::File::Exists(Path + FileName)) {
			StreamReader^ reader = gcnew StreamReader(Path + FileName);
			System::String^ Line = gcnew String("");
			while (reader->Peek() >= 0) {
				Line = reader->ReadLine();
				MarshalString(Line, line[index]);
				if (line[index] == "Title : " + keyText) {
					reader->ReadLine();
					reader->ReadLine();
					index -= 2;
					flag = true;
				}
				index++;
			}
			reader->Close();
		}
		StreamWriter^ File = gcnew StreamWriter(Path + FileName);
		for (int i = 0; i < index; i++) {
			System::String^ newLine = gcnew String(line[i].c_str());
			File->Write(newLine + "\r\n");
		}
		File->Close();
		return flag;
	}

	int get_index() {
		return index;
	}
};