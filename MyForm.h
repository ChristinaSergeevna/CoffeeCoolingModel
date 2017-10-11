#pragma once
#include "Equation.h"
#include <atlstr.h>
#include <math.h>

namespace MCM1 {
	
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	public: Equation *eq = new Equation();
	private: System::Windows::Forms::TextBox^  tbTemp0;
	private: System::Windows::Forms::TextBox^  tbRoomTemp;
	private: System::Windows::Forms::TextBox^  tbTimePeriod;
	private: System::Windows::Forms::Label^  lHader;
	private: System::Windows::Forms::TextBox^  tbCoefCooling;
	protected:

	protected:

	private: System::Windows::Forms::TextBox^  tbNumPoints;
	private: System::Windows::Forms::CheckBox^  cbRK4;
	private: System::Windows::Forms::CheckBox^  cbEuler;
	private: System::Windows::Forms::CheckBox^  cbMEuler;
	private: System::Windows::Forms::CheckBox^  cbEulerKoushi;
	private: System::Windows::Forms::Label^  lTemp0;
	private: System::Windows::Forms::Label^  lRoomTemp;
	private: System::Windows::Forms::Label^  lCoefCooling;
	private: System::Windows::Forms::Label^  lTimePeriod;
	private: System::Windows::Forms::Label^  lNumPoints;
	private: System::Windows::Forms::Button^  bPlot;

	private: System::Windows::Forms::Button^  bTable;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  graph;
	private: System::Windows::Forms::DataGridView^  dgTable;
	private: String ^ BaseName;
	private: DataTable ^ DTable;
	private: DataSet ^ DSet;
	private: System::Windows::Forms::PictureBox^  pictureBox1;

