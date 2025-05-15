#include "MainFrame.h"
#include <wx/wx.h>

//Função MainFrame, cria variavel inicio e atribui a ela a tela de inicio em telaInicio.cpp, após criada a mesma já aparece na tela.

MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE & ~(wxRESIZE_BORDER | wxMAXIMIZE_BOX)) {

    inicio = new telaInicio(this);

}

//Função TransicionarInicioJogadores, após clique no botão avançar na pagina de inicio que consta em telaInicio.cpp, o mesmo retorna esta função
//aqui pegamos o link da lista, quantidade de jogadores e skips e é feito tratamento no link para obtenção do nome da lista
//logo depois é chamado setListaFilmes e criada a função jogadores atribuida a ela a telaJogadores

void MainFrame::TransicionarInicioJogadores() {
    linkLista = inicio->getterLinkLista();
    numJogadores = inicio->getterNumJogadores();
    numSkips = inicio->getterNumSkips();

    nomeLista = linkLista.BeforeLast('/');
    nomeLista = nomeLista.AfterLast('/');
    nomeLista.Replace('-', " ");

    setListaFilmes();

    jogadores = new telaJogadores(this, nomeLista, numJogadores, numSkips);
    inicio->Hide();
    jogadores->Show();
}

//Após ser chamada na função acima, setListaFilmes busca o arquivo txt com a lista dos filmes e atribui ele a variavel arquivoFilmes
//é criada uma string filme e então temos uma estrutura de repetição, que é verdadeira e constante até sua quebra, a mesma pega cada
//linha de arquivoFilmes, passa para filme e então adiciona ela a uma fila onde cada elemento é uma linha, até que se terminem as
//linhas, onde o while se quebra, após isso é randomizada a listaFilmes, assim conseguindo uma fila com todos os filmes.

void MainFrame::setListaFilmes() {

    ifstream arquivoFilmes("src/filmes.txt");
    string filme;

    while (true)
    {
        getline(arquivoFilmes, filme);
        if (filme != "") listaFilmes.push_back(filme);
        else break;
    }

    random_device rd;
    mt19937 g(rd());

    shuffle(listaFilmes.begin(), listaFilmes.end(), g);
}

//Função configura um vetor containerJogadores, onde atribui a cada jogador selecionado a quantidade de skips escolhidos

void MainFrame::setContainerJogadores() {
    
    listaJogadores = jogadores->getterJogadores();

    for (auto jogador : listaJogadores) {
        containerJogadores[jogador] = numSkips;
    }

}

//Função contém uma estrutura de repetição que para cada filme em lista filmes ela separa as informações 
//e atribui a uma classe containerFilmes

void MainFrame::setContainerFilmes() {
    
    wxString info = "";
    int contInfo = 1;

    for (auto filme : listaFilmes) {
        for (size_t i = 0; i < filme.length(); i++)
        {
            if (filme.at(i) != '+') {
                info += filme.at(i);

            }
            else {
                containerFilmes.setInfos(info, contInfo);
                contInfo++;
                info = "";
            }
        }
        break;
    }

}

void MainFrame::TransicionarJogadoresSkip() {

    setContainerJogadores();
    setContainerFilmes();

    skip = new telaSkip(this, containerJogadores, containerFilmes);
    jogadores->Hide();
    skip->Show();

}

void MainFrame::Skipado() {
    
    skipaFilme();
    setContainerFilmes();

    skip->Hide();
    skip = new telaSkip(this, containerJogadores, containerFilmes);

}

void MainFrame::FilmeEscolhido() {

    escolhido = new telaEscolhido(this, containerFilmes);
    skip->Hide();
    escolhido->Show();

}