#pragma once
#include <string>

using namespace std;
using namespace System;
using namespace System::IO;

class Plan {

private:
	int dateInformation[9];
	int dateCount[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	string type;
	string title;
	string detail;
	string startTime;
	string endTime;
	string category;

	System::String^ makeFolder(string root, string startYear, string startMonth) {
		string folderName_year = startYear + "'s Plan";
		string folderName_month = startMonth + "'s Plan";
		System::String^ FolderName_year = gcnew String(folderName_year.c_str());
		System::String^ FolderName_month = gcnew String(folderName_month.c_str());
		System::String^ Root = gcnew String(root.c_str());
		System::String^ StoreAddress = Root + "\\" + FolderName_year + "\\" + FolderName_month;
		if (!System::IO::Directory::Exists(Root)) {
			System::IO::Directory::CreateDirectory(Root);
		}
		if (!System::IO::Directory::Exists(Root + "\\" + FolderName_year)) {
			System::IO::Directory::CreateDirectory(Root + "\\" + FolderName_year);
		}
		if (!System::IO::Directory::Exists(StoreAddress)) {
			System::IO::Directory::CreateDirectory(StoreAddress);
		}
		return StoreAddress;
	}

	StreamWriter^ makeFile(string textName, System::String^ StoreAddress) {
		System::String^ TextName = gcnew String(textName.c_str());
		StreamWriter^ File = gcnew StreamWriter(StoreAddress + "\\" + TextName + "_Plan.txt", true);
		return File;
	}

	void WriteText(StreamWriter^ File, string* dateInfoStr) {
		string startDate;
		string endDate;
		if (dateInformation[0] != dateInformation[3]) {
			startDate = dateInfoStr[0] + "/" + dateInfoStr[1] + "-" + dateInfoStr[2] + "_";
			endDate = dateInfoStr[3] + "/" + dateInfoStr[4] + "-" + dateInfoStr[5] + "_";
		}
		else if (dateInformation[1] != dateInformation[4]) {
			startDate = dateInfoStr[1] + "-" + dateInfoStr[2] + "_";
			endDate = dateInfoStr[4] + "-" + dateInfoStr[5] + "_";
		}
		else if (dateInformation[2] != dateInformation[5]) {
			startDate = dateInfoStr[1] + "-" + dateInfoStr[2] + "_";
			endDate = dateInfoStr[4] + "-" + dateInfoStr[5] + "_";
		}
		
		if (type == "Important") {
			startDate = "";
			if (dateInformation[6] != dateInformation[3]) {
				startDate = dateInfoStr[6] + "/" + dateInfoStr[7] + "-" + dateInfoStr[8] + "_";
			}
			else {
				startDate = dateInfoStr[7] + "-" + dateInfoStr[8] + "_";
				endDate = dateInfoStr[4] + "-" + dateInfoStr[5] + "_";
			}
		}
		startDate += startTime;
		endDate += endTime;
		string period = startDate + " ~ " + endDate;
		System::String^ Period = gcnew String(period.c_str());
		System::String^ Title = gcnew String(title.c_str());
		System::String^ Detail = gcnew String(detail.c_str());
		System::String^ Category = gcnew String(category.c_str());
		File->Write(Period + "\r\n");
		File->Write("Title : " + Title + "\r\n");
		File->Write("Detail : " + Detail + "\r\n");
		File->Write("Category : " + Category + "\r\n");
	}

	void MarshalString(System::String^ s, string& str) {
		using namespace Runtime::InteropServices;
		IntPtr ptr = Marshal::StringToHGlobalAnsi(s);
		const char* c = static_cast<const char*>(ptr.ToPointer());
		str = c;
		Marshal::FreeHGlobal(IntPtr((void*)c));
	}

	bool isLeapYear(int year) {
		return (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
	}

public:
	Plan(int* date, System::String^ Type, System::String^ Title, System::String^ Detail, System::String^ StartTime, System::String^ EndTime, System::String^ Category) {
		for (int i = 0; i < 9; i++) {
			dateInformation[i] = date[i];
		}
		MarshalString(Type, type);
		MarshalString(Title, title);
		MarshalString(Detail, detail);
		MarshalString(StartTime, startTime);
		MarshalString(EndTime, endTime);
		MarshalString(Category, category);
	}

	void makePlan() {
		string dateInfoStr[9];
		for (int i = 0; i < 9; i++) {
			dateInfoStr[i] = to_string(dateInformation[i]);
		}

		for (int i = dateInformation[0]; i <= dateInformation[3]; i++) {
			int startMonth = (i != dateInformation[0]) ? 1 : dateInformation[1];
			int endMonth = (i != dateInformation[3]) ? 12 : dateInformation[4];
			int monthDate[12];
			memcpy(monthDate, dateCount, sizeof(dateCount));
			if (isLeapYear(i)) monthDate[1]++;
			for (int j = startMonth; j <= endMonth; j++) {
				int startDay = (j != startMonth) ? 1 : dateInformation[2];
				int endDay = (j != endMonth) ? monthDate[j - 1] : dateInformation[5];
				for (int k = startDay; k <= endDay; k++) {
					string StartYear = to_string(i);
					string StartMonth = to_string(((j - 1) % 12) + 1);
					string StartDay = to_string(k);
					string textName = StartYear + "-" + StartMonth + "-" + StartDay;
					System::String^ FolderName = makeFolder(type, StartYear, StartMonth);
					StreamWriter^ File = makeFile(textName, FolderName);
					WriteText(File, dateInfoStr);
					File->Close();
				}
			}
		}
	}
};