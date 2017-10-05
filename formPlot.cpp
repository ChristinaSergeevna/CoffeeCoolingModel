#include "formPlot.h"
#include <Windows.h>

using namespace System;
using namespace System::Windows::Forms;
using namespace MCM1;
[STAThreadAttribute]

int Something()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	MCM1::formPlot form;
	Application::Run(%form);
	return 0;
}

