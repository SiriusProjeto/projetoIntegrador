#define fontSize 42

const int LARGURA_TELA = 1280;
const int ALTURA_TELA = 720;

ALLEGRO_DISPLAY *janela = NULL;
ALLEGRO_EVENT_QUEUE *fila_eventos = NULL;
ALLEGRO_BITMAP *tela_inicio = NULL;
ALLEGRO_BITMAP *boas_vindas[2] = {NULL, NULL};
ALLEGRO_FONT *fonte = NULL;
ALLEGRO_COLOR *cor_fonte_principal = NULL;

