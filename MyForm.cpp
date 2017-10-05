#include "MyForm.h"
#include <Windows.h>
#include "Equation.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace MCM1;
[STAThreadAttribute]

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	MCM1::MyForm form;
	Application::Run(%form);
	return 0;
}

namespace MCM1 {

	System::Void MyForm::bPlot_Click(System::Object ^ sender, System::EventArgs ^ e)
	{
		Equation *values = new Equation(Convert::ToInt32(tbTemp0->Text), Convert::ToInt32(tbRoomTemp->Text), Convert::ToInt32(tbCoefCooling->Text), Convert::ToInt32(tbTimePeriod->Text), Convert::ToInt32(tbNumPoints->Text));

		formPlot^ fPlot = gcnew formPlot;
		fPlot->ShowDialog();
	}
	System::Void MyForm::bTable_Click(System::Object ^ sender, System::EventArgs ^ e)
	{
		formTable^ fTable = gcnew formTable;
		fTable->ShowDialog();
	}
}
