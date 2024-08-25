#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

//✦ ✧ ✦ ✧ ✦ ✧PEÕES✦ ✧ ✦ ✧ ✦ ✧
typedef struct {
int base;
int posicao;
int casas_finais;
} cadastro;




//✦ ✧ ✦ ✧ ✦ ✧TABULEIRO✦ ✧ ✦ ✧ ✦ ✧
void Tabuleiro (cadastro (*peao[2][4])){
  printf ("\n:---------TABULEIRO---------:\nJogador1:\n");
  for (int i=0; i<4; i++){
    printf ("- Peão %d na casa %d\n", i+1, peao[0][i]->posicao);
  }
  printf ("\nJogador 2: \n");
  for (int i=0; i<4; i++){
    printf ("- Peão %d na casa %d\n", i+1, peao[1][i]->posicao);
  }
}



//✦ ✧ ✦ ✧ ✦ ✧FUNÇÃO DADO✦ ✧ ✦ ✧ ✦ ✧
int RolarDado (){
  srand (time (NULL));
  return rand()%6+1;
}




//✦ ✧ ✦ ✧ ✦ ✧TRES SEIS✦ ✧ ✦ ✧ ✦ ✧
int TresSeis (int *dado){
  int tres_seis=0;
  
  *dado=RolarDado();
  while (*dado==6){
    if (*dado==6){
      tres_seis++;
    }
    *dado=RolarDado();
  }
  return tres_seis;
}




//✦ ✧ ✦ ✧ ✦ ✧JOGADOR ATUAL✦ ✧ ✦ ✧ ✦ ✧
int TrocarJogador (int *jogador_atual){
  if (*jogador_atual==0){
    return 1;
  }
  else {
    return 0;
  }
}




//✦ ✧ ✦ ✧ ✦ ✧FUNÇÃO DE MOVIMENTO✦ ✧ ✦ ✧ ✦ ✧
int MoverPeoes (cadastro *peoes, int *base, int dado, int jogador_atual){

  int op;
  int peao_escolhido;
  int tres_seis=0;
}



//✦ ✧ ✦ ✧ ✦ ✧CASAS FINAIS✦ ✧ ✦ ✧ ✦ ✧
void CasasFinais (cadastro *peao[2][4], int jogador_atual, int peao_escolhido){
  int cont_casa;
  
  if (jogador_atual==0){
    if (peao[0][peao_escolhido]->posicao>51){
      printf ("O seu peão %d entrou nas casas finais", peao_escolhido+1);
      cont_casa=peao[1][peao_escolhido]->posicao-51;
      peao[1][peao_escolhido]->posicao=0;
      peao[1][peao_escolhido]->casas_finais=cont_casa;
    }
  }
  
  if (jogador_atual==1){
    if (peao[1][peao_escolhido]->posicao>52){
      peao[1][peao_escolhido]->posicao=1;
      if (peao[1][peao_escolhido]->posicao>25){
        printf ("O seu peão %d entrou nas casas finais", peao_escolhido+1);
        cont_casa=peao[1][peao_escolhido]->posicao-25;
        peao[1][peao_escolhido]->posicao=0;
        peao[1][peao_escolhido]->casas_finais=cont_casa;
      }
    }
  }
}





//✦ ✧ ✦ ✧ ✦ ✧MOVER CASAS FINAIS✦ ✧ ✦ ✧ ✦ ✧
void MoverCF (cadastro *peao[2][4], int jogador_atual, int peao_escolhido, int dado){
  int faltam;
  if (peao[jogador_atual][peao_escolhido]->casas_finais>0){
    faltam=6-peao[jogador_atual][peao_escolhido]->casas_finais;
    if (dado!=faltam){
      printf ("Não é possível mover esse peão até o final\n(Necessário tirar %d no dado)", faltam);

      //colocar pra escolher outro peão??
    }
    else {
      printf ("Parabéns! Seu peão %d chegou ao final do tabuleiro", peao_escolhido);
      peao[jogador_atual][peao_escolhido]->casas_finais=6;
    }
  }
}




