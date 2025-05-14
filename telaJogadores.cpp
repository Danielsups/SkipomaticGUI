#include "MainFrame.h"
#include "telaJogadores.h"

telaJogadores::telaJogadores(wxWindow* parent, wxString nomeLista, int numJogadores, int numSkips) : wxPanel(parent), nomeLista(nomeLista), numJogadores(numJogadores), numSkips(numSkips) {
	SetSize(1600, 800);
	SetBackgroundColour(wxColour(20, 24, 28));

	wxFont fonteDescricaoJogo(18, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
	wxFont fonteTituloDescricaoJogo(61, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
	wxFont fonteTextoInsiraJogadores(23, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);

	wxStaticText* textoInsiraJogadores = new wxStaticText(this, wxID_ANY, wxString::Format("Insira os nomes dos %d participantes:", numJogadores), wxPoint(100, 100), wxSize(550, 50), wxALIGN_CENTER);
	textoInsiraJogadores->SetFont(fonteTextoInsiraJogadores);
	textoInsiraJogadores->SetForegroundColour(*wxWHITE);

	insiraJogadores = new wxTextCtrl(this, wxID_ANY, "", wxPoint(100, 150), wxSize(500, 50));
	insiraJogadores->SetFont(fonteTextoInsiraJogadores);
	insiraJogadores->SetHint("Digite o nome do jogador");

	wxButton* adicionarJogador = new wxButton(this, wxID_ANY, "Add", wxPoint(610, 160), wxSize(30, 30), wxBU_LEFT);
	adicionarJogador->Bind(wxEVT_BUTTON, &telaJogadores::adicionarJogador, this);
	adicionarJogador->SetDefault();

	listaJogadores = new wxListBox(this, wxID_ANY, wxPoint(100, 220), wxSize(550, 480), jogadores, wxLB_SORT);
	listaJogadores->SetFont(fonteTextoInsiraJogadores);

	wxStaticText* textoDescricaoJogo = new wxStaticText(this, wxID_ANY, "Descrição da Rodada", wxPoint(670, 100), wxSize(830, 100), wxALIGN_CENTER);
	textoDescricaoJogo->SetFont(fonteTituloDescricaoJogo);
	textoDescricaoJogo->SetForegroundColour(*wxWHITE);

	wxStaticText* descricaoJogo = new wxStaticText(this, wxID_ANY, wxString::Format("Quantidade de participantes: %d\n\nQuantidade de Skips: %d\n\nNome da Lista: %s\n\nTamanho da Lista:", numJogadores, numSkips, nomeLista), wxPoint(670, 220), wxSize(630, 480));
	descricaoJogo->Wrap(250);
	descricaoJogo->SetBackgroundColour(*wxWHITE);
	descricaoJogo->SetFont(fonteDescricaoJogo);

	wxButton* botaoIniciarSkip = new wxButton(this, wxID_ANY, "Iniciar Skip", wxPoint(1320, 220), wxSize(180, 480));
	botaoIniciarSkip->SetFont(fonteDescricaoJogo);

	botaoIniciarSkip->Bind(wxEVT_BUTTON, &telaJogadores::iniciarSkip, this);

}

void telaJogadores::iniciarSkip(wxCommandEvent& evt) {
	if (jogadores.size() != numJogadores) {
		wxMessageBox("Quantidade de Jogadores insuficiente.", "Aviso", wxOK | wxICON_INFORMATION);
		return;
	}
	((MainFrame*)GetParent())->TransicionarJogadoresSkip();
}

void telaJogadores::adicionarJogador(wxCommandEvent& evt) {
	wxString nome = insiraJogadores->GetValue().Trim().Trim(false);

	if (!nome.IsEmpty()) {
		if (jogadores.size() >= numJogadores) {
			wxMessageBox("Quantidade de Jogadores extrapolada.", "Aviso", wxOK | wxICON_INFORMATION);
			insiraJogadores->Clear();
			return;
		}
		for (auto jogador : jogadores) {
			if (nome == jogador) {
				wxMessageBox("Jogador já existe.", "Aviso", wxOK | wxICON_INFORMATION);
				insiraJogadores->Clear();
				return;
			}
		}
		jogadores.Add(nome);
		listaJogadores->AppendString(nome);
		insiraJogadores->Clear();
	}
}