#pragma once

#include "NNPoint.h"
#include "NNPoints.h"
#include "NeuralNetwork.h"

#define LEARNING_CONSTANT 0.6
#define MAX_ERROR 0.01
#define DECIMAL_POINT 8
#define CLASS_COUNT 8
#define MOMENTUM_CONSTANT 0.4

#define FALSE 0
#define TRUE  1

namespace MulticategoryMultilayerNeuralNetwork {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for GUI
	/// </summary>
	public ref class GUI : public System::Windows::Forms::Form
	{
	public:
		GUI(void)
		{
			InitializeComponent();

			this->activation_function = UNIPOLAR_SIGMOID;

			this->points = new NNPoints();
			this->region_points = new NNPoints();

			this->normalized = false;
			this->stop_training = false;

			this->class1_selected = FALSE;
			this->class2_selected = FALSE;
			this->class3_selected = FALSE;
			this->class4_selected = FALSE;
			this->class5_selected = FALSE;
			this->class6_selected = FALSE;
			this->class7_selected = FALSE;
			this->class8_selected = FALSE;

			this->class_num = 0;

		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~GUI()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	protected:

	private:
		NNPoints* points;
		NNPoints* region_points;
		NeuralNetwork* neuralnetwork;
		bool normalized;
		bool stop_training;
		int activation_function;
		int class1_selected;
		int class2_selected;
		int class3_selected;
		int class4_selected;
		int class5_selected;
		int class6_selected;
		int class7_selected;
		int class8_selected;
		int class_num;

	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::RadioButton^  radioButton2;
	private: System::Windows::Forms::RadioButton^  radioButton1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::RadioButton^  radioButton6;
	private: System::Windows::Forms::RadioButton^  radioButton5;
	private: System::Windows::Forms::RadioButton^  radioButton4;
	private: System::Windows::Forms::RadioButton^  radioButton3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::GroupBox^  groupBox4;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::ListBox^  listBox1;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  startTrainingToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  normalizeDataToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  clearToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  stopTrainingToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  showRegionsToolStripMenuItem;
	private: System::Windows::Forms::RadioButton^  radioButton10;
	private: System::Windows::Forms::RadioButton^  radioButton9;
	private: System::Windows::Forms::RadioButton^  radioButton8;
	private: System::Windows::Forms::RadioButton^  radioButton7;



			 System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
			 /// <summary>
			 /// Required method for Designer support - do not modify
			 /// the contents of this method with the code editor.
			 /// </summary>
			 void InitializeComponent(void)
			 {
				 this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
				 this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
				 this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
				 this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
				 this->label1 = (gcnew System::Windows::Forms::Label());
				 this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
				 this->radioButton10 = (gcnew System::Windows::Forms::RadioButton());
				 this->radioButton9 = (gcnew System::Windows::Forms::RadioButton());
				 this->radioButton8 = (gcnew System::Windows::Forms::RadioButton());
				 this->radioButton7 = (gcnew System::Windows::Forms::RadioButton());
				 this->radioButton6 = (gcnew System::Windows::Forms::RadioButton());
				 this->radioButton5 = (gcnew System::Windows::Forms::RadioButton());
				 this->radioButton4 = (gcnew System::Windows::Forms::RadioButton());
				 this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
				 this->label2 = (gcnew System::Windows::Forms::Label());
				 this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
				 this->label7 = (gcnew System::Windows::Forms::Label());
				 this->label6 = (gcnew System::Windows::Forms::Label());
				 this->label5 = (gcnew System::Windows::Forms::Label());
				 this->label4 = (gcnew System::Windows::Forms::Label());
				 this->label3 = (gcnew System::Windows::Forms::Label());
				 this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
				 this->label13 = (gcnew System::Windows::Forms::Label());
				 this->label12 = (gcnew System::Windows::Forms::Label());
				 this->label11 = (gcnew System::Windows::Forms::Label());
				 this->label10 = (gcnew System::Windows::Forms::Label());
				 this->listBox1 = (gcnew System::Windows::Forms::ListBox());
				 this->label9 = (gcnew System::Windows::Forms::Label());
				 this->label8 = (gcnew System::Windows::Forms::Label());
				 this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
				 this->startTrainingToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->normalizeDataToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->clearToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->stopTrainingToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->showRegionsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
				 this->groupBox1->SuspendLayout();
				 this->groupBox2->SuspendLayout();
				 this->groupBox3->SuspendLayout();
				 this->groupBox4->SuspendLayout();
				 this->menuStrip1->SuspendLayout();
				 this->SuspendLayout();
				 // 
				 // pictureBox1
				 // 
				 this->pictureBox1->Location = System::Drawing::Point(50, 33);
				 this->pictureBox1->Name = L"pictureBox1";
				 this->pictureBox1->Size = System::Drawing::Size(400, 400);
				 this->pictureBox1->TabIndex = 0;
				 this->pictureBox1->TabStop = false;
				 this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &GUI::pictureBox1_DrawPlane);
				 this->pictureBox1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &GUI::pictureBox1_MouseClick);
				 // 
				 // groupBox1
				 // 
				 this->groupBox1->Controls->Add(this->radioButton2);
				 this->groupBox1->Controls->Add(this->radioButton1);
				 this->groupBox1->Location = System::Drawing::Point(513, 61);
				 this->groupBox1->Name = L"groupBox1";
				 this->groupBox1->Size = System::Drawing::Size(341, 49);
				 this->groupBox1->TabIndex = 1;
				 this->groupBox1->TabStop = false;
				 // 
				 // radioButton2
				 // 
				 this->radioButton2->AutoSize = true;
				 this->radioButton2->Location = System::Drawing::Point(217, 19);
				 this->radioButton2->Name = L"radioButton2";
				 this->radioButton2->Size = System::Drawing::Size(97, 17);
				 this->radioButton2->TabIndex = 1;
				 this->radioButton2->Text = L"Bipolar Sigmoid";
				 this->radioButton2->UseVisualStyleBackColor = true;
				 this->radioButton2->CheckedChanged += gcnew System::EventHandler(this, &GUI::radioButton2_CheckedChanged);
				 // 
				 // radioButton1
				 // 
				 this->radioButton1->AutoSize = true;
				 this->radioButton1->Checked = true;
				 this->radioButton1->Location = System::Drawing::Point(28, 19);
				 this->radioButton1->Name = L"radioButton1";
				 this->radioButton1->Size = System::Drawing::Size(104, 17);
				 this->radioButton1->TabIndex = 0;
				 this->radioButton1->TabStop = true;
				 this->radioButton1->Text = L"Unipolar Sigmoid";
				 this->radioButton1->UseVisualStyleBackColor = true;
				 this->radioButton1->CheckedChanged += gcnew System::EventHandler(this, &GUI::radioButton1_CheckedChanged);
				 // 
				 // label1
				 // 
				 this->label1->AutoSize = true;
				 this->label1->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
				 this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(162)));
				 this->label1->Location = System::Drawing::Point(623, 33);
				 this->label1->Name = L"label1";
				 this->label1->Size = System::Drawing::Size(126, 16);
				 this->label1->TabIndex = 0;
				 this->label1->Text = L"Activation Functions";
				 // 
				 // groupBox2
				 // 
				 this->groupBox2->Controls->Add(this->radioButton10);
				 this->groupBox2->Controls->Add(this->radioButton9);
				 this->groupBox2->Controls->Add(this->radioButton8);
				 this->groupBox2->Controls->Add(this->radioButton7);
				 this->groupBox2->Controls->Add(this->radioButton6);
				 this->groupBox2->Controls->Add(this->radioButton5);
				 this->groupBox2->Controls->Add(this->radioButton4);
				 this->groupBox2->Controls->Add(this->radioButton3);
				 this->groupBox2->Location = System::Drawing::Point(513, 163);
				 this->groupBox2->Name = L"groupBox2";
				 this->groupBox2->Size = System::Drawing::Size(341, 89);
				 this->groupBox2->TabIndex = 2;
				 this->groupBox2->TabStop = false;
				 // 
				 // radioButton10
				 // 
				 this->radioButton10->AutoSize = true;
				 this->radioButton10->BackColor = System::Drawing::Color::White;
				 this->radioButton10->Cursor = System::Windows::Forms::Cursors::Default;
				 this->radioButton10->Location = System::Drawing::Point(269, 57);
				 this->radioButton10->Name = L"radioButton10";
				 this->radioButton10->Size = System::Drawing::Size(56, 17);
				 this->radioButton10->TabIndex = 9;
				 this->radioButton10->TabStop = true;
				 this->radioButton10->Text = L"Class8";
				 this->radioButton10->UseVisualStyleBackColor = false;
				 // 
				 // radioButton9
				 // 
				 this->radioButton9->AutoSize = true;
				 this->radioButton9->BackColor = System::Drawing::Color::Brown;
				 this->radioButton9->Location = System::Drawing::Point(189, 57);
				 this->radioButton9->Name = L"radioButton9";
				 this->radioButton9->Size = System::Drawing::Size(56, 17);
				 this->radioButton9->TabIndex = 9;
				 this->radioButton9->TabStop = true;
				 this->radioButton9->Text = L"Class7";
				 this->radioButton9->UseVisualStyleBackColor = false;
				 // 
				 // radioButton8
				 // 
				 this->radioButton8->AutoSize = true;
				 this->radioButton8->BackColor = System::Drawing::Color::Orange;
				 this->radioButton8->Location = System::Drawing::Point(104, 57);
				 this->radioButton8->Name = L"radioButton8";
				 this->radioButton8->Size = System::Drawing::Size(56, 17);
				 this->radioButton8->TabIndex = 6;
				 this->radioButton8->TabStop = true;
				 this->radioButton8->Text = L"Class6";
				 this->radioButton8->UseVisualStyleBackColor = false;
				 // 
				 // radioButton7
				 // 
				 this->radioButton7->AutoSize = true;
				 this->radioButton7->BackColor = System::Drawing::Color::Turquoise;
				 this->radioButton7->Location = System::Drawing::Point(18, 57);
				 this->radioButton7->Name = L"radioButton7";
				 this->radioButton7->Size = System::Drawing::Size(56, 17);
				 this->radioButton7->TabIndex = 5;
				 this->radioButton7->TabStop = true;
				 this->radioButton7->Text = L"Class5";
				 this->radioButton7->UseVisualStyleBackColor = false;
				 // 
				 // radioButton6
				 // 
				 this->radioButton6->AutoSize = true;
				 this->radioButton6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
					 static_cast<System::Int32>(static_cast<System::Byte>(0)));
				 this->radioButton6->Location = System::Drawing::Point(269, 19);
				 this->radioButton6->Name = L"radioButton6";
				 this->radioButton6->Size = System::Drawing::Size(56, 17);
				 this->radioButton6->TabIndex = 4;
				 this->radioButton6->Text = L"Class4";
				 this->radioButton6->UseVisualStyleBackColor = false;
				 // 
				 // radioButton5
				 // 
				 this->radioButton5->AutoSize = true;
				 this->radioButton5->BackColor = System::Drawing::Color::Blue;
				 this->radioButton5->Location = System::Drawing::Point(189, 19);
				 this->radioButton5->Name = L"radioButton5";
				 this->radioButton5->Size = System::Drawing::Size(56, 17);
				 this->radioButton5->TabIndex = 4;
				 this->radioButton5->Text = L"Class3";
				 this->radioButton5->UseVisualStyleBackColor = false;
				 // 
				 // radioButton4
				 // 
				 this->radioButton4->AutoSize = true;
				 this->radioButton4->BackColor = System::Drawing::Color::Red;
				 this->radioButton4->Location = System::Drawing::Point(104, 19);
				 this->radioButton4->Name = L"radioButton4";
				 this->radioButton4->Size = System::Drawing::Size(56, 17);
				 this->radioButton4->TabIndex = 1;
				 this->radioButton4->Text = L"Class2";
				 this->radioButton4->UseVisualStyleBackColor = false;
				 // 
				 // radioButton3
				 // 
				 this->radioButton3->AutoSize = true;
				 this->radioButton3->BackColor = System::Drawing::Color::Yellow;
				 this->radioButton3->Checked = true;
				 this->radioButton3->Location = System::Drawing::Point(18, 19);
				 this->radioButton3->Name = L"radioButton3";
				 this->radioButton3->Size = System::Drawing::Size(56, 17);
				 this->radioButton3->TabIndex = 0;
				 this->radioButton3->TabStop = true;
				 this->radioButton3->Text = L"Class1";
				 this->radioButton3->UseVisualStyleBackColor = false;
				 // 
				 // label2
				 // 
				 this->label2->AutoSize = true;
				 this->label2->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
				 this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(162)));
				 this->label2->Location = System::Drawing::Point(662, 133);
				 this->label2->Name = L"label2";
				 this->label2->Size = System::Drawing::Size(57, 16);
				 this->label2->TabIndex = 3;
				 this->label2->Text = L"Classes";
				 // 
				 // groupBox3
				 // 
				 this->groupBox3->Controls->Add(this->label7);
				 this->groupBox3->Controls->Add(this->label6);
				 this->groupBox3->Controls->Add(this->label5);
				 this->groupBox3->Controls->Add(this->label4);
				 this->groupBox3->Location = System::Drawing::Point(513, 284);
				 this->groupBox3->Name = L"groupBox3";
				 this->groupBox3->Size = System::Drawing::Size(341, 55);
				 this->groupBox3->TabIndex = 4;
				 this->groupBox3->TabStop = false;
				 // 
				 // label7
				 // 
				 this->label7->AutoSize = true;
				 this->label7->Location = System::Drawing::Point(279, 25);
				 this->label7->Name = L"label7";
				 this->label7->Size = System::Drawing::Size(0, 13);
				 this->label7->TabIndex = 3;
				 // 
				 // label6
				 // 
				 this->label6->AutoSize = true;
				 this->label6->Location = System::Drawing::Point(192, 25);
				 this->label6->Name = L"label6";
				 this->label6->Size = System::Drawing::Size(81, 13);
				 this->label6->TabIndex = 2;
				 this->label6->Text = L"Cartesian Point:";
				 // 
				 // label5
				 // 
				 this->label5->AutoSize = true;
				 this->label5->Location = System::Drawing::Point(97, 25);
				 this->label5->Name = L"label5";
				 this->label5->Size = System::Drawing::Size(0, 13);
				 this->label5->TabIndex = 1;
				 // 
				 // label4
				 // 
				 this->label4->AutoSize = true;
				 this->label4->Location = System::Drawing::Point(15, 25);
				 this->label4->Name = L"label4";
				 this->label4->Size = System::Drawing::Size(71, 13);
				 this->label4->TabIndex = 0;
				 this->label4->Text = L"Screen Point:";
				 // 
				 // label3
				 // 
				 this->label3->AutoSize = true;
				 this->label3->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
				 this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(162)));
				 this->label3->Location = System::Drawing::Point(645, 265);
				 this->label3->Name = L"label3";
				 this->label3->Size = System::Drawing::Size(95, 16);
				 this->label3->TabIndex = 5;
				 this->label3->Text = L"Selected Point";
				 // 
				 // groupBox4
				 // 
				 this->groupBox4->Controls->Add(this->label13);
				 this->groupBox4->Controls->Add(this->label12);
				 this->groupBox4->Controls->Add(this->label11);
				 this->groupBox4->Controls->Add(this->label10);
				 this->groupBox4->Controls->Add(this->listBox1);
				 this->groupBox4->Controls->Add(this->label9);
				 this->groupBox4->Location = System::Drawing::Point(513, 370);
				 this->groupBox4->Name = L"groupBox4";
				 this->groupBox4->Size = System::Drawing::Size(341, 54);
				 this->groupBox4->TabIndex = 6;
				 this->groupBox4->TabStop = false;
				 // 
				 // label13
				 // 
				 this->label13->AutoSize = true;
				 this->label13->Location = System::Drawing::Point(273, 23);
				 this->label13->Name = L"label13";
				 this->label13->Size = System::Drawing::Size(0, 13);
				 this->label13->TabIndex = 8;
				 // 
				 // label12
				 // 
				 this->label12->AutoSize = true;
				 this->label12->Location = System::Drawing::Point(232, 23);
				 this->label12->Name = L"label12";
				 this->label12->Size = System::Drawing::Size(32, 13);
				 this->label12->TabIndex = 8;
				 this->label12->Text = L"Error:";
				 // 
				 // label11
				 // 
				 this->label11->AutoSize = true;
				 this->label11->Location = System::Drawing::Point(174, 23);
				 this->label11->Name = L"label11";
				 this->label11->Size = System::Drawing::Size(0, 13);
				 this->label11->TabIndex = 8;
				 // 
				 // label10
				 // 
				 this->label10->AutoSize = true;
				 this->label10->Location = System::Drawing::Point(132, 23);
				 this->label10->Name = L"label10";
				 this->label10->Size = System::Drawing::Size(36, 13);
				 this->label10->TabIndex = 2;
				 this->label10->Text = L"Cycle:";
				 // 
				 // listBox1
				 // 
				 this->listBox1->FormattingEnabled = true;
				 this->listBox1->Items->AddRange(gcnew cli::array< System::Object^  >(10) {
					 L"1", L"2", L"3", L"4", L"5", L"6", L"7", L"8",
						 L"9", L"10"
				 });
				 this->listBox1->Location = System::Drawing::Point(62, 23);
				 this->listBox1->Name = L"listBox1";
				 this->listBox1->Size = System::Drawing::Size(35, 17);
				 this->listBox1->TabIndex = 1;
				 // 
				 // label9
				 // 
				 this->label9->AutoSize = true;
				 this->label9->Location = System::Drawing::Point(15, 23);
				 this->label9->Name = L"label9";
				 this->label9->Size = System::Drawing::Size(41, 13);
				 this->label9->TabIndex = 0;
				 this->label9->Text = L"Layers:";
				 // 
				 // label8
				 // 
				 this->label8->AutoSize = true;
				 this->label8->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
				 this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(162)));
				 this->label8->Location = System::Drawing::Point(662, 351);
				 this->label8->Name = L"label8";
				 this->label8->Size = System::Drawing::Size(57, 16);
				 this->label8->TabIndex = 7;
				 this->label8->Text = L"Training";
				 // 
				 // menuStrip1
				 // 
				 this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
					 this->startTrainingToolStripMenuItem,
						 this->normalizeDataToolStripMenuItem, this->clearToolStripMenuItem, this->stopTrainingToolStripMenuItem, this->showRegionsToolStripMenuItem
				 });
				 this->menuStrip1->Location = System::Drawing::Point(0, 0);
				 this->menuStrip1->Name = L"menuStrip1";
				 this->menuStrip1->Size = System::Drawing::Size(884, 24);
				 this->menuStrip1->TabIndex = 8;
				 this->menuStrip1->Text = L"menuStrip1";
				 // 
				 // startTrainingToolStripMenuItem
				 // 
				 this->startTrainingToolStripMenuItem->Name = L"startTrainingToolStripMenuItem";
				 this->startTrainingToolStripMenuItem->Size = System::Drawing::Size(89, 20);
				 this->startTrainingToolStripMenuItem->Text = L"Start Training";
				 this->startTrainingToolStripMenuItem->Click += gcnew System::EventHandler(this, &GUI::startTrainingToolStripMenuItem_Click);
				 // 
				 // normalizeDataToolStripMenuItem
				 // 
				 this->normalizeDataToolStripMenuItem->Name = L"normalizeDataToolStripMenuItem";
				 this->normalizeDataToolStripMenuItem->Size = System::Drawing::Size(100, 20);
				 this->normalizeDataToolStripMenuItem->Text = L"Normalize Data";
				 this->normalizeDataToolStripMenuItem->Click += gcnew System::EventHandler(this, &GUI::normalizeDataToolStripMenuItem_Click);
				 // 
				 // clearToolStripMenuItem
				 // 
				 this->clearToolStripMenuItem->Name = L"clearToolStripMenuItem";
				 this->clearToolStripMenuItem->Size = System::Drawing::Size(46, 20);
				 this->clearToolStripMenuItem->Text = L"Clear";
				 // 
				 // stopTrainingToolStripMenuItem
				 // 
				 this->stopTrainingToolStripMenuItem->Name = L"stopTrainingToolStripMenuItem";
				 this->stopTrainingToolStripMenuItem->Size = System::Drawing::Size(89, 20);
				 this->stopTrainingToolStripMenuItem->Text = L"Stop Training";
				 this->stopTrainingToolStripMenuItem->Click += gcnew System::EventHandler(this, &GUI::stopTrainingToolStripMenuItem_Click);
				 // 
				 // showRegionsToolStripMenuItem
				 // 
				 this->showRegionsToolStripMenuItem->Name = L"showRegionsToolStripMenuItem";
				 this->showRegionsToolStripMenuItem->Size = System::Drawing::Size(93, 20);
				 this->showRegionsToolStripMenuItem->Text = L"Show Regions";
				 this->showRegionsToolStripMenuItem->Click += gcnew System::EventHandler(this, &GUI::showRegionsToolStripMenuItem_Click);
				 // 
				 // GUI
				 // 
				 this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->BackColor = System::Drawing::SystemColors::ActiveBorder;
				 this->ClientSize = System::Drawing::Size(884, 461);
				 this->Controls->Add(this->label8);
				 this->Controls->Add(this->groupBox4);
				 this->Controls->Add(this->label3);
				 this->Controls->Add(this->groupBox3);
				 this->Controls->Add(this->label2);
				 this->Controls->Add(this->groupBox2);
				 this->Controls->Add(this->label1);
				 this->Controls->Add(this->groupBox1);
				 this->Controls->Add(this->pictureBox1);
				 this->Controls->Add(this->menuStrip1);
				 this->MainMenuStrip = this->menuStrip1;
				 this->Name = L"GUI";
				 this->Text = L"GUI";
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
				 this->groupBox1->ResumeLayout(false);
				 this->groupBox1->PerformLayout();
				 this->groupBox2->ResumeLayout(false);
				 this->groupBox2->PerformLayout();
				 this->groupBox3->ResumeLayout(false);
				 this->groupBox3->PerformLayout();
				 this->groupBox4->ResumeLayout(false);
				 this->groupBox4->PerformLayout();
				 this->menuStrip1->ResumeLayout(false);
				 this->menuStrip1->PerformLayout();
				 this->ResumeLayout(false);
				 this->PerformLayout();

			 }

			 // Draw plane and points
			 void pictureBox1_DrawPlane(Object^ sender, PaintEventArgs^ e) {
				 // Get the size of picture box
				 int SizeX = pictureBox1->Size.Width;
				 int SizeY = pictureBox1->Size.Height;

				 // Draw the coordinate plane
				 Pen^ pen = gcnew Pen(Color::Black);
				 e->Graphics->DrawLine(pen, Point(0, SizeY / 2), Point(SizeX, SizeY / 2));
				 e->Graphics->DrawLine(pen, Point(SizeX / 2, 0), Point(SizeX / 2, SizeY));

				 // Draw each point
				 if (this->points->get_size() != 0) {

					 vector<NNPoint> points = this->points->get_points();

					 for (int i = 0; i < points.size(); i++) {

						 // Point color
						 Brush^ color = Brushes::White;
						 int label = points.at(i).get_class_label();

						 // First determine the color
						 if (label == 0)
							 color = Brushes::Yellow;
						 else if (label == 1)
							 color = Brushes::Red;
						 else if (label == 2)
							 color = Brushes::Blue;
						 else if (label == 3)
							 color = Brushes::Green;
						 else if (label == 4)
							 color = Brushes::Turquoise;
						 else if (label == 5)
							 color = Brushes::Orange;
						 else if (label == 6)
							 color = Brushes::Brown;
						 else if (label == 7)
							 color = Brushes::White;

						 double x1 = points.at(i).get_x1();
						 double x2 = points.at(i).get_x2();

						 if (this->normalized) {

							 x1 *= 60;
							 x2 *= 60;

							 int* co = ConvertToScreenCoordinates(x1, x2);
							 e->Graphics->FillRectangle(color, co[0], co[1], 5, 5);
						 }
						 else {
							 int* screen_coordinates = ConvertToScreenCoordinates(x1, x2);
							 e->Graphics->FillRectangle(color, screen_coordinates[0], screen_coordinates[1], 5, 5);
						 }
					 }
				 }

				 // Draw region points
				 if (this->region_points->get_size() != 0) {

					 vector<NNPoint> points = this->region_points->get_points();

					 for (int i = 0; i < points.size(); i++) {

						 // Point color
						 Brush^ color = Brushes::White;
						 int label = points.at(i).get_class_label();

						 // First determine the color
						 if (label == 0)
							 color = Brushes::Yellow;
						 else if (label == 1)
							 color = Brushes::Red;
						 else if (label == 2)
							 color = Brushes::Blue;
						 else if (label == 3)
							 color = Brushes::Green;
						 else if (label == 4)
							 color = Brushes::Turquoise;
						 else if (label == 5)
							 color = Brushes::Orange;
						 else if (label == 6)
							 color = Brushes::Brown;
						 else if (label == 7)
							 color = Brushes::White;

					 double x1 = points.at(i).get_x1();
					 double x2 = points.at(i).get_x2();

					 int* screen_coordinates = ConvertToScreenCoordinates(x1, x2);
					 e->Graphics->FillEllipse(color, screen_coordinates[0], screen_coordinates[1], 2, 2);
					 }
				 }
			 }

			 // Get points from user
			 void pictureBox1_MouseClick(Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {

				 int label;

				 // Determine and store point's label
				 if (radioButton3->Checked) {
					 label = 0;
					 if (class1_selected == FALSE)
						 class1_selected = TRUE;
				 }
				 else if (radioButton4->Checked) {
					 label = 1;
					 if (class2_selected == FALSE)
						 class2_selected = TRUE;
				 }
				 else if (radioButton5->Checked) {
					 label = 2;
					 if (class3_selected == FALSE)
						 class3_selected = TRUE;
				 }
				 else if (radioButton6->Checked) {
					 label = 3;
					 if (class4_selected == FALSE)
						 class4_selected = TRUE;
				 }
				 else if (radioButton7->Checked) {
					 label = 4;
					 if (class5_selected == FALSE)
						 class5_selected = TRUE;
				 }
				 else if (radioButton8->Checked) {
					 label = 5;
					 if (class6_selected == FALSE)
						 class6_selected = TRUE;
				 }
				 else if (radioButton9->Checked) {
					 label = 6;
					 if (class7_selected == FALSE)
						 class7_selected = TRUE;
				 }
				 else if (radioButton10->Checked) {
					 label = 7;
					 if (class8_selected == FALSE)
						 class8_selected = TRUE;
				 }

				 this->label5->Text = "" + e->X + " " + e->Y;
				 // Create NNPoint object
				 double* cartesian_points = ConvertToCartesianCoordinates(e->X, e->Y);
				 this->label7->Text = "" + cartesian_points[0] + " " + cartesian_points[1];
				 NNPoint a_point(cartesian_points[0], cartesian_points[1], label);
				 this->points->add_point(a_point);

				 pictureBox1->Refresh();
			 }

			 void radioButton1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
				 this->activation_function = UNIPOLAR_SIGMOID;
			 }

			 void radioButton2_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
				 this->activation_function = BIPOLAR_SIGMOID;
			 }

			 void normalizeDataToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->normalized = true;
				 this->points->normalize_points();
				 this->pictureBox1->Refresh();
			 }

			 void stopTrainingToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->stop_training = true;
			 }

			 // Start training
			 void startTrainingToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

				 double cost = 10;
				 int iter = 0;

				 // Get the class number
				 int selected_classes = class1_selected + class2_selected + class3_selected + class4_selected +
					 class5_selected + class6_selected + class7_selected + class8_selected;

				 if (selected_classes == 2)
					 this->class_num = 1;
				 else
					 this->class_num = selected_classes;

				 int layer_number = this->listBox1->SelectedIndex + 1;
				 if (layer_number == 0)
					 layer_number = 2;

				 neuralnetwork = new NeuralNetwork(this->points, activation_function, CLASS_COUNT,
					 layer_number, LEARNING_CONSTANT, MOMENTUM_CONSTANT);

				 while (cost > MAX_ERROR && this->stop_training == false) {
					 cost = neuralnetwork->train();
					 iter++;
				 }

				 this->label11->Text = "" + iter;
				 this->label13->Text = ("" + cost)->Substring(0, DECIMAL_POINT);
			 }

			 // Show class regions
			 void showRegionsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

				 int size_x = this->pictureBox1->Size.Width;
				 int size_y = this->pictureBox1->Size.Height;

				 for (int i = 0; i < size_x; i += 4) {
					 for (int j = 0; j < size_y; j += 4) {
						 double* co = ConvertToCartesianCoordinates(i, j);
						 NNPoint a_point(co[0], co[1], 0);
						 int class_label = neuralnetwork->make_prediction(a_point);
						 a_point.set_label(class_label);

						 this->region_points->add_point(a_point);
					 }
				 }

				 this->pictureBox1->Refresh();

			 }

			 // Converting screen coordinates to cartesian coordinates
			 double* ConvertToCartesianCoordinates(double x1, double x2) {

				 double* coordinates = new double[2];

				 int midX = this->pictureBox1->Size.Width / 2;
				 int midY = this->pictureBox1->Size.Height / 2;

				 coordinates[0] = x1 - midX;
				 coordinates[1] = midY - x2;

				 return coordinates;
			 }

			 // Converting cartesian coordinates to screen coordinates
			 int* ConvertToScreenCoordinates(int x1, int x2) {

				 int* coordinates = new int[2];

				 int midX = this->pictureBox1->Size.Width / 2;
				 int midY = this->pictureBox1->Size.Height / 2;

				 coordinates[0] = x1 + midX;
				 coordinates[1] = midY - x2;

				 return coordinates;
			 }


#pragma endregion
};
}
