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
	ALLEGRO_BITMAP* morte;
	ALLEGRO_BITMAP* inicio;
	ALLEGRO_BITMAP* mirando;
	ALLEGRO_BITMAP* maca;
	ALLEGRO_BITMAP* final;
	ALLEGRO_BITMAP* cut;
	ALLEGRO_BITMAP* scene;



	apoio1 = al_load_bitmap("imagens/apoio.png");
	apoio2 = al_load_bitmap("imagens/bigmadeira.png");
	apoio3 = al_load_bitmap("imagens/madeira.png");

	inicio = al_load_bitmap("imagens/inicial.png");
	fundo = al_load_bitmap("imagens/fundo.png");
	fundo2 = al_load_bitmap("imagens/fundo-fase2.png");
	blibioteca = al_load_bitmap("imagens/blibio.png");
	final = al_load_bitmap("imagens/final.png");
	morte = al_load_bitmap("imagens/morte.png");
	cut = al_load_bitmap("imagens/cut.png");
	scene = al_load_bitmap("imagens/scene.png");
	chao2 = al_load_bitmap("imagens/chao.png");
	chao = al_load_bitmap("imagens/chao.png");

	coracao1 = al_load_bitmap("imagens/coracao.png");
	coracao2 = al_load_bitmap("imagens/hart2.png");
	coracao3 = al_load_bitmap("imagens/hort3.png");


	mirando = al_load_bitmap("imagens/mirando-chao.png");
	personagem = al_load_bitmap("imagens/personagem.png");
	inimigo = al_load_bitmap("imagens/inimigo.png");



	maca = al_load_bitmap("imagens/maca.png");
	arvore = al_load_bitmap("imagens/arvore2.png");
	arvore4 = al_load_bitmap("imagens/arvore4.png");
	arvore5 = al_load_bitmap("imagens/arvore5.png");


	if (!chao || !arvore || !arvore4 || !arvore5 || !fundo || !fundo2 || !chao2 || !personagem || !inimigo || !coracao1|| !coracao2 || !coracao3 || !inicio || !mirando || !maca ||!cut || !scene) {
		return -1;
	}


	/*--------------------------------IMAGENS-------------------------------------*/







	/*terceira fase */
	/* bloco2 kk  */
	float blocoX2 = 1250;
	float blocoY2 = 300;
	float largurabloco2 = 140;
	float alturabloco2 = 50;

	/* bloco  */
	float blocoX = 1800;
	float blocoY = 300;
	float largurabloco = 140;
	float alturabloco = 50;


	/* Variaveis da parede */
	float paredeX = 2130;
	float paredeY = 735;
	float larguraParede = 160;
	float alturaParede = 150;


	/* bloco3   */
	float blocoX3 = 2350;
	float blocoY3 = 500;
	float largurabloco3 = 280;
	float alturabloco3 = 50;

	/*terceira fase */

	/*QUARTA BLOCOS */


	float blocoX4 = 100;
	float blocoY4 = 345;
	float largurabloco4 = 250;
	float alturabloco4 = 50;

	float blocoX5 = 1250;
	float blocoY5 = 345;
	float largurabloco5 = 250;
	float alturabloco5 = 50;

	float blocoX6 = 600;
	float blocoY6 = 345;
	float largurabloco6 = 190;
	float alturabloco6 = 50;


	float blocoX7 = 1720;
	float blocoY7 = 570;
	float largurabloco7 = 400;
	float alturabloco7 = 400;

	float blocoX8 = 838;
	float blocoY8 = 585;
	float largurabloco8 = 350;
	float alturabloco8 = 300;



	/* ----- Variaveis da fase ----- */
	int start = 1;
	int fase1 = 1;
	int fase2 = 0;
	int fase3 = 0;
	int fase4 = 0;
	int telaMorte = 0;
	float larguraFase = 5000;
	float cameraX = 0;
	float chaoY = 600;
	int passou = 0;
	float cor = 0;




	float arvoreX1 = 1500;
	float arvoreX3 = 3200;
	float arvoreX4 = 3500;
	float arvoreX5 = 4000;







	float Xblibioteca = 850;
	float Yblibioteca = 750;



	/* ----- Variaveis da fase ----- */






	/* VARIAVEIS JOGADOR ESTATICO  */
	int perso = 1;
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


	/* variaveis maca*/
	int quadroMaca = 0;
	int contadorMaca = 0;
	int velocidadeAnimacaoMaca = 5;
	/* variaveis maca*/


	/* colisao objetos  */

	int mouse = 0;



	/* Variaveis do inimigo */

	float inimigoX = 1300; 
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
	float velocidadeInimigo = 4;


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
	float momentoDoTiro = 0;
	int esperandoPulo = 0;
	float tiroX = 0;
	float tiroY = 0;
	int tiroAtivo = 0;
	int velocidadeTiro = 5;
	int direcaoTiro = 1; /* 1 = direita, 2 = esquerda, -1 = baixo */

	/* ----------------------------------*/






	ALLEGRO_TIMER* timer;
	timer = al_create_timer(1.0 / 60.0);




	al_install_mouse();


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

	al_register_event_source(
		fila,
		al_get_mouse_event_source()
	);
	/* ------------------------------------ */



	al_start_timer(timer);




	while (rodando)
	{
		ALLEGRO_EVENT evento;


		al_wait_for_event(fila, &evento);


		if (start == 1) {
			fase1 = 0;
			fase2 = 0;
			fase3 = 0;
			fase4 = 0;
			perso = 0;
		}


		if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		{
			rodando = 0;
		}

		if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {

			if (evento.mouse.button == 1) {
				mouse = 1;
			}

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

			if (tiroAtivo == 0) {

			if (evento.keyboard.keycode == ALLEGRO_KEY_F) {

				/*empurrar pensonagem ao atirar*/

				if (fase1 == 1 || fase2 == 2) {
				tiroAtivo = 1;
				empurrao = -35;

				if (!direita && !esquerda) {
					empurrao = -200;
					playerX += empurrao;
					empurrao += 0.5;
					empurrao = 0;

					if (playerX <= 0) {
						playerX = 0 - 80;
					}
				}

				if (esquerda) {
					empurrao = 35;
					}
				}

				tiroY = playerY + 100;
				/*empurrar pensonagem ao atirar*/


				/*fala pra que lado o personagem ta olhjabndo*/
				if (esquerda) {
					tiroX = playerX;
					direcaoTiro = 1;
				}
				else {
					tiroX = playerX + larguraPlayer;
					direcaoTiro = 2;
				}
			if (fase4 == 1 ||  fase3 == 1  && segurando == 1 && noChao == 1 && esperandoPulo == 0) {
				tiroAtivo = 0;
				tiroX = playerX + larguraPlayer / 2;
				tiroY = playerY + alturaPlayer - 30;
				direcaoTiro = -1;
				/*fala pra que lado o personagem ta olhjabndo*/


				/* marca o momento do tiro mas ainda nao pula */
				momentoDoTiro = al_get_time();
				esperandoPulo = 1;
			}
			}
		}
		
			


			if (fase1 == 1 || fase3 == 1 || fase4 == 1) {
			 if (evento.keyboard.keycode == ALLEGRO_KEY_LSHIFT) {
			   shift = 1;
			 }
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
					REDdano = 100;
				}


				if (inimigo2Ativo == 1 && playerX + larguraPlayer >= inimigoX2 && playerX <= inimigoX2 + larguraInimigo && playerY + alturaPlayer - 30 >= inimigoY && playerY <= inimigoY + alturaInimigo) {
					inimigo2Ativo = 0;
					levouDano = 1;
					menosUM++;
					REDdano = 100;
				}

				if (inimigo3Ativo == 1 && playerX + larguraPlayer >= inimigoX3 && playerX <= inimigoX3 + larguraInimigo && playerY + alturaPlayer - 30 >= inimigoY && playerY <= inimigoY + alturaInimigo) {
					inimigo3Ativo = 0;
					levouDano = 1;
					menosUM++;
					REDdano = 100;
				}

				if (inimigo4Ativo == 1 && playerX + larguraPlayer >= inimigoX4 && playerX <= inimigoX4 + larguraInimigo && playerY + alturaPlayer - 30 >= inimigoY && playerY <= inimigoY + alturaInimigo) {
					inimigo4Ativo = 0;
					levouDano = 1;
					menosUM++;
					REDdano = 100;
				}

				if (levouDano == 1 || levouDano == 2) {
					vidas--;


					ultimoDano = al_get_time();

					if (vidas <= 0) {
						telaMorte = 1;
						fase1 = 0;
						blibioteca = 0;
						fase2 = 0;

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

/*------------------------ colisao tiro com inimigo ------------------------------ */
			if (fase1 == 1 && tiroAtivo == 1) {
				if (inimigo1Ativo == 1 && tiroX + 20 >= inimigoX && tiroX - 20 <= inimigoX + larguraInimigo && tiroY + 20 >= inimigoY && tiroY - 20 <= inimigoY + alturaInimigo) {
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

			/*------------------------ colisao tiro com inimigo ------------------------------ */



						/*--- SE SAIR DA TELA PARA ----- DELAY PARA PULO ---*/
			if (tiroX - cameraX > 1500 || tiroX - cameraX < 0 || tiroY > 980) {
				tiroAtivo = 0;
			}


			if (esperandoPulo == 1 &&( fase3 == 1 || fase4 == 1)) {
				if (al_get_time() - momentoDoTiro >= 2.0) {

					tiroX += 0;


					if (noChao == 1) {
						tiroY = playerY + alturaPlayer - 30;
						pulando = 1;
						noChao = 0;
						maxAlt = -15;
					}
					tiroAtivo = 1;
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
						fase1 = 0;
						fase2 = 2;


						cameraX = 0;
						playerY = 620;
						playerX = 10;
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

					fase2 = 0;

					cameraX = 0;
					passou = 4;
					fase3 = 1;
					playerX = 10;
					playerY = 670;
				}
			}

			if (passou == 4) {
				cor -= 3;
				if (cor <= 0) {
					cor = 0;
					passou = 0;
				}
			}

			if (passou == 5) {
				cor += 3;

				if (cor >= 255) {
					cor = 255;

				}
					fase3 = 0;
					fase4 = 1;

					passou++;
					cameraX = 0;

					playerY = 130;
					playerX = 100;
			}
			if (passou == 6) {
				cor -= 3;
				if (cor <= 0) {
					cor = 0;
					passou = 0;
				}
			}

			/*--------------- TRANSIÇÃO DE FASES -------------*/








			/*---------------- PERSONAGEM ANDAR PARA ESQUERDA  ------------------*/
			if (esquerda) {
				if (empurrao == 0) {
					playerX -= 5;
				}


				// Aplica o impulso
				playerX += empurrao;

				/* Empurrao */
				if (empurrao >= 0) {
					empurrao -= 0.5;

					if (empurrao <= 0) {
						empurrao = 0;
					}
				}
				if (empurrao <= 0) {
					empurrao += 0.5;

					if (empurrao >= 0) {
						empurrao = 0;
					}
				}
				/* Empurrao */

				/* CORRE */
				if (shift == 1) {
					playerX -= 15;
				}/* CORRE */




				/* LIMITE FASE */
				if (playerX <= 0 - 80) {
					playerX = 0 - 80;
				}
			}
			if (fase4 == 1) {
			if (playerX + larguraPlayer <=  blocoX8 + largurabloco8 + 100 && playerX + larguraPlayer >= blocoX8 + largurabloco8 - 250 && playerY >= alturabloco8 + 100) {
				playerX = blocoX8 + largurabloco8 - 80 ;
			}
			else { playerX = playerX; }
		}
			

				/* LIMITE FASE */


			/*---------------- PERSONAGEM ANDAR PARA ESQUERDA ------------------*/




				if (direita) {
					/*---------------- PERSONAGEM ANDAR PARA DIREITA ------------------*/
					if (empurrao == 0) {
						playerX += 5;
					}


					/* Empurrao */
					playerX += empurrao;
					if (empurrao >= 0) {
						empurrao -= 0.5;

						if (empurrao <= 0) {
							empurrao = 0;
						}
					}
					if (empurrao <= 0) {
						empurrao += 0.5;

						if (empurrao >= 0) {
							empurrao = 0;
						}
					}
					/* Empurrao */


					/* CORRE */
					if (shift == 1) {
						playerX += 10;
					}/* CORRE */

					if (fase4 == 1) {
					if (playerX + larguraPlayer >= blocoX8 + 100 && playerX + larguraPlayer <= blocoX8 + 150 && playerY >= alturabloco8 + 100) {
						playerX = blocoX8 - larguraPlayer + 90;
					}
					if (playerX + larguraPlayer >= blocoX7 + 100 && playerX + larguraPlayer <= blocoX7 + 150 && playerY >= alturabloco7 ) {
						playerX = blocoX7 - larguraPlayer + 90;
					}
				}

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

					/*fase TRES */
					if (fase3 == 1) {
						float pePlayer = playerY + alturaPlayer - 45;

						if (playerY + alturaPlayer >= 780 && playerX + larguraPlayer > paredeX && playerX < paredeX + larguraParede - 80) {
							maxAlt = 0;
							noChao = 1;
						}

						if (pePlayer >= blocoY && pePlayer - 50 <= blocoY + 10 && playerX + larguraPlayer > blocoX && playerX < blocoX + largurabloco - 30) {
							maxAlt = 0;
							noChao = 1;
						}

						if (pePlayer >= blocoY && pePlayer - 50 <= blocoY + 10 && playerX + larguraPlayer > blocoX2 && playerX < blocoX2 + largurabloco2 - 30) {
							passou = 5;
							maxAlt = 0;
							noChao = 1;
						}

						if (playerY - alturaPlayer <= 65 && playerY - alturaPlayer > 55 && playerX + larguraPlayer > blocoX3 && playerX < blocoX3 + largurabloco3) {
							maxAlt = 0;
							noChao = 1;
						}
					}

					/*fase TRES */


					/*fase "QUATRO" TRES E MEIO */
					float pePlayer = playerY + alturaPlayer - 45;

					if (pePlayer >= blocoY4 && pePlayer <= blocoY4 + 10 && playerX + larguraPlayer > blocoX4 && playerX < blocoX4 + largurabloco4 - 50) {
						maxAlt = 0;
						noChao = 1;
					}

					if (pePlayer >= blocoY5 && pePlayer <= blocoY5 + 10 && playerX - 70 + larguraPlayer > blocoX5 && playerX < blocoX5 + largurabloco5 - 50) {
						maxAlt = 0;
						noChao = 1;
					}

					if (pePlayer >= blocoY6 && pePlayer <= blocoY6 + 10 && playerX + larguraPlayer > blocoX6 && playerX < blocoX6 + largurabloco6 - 50) {
						maxAlt = 0;
						noChao = 1;
					}
					if (playerY + alturaPlayer >= 620 && pePlayer <= blocoY7 + 10 && playerX + larguraPlayer > blocoX7 && playerX < blocoX7 + largurabloco7) {
						maxAlt = 0;
						noChao = 1;
					}

					if (playerY + alturaPlayer >= 620 && pePlayer <= blocoY8 && playerX + larguraPlayer > blocoX8 && playerX < blocoX8 + largurabloco8) {
						maxAlt = 0;
						noChao = 1;
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

				if (fase4 == 1) {
					cameraX = playerX - 800;

					if (cameraX < 0) {
						cameraX = 0;
					}
					if (cameraX > 500) {
						cameraX = 500;
					}
				}

				contadorMaca++;
				if (contadorMaca >= velocidadeAnimacaoMaca) {

					quadroMaca++;

					if (quadroMaca > 2) {
						quadroMaca = 0;
					}

					contadorMaca = 0;

				}
			}




		/*---------------- DESENHA INICIO/ FUNDO1 / FUNDO2 / FUNDO3 ------------------*/
		al_clear_to_color(al_map_rgb(30, 30, 30)); /* Limpa a cor da janela e, coloca outra no lugar */
		if (fase1 == 1) {
			al_draw_scaled_bitmap(fundo, 0 /*inicio X da imagem*/, 0 /*inicio Y da imagem*/, al_get_bitmap_width(fundo), al_get_bitmap_height(fundo),
				0 - cameraX /*X comeca do 0 */, 0 /*Y comeca do 0*/, 5000, 845, 0 /* 0 diz que a imgagem nao precisa ser invertida */);
		}
		if (fase2 == 2) {
			al_draw_bitmap(fundo2, -cameraX, -80, 0);
		}
		if (fase3 == 1) {
			if (fase3 == 1) {
				al_draw_scaled_bitmap(blibioteca, 0 /*inicio X da imagem*/, 0 /*inicio Y da imagem*/, al_get_bitmap_width(blibioteca), al_get_bitmap_height(blibioteca),
					0 - cameraX /*X comeca do 0 */, 0 /*Y comeca do 0*/, 2600, 1024, 0 /* 0 diz que a imgagem nao precisa ser invertida */);
			}
		}
		if (fase4 == 1) {
			al_draw_scaled_bitmap(final, 0 /*inicio X da imagem*/, 0 /*inicio Y da imagem*/, al_get_bitmap_width(final), al_get_bitmap_height(final),
				0 - cameraX /*X comeca do 0 */, 0 /*Y comeca do 0*/, 2000, 1024 , 0 /* 0 diz que a imgagem nao precisa ser invertida */);
		}
		/*---------------- DESENHA FUNDO CHAO ------------------*/



		/*---------- CORACAO E DEIXA A TELA VERMELHA AO TOMAR DANO -----------*/
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
	
		al_set_blender(ALLEGRO_ADD, ALLEGRO_ALPHA, ALLEGRO_INVERSE_ALPHA);
		if (REDdano >= 0 && fase1 == 1 && menosUM == 1 || menosUM == 2 || menosUM == 3) {
			REDdano += -0.01;
			al_draw_filled_rectangle(0, 0, 1500, 980, al_map_rgba(255, 0, 0, REDdano));
		}
				
		/*---------- CORACAO E TELA VERMELHA AO TOMAR DANO  -----------*/


		/* ------------- objetos escalada terceira fase --------------------*/
		if (fase3 == 1 ) {
			al_draw_scaled_bitmap(apoio1, 0 /*inicio X da imagem*/, 0/*inicio Y da imagem*/, al_get_bitmap_width(apoio1), al_get_bitmap_height(apoio1),
				1800 - cameraX/* X onde a  objeto pareacrece na tela */, 300 /* Y onde a objeto aparece na tela */, 150/* largura que a objeto  */, 50 /* altura */, 0);

			al_draw_scaled_bitmap(apoio1, 0 /*inicio X da imagem*/, 0/*inicio Y da imagem*/, al_get_bitmap_width(apoio1), al_get_bitmap_height(apoio1),
				1250 - cameraX/* X onde a  objeto pareacrece na tela */, 300 /* Y onde a objeto aparece na tela */, 150/* largura que a objeto  */, 50 /* altura */, 0);

			al_draw_scaled_bitmap(apoio2, 0 /*inicio X da imagem*/, 0/*inicio Y da imagem*/, al_get_bitmap_width(apoio2), al_get_bitmap_height(apoio2),
				2100 - cameraX/* X onde a  objeto aparece na tela */, 700 /* Y onde a arvore aparece na tela */, 200/* largura que a objeto  */, 200 /* altura */, 0);

			al_draw_scaled_bitmap(apoio3, 0 /*inicio X da imagem*/, 0/*inicio Y da imagem*/, al_get_bitmap_width(apoio3), al_get_bitmap_height(apoio3),
				2300 - cameraX/* X onde a  objeto aparece na tela */, 435 /* Y onde a objeto aparece na tela */, 300 /* largura que a objeto  */, 500 /* altura */, 0);
			/* ------------- objetos escalada terceira fase --------------------*/
			
		}

		/*---------------- DESENHA ARVORES PELO MAPA E O CHAO  ------------------*/



		if (fase4 == 1) {
			al_draw_scaled_bitmap(apoio1, 0 /*inicio X da imagem*/, 0/*inicio Y da imagem*/, al_get_bitmap_width(apoio1), al_get_bitmap_height(apoio1),
				100 - cameraX/* X onde a  objeto pareacrece na tela */, 340 /* Y onde a objeto aparece na tela */, 250/* largura que a objeto  */, 50 /* altura */, 0);

			al_draw_scaled_bitmap(apoio1, 0 /*inicio X da imagem*/, 0/*inicio Y da imagem*/, al_get_bitmap_width(apoio1), al_get_bitmap_height(apoio1),
				1250 - cameraX/* X onde a  objeto pareacrece na tela */, 340 /* Y onde a objeto aparece na tela */, 250/* largura que a objeto  */, 50 /* altura */, 0);


			al_draw_scaled_bitmap(apoio1, 0 /*inicio X da imagem*/, 0/*inicio Y da imagem*/, al_get_bitmap_width(apoio1), al_get_bitmap_height(apoio1),
				600 - cameraX/* X onde a  objeto pareacrece na tela */, 340 /* Y onde a objeto aparece na tela */, 190/* largura que a objeto  */, 50 /* altura */, 0);

			al_draw_scaled_bitmap(apoio3, 0 /*inicio X da imagem*/, 0/*inicio Y da imagem*/, al_get_bitmap_width(apoio3), al_get_bitmap_height(apoio3),
				1660 - cameraX/* X onde a  objeto aparece na tela */, 520 /* Y onde a objeto aparece na tela */, 400 /* largura que a objeto  */, 400 /* altura */, 0);
			/* ------------- objetos escalada terceira fase --------------------*/



		}










		if (fase1 == 1) {
			al_draw_scaled_bitmap(arvore, 0 /*inicio X da imagem*/, 0/*inicio Y da imagem*/, al_get_bitmap_width(arvore), al_get_bitmap_height(arvore),
				arvoreX1 - cameraX/* X onde a  arvore aparece na tela */, 240 /* Y onde a arvore aparece na tela */, 500/* largura que a arvore  */, 655 /* altura */, 0);

			al_draw_scaled_bitmap(arvore5, 0, 0, al_get_bitmap_width(arvore5), al_get_bitmap_height(arvore5), arvoreX5 - cameraX, 260, 400, 655, 0);

			al_draw_scaled_bitmap(arvore4, 0, 0, al_get_bitmap_width(arvore4), al_get_bitmap_height(arvore4), arvoreX3 - cameraX, 240, 500, 655, 0);




			al_draw_scaled_bitmap(chao, 0, 0, al_get_bitmap_width(chao), al_get_bitmap_height(chao), -cameraX, chaoY, larguraFase, 980 - chaoY, 0);
		}
		if (fase2 == 2) {
			al_draw_scaled_bitmap(chao2, 50, 0, al_get_bitmap_width(chao), 130, -cameraX, chaoY, larguraFase, 980 - chaoY, 0);
		}
		/*---------------- DESENHA ARVORES PELO MAPA E O CHAO  ------------------*/

		if (start == 1) {
		al_draw_bitmap(inicio, 0, 0, 0);
		  al_draw_filled_rectangle(760, 470, 1220, 580, al_map_rgba(255, 0, 0,0));
		  al_draw_filled_rectangle(760, 640, 1220, 770, al_map_rgba(255, 0, 0, 0));

		if (mouse == 1 && evento.mouse.x >= 760 && evento.mouse.x <= 1220 && evento.mouse.y >= 470 && evento.mouse.y <= 580) {
			start = 0;
			playerY = 100;
			pulando = 1;
			noChao = 0;
			fase4 = 1;
			perso = 1;
			mouse = 0;
		}

		if (mouse == 1 && evento.mouse.x >= 760 && evento.mouse.x <= 1220 && evento.mouse.y >= 640 && evento.mouse.y <= 770) {
			rodando = 0;
		}
	}
		








		/*desenha blocos para colicoes do objetos */
		if (fase3 == 1) {
		al_draw_filled_rectangle(blocoX -cameraX, blocoY, blocoX - cameraX + largurabloco, blocoY + alturabloco, al_map_rgba(255, 0, 0, 0));

		al_draw_filled_rectangle(blocoX2 -cameraX, blocoY2, blocoX2 - cameraX + largurabloco2, blocoY2 + alturabloco2, al_map_rgba(255, 0, 0, 0));

		al_draw_filled_rectangle(blocoX3 - cameraX, blocoY3, blocoX3 - cameraX + largurabloco3, blocoY3 + alturabloco3, al_map_rgba(255, 0, 0, 0));

		al_draw_filled_rectangle(paredeX - cameraX, paredeY, paredeX - cameraX + larguraParede, paredeY + alturaParede, al_map_rgba(255, 0, 0, 0));
		}
		/*desenha blocos para colicoes do objetos */
		
		if (fase4 == 1) {
			al_draw_filled_rectangle(blocoX4 - cameraX, blocoY4, blocoX4 - cameraX + largurabloco4, blocoY4 + alturabloco4, al_map_rgba(255, 0, 0, 0));

			al_draw_filled_rectangle(blocoX5 - cameraX, blocoY5, blocoX5 - cameraX + largurabloco5, blocoY5 + alturabloco5, al_map_rgba(255, 0, 0, 0));

			al_draw_filled_rectangle(blocoX6 - cameraX, blocoY6, blocoX6 - cameraX + largurabloco6, blocoY6 + alturabloco6, al_map_rgba(255, 0, 0, 0));

			al_draw_filled_rectangle(blocoX7 - cameraX, blocoY7, blocoX7 - cameraX + largurabloco7, blocoY7 + alturabloco7, al_map_rgba(255, 0, 0, 0));

			al_draw_filled_rectangle(blocoX8 - cameraX, blocoY8, blocoX8 - cameraX + largurabloco8, blocoY8 + alturabloco8, al_map_rgba(255, 0, 0, 0));


		}


















		
		
			/*---------------- DESENHA O TIRO   ------------------*/
		if (tiroAtivo == 1 && fase1 == 1 || fase2 == 2) {
			tiroY += 3;
			if (tiroY >= 835) {
				tiroAtivo = 0;
			}
				int larguraTotalMaca = al_get_bitmap_width(maca);
				int alturaTotalMaca = al_get_bitmap_height(maca);
				int larguraQuadroMaca = larguraTotalMaca / 3;
				int origemXMaca = quadroMaca * larguraQuadroMaca;
			
				al_draw_scaled_bitmap(maca, origemXMaca, 0, larguraQuadroMaca, alturaTotalMaca, tiroX - cameraX - 22, tiroY - 22, 80, 80, 0);
			}

					if (fase3 == 1 || fase4 == 1 && tiroAtivo == 1 && direcaoTiro == -1) {
						int larguraTotalMaca = al_get_bitmap_width(maca);
						int alturaTotalMaca = al_get_bitmap_height(maca);
						int larguraQuadroMaca = larguraTotalMaca / 3;
						int origemXMaca = quadroMaca * larguraQuadroMaca;

						al_draw_scaled_bitmap(maca, origemXMaca -50 , 0, larguraQuadroMaca - 50, alturaTotalMaca, tiroX - cameraX - 22, tiroY - 22, 80, 80, 0);
						al_draw_filled_circle(tiroX - cameraX, tiroY, 20, al_map_rgba(255, 255, 255, 0));	
					}

			/*---------------- DESENHA O TIRO   ------------------*/








			/* DESENHA O PERSONAGEM */

			if (perso == 1 && esperandoPulo == 0) {
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

			}



			/*personagem com canhao para baixo*/
			if ((fase4 == 1 || fase3 == 1) && perso == 1 && esperandoPulo == 1) {

				int larguraTotal = al_get_bitmap_width(mirando);
				int origemX = quadroAtual * larguraTotal / 9;
				int proximoX = (quadroAtual + 1) * larguraTotal / 9;
				int larguraQuadro = proximoX - origemX;


				int direcao = 0;


				if (esquerda) {
					direcao = ALLEGRO_FLIP_HORIZONTAL;
				}



				al_draw_scaled_bitmap(mirando,origemX + 21, 180,  larguraQuadro, 350,  playerX - cameraX, playerY,larguraPlayer, alturaPlayer - 30,direcao);
			}
			/*personagem com canhao para baixo*/

			

			/* HIT BOX INIMIGO */

			int larguraTotalInimigo = al_get_bitmap_width(inimigo);
			int alturaTotalInimigo = al_get_bitmap_height(inimigo);
			int origemInimigoX = quadroInimigo * larguraTotalInimigo / 9;
			int proximoInimigoX = (quadroInimigo + 1) * larguraTotalInimigo / 9;
			int larguraQuadroInimigo = proximoInimigoX - origemInimigoX;

			/* HIT BOX INIMIGO */


	/*---------- DESENHANDO INIMIGOS -----------*/
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
			/*---------- DESENHANDO INIMIGOS -----------*/




					/*PARA A TELA ESCURECER NA TRANSICAO*/
			if (cor > 0) {
				al_set_blender(ALLEGRO_ADD, ALLEGRO_ALPHA, ALLEGRO_INVERSE_ALPHA);


				al_draw_filled_rectangle(0, 0, 1500, 980, al_map_rgba(0, 0, 0, (int)cor));
			}
			/*PARA A TELA ESCURECER NA TRANSICAO*/

		/*tela de morte  E quadrado para clicar em reiniciar */
		if (telaMorte == 1) {
			perso = 0;
			al_draw_scaled_bitmap(morte, 0, 0 , al_get_bitmap_width(morte), al_get_bitmap_height(morte), 0 - cameraX,0, 1671, 941, 0 );
			al_draw_filled_rectangle(500, 750, 1150, 900, al_map_rgba(255, 0, 0, 0));
		}
		if (telaMorte == 1 && mouse == 1 && evento.mouse.x >= 500 && evento.mouse.x <= 1150 && evento.mouse.y >= 750 && evento.mouse.y <= 900) {	
			fase1 = 1;
			telaMorte = 0;

			perso = 1;
			playerX = 100;
			playerY = 620;
			menosUM = 0;
			REDdano = 70;
			vidas = 3;

			inimigo1Ativo = 1;
			inimigo2Ativo = 1;
			inimigo3Ativo = 1;
			inimigo4Ativo = 1;


			inimigoX = 1300;
			inimigoX2 = -500;
			inimigoX3 = -1500;
			inimigoX4 = 4000;		
		}
				

			


			al_flip_display(); /* Atualiza a janela, altera de desenhando para visivel */
		}




		/* Os fodoes que impedem seu pc de quebrar  (destroe as janelas)  */

		al_destroy_bitmap(inicio);
		al_destroy_bitmap(fundo);
		al_destroy_bitmap(fundo2);
		al_destroy_bitmap(blibioteca);
		al_destroy_bitmap(morte);
		al_destroy_bitmap(chao);
		al_destroy_bitmap(final);
		al_destroy_bitmap(cut);
		al_destroy_bitmap(scene);

		al_destroy_bitmap(coracao1);
		al_destroy_bitmap(coracao2);
		al_destroy_bitmap(coracao3);


		al_destroy_bitmap(mirando);
		al_destroy_bitmap(personagem);
		al_destroy_bitmap(inimigo);
		al_destroy_bitmap(maca);

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