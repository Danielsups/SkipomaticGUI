#include "MainFrame.h"
#include "ImagePanel.h"
#include "telaEscolhido.h"

telaEscolhido::telaEscolhido(wxWindow* parent, filmeInfos containerFilme) : wxPanel(parent), containerFilme(containerFilme) {
	SetSize(1600, 800);

	ImagePanel* fimFundo = new ImagePanel(this, "src/fimFundoCompleto.png", wxPoint(0, 0), wxSize(1600, 800));

	ImagePanel* bordaPoster = new ImagePanel(this, "src/fimBordaPoster.png", wxPoint(1050, 50), wxSize(500, 700));
	ImagePanel* posterFilme = new ImagePanel(this, containerFilme.getPoster(), wxPoint(1100, 100), wxSize(400, 600));	

}
