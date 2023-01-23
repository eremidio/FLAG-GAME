//ESTE ARQUIVO CONTÉM A JANELA DE INSTRUÇÕES PARA O USO DO APLICATIVO

/*CABEÇALHO*/
#include<gtkmm.h>
#include<iostream>

using namespace std;
using namespace Glib;
using namespace Gtk;

/*CLASSE DE MENU DE AJUDA LABEL+SCROLLEDWINDOW*/
class HelpWindow: public Window{
public:

//CONSTRUTOR E DESTRUIDOR DA CLASSE
HelpWindow();
virtual ~HelpWindow();
//WIDGETS
ScrolledWindow help_scrolledwindow;
Label help_label;
Box help_box;

};

//DESTRUIDOR DA CLASSE
HelpWindow::~HelpWindow(){
};

//CONSTRUTOR DA CLASSE
HelpWindow::HelpWindow(){

//LAYOUT
add(help_scrolledwindow);
help_scrolledwindow.set_policy(POLICY_AUTOMATIC, POLICY_AUTOMATIC);
help_scrolledwindow.add(help_label);
help_label.set_justify(JUSTIFY_FILL);
help_label.set_line_wrap();
//AJUSTE DA FONTE A SER USADA
Pango::FontDescription help_font;
help_font.set_family("Times");
help_font.set_size(12*PANGO_SCALE);
help_font.set_weight(Pango::Weight::WEIGHT_BOLD);
help_label.override_font(help_font);
//TEXTO DE AJUDA A SER EXIBIDO NA JANELA SECUNDÁRIA
help_label.set_text("JOGO DAS BANDEIRAS - Versão 1.0\n"
"----------------------------------------------------------------\n\n"
"1.0 - LAYOUT GERAL E FUNCIONALIDADE\n"
"----------------------------------------------------------------\n\n"
"Este aplicativo criado com finalidade pedagógica visa a testar o conhecimento dos usuário acerca dos estados brasileiros.\nEle dispõe de um jogo de bandeiras na qual o usuário deverá identificar o estado e sua respectiva capital apenas pela bandeira de cada estado.\nPara ter acesso ao jogo basta clicar no botão 'Jogar' na tela inicial do aplicativo que uma janela secundária irá se abrir, possibilitando que o usuário tenha acesso ao jogo.\nNeste jogo ao clicar no botão 'Escolha' uma bandeira irá aparecer, o usuário deverá selecionar o nome e a capital do estado correspondente a bandeira e em seguida clicar no botão 'Checar a resposta' para verificar possíveis erros ou acertos.\nEste aplicativo dispõe de uma janela que possibilita ao usuário a ter acesso a links externos com maiores informações acerca dos estados brasileiros na guia 'Saiba mais' na janela principal do aplicativo.\n\n"
"2.0 - AGRADECIMENTOS\n"
"----------------------------------------------------------------\n\n"
"Obrigado pela preferência. Sugestões de melhorias entrar em contato com: e.r.emidio@yandex.com.\n\n"

);



};
