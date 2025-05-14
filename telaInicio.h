#pragma once
#include <wx/wx.h>
#include <wx/spinctrl.h>

class telaInicio : public wxPanel
{
public:
	telaInicio(wxWindow* parent);

	wxString getterLinkLista() const { return getLinkLista->GetValue(); }
	int getterNumJogadores() const { return getNumJogadores->GetValue(); }
	int getterNumSkips() const { return getNumSkips->GetValue(); }

private:
	void botaoJogadores(wxCommandEvent& evt);
	wxTextCtrl* getLinkLista;
	wxSpinCtrl* getNumJogadores;
	wxSpinCtrl* getNumSkips;
};