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
    while(verdade != 0){
        if(mudanca == 1){
            al_draw_bitmap(img1, 0, 0, 0);
            al_flip_display();
            al_clear_to_color(al_map_rgb(0, 0, 0));
            mudanca = mudanca * -1;
            if (verdade > 0) verdade--;
            al_rest(tempo);
        }
        if(mudanca == -1){
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
    printf("vou iniciar\n");

    //temporizador = al_create_timer(3.0);
    if (!start_ok()){ //Verifica se tudo iniciou certo
        return -1;
    }

    //al_start_timer(temporizador);
    printf("vou iniciar a apresentacao\n");

    al_draw_bitmap(apresentacao[0], 0, 0, 0);
    al_rest(1.0);
    troca_tela(apresentacao[0], apresentacao[1]);
    al_rest(2.5);
    troca_tela(apresentacao[1], apresentacao[2]);
    al_rest(0.1);
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
    //al_rest(2.0);
    al_destroy_bitmap(apresentacao[9]);
    al_draw_bitmap(tela_inicio, 0, 0, 0);
    printf("passei aqui\n");


     // Desenha o menu na tela
    al_flip_display();
    while (!sair){
        while(!al_is_event_queue_empty(fila_eventos)){
            ALLEGRO_EVENT event; //Declaração  do evento
            al_wait_for_event(fila_eventos, &event);// Espera evento na fila de eventos e inclui na var eventos

            //Parte da tela inicial
            //Captura tecla
            if (event.type == ALLEGRO_EVENT_KEY_DOWN){ // se o tipo do evento for press no teclado
                if (event.keyboard.keycode == ALLEGRO_KEY_SPACE){
                    tecla = 1;
                } else if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE){
                    tecla = 2;
                }
            } else if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE){ // se houver o clique no "x" (Fechar janela)
            sair = true;
        }



        if (tecla){
            switch (tecla){
                case 10://Caso tenha digitado space
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
                    case 1:
                    al_clear_to_color(al_map_rgb(255,255,255));
                    printf("fonte aqui: %d\n", fonte);
                        // al_draw_text(fonte, al_map_rgb(255,0,0) ,ALTURA_TELA - 100 ,LARGURA_TELA - 100, ALLEGRO_ALIGN_LEFT, "Teste");
                    while(!al_is_event_queue_empty(fila_eventos)){
                        ALLEGRO_EVENT evento;
                //espera ate que algum evento esteja na fila
                        al_wait_for_event(fila_eventos, &evento);

                //se o evento for pressionar uma tecla
                        if (evento.type == ALLEGRO_EVENT_KEY_DOWN){
                    //verifica qual tecla foi pressionada
                            switch(evento.keyboard.keycode){
                    //seta para cima
                                case ALLEGRO_KEY_A:
                                tecla = 1;
                                break;
                    //seta para baixo
                                case ALLEGRO_KEY_B:
                                tecla = 2;
                                break;
                    //seta para esquerda
                                case ALLEGRO_KEY_C:
                                tecla = 3;
                                break;
                    //seta para direita.
                                case ALLEGRO_KEY_D:
                                tecla = 4;
                                break;
                                case ALLEGRO_KEY_E:
                                tecla = 5;
                                break;
                                case ALLEGRO_KEY_F:
                                tecla = 6;
                                break;
                                case ALLEGRO_KEY_G:
                                tecla = 7;
                                break;
                                case ALLEGRO_KEY_H:
                                tecla = 8;
                                break;
                                case ALLEGRO_KEY_I:
                                tecla = 9;
                                break;
                                case ALLEGRO_KEY_J:
                                tecla = 10;
                                break;
                                case ALLEGRO_KEY_K:
                                tecla = 11;
                                break;
                                case ALLEGRO_KEY_L:
                                tecla = 12;
                                break;
                                case ALLEGRO_KEY_M:
                                tecla = 13;
                                break;
                                case ALLEGRO_KEY_N:
                                tecla = 14;
                                break;
                                case ALLEGRO_KEY_O:
                                tecla = 15;
                                break;
                                case ALLEGRO_KEY_P:
                                tecla = 16;
                                break;
                                case ALLEGRO_KEY_Q:
                                tecla = 17;
                                break;
                                case ALLEGRO_KEY_R:
                                tecla = 18;
                                break;
                                case ALLEGRO_KEY_S:
                                tecla = 19;
                                break;
                                case ALLEGRO_KEY_T:
                                tecla = 20;
                                break;
                                case ALLEGRO_KEY_U:
                                tecla = 21;
                                break;
                                case ALLEGRO_KEY_V:
                                tecla = 22;
                                break;
                                case ALLEGRO_KEY_W:
                                tecla = 23;
                                break;
                                case ALLEGRO_KEY_X:
                                tecla = 24;
                                break;
                                case ALLEGRO_KEY_Y:
                                tecla = 25;
                                break;
                                case ALLEGRO_KEY_Z:
                                tecla = 26;
                                break;

                                case ALLEGRO_KEY_ENTER:
                                tecla = 999;
                                break;
                                case ALLEGRO_KEY_BACKSPACE:
                                tecla = 998;
                                break;
                    //esc. sair=1 faz com que o programa saia do loop principal
                                case ALLEGRO_KEY_ESCAPE:
                                sair = 1;
                            }
                        }
                //se o evento foi o soltar de uma tecla
                //tecla=5 significa que alguma foi pressionada mas nao e nenhuma das setas

                //se clicou para fechar a janela
                        else if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
                            sair = 1;
                        }
                    }

            //tecla!=0 significa que algo foi pressionado
                    if (tecla){
                        al_clear_to_color(al_map_rgb(255, 255, 255));

                //desenha na tela as palavras relativas a seta preesionada
                        switch (tecla){
                            case 1:
                            strcat(palavra,"A");
                            break;
                            case 2:
                            strcat(palavra,"B");
                            break;
                            case 3:
                            strcat(palavra,"C");
                            break;
                            case 4:
                            strcat(palavra,"D");
                            break;
                            case 5:
                            strcat(palavra,"E");
                            break;
                            case 6:
                            strcat(palavra,"F");
                            break;
                            case 7:
                            strcat(palavra,"G");
                            break;
                            case 8:
                            strcat(palavra,"H");
                            break;
                            case 9:
                            strcat(palavra,"I");
                            break;
                            case 10:
                            strcat(palavra,"J");
                            break;
                            case 11:
                            strcat(palavra,"K");
                            break;
                            case 12:
                            strcat(palavra,"L");
                            break;
                            case 13:
                            strcat(palavra,"M");
                            break;
                            case 14:
                            strcat(palavra,"N");
                            break;
                            case 15:
                            strcat(palavra,"O");
                            break;
                            case 16:
                            strcat(palavra,"P");
                            break;
                            case 17:
                            strcat(palavra,"Q");
                            break;
                            case 18:
                            strcat(palavra,"R");
                            break;
                            case 19:
                            strcat(palavra,"S");
                            break;
                            case 20:
                            strcat(palavra,"T");
                            break;
                            case 21:
                            strcat(palavra,"U");
                            break;
                            case 22:
                            strcat(palavra,"V");
                            break;
                            case 23:
                            strcat(palavra,"W");
                            break;
                            case 24:
                            strcat(palavra,"X");
                            break;
                            case 25:
                            strcat(palavra,"Y");
                            break;
                            case 26:
                            strcat(palavra,"Z");
                            break;

                            case 999:
                            sair = 1;
                            break;
                        }

                //zera a tecla para a proxima vez nao entrar aqui de novo
                        al_draw_text(fonte, al_map_rgb(0, 0, 0), LARGURA_TELA / 2,
                            ALTURA_TELA / 4 - al_get_font_ascent(fonte) / 4,
                            ALLEGRO_ALIGN_CENTER, palavra);
                        tecla = 0;
                    }
                    al_flip_display();

                }
                tecla = 0;
            }

        }

    }
    al_flip_display();
    int n=0;
    al_uninstall_keyboard();
    printf("%d\n", n++);
    al_destroy_bitmap(boas_vindas[0]);
    printf("%d\n", n++);
    al_destroy_bitmap(boas_vindas[1]);
    printf("%d\n", n++);
    al_destroy_bitmap(boas_vindas[2]);
    printf("%d\n", n++);
    al_destroy_bitmap(tela_inicio);
    printf("%d\n", n++);
    al_destroy_event_queue(fila_eventos);
    printf("%d\n", n++);
    al_destroy_font(fonte);
    printf("%d\n", n++);
    al_destroy_display(janela);
    printf("%d\n", n++);
    al_uninstall_mouse();
    al_uninstall_audio();
    al_shutdown_image_addon();
    al_shutdown_ttf_addon();
    al_shutdown_font_addon();
    al_shutdown_primitives_addon();
    return 0;
}
