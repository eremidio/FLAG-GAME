//ESTE ARQUIVO CONTÉM UMA INSTÂNCIA DA CLASSE DO APLICATIVO
/* PARA COMPILAR ESTE PROGRAMA EM PLATAFORMA LINUX USAR O COMANDO:
   g++ -o jogo_das_bandeiras jogo_das_bandeiras.cpp `pkg-config gtkmm-3.0 --cflags --libs`

   USAR A FLAG `pkg-config gtkmm-3.0 --cflags --libs` PARA COMPILAR EM WINDOWS.

*/

/*CABEÇALHO*/
#include"jogo_das_bandeiras0.h"
#include<gtkmm/application.h>
using namespace std;
using namespace Gtk;
using namespace Glib;

int main(int argc, char* argv[]){
//Ponteiro Smart
RefPtr<Application> app =Application::create(argc, argv);
//Instanciando um objeto da classe de aplicativo e rodando o app
Game flag_game;
flag_game.set_default_size(450, 500);
flag_game.set_title("Jogo das bandeiras");
return app->run(flag_game);
}
