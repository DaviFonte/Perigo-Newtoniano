#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h> /* permite desenhar formas */

int main()
{

	/* ----- Iniciacoes ----*/
	if (!al_init()) { /* Inicia o allegro e retorna False caso ele não abra */
		return -1;
	}

	al_install_keyboard(); /* Inicia o teclado, para poder usar ele */
	al_init_primitives_addon(); /* Inicializa a biblioteca  */

	ALLEGRO_EVENT_QUEUE* fila; /* Variável para armazenar o ponteiro para a fila de eventos */
	fila = al_create_event_queue(); /* Cria a fila de eventos, para poder usar o teclado */


	ALLEGRO_DISPLAY* janela; /* Variável para armazenar o ponteiro para a janela */
	janela = al_create_display(800, 600); /* Cria uma janela de fato */

	ALLEGRO_TIMER* timer;
	timer = al_create_timer(1.0 / 60.0);
	/* -------------------------------*/


	/* ----- Criacoes ----- */

	/* Variaveis do Jogador */
	float playerX = 100;
	float playerY = 450;
	float larguraPlayer = 50;
	float alturaPlayer = 50;
	float maxAlt = 0;/*o maximo da altura do pulo*/
	int noChao = 1; /* Variavel para saber se o jogador esta no chao ou no ar */

	/* Variaveis da parede */
	float paredeX = 500;
	float paredeY = 350;
	float larguraParede = 50;
	float alturaParede = 150;



	int rodando = 1; /* Variável para controlar o loop do jogo */
	int esquerda = 0;
	int direita = 0;
	int pulando = 0;



	/* ----- Registros dos eventos ----- */
	al_register_event_source( /*Registra a fonte de eventos do teclado na fila*/
		fila,
		al_get_keyboard_event_source()
	);

	al_register_event_source( /*Registra a fonte de eventos da janela na fila*/
		fila,
		al_get_display_event_source(janela)
	);

	al_register_event_source( /*Registra a fonte de eventos do tempo */
		fila,
		al_get_timer_event_source(timer)
	);
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
					maxAlt = -15;
				}
			}

			if (evento.keyboard.keycode == ALLEGRO_KEY_ESCAPE) { /* finaliza o while */
				rodando = 0;
			}
		}

		if (evento.type == ALLEGRO_EVENT_KEY_UP)
		{
			if (evento.keyboard.keycode == ALLEGRO_KEY_A) { /* Parada Esquerda*/
				esquerda = 0;
			}
			if (evento.keyboard.keycode == ALLEGRO_KEY_D) { /* Parada Direita*/
				direita = 0;
			}

		}

		if (evento.type == ALLEGRO_EVENT_TIMER)
		{
			if (esquerda) {
				playerX -= 5;

				if ( /* Verifica colisão com a parede */
					playerX < paredeX + larguraParede &&
					playerX + larguraPlayer > paredeX &&
					playerY < paredeY + alturaParede &&
					playerY + alturaPlayer > paredeY
					)
				{
					playerX = paredeX + larguraParede; /* Reposiciona o jogador para fora da parede pela esquerda */
				}
			}


			if (direita) {
				playerX += 5;

				if ( /* Verifica colisão com a parede */
					playerX < paredeX + larguraParede &&
					playerX + larguraPlayer > paredeX &&
					playerY < paredeY + alturaParede &&
					playerY + alturaPlayer > paredeY
					)
				{
					playerX = paredeX - larguraPlayer; /* Reposiciona o jogador para fora da parede pela direita */
				}
			}

			if (pulando) {

				playerY += maxAlt;
				maxAlt += 0.5;

				/* Verifica colisão com a parede */
				if (playerY >= 450) {
					playerY = 450;
					maxAlt = 0;
					pulando = 0;
					noChao = 1;
				}
				if (maxAlt > 0 && playerY + alturaPlayer >= paredeY && playerX + larguraPlayer > paredeX && playerX < paredeX + larguraParede) { /* colisao com o bloco*/
					playerY = paredeY - alturaPlayer; /* Reposiciona o jogador para fora da parede por cima */
					maxAlt = 0;
					noChao = 1;
				}

				/*No pulando tirei uma variavel que nn tava servindo pra nada e ele nao tava caindo depois de ficar no quadrado agora esta */
			}
		}



		al_clear_to_color(al_map_rgb(30, 30, 30)); /* Limpa a cor da janela e, coloca outra no lugar */
		al_draw_filled_rectangle( /* Desenha um retângulo/chão com os (x1,y1,x2,y2) e cor */
			0,
			500,
			800,
			600,
			al_map_rgb(255, 100, 100)
		);


		al_draw_filled_rectangle( /* Desenha a parede */
			paredeX,
			paredeY,
			paredeX + larguraParede,
			paredeY + alturaParede,
			al_map_rgb(100, 150, 255)
		);



		/* Desenha o jogador */
		al_draw_filled_rectangle(
			playerX,
			playerY,
			playerX + larguraPlayer,
			playerY + alturaPlayer,
			al_map_rgb(255, 255, 255)
		);


		al_flip_display(); /* Atualiza a janela, altera de desenhando para visivel */
	}

	al_rest(7.0);   /* Espera 7 segundos para fechar a janela */
	al_destroy_timer(timer);
	al_destroy_event_queue(fila);
	al_destroy_display(janela); /* Destroi a janela */
	return 0;

}