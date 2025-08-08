# 📄 get_next_line

> Projeto da 42 São Paulo que implementa uma função em C capaz de **ler uma linha por vez de um arquivo**, com suporte a múltiplos descritores de arquivo, uso eficiente de memória e respeito às normas da escola.

![badge](https://img.shields.io/badge/42%20Project-get__next__line-blue)
![badge](https://img.shields.io/badge/Made%20with-C-00599C?logo=c)
![badge](https://img.shields.io/badge/Linux-Friendly-informational?logo=linux)
![badge](https://img.shields.io/badge/Norminette-OK-green)

---

## ✨ Objetivo

Recriar do zero a função `get_next_line` com as seguintes características:

- Retorna **uma linha completa** por chamada (incluindo o `\n`, se houver).
- Lida com **arquivos, stdin, pipes ou múltiplos descritores abertos ao mesmo tempo**.
- Usa **buffers dinâmicos** e gerenciamento de memória manual.
- Compatível com qualquer valor de `BUFFER_SIZE`.

---

## ⚙️ Protótipo

```c
char *get_next_line(int fd);
```
fd: File descriptor (arquivo, entrada padrão, etc).

Retorna: a próxima **linha** (com `\n` se presente), ou `NULL` ao final do arquivo ou em **erro**.

## 🧠 Conceitos Trabalhados
- 📚 Manipulação de arquivos (read)
- 🧠 Ponteiros, static e persistência entre chamadas
- 🧵 Suporte a múltiplos descritores simultâneos
- 🧼 Alocação e limpeza de memória com malloc e free
- 📦 Criação de bibliotecas com header file
- 🛠️ Uso de funções auxiliares (ft_strlen, ft_strjoin, etc)

## 💻 Exemplo de uso
```c
#include "get_next_line.h"

int main(void)
{
    int     fd;
    char    *line;

    fd = open("arquivo.txt", O_RDONLY);
    line = get_next_line(fd);
    while (line != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

## 📂 Arquivos

| Arquivo                | Função                                                                 |
|------------------------|------------------------------------------------------------------------|
| `get_next_line.c`      | Lógica principal da leitura linha por linha                           |
| `get_next_line_utils.c`| Funções auxiliares (`ft_strlen`, `ft_strchr`, `ft_strjoin`, etc.)     |
| `get_next_line.h`      | Header com protótipos, macros e includes necessários                   |
| `Makefile`             | Facilita a compilação, recompilação e limpeza dos arquivos gerados     |


## 🔧 Como Compilar

### Compilação manual
(definindo o tamanho do buffer):

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 *.c
```
> 💡 Você pode ajustar o valor de BUFFER_SIZE para testar diferentes comportamentos de leitura.

## 🧠 Dicas
Sempre libere a memória retornada por get_next_line após o uso.

Use o BUFFER_SIZE ideal para o seu caso. Valores pequenos testam bem a robustez do código.

## 📌 Observações
- O projeto segue a norma da 42.
- Nenhuma função da `libc` além de `read`, `malloc` e `free` é permitida.
- Não é permitido usar variáveis globais.
- A função deve funcionar com qualquer descritor de arquivo válido, inclusive entrada padrão.

---

### 👩‍💻 Autoria

#### Amy Rodrigues

🎓 Estudante de C e baixo nível na 42 São Paulo

🐧 Usuária de Linux | 💻 Fã de terminal | 🎯 Apaixonada por entender como tudo funciona

### 📎 Licença
Projeto educacional feito como parte do currículo da 42.

Pode ser usado como referência, estudo ou inspiração.

Proibido submeter cópias em processos avaliativos.
