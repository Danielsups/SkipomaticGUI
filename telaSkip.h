#pragma once
#include "filmeInfos.h"
#include <wx/wx.h>
#include <map>
using namespace std;

class telaSkip : public wxPanel
{
public:
	telaSkip(wxWindow* parent, map<wxString, int> containerJogadores, filmeInfos containerFilme);

private:
	void continuarSkip(wxCommandEvent& evt);

	map<wxString, int> containerJogadores;
	filmeInfos containerFilme;

	wxListBox* escolha;
	wxRadioBox* jogador;
};

