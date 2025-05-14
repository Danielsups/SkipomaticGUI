#pragma once
#include <wx/wx.h>
#include <wx/dcbuffer.h>
#include <wx/mstream.h>
#include <wx/image.h>
#include <wx/webrequest.h>

class ImagePanel : public wxPanel {
    wxBitmap imagem;

public:
    ImagePanel(wxWindow* parent, const wxString& caminhoOuUrl, wxPoint posicao, wxSize tamanho)
        : wxPanel(parent, wxID_ANY, posicao, tamanho) {

        // Configura o estilo de fundo para evitar flickering
        SetBackgroundStyle(wxBG_STYLE_PAINT);
        // Associa o evento de pintura ao método OnPaint
        Bind(wxEVT_PAINT, &ImagePanel::OnPaint, this);

        // Registra handlers para os formatos de imagem mais comuns
        wxImage::AddHandler(new wxJPEGHandler());
        wxImage::AddHandler(new wxPNGHandler());
        wxImage::AddHandler(new wxGIFHandler());

        if (caminhoOuUrl.StartsWith("http")) {
            // Carregamento de imagem via URL
            CarregarImagemWeb(caminhoOuUrl);
        }
        else {
            // Carregamento de imagem local
            CarregarImagemLocal(caminhoOuUrl, tamanho);
        }
    }

private:
    void CarregarImagemLocal(const wxString& caminho, const wxSize& tamanho) {
        wxImage img;
        if (img.LoadFile(caminho)) {
            if (img.IsOk()) {
                // Redimensiona a imagem para o tamanho do painel
                img.Rescale(tamanho.GetWidth(), tamanho.GetHeight());
                imagem = wxBitmap(img);
                // Força a redesenhar o painel
                Refresh();
            }
            else {
                wxLogError("Imagem local inválida: %s", caminho);
            }
        }
        else {
            wxLogError("Falha ao carregar imagem local: %s", caminho);
        }
    }

    void CarregarImagemWeb(const wxString& url) {
        wxWebSession& sessao = wxWebSession::GetDefault();
        wxWebRequest requisicao = sessao.CreateRequest(this, url);
        // Associa o evento de conclusão da requisição
        Bind(wxEVT_WEBREQUEST_STATE, &ImagePanel::OnRequisicaoWebConcluida, this);
        requisicao.Start();
    }

    void OnPaint(wxPaintEvent& evt) {
        wxAutoBufferedPaintDC dc(this);
        dc.Clear();

        // Desenha a imagem se ela for válida
        if (imagem.IsOk()) {
            dc.DrawBitmap(imagem, 0, 0, false);
        }
        else {
            // Opcional: Desenha um placeholder quando não há imagem
            dc.SetBrush(*wxLIGHT_GREY_BRUSH);
            dc.DrawRectangle(0, 0, GetSize().GetWidth(), GetSize().GetHeight());
        }
    }

    void OnRequisicaoWebConcluida(wxWebRequestEvent& evt) {
        if (evt.GetState() == wxWebRequest::State_Completed) {
            wxInputStream* stream = evt.GetResponse().GetStream();

            if (stream && stream->IsOk()) {
                wxImage img;
                if (img.LoadFile(*stream, wxBITMAP_TYPE_ANY)) {
                    if (img.IsOk()) {
                        // Redimensiona e converte para bitmap
                        img.Rescale(GetSize().GetWidth(), GetSize().GetHeight());
                        imagem = wxBitmap(img);
                        Refresh();
                    }
                    else {
                        wxLogError("Imagem da web inválida");
                    }
                }
                else {
                    wxLogError("Formato de imagem não suportado");
                }
            }
            else {
                wxLogError("Stream de resposta inválido");
            }
        }
        else if (evt.GetState() == wxWebRequest::State_Failed) {
            wxLogError("Falha na requisição web");
        }
    }
};