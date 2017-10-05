#pragma once

namespace MCM1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для formTable
	/// </summary>
	public ref class formTable : public System::Windows::Forms::Form
	{
	public:
		formTable(void)
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
		~formTable()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^  DGTable;
	private: String ^ BaseName;
	private: DataTable ^ DTable;
	private: DataSet ^ DSet;
	protected:

	protected:

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
			this->DGTable = (gcnew System::Windows::Forms::DataGridView());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DGTable))->BeginInit();
			this->SuspendLayout();
			// 
			// DGTable
			// 
			this->DGTable->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->DGTable->Location = System::Drawing::Point(0, 0);
			this->DGTable->Name = L"DGTable";
			this->DGTable->RowTemplate->Height = 28;
			this->DGTable->Size = System::Drawing::Size(940, 489);
			this->DGTable->TabIndex = 0;
			// 
			// formTable
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(940, 491);
			this->Controls->Add(this->DGTable);
			this->Name = L"formTable";
			this->Text = L"formTable";
			this->Load += gcnew System::EventHandler(this, &formTable::formTable_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DGTable))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void formTable_Load(System::Object^  sender, System::EventArgs^  e) {
		BaseName = "table.xml";
		DTable = gcnew DataTable();
		DSet = gcnew DataSet();
		if (IO::File::Exists(BaseName) == false) {
			DGTable->DataSource = DTable;
			DTable->Columns->Add("k");
			DTable->Columns->Add("t(k)");
			DTable->Columns->Add("T(k) теор.");
			DTable->Columns->Add("T(k) Эйлера");
			DTable->Columns->Add("E(k) Эйлера");
			DTable->Columns->Add("T(k) улучш. Эйлера");
			DTable->Columns->Add("E(k) улучш. Эйлера");
			DTable->Columns->Add("T(k) РК4");
			DTable->Columns->Add("E(k) РК4");
			DSet->Tables->Add(DTable);
		}
		else {
			DSet->ReadXml(BaseName);
			String ^ StringXML = DSet->GetXml();
			DGTable->DataMember = "Название таблицы";
			DGTable->DataSource = DSet;
		}
	}
	};

	//public ref class DataTable : MarshalByValueComponent, IListSource,
	//	ISupportInitializeNotification, ISupportInitialize, ISerializable,
	//	IXmlSerializable
}
