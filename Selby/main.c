#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <stdio.h>
#include <stdbool.h>

const int LARGURA_TELA = 1280;
const int ALTURA_TELA = 720;

ALLEGRO_DISPLAY *janela = NULL;
ALLEGRO_EVENT_QUEUE *fila_eventos = NULL;
ALLEGRO_BITMAP *tela_inicio, *boas_vindas , *teste= NULL;
ALLEGRO_FONT *fonte = NULL;


bool inicializar(){
    if (!al_init()){
        fprintf(stderr, "Falha ao inicializar a Allegro.\n");
        return false;
    }

    if (!al_init_primitives_addon()) {
        fprintf(stderr, "Falha ao iniciar primitives_addon\n");
        return false;
    }

    al_init_font_addon();
    if (!al_init_ttf_addon()){
        fprintf(stderr, "Falha ao inicializar add-on allegro_ttf.\n");
        al_shutdown_primitives_addon();
        return false;
    }

    if (!al_init_image_addon()){
        fprintf(stderr, "Falha ao inicializar add-on allegro_image.\n");
        al_shutdown_ttf_addon();
        al_shutdown_font_addon();
        al_shutdown_primitives_addon();
        return false;
    }

    if (!al_install_audio()) {
        fprintf(stderr, "Falha ao iniciar audio\n");
        al_shutdown_image_addon();
        al_shutdown_ttf_addon();
        al_shutdown_font_addon();
        al_shutdown_primitives_addon();
        return false;
    }

    if(!al_init_acodec_addon()) {
        fprintf(stderr, "al_init_acodec_addon\n");
        al_uninstall_audio();
        al_shutdown_image_addon();
        al_shutdown_ttf_addon();
        al_shutdown_font_addon();
        al_shutdown_primitives_addon();
        return false;
    }

        if (!al_install_mouse()) {
        fprintf(stderr, "al_install_mouse\n");
        al_uninstall_audio();
        al_shutdown_image_addon();
        al_shutdown_ttf_addon();
        al_shutdown_font_addon();
        al_shutdown_primitives_addon();
        return false;
    }


    janela = al_create_display(LARGURA_TELA, ALTURA_TELA);
    if (!janela){
        fprintf(stderr, "Falha ao criar janela.\n");
        al_uninstall_mouse();
        al_uninstall_audio();
        al_shutdown_image_addon();
        al_shutdown_ttf_addon();
        al_shutdown_font_addon();
        al_shutdown_primitives_addon();
        return false;
    }

    al_set_window_title(janela, "Selby Space");

    fonte = al_load_font("res/font/comic.ttf", 72, 0);
    if (!fonte){
        fprintf(stderr, "Falha ao carregar \"fonte comic.ttf\".\n");
        al_destroy_display(janela);
        al_uninstall_mouse();
        al_uninstall_audio();
        al_shutdown_image_addon();
        al_shutdown_ttf_addon();
        al_shutdown_font_addon();
        al_shutdown_primitives_addon();
        return false;
    }

    fila_eventos = al_create_event_queue();
    if (!fila_eventos){
        fprintf(stderr, "Falha ao criar fila de eventos.\n");
        al_destroy_font(fonte);
        al_destroy_display(janela);
        al_uninstall_mouse();
        al_uninstall_audio();
        al_shutdown_image_addon();
        al_shutdown_ttf_addon();
        al_shutdown_font_addon();
        al_shutdown_primitives_addon();
        return false;
    }

    tela_inicio = al_load_bitmap("res/img/inicio.png");
    if (!tela_inicio){
        fprintf(stderr, "Falha ao carregar imagem.\n");
        al_destroy_event_queue(fila_eventos);
        al_destroy_font(fonte);
        al_destroy_display(janela);
        al_uninstall_mouse();
        al_uninstall_audio();
        al_shutdown_image_addon();
        al_shutdown_ttf_addon();
        al_shutdown_font_addon();
        al_shutdown_primitives_addon();
        return false;
    }

    boas_vindas = al_load_bitmap("res/img/fundo.png");
    if (!boas_vindas){
        fprintf(stderr, "Falha ao carregar tela.\n");
        al_destroy_bitmap(tela_inicio);
        al_destroy_event_queue(fila_eventos);
        al_destroy_font(fonte);
        al_destroy_display(janela);
        al_uninstall_mouse();
        al_uninstall_audio();
        al_shutdown_image_addon();
        al_shutdown_ttf_addon();
        al_shutdown_font_addon();
        al_shutdown_primitives_addon();
        return false;
    }

    if (!al_install_keyboard()){
        fprintf(stderr, "Falha ao inicializar o teclado.\n");
        al_destroy_bitmap(boas_vindas);
        al_destroy_bitmap(tela_inicio);
        al_destroy_event_queue(fila_eventos);
        al_destroy_font(fonte);
        al_destroy_display(janela);
        al_uninstall_mouse();
        al_uninstall_audio();
        al_shutdown_image_addon();
        al_shutdown_ttf_addon();
        al_shutdown_font_addon();
        al_shutdown_primitives_addon();
        return false;
    }


    al_register_event_source(fila_eventos, al_get_keyboard_event_source());
    al_register_event_source(fila_eventos, al_get_display_event_source(janela));

    return true;
}

