#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <stdio.h>
#include <stdbool.h>

const int LARGURA_TELA = 1280;
const int ALTURA_TELA = 720;

ALLEGRO_DISPLAY *janela = NULL;
ALLEGRO_EVENT_QUEUE *fila_eventos = NULL;
ALLEGRO_BITMAP *tela_inicio, *tela , *teste= NULL;
ALLEGRO_FONT *fonte = NULL;


bool inicializar(){
    if (!al_init()){
        fprintf(stderr, "Falha ao inicializar a Allegro.\n");
        return false;
    }

    al_init_font_addon();
    if (!al_init_ttf_addon()){
        fprintf(stderr, "Falha ao inicializar add-on allegro_ttf.\n");
        return false;
    }

    if (!al_init_image_addon()){
        fprintf(stderr, "Falha ao inicializar add-on allegro_image.\n");
        return false;
    }

    if (!al_install_keyboard()){
        fprintf(stderr, "Falha ao inicializar o teclado.\n");
        return false;
    }

    janela = al_create_display(LARGURA_TELA, ALTURA_TELA);
    if (!janela){
        fprintf(stderr, "Falha ao criar janela.\n");
        return false;
    }

    al_set_window_title(janela, "Selby Space");

    fonte = al_load_font("res/font/comic.ttf", 72, 0);
    if (!fonte){
        fprintf(stderr, "Falha ao carregar \"fonte comic.ttf\".\n");
        al_destroy_display(janela);
        return false;
    }

    fila_eventos = al_create_event_queue();
    if (!fila_eventos){
        fprintf(stderr, "Falha ao criar fila de eventos.\n");
        al_destroy_display(janela);
        return false;
    }

    tela_inicio = al_load_bitmap("res/img/inicio.png");
    if (!tela_inicio){
        fprintf(stderr, "Falha ao carregar imagem.\n");
        return false;
    }

    tela = al_load_bitmap("res/img/fundo.png");
    if (!tela){
        fprintf(stderr, "Falha ao carregar tela.\n");
        return false;
    }


    al_register_event_source(fila_eventos, al_get_keyboard_event_source());
    al_register_event_source(fila_eventos, al_get_display_event_source(janela));

    return true;
}


bool inicializar();


int main(void){
    bool sair = false;//Iniciei a variavel sair como false..
    int tecla = 0;

    if (!inicializar()){ //Verifica se tudo iniciou certo
        return -1;
    }

    al_draw_bitmap(tela_inicio, 0, 0, 0); // Desenha o menu na tela

    while (!sair){
        while(!al_is_event_queue_empty(fila_eventos)){
            ALLEGRO_EVENT evento; //Declaração  do evento
            al_wait_for_event(fila_eventos, &evento);// Espera evento na fila de eventos e inclui na var eventos

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN){ // se o tipo do evento for press no teclado
                switch(evento.keyboard.keycode){ // da um switch no evento, para saber oque foi informado
                case ALLEGRO_KEY_SPACE: //Caso o usuario informe SPACE
                    tecla = 1;
                    break;
                }
            }
            else if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE){ // se houver o clique no "x" (Fechar janela)
                sair = true;
            }
        }

        if (tecla){
            switch (tecla){ //Caso tenha digitado space
            case 1:
                al_destroy_bitmap(tela_inicio);// Destroi a tela de inicio
                al_draw_bitmap(tela, 0, 0, 0);//desenha a tela seguinte
                break;
            }

            tecla = 0;
        }

        al_flip_display();
    }

    al_destroy_display(janela); // Fecha a janela
    al_destroy_event_queue(fila_eventos);// Fecha a fila de eventos

    return 0;
}
