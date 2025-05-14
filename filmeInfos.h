#pragma once
#include <wx/wx.h>

class filmeInfos
{
public:
    void setInfos(wxString info, int contInfo) {
        if (contInfo == 1) this->nome = info;
        if (contInfo == 2) this->ano = info;
        if (contInfo == 3) this->sinopse = info;
        if (contInfo == 4) this->duracao = info;
        if (contInfo == 5) this->diretor = info;
        if (contInfo == 6) this->nota = info;
        if (contInfo == 7) this->poster = info;
    };

    wxString getNome() { return this->nome; }
    wxString getAno() { return this->ano; }
    wxString getSinopse() { return this->sinopse; }
    wxString getDuracao() { return this->duracao; }
    wxString getDiretor() { return this->diretor; }
    wxString getNota() { return this->nota; }
    wxString getPoster() { return this->poster; }

private:
    wxString nome;
    wxString ano;
    wxString sinopse;
    wxString duracao;
    wxString diretor;
    wxString nota;
    wxString poster;
};