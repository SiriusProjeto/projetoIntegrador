#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <stdio.h>
#include <stdbool.h>

ALLEGRO_BITMAP *tela_inicio = NULL;
ALLEGRO_BITMAP *boas_vindas[3] = {NULL, NULL, NULL};
ALLEGRO_BITMAP *apresentacao[26] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
