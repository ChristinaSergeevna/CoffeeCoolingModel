#include "MyForm.h"
#include <Windows.h>

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

	System::Void MyForm::CheckMethods()
	{
		if (eq->selectEuler) {
			eq->table.push_back(eq->Euler());
		}
		if (eq->selectEC) {
			eq->table.push_back(eq->EulerCauchy());
		}
		if (eq->selectEulerM) {
			eq->table.push_back(eq->MEuler());
		}
		if (eq->selectRK4) {
			eq->table.push_back(eq->RungeKutta4());
		}
	}

	System::Void MyForm::bPlot_Click(System::Object ^ sender, System::EventArgs ^ e)
	{
		

		formPlot^ fPlot = gcnew formPlot;
		fPlot->ShowDialog();
	}
	System::Void MyForm::bTable_Click(System::Object ^ sender, System::EventArgs ^ e)
	{


		formTable^ fTable = gcnew formTable;
		fTable->ShowDialog();
	}
	System::Void MyForm::cbRK4_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
	{
		eq->selectRK4 = cbRK4->Checked;
	}
	System::Void MyForm::cbEuler_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
	{
		eq->selectEuler = cbEuler->Checked;
	}
	System::Void MyForm::cbMEuler_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
	{
		eq->selectEulerM = cbMEuler->Checked;
	}
	System::Void MyForm::cbEulerKoushi_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
	{
		eq->selectEC = cbEulerKoushi->Checked;
	}
	System::Void MyForm::MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
		eq->TRoom = Convert::ToDouble(tbRoomTemp->Text);
		eq->TCoffee = Convert::ToDouble(tbTemp0->Text);
		eq->r = Convert::ToDouble(tbCoefCooling->Text);
		eq->time = Convert::ToDouble(tbTimePeriod->Text);
		eq->n = Convert::ToDouble(tbNumPoints->Text);
		eq->selectEuler = cbEuler->Checked;
		eq->selectEC = cbEulerKoushi->Checked;
		eq->selectEulerM = cbMEuler->Checked;
		eq->selectRK4 = cbRK4->Checked;
}
	System::Void MyForm::tbRoomTemp_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		eq->TRoom = Convert::ToDouble(tbRoomTemp->Text);
	}
	System::Void MyForm::tbCoefCooling_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		eq->r = Convert::ToDouble(tbCoefCooling->Text);
	}

	System::Void MyForm::tbTemp0_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		eq->TCoffee = Convert::ToDouble(tbTemp0->Text);
	}

	System::Void MyForm::tbTimePeriod_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		eq->time = Convert::ToDouble(tbTimePeriod->Text);
	}
	System::Void MyForm::tbNumPoints_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		eq->n = Convert::ToDouble(tbNumPoints->Text);
	}
}