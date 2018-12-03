
bool inicializar(){
    if (!al_init()){
        fprintf(stderr, "Falha ao inicializar a Allegro.\n");
        return false;
    }

    if (!al_init_primitives_addon()) {
        fprintf(stderr, "Falha ao iniciar primitives_addon\n");
        return false;
    }

    al_init_font_addon();
    if (!al_init_ttf_addon()){
        fprintf(stderr, "Falha ao inicializar add-on allegro_ttf.\n");
        al_shutdown_primitives_addon();
        return false;
    }

    if (!al_init_image_addon()){
        fprintf(stderr, "Falha ao inicializar add-on allegro_image.\n");
        al_shutdown_ttf_addon();
        al_shutdown_font_addon();
        al_shutdown_primitives_addon();
        return false;
    }

    if (!al_install_audio()) {
        fprintf(stderr, "Falha ao iniciar audio\n");
        al_shutdown_image_addon();
        al_shutdown_ttf_addon();
        al_shutdown_font_addon();
        al_shutdown_primitives_addon();
        return false;
    }

    if(!al_init_acodec_addon()) {
        fprintf(stderr, "al_init_acodec_addon\n");
        al_uninstall_audio();
        al_shutdown_image_addon();
        al_shutdown_ttf_addon();
        al_shutdown_font_addon();
        al_shutdown_primitives_addon();
        return false;
    }

        if (!al_install_mouse()) {
        fprintf(stderr, "al_install_mouse\n");
        al_uninstall_audio();
        al_shutdown_image_addon();
        al_shutdown_ttf_addon();
        al_shutdown_font_addon();
        al_shutdown_primitives_addon();
        return false;
    }


    janela = al_create_display(LARGURA_TELA, ALTURA_TELA);
    if (!janela){
        fprintf(stderr, "Falha ao criar janela.\n");
        al_uninstall_mouse();
        al_uninstall_audio();
        al_shutdown_image_addon();
        al_shutdown_ttf_addon();
        al_shutdown_font_addon();
        al_shutdown_primitives_addon();
        return false;
    }

    al_set_window_title(janela, "Selby Space");

    printf("fonte antes: %d\n", fonte);
    fonte = al_load_font("res/font/comic.ttf", fontSize, 0);
    printf("fonte depois: %d\n", fonte);
    if (!fonte){
        fprintf(stderr, "Falha ao carregar \"fonte comic.ttf\".\n");
        al_destroy_display(janela);
        al_uninstall_mouse();
        al_uninstall_audio();
        al_shutdown_image_addon();
        al_shutdown_ttf_addon();
        al_shutdown_font_addon();
        al_shutdown_primitives_addon();
        return false;
    }

    fila_eventos = al_create_event_queue();
    if (!fila_eventos){
        fprintf(stderr, "Falha ao criar fila de eventos.\n");
        // al_destroy_font(fonte);
        al_destroy_display(janela);
        al_uninstall_mouse();
        al_uninstall_audio();
        al_shutdown_image_addon();
        al_shutdown_ttf_addon();
        al_shutdown_font_addon();
        al_shutdown_primitives_addon();
        return false;
    }

    tela_inicio = al_load_bitmap("res/img/inicio/menuIniciar.jpg");
    if (!tela_inicio){
        fprintf(stderr, "Falha ao carregar imagem.\n");
        al_destroy_event_queue(fila_eventos);
        // al_destroy_font(fonte);
        al_destroy_display(janela);
        al_uninstall_mouse();
        al_uninstall_audio();
        al_shutdown_image_addon();
        al_shutdown_ttf_addon();
        al_shutdown_font_addon();
        al_shutdown_primitives_addon();
        return false;
    }

    boas_vindas[0] = al_load_bitmap("res/img/transicoes_de_tela/boasvindas.jpg");
    if (!boas_vindas[0]){
        fprintf(stderr, "Falha ao carregar tela.\n");
        al_destroy_bitmap(tela_inicio);
        al_destroy_event_queue(fila_eventos);
        // al_destroy_font(fonte);
        al_destroy_display(janela);
        al_uninstall_mouse();
        al_uninstall_audio();
        al_shutdown_image_addon();
        al_shutdown_ttf_addon();
        al_shutdown_font_addon();
        al_shutdown_primitives_addon();
        return false;
    }

    boas_vindas[1] = al_load_bitmap("res/img/transicoes_de_tela/boasvindas2.jpg");
    boas_vindas_alerta = al_load_bitmap("res/img/transicoes_de_tela/boasvindas2alerta.jpg");
    if (!boas_vindas[1]){
        fprintf(stderr, "Falha ao carregar tela.\n");
        al_destroy_bitmap(boas_vindas[1]);
        al_destroy_bitmap(tela_inicio);
        al_destroy_event_queue(fila_eventos);
        // al_destroy_font(fonte);
        al_destroy_display(janela);
        al_uninstall_mouse();
        al_uninstall_audio();
        al_shutdown_image_addon();
        al_shutdown_ttf_addon();
        al_shutdown_font_addon();
        al_shutdown_primitives_addon();
        return false;
    }

    boas_vindas[2] = al_load_bitmap("res/img/transicoes_de_tela/boasvindas3.jpg");
    if (!boas_vindas[2]){
        fprintf(stderr, "Falha ao carregar tela.\n");
        al_destroy_bitmap(boas_vindas[1]);
        al_destroy_bitmap(boas_vindas[2]);
        al_destroy_bitmap(tela_inicio);
        al_destroy_event_queue(fila_eventos);
        // al_destroy_font(fonte);
        al_destroy_display(janela);
        al_uninstall_mouse();
        al_uninstall_audio();
        al_shutdown_image_addon();
        al_shutdown_ttf_addon();
        al_shutdown_font_addon();
        al_shutdown_primitives_addon();
        return false;
    }

    apresentacao[0] = al_load_bitmap("res/img/inicio/inicioJogo1.jpeg");
    if (!apresentacao[0]){
                fprintf(stderr, "Falha ao carregar tela de apresentaçao.\n");
        al_destroy_bitmap(apresentacao[1]);
        al_destroy_bitmap(boas_vindas[0]);
        al_destroy_bitmap(boas_vindas[1]);
        al_destroy_bitmap(boas_vindas[2]);
        al_destroy_bitmap(tela_inicio);
        al_destroy_event_queue(fila_eventos);
        // al_destroy_font(fonte);
        al_destroy_display(janela);
        al_uninstall_mouse();
        al_uninstall_audio();
        al_shutdown_image_addon();
        al_shutdown_ttf_addon();
        al_shutdown_font_addon();
        al_shutdown_primitives_addon();
        return false;
    }

    apresentacao[1] = al_load_bitmap("res/img/inicio/inicioJogo2.jpeg");
    if (!apresentacao[1]){
        fprintf(stderr, "Falha ao carregar tela de apresentaçao.\n");
        al_destroy_bitmap(apresentacao[1]);
        al_destroy_bitmap(apresentacao[0]);
        al_destroy_bitmap(boas_vindas[0]);
        al_destroy_bitmap(boas_vindas[1]);
        al_destroy_bitmap(boas_vindas[2]);
        al_destroy_bitmap(tela_inicio);
        al_destroy_event_queue(fila_eventos);
        // al_destroy_font(fonte);
        al_destroy_display(janela);
        al_uninstall_mouse();
        al_uninstall_audio();
        al_shutdown_image_addon();
        al_shutdown_ttf_addon();
        al_shutdown_font_addon();
        al_shutdown_primitives_addon();
        return false;
    }

    apresentacao[2] = al_load_bitmap("res/img/inicio/inicioJogo3.jpeg");
    if (!apresentacao[2]){
        fprintf(stderr, "Falha ao carregar tela de apresentaçao.\n");
        al_destroy_bitmap(apresentacao[2]);
        al_destroy_bitmap(apresentacao[1]);
        al_destroy_bitmap(apresentacao[0]);
        al_destroy_bitmap(boas_vindas[0]);
        al_destroy_bitmap(boas_vindas[1]);
        al_destroy_bitmap(boas_vindas[2]);
        al_destroy_bitmap(tela_inicio);
        al_destroy_event_queue(fila_eventos);
        // al_destroy_font(fonte);
        al_destroy_display(janela);
        al_uninstall_mouse();
        al_uninstall_audio();
        al_shutdown_image_addon();
        al_shutdown_ttf_addon();
        al_shutdown_font_addon();
        al_shutdown_primitives_addon();
        return false;
    }
apresentacao[3] = al_load_bitmap("res/img/inicio/inicioJogo4.jpeg");
    if(!apresentacao[3]){
        fprintf(stderr, "Falha ao carregar tela de apresentaçao.\n");
        al_destroy_bitmap(apresentacao[3]);
        al_destroy_bitmap(apresentacao[2]);
        al_destroy_bitmap(apresentacao[1]);
        al_destroy_bitmap(apresentacao[0]);
        al_destroy_bitmap(boas_vindas[0]);
        al_destroy_bitmap(boas_vindas[1]);
        al_destroy_bitmap(boas_vindas[2]);
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
        return false;
    }
    apresentacao[4] = al_load_bitmap("res/img/inicio/inicioJogo5.jpeg");
        if(!apresentacao[4]){
        fprintf(stderr, "Falha ao carregar tela de apresentaçao.\n");
        al_destroy_bitmap(apresentacao[4]);
        al_destroy_bitmap(apresentacao[3]);
        al_destroy_bitmap(apresentacao[2]);
        al_destroy_bitmap(apresentacao[1]);
        al_destroy_bitmap(apresentacao[0]);
        al_destroy_bitmap(boas_vindas[0]);
        al_destroy_bitmap(boas_vindas[1]);
        al_destroy_bitmap(boas_vindas[2]);
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
        return false;
    }
        apresentacao[5] = al_load_bitmap("res/img/inicio/inicioJogo6.jpeg");
        if(!apresentacao[5]){
        fprintf(stderr, "Falha ao carregar tela de apresentaçao.\n");
        al_destroy_bitmap(apresentacao[5]);
        al_destroy_bitmap(apresentacao[4]);
        al_destroy_bitmap(apresentacao[3]);
        al_destroy_bitmap(apresentacao[2]);
        al_destroy_bitmap(apresentacao[1]);
        al_destroy_bitmap(apresentacao[0]);
        al_destroy_bitmap(boas_vindas[0]);
        al_destroy_bitmap(boas_vindas[1]);
        al_destroy_bitmap(boas_vindas[2]);
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
        return false;
    }
    apresentacao[6] = al_load_bitmap("res/img/inicio/inicioJogo7.jpeg");
    apresentacao[7] = al_load_bitmap("res/img/inicio/inicioJogo8.jpeg");
    apresentacao[8] = al_load_bitmap("res/img/inicio/inicioJogo9.jpeg");
    apresentacao[9] = al_load_bitmap("res/img/inicio/inicioJogo10.jpeg");
    venus = al_load_bitmap("res/img/transicoes_de_tela/transicaoTerra.jpg");
    transicaoTerra = al_load_bitmap("res/img/transicoes_de_tela/avaliacaoVenus.jpg");
    explicaTerra[0] = al_load_bitmap("res/img/fase_Terra/explicacaoTerra1.jpg");
    explicaTerra[1] = al_load_bitmap("res/img/fase_Terra/explicacaoTerra2.jpg");


    acre = al_load_bitmap("res/img/fase_Terra/estados/acre.png");
    alagoas = al_load_bitmap("res/img/fase_Terra/estados/alagoas.png");
    amapa = al_load_bitmap("res/img/fase_Terra/estados/amapa.png");
    amazonas = al_load_bitmap("res/img/fase_Terra/estados/amazonas.png");
    bahia = al_load_bitmap("res/img/fase_Terra/estados/bahia.png");
    ceara = al_load_bitmap("res/img/fase_Terra/estados/ceara.png");
    espirito_santo = al_load_bitmap("res/img/fase_Terra/estados/espirito_santo.png");
    goias = al_load_bitmap("res/img/fase_Terra/estados/goias.png");
    maranhao = al_load_bitmap("res/img/fase_Terra/estados/maranhao.png");
    mato_grosso = al_load_bitmap("res/img/fase_Terra/estados/mato_grosso.png");
    mato_grosso_do_sul = al_load_bitmap("res/img/fase_Terra/estados/mato_grosso_do_sul.png");
    minas_gerais = al_load_bitmap("res/img/fase_Terra/estados/minas_gerais.png");
    paraiba = al_load_bitmap("res/img/fase_Terra/estados/paraiba.png");
    parana = al_load_bitmap("res/img/fase_Terra/estados/parana.png");
    pernambuco = al_load_bitmap("res/img/fase_Terra/estados/pernambuco.png");
    piaui = al_load_bitmap("res/img/fase_Terra/estados/piaui.png");
    rio_de_janeiro = al_load_bitmap("res/img/fase_Terra/estados/rio_de_janeiro.png");
    rio_grande_do_norte = al_load_bitmap("res/img/fase_Terra/estados/rio_grande_do_norte.png");
    rio_grande_do_sul = al_load_bitmap("res/img/fase_Terra/estados/rio_grande_do_sul.png");
    roraima = al_load_bitmap("res/img/fase_Terra/estados/roraima.png");
    santa_catarina = al_load_bitmap("res/img/fase_Terra/estados/santa_catarina.png");
    sao_paulo = al_load_bitmap("res/img/fase_Terra/estados/sao_paulo.png");
    sergipe = al_load_bitmap("res/img/fase_Terra/estados/sergipe.png");
    tocantins = al_load_bitmap("res/img/fase_Terra/estados/tocantins.png");

    if (!al_install_keyboard()){
        fprintf(stderr, "Falha ao inicializar o teclado.\n");
        al_destroy_bitmap(boas_vindas[0]);
        al_destroy_bitmap(boas_vindas[1]);
        al_destroy_bitmap(boas_vindas[2]);
        al_destroy_bitmap(tela_inicio);
        al_destroy_event_queue(fila_eventos);
        // al_destroy_font(fonte);
        al_destroy_display(janela);
        al_uninstall_mouse();
        al_uninstall_audio();
        al_shutdown_image_addon();
        al_shutdown_ttf_addon();
        al_shutdown_font_addon();
        al_shutdown_primitives_addon();
        return false;
    }


    al_register_event_source(fila_eventos, al_get_keyboard_event_source());
    al_register_event_source(fila_eventos, al_get_display_event_source(janela));

    return true;
}



bool start_ok(){
    if (inicializar()){
        return true;
    } else {
        printf("aqui não vem!\n");
        al_uninstall_keyboard();
        al_destroy_bitmap(boas_vindas[0]);
        al_destroy_bitmap(boas_vindas[1]);
        al_destroy_bitmap(boas_vindas[2]);
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
        return false;
    }
}


//Troca a imagem anterior por uma nova, determinando em que posição a nova ser criada
/*void trocaTela(ALLEGRO_BITMAP *img1, ALLEGRO_BITMAP *img2, float x, float y){
    al_destroy_bitmap(img1);
    al_flip_display();
    al_draw_bitmap(img2, x, y, 0);
    al_flip_display();
}*/


//Troca a imagem anterior por uma nova, determinando em que posição a nova ser criada
void troca_tela(ALLEGRO_BITMAP *img1, ALLEGRO_BITMAP *img2){
    al_destroy_bitmap(img1);
    al_flip_display();
    al_draw_bitmap(img2, 0, 0, 0);
    al_flip_display();
}



