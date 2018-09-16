#include <allegro5/allegro.h>

int main(void){
    ALLEGRO_DISPLAY *janela = NULL;

    al_init();

    janela = al_create_display(720,360);

    al_clear_to_color(al_map_rgb(225,56,225));

    al_flip_display();

    al_rest(3.0);

    al_destroy_display(janela);

    return 0;
}
