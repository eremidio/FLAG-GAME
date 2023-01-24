//ESSE ARQUIVO TEM A JANELA AUXILIAR CONTENDO BOTÔES COM OS LINKS DA WIKPÉDIA EM PORTUGUÊS COM INFORMAÇÕES SOBRE OS ESTADOS BRASILEIROS (ESTILO SAIBA MAIS)


/*CABEÇALHO*/
#include<gtkmm.h>
using namespace std;
using namespace Gtk;
using namespace Glib;

class LinkWindow: public Window{
public:
//CONSTRUTOR E DESTRUIDOR DA CLASSE
LinkWindow();
virtual ~ LinkWindow();
//WIDGETS
ScrolledWindow link_scrolledwindow;
Grid link_grid;
Label linkinfo_label;
Image acre, alagoas, amapa, amazonas, bahia, ceara, distritofederal, espiritosanto, goias, maranhao, matogrosso, matogrossodosul, minasgerais, para, paraiba, parana, pernambuco, piaui, riodejaneiro, riograndedonorte, riograndedosul, rondonia, roraima, santacatarina, saopaulo, sergipe, tocantins;
Frame acre_frame, alagoas_frame, amapa_frame, amazonas_frame, bahia_frame, ceara_frame, distritofederal_frame, espiritosanto_frame, goias_frame, maranhao_frame, matogrosso_frame, matogrossodosul_frame, minasgerais_frame, para_frame, paraiba_frame, parana_frame, pernambuco_frame, piaui_frame, riodejaneiro_frame, riograndedonorte_frame, riograndedosul_frame, rondonia_frame, roraima_frame, santacatarina_frame, saopaulo_frame, sergipe_frame, tocantins_frame;
LinkButton acre_button, alagoas_button, amapa_button, amazonas_button, bahia_button, ceara_button, distritofederal_button, espiritosanto_button, goias_button, maranhao_button, matogrosso_button, matogrossodosul_button, minasgerais_button, para_button, paraiba_button, parana_button, pernambuco_button, piaui_button, riodejaneiro_button, riograndedonorte_button, riograndedosul_button, rondonia_button, roraima_button, santacatarina_button, saopaulo_button, sergipe_button, tocantins_button;
};

