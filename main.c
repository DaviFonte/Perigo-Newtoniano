#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>


int main()
{


/* ----- Iniciacoes ----*/
	if (!al_init()) { /* Inicia o allegro e retorna False caso ele não abra */
		return -1;
	}


	al_install_keyboard(); /* Inicia o teclado, para poder usar ele */
	al_init_primitives_addon(); /* Inicializa a biblioteca  */
	al_init_image_addon(); /*inicia imgem*/


	ALLEGRO_EVENT_QUEUE* fila; /* Variável para armazenar o ponteiro para a fila de eventos */
	fila = al_create_event_queue(); /* Cria a fila de eventos, para poder usar o teclado */




	ALLEGRO_DISPLAY* janela; /* Variável para armazenar o ponteiro para a janela */
	janela = al_create_display(1500, 980); /* Cria uma janela de fato */




	/*--------------------------------IMAGENS-------------------------------------*/
	ALLEGRO_BITMAP* fundo;
	ALLEGRO_BITMAP* chao;
	ALLEGRO_BITMAP* arvore;
	ALLEGRO_BITMAP* arvore4;
	ALLEGRO_BITMAP* arvore5;
	ALLEGRO_BITMAP* personagem;
	ALLEGRO_BITMAP* fundo2;
	ALLEGRO_BITMAP* chao2;
	ALLEGRO_BITMAP* inimigo;
	ALLEGRO_BITMAP* blibioteca;
	ALLEGRO_BITMAP* apoio1;
	ALLEGRO_BITMAP* apoio2;
	ALLEGRO_BITMAP* apoio3;
	ALLEGRO_BITMAP* coracao1;
	ALLEGRO_BITMAP* coracao2;
	ALLEGRO_BITMAP* coracao3;



	apoio1 = al_load_bitmap("imagens/apoio.png");
	apoio2 = al_load_bitmap("imagens/bigmadeira.png");
	apoio3 = al_load_bitmap("imagens/madeira.png");


	blibioteca = al_load_bitmap("imagens/blibio.png");
	fundo2 = al_load_bitmap("imagens/fundo-fase2.png");
	fundo = al_load_bitmap("imagens/fundo.png");
	chao2 = al_load_bitmap("imagens/chao.png");
	chao = al_load_bitmap("imagens/chao.png");

	coracao1 = al_load_bitmap("imagens/coracao.png");
	coracao2 = al_load_bitmap("imagens/hart2.png");
	coracao3 = al_load_bitmap("imagens/hort3.png");



	personagem = al_load_bitmap("imagens/personagem.png");
	inimigo = al_load_bitmap("imagens/inimigo.png");




	arvore = al_load_bitmap("imagens/arvore2.png");
	arvore4 = al_load_bitmap("imagens/arvore4.png");
	arvore5 = al_load_bitmap("imagens/arvore5.png");


	if (!chao || !arvore || !arvore4 || !arvore5 || !fundo || !fundo2 || !chao2 || !personagem || !inimigo || !coracao1|| !coracao2 || !coracao3) {
		return -1;
	}


	/*--------------------------------IMAGENS-------------------------------------*/














	/* ----- Variaveis da fase ----- */
	int fase1 = 1;
	float arvoreX1 = 1500;
	float arvoreX3 = 3200;
	float arvoreX4 = 3500;
	float arvoreX5 = 4000;
	float larguraFase = 5000;
	float cameraX = 0;
	float chaoY = 600;
	int passou = 0;
	float cor = 0;





	int fase2 = 0;
	float Xblibioteca = 850;
	float Yblibioteca = 750;



	int fase3 = 0;
	/* ----- Variaveis da fase ----- */






	/* VARIAVEIS JOGADOR ESTATICO  */
	int vidas = 3;
	int REDdano = 0;
	int menosUM = 0;
	float ultimoDano = -2.0;
	float tempoInvencivel = 2.0;

	float playerX = 100;
	float playerY = 620;
	float larguraPlayer = 180;
	float alturaPlayer = 250;
	
	
	int segurando = 0;
	float maxAlt = 0;
	int noChao = 1;
	int olhandoEsquerda = 0;


	/* VARIAVEIS JOGADOR ESTATICO */




	/* ------ VARIAVEIS JOGADOR ANDANDO ------*/

	int quadroAtual = 0;
	int contadorAnimacao = 0;
	int velocidadeAnimacao = 6;

	/* ------ VARIAVEIS JOGADOR ANDANDO -------*/

	/* colisao objetos  */



	/* Variaveis do inimigo */

	/* Variaveis do inimigo */

	float inimigoX = 1300; /*primeiro que aparece*/
	float inimigoY = 565;
	float inimigoX2 = -500;
	float inimigoX3 = -1500;
	float inimigoX4 = 4000;


	int inimigo1Ativo = 1;
	int inimigo2Ativo = 1;
	int inimigo3Ativo = 1;
	int inimigo4Ativo = 1;


	float larguraInimigo = 200;
	float alturaInimigo = 340;
	float velocidadeInimigo = 2;


	int inimigoOlhandoEsquerda = 0;


	int quadroInimigo = 1;
	int contadorInimigo = 0;
	int velocidadeAnimacaoInimigo = 6;
	/* Variaveis do inimigo */








	/* ------------------ COMANDOS PLAYER  ----------------*/
	int espaco = 0;
	int rodando = 1; /* Variável para controlar o loop do jogo */
	int esquerda = 0;
	int direita = 0;
	int pulando = 0;
	int shift = 0;
	/* ------------------ COMANDOS PLAYER  ----------------*/





/* ------------------ DISPARO/TIRO ----------------*/
	int empurrao = 0;
	int momentoDoTiro = 0;
	int esperandoPulo = 0;
	float tiroX = 0;
	float tiroY = 0;
	int tiroAtivo = 0;
	int velocidadeTiro = 10;
	int direcaoTiro = 1; /* 1 = direita, 2 = esquerda, -1 = baixo */

	/* ----------------------------------*/






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
				olhandoEsquerda = 1;
			}


			if (evento.keyboard.keycode == ALLEGRO_KEY_D) { /* altera direita*/
				direita = 1;
				olhandoEsquerda = 0;
			}
			if (evento.keyboard.keycode == ALLEGRO_KEY_SPACE) {
				segurando = 1;
			}


			if (evento.keyboard.keycode == ALLEGRO_KEY_F) {
				if (fase1 == 1) {
					tiroAtivo = 1;
					if (direita) {
						empurrao = -25;
					}
					else {
						empurrao = 25;
					}

					tiroY = playerY + 100;

					if (esquerda) {
						tiroX = playerX;
						direcaoTiro = 1;
					}
					else {
						tiroX = playerX + larguraPlayer;
						direcaoTiro = 2;
					}
				}
				if (fase3 == 1 && segurando == 1 && noChao == 1 && esperandoPulo == 0) {
					tiroAtivo = 1;
					tiroX = playerX + larguraPlayer / 2;
					tiroY = playerY + alturaPlayer - 30;
					direcaoTiro = -1;

					/* marca o momento do tiro mas ainda nao pula */
					momentoDoTiro = al_get_time();
					esperandoPulo = 1;
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
				segurando = 0;
			}
			if (evento.keyboard.keycode == ALLEGRO_KEY_LSHIFT) {/*ta muito rapido so pra testar melhor!*/
				shift = 0;
			}


		}


		if (evento.type == ALLEGRO_EVENT_TIMER) {




			/*------------------ INIMIGOS SEGINDO O NEWTON  ---------------------------*/

			if (fase1 == 1) {
				if (inimigo1Ativo == 1) {
					if (inimigoX < playerX) {
						inimigoX += velocidadeInimigo;
					}
					else {
						inimigoX -= velocidadeInimigo;
					}
				}


				if (inimigo2Ativo == 1) {
					if (inimigoX2 < playerX) {
						inimigoX2 += velocidadeInimigo;
					}
					else {
						inimigoX2 -= velocidadeInimigo;
					}
				}


				if (inimigo3Ativo == 1) {
					if (inimigoX3 < playerX) {
						inimigoX3 += velocidadeInimigo;
						if (playerX >= 2000) {
							inimigoX3 += velocidadeInimigo + 15;
						}
					}
					else {
						inimigoX3 -= velocidadeInimigo;
					}
				}
				if (inimigo4Ativo == 1) {
					if (inimigoX4 < playerX) {
						inimigoX4 += velocidadeInimigo;
					}
					else {
						inimigoX4 -= velocidadeInimigo;
					}
				}
			}
			/*------------------ INIMIGOS SEGINDO O NEWTON  --------------------------*/


/*------------------ COLISAO COM O NEWTON  --------------------*/
			if (fase1 == 1 && al_get_time() - ultimoDano >= tempoInvencivel) {

				int levouDano = 0;

				if (inimigo1Ativo == 1 && playerX + larguraPlayer >= inimigoX && playerX <= inimigoX + larguraInimigo && playerY + alturaPlayer - 30 >= inimigoY && playerY <= inimigoY + alturaInimigo) {
					inimigo1Ativo = 0;
					levouDano = 1;
					menosUM++;
					REDdano = 70;
				}


				if (inimigo2Ativo == 1 && playerX + larguraPlayer >= inimigoX2 && playerX <= inimigoX2 + larguraInimigo && playerY + alturaPlayer - 30 >= inimigoY && playerY <= inimigoY + alturaInimigo) {
					inimigo2Ativo = 0;
					levouDano = 1;
					menosUM++;
					REDdano = 70;
				}

				if (inimigo3Ativo == 1 && playerX + larguraPlayer >= inimigoX3 && playerX <= inimigoX3 + larguraInimigo && playerY + alturaPlayer - 30 >= inimigoY && playerY <= inimigoY + alturaInimigo) {
					inimigo3Ativo = 0;
					levouDano = 1;
					menosUM++;
					REDdano = 70;
				}

				if (inimigo4Ativo == 1 && playerX + larguraPlayer >= inimigoX4 && playerX <= inimigoX4 + larguraInimigo && playerY + alturaPlayer - 30 >= inimigoY && playerY <= inimigoY + alturaInimigo) {
					inimigo4Ativo = 0;
					levouDano = 1;
					menosUM++;
					REDdano = 70;
				}

				if (levouDano == 1 || levouDano == 2) {
					vidas--;


					ultimoDano = al_get_time();

					if (vidas <= 0) {
						rodando = 0;
					}
				}
			}

			/*------------------ COLISAO COM O NEWTON  --------------------*/



		/*------------------ ANIMACAO INIMIGOS ---------------------------*/
			if (fase1 == 1 && inimigo1Ativo == 1) {


				if (inimigoX < playerX) {
					inimigoX += velocidadeInimigo;
					inimigoOlhandoEsquerda = 0;
				}
				if (inimigoX > playerX) {
					inimigoX -= velocidadeInimigo;
					inimigoOlhandoEsquerda = 1;
				}
			}

			if (fase1 == 1 && (inimigo1Ativo == 1 || inimigo1Ativo == 1 || inimigo2Ativo == 1 || inimigo3Ativo == 1 || inimigo4Ativo == 1)) { /*foda essas ()*/
				contadorInimigo++;

				if (contadorInimigo >= velocidadeAnimacaoInimigo) {
					quadroInimigo++;

					if (quadroInimigo > 8) {
						quadroInimigo = 1;
					}
					contadorInimigo = 0;
				}
			}
			/*------------------ ANIMACAO INIMIGOS ---------------------------*/



			/* ------ DIRECAO DO TIRO -----*/
			if (tiroAtivo == 1) {

				if (direcaoTiro == 2) {
					tiroX += velocidadeTiro;
				}
				if (direcaoTiro == 1) {
					tiroX -= velocidadeTiro;
				}
				if (direcaoTiro == -1) {
					tiroY += velocidadeTiro;
				}
			}/*------- DIRECAO DO TIRO ------*/


			if (fase1 == 1 && tiroAtivo == 1) {
				if (tiroX + 20 >= inimigoX && tiroX - 20 <= inimigoX + larguraInimigo && tiroY + 20 >= inimigoY && tiroY - 20 <= inimigoY + alturaInimigo) {
					inimigo1Ativo = 0;
					tiroAtivo = 0;
				}

				if (inimigo2Ativo == 1 && tiroX + 20 >= inimigoX2 && tiroX - 20 <= inimigoX2 + larguraInimigo && tiroY + 20 >= inimigoY && tiroY - 20 <= inimigoY + alturaInimigo) {
					inimigo2Ativo = 0;
					tiroAtivo = 0;
				}
				if (inimigo3Ativo == 1 && tiroX + 20 >= inimigoX3 && tiroX - 20 <= inimigoX3 + larguraInimigo && tiroY + 20 >= inimigoY && tiroY - 20 <= inimigoY + alturaInimigo) {
					inimigo3Ativo = 0;
					tiroAtivo = 0;
				}
				if (inimigo4Ativo == 1 && tiroX + 20 >= inimigoX4 && tiroX - 20 <= inimigoX4 + larguraInimigo && tiroY + 20 >= inimigoY && tiroY - 20 <= inimigoY + alturaInimigo) {
					inimigo4Ativo = 0;
					tiroAtivo = 0;
				}
			}



			/*--- SE SAIR DA TELA PARA ----- DELAY PARA PULO ---*/
			if (tiroX - cameraX > 1500 || tiroX - cameraX < 0 || tiroY > 980) {
				tiroAtivo = 0;
			}


			if (esperandoPulo == 1) {
				if (al_get_time() - momentoDoTiro >= 2.0) {


					if (noChao == 1) {
						pulando = 1;
						noChao = 0;
						maxAlt = -20;
					}


					esperandoPulo = 0;
				}
			}
			/*--- SE SAIR DA TELA PARA ----- DELAY PARA PULO ---*/






			/* ANIMACAO DO PERSONAGEM */


			if (esquerda || direita) {

				contadorAnimacao++;

				if (contadorAnimacao >= velocidadeAnimacao) {
					quadroAtual++;

					if (quadroAtual > 8) {
						quadroAtual = 1;
					}

					contadorAnimacao = 0;
				}
			}
			else {
				quadroAtual = 0;
				contadorAnimacao = 0;
			}




			/*--------------- TRANSIÇÃO DE FASES -------------*/


			if (passou == 1) {
				cor += 5;


				if (cor >= 255) {
					cor = 255;
					fase2++;

					if (fase2 == 1) {
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


			if (passou == 2) {
				cor -= 3;
				if (cor <= 0) {
					cor = 0;
					passou = 0;
				}
			}


			if (passou == 3) {
				cor += 5;
				if (cor >= 255) {
					cor = 255;

					al_destroy_bitmap(fundo);

					fundo = blibioteca;
					blibioteca = NULL;

					fase2 = 0;
					playerX = 10;
					playerY = 670;
					cameraX = 0;
					passou = 4;
					fase3 = 1;
				}
			}

			if (passou == 4) {
				cor -= 3;
				if (cor <= 0) {
					cor = 0;
					passou = 0;
				}
			}


			/*--------------- TRANSIÇÃO DE FASES -------------*/








			/*---------------- PERSONAGEM ANDAR PARA ESQUERDA  ------------------*/
			if (esquerda) {

				playerX += empurrao;
				empurrao -= 0.5;

				/* CORRE */
				if (shift == 1) {
					playerX -= 15;
				}/* CORRE */


				playerX -= 5;


				/* LIMITE FASE */
				if (playerX <= 0 - 80) {
					playerX = 0 - 80;
				}

				/* LIMITE FASE */
			}
			/*---------------- PERSONAGEM ANDAR PARA ESQUERDA ------------------*/




			if (direita) {
				/*---------------- PERSONAGEM ANDAR PARA DIREITA ------------------*/
				playerX += 5;

				playerX += empurrao;
				empurrao += 0.5;


				/* CORRE */
				if (shift == 1) {
					playerX += 10;


				}/* CORRE */


				/*---------------- PERSONAGEM ANDAR PARA DIREITA ------------------*/




					/*---------------- LIMITES DA FASE ------------------*/
				if (fase1 == 1) {
					if (playerX >= larguraFase - larguraPlayer + 80) {
						passou = 1;
					}
				}

				if (fase2 == 2 && playerX >= 1410 - larguraPlayer + 80) {
					passou = 3;
				}
				if (fase3 == 1 && playerX >= 2580 - larguraPlayer) {
					playerX = 2580 - larguraPlayer;
				}
			}
			/*---------------- LIMITES DA FASE ------------------*/




			if (pulando) {

				playerY += maxAlt;
				maxAlt += 0.5;

				if (playerY >= 670) {
					playerY = 670;
					maxAlt = 0;
					noChao = 1;
					pulando = 0;
				}

			}




			/* as 2 condicoes sao para que se o personagem sair da tela a acamera continua nela */
			if (fase1 == 1) {
				cameraX = playerX - 750;

				if (cameraX < 0) {
					cameraX = 0;
				}

				if (cameraX > larguraFase - 1600) {
					cameraX = larguraFase - 1600;
				}

			}
			else if (fase3 == 1) {

				cameraX = playerX - 800;

				if (cameraX < 0) {
					cameraX = 0;
				}

				if (cameraX > 1000) {
					cameraX = 1000;
				}

			}
			else {
				cameraX = 0;
			}
		}




		/*---------------- DESENHA FUNDO ------------------*/


		al_clear_to_color(al_map_rgb(30, 30, 30)); /* Limpa a cor da janela e, coloca outra no lugar */
		if (fase1 == 1) {
			al_draw_scaled_bitmap(fundo, 0 /*inicio X da imagem*/, 0 /*inicio Y da imagem*/, al_get_bitmap_width(fundo), al_get_bitmap_height(fundo),
				0 - cameraX /*X comeca do 0 */, 0 /*Y comeca do 0*/, 5000, 845, 0 /* 0 diz que a imgagem nao precisa ser invertida */);
		}
		if (fase2 == 2) {
			al_draw_bitmap(fundo, -cameraX, -80, 0);
		}
		if (fase3 == 1) {
			al_draw_scaled_bitmap(fundo, 0 /*inicio X da imagem*/, 0 /*inicio Y da imagem*/, al_get_bitmap_width(fundo), al_get_bitmap_height(fundo),
				0 - cameraX /*X comeca do 0 */, 0 /*Y comeca do 0*/, 2600, 1024, 0 /* 0 diz que a imgagem nao precisa ser invertida */);
		}
		/*---------------- DESENHA FUNDO CHAO ------------------*/



		/*---------- CORACAO  -----------*/
		if (fase1 == 1) {

			if (vidas == 3) {
				al_draw_scaled_bitmap(coracao1, 0, 0, al_get_bitmap_width(coracao1), al_get_bitmap_height(coracao1), 100, 0, 300, 100, 0);
			}
			if (vidas == 2) {
				al_draw_scaled_bitmap(coracao3, 0, 0, al_get_bitmap_width(coracao3), al_get_bitmap_height(coracao3), 100, 20, 200, 60, 0);
			}

			if (vidas == 1) {
				al_draw_scaled_bitmap(coracao2, 0, 0, al_get_bitmap_width(coracao2), al_get_bitmap_height(coracao2), 180, 20, 100, 70, 0);
			}
		}
		/*---------- CORACAO  -----------*/


		/* ------------- objetos escalada terceira fase --------------------*/
		if (fase3 == 1) {
			al_draw_scaled_bitmap(apoio1, 0 /*inicio X da imagem*/, 0/*inicio Y da imagem*/, al_get_bitmap_width(apoio1), al_get_bitmap_height(apoio1),
				1800 - cameraX/* X onde a  objeto pareacrece na tela */, 300 /* Y onde a objeto aparece na tela */, 150/* largura que a objeto  */, 50 /* altura */, 0);

			al_draw_scaled_bitmap(apoio1, 0 /*inicio X da imagem*/, 0/*inicio Y da imagem*/, al_get_bitmap_width(apoio1), al_get_bitmap_height(apoio1),
				1250 - cameraX/* X onde a  objeto pareacrece na tela */, 300 /* Y onde a objeto aparece na tela */, 150/* largura que a objeto  */, 50 /* altura */, 0);

			al_draw_scaled_bitmap(apoio2, 0 /*inicio X da imagem*/, 0/*inicio Y da imagem*/, al_get_bitmap_width(apoio2), al_get_bitmap_height(apoio2),
				1800 - cameraX/* X onde a  objeto aparece na tela */, 600 /* Y onde a arvore aparece na tela */, 300/* largura que a objeto  */, 300 /* altura */, 0);

			al_draw_scaled_bitmap(apoio3, 0 /*inicio X da imagem*/, 0/*inicio Y da imagem*/, al_get_bitmap_width(apoio3), al_get_bitmap_height(apoio3),
				2300 - cameraX/* X onde a  objeto aparece na tela */, 435 /* Y onde a objeto aparece na tela */, 300 /* largura que a objeto  */, 500 /* altura */, 0);
			/* ------------- objetos escalada terceira fase --------------------*/


		}
		/*---------------- DESENHA ARVORES PELO MAPA E O CHAO  ------------------*/
		if (fase1 == 1) {
			al_draw_scaled_bitmap(arvore, 0 /*inicio X da imagem*/, 0/*inicio Y da imagem*/, al_get_bitmap_width(arvore), al_get_bitmap_height(arvore),
				arvoreX1 - cameraX/* X onde a  arvore aparece na tela */, 240 /* Y onde a arvore aparece na tela */, 500/* largura que a arvore  */, 655 /* altura */, 0);

			al_draw_scaled_bitmap(arvore5, 0, 0, al_get_bitmap_width(arvore5), al_get_bitmap_height(arvore5), arvoreX5 - cameraX, 260, 400, 655, 0);

			al_draw_scaled_bitmap(arvore4, 0, 0, al_get_bitmap_width(arvore4), al_get_bitmap_height(arvore4), arvoreX3 - cameraX, 240, 500, 655, 0);




			al_draw_scaled_bitmap(chao, 0, 0, al_get_bitmap_width(chao), al_get_bitmap_height(chao), -cameraX, chaoY, larguraFase, 980 - chaoY, 0);
		}
		if (fase2 == 2) {
			al_draw_scaled_bitmap(chao2, 50, 0, al_get_bitmap_width(chao), 400, -cameraX, chaoY, larguraFase, 1010 - chaoY, 0);
		}
		/*---------------- DESENHA ARVORES PELO MAPA E O CHAO  ------------------*/



		al_set_blender(ALLEGRO_ADD, ALLEGRO_ALPHA, ALLEGRO_INVERSE_ALPHA);
		if (REDdano >=0 && fase1 == 1 && menosUM == 1 || menosUM == 2 || menosUM == 3) {
				REDdano += -0.01;
				al_draw_filled_rectangle(0, 0,1500, 980,al_map_rgba(255, 0, 0, REDdano));
				
		}


				
		
		
		
				if (tiroAtivo == 1 && fase1 == 1) {
					al_draw_filled_circle(tiroX - cameraX, tiroY, 20, al_map_rgb(255, 255, 255));
				}
			








			/* DESENHA O PERSONAGEM */
			int larguraTotal = al_get_bitmap_width(personagem);


			int origemX = quadroAtual * larguraTotal / 9;
			int proximoX = (quadroAtual + 1) * larguraTotal / 9;
			int larguraQuadro = proximoX - origemX;


			int direcao = 0;


			if (esquerda) {
				direcao = ALLEGRO_FLIP_HORIZONTAL;
			}




			al_draw_scaled_bitmap(
				personagem,
				origemX + 21, 205,           // Posição inicial do recorte
				larguraQuadro, 350,     // Dimensão de cada quadro
				playerX - cameraX, playerY,
				larguraPlayer, alturaPlayer - 30,
				direcao);










			/* HIT BOX INIMIGO */

			int larguraTotalInimigo = al_get_bitmap_width(inimigo);
			int alturaTotalInimigo = al_get_bitmap_height(inimigo);
			int origemInimigoX = quadroInimigo * larguraTotalInimigo / 9;
			int proximoInimigoX = (quadroInimigo + 1) * larguraTotalInimigo / 9;
			int larguraQuadroInimigo = proximoInimigoX - origemInimigoX;

			/* HIT BOX INIMIGO */


	/*---------- INIMIGOS MORRENDO -----------*/
			if (fase1 == 1) {

				if (inimigo1Ativo == 1) {
					int flip = 0;

					if (inimigoX > playerX) {
						flip = ALLEGRO_FLIP_HORIZONTAL;
					}

					al_draw_scaled_bitmap(inimigo, origemInimigoX, 0, larguraQuadroInimigo, alturaTotalInimigo, inimigoX - cameraX, inimigoY, larguraInimigo, alturaInimigo, flip);
				}

				if (inimigo2Ativo == 1) {
					int flip1 = 0;
					if (inimigoX2 > playerX) {
						flip1 = ALLEGRO_FLIP_HORIZONTAL;
					}
					al_draw_scaled_bitmap(inimigo, origemInimigoX, 0, larguraQuadroInimigo, alturaTotalInimigo, inimigoX2 - cameraX, inimigoY, larguraInimigo, alturaInimigo, flip1);
				}

				if (inimigo3Ativo == 1) {
					int flip2 = 0;

					if (inimigoX3 > playerX) {
						flip2 = ALLEGRO_FLIP_HORIZONTAL;
					}
					al_draw_scaled_bitmap(inimigo, origemInimigoX, 0, larguraQuadroInimigo, alturaTotalInimigo, inimigoX3 - cameraX, inimigoY, larguraInimigo, alturaInimigo, flip2);
				}

				if (inimigo4Ativo == 1) {
					int flip3 = 0;

					if (inimigoX4 > playerX) {
						flip3 = ALLEGRO_FLIP_HORIZONTAL;
					}
					al_draw_scaled_bitmap(inimigo, origemInimigoX, 0, larguraQuadroInimigo, alturaTotalInimigo, inimigoX4 - cameraX, inimigoY, larguraInimigo, alturaInimigo, flip3);
				}			
			}
			/*---------- INIMIGOS MORRENDO -----------*/




					/*PARA A TELA ESCURECER NA TRANSICAO*/
			if (cor > 0) {
				al_set_blender(ALLEGRO_ADD, ALLEGRO_ALPHA, ALLEGRO_INVERSE_ALPHA);


				al_draw_filled_rectangle(0, 0, 1500, 980, al_map_rgba(0, 0, 0, (int)cor));
			}
			/*PARA A TELA ESCURECER NA TRANSICAO*/






			al_flip_display(); /* Atualiza a janela, altera de desenhando para visivel */
		}




		/* Os fodoes que impedem seu pc de quebrar  (destroe as janelas)  */


		al_destroy_bitmap(fundo);
		al_destroy_bitmap(fundo2);
		al_destroy_bitmap(blibioteca);
		al_destroy_bitmap(coracao1);
		al_destroy_bitmap(coracao2);
		al_destroy_bitmap(coracao3);


		al_destroy_bitmap(chao);
		al_destroy_bitmap(personagem);
		al_destroy_bitmap(inimigo);


		al_destroy_bitmap(arvore);
		al_destroy_bitmap(arvore4);
		al_destroy_bitmap(arvore5);
		al_destroy_bitmap(apoio1);
		al_destroy_bitmap(apoio2);
		al_destroy_bitmap(apoio3);



		al_destroy_timer(timer);
		al_destroy_event_queue(fila);
		al_destroy_display(janela);




		return 0;
	
}