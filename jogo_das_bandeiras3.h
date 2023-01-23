//NESTE ARQUIVO VAMOS INNSTANCIAR OS MÉTODOS DA CLASSE DO APP CONTENDO A JANELA SECUNDARÍA DO JOGO DE ADIVINHAÇÃO DAS BANDEIRAS
//NESTA JANELA HAVERÁ O NOME DA BANDEIRA, O USUÁRIO DEVERÁ SELECIONAR O ESTADO E A CAPITAL DO ESTADO, APÓS PRESSIONAR O BOTÃO DE CONFIRMAÇÃO

/*CABEÇALHO*/
#include<gtkmm.h>
#include<string>
using namespace std;
using namespace Gtk;
using namespace Glib;

class FlagWindow: public Window{
public:
//CONSTRUTOR E DESTRUIDOR DA CLASSE
FlagWindow();
virtual ~FlagWindow();
//WIDGETS
Box base, box1, box2, box21, box22, box3;
Frame game_frame, flag_frame, option_frame, state_frame, capital_frame, buttonbox_frame;
Grid option_grid;
ScrolledWindow flag_scrolledwindow;
ComboBoxText state_combobox, capital_combobox;
Label game_label;
Separator flag_separator;
Image acre, alagoas, amapa, amazonas, bahia, ceara, distritofederal, espiritosanto, goias, maranhao, matogrosso, matogrossodosul, minasgerais, para, paraiba, parana, pernambuco, piaui, riodejaneiro, riograndedonorte, riograndedosul, rondonia, roraima, santacatarina, saopaulo, sergipe, tocantins;
ButtonBox buttonbox1;
Button reset_button, answer_button, quit_button;

//VARIÁVEIS DE BACK-END
int int_option;
bool is_correct;
string state, capital;
//MÉTODOS DA CLASSE
void select_option();
void set_flag();
void set_state();
void set_capital();
void send_answer();
void check_answer();
void exit_flag_window();
};
