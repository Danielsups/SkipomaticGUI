#pragma once
#include <wx/wx.h>

class telaJogadores : public wxPanel
{
public:
	telaJogadores(wxWindow* parent, wxString nomeLista, int numJogadores, int numSkips);

	wxArrayString getterJogadores() const { return jogadores; }

private:
	void adicionarJogador(wxCommandEvent& evt);
	void iniciarSkip(wxCommandEvent& evt);

	wxString nomeLista;
	int numJogadores;
	int numSkips;

	wxArrayString jogadores;
	wxTextCtrl* insiraJogadores;
	wxListBox* listaJogadores;
};