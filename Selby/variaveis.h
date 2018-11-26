const int LARGURA_TELA = 1280;
const int ALTURA_TELA = 720;
const int fontSize = 42;

ALLEGRO_DISPLAY *janela = NULL;
ALLEGRO_EVENT_QUEUE *fila_eventos = NULL;
ALLEGRO_FONT *fonte = NULL;
ALLEGRO_COLOR *cor_fonte_principal = NULL;

//inicio
ALLEGRO_BITMAP *tela_inicio = NULL;
ALLEGRO_BITMAP *boas_vindas[3] = {NULL, NULL, NULL};
ALLEGRO_BITMAP *boas_vindas_alerta = NULL;
ALLEGRO_BITMAP *apresentacao[10] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};

ALLEGRO_BITMAP *venus = NULL;
ALLEGRO_BITMAP *transicaoTerra = NULL;

ALLEGRO_BITMAP *explicaTerra[2] = {NULL, NULL};


