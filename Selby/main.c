#include <stdio.h>
#include <stdlib.h>

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>


void mostra_caixa_de_texto(){
    char tcaixa[50] = "Meu titulo";
    //o título da mensagem dentro da caixa
    char titulo[100] = "Sou uma caixa de texto";
    //o conteúdo da mensagem exibida
    char texto[200] = "A mensagem a ser exibida deve ficar aqui";
    //mostra a caixa de texto
    int r = al_show_native_message_box(NULL,tcaixa,titulo,texto,NULL,ALLEGRO_MESSAGEBOX_OK_CANCEL);
    printf("%i",r);
    return 0;

}

void mensagem_de_erro(char *text){
	al_show_native_message_box(NULL,"ERRO","Ocorreu o seguinte erro e o programa sera finalizado:",
		text,NULL,ALLEGRO_MESSAGEBOX_ERROR);
}


int main(){

    //VARIAVEIS
    ALLEGRO_DISPLAY *janela = NULL; //VAriavel tipo ALLEGRO_DISPLAY Representando Janela
    ALLEGRO_BITMAP *imagem_principal = NULL; //Variavel tipo ALLEGRO_BITMAP Representando a imagem atual da tela
    ALLEGRO_EVENT_QUEUE *fila_eventos = NULL; //Variavel tipo ALLEGRO_EVENT_QUEUE para fila de eventos

    //INICIALIZAÇÔES
    if (!al_init()){        //Função que inicializa a lib allegro5
        mensagem_de_erro("Erro de inicialização do Allegro");
        return -1;
    }

    if (!al_init_image_addon()){
        mensagem_de_erro("Erro de inicialização do Image Add-on");
        return -1;
    }


    janela = al_create_display(1280,720); //Função que cria o display com os parametros de tamanho em px
    if (!janela){
        mensagem_de_erro("Erro na inicialização do display");
        return -1;
    }

    imagem_principal = al_load_bitmap("res/img/Menu.png");//Função que carrega imagem para variavel
    if (!imagem_principal){
    mensagem_de_erro("Erro no carregamento da imagem");
    return -1;
    }

    fila_eventos = al_create_event_queue();//Função que cria fila de eventos
    if (!fila_eventos){
        mensagem_de_erro("Erro no carregamento da fila de eventos");
        return -1;
    }

    al_draw_bitmap(imagem_principal,0, 0, 0); //Desenha imagem na tela

    al_flip_display(); //Atualiza o que está sendo mostrado na tela

    //**neste lugar colocar evento "clique no inicio**"
    al_rest(3.0); //Função que segura a execução por determinado tempo


    return 0;
}
