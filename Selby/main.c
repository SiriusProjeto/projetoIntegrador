#include <stdio.h>
#include <stdlib.h>

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>

const int LARGURA_TELA = 1281;
const int ALTURA_TELA = 721;

void mensagem_de_erro(char *text){
	al_show_native_message_box(NULL,"ERRO","Ocorreu o seguinte erro e o programa sera finalizado:",
		text,NULL,ALLEGRO_MESSAGEBOX_ERROR);
}

void desenha_imagem(ALLEGRO_BITMAP *imagem){
    al_draw_bitmap(imagem,0, 0, 0); //Desenha imagem na tela
    al_flip_display(); //Atualiza o que está sendo mostrado na tea
    }

void titulo_da_janela(ALLEGRO_DISPLAY *janela){
    al_set_window_title(janela, "SelbySpace");
}



int main(){

    //VARIAVEIS
    ALLEGRO_DISPLAY *janela = NULL; //VAriavel tipo ALLEGRO_DISPLAY Representando Janela
    ALLEGRO_BITMAP *tela_inicial, *tela_X = NULL; //Variavel tipo ALLEGRO_BITMAP Representando a imagem atual da tela
    ALLEGRO_EVENT_QUEUE *fila_eventos = NULL; //Variavel tipo ALLEGRO_EVENT_QUEUE para fila de eventos
    ALLEGRO_EVENT *evento = NULL;
    int sair = 0; //Variavel para o loop

    //INICIALIZAÇÔES
    if (!al_init()){//Função que inicializa a lib allegro5
        mensagem_de_erro("Erro de inicialização do Allegro");
        return -1;
    }

    if (!al_init_image_addon()){
        mensagem_de_erro("Erro de inicialização do Image Add-on");
        return -1;
    }

    janela = al_create_display(LARGURA_TELA,ALTURA_TELA); //Função que cria o display com os parametros de tamanho em px
    if (!janela){
        mensagem_de_erro("Erro na inicialização do display");
        return -1;
    }


    titulo_da_janela(janela); //Função que define o titulo da janela


    tela_inicial = al_load_bitmap("res/img/Menu.png");//Função que carrega imagem para variavel
    if (!tela_inicial){
    mensagem_de_erro("Erro no carregamento da tela_inicial");
    return -1;
    }

    fila_eventos = al_create_event_queue();//Função que cria fila de eventos
    if (!fila_eventos){
        mensagem_de_erro("Erro no carregamento da fila de eventos");
        return -1;
    }

    if (!al_install_mouse()){//Função que instala a funcionalidade de Mouse
    mensagem_de_erro("Erro ao instalar mouse.");
    return -1;
    }

    // Atribui o cursor padrão do sistema para ser usado
    if (!al_set_system_mouse_cursor(janela, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT)){
        mensagem_de_erro("Erro ao atribuir cursor ao sistema");
        return -1;
    }

    desenha_imagem(tela_inicial);


     //**neste lugar colocar evento "clique no inicio**"
    al_rest(3.0); //Função que segura a execução por determinado tempo



    return 0;
}
