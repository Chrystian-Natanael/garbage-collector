# `Garbage Collector in C` 🚮

[<img src="https://raw.githubusercontent.com/Chrystian-Natanael/Aleatorios/master/Mycovers/garbage_capa.jpg" alt="Garb_banner" width="1000">](https://github.com/Chrystian-Natanael/Aleatorios/blob/master/Mycovers/garbage_capa.jpg)

### `Select a language:`

<p align="center">
  <a href="https://github.com/Chrystian-Natanael/garbage-collector/blob/main/README_BR.md">
  <img src="https://github.com/Chrystian-Natanael/Aleatorios/raw/master/Flags/Round_Brazil_Flag.png" alt="Portuguese" width="50">
  </a>
  &nbsp &nbsp &nbsp &nbsp
  <a href="https://github.com/Chrystian-Natanael/garbage-collector">
  <img src="https://github.com/Chrystian-Natanael/Aleatorios/raw/master/Flags/Round_EUA_Flag.png" alt="English" width="50">
  </a>
</p>

<h3> 🦮 Summary: 🦮 <br>
<br>
<a href="https://github.com/Chrystian-Natanael/garbage-collector?tab=readme-ov-file#about-the-project" style="color: inherit; text-decoration: none;">🔗 About the project</a> <br> <br>
<a href="https://github.com/Chrystian-Natanael/garbage-collector?tab=readme-ov-file#how-does-it-work" style="color: inherit; text-decoration: none;">🔗 How does it work?</a> <br> <br>
<a href="https://github.com/Chrystian-Natanael/garbage-collector?tab=readme-ov-file#how-to-use" style="color: inherit; text-decoration: none;">🔗 How to use </a>
<br>
</h3>

# Warnings:

• This project was designed for `Linux` environments and may `not` work correctly on other operating systems.

• This project was made for `educational` purposes and `should not` be used in production.

• The project `may` contain `bugs` and `security vulnerabilities`, so use it at `your` own risk.

• The project is `open source`, so feel free to fork it and `contribute` to the project.

# About the project

• The `Garbage Collector` is a project aimed at creating a garbage collector in C. The garbage collector is a `memory management` system that is responsible for freeing up memory that was allocated during the program's execution. The garbage collector is an essential part of any modern programming language as it helps `prevent memory leaks` and memory corruption.
<br><br>

• But, as we know, in `C` there is `no` `built-in` garbage collector, so in this project, we are going to create a `SIMPLE` garbage collector that can be used in C programs.

## 💡 `Logic` of the garbage collector:

To create this `mini` garbage collector, we'll use a concept I learned while working on my [`minishell`](https://github.com/Chrystian-Natanael/minishell): the `binary tree`.

If you're not familiar with the concept of trees, I recommend some videos that helped me understand it better in my [`minishell`](https://github.com/Chrystian-Natanael/minishell) repository. A useful and not too long video that can illustrate what happens in the project is from the `Bro Code` channel: [Learn Tree traversal in 3 minutes 🧗](https://www.youtube.com/watch?v=b_NjndniOqY).

Another `quick summary` of what a `binary tree` is:

• A binary tree is a `data structure` consisting of a `root node` and `two child nodes`, a left node and a right node. Each node can have up to two children, and each node can be a tree by itself.

• The binary tree is a very `powerful` and `versatile` data structure that can be used to solve a wide variety of `computational problems`.

• The binary tree is a data structure that is very `efficient` and `fast`, which can be used to store and retrieve data efficiently.

With this, we will create a tree that will store the `memory addresses` allocated during the program. At the end of the program, we will `free` all allocated memory addresses by traversing the binary tree.

# How does it work

### First, we need to understand the functions that this "library" has:

• `allocate()`: This function is responsible for `allocating` memory for a new memory block. The function returns a pointer to the allocated memory block. It is equivalent to the `malloc()` function from the `stdlib.h` library.

• `deallocate()`: This function is responsible for `freeing` the allocated memory for a memory block. The function takes a pointer to the allocated memory block and releases the allocated memory. It is equivalent to the `free()` function from the `stdlib.h` library.

• `quit()`: This function is responsible for freeing all allocated memory during the program execution. The function traverses the binary tree and frees all allocated memory blocks. It is equivalent to the `exit()` function from the `stdlib.h` library.

• `insert()`: This function is responsible for `inserting` a memory block into the binary tree. The function takes a pointer to the allocated memory block and inserts it into the binary tree.

###  Now let's take it step by step.:

```void	*allocate(unsigned int size)``` :

• The function `allocate()` will replace the use of the `malloc()` function from the `stdlib.h` library. The `allocate()` function takes an argument `size` which is the size of the memory block to be allocated. It allocates a new memory block of the specified size and returns a pointer to the allocated memory block. Additionally, it adds the allocated memory block to the binary tree.

```void	deallocate(void *address)``` :

• The function `deallocate()` will replace the use of the `free()` function from the `stdlib.h` library. The `deallocate()` function takes an argument `address` which is a pointer to the allocated memory block. The `deallocate()` function frees the allocated memory block and `removes` it from the binary tree.

```void	quit(int code)``` :

• The function `quit()` will replace the use of the `exit()` function from the `stdlib.h` library. The `quit()` function `traverses` the binary tree and frees `all` allocated memory blocks during the program execution, and `returns` the specified exit code.

```void	insert(void *address)``` :

• The `insert()` function is responsible for `inserting` a memory block into the binary tree. The `insert()` function takes an argument `address`, which is a pointer to the allocated memory block. It inserts the memory block into the binary tree.

Examples of use:

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
  insert(join); // To add the memory allocated by 'join' to the binary tree
  quit(0);
  return (0);
}
```
<br>

# How to use

### If you are a `cadet at 42`, I recommend that you take some time to try to do the project `on your own`, as it's a great way to learn and practice your `programming skills`.

### But if you're having `difficulties` or want to see how I did the project, you can clone the repository and compile the project using the `make` command.:

```shell
git clone git@github.com:Chrystian-Natanael/garbage-collector.git garbage_collector
```

```shell
cd garbage_collector
```

```shell
make
```

After compiling the project, you can use the library in your C programs by including the file `garbage_collector.h` and the static library `garbage_collector.a`.:

# REMEMBER:

• The project contains the `42` header, so if you are a cadet at `42`, you `MUST` replace the header to avoid being classified as `cheating`.