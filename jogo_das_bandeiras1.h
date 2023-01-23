//ESSE ARQUIVO CONTÉM A CLASSE DO APLICATIVO E INVOCA INSTÂNCIA DAS CLASSES SECUNDÁRIAS NA EXECUÇÃO DO APP

/*CABEÇALHO*/
#include<gtkmm.h>
#include"jogo_das_bandeiras5.h"
#include"jogo_das_bandeiras4.h"
#include"jogo_das_bandeiras2.h"
using namespace std;
using namespace Gtk;
using namespace Glib;

class Game: public Window{
public:
//CONSTRUTOR E DESTRUIDOR DA CLASSE
Game();
virtual ~Game();
//WIDGETS
Box base, toolbar_box, main_box;
Grid game_grid;
Image brasil_flag;
Button game_button;
ButtonBox game_buttonbox;
Toolbar game_toolbar;
AboutDialog game_aboutdialog;
HelpWindow* help_window= new HelpWindow;
LinkWindow* link_window = new LinkWindow;
FlagWindow* flag_window = new FlagWindow;
//MÉTODOS DA CLASSE
void flag_game();
void help();
void external_links();
void close_credits(int response_id);
void about();
void quit();
                         }; 
