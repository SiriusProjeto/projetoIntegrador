//carrega bibliotecas do projeto
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <stdio.h>
#include <stdbool.h>
#include "definicoes.h"
#include "variaveis.h"
#include "funcoes_basicas.h"

bool inicializar();
int a=0, min = -2560;
const float FPS = 60;
//ALLEGRO_TIMER *temporizador = NULL;

void moveBitmapInX(ALLEGRO_BITMAP *bitmap, int x, int max){
//al_draw_text(fonte, al_map_rgb(0,127,255), 30,30 , ALLEGRO_ALIGN_CENTRE, "Você concluiu Vênus!");
    if(x < max){
        while(x <= max){
        al_draw_bitmap(bitmap, x, 0, 0);
        al_flip_display();
        x = x + 5;
        al_clear_to_color(al_map_rgb(0,0,0));
        }
    }
        else if(x > max){
        while(x >= max){
        al_draw_bitmap(bitmap, x, 0, 0);
        al_flip_display();
        x = x - 5;
        al_clear_to_color(al_map_rgb(0,0,0));
        }
    }
}

void intercalaTela(ALLEGRO_BITMAP *img1, ALLEGRO_BITMAP *img2, float tempo, int verdade){
    int mudanca = 1;
    //bool mudanca = true, verdade = true;
    while(verdade > 0 || verdade < 0){
        while(mudanca == 1){
            al_draw_bitmap(img1, 0, 0, 0);
            al_flip_display();
            al_clear_to_color(al_map_rgb(0, 0, 0));
            mudanca = mudanca * -1;
            if (verdade > 0) verdade--;
            al_rest(tempo);
            }
        while(mudanca == -1){
            al_draw_bitmap(img2, 0, 0, 0);
            al_flip_display();
            al_clear_to_color(al_map_rgb(0, 0, 0));
            mudanca = mudanca * -1;
            if (verdade > 0) verdade--;
            al_rest(tempo);

        }
    }
}

int main(void){
    bool sair = false;//Iniciei a variavel sair como false..
    int tecla = 0;
    //temporizador = al_create_timer(3.0);
    if (!start_ok()){ //Verifica se tudo iniciou certo
        return -1;
    }

    //al_start_timer(temporizador);

    al_draw_bitmap(apresentacao[1], 0, 0, 0);
    al_rest(1.0);
    troca_tela(apresentacao[1], apresentacao[2]);
    al_rest(2.5);
    troca_tela(apresentacao[2], apresentacao[3]);
    al_rest(0.1);
    troca_tela(apresentacao[3], apresentacao[4]);
    al_rest(0.1);
    troca_tela(apresentacao[4], apresentacao[5]);
    al_rest(0.1);
    troca_tela(apresentacao[5], apresentacao[6]);
    al_rest(0.1);
    troca_tela(apresentacao[6], apresentacao[7]);
    al_rest(0.1);
    troca_tela(apresentacao[7], apresentacao[8]);
    al_rest(0.1);
    troca_tela(apresentacao[8], apresentacao[9]);
    al_rest(0.1);
    troca_tela(apresentacao[9], apresentacao[10]);
    //al_rest(2.0);
    al_destroy_bitmap(apresentacao[10]);
    al_draw_bitmap(tela_inicio, 0, 0, 0);


     // Desenha o menu na tela
    //al_draw_text(fonte, al_map_rgb(0,127,255), 30,30 , ALLEGRO_ALIGN_INTEGER, "(I) Para informaçoes do jogo\n(ESC) para sair");
    al_flip_display();
    al_draw_bitmap(tela_inicio, 0, 0, 0);
    al_flip_display();
    while (!sair){
        while(!al_is_event_queue_empty(fila_eventos)){
            ALLEGRO_EVENT evento; //Declaração  do evento
            al_wait_for_event(fila_eventos, &evento);// Espera evento na fila de eventos e inclui na var eventos

            //Parte da tela inicial
            //Captura tecla
            if (evento.type == ALLEGRO_EVENT_KEY_DOWN){ // se o tipo do evento for press no teclado
                if (evento.keyboard.keycode == ALLEGRO_KEY_SPACE){
                    tecla = 1;
                } else if (evento.keyboard.keycode == ALLEGRO_KEY_ESCAPE){
                    tecla = 2;
                }
            } else if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE){ // se houver o clique no "x" (Fechar janela)
                sair = true;
            }

            if (tecla){
                switch (tecla){
                case 1://Caso tenha digitado space
                //al_clear_to_color(al_map_rgb(0,0,0));
                //al_draw_text(fonte, al_map_rgb(0,127,255), 30, 60, 0, "TESTE DE TEXTO");
                    troca_tela(tela_inicio, boas_vindas[0]);//desenha a tela seguinte
                    al_rest(5.0);
                    troca_tela(boas_vindas[0], boas_vindas[1]);
                    intercalaTela(boas_vindas[1], boas_vindas_alerta, 0.5, 10);
                    troca_tela(boas_vindas[1], boas_vindas[2]);
                    al_rest(5.0);
                    al_destroy_bitmap(boas_vindas[2]);
                    moveBitmapInX(transicaoTerra, a, min);
                    al_flip_display();
                    al_destroy_bitmap(transicaoTerra);
                    al_flip_display();
                    al_draw_bitmap(venus, 0, 0, 0);
                    al_flip_display();
                    al_rest(7.0);
                    al_flip_display();
                    intercalaTela(explicaTerra[0], explicaTerra[1], 1.0, -1);

                    break ;
                }
                tecla = 0;
            }

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
