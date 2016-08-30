#include <stdio.h>  // inclui o arquivo de cabeçalho 

void main (void) { // entry point
    printf ("hello\n");
}

/* C é uma linguagem estruturada, procedural e imperativa criada no final da década de 1960 por Kernigham e Ritchie, na época trabalhando para Bell labs.
 * a proposta para a linguagem era criar algo eficiente e mais simples que a linguagem B, que por sua vez era uma simplificação de Algol. 
* Na época ainda era comum computadores executarem um processo por vez (multitarefa é algo da década de 1980).
* a linguagem passou por reestruturações que resultaram na norma ANSI-C e na norma POSIX-C.
* Sistemas operacionais como Linux e Windows (pelo menos o 3.1) são escritos predominantemente em C.
* Muitos SDKs de sistemas embarcados também usam C como linguagem principal (Microchip PIC; ATMel Arduino,...).
* No Linux o compilador é invocado pelo comando gcc.
* o comando "gcc hello1.c" criará um executável linux de nome a.out O nome é o default.
* para mudar o nome use "gcc hello1.c -o hello". O executável terá o nome hello
* para executar o executável use "./hello"


* A linguagem (estruturada) permite criar tipos de dados através dos comandos struct e union.
* alocação de memória é feita por comandos como alloc, malloc, calloc, ... a memória tem que ser explicitamente liberada usando o comando free.
* Em C variáveis podem conter valores ou referências (ponteiros). Ao contrário de Java, variáveis de tipos abstratos são pensadas como contendo os valores. 
* Isso tem efeito por exemplo em arrays de tipos abstratos, em C, os arrays contém os campos do tipo abstrato, em Java arrays de objetos contém as referências para os objetos.
* ponteiros para variáveis são referências para estas. Consegue-se o ponteiro para a variável com o operador & e acessa-se o conteúdo com o operador *.
*

* para manter a eficiência e pela idade da linguagem, tomando Java como referência, não há garbage collection, tratamento de erros e verificação de acesso de memória (objeto gc, errors, exeptions e "null pointer exception", "array index out of bounds", ...)
* a compilação é feita em uma passada sobre o código-fonte. Desta forma, o programador é obrigado a declarar o que for usar, inclusive classes e métodos, ANTES de usá-las.
* Isto cria uma ordem para compilar os arquivos: as classes e métodos ( contidos nos arquivos A, B,...) que o programador for usar em um arquivo-fonte (arquivo X) precisam ser compiladas antes:  É obrigatório compilar A, B, ... antes de compilar X.
* dependendo de como as classes e métodos forem usados (instanciados, invocados) criam-se referências circulares que impossibilitariam a compilação.
* Tal dependência ocorre pela falta das declarações das classes e métodos (fazendo analogia com Java, faltam as interfaces).
* Em C isso se resolve com arquivos de cabeçalho e o pré-processador.
* Arquivos de cabeçalho por convenção tem extensão .h e contém as declarações de classes e métodos (que no vocabulário de C são chamados protótipos).
* O pré-processador C processa texto: ele substitui comando iniciados por # com um texto específico. 
* #include <arq> instrui o pré processador a "copiar o conteúdo de arq nessa posição"
* #define simb val instrui o pré-processador a "substituir as ocorrências de simb por val" (val pode ser outro símbolo) 
* #ifdef simb 
*    código1...
* #elsif ...
*    código2...
* #endif 
* inclui código 1 ou código 2 dependendo se simb foi ou não definido.
* no lugar de "#ifdef simb" pode-se usar "#if cond " onde se cond for diferente de zero então inclui código1, senão, código2.
* Há livros que referem-se a esses comandos como "diretivas de pré-processador", outros como "macros", ou "macros de substituição".
* em geral o símbolo a que se refere uma macro do tipo #define é escrito em letras maiúsculas.

* Orientação a objetos foi acrescentada a C na década de 1990. Muitas das palavras-chave de Java também são usadas em C++ com o mesmo significado, por exemplo class, public, private, protected. 
* C++ tem palavras-chave como friend e const, não tem interface, final, implements.
* Instanciação é feita com a palavra-chave new e destruição com delete. Objetos em C++ permitem construtores e destrutores.
* Saiba mais sobre isso em algum livro sobre C++.
* Para saber a versão do gcc:
* fabio@fabio-PORTEGE-M400:~/c$ gcc --version
* gcc (Ubuntu 5.4.0-6ubuntu1~16.04.1) 5.4.0 20160609
* Copyright (C) 2015 Free Software Foundation, Inc.
* This is free software; see the source for copying conditions.  There is NO
* warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

