# `Coletor de lixo em C: Garbage Collector` 🚮

[<img src="https://raw.githubusercontent.com/Chrystian-Natanael/Aleatorios/master/Mycovers/garbage_capa.jpg" alt="Garb_banner" width="1000">](https://github.com/Chrystian-Natanael/Aleatorios/blob/master/Mycovers/garbage_capa.jpg)

### `Selecione a linguagem:`

<p align="center">
  <a href="https://github.com/Chrystian-Natanael/garbage-collector/blob/main/README_BR.md">
  <img src="https://github.com/Chrystian-Natanael/Aleatorios/raw/master/Flags/Round_Brazil_Flag.png" alt="Portuguese" width="50">
  </a>
  &nbsp &nbsp &nbsp &nbsp
  <a href="https://github.com/Chrystian-Natanael/garbage-collector">
  <img src="https://github.com/Chrystian-Natanael/Aleatorios/raw/master/Flags/Round_EUA_Flag.png" alt="English" width="50">
  </a>
</p>

<h3> 🦮 Sumário: 🦮 <br>
<br>
<a href="https://github.com/Chrystian-Natanael/garbage-collector/blob/main/README_BR.md#mandat%C3%B3rio-parte-1" style="color: inherit; text-decoration: none;">🔗 Sobre o projeto</a> <br> <br>
<a href="https://github.com/Chrystian-Natanael/garbage-collector/blob/main/README_BR.md#mandat%C3%B3rio-parte-2" style="color: inherit; text-decoration: none;">🔗 Como ele funciona</a> <br> <br>
<a href="https://github.com/Chrystian-Natanael/garbage-collector/blob/main/README_BR.md#-parte-b%C3%B4nus" style="color: inherit; text-decoration: none;">🔗 Como usar </a>
<br>
</h3>

# Avisos:

• Este projeto foi para ambientes `Linux` e pode `não` funcionar corretamente em outros sistemas operacionais.

• Este projeto foi feito para fins `educacionais` e `não` deve ser usado em produção.

• O projeto `pode` conter `bugs` e `falhas de segurança`, então use por `sua` conta e risco.

• O projeto é de `código aberto`, então sinta-se à vontade para fazer um fork e `contribuir` com o projeto.

# Sobre o projeto

• O `Garbage Collector` é um projeto que visa a criação de um coletor de lixo em C. O coletor de lixo é um sistema de `gerenciamento de memória` que é responsável por liberar a memória que foi alocada durante a execução do programa. O coletor de lixo é uma parte essencial de qualquer linguagem de programação moderna, pois ajuda a `evitar vazamentos de memória` e corrupção de memória.
<br><br>

• Mas, como sabemos. Em `C` `não` temos um coletor de lixo `embutido`, então, neste projeto, vamos criar um coletor de lixo `SIMPLES` que pode ser usado em programas C.

## 💡 `Lógica` do coletor:

Para fazermos esse `mini` coletor de lixo, vamos utilizar um conceito que aprendi enquanto fazia o meu `minishell`, a `árvore binária`.

Caso não conheca o conceito de árvores, eu recomendo alguns vídeos que me ajudaram a entender melhor o conceito no meu repositório do `minishell`, mas um que não é tão longo e pode ilustrar o que acontece no projeto é este do canal `Bro Code`: [Learn Tree traversal in 3 minutes 🧗](https://www.youtube.com/watch?v=b_NjndniOqY).

Mas um `resumo rápido` do que é uma `árvore binária`:

• Uma árvore binária é uma `estrutura de dados` que consiste em um nó `raiz` e `dois nós filhos`, um nó esquerdo e um nó direito. Cada nó pode ter até dois filhos, e cada nó pode ser uma árvore por si só.

• A árvore binária é uma estrutura de dados muito `poderosa` e `versátil` que pode ser usada para resolver uma ampla variedade de `problemas de computação`.

• A árvore binária é uma estrutura de dados muito `eficiente` e `rápida` que pode ser usada para armazenar e recuperar dados de forma eficiente.

Com isso, vamos criar uma árvore que vai armazenar os `endereços` de memória alocados durante o programa. E ao final do programa, vamos `liberar` todos os endereços de memória alocados percorrendo a árvore binária.

# Como ele funciona

### Primeiro, precisamos entender as funções que essa "biblioteca" possui:

• `allocate()`: Esta função é responsável por `alocar` a memória para um novo bloco de memória. A função retorna um ponteiro para o bloco de memória alocado. Ela é equivalente à função `malloc()` da biblioteca `stdlib.h`.

• `deallocate()`: Esta função é responsável por `liberar` a memória alocada para um bloco de memória. A função recebe um ponteiro para o bloco de memória alocado e libera a memória alocada. Ela é equivalente à função `free()` da biblioteca `stdlib.h`.

• `quit()`: Esta função é responsável por liberar toda a memória alocada durante a execução do programa. A função percorre a árvore binária e libera todos os blocos de memória alocados. Ela é equivalente à função `exit()` da biblioteca `stdlib.h`.

• `insert()`: Esta função é responsável por `inserir` um bloco de memória na árvore binária. A função recebe um ponteiro para o bloco de memória alocado e insere o bloco de memória na árvore binária.

###  Agora vamos por partes:

```void	*allocate(unsigned int size)``` :

• A função `allocate()` vai substituir o uso da função `malloc()` da biblioteca `stdlib.h`. A função allocate() recebe um argumento `size` que é o tamanho do bloco de memória a ser alocado. A função allocate() aloca um novo bloco de memória do tamanho especificado e retorna um ponteiro para o bloco de memória alocado. `Além disso`, ela adiciona o bloco de memória alocado na `árvore binária`.

```void	deallocate(void *address)``` :

• A função `deallocate()` vai substituir o uso da função `free()` da biblioteca `stdlib.h`. A função deallocate() recebe um argumento `address` que é um ponteiro para o bloco de memória alocado. A função deallocate() libera o bloco de memória alocado e o `remove` da árvore binária.

```void	quit(int code)``` :

• A função `quit()` vai substituir o uso da função exit() da biblioteca `stdlib.h`. A função quit() `percorre` a árvore binária e libera `todos` os blocos de memória alocados durante a execução do programa e `retorna` o código de saída especificado.

```void	insert(void *address)``` :

• A função `insert()` é responsável por `inserir` um bloco de memória na árvore binária. A função insert() recebe um argumento `address` que é um ponteiro para o bloco de memória alocado. A função insert() insere o bloco de memória na árvore binária.

exemplos de uso:

```c
#include "garbage_collector.h"
#include <stdio.h>

int	main(void)
{
  char	*str;

  str = allocate(14 * sizeof(char));
  str = "Hello, World!";
  printf("%s\n", str);
  quit(0);
  return (0);
}
```
<br>

```c
#include "garbage_collector.h"
#include <stdio.h>

int	main(void)
{
  char	*str;

  str = allocate(14 * sizeof(char));
  str = "Hello, World!";
  printf("%s\n", str);
  deallocate(str);
  str = allocate(13 * sizeof(char));
  str = "Hola, Mundo!";
  quit(0);
  return (0);
}
```
<br>

```c
#include "garbage_collector.h"
#include <stdio.h>
#include <string.h>

int	main(void)
{
  char	*str1;
  char	*str2;
  char	*join;

  str1 = allocate(14 * sizeof(char));
  str = "Hello, World!";
  str2 = allocate(13 * sizeof(char));
  str = "Hola, Mundo!";
  join = strjoin(str1, str2);
  insert(join); // Para adicionar a memória alocada pelo join na árvore binária
  quit(0);
  return (0);
}
```
<br>

# Como usar

### Se você for um `cadete da 42`, eu recomendo que você tire um tempo para tentar fazer o projeto `por conta própria`, pois é uma ótima maneira de aprender e praticar suas `habilidades de programação`.

### Mas se você estiver com `dificuldades` ou quiser ver como eu fiz o projeto, você pode clonar o repositório e compilar o projeto com o comando `make`:

```shell
git clone git@github.com:Chrystian-Natanael/garbage-collector.git garbage_collector
```

```shell
cd garbage_collector
```

```shell
make
```

Após compilar o projeto, você pode usar a biblioteca em seus programas C incluindo o arquivo `garbage_collector.h` e a biblioteca estática `garbage_collector.a`:

# LEMBRE-SE:

• O projeto contém o `MEU` header da `42`, então, se você for um cadete da `42`, você pode DEVE trocar o header para não se caracterizar `cheat`.