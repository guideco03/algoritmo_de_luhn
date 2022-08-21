#include<stdio.h>

int main(void)
{
  long long numero_cartao, cartao_atual, divisor = 10;
  int soma1 = 0, soma2 = 0, soma_total = 0, contador = 0;

  do
    {
      printf("\n Digite o número do cartão de credito (sem espaços): \n");
      scanf("%lld", &numero_cartao);
    } 
  while (numero_cartao <=0);

  //1º passo -----
  
  cartao_atual = numero_cartao;
  while (cartao_atual > 0)
  {
    int ultimo_digito = cartao_atual % 10;
    soma1 = soma1 + ultimo_digito;
    cartao_atual = cartao_atual / 100;
  }

  // 2º passo -----

  cartao_atual = numero_cartao / 10;
  while (cartao_atual > 0)
    {
      int ultimo_digito = cartao_atual % 10;
      int multiplicacao = ultimo_digito * 2;
      soma2 = soma2 + (multiplicacao % 10) + (multiplicacao / 10);
      cartao_atual = cartao_atual / 100;
    }

  //3º passo -----
  
  soma_total = soma1 + soma2;

  cartao_atual = numero_cartao;
  while (cartao_atual != 0)
    {
      cartao_atual = cartao_atual / 10;
      contador++;
    }

  for (int i = 0; i < contador - 2; i++)
    {
      divisor = divisor * 10;
    }

  int primeiro_digito = numero_cartao / divisor;
  int dois_primeiros = numero_cartao / (divisor / 10);

  if (soma_total % 10 == 0)
  {
    if (primeiro_digito == 4 && (contador == 13 || contador == 16))
    {
      printf("\n VISA \n");
    }
    else if ((dois_primeiros == 34 || dois_primeiros == 37) && contador == 15)
    {
      printf("\n AMEX \n");
    }
    else if ((dois_primeiros > 50 && dois_primeiros < 56) && contador == 16)
    {
      printf ("\n MASTERCARD \n");
    }
    else{
      printf("\n CARTÃO INVÁLIDO \n");
    }
  }
   else{
      printf("\n CARTÃO INVÁLIDO \n");
    }
}
