#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <stdio.h>
#include <stdbool.h>

#define fontSize 42

const int LARGURA_TELA = 1280;
const int ALTURA_TELA = 720;

ALLEGRO_DISPLAY *janela = NULL;
ALLEGRO_EVENT_QUEUE *fila_eventos = NULL;
ALLEGRO_BITMAP *tela_inicio = NULL;
ALLEGRO_BITMAP *boas_vindas[2] = {NULL, NULL};
ALLEGRO_FONT *fonte = NULL;
ALLEGRO_COLOR *cor_fonte_principal = NULL;


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

    fonte = al_load_font("res/font/comic.ttf", fontSize, 0);
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

    tela_inicio = al_load_bitmap("res/img/inicio/menuIniciar.jpg");
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

    boas_vindas[1] = al_load_bitmap("res/img/transicoes_de_tela/boasvindas.jpg");
    if (!boas_vindas[1]){
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

    boas_vindas[2] = al_load_bitmap("res/img/transicoes_de_tela/boasvindas2.jpg");
    if (!boas_vindas[2]){
        fprintf(stderr, "Falha ao carregar tela.\n");
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

void troca_tela(ALLEGRO_BITMAP *img1, ALLEGRO_BITMAP *img2){
    al_destroy_bitmap(img1);// Destroi a tela de inicio
    al_flip_display();
    al_draw_bitmap(img2, 0, 0, 0);
    al_flip_display();
}


int main(void){
    bool inicializar();

    bool sair = false;
    bool concluido = false;
    int tecla = 0;


    // Desenha Tela de inicio
    al_flip_display();
    al_draw_bitmap(tela_inicio, 0, 0, 0);
    al_flip_display();

    while (!sair){
        while(!al_is_event_queue_empty(fila_eventos)){
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);



            if (evento.type == ALLEGRO_EVENT_KEY_DOWN){
                if (evento.keyboard.keycode == ALLEGRO_KEY_SPACE){
                    tecla = 1;
                } else if (evento.keyboard.keycode == ALLEGRO_KEY_ESCAPE){
                    tecla = 2;
                }
            }
            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE){ // se houver o clique no "x" (Fechar janela)
                sair = true;
            }

            switch (tecla){
            case 1://Caso tenha digitado space
                troca_tela(tela_inicio, boas_vindas[1]);//desenha a tela seguinte
                //char *texto = "Bem Vindo ao\nSelbySpace";
                //al_draw_text(fonte, al_map_rgb(255,255,255), 260, 0, ALLEGRO_ALIGN_CENTER, texto);
                break;
            }
            tecla = 0;
        }
        if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE){ // se houver o clique no "x" (Fechar janela)
                sair = true;
            }
    }
    al_flip_display();
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
    return 0;
}
