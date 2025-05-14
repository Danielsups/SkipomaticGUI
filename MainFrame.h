#pragma once
#include "telaJogadores.h"
#include "telaEscolhido.h"
#include "telaInicio.h"
#include "filmeInfos.h"
#include "telaSkip.h"
#include <iostream>
#include <wx/wx.h>
#include <fstream>
#include <random>
#include <deque>
#include <map>
using namespace std;

class MainFrame : public wxFrame
{
public:
	MainFrame(const wxString& title);

	void TransicionarInicioJogadores();
	void TransicionarJogadoresSkip();
	void Skipado();
	void FilmeEscolhido();

	void setListaFilmes();
	void setContainerFilmes();
	void setContainerJogadores();

	void skipaFilme() { this->listaFilmes.pop_front(); }
	void tiraSkip(wxString nome) { this->containerJogadores.at(nome) -= 1; }

private:
	telaJogadores* jogadores;
	telaInicio* inicio;
	telaSkip* skip;
	telaEscolhido* escolhido;

	int numSkips;
	int numJogadores;
	wxString linkLista;
	wxString nomeLista;
	filmeInfos containerFilmes;
	deque<wxString> listaFilmes;
	wxArrayString listaJogadores;
	map<wxString, int> containerJogadores;
};