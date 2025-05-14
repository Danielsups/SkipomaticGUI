#include "Skipo.h"
#include "MainFrame.h"
#include <wx/wx.h>

wxIMPLEMENT_APP(Skipo);

bool Skipo::OnInit() {
	wxInitAllImageHandlers();
	MainFrame* mainFrame = new MainFrame("Skipomatic");
	mainFrame->SetClientSize(1600, 800);
	mainFrame->Center();
	mainFrame->Show();
	return true;
}