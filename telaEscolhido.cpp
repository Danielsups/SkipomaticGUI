#include "MainFrame.h"
#include "ImagePanel.h"
#include "telaEscolhido.h"

telaEscolhido::telaEscolhido(wxWindow* parent, filmeInfos containerFilme) : wxPanel(parent), containerFilme(containerFilme) {
	SetSize(1600, 800);
	SetBackgroundColour(wxColour(20, 24, 28));

	ImagePanel* posterFilme = new ImagePanel(this, containerFilme.getPoster(), wxPoint(1050, 50), wxSize(500, 700));

	ImagePanel* resultadoFilme = new ImagePanel(this, "src/fim.png", wxPoint(50, 50), wxSize(950, 700));

}
