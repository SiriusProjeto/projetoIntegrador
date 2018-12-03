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

ALLEGRO_BITMAP *acre = NULL;
ALLEGRO_BITMAP *alagoas = NULL;
ALLEGRO_BITMAP *amapa = NULL;
ALLEGRO_BITMAP *amazonas = NULL;
ALLEGRO_BITMAP *bahia = NULL;
ALLEGRO_BITMAP *ceara = NULL;
ALLEGRO_BITMAP *espirito_santo = NULL;
ALLEGRO_BITMAP *goias = NULL;
ALLEGRO_BITMAP *maranhao = NULL;
ALLEGRO_BITMAP *mato_grosso = NULL;
ALLEGRO_BITMAP *mato_grosso_do_sul = NULL;
ALLEGRO_BITMAP *minas_gerais = NULL;
ALLEGRO_BITMAP *paraiba = NULL;
ALLEGRO_BITMAP *parana = NULL;
ALLEGRO_BITMAP *pernambuco = NULL;
ALLEGRO_BITMAP *piaui = NULL;
ALLEGRO_BITMAP *rio_de_janeiro = NULL;
ALLEGRO_BITMAP *rio_grande_do_norte = NULL;
ALLEGRO_BITMAP *rio_grande_do_sul = NULL;
ALLEGRO_BITMAP *rondonia = NULL;
ALLEGRO_BITMAP *roraima = NULL;
ALLEGRO_BITMAP *santa_catarina = NULL;
ALLEGRO_BITMAP *sao_paulo = NULL;
ALLEGRO_BITMAP *sergipe = NULL;
ALLEGRO_BITMAP *tocantins = NULL;

ALLEGRO_BITMAP *venus = NULL;
ALLEGRO_BITMAP *transicaoTerra = NULL;

ALLEGRO_BITMAP *explicaTerra[2] = {NULL, NULL};

char palavra[15];
