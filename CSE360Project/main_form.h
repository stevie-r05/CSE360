#pragma once

namespace CSE360Project {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for main_form
	/// </summary>
	public ref class main_form : public System::Windows::Forms::Form
	{
	public:
		main_form(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~main_form()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->SuspendLayout();
			// 
			// main_form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(440, 439);
			this->Name = L"main_form";
			this->Text = L"JITL - Team DITS, LLC";
			this->Load += gcnew System::EventHandler(this, &main_form::main_form_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void main_form_Load(System::Object^  sender, System::EventArgs^  e) {
			 }
	};
}