//DESTRUIDOR DA CLASSE
LinkWindow::~LinkWindow(){
};
//CONSTRUTOR DA CLASSE
LinkWindow::LinkWindow(): acre("acre.png"), alagoas("alagoas.png"), amapa("amapa.png"), amazonas("amazonas.png"), bahia("bahia.png"), ceara("ceara.png"), distritofederal("distritofederal.png"), espiritosanto("espiritosanto.png"), goias("goias.png"), maranhao("maranhao.png"), matogrosso("matogrosso.png"), matogrossodosul("matogrossodosul.png"), minasgerais("minasgerais.png"), para("para.png"), paraiba("paraiba.png"), parana("parana.png"), pernambuco("pernambuco.png"), piaui("piaui.png"), riodejaneiro("riodejaneiro.png"), riograndedonorte("riograndedonorte.png"), riograndedosul("riograndedosul.png"), rondonia("rondonia.png"), roraima("roraima.png"), santacatarina("santacatarina.png"), saopaulo("saopaulo.png"), sergipe("sergipe.png"), tocantins("tocantins.png"), acre_frame("Acre"), alagoas_frame("Alagoas"), amapa_frame("Amapá"), amazonas_frame("Amazonas"), bahia_frame("Bahia"), ceara_frame("Ceará"), distritofederal_frame("Distrito Federal"), espiritosanto_frame("Espirito Santo"), goias_frame("Goiás"), maranhao_frame("Maranhão"), matogrosso_frame("Mato Grosso"), matogrossodosul_frame("Mato Grosso do Sul"), minasgerais_frame("Minas Gerais"), para_frame("Pará"), paraiba_frame("Paraíba"), parana_frame("Paraná"), pernambuco_frame("Pernambuco"), piaui_frame("Piauí"), riodejaneiro_frame("Rio de Janeiro"), riograndedonorte_frame("Rio Grande do Norte"), riograndedosul_frame("Rio Grande do Sul"), rondonia_frame("Rondônia"), roraima_frame("Roraima"), santacatarina_frame("Santa Catarina"), saopaulo_frame("São Paulo"), sergipe_frame("Sergipe"), tocantins_frame("Tocantins"), acre_button("https://pt.wikipedia.org/wiki/Acre", "Saiba mais"), alagoas_button("https://pt.wikipedia.org/wiki/Alagoas", "Saiba mais"), amapa_button("https://pt.wikipedia.org/wiki/Amapá", "Saiba mais"), amazonas_button("https://pt.wikipedia.org/wiki/Amazonas", "Saiba mais"), bahia_button("https://pt.wikipedia.org/wiki/Bahia", "Saiba mais"), ceara_button("https://pt.wikipedia.org/wiki/Ceará", "Saiba mais"), distritofederal_button("https://pt.wikipedia.org/wiki/Distrito_Federal_(Brasil)", "Saiba mais"), espiritosanto_button("https://pt.wikipedia.org/wiki/Espírito_Santo_(estado)", "Saiba mais"), goias_button("https://pt.wikipedia.org/wiki/Goiás", "Saiba mais"), maranhao_button("https://pt.wikipedia.org/wiki/Maranhão", "Saiba mais"), matogrosso_button("https://pt.wikipedia.org/wiki/Mato_Grosso", "Saiba mais"), matogrossodosul_button("https://pt.wikipedia.org/wiki/Mato_Grosso_do_Sul", "Saiba mais"), minasgerais_button("https://pt.wikipedia.org/wiki/Minas_Gerais", "Saiba mais"), para_button("https://pt.wikipedia.org/wiki/Pará", "Saiba mais"), paraiba_button("https://pt.wikipedia.org/wiki/Paraíba", "Saiba mais"), parana_button("https://pt.wikipedia.org/wiki/Paraná", "Saiba mais"), pernambuco_button("https://pt.wikipedia.org/wiki/Pernambuco", "Saiba mais"), piaui_button("https://pt.wikipedia.org/wiki/Piauí", "Saiba mais"), riodejaneiro_button("https://pt.wikipedia.org/wiki/Rio_de_Janeiro_(estado)", "Saiba mais"), riograndedonorte_button("https://pt.wikipedia.org/wiki/Rio_Grande_do_Norte", "Saiba mais"), riograndedosul_button("https://pt.wikipedia.org/wiki/Rio_Grande_do_Sul", "Saiba mais"), rondonia_button("https://pt.wikipedia.org/wiki/Rondônia", "Saiba mais"), roraima_button("https://pt.wikipedia.org/wiki/Roraima", "Saiba mais"), santacatarina_button("https://pt.wikipedia.org/wiki/Santa_Catarina", "Saiba mais"), saopaulo_button("https://pt.wikipedia.org/wiki/São_Paulo_(estado)", "Saiba mais"), sergipe_button("https://pt.wikipedia.org/wiki/Sergipe", "Saiba mais"), tocantins_button("https://pt.wikipedia.org/wiki/Tocantins", "Saiba mais")
{
add(link_scrolledwindow);
link_scrolledwindow.add(link_grid);
link_scrolledwindow.set_policy(POLICY_AUTOMATIC, POLICY_AUTOMATIC);
link_grid.set_column_homogeneous(true);
set_border_width(10);
//CONFIGURANDO O RÓTULO
link_grid.attach(linkinfo_label, 0, 0, 2, 1);
linkinfo_label.set_line_wrap();
linkinfo_label.set_justify(JUSTIFY_FILL);
linkinfo_label.set_text("Para maiores informações sobre o estados do Brasil. Clique em \"Saiba mais\"");
//ADICIONANDO OS BOTÔES E AS BANDEIRAS DE CADA ESTADO
link_grid.attach(acre_frame, 0, 1, 1, 1);
acre_frame.add(acre);
link_grid.attach(acre_button, 1, 1, 1, 1);
link_grid.attach(alagoas_frame, 0, 2, 1, 1);
alagoas_frame.add(alagoas);
link_grid.attach(alagoas_button, 1, 2, 1, 1);
link_grid.attach(amapa_frame, 0, 3, 1, 1);
amapa_frame.add(amapa);
link_grid.attach(amapa_button, 1, 3, 1, 1);
link_grid.attach(amazonas_frame, 0, 4, 1, 1);
amazonas_frame.add(amazonas);
link_grid.attach(amazonas_button, 1, 4, 1, 1);
link_grid.attach(bahia_frame, 0, 5, 1, 1);
bahia_frame.add(bahia);
link_grid.attach(bahia_button, 1, 5, 1, 1);
link_grid.attach(ceara_frame, 0, 6, 1, 1);
ceara_frame.add(ceara);
link_grid.attach(ceara_button, 1, 6, 1, 1);
link_grid.attach(distritofederal_frame, 0, 7, 1, 1);
distritofederal_frame.add(distritofederal);
link_grid.attach(distritofederal_button, 1, 7, 1, 1);
link_grid.attach(espiritosanto_frame, 0, 8, 1, 1);
espiritosanto_frame.add(espiritosanto);
link_grid.attach(espiritosanto_button, 1, 8, 1, 1);
link_grid.attach(goias_frame, 0, 9, 1, 1);
goias_frame.add(goias);
link_grid.attach(goias_button, 1, 9, 1, 1);
link_grid.attach(maranhao_frame, 0, 10, 1, 1);
maranhao_frame.add(maranhao);
link_grid.attach(maranhao_button, 1, 10, 1, 1);
link_grid.attach(matogrosso_frame, 0, 11, 1, 1);
matogrosso_frame.add(matogrosso);
link_grid.attach(matogrosso_button, 1, 11, 1, 1);
link_grid.attach(matogrossodosul_frame, 0, 12, 1, 1);
matogrossodosul_frame.add(matogrossodosul);
link_grid.attach(matogrossodosul_button, 1, 12, 1, 1);
link_grid.attach(minasgerais_frame, 0, 13, 1, 1);
minasgerais_frame.add(minasgerais);
link_grid.attach(minasgerais_button, 1, 13, 1, 1);
link_grid.attach(para_frame, 0, 14, 1, 1);
para_frame.add(para);
link_grid.attach(para_button, 1, 14, 1, 1);
link_grid.attach(paraiba_frame, 0, 15, 1, 1);
paraiba_frame.add(paraiba);
link_grid.attach(paraiba_button, 1, 15, 1, 1);
link_grid.attach(parana_frame, 0, 16, 1, 1);
parana_frame.add(parana);
link_grid.attach(parana_button, 1, 16, 1, 1);
link_grid.attach(pernambuco_frame, 0, 17, 1, 1);
pernambuco_frame.add(pernambuco);
link_grid.attach(pernambuco_button, 1, 17, 1, 1);
link_grid.attach(piaui_frame, 0, 18, 1, 1);
piaui_frame.add(piaui);
link_grid.attach(piaui_button, 1, 18, 1, 1);
link_grid.attach(riodejaneiro_frame, 0, 19, 1, 1);
riodejaneiro_frame.add(riodejaneiro);
link_grid.attach(riodejaneiro_button, 1, 19, 1, 1);
link_grid.attach(riograndedonorte_frame, 0, 20, 1, 1);
riograndedonorte_frame.add(riograndedonorte);
link_grid.attach(riograndedonorte_button, 1, 20, 1, 1);
link_grid.attach(riograndedonorte_frame, 0, 20, 1, 1);
riograndedonorte_frame.add(riograndedonorte);
link_grid.attach(riograndedonorte_button, 1, 20, 1, 1);
link_grid.attach(riograndedosul_frame, 0, 21, 1, 1);
riograndedosul_frame.add(riograndedosul);
link_grid.attach(riograndedosul_button, 1, 21, 1, 1);
link_grid.attach(rondonia_frame, 0, 22, 1, 1);
rondonia_frame.add(rondonia);
link_grid.attach(rondonia_button, 1, 22, 1, 1);
link_grid.attach(roraima_frame, 0, 23, 1, 1);
roraima_frame.add(roraima);
link_grid.attach(roraima_button, 1, 23, 1, 1);
link_grid.attach(santacatarina_frame, 0, 24, 1, 1);
santacatarina_frame.add(santacatarina);
link_grid.attach(santacatarina_button, 1, 24, 1, 1);
link_grid.attach(saopaulo_frame, 0, 25, 1, 1);
saopaulo_frame.add(saopaulo);
link_grid.attach(saopaulo_button, 1, 25, 1, 1);
link_grid.attach(sergipe_frame, 0, 26, 1, 1);
sergipe_frame.add(sergipe);
link_grid.attach(sergipe_button, 1, 26, 1, 1);
link_grid.attach(tocantins_frame, 0, 27, 1, 1);
tocantins_frame.add(tocantins);
link_grid.attach(tocantins_button, 1, 27, 1, 1);
};
