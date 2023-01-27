//ESTE ARQUIVO CONTÉM OS MÉTODOS DA CLASSE DA JANELA SECUNDÁRIA DO JOGO DAS BANDEIRAS

/*1: USAREMOS A SEGUINTE CORRESPODÊNCIA PARA O NOME DOS ESTADOS E CAṔITAIS:
acre--> 0 , alagoas--> 1, amapa--> 2, amazonas--> 3, bahia--> 4, ceara--> 5, distritofederal--> 6, espiritosanto--> 7,
goias--> 8, maranhao--> 9, matogrosso--> 10, matogrossodosul--> 11, minasgerais--> 12, para--> 13, paraiba--> 14,
parana--> 15, pernambuco--> 16, piaui--> 17, riodejaneiro--> 18, riograndedonorte--> 19, riograndedosul--> 20, rondonia--> 21, roraima--> 22, santacatarina--> 23, saopaulo--> 24, sergipe--> 25, tocantins--> 26.

*/

/*CABEÇALHO*/
#include"jogo_das_bandeiras3.h"
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
using namespace std;
using namespace Gtk;
using namespace Glib;

//DESTRUIDOR DA CLASSE
FlagWindow::~FlagWindow(){
};
//CONSTRUTOR DA CLASSE
FlagWindow::FlagWindow():base(ORIENTATION_VERTICAL, 5), box1(ORIENTATION_HORIZONTAL, 5), box2(ORIENTATION_HORIZONTAL, 5), box21(ORIENTATION_VERTICAL, 5), box22(ORIENTATION_VERTICAL, 5), box3(ORIENTATION_HORIZONTAL, 5), state_combobox(true), capital_combobox(true), reset_button("Escolha"), answer_button("Checar a \nresposta"), quit_button("Sair"), acre("acre.png"), alagoas("alagoas.png"), amapa("amapa.png"), amazonas("amazonas.png"), bahia("bahia.png"), ceara("ceara.png"), distritofederal("distritofederal.png"), espiritosanto("espiritosanto.png"), goias("goias.png"), maranhao("maranhao.png"), matogrosso("matogrosso.png"), matogrossodosul("matogrossodosul.png"), minasgerais("minasgerais.png"), para("para.png"), paraiba("paraiba.png"), parana("parana.png"), pernambuco("pernambuco.png"), piaui("piaui.png"), riodejaneiro("riodejaneiro.png"), riograndedonorte("riograndedonorte.png"), riograndedosul("riograndedosul.png"), rondonia("rondonia.png"), roraima("roraima.png"), santacatarina("santacatarina.png"), saopaulo("saopaulo.png"), sergipe("sergipe.png"), tocantins("tocantins.png"), buttonbox1(ORIENTATION_HORIZONTAL)
{//AJUSTE DE LAYOUT BÁSICO DO APLICATIVO
add(base);
base.pack_start(box1, PACK_EXPAND_WIDGET, 5);
base.pack_start(box2, PACK_EXPAND_WIDGET, 5);
box2.pack_start(box21, PACK_EXPAND_WIDGET, 5);
box2.pack_start(box22, PACK_EXPAND_WIDGET, 5);
base.pack_start(box3, PACK_EXPAND_WIDGET, 5);
//ADICIONANDO UM RÓTULO COM INSTRUÇÕES DO JOGO
box1.pack_start(game_frame, PACK_EXPAND_WIDGET, 5);
game_frame.add(game_label);
game_label.set_text("REGRAS DO JOGO:\n1. CLIQUE NO BOTÃO 'ESCOLHA' E EM SEGUIDA SELECIONE O NOME DO ESTADO E SUA RESPECTIVA CAPITAL.\n2. USE O BOTÃO 'CHECAR A RESPOSTA' PARA VEFIRICAR POSSÍVEIS ACERTOS OU ERROS\n3. APERTE O BOTÃO 'SAIR' PARA FECHAR ESTA JANELA E RETORNAR A JANELA PRINCIPAL DO APLICATIVO.");
game_label.set_line_wrap();
//ADICIONANDO A JANELA QUE IRA CONTER A IMAGEM DA BANDEIRA DO ESTADO
box21.pack_start(flag_frame, PACK_EXPAND_WIDGET, 5);
flag_frame.set_label("Bandeira:");
flag_frame.add(flag_scrolledwindow);
flag_scrolledwindow.set_policy(POLICY_AUTOMATIC, POLICY_AUTOMATIC);
//ADICIONANDO AS COMBOBOXES QUE PERMITIRÃO AO USUÁRIO SELECIONAR O ESTADO E A CAPITAL DO ESTADO
box22.pack_start(option_frame, PACK_EXPAND_WIDGET, 5);
option_frame.add(option_grid);
option_grid.set_row_homogeneous(true);
option_grid.set_column_homogeneous(true);
option_grid.attach(state_frame, 0, 0, 1, 1);
state_frame.set_shadow_type(SHADOW_NONE);
state_frame.set_label("Selecione o estado:");
state_frame.add(state_combobox);
state_combobox.property_has_frame() = false;
option_grid.attach(capital_frame, 0, 1, 1, 1);
capital_frame.set_shadow_type(SHADOW_NONE);
capital_frame.set_label("Selecione a capital do estado:");
capital_frame.add(capital_combobox);
capital_combobox.property_has_frame() = false;
//ADICIONANDO AS OPÇÕES ESCOLHA A COMBOBOXES
//SELEÇÃO DE ESTADO
state_combobox.append(" ");
state_combobox.append("Acre");
state_combobox.append("Alagoas");
state_combobox.append("Amapá");
state_combobox.append("Amazonas");
state_combobox.append("Bahia");
state_combobox.append("Ceará");
state_combobox.append("Distrito Federal");
state_combobox.append("Espirito Santo");
state_combobox.append("Goiás");
state_combobox.append("Maranhão");
state_combobox.append("Mato Grosso");
state_combobox.append("Mato Grosso do Sul");
state_combobox.append("Minas Gerais");
state_combobox.append("Pará");
state_combobox.append("Paraíba");
state_combobox.append("Paraná");
state_combobox.append("Pernambuco");
state_combobox.append("Piauí");
state_combobox.append("Rio de Janeiro");
state_combobox.append("Rio Grande do Norte");
state_combobox.append("Rio Grande do Sul");
state_combobox.append("Rondônia");
state_combobox.append("Roraima");
state_combobox.append("Santa Catarina");
state_combobox.append("São Paulo");
state_combobox.append("Sergipe");
state_combobox.append("Tocantins");
//SELEÇÃO DE CAPITAL DE ESTADO
capital_combobox.append("");
capital_combobox.append("Rio Branco");
capital_combobox.append("Maceió");
capital_combobox.append("Macapá");
capital_combobox.append("Manaus");
capital_combobox.append("Salvador");
capital_combobox.append("Fortaleza");
capital_combobox.append("Brasília");
capital_combobox.append("Vitória");
capital_combobox.append("Goiânia");
capital_combobox.append("São Luís");
capital_combobox.append("Cuiabá");
capital_combobox.append("Campo Grande");
capital_combobox.append("Belo Horizonte");
capital_combobox.append("Belém");
capital_combobox.append("João Pessoa");
capital_combobox.append("Curitiba");
capital_combobox.append("Recife");
capital_combobox.append("Teresina");
capital_combobox.append("Rio de Janeiro");
capital_combobox.append("Natal");
capital_combobox.append("Porto Alegre");
capital_combobox.append("Porto Velho");
capital_combobox.append("Boa Vista");
capital_combobox.append("Florianópolis");
capital_combobox.append("São Paulo");
capital_combobox.append("Aracaju");
capital_combobox.append("Palmas");
//ATIVANDO AS COMBOXES DE SELEÇÃO
state_combobox.set_active(0);
capital_combobox.set_active(0);
auto state_entry = state_combobox.get_entry();
auto capital_entry=capital_combobox.get_entry();
state_combobox.signal_changed().connect(sigc::mem_fun(*this, &FlagWindow::set_state));
capital_combobox.signal_changed().connect(sigc::mem_fun(*this, &FlagWindow::set_capital));
//CONFIGURANDO A CAIXA DE BOTÕES
box3.pack_start(flag_separator, PACK_SHRINK);
box3.pack_start(buttonbox1, PACK_EXPAND_WIDGET, 5);
buttonbox1.pack_start(reset_button);
buttonbox1.pack_start(answer_button);
buttonbox1.pack_start(quit_button);
reset_button.set_tooltip_text("Use este botão para selecionar a bandeira correspondente a um estado do Brasil.");
answer_button.set_tooltip_text("Use este botão para checar se suas respostas estão corretas.");
buttonbox1.set_layout(BUTTONBOX_SPREAD);
//ATIVANDO OS BOTÔES DA CAIXA DE BOTÕES
reset_button.signal_clicked().connect(sigc::mem_fun(*this, &FlagWindow::select_option));
answer_button.signal_clicked().connect(sigc::mem_fun(*this, &FlagWindow::send_answer));
quit_button.signal_clicked().connect(sigc::mem_fun(*this, &FlagWindow::exit_flag_window));
//EXIBINDO OS WIDGETS
show_all_children();
};/*FIM DO CONSTRUTOR DA CLASSE DE JANELA SECUNDÁRIA DO JOGO*/