	protected:

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
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea7 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend7 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series31 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series32 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series33 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series34 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series35 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->tbTemp0 = (gcnew System::Windows::Forms::TextBox());
			this->tbRoomTemp = (gcnew System::Windows::Forms::TextBox());
			this->tbTimePeriod = (gcnew System::Windows::Forms::TextBox());
			this->lHader = (gcnew System::Windows::Forms::Label());
			this->tbCoefCooling = (gcnew System::Windows::Forms::TextBox());
			this->tbNumPoints = (gcnew System::Windows::Forms::TextBox());
			this->cbRK4 = (gcnew System::Windows::Forms::CheckBox());
			this->cbEuler = (gcnew System::Windows::Forms::CheckBox());
			this->cbMEuler = (gcnew System::Windows::Forms::CheckBox());
			this->cbEulerKoushi = (gcnew System::Windows::Forms::CheckBox());
			this->lTemp0 = (gcnew System::Windows::Forms::Label());
			this->lRoomTemp = (gcnew System::Windows::Forms::Label());
			this->lCoefCooling = (gcnew System::Windows::Forms::Label());
			this->lTimePeriod = (gcnew System::Windows::Forms::Label());
			this->lNumPoints = (gcnew System::Windows::Forms::Label());
			this->bPlot = (gcnew System::Windows::Forms::Button());
			this->bTable = (gcnew System::Windows::Forms::Button());
			this->graph = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->dgTable = (gcnew System::Windows::Forms::DataGridView());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->graph))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgTable))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// tbTemp0
			// 
			this->tbTemp0->Location = System::Drawing::Point(245, 139);
			this->tbTemp0->Name = L"tbTemp0";
			this->tbTemp0->Size = System::Drawing::Size(83, 26);
			this->tbTemp0->TabIndex = 0;
			this->tbTemp0->Text = L"90";
			// 
			// tbRoomTemp
			// 
			this->tbRoomTemp->Location = System::Drawing::Point(245, 183);
			this->tbRoomTemp->Name = L"tbRoomTemp";
			this->tbRoomTemp->Size = System::Drawing::Size(83, 26);
			this->tbRoomTemp->TabIndex = 1;
			this->tbRoomTemp->Text = L"23";
			// 
			// tbTimePeriod
			// 
			this->tbTimePeriod->Location = System::Drawing::Point(245, 276);
			this->tbTimePeriod->Name = L"tbTimePeriod";
			this->tbTimePeriod->Size = System::Drawing::Size(83, 26);
			this->tbTimePeriod->TabIndex = 2;
			this->tbTimePeriod->Text = L"20";
			// 
			// lHader
			// 
			this->lHader->AutoSize = true;
			this->lHader->Font = (gcnew System::Drawing::Font(L"Tahoma", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lHader->Location = System::Drawing::Point(149, 28);
			this->lHader->Name = L"lHader";
			this->lHader->Size = System::Drawing::Size(0, 39);
			this->lHader->TabIndex = 3;
			// 
			// tbCoefCooling
			// 
			this->tbCoefCooling->Location = System::Drawing::Point(245, 230);
			this->tbCoefCooling->Name = L"tbCoefCooling";
			this->tbCoefCooling->Size = System::Drawing::Size(83, 26);
			this->tbCoefCooling->TabIndex = 4;
			this->tbCoefCooling->Text = L"0,4";
			// 
			// tbNumPoints
			// 
			this->tbNumPoints->Location = System::Drawing::Point(245, 319);
			this->tbNumPoints->Name = L"tbNumPoints";
			this->tbNumPoints->Size = System::Drawing::Size(83, 26);
			this->tbNumPoints->TabIndex = 5;
			this->tbNumPoints->Text = L"10";
			// 
			// cbRK4
			// 
			this->cbRK4->AutoSize = true;
			this->cbRK4->Location = System::Drawing::Point(98, 373);
			this->cbRK4->Name = L"cbRK4";
			this->cbRK4->Size = System::Drawing::Size(230, 24);
			this->cbRK4->TabIndex = 6;
			this->cbRK4->Text = L"Рунге-Кутты 4-го порядка";
			this->cbRK4->UseVisualStyleBackColor = true;
			this->cbRK4->CheckedChanged += gcnew System::EventHandler(this, &MyForm::cbRK4_CheckedChanged);
			// 
			// cbEuler
			// 
			this->cbEuler->AutoSize = true;
			this->cbEuler->Location = System::Drawing::Point(98, 419);
			this->cbEuler->Name = L"cbEuler";
			this->cbEuler->Size = System::Drawing::Size(93, 24);
			this->cbEuler->TabIndex = 7;
			this->cbEuler->Text = L"Эйлера";
			this->cbEuler->UseVisualStyleBackColor = true;
			this->cbEuler->CheckedChanged += gcnew System::EventHandler(this, &MyForm::cbEuler_CheckedChanged);
			// 
			// cbMEuler
			// 
			this->cbMEuler->AutoSize = true;
			this->cbMEuler->Location = System::Drawing::Point(98, 471);
			this->cbMEuler->Name = L"cbMEuler";
			this->cbMEuler->Size = System::Drawing::Size(193, 24);
			this->cbMEuler->TabIndex = 8;
			this->cbMEuler->Text = L"Улучшенный Эйлера";
			this->cbMEuler->UseVisualStyleBackColor = true;
			this->cbMEuler->CheckedChanged += gcnew System::EventHandler(this, &MyForm::cbMEuler_CheckedChanged);
			// 
			// cbEulerKoushi
			// 
			this->cbEulerKoushi->AutoSize = true;
			this->cbEulerKoushi->Location = System::Drawing::Point(98, 516);
			this->cbEulerKoushi->Name = L"cbEulerKoushi";
			this->cbEulerKoushi->Size = System::Drawing::Size(139, 24);
			this->cbEulerKoushi->TabIndex = 9;
			this->cbEulerKoushi->Text = L"Эйлера-Коши";
			this->cbEulerKoushi->UseVisualStyleBackColor = true;
			this->cbEulerKoushi->CheckedChanged += gcnew System::EventHandler(this, &MyForm::cbEulerKoushi_CheckedChanged);
			// 
			// lTemp0
			// 
			this->lTemp0->AutoSize = true;
			this->lTemp0->Location = System::Drawing::Point(28, 139);
			this->lTemp0->Name = L"lTemp0";
			this->lTemp0->Size = System::Drawing::Size(197, 20);
			this->lTemp0->TabIndex = 10;
			this->lTemp0->Text = L"Начальная температура";
			// 
			// lRoomTemp
			// 
			this->lRoomTemp->AutoSize = true;
			this->lRoomTemp->Location = System::Drawing::Point(29, 183);
			this->lRoomTemp->Name = L"lRoomTemp";
			this->lRoomTemp->Size = System::Drawing::Size(196, 20);
			this->lRoomTemp->TabIndex = 11;
			this->lRoomTemp->Text = L"Комнатная температура";
			// 
			// lCoefCooling
			// 
			this->lCoefCooling->AutoSize = true;
			this->lCoefCooling->Location = System::Drawing::Point(18, 230);
			this->lCoefCooling->Name = L"lCoefCooling";
			this->lCoefCooling->Size = System::Drawing::Size(207, 20);
			this->lCoefCooling->TabIndex = 12;
			this->lCoefCooling->Text = L"Коэффициент остывания";
			// 
			// lTimePeriod
			// 
			this->lTimePeriod->AutoSize = true;
			this->lTimePeriod->Location = System::Drawing::Point(71, 276);
			this->lTimePeriod->Name = L"lTimePeriod";
			this->lTimePeriod->Size = System::Drawing::Size(154, 20);
			this->lTimePeriod->TabIndex = 13;
			this->lTimePeriod->Text = L"Временной период";
			// 
			// lNumPoints
			// 
			this->lNumPoints->AutoSize = true;
			this->lNumPoints->Location = System::Drawing::Point(77, 319);
			this->lNumPoints->Name = L"lNumPoints";
			this->lNumPoints->Size = System::Drawing::Size(148, 20);
			this->lNumPoints->TabIndex = 14;
			this->lNumPoints->Text = L"Количество точек";
			// 
			// bPlot
			// 
			this->bPlot->Location = System::Drawing::Point(45, 566);
			this->bPlot->Name = L"bPlot";
			this->bPlot->Size = System::Drawing::Size(136, 65);
			this->bPlot->TabIndex = 15;
			this->bPlot->Text = L"Графики";
			this->bPlot->UseVisualStyleBackColor = true;
			this->bPlot->Click += gcnew System::EventHandler(this, &MyForm::bPlot_Click);
			// 
			// bTable
			// 
			this->bTable->Location = System::Drawing::Point(219, 566);
			this->bTable->Name = L"bTable";
			this->bTable->Size = System::Drawing::Size(136, 65);
			this->bTable->TabIndex = 16;
			this->bTable->Text = L"Таблица";
			this->bTable->UseVisualStyleBackColor = true;
			this->bTable->Click += gcnew System::EventHandler(this, &MyForm::bTable_Click);
			// 
			// graph
			// 
			chartArea7->Name = L"ChartArea1";
			this->graph->ChartAreas->Add(chartArea7);
			legend7->Name = L"Legend1";
			this->graph->Legends->Add(legend7);
			this->graph->Location = System::Drawing::Point(435, 88);
			this->graph->Name = L"graph";
			series31->BorderWidth = 2;
			series31->ChartArea = L"ChartArea1";
			series31->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series31->Legend = L"Legend1";
			series31->Name = L"Euler";
			series32->BorderWidth = 2;
			series32->ChartArea = L"ChartArea1";
			series32->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series32->Legend = L"Legend1";
			series32->Name = L"Analytical";
			series33->BorderWidth = 2;
			series33->ChartArea = L"ChartArea1";
			series33->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series33->Legend = L"Legend1";
			series33->Name = L"Euler modified";
			series34->BorderWidth = 2;
			series34->ChartArea = L"ChartArea1";
			series34->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series34->Legend = L"Legend1";
			series34->Name = L"Euler Cauchy";
			series35->BorderWidth = 2;
			series35->ChartArea = L"ChartArea1";
			series35->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series35->Legend = L"Legend1";
			series35->Name = L"Runge-Kutta";
			this->graph->Series->Add(series31);
			this->graph->Series->Add(series32);
			this->graph->Series->Add(series33);
			this->graph->Series->Add(series34);
			this->graph->Series->Add(series35);
			this->graph->Size = System::Drawing::Size(785, 571);
			this->graph->TabIndex = 17;
			this->graph->Text = L"chart1";
			// 
			// dgTable
			// 
			this->dgTable->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->dgTable->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::ColumnHeader;
			this->dgTable->BackgroundColor = System::Drawing::SystemColors::Window;
			this->dgTable->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dgTable->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::Sunken;
			this->dgTable->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgTable->GridColor = System::Drawing::SystemColors::Window;
			this->dgTable->Location = System::Drawing::Point(435, 0);
			this->dgTable->Name = L"dgTable";
			this->dgTable->ReadOnly = true;
			this->dgTable->RowHeadersVisible = false;
			this->dgTable->RowHeadersWidth = 20;
			this->dgTable->RowTemplate->Height = 28;
			this->dgTable->Size = System::Drawing::Size(793, 659);
			this->dgTable->TabIndex = 18;
			// 
			// pictureBox1
			// 
			this->pictureBox1->ImageLocation = L"C:\\Users\\Christine\\Downloads\\Telegram Desktop\\CoffeeCoolingModel-master\\CoffeeCoo"
				L"lingModel-master\\eq.png";
			this->pictureBox1->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.InitialImage")));
			this->pictureBox1->Location = System::Drawing::Point(32, 42);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(323, 62);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 19;
			this->pictureBox1->TabStop = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->BackColor = System::Drawing::SystemColors::Window;
			this->ClientSize = System::Drawing::Size(1224, 655);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->dgTable);
			this->Controls->Add(this->graph);
			this->Controls->Add(this->bTable);
			this->Controls->Add(this->bPlot);
			this->Controls->Add(this->lNumPoints);
			this->Controls->Add(this->lTimePeriod);
			this->Controls->Add(this->lCoefCooling);
			this->Controls->Add(this->lRoomTemp);
			this->Controls->Add(this->lTemp0);
			this->Controls->Add(this->cbEulerKoushi);
			this->Controls->Add(this->cbMEuler);
			this->Controls->Add(this->cbEuler);
			this->Controls->Add(this->cbRK4);
			this->Controls->Add(this->tbNumPoints);
			this->Controls->Add(this->tbCoefCooling);
			this->Controls->Add(this->lHader);
			this->Controls->Add(this->tbTimePeriod);
			this->Controls->Add(this->tbRoomTemp);
			this->Controls->Add(this->tbTemp0);
			this->Name = L"MyForm";
			this->Text = L"Моделирование процесса остывания кофе";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->graph))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgTable))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void Go(System::Windows::Forms::DataVisualization::Charting::Chart ^ Graphic);
private: System::Void bPlot_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void bTable_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void cbRK4_CheckedChanged(System::Object^  sender, System::EventArgs^  e); 
private: System::Void cbEuler_CheckedChanged(System::Object^  sender, System::EventArgs^  e); 
private: System::Void cbMEuler_CheckedChanged(System::Object^  sender, System::EventArgs^  e); 
private: System::Void cbEulerKoushi_CheckedChanged(System::Object^  sender, System::EventArgs^  e); 
private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e);
private: System::Void CheckMethods(System::Windows::Forms::DataVisualization::Charting::Chart ^ Graphic);
};
}
