#include "telaSkip.h"
#include "MainFrame.h"
#include "ImagePanel.h"

telaSkip::telaSkip(wxWindow* parent, map<wxString, int> containerJogadores, filmeInfos containerFilme) : wxPanel(parent), containerJogadores(containerJogadores), containerFilme(containerFilme) {
	SetSize(1600, 800);
	SetBackgroundColour(wxColour(20, 24, 28));

	wxFont fonteNomeFilme(25, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
	wxFont fonteSinopseFilme(18, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);

	wxArrayString escolhasFilme;
	escolhasFilme.Add("Skipar");
	escolhasFilme.Add("Inciso 10");
	escolhasFilme.Add("Ninguem Skipou");

	wxArrayString jogadores;
	for (auto jogador : containerJogadores) {
		jogadores.Add(wxString::Format("%s com %d skips", jogador.first, jogador.second));
	}

	ImagePanel* posterFilme = new ImagePanel(this, containerFilme.getPoster(), wxPoint(100, 100), wxSize(400, 600));

	wxStaticText* nomeFilme = new wxStaticText(this, wxID_ANY, containerFilme.getNome(), wxPoint(525, 100), wxSize(975, 100));
	nomeFilme->SetForegroundColour(*wxWHITE);
	nomeFilme->SetFont(fonteNomeFilme);
	nomeFilme->Wrap(975);

	wxStaticText* notaFilme = new wxStaticText(this, wxID_ANY, containerFilme.getNota(), wxPoint(525, 210), wxSize(75, 50));
	notaFilme->SetForegroundColour(*wxWHITE);
	notaFilme->SetFont(fonteNomeFilme);

	wxStaticText* tempoFilme = new wxStaticText(this, wxID_ANY, containerFilme.getDuracao(), wxPoint(625, 210), wxSize(75, 50));
	tempoFilme->SetForegroundColour(*wxWHITE);
	tempoFilme->SetFont(fonteNomeFilme);

	wxStaticText* anoFilme = new wxStaticText(this, wxID_ANY, containerFilme.getAno(), wxPoint(725, 210), wxSize(75, 50));
	anoFilme->SetForegroundColour(*wxWHITE);
	anoFilme->SetFont(fonteNomeFilme);

	wxStaticText* diretorFilme = new wxStaticText(this, wxID_ANY, containerFilme.getDiretor(), wxPoint(825, 210), wxSize(-1, 50));
	diretorFilme->SetForegroundColour(*wxWHITE);
	diretorFilme->SetFont(fonteNomeFilme);

	wxStaticText* sinopseFilme = new wxStaticText(this, wxID_ANY, containerFilme.getSinopse(), wxPoint(525, 295), wxSize(975, 280));
	sinopseFilme->SetForegroundColour(*wxWHITE);
	sinopseFilme->SetFont(fonteSinopseFilme);
	sinopseFilme->Wrap(975);

	escolha = new wxListBox(this, wxID_ANY, wxPoint(525, 610), wxSize(100, 90), escolhasFilme);

	jogador = new wxRadioBox(this, wxID_ANY, "Jogadores", wxPoint(625, 610), wxSize(750, 90), jogadores, 2, wxRA_SPECIFY_ROWS);
	jogador->SetBackgroundColour(*wxWHITE);

	wxButton* avancar = new wxButton(this, wxID_ANY, "Avançar", wxPoint(1375, 610), wxSize(125, 90));
	avancar->Bind(wxEVT_BUTTON, &telaSkip::continuarSkip, this);
}

void telaSkip::continuarSkip(wxCommandEvent& evt) {
	
	if (escolha->GetSelection() == wxNOT_FOUND)
	{
		wxMessageBox("É necessario que se faça uma escolha de ação para o filme", "Aviso", wxOK | wxICON_INFORMATION);
		return;
	}

	wxString escolhaSelecionada = escolha->GetString(escolha->GetSelection());

	wxString jogadorSelecionado = jogador->GetString(jogador->GetSelection());
	for (size_t i = 0; i < 3; i++)
	{
		jogadorSelecionado = jogadorSelecionado.BeforeLast(' ');
	}	


	if (escolhaSelecionada == "Skipar") {
		
		if (containerJogadores.at(jogadorSelecionado) < 1)
		{
			wxMessageBox("O jogador selecionado não tem mais skips", "Aviso", wxOK | wxICON_INFORMATION);
			return;
		}

		((MainFrame*)GetParent())->tiraSkip(jogadorSelecionado);
		((MainFrame*)GetParent())->Skipado();

	}

	if (escolhaSelecionada == "Inciso 10") {

		((MainFrame*)GetParent())->Skipado();

	}

	if (escolhaSelecionada == "Ninguem Skipou") {

		((MainFrame*)GetParent())->FilmeEscolhido();

	}

	escolha->SetSelection(-1);
}