//MÉTODOS DA CLASSE
void FlagWindow::select_option(){
//SEMENTE PARA GERAÇÃO DE NÚMEROS ALEATÓRIOS
srand(time(NULL));
int_option=rand()%27;
flag_scrolledwindow.remove();
set_flag();
state_combobox.set_active(0);
capital_combobox.set_active(0);
state="";
capital="";
                                };

void FlagWindow::set_flag(){
if (int_option==0){
flag_scrolledwindow.add(acre);
acre.show();
                  };

if (int_option==1){
flag_scrolledwindow.add(alagoas);
alagoas.show();
                  };
if (int_option==2){
flag_scrolledwindow.add(amapa);
amapa.show();
                  };
if (int_option==3){
flag_scrolledwindow.add(amazonas);
amazonas.show();
                  };
if (int_option==4){
flag_scrolledwindow.add(bahia);
bahia.show();
                  };
if (int_option==5){
flag_scrolledwindow.add(ceara);
ceara.show();
                  };
if (int_option==6){
flag_scrolledwindow.add(distritofederal);
distritofederal.show();
                  };
if (int_option==7){
flag_scrolledwindow.add(espiritosanto);
espiritosanto.show();
                  };
if (int_option==8){
flag_scrolledwindow.add(goias);
goias.show();
                  };
if (int_option==9){
flag_scrolledwindow.add(maranhao);
maranhao.show();
                  };
if (int_option==10){
flag_scrolledwindow.add(matogrosso);
matogrosso.show();
                  };
if (int_option==11){
flag_scrolledwindow.add(matogrossodosul);
matogrossodosul.show();
                  };
if (int_option==12){
flag_scrolledwindow.add(minasgerais);
minasgerais.show();
                  };
if (int_option==13){
flag_scrolledwindow.add(para);
para.show();
                  };
if (int_option==14){
flag_scrolledwindow.add(paraiba);
paraiba.show();
                  };
if (int_option==15){
flag_scrolledwindow.add(parana);
parana.show();
                  };
if (int_option==16){
flag_scrolledwindow.add(pernambuco);
pernambuco.show();
                  };
if (int_option==17){
flag_scrolledwindow.add(piaui);
piaui.show();
                  };
if (int_option==18){
flag_scrolledwindow.add(riodejaneiro);
riodejaneiro.show();
                  };
if (int_option==19){
flag_scrolledwindow.add(riograndedonorte);
riograndedonorte.show();
                  };
if (int_option==20){
flag_scrolledwindow.add(riograndedosul);
riograndedosul.show();
                  };
if (int_option==21){
flag_scrolledwindow.add(rondonia);
rondonia.show();
                  };
if (int_option==22){
flag_scrolledwindow.add(roraima);
roraima.show();
                  };
if (int_option==23){
flag_scrolledwindow.add(santacatarina);
santacatarina.show();
                  };
if (int_option==24){
flag_scrolledwindow.add(saopaulo);
saopaulo.show();
                  };
if (int_option==25){
flag_scrolledwindow.add(sergipe);
sergipe.show();
                  };
if (int_option==26){
flag_scrolledwindow.add(tocantins);
tocantins.show();
                   };

                            };

