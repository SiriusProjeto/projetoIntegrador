    #include <allegro5/allegro.h>
    #include <allegro5/allegro_font.h>
    #include <allegro5/allegro_ttf.h>
    #include <allegro5/allegro_native_dialog.h>
    #include <string.h>

    #define LARGURA_TELA 640
    #define ALTURA_TELA 480

    ALLEGRO_DISPLAY *janela = NULL;
    ALLEGRO_EVENT_QUEUE *fila_eventos = NULL;
    ALLEGRO_FONT *fonte = NULL;

    void error_msg(char *text){
        al_show_native_message_box(janela,"ERRO",
            "Ocorreu o seguinte erro e o programa sera finalizado:",
            text,NULL,ALLEGRO_MESSAGEBOX_ERROR);
    }

    int inicializar(){
        if (!al_init()){
            error_msg("Falha ao inicializar a Allegro");
            return 0;
        }

        al_init_font_addon();

        if (!al_init_ttf_addon()){
            error_msg("Falha ao inicializar add-on allegro_ttf");
            return 0;
        }

        if (!al_init_image_addon()){
            error_msg("Falha ao inicializar add-on allegro_image");
            return 0;
        }

        //inicializa addon do teclado
        if (!al_install_keyboard()){
            error_msg("Falha ao inicializar o teclado");
            return 0;
        }

        janela = al_create_display(LARGURA_TELA, ALTURA_TELA);
        if (!janela){
            error_msg("Falha ao criar janela");
            return 0;
        }

        al_set_window_title(janela, "Utilizando o Teclado");

        fonte = al_load_font("res/font/comic.ttf", 72, 0);
        if (!fonte){
            error_msg("Falha ao carregar \"arial.ttf\"");
            al_destroy_display(janela);
            return 0;
        }

        fila_eventos = al_create_event_queue();
        if (!fila_eventos){
            error_msg("Falha ao criar fila de eventos");
            al_destroy_display(janela);
            return 0;
        }

        //registra duas fontes de eventos na fila. o da janela, e do teclado
        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
        al_register_event_source(fila_eventos, al_get_display_event_source(janela));

        return 1;
    }

    int main(void)
    {
        int sair = 0;
        int tecla = 0;
        char palavra[15];
        int n = 0;

        if (!inicializar()){
            return -1;
        }

        al_clear_to_color(al_map_rgb(255, 255, 255));

        while (!sair){
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

        al_destroy_display(janela);
        al_destroy_event_queue(fila_eventos);

        return 0;
    }
















