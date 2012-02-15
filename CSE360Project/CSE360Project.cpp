// CSE360Project.cpp : main project file.

#include "stdafx.h"
#include "main_form.h"
#include "timingClass.h"

using namespace CSE360Project;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Create the main window and run it
	Application::Run(gcnew main_form());
	return 0;
}
