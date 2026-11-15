#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h> /* permite desenhar formas */
#include <allegro5/allegro_image.h>

int main()
{

	/* ----- Iniciacoes ----*/
	if (!al_init()) { /* Inicia o allegro e retorna False caso ele não abra */
		return -1;
	}

	al_install_keyboard(); /* Inicia o teclado, para poder usar ele */
	al_init_primitives_addon(); /* Inicializa a biblioteca  */
	al_init_image_addon(); /*inicia imgem*/

	ALLEGRO_EVENT_QUEUE* fila; /* Variável para armazenar o ponteiro para a fila de eventos */
	fila = al_create_event_queue(); /* Cria a fila de eventos, para poder usar o teclado */


	ALLEGRO_DISPLAY* janela; /* Variável para armazenar o ponteiro para a janela */
	janela = al_create_display(1500, 980); /* Cria uma janela de fato */



	ALLEGRO_BITMAP* fundo;
	ALLEGRO_BITMAP* chao;
	ALLEGRO_BITMAP* arvore;
	ALLEGRO_BITMAP* arvore3;
	ALLEGRO_BITMAP* arvore4;
	ALLEGRO_BITMAP* arvore5;
	ALLEGRO_BITMAP* personagem_parado;
	ALLEGRO_BITMAP* meteoro;
	ALLEGRO_BITMAP* meteorinho;
	ALLEGRO_BITMAP* meteoro_medio;
	ALLEGRO_BITMAP* fundo2;
	ALLEGRO_BITMAP* chao2;

	fundo2 = al_load_bitmap("imagens/fundo-fase2.png");
	chao2 = al_load_bitmap("imagens/chao.png");
	meteoro = al_load_bitmap("imagens/meteoro.png");
	meteoro_medio = al_load_bitmap("imagens/medio_meteoro.png");
	meteorinho = al_load_bitmap("imagens/pequeno_meteoro.png");
	personagem_parado = al_load_bitmap("imagens/personagem.png");
	fundo = al_load_bitmap("imagens/fundo.png");
	chao = al_load_bitmap("imagens/chao.png");

	
	arvore = al_load_bitmap("imagens/arvore2.png");
	arvore3 = al_load_bitmap("imagens/arvore3.png");
	arvore4 = al_load_bitmap("imagens/arvore4.png");
	arvore5 = al_load_bitmap("imagens/arvore5.png");




	if (!chao || !arvore || !arvore3 || !arvore4 || !arvore5 || !meteoro || !fundo || !fundo2||!chao2) {
		return -1;
	}






	/* ----- Criacoes ----- */
<<<<<<< HEAD
	int fase2 = 0;
	int fase1 = 1;
	int passou = 0;
	float cor = 0;
=======

	int fase1 = 0;

>>>>>>> 83a90952efda326a5631cc76e189ea94e16b3bb7
	/* Variaveis do Jogador */
	float playerX = 100;
	float playerY = 620; 
	float larguraPlayer = 250;
	float alturaPlayer = 250;
	float maxAlt = 0;/*o maximo da altura do pulo*/
	int noChao = 1; /* Variavel para saber se o jogador esta no chao ou no ar */


	/*comandos do personagem*/
	int espaco = 0;
	int rodando = 1; /* Variável para controlar o loop do jogo */
	int esquerda = 0;
	int direita = 0;
	int pulando = 0;
	int shift = 0;

	/*floats da primeira fase */
	float larguraFase = 5000;
	float cameraX = 0;
	float chaoY = 595;

	float meteoroX = 0;
	float velocidadeMeteoro = 1;
	float Xmeteoro = -900;
	float meteoroY = -700;
<<<<<<< HEAD
	float velocidadeMeteoroX = 3;
	float velocidadeMeteoroY = 2;
	float Xblibioteca = 850;
	float Yblibioteca = 750;
=======
	float velocidadeMeteoroX = 5;
	float velocidadeMeteoroY = 3;

>>>>>>> 83a90952efda326a5631cc76e189ea94e16b3bb7
	int meteoroCaindo = 0;


	float arvoreX1 = 700;
	float arvoreX2 = 1800;
	float arvoreX3 = 3200;
	float arvoreX4 = 4300;
<<<<<<< HEAD
=======
	
>>>>>>> 83a90952efda326a5631cc76e189ea94e16b3bb7



	ALLEGRO_TIMER* timer;
	timer = al_create_timer(1.0 / 60.0);



	/* ----- Registros dos eventos ----- */
	al_register_event_source( /*Registra a fonte de eventos do teclado na fila*/
		fila,
		al_get_keyboard_event_source());

	al_register_event_source( /*Registra a fonte de eventos da janela na fila*/
		fila,
		al_get_display_event_source(janela));

	al_register_event_source( /*Registra a fonte de eventos do tempo */
		fila,
		al_get_timer_event_source(timer));
	/* ------------------------------------ */


	al_start_timer(timer);


	while (rodando)
	{
		ALLEGRO_EVENT evento;

		al_wait_for_event(fila, &evento);


		if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		{
			rodando = 0;
		}


		if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			if (evento.keyboard.keycode == ALLEGRO_KEY_A) { /* altera esquerda*/
				esquerda = 1;

			}

			if (evento.keyboard.keycode == ALLEGRO_KEY_D) { /* altera direita*/
				direita = 1;
			}

			if (evento.keyboard.keycode == ALLEGRO_KEY_SPACE) {
				if (noChao) {
					pulando = 1;
					noChao = 0;
					maxAlt = -14;
				}
			}

			if (evento.keyboard.keycode == ALLEGRO_KEY_LSHIFT) {
				shift = 1;
			}


			if (evento.keyboard.keycode == ALLEGRO_KEY_ESCAPE) { /* finaliza o while */
				rodando = 0;
			}
		}

		if (evento.type == ALLEGRO_EVENT_KEY_UP)
		{
			if (evento.keyboard.keycode == ALLEGRO_KEY_A) {
				esquerda = 0;
			}
			if (evento.keyboard.keycode == ALLEGRO_KEY_D) {
				direita = 0;
			}
			if (evento.keyboard.keycode == ALLEGRO_KEY_SPACE) {
				playerY += maxAlt;
				maxAlt += 5;
				noChao = 0;
			}
			if (evento.keyboard.keycode == ALLEGRO_KEY_LSHIFT) {/*ta muito rapido so pra testar melhor!*/
				shift = 0;
			}

		}

		if (evento.type == ALLEGRO_EVENT_TIMER)
		{
		
				if (passou == 1){
					cor += 5;

					if (cor >= 255){
						cor = 255;

						fase2++;

						if (fase2 == 1){
							al_destroy_bitmap(fundo);
							
							fundo = fundo2;
							fundo2 = NULL;

							fase1 = 0;
							playerX = 10;
							playerY = 620;
							cameraX = 0;

							fase2 = 2;
						}

						passou = 2;
					}
				}
						
			if (passou == 2){
				cor -= 3;

				if (cor <= 0){
					cor = 0;
					passou = 0;
				}
			}


			if (fase1 == 1) {

			if (playerX >= 110) {
				meteoroCaindo = 1;
			}

			if (meteoroCaindo == 1) {
				Xmeteoro += velocidadeMeteoroX;
				meteoroY += velocidadeMeteoroY;
			}
			}
			if (fase2 == 2) {
				meteoroCaindo = 0;
		 }
			
			
			
			/*---------------- PERSONAGEM ANDAR PARA ESQUERDA  ------------------*/
			if (esquerda) {

				/* CORRE */
				if (shift == 1) {
					playerX -= 15;
				}/* CORRE */

				playerX -= 5;
				

				if (playerX <= 0 - 80) {
					playerX = 0 - 80;
				}
				/*---------------- PERSONAGEM ANDAR PARA ESQUERDA ------------------*/


			}


			if (direita) {
				/*---------------- PERSONAGEM ANDAR PARA DIREITA ------------------*/
				playerX += 5;

				/* CORRE */
				if (shift == 1) {
					playerX += 10;
				}/* CORRE */


				/*---------------- PERSONAGEM ANDAR PARA DIREITA ------------------*/
				if (fase1 == 1) {
				if (playerX >= larguraFase -1100 - larguraPlayer + 80) {
					passou = 1;
				}
			}
				if (fase2 == 2 && playerX >= 1490 - larguraPlayer + 80) {
					playerX = 1350;
				}


			}


			if (pulando) {

				playerY += maxAlt;
				maxAlt += 0.5;


				if (playerY >= 620) {
					playerY = 620;
					maxAlt = 0;
					noChao = 1;
				}

			}

			/* as 2 condicoes sao para que se o personagem sair da tela a acamera continua nela */
			if (fase1 == 1) {
			cameraX = playerX - 750; /*FAz que a camera comece a seguir o boneco no meio do mapa */
			}
			else {
				cameraX = 0;
			}


			if (cameraX < 0) {
				cameraX = 0;
			}



		}
		/*---------------- DESENHA FUNDO CHAO E O JOGADOR ------------------*/
		al_clear_to_color(al_map_rgb(30, 30, 30)); /* Limpa a cor da janela e, coloca outra no lugar */
		if (fase1 == 1) {
		al_draw_scaled_bitmap(fundo, 0 /*inicio X da imagem*/, 0 /*inicio Y da imagem*/, al_get_bitmap_width(fundo), al_get_bitmap_height(fundo),
			0 - cameraX /*X comeca do 0 */, 0 /*Y comeca do 0*/, 5000, 825, 0 /* 0 diz que a imgagem nao precisa ser invertida */);
		}
		else {
			al_draw_bitmap(fundo, -cameraX, -80, 0);
		}

		if (meteoroCaindo == 1 || meteoroCaindo == 2){
			al_draw_scaled_bitmap(meteoro, 0, 0, al_get_bitmap_width(meteoro), al_get_bitmap_height(meteoro), Xmeteoro, meteoroY, 700, 700, 0);
		}
		if (meteoroCaindo == 1 || meteoroCaindo == 2) {
			al_draw_scaled_bitmap(meteorinho, 0, 0, al_get_bitmap_width(meteorinho), al_get_bitmap_height(meteorinho), Xmeteoro + 500, meteoroY + 950, 100, 90, 0);
		}
		if (meteoroCaindo == 1 || meteoroCaindo == 2){
			al_draw_scaled_bitmap(meteoro_medio, 0, 0, al_get_bitmap_width(meteoro_medio), al_get_bitmap_height(meteoro_medio), Xmeteoro + 720, meteoroY + 400, 300, 150, 0);
		}
<<<<<<< HEAD
		/*---------------- DESENHA ARVORES PELO MAPA  ------------------*/
		
		if (fase1 == 1) {

		al_draw_scaled_bitmap(arvore, 0 /*inicio X da imagem*/, 0/*inicio Y da imagem*/, al_get_bitmap_width(arvore), al_get_bitmap_height(arvore),
			arvoreX1 - cameraX/* X onde a  arvore aparece na tela */ , 240 /* Y onde a arvore aparece na tela */, 800/* largura que a arvore  */, 655 /* altura */, 0);

		al_draw_scaled_bitmap(arvore3, 0, 0, al_get_bitmap_width(arvore3), al_get_bitmap_height(arvore3), arvoreX2 - cameraX, 240, 800, 655, 0);

		al_draw_scaled_bitmap(arvore4, 0, 0, al_get_bitmap_width(arvore4), al_get_bitmap_height(arvore4), arvoreX3 - cameraX, 240, 800, 655, 0);
=======
		/*---------------- DESENHA ARVORES PELO MAPA  ------------------*/
		al_draw_scaled_bitmap(arvore, 0 /*inicio X da imagem*/, 0/*inicio Y da imagem*/, al_get_bitmap_width(arvore),al_get_bitmap_height(arvore),	
			arvoreX1 - cameraX  /* X onde a arvore aparece na tela */ , 240 /* Y onde a arvore aparece na tela */ , 800/* largura que a arvore  */ , 655   /* altura */, 0);

		al_draw_scaled_bitmap(arvore3, 0 , 0, al_get_bitmap_width(arvore3),al_get_bitmap_height(arvore3),arvoreX2 - cameraX , 240, 800, 655, 0);

		al_draw_scaled_bitmap(arvore4, 0,0, al_get_bitmap_width(arvore4),al_get_bitmap_height(arvore4),arvoreX3 - cameraX, 240, 800, 655, 0);

		al_draw_scaled_bitmap(arvore5, 0 , 0, al_get_bitmap_width(arvore5),al_get_bitmap_height(arvore5),arvoreX4 - cameraX  , 240, 800 , 665, 0);
>>>>>>> 83a90952efda326a5631cc76e189ea94e16b3bb7

		al_draw_scaled_bitmap(arvore5, 0, 0, al_get_bitmap_width(arvore5), al_get_bitmap_height(arvore5), arvoreX4 - cameraX, 240, 800, 665, 0);

		/*---------------- DESENHA ARVORES PELO MAPA  ------------------*/


		al_draw_scaled_bitmap(chao, 0, 0, al_get_bitmap_width(chao), al_get_bitmap_height(chao), -cameraX, chaoY, larguraFase, 980 - chaoY, 0);
		}
		else {
			al_draw_scaled_bitmap(chao2, 50, 0, al_get_bitmap_width(chao), 400, -cameraX, chaoY, larguraFase , 1010 -chaoY, 0);
		}
		

		al_draw_scaled_bitmap(personagem_parado, 0, 0, al_get_bitmap_width(personagem_parado), al_get_bitmap_height(personagem_parado), playerX - cameraX, playerY, larguraPlayer, alturaPlayer, 0);
		/*jogador */



		/*
		al_draw_filled_rectangle(playerX - cameraX, playerY, playerX - cameraX + larguraPlayer, playerY + alturaPlayer, al_map_rgb(255, 255, 255));*/
		/*---------------- DESENHA BLOCOS E O JOGADOR ------------------*/


		if (cor > 0){
			al_set_blender(ALLEGRO_ADD, ALLEGRO_ALPHA, ALLEGRO_INVERSE_ALPHA);

			al_draw_filled_rectangle(0, 0, 1500, 980,al_map_rgba(0, 0, 0, (int)cor));
		}




		al_flip_display(); /* Atualiza a janela, altera de desenhando para visivel */
	}


	/* Os fodoes que impedem seu pc de quebrar  (destroe as janelas)  */
	al_destroy_bitmap(fundo);

	al_destroy_bitmap(fundo2);

	al_destroy_bitmap(meteorinho);

	al_destroy_bitmap(meteoro_medio);

	al_destroy_bitmap(personagem_parado);

	al_destroy_bitmap(chao);

	al_destroy_bitmap(meteoro);

	al_destroy_bitmap(arvore);

	al_destroy_bitmap(arvore3);

	al_destroy_bitmap(arvore4);

	al_destroy_bitmap(arvore5);



	al_destroy_timer(timer);

	al_destroy_event_queue(fila);

	al_destroy_display(janela);



	return 0;



	int fase2 = 0;















}