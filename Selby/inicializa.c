#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <stdio.h>
#include <stdbool.h>

bool inicializar(){
    if (!al_init()){
        fprintf(stderr, "Falha ao inicializar a Allegro.\n");
        return -1;
    }

    if (!al_init_primitives_addon()) {
        fprintf(stderr, "Falha ao iniciar primitives_addon\n");
        return -1;
    }

    al_init_font_addon();
    if (!al_init_ttf_addon()){
        fprintf(stderr, "Falha ao inicializar add-on allegro_ttf.\n");
        //al_shutdown_primitives_addon();
        return -1;
    }

    if (!al_init_image_addon()){
        fprintf(stderr, "Falha ao inicializar add-on allegro_image.\n");
        return -1;
    }

    if (!al_install_audio()) {
        fprintf(stderr, "Falha ao iniciar audio\n");
       return -1;
    }

    if(!al_init_acodec_addon()) {
        fprintf(stderr, "al_init_acodec_addon\n");
return -1;
    }

        if (!al_install_mouse()) {
        fprintf(stderr, "al_install_mouse\n");
        return -1;
    }


    janela = al_create_display(LARGURA_TELA, ALTURA_TELA);
    if (!janela){
        fprintf(stderr, "Falha ao criar janela.\n");
        return -1;
    }

    al_set_window_title(janela, "Selby Space");

    fonte = al_load_font("res/font/comic.ttf", fontSize, 0);
    if (!fonte){
        fprintf(stderr, "Falha ao carregar \"fonte comic.ttf\".\n");
        return -1;
    }

    fila_eventos = al_create_event_queue();
    if (!fila_eventos){
        fprintf(stderr, "Falha ao criar fila de eventos.\n");
        return -1;
    }

    tela_inicio = al_load_bitmap("res/img/inicio/menuIniciar.jpg");
    if (!tela_inicio){
        fprintf(stderr, "Falha ao carregar imagem.\n");
        return -1;
    }

    boas_vindas[0] = al_load_bitmap("res/img/transicoes_de_tela/boasvindas.jpg");
    if (!boas_vindas[0]){
        fprintf(stderr, "Falha ao carregar tela 1.\n");
        return -1;
    }

    boas_vindas[1] = al_load_bitmap("res/img/transicoes_de_tela/boasvindas2.jpg");
    if (!boas_vindas[1]){
        fprintf(stderr, "Falha ao carregar tela 2.\n");
        exit(0);
    }

    boas_vindas[2] = al_load_bitmap("res/img/transicoes_de_tela/avaliacaoVenus.jpg");
    if (!boas_vindas[2]){
        fprintf(stderr, "Falha ao carregar tela 3.\n");
        return -1;
    }

    apresentacao[1] = al_load_bitmap("res/img/inicio/inicioJogo1.jpeg");
    if (!apresentacao[1]){
        fprintf(stderr, "Falha ao carregar tela de apresentaçao.\n");
return -1;
    }

    apresentacao[2] = al_load_bitmap("res/img/inicio/inicioJogo2.jpeg");
    if (!apresentacao[2]){
        fprintf(stderr, "Falha ao carregar tela de apresentaçao.\n");
return -1;
    }

    apresentacao[3] = al_load_bitmap("res/img/inicio/inicioJogo3.jpeg");
    if (!apresentacao[3]){
        fprintf(stderr, "Falha ao carregar tela de apresentaçao.\n");
       return -1;
    }

    apresentacao[4] = al_load_bitmap("res/img/inicio/inicioJogo4.jpeg");
    apresentacao[5] = al_load_bitmap("res/img/inicio/inicioJogo5.jpeg");
    apresentacao[6] = al_load_bitmap("res/img/inicio/inicioJogo6.jpeg");
    apresentacao[7] = al_load_bitmap("res/img/inicio/inicioJogo7.jpeg");
    apresentacao[8] = al_load_bitmap("res/img/inicio/inicioJogo8.jpeg");
    apresentacao[9] = al_load_bitmap("res/img/inicio/inicioJogo9.jpeg");
    apresentacao[10] = al_load_bitmap("res/img/inicio/inicioJogo10.jpeg");
    venus = al_load_bitmap("res/img/transicoes_de_tela/transicaoTerra.jpg");



    if (!al_install_keyboard()){
        fprintf(stderr, "Falha ao inicializar o teclado.\n");
return -1;
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


//Troca a imagem anterior por uma nova, determinando em que posição a nova ser criada
/*void trocaTela(ALLEGRO_BITMAP *img1, ALLEGRO_BITMAP *img2, float x, float y){
    al_destroy_bitmap(img1);
    al_flip_display();
    al_draw_bitmap(img2, x, y, 0);
    al_flip_display();
}*/


//Troca a imagem anterior por uma nova, determinando em que posição a nova ser criada
void troca_tela(ALLEGRO_BITMAP *img1, ALLEGRO_BITMAP *img2){
    al_destroy_bitmap(img1);
    al_flip_display();
    al_draw_bitmap(img2, 0, 0, 0);
    al_flip_display();
}



