//ESTE ARQUIVO CONTÉM OS MÉTODOS DA CLASSE PRINCIPAL DO APLICATIVO

/*CABEÇALHO*/
#include"jogo_das_bandeiras1.h"
#include<string>
#include<vector>
using namespace std;
using namespace Gtk;
using namespace Glib;

//DESTRUIDOR DA CLASSE
Game::~Game(){
delete help_window;
delete flag_window;
delete link_window;
};

//CONSTRUTOR DA CLASSE
Game::Game():base(ORIENTATION_VERTICAL, 5), toolbar_box(ORIENTATION_HORIZONTAL, 5), main_box(ORIENTATION_HORIZONTAL, 5), game_button("Jogar"), brasil_flag("brasil.png")
{
//LAYOUT GERAL DA TELA PRINCIPAL DO APP
add(base);
base.pack_start(toolbar_box);
base.pack_start(main_box);
//AJUSTANDO A BARRA DE FERRAMENTAS E ATIVANDO ÍCONES
toolbar_box.pack_start(game_toolbar, PACK_SHRINK);
game_toolbar.set_toolbar_style(TOOLBAR_BOTH);
auto item1 = Gtk::make_managed<Gtk::ToolButton>("_Saiba mais");
item1->set_use_underline();
item1->set_icon_name("applications-internet");
item1->set_homogeneous(true);
game_toolbar.append(*item1);
item1->signal_clicked().connect( sigc::mem_fun(*this,&Game::external_links));
game_toolbar.append(*make_managed<Gtk::SeparatorToolItem>());
auto item2 = Gtk::make_managed<Gtk::ToolButton>("_Ajuda");
item2->set_use_underline();
item2->set_icon_name("help-faq");
item2->set_homogeneous(true);
game_toolbar.append(*item2);
item2->signal_clicked().connect( sigc::mem_fun(*this,&Game::help));
auto item3 = Gtk::make_managed<Gtk::ToolButton>("_Sobre");
item3->set_use_underline();
item3->set_icon_name("help-about");
item3->set_homogeneous(true);
game_toolbar.append(*item3);
item3->signal_clicked().connect( sigc::mem_fun(*this,&Game::about));
game_toolbar.append(*make_managed<Gtk::SeparatorToolItem>());
auto item4 = Gtk::make_managed<Gtk::ToolButton>("_Sair");
item4->set_use_underline();
item4->set_icon_name("application-exit");
item4->set_homogeneous(true);
game_toolbar.append(*item4);
item4->signal_clicked().connect( sigc::mem_fun(*this,&Game::quit));
//AJUSTANDO O LAYOUT DO RESTANTE DA JANELA DO APP
main_box.pack_start(game_grid);
game_grid.set_row_homogeneous(true);
game_grid.set_column_homogeneous(true);
game_grid.attach(brasil_flag, 0, 0, 1, 1);
game_grid.attach(game_buttonbox, 0, 1, 1, 1);
game_buttonbox.pack_start(game_button);
game_buttonbox.set_layout(BUTTONBOX_CENTER);
//AJUSTANDO A CAIXA DE DIALÓGO COM INFORMAÇÕES DO APLICATIVO
game_aboutdialog.set_transient_for(*this);
game_aboutdialog.set_logo_icon_name("help-about");
game_aboutdialog.set_program_name("Jogo das bandeiras");
game_aboutdialog.set_version("1.0");
game_aboutdialog.set_copyright("Elias Rodrigues Emídio");
game_aboutdialog.set_comments("Entre em contato com:\ne.r.emidio@yandex.com");
game_aboutdialog.set_license("LGPL");
vector<Glib::ustring> list_authors;
list_authors.push_back("Elias Rodrigues Emídio");
game_aboutdialog.set_authors(list_authors);
game_aboutdialog.signal_response().connect(sigc::mem_fun(*this, &Game::close_credits));
//ATIVANDO O BOTÃO QUE ACIONA O JOGO DAS BANDEIRAS
game_button.signal_clicked().connect(sigc::mem_fun(*this, &Game::flag_game));
//EXIBINDO OS WIDGETS
show_all_children();
};

//MÉTODOS DA CLASSE

void Game::flag_game(){
flag_window->set_default_size(800, 800);
flag_window->show();
flag_window->set_title("Jogo das bandeiras");
                      };

void Game::help(){
help_window->set_default_size(400, 500);
help_window->show();
help_window->show_all_children();
help_window->set_title("Ajuda.");
                 };

void Game::about(){
game_aboutdialog.show();
game_aboutdialog.present();
                  };

void Game::external_links(){
link_window->set_default_size(400, 600);
link_window->show();
link_window->show_all_children();
link_window->set_title("Saiba mais.");
                 };

void Game::close_credits(int response_id){
switch (response_id){
case Gtk::RESPONSE_CLOSE:
case Gtk::RESPONSE_CANCEL:
case Gtk::RESPONSE_DELETE_EVENT:
game_aboutdialog.hide();
break;

default:
break;
                    };
                                         };

void Game::quit(){
hide();
                 };
