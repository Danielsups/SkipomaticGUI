#include "MainFrame.h"
#include "telaInicio.h"
#include "ImagePanel.h"
#include <wx/spinctrl.h>

telaInicio::telaInicio(wxWindow* parent) : wxPanel(parent) {
	SetSize(1600, 800);
	SetBackgroundColour(wxColour(20, 24, 28));

	ImagePanel* logoImage = new ImagePanel(this, "src/icon.png", wxPoint(500, 100), wxSize(600, 300));

	getLinkLista = new wxTextCtrl(this, wxID_ANY, "", wxPoint(600, 450), wxSize(400, -1));
	getLinkLista->SetHint("Link da lista");

	wxFont fonte(12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);

	getNumJogadores = new wxSpinCtrl(this, wxID_ANY, "", wxPoint(680, 500), wxSize(40, -1));
	wxStaticText* textoJogadores = new wxStaticText(this, wxID_ANY, "Quantidade de Jogadores", wxPoint(730, 500), wxSize(-1, 23));
	textoJogadores->SetFont(fonte);
	textoJogadores->SetForegroundColour(*wxWHITE);

	getNumSkips = new wxSpinCtrl(this, wxID_ANY, "3", wxPoint(680, 540), wxSize(40, -1));
	wxStaticText* textoSkips = new wxStaticText(this, wxID_ANY, "Quantidade de Skips", wxPoint(730, 540), wxSize(-1, 23));
	textoSkips->SetFont(fonte);
	textoSkips->SetForegroundColour(*wxWHITE);

	wxButton* setJogadores = new wxButton(this, wxID_ANY, "Inserir Jogadores", wxPoint(700, 600), wxSize(200, 35), wxBORDER_NONE);

	setJogadores->Bind(wxEVT_BUTTON, &telaInicio::botaoJogadores, this);
}

void telaInicio::botaoJogadores(wxCommandEvent& evt) {
	if (getNumJogadores->GetValue() == 0) {
		wxMessageBox("Quantidade de Jogadores insuficiente.", "Aviso", wxOK | wxICON_INFORMATION);
		return;
	}
	if (getNumSkips->GetValue() == 0) {
		wxMessageBox("Quantidade de Skips insuficiente.", "Aviso", wxOK | wxICON_INFORMATION);
		return;
	}

	((MainFrame*)GetParent())->TransicionarInicioJogadores();
}