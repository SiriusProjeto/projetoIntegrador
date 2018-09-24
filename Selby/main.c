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
ALLEGRO_BITMAP *imagem, *tela , *menu= NULL;
ALLEGRO_FONT *fonte = NULL;


bool inicializar(){
    if (!al_init())
    {
        fprintf(stderr, "Falha ao inicializar a Allegro.\n");
        return false;
    }

    al_init_font_addon();

    if (!al_init_ttf_addon())
    {
        fprintf(stderr, "Falha ao inicializar add-on allegro_ttf.\n");
        return false;
    }

    if (!al_init_image_addon())
    {
        fprintf(stderr, "Falha ao inicializar add-on allegro_image.\n");
        return false;
    }

    if (!al_install_keyboard())
    {
        fprintf(stderr, "Falha ao inicializar o teclado.\n");
        return false;
    }

    janela = al_create_display(LARGURA_TELA, ALTURA_TELA);
    if (!janela)
    {
        fprintf(stderr, "Falha ao criar janela.\n");
        return false;
    }

    al_set_window_title(janela, "Utilizando o Teclado");

    fonte = al_load_font("res/font/comic.ttf", 72, 0);
    if (!fonte)
    {
        fprintf(stderr, "Falha ao carregar \"fonte comic.ttf\".\n");
        al_destroy_display(janela);
        return false;
    }

    fila_eventos = al_create_event_queue();
    if (!fila_eventos)
    {
        fprintf(stderr, "Falha ao criar fila de eventos.\n");
        al_destroy_display(janela);
        return false;
    }


    al_register_event_source(fila_eventos, al_get_keyboard_event_source());
    al_register_event_source(fila_eventos, al_get_display_event_source(janela));

    return true;
}

int carrega_imagem(char *caminho){
    ALLEGRO_BITMAP *imagem = NULL;
    imagem = al_load_bitmap(caminho);
    if (!imagem){
        fprintf(stderr, "Falha ao carregar imagem.\n");
        return false;
    }
    return imagem;
}

bool inicializar();


int main(void)
{
    bool sair = false;//Iniciei a variavel sair como false..
    int tecla = 0;

    if (!inicializar()){ //Verifica se tudo iniciou certo
        return -1;
    }

    menu = carrega_imagem("res/img/Menu.png");
    al_draw_bitmap(menu, 0, 0, 0); // Desenha o menu na tela

    while (!sair)
    {
        while(!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                switch(evento.keyboard.keycode)
                {
                case ALLEGRO_KEY_SPACE:
                    tecla = 1;
                    break;
                }
            }
            else if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                sair = true;
            }
        }

        if (tecla)
        {
            al_draw_bitmap(imagem, 0, 0, 0);

            switch (tecla)
            {
            case 1:

                al_draw_bitmap(tela, 0, 0, 0);
                break;
            }

            tecla = 0;
        }

        al_flip_display();
    }

    al_destroy_display(janela);
    al_destroy_event_queue(fila_eventos);

    return 0;
}
