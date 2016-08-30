/* comandos para imprimir na tela. */

#include <stdio.h>  // inclui o arquivo de cabeçalho


void main (void) { // entry point
    int i=45;
    char c='c';
    char nome[60]="hello";   // em C string é um array de char. O conteúdo para de ser escrito quando o conteúdo do caracter for ZERO.
/* nome é um array de comprimento limitado, mas não há checagem de leitura/escrita para além do limite. */

    putchar (c);    // imprime um caracter na tela

    puts (nome);  // imprime um string na tela, acrescenta um LF \0x0A nos unix-like e CRLF \0x0D \0x0A nos CPM/DOS like.

    printf ("%s, %d\n", nome, i);
/* printf (<format_string>, ...) é o método que imprime na tela. Ele recebe uma string de formato (que pode conter trechos de texto) e depois
uma quantidade variável de argumentos. Em geral cada argumento corresponde a uma variável que deseja-se imprimir. os %s, %d, %f, ... são
especificadores de tipo e de formato. fprintf imprime em um arquivo, sprintf imprime em um string.
    para mais informação use o comando man: man printf
    caso o comando em C que procura tenha um comando de shell de mesmo nome, você receberá a man page do comando do shell. Os comandos de C
estão na seção 3 do manual, então man 3 printf vai mostrar o man do printf para C.
*/

  c=getchar ();   // lê um caracter do teclado.
  gets (&nome);  // lê um string do teclado. A função recebe o ponteiro para o endereço de memória a partir do qual os caracteres serão escritos sequencialmente.
/* O operador que retorna o endereço de uma variável é &.
*/

//Se o que for digitado no teclado passar do comprimento declarado para nome, continua escrevendo. Causa buffer overflow, que é a base de ataques do tipo code injection.
  puts (nome);

}

