#include "Calculator.h"

using namespace std;
using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void main(array<String^>^ arg) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	My1516lab::Calculator form; //имя вашего проекта
	Application::Run(% form);
};