//✦ ✧ ✦ ✧ ✦ ✧ ✦ ✧MAIN✦ ✧ ✦ ✧ ✦ ✧ ✦ ✧
int main (){
  int dado;
  cadastro *peao[2][4];
  int jogador_atual=0;
  int *base[2];
  int peao_escolhido;
  int tres_seis;
  int op;


  //ପ( •̤ᴗ•̤ )੭⁾⁾.｡.:✽・ﾟ＋ INICIALIZAR PEOES
  for (int i=0; i<4; i++){
    peao[0][i] = malloc(sizeof(cadastro));
    peao[1][i] = malloc(sizeof(cadastro));

    peao[0][i]->posicao=1;
    peao[1][i]->posicao=27;

    peao[0][i]->base=1;
    peao[1][i]->base=1;
    
    peao[0][i]->casas_finais=0;
    peao[1][i]->casas_finais=0;
  }


int i=0;
  while (1){
  
    printf ("............. Vez do jogador %d .............\n\n", jogador_atual+1);
    
    tres_seis=TresSeis(&dado);
    
    //caso o numero 6 saia uma vez
    if (tres_seis==1){
      printf ("Dado1 = 6\nDado2 = %d\n", dado);
      printf ("Escolha um peão para ser movido: ");
      scanf ("%d", &peao_escolhido);
      
      if (peao[jogador_atual][peao_escolhido-1]->base==1 && i==0){
        printf ("Voce tirou o peão %d da base\n\n", peao_escolhido);
        peao[jogador_atual][peao_escolhido-1]->base=0;
      }
        
      else if (peao[jogador_atual][peao_escolhido-1]->base==1 && i!=0){
        printf ("Não é possível tirar o peão da base ainda :(\n(Necessário um 6 no dado)\n\n");
        i--;
      }
        
      else {
        peao[jogador_atual][peao_escolhido-1]->posicao+=6;
        Tabuleiro(peao);// parametros
        CasasFinais(peao, jogador_atual, peao_escolhido);// parametros
        //add comer
      }
      
      printf ("Escolha um peão para ser movido: ");
      scanf ("%d", &peao_escolhido);
      if (peao[jogador_atual][peao_escolhido-1]->base==1){
        printf ("Não é possível tirar um peão da base ainda :(\n(Necessário um 6 no dado)\n\n");
      }
        
      else {
        peao[jogador_atual][peao_escolhido-1]->posicao+=dado;
        Tabuleiro(peao);
        CasasFinais(peao, jogador_atual, peao_escolhido);
        //add comer
      }
    }
    
    else if (tres_seis==2){
      printf ("Dado1 = 6\nDado2 = 6\nDado3 = %d", dado);
      for (int i=0; i<2; i++){
        printf ("Escolha um peão para ser movido: ");
        scanf ("%d", &peao_escolhido);
        if (peao[jogador_atual][peao_escolhido-1]->base==1){
          printf ("Voce tirou o peão %d da base\n\n", peao_escolhido);
          peao[jogador_atual][peao_escolhido-1]->base=0;
        }
        else {
          peao[jogador_atual][peao_escolhido-1]->posicao+=6;
          Tabuleiro (peao);
          CasasFinais(peao, jogador_atual, peao_escolhido);
          //add comer
        }
      }
      if (peao[jogador_atual][peao_escolhido-1]->base==1){
        printf ("Voce tirou o peão %d da base\n\n", peao_escolhido);
        peao[jogador_atual][peao_escolhido-1]->base=0;
      }
      else {
        peao[jogador_atual][peao_escolhido-1]->posicao+=dado;
        Tabuleiro (peao);
        CasasFinais(peao, jogador_atual, peao_escolhido);
      }
    }

    else if (tres_seis==3){
      printf ("Perdeu a vez, lol\nBOBÃO");
      break;
    }

    else if (tres_seis==0){
      printf ("Dado = %d\n", dado);
      printf ("Escolha um peão pra ser movido: ");
      scanf ("%d", &peao_escolhido);
      if (peao[jogador_atual][peao_escolhido-1]->base==1){
        printf ("Não é possível tirar um peão da base ainda :(\n(Necessário um 6 no dado)\n\n");
      }
        
      else {
        peao[jogador_atual][peao_escolhido]->posicao+=dado;
        Tabuleiro (peao);
        CasasFinais(peao, jogador_atual, peao_escolhido);
      }
    }


    jogador_atual=TrocarJogador(&jogador_atual);
    i++;
  }



  




  return 0;
}