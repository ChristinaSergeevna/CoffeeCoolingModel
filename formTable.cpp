#include "formTable.h"
#include <Windows.h>

using namespace System;
using namespace System::Windows::Forms;
using namespace MCM1;
[STAThreadAttribute]

int formTableInit()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	MCM1::formTable form;
	Application::Run(%form);
	return 0;
}
