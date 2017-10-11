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
	 System::Void MyForm::Go(System::Windows::Forms::DataVisualization::Charting::Chart ^ Graphic){
		for (int i = 0; i < 5; i++) {
			Graphic->Series[i]->Points->Clear();
		}
		CheckMethods(Graphic);
		double h = eq->time / eq->n;
		for (int i = 0; i < eq->n; i++) {
			Graphic->Series[1]->Points->AddXY(i*h, (eq->TCoffee - eq->TRoom) * exp(-eq->r * i*h) + eq->TRoom);
		}
	}

	System::Void MyForm::CheckMethods(System::Windows::Forms::DataVisualization::Charting::Chart ^ Graphic){
		eq->TRoom = Convert::ToDouble(tbRoomTemp->Text);
		eq->TCoffee = Convert::ToDouble(tbTemp0->Text);
		eq->r = Convert::ToDouble(tbCoefCooling->Text);
		eq->time = Convert::ToDouble(tbTimePeriod->Text);
		eq->n = Convert::ToDouble(tbNumPoints->Text);
		eq->tableMethods.clear();

		double h = eq->time / eq->n;

		if (eq->selectEuler) {
			vector <vector<double> > tmp;
			tmp.push_back(eq->Euler());
			for (int i = 0; i < eq->n; i++) {
				Graphic->Series[0]->Points->AddXY(i*h, tmp[0][i]);
			}
		}
		if (eq->selectEulerM) {
			vector <vector<double> > tmp;
			tmp.push_back(eq->MEuler());
			for (int i = 0; i < eq->n; i++) {
				Graphic->Series[2]->Points->AddXY(i*h, tmp[0][i]);
			}
		}
		if (eq->selectEC) {
			vector <vector<double> > tmp;
			tmp.push_back(eq->EulerCauchy());
			for (int i = 0; i < eq->n; i++) {
				Graphic->Series[3]->Points->AddXY(i*h, tmp[0][i]);
			}
		}
		if (eq->selectRK4) {
			vector <vector<double> > tmp;
			tmp.push_back(eq->RungeKutta4());
			for (int i = 0; i < eq->n; i++) {
				Graphic->Series[4]->Points->AddXY(i*h, tmp[0][i]);
			}
		}
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
		eq->selectEuler = cbEuler->Checked;
		eq->selectEC = cbEulerKoushi->Checked;
		eq->selectEulerM = cbMEuler->Checked;
		eq->selectRK4 = cbRK4->Checked;
		eq->n = eq->n + 1;
	}
	System::Void MyForm::bPlot_Click(System::Object^  sender, System::EventArgs^  e) {
		dgTable->Visible = false;
		graph->Visible = true;
		Go(graph);
	}

	double roundTo(double arg, int prec)
	{
		double div = 1.0;
		if (prec >= 0)
			while (prec--)
				div *= 10.0;
		else
			while (prec++)
				div /= 10.0;
		return floor(arg * div + 0.5) / div;
	}

	System::Void MyForm::bTable_Click(System::Object^  sender, System::EventArgs^  e) {
		graph->Visible = false;
		dgTable->Visible = true;
		BaseName = "table.xml";
		DTable = gcnew DataTable();
		DSet = gcnew DataSet();

		eq->TRoom = Convert::ToDouble(tbRoomTemp->Text);
		eq->TCoffee = Convert::ToDouble(tbTemp0->Text);
		eq->r = Convert::ToDouble(tbCoefCooling->Text);
		eq->time = Convert::ToDouble(tbTimePeriod->Text);
		eq->n = Convert::ToInt32(tbNumPoints->Text) + 1;

		eq->tableMethods.push_back(eq->analytSolF());
		eq->tableMethods.push_back(eq->Euler());
		eq->tableMethods.push_back(eq->MEuler());
		eq->tableMethods.push_back(eq->EulerCauchy());
		eq->tableMethods.push_back(eq->RungeKutta4());

		if (IO::File::Exists(BaseName) == false) {
			dgTable->DataSource = DTable;
			DTable->Columns->Add("k");
			DTable->Columns->Add("t(k)");
			DTable->Columns->Add("T(k) теор.");
			DTable->Columns->Add("T(k) Эйлера");
			DTable->Columns->Add("E(k) Эйлера");
			DTable->Columns->Add("T(k) улучш. Эйлера");
			DTable->Columns->Add("E(k) улучш. Эйлера");
			DTable->Columns->Add("T(k) Эйлера-Коши");
			DTable->Columns->Add("E(k) Эйлера-Коши");
			DTable->Columns->Add("T(k) РК4");
			DTable->Columns->Add("E(k) РК4");
			DSet->Tables->Add(DTable);
			
			for (int i = 0; i < eq->n; i++)
			{
				DTable->Rows->Add(i, int(i * eq->time / eq->n), roundTo(eq->tableMethods[0][i], 4), roundTo(eq->tableMethods[1][i], 4), roundTo(eq->tableMethods[0][i] - eq->tableMethods[1][i], 4),
					roundTo(eq->tableMethods[2][i], 4), roundTo(eq->tableMethods[0][i] - eq->tableMethods[2][i], 4),
					roundTo(eq->tableMethods[3][i], 4), roundTo(eq->tableMethods[0][i] - eq->tableMethods[3][i], 4),
					roundTo(eq->tableMethods[4][i], 4), roundTo(eq->tableMethods[0][i] - eq->tableMethods[4][i], 4));
			}
		}
		else {
			DSet->ReadXml(BaseName);
			String ^ StringXML = DSet->GetXml();
			dgTable->DataMember = "Название таблицы";
			dgTable->DataSource = DSet;
		}
	}
}