void FlagWindow::set_state(){
state=state_combobox.get_active_text();
                };

void FlagWindow::set_capital(){
capital=capital_combobox.get_active_text();
                  };

void FlagWindow::check_answer(){
if(int_option==0 && state=="Acre" && capital=="Rio Branco")
{ is_correct=true; return;}
else if(int_option==1 && state=="Alagoas" && capital=="Maceió")
{ is_correct=true; return;}
else if(int_option==2 && state=="Amapá" && capital=="Macapá")
{ is_correct=true; return;}
else if(int_option==3 && state=="Amazonas" && capital=="Manaus")
{ is_correct=true; return;}
else if(int_option==4 && state=="Bahia" && capital=="Salvador")
{ is_correct=true; return;}
else if(int_option==5 && state=="Ceará" && capital=="Fortaleza")
{ is_correct=true; return;}
else if(int_option==6 && state=="Distrito Federal" && capital=="Brasília")
{ is_correct=true; return;}
else if(int_option==7 && state=="Espirito Santo" && capital=="Vitória")
{ is_correct=true; return;}
else if(int_option==8 && state=="Goiás" && capital=="Goiânia")
{ is_correct=true; return;}
else if(int_option==9 && state=="Maranhão" && capital=="São Luís")
{ is_correct=true; return;}
else if(int_option==10 && state=="Mato Grosso" && capital=="Cuiabá")
{ is_correct=true; return;}
else if(int_option==11 && state=="Mato Grosso do Sul" && capital=="Campo Grande")
{ is_correct=true; return;}
else if(int_option==12 && state=="Minas Gerais" && capital=="Belo Horizonte")
{ is_correct=true; return;}
else if(int_option==13 && state=="Pará" && capital=="Belém")
{ is_correct=true; return;}
else if(int_option==14 && state=="Paraíba" && capital=="João Pessoa")
{ is_correct=true; return;}
else if(int_option==15 && state=="Paraná" && capital=="Curitiba")
{ is_correct=true; return;}
else if(int_option==16 && state=="Pernambuco" && capital=="Recife")
{ is_correct=true; return;}
else if(int_option==17 && state=="Piauí" && capital=="Teresina")
{ is_correct=true; return;}
else if(int_option==18 && state=="Rio de Janeiro" && capital=="Rio de Janeiro")
{ is_correct=true; return;}
else if(int_option==19 && state=="Rio Grande do Norte" && capital=="Natal")
{ is_correct=true; return;}
else if(int_option==20 && state=="Rio Grande do Sul" && capital=="Porto Alegre")
{ is_correct=true; return;}
else if(int_option==21 && state=="Rondônia" && capital=="Porto Velho")
{ is_correct=true; return;}
else if(int_option==22 && state=="Roraima" && capital=="Boa vista")
{ is_correct=true; return;}
else if(int_option==23 && state=="Santa Catarina" && capital=="Florianópolis")
{ is_correct=true; return;}
else if(int_option==24 && state=="São Paulo" && capital=="São Paulo")
{ is_correct=true; return;}
else if(int_option==25 && state=="Sergipe" && capital=="Aracaju")
{ is_correct=true; return;}
else if(int_option==26 && state=="Tocantins" && capital=="Palmas")
{ is_correct=true; return;}
else
is_correct=false;

                               };