bool start_ok(){
    if (inicializar()){
        return true;
    } else {
        al_uninstall_keyboard();
        al_destroy_bitmap(boas_vindas);
        al_destroy_bitmap(tela_inicio);
        al_destroy_event_queue(fila_eventos);
        al_destroy_font(fonte);
        al_destroy_display(janela);
        al_uninstall_mouse();
        al_uninstall_audio();
        al_shutdown_image_addon();
        al_shutdown_ttf_addon();
        al_shutdown_font_addon();
        al_shutdown_primitives_addon();
        return false;
    }
}


bool inicializar();


int main(void){
    bool sair = false;//Iniciei a variavel sair como false..
    int tecla = 0;

    if (!start_ok()){ //Verifica se tudo iniciou certo
        return -1;
    }

    al_draw_bitmap(tela_inicio, 0, 0, 0); // Desenha o menu na tela

    while (!sair){
        while(!al_is_event_queue_empty(fila_eventos)){
            ALLEGRO_EVENT evento; //Declaração  do evento
            al_wait_for_event(fila_eventos, &evento);// Espera evento na fila de eventos e inclui na var eventos


            //Parte da tela inicial
            //Captura tecla
            if (evento.type == ALLEGRO_EVENT_KEY_DOWN){ // se o tipo do evento for press no teclado
                switch(evento.keyboard.keycode){ // da um switch no evento, para saber oque foi informado
                case ALLEGRO_KEY_SPACE: //Caso o usuario informe SPACE
                    tecla = 1;
                    break;
                case ALLEGRO_KEY_ESCAPE:
                    sair = true;
                    break;
                }
            } else if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE){ // se houver o clique no "x" (Fechar janela)
                sair = true;
            }

            if (tecla){
                switch (tecla){ //Caso tenha digitado space
                case 1:
                    al_destroy_bitmap(tela_inicio);// Destroi a tela de inicio
                    al_draw_bitmap(boas_vindas, 0, 0, 0);//desenha a tela seguinte
                    char *texto = "Bem Vindo ao SelbySpace";
                    al_draw_text(fonte, al_map_rgb(12, 9, 222), LARGURA_TELA / 2, ALTURA_TELA/5, ALLEGRO_ALIGN_CENTRE, texto);
                    break;
                }
                tecla = 0;
            }
        }


        al_flip_display();
    }

    al_destroy_display(janela); // Fecha a janela
    al_destroy_event_queue(fila_eventos);// Fecha a fila de eventos

    return 0;
}
