#pragma once
#include "filmeInfos.h"
#include <wx/wx.h>

class telaEscolhido : public wxPanel
{
public:
	telaEscolhido(wxWindow* parent, filmeInfos containerFilme);


private:
	filmeInfos containerFilme;
};

