﻿#pragma once

#include <windows.h>
#include "IPC.h"
#include <sstream>
#include <msclr/marshal_cppstd.h>
#include "PipeNamesBuffsizesPaths.h"
//msclr::interop::marshal_as<std::string>(mPathBox->Text);
//msclr::interop::marshal_as<String^>(el));

HANDLE pipeForSend = NULL;
HANDLE pipeForRead = NULL;

namespace Client {

	using namespace System;
	using namespace System::Windows::Forms;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;

	public ref class ClientForm : public System::Windows::Forms::Form
	{
	public:
		ClientForm(void)
		{
			InitializeComponent();
			Control::CheckForIllegalCrossThreadCalls = false;
		}

	protected:
		~ClientForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::FolderBrowserDialog^ folderBrowserDialog;
	private: System::Windows::Forms::OpenFileDialog^ openFD;











































	private: System::Windows::Forms::Button^ btnStopService;
	private: System::Windows::Forms::Button^ btnStartService;
	private: System::Windows::Forms::TabPage^ tabPage4;
	private: System::Windows::Forms::ListBox^ reportListBox;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ btnDeleteFromQuarantine;
	private: System::Windows::Forms::ListBox^ QuarantineListBox;
	private: System::Windows::Forms::Button^ btnMoveToQuarantine;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Button^ btnDelete;
	private: System::Windows::Forms::TabPage^ tabPage2;
	private: System::Windows::Forms::ProgressBar^ progressBar3;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::RichTextBox^ txtMonitorRes;
	private: System::Windows::Forms::TextBox^ txtMonitoringPath;
	private: System::Windows::Forms::Button^ btnDelMonitoring;
	private: System::Windows::Forms::Button^ btnSetMonitoring;
	private: System::Windows::Forms::ListBox^ monitoringListBox;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ btnBrowse2;
	private: System::Windows::Forms::TabPage^ tabPage3;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::ProgressBar^ progressBar2;
	private: System::Windows::Forms::RichTextBox^ txtScheduleScanRes;
	private: System::Windows::Forms::TextBox^ txtSchedulePath;
	private: System::Windows::Forms::Button^ btnStopSchedule;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker;
	private: System::Windows::Forms::ListBox^ scheduleListBox;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ btnScheduleScan;
	private: System::Windows::Forms::Button^ btnBrowse3;
	private: System::Windows::Forms::TabPage^ tabPage1;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Button^ btnBrowseFile;
	private: System::Windows::Forms::Button^ btnStopScan;
	private: System::Windows::Forms::ProgressBar^ progressBar1;
	private: System::Windows::Forms::TextBox^ txtScanPath;
	private: System::Windows::Forms::RichTextBox^ txtScanRes;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ btnStartScan;
	private: System::Windows::Forms::Button^ btnBrowseFolder;
	private: System::Windows::Forms::TabControl^ tabControl1;










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
			this->folderBrowserDialog = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->openFD = (gcnew System::Windows::Forms::OpenFileDialog());
			this->btnStopService = (gcnew System::Windows::Forms::Button());
			this->btnStartService = (gcnew System::Windows::Forms::Button());
			this->tabPage4 = (gcnew System::Windows::Forms::TabPage());
			this->btnDelete = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->btnMoveToQuarantine = (gcnew System::Windows::Forms::Button());
			this->QuarantineListBox = (gcnew System::Windows::Forms::ListBox());
			this->btnDeleteFromQuarantine = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->reportListBox = (gcnew System::Windows::Forms::ListBox());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->btnBrowse2 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->txtMonitoringPath = (gcnew System::Windows::Forms::TextBox());
			this->monitoringListBox = (gcnew System::Windows::Forms::ListBox());
			this->btnSetMonitoring = (gcnew System::Windows::Forms::Button());
			this->btnDelMonitoring = (gcnew System::Windows::Forms::Button());
			this->txtMonitorRes = (gcnew System::Windows::Forms::RichTextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->progressBar3 = (gcnew System::Windows::Forms::ProgressBar());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->btnBrowse3 = (gcnew System::Windows::Forms::Button());
			this->btnScheduleScan = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->scheduleListBox = (gcnew System::Windows::Forms::ListBox());
			this->dateTimePicker = (gcnew System::Windows::Forms::DateTimePicker());
			this->btnStopSchedule = (gcnew System::Windows::Forms::Button());
			this->txtSchedulePath = (gcnew System::Windows::Forms::TextBox());
			this->txtScheduleScanRes = (gcnew System::Windows::Forms::RichTextBox());
			this->progressBar2 = (gcnew System::Windows::Forms::ProgressBar());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->btnBrowseFolder = (gcnew System::Windows::Forms::Button());
			this->btnStartScan = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->txtScanRes = (gcnew System::Windows::Forms::RichTextBox());
			this->txtScanPath = (gcnew System::Windows::Forms::TextBox());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->btnStopScan = (gcnew System::Windows::Forms::Button());
			this->btnBrowseFile = (gcnew System::Windows::Forms::Button());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage4->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->tabPage3->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabControl1->SuspendLayout();
			this->SuspendLayout();
			// 
			// btnStopService
			// 
			this->btnStopService->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->btnStopService->BackColor = System::Drawing::Color::Silver;
			this->btnStopService->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnStopService->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnStopService->Location = System::Drawing::Point(725, 515);
			this->btnStopService->Name = L"btnStopService";
			this->btnStopService->Size = System::Drawing::Size(361, 29);
			this->btnStopService->TabIndex = 1;
			this->btnStopService->Text = L"Остановить сервис";
			this->btnStopService->UseVisualStyleBackColor = false;
			this->btnStopService->Click += gcnew System::EventHandler(this, &ClientForm::btnStopService_Click);
			// 
			// btnStartService
			// 
			this->btnStartService->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->btnStartService->BackColor = System::Drawing::Color::Silver;
			this->btnStartService->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnStartService->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnStartService->Location = System::Drawing::Point(9, 510);
			this->btnStartService->Name = L"btnStartService";
			this->btnStartService->Size = System::Drawing::Size(354, 36);
			this->btnStartService->TabIndex = 0;
			this->btnStartService->Text = L"Запустить сервис";
			this->btnStartService->UseVisualStyleBackColor = false;
			this->btnStartService->Click += gcnew System::EventHandler(this, &ClientForm::btnStartService_Click);
			// 
			// tabPage4
			// 
			this->tabPage4->BackColor = System::Drawing::Color::WhiteSmoke;
			this->tabPage4->Controls->Add(this->reportListBox);
			this->tabPage4->Controls->Add(this->label1);
			this->tabPage4->Controls->Add(this->btnDeleteFromQuarantine);
			this->tabPage4->Controls->Add(this->QuarantineListBox);
			this->tabPage4->Controls->Add(this->btnMoveToQuarantine);
			this->tabPage4->Controls->Add(this->label5);
			this->tabPage4->Controls->Add(this->btnDelete);
			this->tabPage4->Location = System::Drawing::Point(4, 25);
			this->tabPage4->Name = L"tabPage4";
			this->tabPage4->Padding = System::Windows::Forms::Padding(3);
			this->tabPage4->Size = System::Drawing::Size(1100, 478);
			this->tabPage4->TabIndex = 3;
			this->tabPage4->Text = L"Обнаруженные угрозы";
			// 
			// btnDelete
			// 
			this->btnDelete->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->btnDelete->BackColor = System::Drawing::Color::Silver;
			this->btnDelete->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnDelete->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnDelete->Location = System::Drawing::Point(186, 418);
			this->btnDelete->Name = L"btnDelete";
			this->btnDelete->Size = System::Drawing::Size(107, 28);
			this->btnDelete->TabIndex = 28;
			this->btnDelete->Text = L"Удалить";
			this->btnDelete->UseVisualStyleBackColor = false;
			this->btnDelete->Click += gcnew System::EventHandler(this, &ClientForm::btnDelete_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->ForeColor = System::Drawing::Color::Black;
			this->label5->Location = System::Drawing::Point(587, 27);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(102, 19);
			this->label5->TabIndex = 27;
			this->label5->Text = L"В карантине:";
			// 
			// btnMoveToQuarantine
			// 
			this->btnMoveToQuarantine->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->btnMoveToQuarantine->BackColor = System::Drawing::Color::Silver;
			this->btnMoveToQuarantine->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnMoveToQuarantine->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnMoveToQuarantine->Location = System::Drawing::Point(695, 384);
			this->btnMoveToQuarantine->Name = L"btnMoveToQuarantine";
			this->btnMoveToQuarantine->Size = System::Drawing::Size(351, 28);
			this->btnMoveToQuarantine->TabIndex = 29;
			this->btnMoveToQuarantine->Text = L"Поместить в карантин";
			this->btnMoveToQuarantine->UseVisualStyleBackColor = false;
			this->btnMoveToQuarantine->Click += gcnew System::EventHandler(this, &ClientForm::btnMoveToQuarantine_Click);
			// 
			// QuarantineListBox
			// 
			this->QuarantineListBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->QuarantineListBox->BackColor = System::Drawing::Color::White;
			this->QuarantineListBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->QuarantineListBox->ForeColor = System::Drawing::Color::Black;
			this->QuarantineListBox->FormattingEnabled = true;
			this->QuarantineListBox->ItemHeight = 16;
			this->QuarantineListBox->Location = System::Drawing::Point(695, 27);
			this->QuarantineListBox->Name = L"QuarantineListBox";
			this->QuarantineListBox->Size = System::Drawing::Size(351, 338);
			this->QuarantineListBox->TabIndex = 26;
			// 
			// btnDeleteFromQuarantine
			// 
			this->btnDeleteFromQuarantine->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->btnDeleteFromQuarantine->BackColor = System::Drawing::Color::Silver;
			this->btnDeleteFromQuarantine->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnDeleteFromQuarantine->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 7.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->btnDeleteFromQuarantine->Location = System::Drawing::Point(695, 418);
			this->btnDeleteFromQuarantine->Name = L"btnDeleteFromQuarantine";
			this->btnDeleteFromQuarantine->Size = System::Drawing::Size(351, 28);
			this->btnDeleteFromQuarantine->TabIndex = 30;
			this->btnDeleteFromQuarantine->Text = L"Вернуть из карантина";
			this->btnDeleteFromQuarantine->UseVisualStyleBackColor = false;
			this->btnDeleteFromQuarantine->Click += gcnew System::EventHandler(this, &ClientForm::btnDeleteFromQuarantine_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->ForeColor = System::Drawing::Color::Black;
			this->label1->Location = System::Drawing::Point(6, 27);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(174, 19);
			this->label1->TabIndex = 24;
			this->label1->Text = L"Обнаруженные угрозы:";
			// 
			// reportListBox
			// 
			this->reportListBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->reportListBox->BackColor = System::Drawing::Color::White;
			this->reportListBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->reportListBox->ForeColor = System::Drawing::Color::Black;
			this->reportListBox->FormattingEnabled = true;
			this->reportListBox->ItemHeight = 16;
			this->reportListBox->Location = System::Drawing::Point(186, 27);
			this->reportListBox->Name = L"reportListBox";
			this->reportListBox->Size = System::Drawing::Size(346, 370);
			this->reportListBox->TabIndex = 25;
			// 
			// tabPage2
			// 
			this->tabPage2->BackColor = System::Drawing::Color::WhiteSmoke;
			this->tabPage2->Controls->Add(this->progressBar3);
			this->tabPage2->Controls->Add(this->label9);
			this->tabPage2->Controls->Add(this->label8);
			this->tabPage2->Controls->Add(this->txtMonitorRes);
			this->tabPage2->Controls->Add(this->txtMonitoringPath);
			this->tabPage2->Controls->Add(this->btnDelMonitoring);
			this->tabPage2->Controls->Add(this->btnSetMonitoring);
			this->tabPage2->Controls->Add(this->monitoringListBox);
			this->tabPage2->Controls->Add(this->label3);
			this->tabPage2->Controls->Add(this->btnBrowse2);
			this->tabPage2->Location = System::Drawing::Point(4, 25);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(1100, 478);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Мониторинг";
			// 
			// btnBrowse2
			// 
			this->btnBrowse2->BackColor = System::Drawing::Color::Silver;
			this->btnBrowse2->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnBrowse2->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnBrowse2->Location = System::Drawing::Point(721, 24);
			this->btnBrowse2->Name = L"btnBrowse2";
			this->btnBrowse2->Size = System::Drawing::Size(366, 27);
			this->btnBrowse2->TabIndex = 9;
			this->btnBrowse2->Text = L"Выбрать папку";
			this->btnBrowse2->UseVisualStyleBackColor = false;
			this->btnBrowse2->Click += gcnew System::EventHandler(this, &ClientForm::btnBrowse2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->ForeColor = System::Drawing::Color::Black;
			this->label3->Location = System::Drawing::Point(10, 29);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(117, 19);
			this->label3->TabIndex = 8;
			this->label3->Text = L"Выберите путь:";
			// 
			// txtMonitoringPath
			// 
			this->txtMonitoringPath->BackColor = System::Drawing::Color::White;
			this->txtMonitoringPath->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->txtMonitoringPath->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->txtMonitoringPath->ForeColor = System::Drawing::Color::Black;
			this->txtMonitoringPath->Location = System::Drawing::Point(274, 24);
			this->txtMonitoringPath->Name = L"txtMonitoringPath";
			this->txtMonitoringPath->ReadOnly = true;
			this->txtMonitoringPath->Size = System::Drawing::Size(428, 27);
			this->txtMonitoringPath->TabIndex = 7;
			// 
			// monitoringListBox
			// 
			this->monitoringListBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Right));
			this->monitoringListBox->BackColor = System::Drawing::Color::White;
			this->monitoringListBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->monitoringListBox->ForeColor = System::Drawing::Color::Black;
			this->monitoringListBox->FormattingEnabled = true;
			this->monitoringListBox->ItemHeight = 16;
			this->monitoringListBox->Location = System::Drawing::Point(274, 109);
			this->monitoringListBox->Name = L"monitoringListBox";
			this->monitoringListBox->Size = System::Drawing::Size(428, 98);
			this->monitoringListBox->TabIndex = 29;
			// 
			// btnSetMonitoring
			// 
			this->btnSetMonitoring->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->btnSetMonitoring->BackColor = System::Drawing::Color::Silver;
			this->btnSetMonitoring->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnSetMonitoring->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnSetMonitoring->Location = System::Drawing::Point(721, 71);
			this->btnSetMonitoring->Name = L"btnSetMonitoring";
			this->btnSetMonitoring->Size = System::Drawing::Size(170, 27);
			this->btnSetMonitoring->TabIndex = 30;
			this->btnSetMonitoring->Text = L"Установить мониторинг";
			this->btnSetMonitoring->UseVisualStyleBackColor = false;
			this->btnSetMonitoring->Click += gcnew System::EventHandler(this, &ClientForm::btnSetMonitoring_Click_1);
			// 
			// btnDelMonitoring
			// 
			this->btnDelMonitoring->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btnDelMonitoring->BackColor = System::Drawing::Color::Silver;
			this->btnDelMonitoring->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnDelMonitoring->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnDelMonitoring->Location = System::Drawing::Point(897, 71);
			this->btnDelMonitoring->Name = L"btnDelMonitoring";
			this->btnDelMonitoring->Size = System::Drawing::Size(193, 27);
			this->btnDelMonitoring->TabIndex = 31;
			this->btnDelMonitoring->Text = L"Отменить мониторинг";
			this->btnDelMonitoring->UseVisualStyleBackColor = false;
			this->btnDelMonitoring->Click += gcnew System::EventHandler(this, &ClientForm::btnDelMonitoring_Click);
			// 
			// txtMonitorRes
			// 
			this->txtMonitorRes->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->txtMonitorRes->BackColor = System::Drawing::Color::White;
			this->txtMonitorRes->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->txtMonitorRes->Font = (gcnew System::Drawing::Font(L"Calibri", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->txtMonitorRes->ForeColor = System::Drawing::Color::Black;
			this->txtMonitorRes->HideSelection = false;
			this->txtMonitorRes->Location = System::Drawing::Point(274, 223);
			this->txtMonitorRes->Name = L"txtMonitorRes";
			this->txtMonitorRes->ReadOnly = true;
			this->txtMonitorRes->Size = System::Drawing::Size(428, 197);
			this->txtMonitorRes->TabIndex = 32;
			this->txtMonitorRes->Text = L"";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label8->ForeColor = System::Drawing::Color::Black;
			this->label8->Location = System::Drawing::Point(6, 223);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(262, 19);
			this->label8->TabIndex = 33;
			this->label8->Text = L"Процесс последнего сканирования:";
			// 
			// label9
			// 
			this->label9->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label9->ForeColor = System::Drawing::Color::Black;
			this->label9->Location = System::Drawing::Point(6, 109);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(237, 19);
			this->label9->TabIndex = 34;
			this->label9->Text = L"Список папок для мониторинга:";
			// 
			// progressBar3
			// 
			this->progressBar3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->progressBar3->Location = System::Drawing::Point(274, 426);
			this->progressBar3->Name = L"progressBar3";
			this->progressBar3->Size = System::Drawing::Size(428, 28);
			this->progressBar3->TabIndex = 35;
			// 
			// tabPage3
			// 
			this->tabPage3->BackColor = System::Drawing::Color::WhiteSmoke;
			this->tabPage3->Controls->Add(this->label7);
			this->tabPage3->Controls->Add(this->label6);
			this->tabPage3->Controls->Add(this->progressBar2);
			this->tabPage3->Controls->Add(this->txtScheduleScanRes);
			this->tabPage3->Controls->Add(this->txtSchedulePath);
			this->tabPage3->Controls->Add(this->btnStopSchedule);
			this->tabPage3->Controls->Add(this->dateTimePicker);
			this->tabPage3->Controls->Add(this->scheduleListBox);
			this->tabPage3->Controls->Add(this->label4);
			this->tabPage3->Controls->Add(this->btnScheduleScan);
			this->tabPage3->Controls->Add(this->btnBrowse3);
			this->tabPage3->Location = System::Drawing::Point(4, 25);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Padding = System::Windows::Forms::Padding(3);
			this->tabPage3->Size = System::Drawing::Size(1100, 478);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"Сканирование по расписанию";
			// 
			// btnBrowse3
			// 
			this->btnBrowse3->BackColor = System::Drawing::Color::Silver;
			this->btnBrowse3->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnBrowse3->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnBrowse3->Location = System::Drawing::Point(828, 24);
			this->btnBrowse3->Name = L"btnBrowse3";
			this->btnBrowse3->Size = System::Drawing::Size(259, 27);
			this->btnBrowse3->TabIndex = 16;
			this->btnBrowse3->Text = L"Выбрать папку или файл";
			this->btnBrowse3->UseVisualStyleBackColor = false;
			this->btnBrowse3->Click += gcnew System::EventHandler(this, &ClientForm::btnBrowse3_Click);
			// 
			// btnScheduleScan
			// 
			this->btnScheduleScan->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->btnScheduleScan->BackColor = System::Drawing::Color::Silver;
			this->btnScheduleScan->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnScheduleScan->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnScheduleScan->Location = System::Drawing::Point(945, 66);
			this->btnScheduleScan->Name = L"btnScheduleScan";
			this->btnScheduleScan->Size = System::Drawing::Size(142, 27);
			this->btnScheduleScan->TabIndex = 13;
			this->btnScheduleScan->Text = L"Запланировать";
			this->btnScheduleScan->UseVisualStyleBackColor = false;
			this->btnScheduleScan->Click += gcnew System::EventHandler(this, &ClientForm::btnScheduleScan_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->ForeColor = System::Drawing::Color::Black;
			this->label4->Location = System::Drawing::Point(6, 29);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(151, 19);
			this->label4->TabIndex = 15;
			this->label4->Text = L"Путь сканирования:";
			// 
			// scheduleListBox
			// 
			this->scheduleListBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Right));
			this->scheduleListBox->BackColor = System::Drawing::Color::White;
			this->scheduleListBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->scheduleListBox->ForeColor = System::Drawing::Color::Black;
			this->scheduleListBox->FormattingEnabled = true;
			this->scheduleListBox->ItemHeight = 16;
			this->scheduleListBox->Location = System::Drawing::Point(269, 107);
			this->scheduleListBox->Name = L"scheduleListBox";
			this->scheduleListBox->Size = System::Drawing::Size(538, 82);
			this->scheduleListBox->Sorted = true;
			this->scheduleListBox->TabIndex = 17;
			// 
			// dateTimePicker
			// 
			this->dateTimePicker->CalendarFont = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->dateTimePicker->CalendarForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->dateTimePicker->CalendarMonthBackground = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->dateTimePicker->CalendarTitleBackColor = System::Drawing::SystemColors::ButtonShadow;
			this->dateTimePicker->CustomFormat = L"HH:mm";
			this->dateTimePicker->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->dateTimePicker->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->dateTimePicker->Location = System::Drawing::Point(828, 66);
			this->dateTimePicker->Name = L"dateTimePicker";
			this->dateTimePicker->ShowUpDown = true;
			this->dateTimePicker->Size = System::Drawing::Size(111, 27);
			this->dateTimePicker->TabIndex = 19;
			// 
			// btnStopSchedule
			// 
			this->btnStopSchedule->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->btnStopSchedule->BackColor = System::Drawing::Color::Silver;
			this->btnStopSchedule->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnStopSchedule->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnStopSchedule->Location = System::Drawing::Point(708, 444);
			this->btnStopSchedule->Name = L"btnStopSchedule";
			this->btnStopSchedule->Size = System::Drawing::Size(99, 27);
			this->btnStopSchedule->TabIndex = 20;
			this->btnStopSchedule->Text = L"Отменить";
			this->btnStopSchedule->UseVisualStyleBackColor = false;
			this->btnStopSchedule->Click += gcnew System::EventHandler(this, &ClientForm::btnStopSchedule_Click);
			// 
			// txtSchedulePath
			// 
			this->txtSchedulePath->BackColor = System::Drawing::Color::White;
			this->txtSchedulePath->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->txtSchedulePath->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->txtSchedulePath->ForeColor = System::Drawing::Color::Black;
			this->txtSchedulePath->Location = System::Drawing::Point(269, 24);
			this->txtSchedulePath->Name = L"txtSchedulePath";
			this->txtSchedulePath->ReadOnly = true;
			this->txtSchedulePath->Size = System::Drawing::Size(538, 27);
			this->txtSchedulePath->TabIndex = 14;
			// 
			// txtScheduleScanRes
			// 
			this->txtScheduleScanRes->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->txtScheduleScanRes->BackColor = System::Drawing::Color::White;
			this->txtScheduleScanRes->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->txtScheduleScanRes->Font = (gcnew System::Drawing::Font(L"Calibri", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->txtScheduleScanRes->ForeColor = System::Drawing::Color::Black;
			this->txtScheduleScanRes->HideSelection = false;
			this->txtScheduleScanRes->Location = System::Drawing::Point(269, 203);
			this->txtScheduleScanRes->Name = L"txtScheduleScanRes";
			this->txtScheduleScanRes->ReadOnly = true;
			this->txtScheduleScanRes->Size = System::Drawing::Size(538, 235);
			this->txtScheduleScanRes->TabIndex = 22;
			this->txtScheduleScanRes->Text = L"";
			// 
			// progressBar2
			// 
			this->progressBar2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->progressBar2->Location = System::Drawing::Point(269, 444);
			this->progressBar2->Name = L"progressBar2";
			this->progressBar2->Size = System::Drawing::Size(422, 28);
			this->progressBar2->TabIndex = 21;
			// 
			// label6
			// 
			this->label6->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->ForeColor = System::Drawing::Color::Black;
			this->label6->Location = System::Drawing::Point(6, 107);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(204, 19);
			this->label6->TabIndex = 23;
			this->label6->Text = L"Расписание сканирований:";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label7->ForeColor = System::Drawing::Color::Black;
			this->label7->Location = System::Drawing::Point(1, 203);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(262, 19);
			this->label7->TabIndex = 24;
			this->label7->Text = L"Процесс последнего сканирования:";
			// 
			// tabPage1
			// 
			this->tabPage1->BackColor = System::Drawing::Color::WhiteSmoke;
			this->tabPage1->Controls->Add(this->label11);
			this->tabPage1->Controls->Add(this->label10);
			this->tabPage1->Controls->Add(this->btnBrowseFile);
			this->tabPage1->Controls->Add(this->btnStopScan);
			this->tabPage1->Controls->Add(this->progressBar1);
			this->tabPage1->Controls->Add(this->txtScanPath);
			this->tabPage1->Controls->Add(this->txtScanRes);
			this->tabPage1->Controls->Add(this->label2);
			this->tabPage1->Controls->Add(this->btnStartScan);
			this->tabPage1->Controls->Add(this->btnBrowseFolder);
			this->tabPage1->Location = System::Drawing::Point(4, 25);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(1100, 478);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Сканирование";
			// 
			// btnBrowseFolder
			// 
			this->btnBrowseFolder->BackColor = System::Drawing::Color::Silver;
			this->btnBrowseFolder->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnBrowseFolder->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnBrowseFolder->Location = System::Drawing::Point(954, 19);
			this->btnBrowseFolder->Name = L"btnBrowseFolder";
			this->btnBrowseFolder->Size = System::Drawing::Size(117, 27);
			this->btnBrowseFolder->TabIndex = 5;
			this->btnBrowseFolder->Text = L"Выбрать папку";
			this->btnBrowseFolder->UseVisualStyleBackColor = false;
			this->btnBrowseFolder->Click += gcnew System::EventHandler(this, &ClientForm::btnBrowse_Click);
			// 
			// btnStartScan
			// 
			this->btnStartScan->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->btnStartScan->BackColor = System::Drawing::Color::Silver;
			this->btnStartScan->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnStartScan->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnStartScan->Location = System::Drawing::Point(224, 394);
			this->btnStartScan->Name = L"btnStartScan";
			this->btnStartScan->Size = System::Drawing::Size(354, 37);
			this->btnStartScan->TabIndex = 0;
			this->btnStartScan->Text = L"Начать сканирование";
			this->btnStartScan->UseVisualStyleBackColor = false;
			this->btnStartScan->Click += gcnew System::EventHandler(this, &ClientForm::btnStartScan_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::WhiteSmoke;
			this->label2->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->ForeColor = System::Drawing::Color::Black;
			this->label2->Location = System::Drawing::Point(3, 23);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(151, 19);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Путь сканирования:";
			// 
			// txtScanRes
			// 
			this->txtScanRes->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->txtScanRes->BackColor = System::Drawing::Color::White;
			this->txtScanRes->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->txtScanRes->Font = (gcnew System::Drawing::Font(L"Calibri", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->txtScanRes->ForeColor = System::Drawing::Color::Black;
			this->txtScanRes->HideSelection = false;
			this->txtScanRes->Location = System::Drawing::Point(224, 52);
			this->txtScanRes->Name = L"txtScanRes";
			this->txtScanRes->ReadOnly = true;
			this->txtScanRes->Size = System::Drawing::Size(847, 291);
			this->txtScanRes->TabIndex = 15;
			this->txtScanRes->Text = L"";
			// 
			// txtScanPath
			// 
			this->txtScanPath->BackColor = System::Drawing::Color::White;
			this->txtScanPath->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->txtScanPath->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->txtScanPath->ForeColor = System::Drawing::Color::Black;
			this->txtScanPath->Location = System::Drawing::Point(224, 19);
			this->txtScanPath->Name = L"txtScanPath";
			this->txtScanPath->ReadOnly = true;
			this->txtScanPath->Size = System::Drawing::Size(601, 27);
			this->txtScanPath->TabIndex = 2;
			// 
			// progressBar1
			// 
			this->progressBar1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->progressBar1->Location = System::Drawing::Point(224, 349);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(847, 28);
			this->progressBar1->TabIndex = 13;
			// 
			// btnStopScan
			// 
			this->btnStopScan->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btnStopScan->BackColor = System::Drawing::Color::Silver;
			this->btnStopScan->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnStopScan->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnStopScan->Location = System::Drawing::Point(710, 394);
			this->btnStopScan->Name = L"btnStopScan";
			this->btnStopScan->Size = System::Drawing::Size(361, 37);
			this->btnStopScan->TabIndex = 14;
			this->btnStopScan->Text = L"Остановить сканирование";
			this->btnStopScan->UseVisualStyleBackColor = false;
			this->btnStopScan->Click += gcnew System::EventHandler(this, &ClientForm::btnStopScan_Click);
			// 
			// btnBrowseFile
			// 
			this->btnBrowseFile->BackColor = System::Drawing::Color::Silver;
			this->btnBrowseFile->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnBrowseFile->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnBrowseFile->Location = System::Drawing::Point(831, 19);
			this->btnBrowseFile->Name = L"btnBrowseFile";
			this->btnBrowseFile->Size = System::Drawing::Size(117, 27);
			this->btnBrowseFile->TabIndex = 16;
			this->btnBrowseFile->Text = L"Выбрать файл";
			this->btnBrowseFile->UseVisualStyleBackColor = false;
			this->btnBrowseFile->Click += gcnew System::EventHandler(this, &ClientForm::btnBrowseFile_Click);
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label10->Location = System::Drawing::Point(3, 52);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(215, 19);
			this->label10->TabIndex = 17;
			this->label10->Text = L"Отсканированные элементы:";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label11->Location = System::Drawing::Point(7, 346);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(183, 19);
			this->label11->TabIndex = 18;
			this->label11->Text = L"Прогресс сканирования:";
			// 
			// tabControl1
			// 
			this->tabControl1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Controls->Add(this->tabPage4);
			this->tabControl1->Location = System::Drawing::Point(-5, 0);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(1108, 507);
			this->tabControl1->TabIndex = 6;
			// 
			// ClientForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::WhiteSmoke;
			this->ClientSize = System::Drawing::Size(1098, 548);
			this->Controls->Add(this->btnStopService);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->btnStartService);
			this->MinimumSize = System::Drawing::Size(1050, 300);
			this->Name = L"ClientForm";
			this->Text = L"Антивирус";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &ClientForm::ClientForm_FormClosed);
			this->Load += gcnew System::EventHandler(this, &ClientForm::ClientForm_Load);
			this->tabPage4->ResumeLayout(false);
			this->tabPage4->PerformLayout();
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
			this->tabPage3->ResumeLayout(false);
			this->tabPage3->PerformLayout();
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			this->tabControl1->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void ClientForm_Load(System::Object^ sender, System::EventArgs^ e)
	{
		Thread^ thread = gcnew Thread(gcnew ThreadStart(this, &ClientForm::createPipeAndListening));
		thread->IsBackground = true;
		thread->Start();
	}

	private: bool createPipeForRead()
	{
		pipeForRead = CreateNamedPipe(
			PIPE_SERVICE_TO_CLIENT_NAME,             // имя канала 
			PIPE_ACCESS_DUPLEX,       // чтение/запись доступ 
			PIPE_TYPE_MESSAGE |       // тип сообщения каналу 
			PIPE_READMODE_MESSAGE |   // режим чтения сообщений 
			PIPE_WAIT,                // режим блокирования
			PIPE_UNLIMITED_INSTANCES, // максимальное количество экземпляров 
			PIPE_BUFSIZE,                  // размер буфера на выход 
			PIPE_BUFSIZE,                  // размер буфера на вход 
			0,                        // клиент время 
			NULL);                    // атрибут безопасности по умолчанию 

		if (pipeForRead == INVALID_HANDLE_VALUE)
		{
			//MessageBox::Show("Нет соединения с сервером\r\nКод ошибки: " + GetLastError().ToString(), "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			FlushFileBuffers(pipeForRead);
			DisconnectNamedPipe(pipeForRead);
			CloseHandle(pipeForRead);
			//createPipeForSend();
			return false;
		}
		return true;
	}

	private: bool createPipeForSend()
	{
		pipeForSend = NULL;
		CloseHandle(pipeForSend);

		if (pipeForSend == NULL)
			pipeForSend = CreateFile(
				PIPE_CLIENT_TO_SERVICE_NAME,   // pipe name 
				GENERIC_READ |  // read and write access 
				GENERIC_WRITE,
				0,              // no sharing 
				NULL,           // default security attributes
				OPEN_EXISTING,  // opens existing pipe 
				0,              // default attributes 
				NULL);          // no template file 

		  // Break if the pipe handle is valid.
		if (pipeForSend == INVALID_HANDLE_VALUE)
		{
			CloseHandle(pipeForSend);
			//MessageBox::Show("Нет соединения с сервером\r\n" + GetLastError().ToString(), "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			pipeForSend = NULL;
			return false;
		}

		// Exit if an error other than ERROR_PIPE_BUSY occurs.
		if (GetLastError() == ERROR_PIPE_BUSY)
		{
			CloseHandle(pipeForSend);
			//MessageBox::Show("Нет соединения с сервером\r\n" + GetLastError().ToString(), "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			pipeForSend = NULL;
			return false;
		}

		// Exit if an error other than ERROR_PIPE_BUSY occurs.
		if (GetLastError() == ERROR_BROKEN_PIPE)
		{
			CloseHandle(pipeForSend);
			//MessageBox::Show("Нет соединения с сервером\r\n" + GetLastError().ToString(), "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			pipeForSend = NULL;
			return false;
		}

		if (GetLastError() == ERROR_FILE_NOT_FOUND)
		{
			CloseHandle(pipeForSend);
			//MessageBox::Show("Нет соединения с сервером\r\n" + GetLastError().ToString(), "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			pipeForSend = NULL;
			return false;
		}
		if (!GetLastError())
			return true;
	}

	void createPipeAndListening()
	{
		bool fConnected6 = false;
		while (!fConnected6)
		{
			fConnected6 = createPipeForSend();

		}
		createPipeForRead();

		// Подождите, пока клиент подключится; если это удастся,
		// функция возвращает ненулевое значение. Если функция
		// возвращает ноль, GetLastError возвращает ERROR_PIPE_CONNECTED.
		BOOL fConnected = ConnectNamedPipe(pipeForRead, NULL) ?
			TRUE : (GetLastError() == ERROR_PIPE_CONNECTED);
		message messagefromService;
		while (fConnected)
		{
			fConnected = ConnectNamedPipe(pipeForRead, NULL) ?
				TRUE : (GetLastError() == ERROR_PIPE_CONNECTED);
			if (!fConnected)
			{
				//MessageBox::Show("Нет соединения с сервером\r\n" + GetLastError().ToString(), "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
				FlushFileBuffers(pipeForRead);
				DisconnectNamedPipe(pipeForRead);
				CloseHandle(pipeForRead);
			}
			messagefromService = Messenger::readMessage(pipeForRead, PIPE_BUFSIZE);
			if (messagefromService.cmd == COMMAND::UNKNOWN)
			{				
				MessageBox::Show("Сервис был остановлен", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
				progressBar1->Value = 0;
				progressBar2->Value = 0;
				progressBar3->Value = 0;
				txtScanRes->Clear();
				txtScheduleScanRes->Clear();
				txtMonitorRes->Clear();
				monitoringListBox->Items->Clear();
				scheduleListBox->Items->Clear();
				bool fConnected2 = false, fConnected3 = false;
				while (!fConnected2)
				{
					fConnected2 = createPipeForSend();

				}
				while (!fConnected3)
				{
					fConnected3 = createPipeForRead();

				}
				
			}
			messageProcessing(messagefromService);
		}
		
		//progressBar1->Value = 0;

		//CloseHandle(pipeForRead);
		//createPipeForSend();
		//Thread^ thread = gcnew Thread(gcnew ThreadStart(this, &ClientForm::createPipeAndListening));
		//thread->IsBackground = true;
		//thread->Start();
		//createPipeAndListening();
	}		

	void messageProcessing(message msg)
	{
		switch (msg.cmd)
		{
			case COMMAND::INFO: {
				if (msg.nArr.at(0) == 0) {
					reportListBox->Items->Clear();
					for (size_t i = 0; i < msg.sArr.size(); i += 2)
					{
						if (!reportListBox->Items->Contains(msclr::interop::marshal_as<String^>(msg.sArr.at(i + 1)) + "\t" + msclr::interop::marshal_as<String^>(msg.sArr.at(i))))
							reportListBox->Items->Add(msclr::interop::marshal_as<String^>(msg.sArr.at(i + 1)) + "\t" + msclr::interop::marshal_as<String^>(msg.sArr.at(i)));
					}
				}
				if (msg.nArr.at(0) == 1) {
					QuarantineListBox->Items->Clear();
					for (size_t i = 0; i < msg.sArr.size(); i += 2)
					{
						if (!QuarantineListBox->Items->Contains(msclr::interop::marshal_as<String^>(msg.sArr.at(i + 1)) + "\t" + msclr::interop::marshal_as<String^>(msg.sArr.at(i))))
							QuarantineListBox->Items->Add(msclr::interop::marshal_as<String^>(msg.sArr.at(i + 1)) + "\t" + msclr::interop::marshal_as<String^>(msg.sArr.at(i)));
					}
				}
				break;
			}
		   case COMMAND::START: {
			   if (!msg.nArr.empty())
			   {
				   progressBar1->Maximum = msg.nArr.at(0);
			   }
			   else
			   {
				   txtScanRes->AppendText(msclr::interop::marshal_as<String^>(msg.sArr.at(0)));
				   txtScanRes->AppendText("\t\t\t");
				   txtScanRes->AppendText(msclr::interop::marshal_as<String^>(msg.sArr.at(1)));
				   txtScanRes->AppendText("\r\n");
				   progressBar1->Increment(1);
				   if (msclr::interop::marshal_as<String^>(msg.sArr.at(1))->Contains("вредонос"))
				   {
					   if (!reportListBox->Items->Contains(msclr::interop::marshal_as<String^>(msg.sArr.at(1)) + "\t" + msclr::interop::marshal_as<String^>(msg.sArr.at(0))))
						   reportListBox->Items->Add(msclr::interop::marshal_as<String^>(msg.sArr.at(1)) + "\t" + msclr::interop::marshal_as<String^>(msg.sArr.at(0)));
				   }
	
			   }
			   break;
		   }
		   case COMMAND::SCHEDULE_START: {
			   if (!msg.nArr.empty())
			   {
				   progressBar2->Maximum = msg.nArr.at(0);
				   if (scheduleListBox->Items->Count > 0)
					   scheduleListBox->Items->RemoveAt(0);
			   }
			   else
			   {
				   txtScheduleScanRes->AppendText(msclr::interop::marshal_as<String^>(msg.sArr.at(0)));
				   txtScheduleScanRes->AppendText("\t\t\t");
				   txtScheduleScanRes->AppendText(msclr::interop::marshal_as<String^>(msg.sArr.at(1)));
				   txtScheduleScanRes->AppendText("\r\n");
				   progressBar2->Increment(1);
				   if (msclr::interop::marshal_as<String^>(msg.sArr.at(1))->Contains("вредонос"))
				   {
					   if (!reportListBox->Items->Contains(msclr::interop::marshal_as<String^>(msg.sArr.at(1)) + "\t" + msclr::interop::marshal_as<String^>(msg.sArr.at(0))))
						   reportListBox->Items->Add(msclr::interop::marshal_as<String^>(msg.sArr.at(1)) + "\t" + msclr::interop::marshal_as<String^>(msg.sArr.at(0)));
				   }
	
			   }
			   break;
		   }

		   case COMMAND::SET_MONITORING: {
			   if (!msg.nArr.empty())
			   {
				   progressBar3->Value = 0;
				   txtMonitorRes->Clear();
				   progressBar3->Maximum = msg.nArr.at(0);
			   }
			   else
			   {
				   txtMonitorRes->AppendText(msclr::interop::marshal_as<String^>(msg.sArr.at(0)));
				   txtMonitorRes->AppendText("\t\t\t");
				   txtMonitorRes->AppendText(msclr::interop::marshal_as<String^>(msg.sArr.at(1)));
				   txtMonitorRes->AppendText("\r\n");
				   progressBar3->Increment(1);
				   if (msclr::interop::marshal_as<String^>(msg.sArr.at(1))->Contains("вредонос"))
				   {
					   if (!reportListBox->Items->Contains(msclr::interop::marshal_as<String^>(msg.sArr.at(1)) + "\t" + msclr::interop::marshal_as<String^>(msg.sArr.at(0))))
						   reportListBox->Items->Add(msclr::interop::marshal_as<String^>(msg.sArr.at(1)) + "\t" + msclr::interop::marshal_as<String^>(msg.sArr.at(0)));
				   }

			   }
			   break;
		   }
		   case COMMAND::STOP: {
			   btnBrowseFile->Enabled = true;
			   btnBrowseFolder->Enabled = true;
			   btnStartScan->Enabled = true;
			   progressBar1->Value = 0;
			   txtScanRes->Clear();
			   MessageBox::Show("Сканирование остановлено\r\nКоличество просканированных файлов: " + msg.nArr.at(0) + "\r\nУгроз: " + msg.nArr.at(1), "Информация", MessageBoxButtons::OK, MessageBoxIcon::Information);
			   break;
		   }
		   case COMMAND::SCAN_RESULT: {
			   btnBrowseFile->Enabled = true;
			   btnBrowseFolder->Enabled = true;
			   btnStartScan->Enabled = true;
			   //progressBar1->Value = 0;
			   txtScanRes->AppendText("\r\nКоличество просканированных файлов: " + msg.nArr.at(0) + "\r\nУгроз: " + msg.nArr.at(1) + "\r\n");
			   MessageBox::Show("Сканирование успешно завершилось!\r\nКоличество просканированных файлов: " + msg.nArr.at(0) + "\r\nУгроз: " + msg.nArr.at(1), "Информация", MessageBoxButtons::OK, MessageBoxIcon::Information);
			   break;
		   }
		   case COMMAND::SCHEDULE_SCAN_RESULT: {
			   //progressBar2->Value = 0;
			   txtScheduleScanRes->AppendText("\r\nКоличество просканированных файлов: " + msg.nArr.at(0) + "\r\nУгроз: " + msg.nArr.at(1) + "\r\n");
			   MessageBox::Show("Запланированное сканирование успешно завершилось!\r\nКоличество просканированных файлов: " + msg.nArr.at(0) + "\r\nУгроз: " + msg.nArr.at(1), "Информация", MessageBoxButtons::OK, MessageBoxIcon::Information);
			   break;
		   }
		   case COMMAND::MONITORING_RESULT: {
			   //progressBar3->Value = 0;
			   txtMonitorRes->AppendText("\r\nКоличество просканированных файлов: " + msg.nArr.at(0) + "\r\nУгроз: " + msg.nArr.at(1) + "\r\n");
			   MessageBox::Show("Содержимое папки было изменено, папка успешно просканирована\r\nКоличество просканированных файлов: " + msg.nArr.at(0) + "\r\nУгроз: " + msg.nArr.at(1), "Информация", MessageBoxButtons::OK, MessageBoxIcon::Information);
			   break;
		   }
		   case COMMAND::RESET_SCHEDULE: {
			   MessageBox::Show("Запланированная проверка отменена", "Информация", MessageBoxButtons::OK, MessageBoxIcon::Information);
			   if (scheduleListBox->Items->Count > 0)
				   scheduleListBox->Items->Clear();
			   progressBar2->Value = 0;
			   txtScheduleScanRes->Clear();
			   break;
		   }
		}
	}

	private: System::Void btnStartScan_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (String::IsNullOrWhiteSpace(txtScanPath->Text))
		{
			MessageBox::Show("Выберите файл или папку для сканирования", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		btnBrowseFile->Enabled = false;
		btnBrowseFolder->Enabled = false;
		btnStartScan->Enabled = false;
		txtScanRes->Clear();
		progressBar1->Value = 0;
		message startScanMsg;
		std::string path = msclr::interop::marshal_as<std::string>(txtScanPath->Text);
		startScanMsg.cmd = COMMAND::START;
		startScanMsg.sArr.push_back(path);
		Messenger::sendMessage(pipeForSend, PIPE_BUFSIZE, startScanMsg);	
		txtScanPath->Clear();
	}

	private: System::Void btnBrowseFile_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (openFD->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			txtScanPath->Text = openFD->FileName;
		}
	}

	private: System::Void btnStopScan_Click(System::Object^ sender, System::EventArgs^ e)
	{
		message startScanMsg;
		startScanMsg.cmd = COMMAND::STOP;
		Messenger::sendMessage(pipeForSend, PIPE_BUFSIZE, startScanMsg);
	}
	private: System::Void btnStopSchedule_Click(System::Object^ sender, System::EventArgs^ e)
	{
		message stopSchedule;
		stopSchedule.cmd = COMMAND::RESET_SCHEDULE;
		Messenger::sendMessage(pipeForSend, PIPE_BUFSIZE, stopSchedule);
		MessageBox::Show("Запланированная проверка будет отменена в течении 30 секунд", "Информация", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}

	private: System::Void btnSetMonitoring_Click_1(System::Object^ sender, System::EventArgs^ e)
	{
		monitoringListBox->Items->Add(txtMonitoringPath->Text);
		message monitoringMessage;
		monitoringMessage.sArr.push_back(msclr::interop::marshal_as<std::string>(txtMonitoringPath->Text));
		monitoringMessage.cmd = COMMAND::SET_MONITORING;
		Messenger::sendMessage(pipeForSend, PIPE_BUFSIZE, monitoringMessage);
		txtMonitoringPath->Clear();
	}

	private: System::Void btnDelMonitoring_Click(System::Object^ sender, System::EventArgs^ e)
	{
		txtMonitoringPath->Clear();
		message monitoringMessage;
		monitoringMessage.cmd = COMMAND::STOP_MONITORING;
		Messenger::sendMessage(pipeForSend, PIPE_BUFSIZE, monitoringMessage);
		monitoringListBox->Items->Clear();
		MessageBox::Show("Мониторинг отменён", "Информация", MessageBoxButtons::OK, MessageBoxIcon::Information);

	}
	
	private: System::Void btnBrowse_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (folderBrowserDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			txtScanPath->Text = folderBrowserDialog->SelectedPath;
		}
	}

	private: System::Void btnBrowse2_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (folderBrowserDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			txtMonitoringPath->Text = folderBrowserDialog->SelectedPath;
		}
	}

	private: System::Void btnBrowse3_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (folderBrowserDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {

			txtSchedulePath->Text = folderBrowserDialog->SelectedPath;
			dateTimePicker->Value = dateTimePicker->Value.AddMinutes(1);
		}
	}

	private: System::Void btnScheduleScan_Click(System::Object^ sender, System::EventArgs^ e)
	{
		txtScheduleScanRes->Clear();
		if (String::IsNullOrEmpty(txtSchedulePath->Text))
		{
			MessageBox::Show("Выберите файл или папку для сканирования", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		scheduleListBox->Items->Add(dateTimePicker->Value.ToShortTimeString() + "\t" + txtSchedulePath->Text);
		message scheduleMsg;
		scheduleMsg.cmd = COMMAND::SET_SCHEDULE;
		scheduleMsg.sArr.push_back(msclr::interop::marshal_as<std::string>(txtSchedulePath->Text));
		scheduleMsg.nArr.push_back(dateTimePicker->Value.Hour);
		scheduleMsg.nArr.push_back(dateTimePicker->Value.Minute);
		Messenger::sendMessage(pipeForSend, PIPE_BUFSIZE, scheduleMsg);
		txtSchedulePath->Clear();
		progressBar2->Value = 0;
		monitoringListBox->Items->Clear();
	}

	private: System::Void btnStartService_Click(System::Object^ sender, System::EventArgs^ e)
	{
		SC_HANDLE schSCManager = OpenSCManager(
			NULL,                    // local computer
			NULL,                    // ServicesActive database 
			SC_MANAGER_CONNECT);

		if (NULL == schSCManager)
		{
			HRESULT error = GetLastError();
			printf("OpenSCManager failed (%d)\n", error);
			return;
		}

		SC_HANDLE schService = OpenService(
			schSCManager,         // SCM database 
			L"AntivirusService",            // name of service 
			SERVICE_START |
			SERVICE_QUERY_STATUS |
			SERVICE_ENUMERATE_DEPENDENTS);

		if (schService == NULL)
		{
			printf("OpenService failed (%d)\n", GetLastError());
			CloseServiceHandle(schSCManager);
			return;
		}

		StartService(schService, NULL, NULL);

		MessageBox::Show("Сервис запущен", "Информация", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}

	private: System::Void btnStopService_Click(System::Object^ sender, System::EventArgs^ e)
	{
		message doStopMsg;
		doStopMsg.cmd = COMMAND::STOP_SERVICE;
		Messenger::sendMessage(pipeForSend, PIPE_BUFSIZE, doStopMsg);
	}

	private: System::Void ClientForm_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e)
	{
		FlushFileBuffers(pipeForSend);
		DisconnectNamedPipe(pipeForSend);
		//CloseHandle(pipeForSend);
	}

private: System::Void btnDelete_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (reportListBox->SelectedItems->Count == 0)
	{
		MessageBox::Show("Выберите файл для удаления", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}
	message delMsg;
	delMsg.cmd = COMMAND::DEL;
	String^ threatText = reportListBox->SelectedItem->ToString();
	array<String^>^ threatTextArr = threatText->Split('\t');
	String^ nameMessage = threatTextArr->GetValue(0)->ToString();
	String^ pathMessage = threatTextArr->GetValue(1)->ToString();
	delMsg.sArr.push_back(msclr::interop::marshal_as<std::string>(pathMessage));
	delMsg.sArr.push_back(msclr::interop::marshal_as<std::string>(nameMessage));
	Messenger::sendMessage(pipeForSend, PIPE_BUFSIZE, delMsg);
	reportListBox->Items->Remove(reportListBox->SelectedItem);
}
private: System::Void btnMoveToQuarantine_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (reportListBox->SelectedItems->Count == 0)
	{
		MessageBox::Show("Выберите файл для помещения в карантин", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}
	message quarMsg;
	quarMsg.cmd = COMMAND::MOVE_TO_QUARANTINE;
	String^ threatText = reportListBox->SelectedItem->ToString();
	array<String^>^ threatTextArr = threatText->Split('\t');
	String^ nameMessage = threatTextArr->GetValue(0)->ToString();
	String^ pathMessage = threatTextArr->GetValue(1)->ToString();
	quarMsg.sArr.push_back(msclr::interop::marshal_as<std::string>(pathMessage));
	quarMsg.sArr.push_back(msclr::interop::marshal_as<std::string>(nameMessage));
	Messenger::sendMessage(pipeForSend, PIPE_BUFSIZE, quarMsg);
	QuarantineListBox->Items->Add(reportListBox->SelectedItem);
	reportListBox->Items->Remove(reportListBox->SelectedItem);
}
private: System::Void btnDeleteFromQuarantine_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (QuarantineListBox->SelectedItems->Count == 0)
	{
		MessageBox::Show("Выберите файл для возврата из карантина", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}
	message delFromQuarMsg;
	delFromQuarMsg.cmd = COMMAND::DELETE_FROM_QUARANTINE;
	String^ threatText = QuarantineListBox->SelectedItem->ToString();
	array<String^>^ threatTextArr = threatText->Split('\t');
	String^ nameMessage = threatTextArr->GetValue(0)->ToString();
	String^ pathMessage = threatTextArr->GetValue(1)->ToString();
	delFromQuarMsg.sArr.push_back(msclr::interop::marshal_as<std::string>(pathMessage));
	delFromQuarMsg.sArr.push_back(msclr::interop::marshal_as<std::string>(nameMessage));
	Messenger::sendMessage(pipeForSend, PIPE_BUFSIZE, delFromQuarMsg);
	reportListBox->Items->Add(QuarantineListBox->SelectedItem);
	QuarantineListBox->Items->Remove(QuarantineListBox->SelectedItem);
}
private: System::Void tabPage5_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