void FlagWindow::send_answer(){
check_answer();
//CRIANDO UMA CAIXA DE DIÁLOGO QUE INFORMA AO USUÁRIO UM ACERTO OU ERRO
if(is_correct==true){
MessageDialog dialog(*this,"A sua resposta está correta!\nParabéns!!!");
dialog.set_secondary_text("");
dialog.run();
                    };

if(is_correct==false){
MessageDialog dialog(*this,"A sua resposta está errada.\n");
if(int_option==0)
dialog.set_secondary_text("Esta é a bandeira do Acre.\nEstado cuja capital é Rio Branco.\n");
if(int_option==1)
dialog.set_secondary_text("Esta é a bandeira de Alagoas.\nEstado cuja capital é Maceió.\n");
if(int_option==2)
dialog.set_secondary_text("Esta é a bandeira do Amapá.\nEstado cuja capital é Macapá.\n");
if(int_option==3)
dialog.set_secondary_text("Esta é a bandeira de Amazonas.\nEstado cuja capital é Manaus.\n");
if(int_option==4)
dialog.set_secondary_text("Esta é a bandeira da Bahia.\nEstado cuja capital é Salvador.\n");
if(int_option==5)
dialog.set_secondary_text("Esta é a bandeira do Ceará.\nEstado cuja capital é Fortaleza.\n");
if(int_option==6)
dialog.set_secondary_text("Esta é a bandeira do Distrito Federal.\nDistrito com status especial cuja capital admnistrativa é Brasília.\n");
if(int_option==7)
dialog.set_secondary_text("Esta é a bandeira do Espirito Santo.\nEstado cuja capital é Vitória.\n");
if(int_option==8)
dialog.set_secondary_text("Esta é a bandeira de Goiás.\nEstado cuja capital é Goiânia.\n");
if(int_option==9)
dialog.set_secondary_text("Esta é a bandeira do Maranhão.\nEstado cuja capital é São Luís.\n");
if(int_option==10)
dialog.set_secondary_text("Esta é a bandeira do Mato Grosso.\nEstado cuja capital é Cuiabá.\n");
if(int_option==11)
dialog.set_secondary_text("Esta é a bandeira do Mato Grosso do Sul.\nEstado cuja capital é Campo Grande.\n");
if(int_option==12)
dialog.set_secondary_text("Esta é a bandeira de Minas Gerais.\nEstado cuja capital é Belo Horizonte.\n");
if(int_option==13)
dialog.set_secondary_text("Esta é a bandeira do Pará.\nEstado cuja capital é Belém.\n");
if(int_option==14)
dialog.set_secondary_text("Esta é a bandeira da Paraíba.\nEstado cuja capital é João Pessoa.\n");
if(int_option==15)
dialog.set_secondary_text("Esta é a bandeira do Paraná.\nEstado cuja capital é Curitiba.\n");
if(int_option==16)
dialog.set_secondary_text("Esta é a bandeira de Pernambuco.\nEstado cuja capital é Recife.\n");
if(int_option==17)
dialog.set_secondary_text("Esta é a bandeira do Piauí.\nEstado cuja capital é Teresina.\n");
if(int_option==18)
dialog.set_secondary_text("Esta é a bandeira do Rio de Janeiro.\nEstado cuja capital é Rio de Janeiro.\n");
if(int_option==19)
dialog.set_secondary_text("Esta é a bandeira do Rio Grande do Norte.\nEstado cuja capital é Natal.\n");
if(int_option==20)
dialog.set_secondary_text("Esta é a bandeira do Rio Grande do Sul.\nEstado cuja capital é Porto Alegre.\n");
if(int_option==21)
dialog.set_secondary_text("Esta é a bandeira de Rondônia.\nEstado cuja capital é Porto Velho.\n");
if(int_option==22)
dialog.set_secondary_text("Esta é a bandeira do Roraima.\nEstado cuja capital é Boa Vista.\n");
if(int_option==23)
dialog.set_secondary_text("Esta é a bandeira de Santa Catarina.\nEstado cuja capital é Florianópolis.\n");
if(int_option==24)
dialog.set_secondary_text("Esta é a bandeira de São Paulo.\nEstado cuja capital é São Paulo.\n");
if(int_option==25)
dialog.set_secondary_text("Esta é a bandeira de Sergipe.\nEstado cuja capital é Aracaju.\n");
if(int_option==26)
dialog.set_secondary_text("Esta é a bandeira do Tocantins.\nEstado cuja capital é Palmas.\n");
dialog.run();
                     };
                              };

void FlagWindow::exit_flag_window(){
hide();
                                   };
