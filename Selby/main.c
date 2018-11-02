#include "definicoes.h"
#include "variaveis.h"
#include "funcoes_basicas.h"

bool inicializar();


int main(void){
    bool sair = false;//Iniciei a variavel sair como false..
    int tecla = 0;

    if (!start_ok()){ //Verifica se tudo iniciou certo
        return -1;
    }



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
                    troca_tela(tela_inicio, boas_vindas[1]);//desenha a tela seguinte
                    al_rest(5.0);
                    troca_tela(boas_vindas[1], boas_vindas[2]);
                    al_rest(5.0);
                    troca_tela(boas_vindas[2], boas_vindas[3]);
                    al_rest(5.0);
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
