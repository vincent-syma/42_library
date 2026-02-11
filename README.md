*This library has been created as part of the 42 curriculum by ssucha/vincent_syma.*


## Table of Contents
- [Description](#description)
- [Instructions](#instructions)
- [Contents](#contents)
	- [Libft](#libft)
	- [ft_printf](#ft_printf)
	- [get_next_line](#get_next_line)
	- [My own additions](#my-own-additions)

---

## Description

This library is a result of 3 of 42 school projects:
1. `libft`
2. `ft_printf`
3. `get_next_line`

The goal was to recode some of the well known and used public libraries functions as well as some others. More detailed info below and in their own Readme files.

---

## Instructions
The project is compiled by using `Makefile`:

```make
make / make all		# to compile the library
make clean			# to delete the temporary files
make fclean			# to delete the temporary files + the compiled library
make re				# to do make fclean and make all together
```
To use the functions from the library in your own project, add this include in your files:
```c
#include "libft.a"
```
---

## Contents

### Libft
[BONUS VERSION]

My takes on public library functions:

```c
int			ft_isalpha(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);
int			ft_atoi(const char *str);
size_t		ft_strlen(const char *s);
int			ft_toupper(int c);
int			ft_tolower(int c);
void		ft_bzero(void *s, size_t n);
void		*ft_memset(void *s, int c, size_t n);
void		*ft_calloc(size_t nmemb, size_t size);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strnstr(const char *haystack, const char *needle, size_t n);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
char		*ft_strdup(const char *src);
size_t		ft_strlcat(char *dst, const char *src, size_t dsize);
size_t		ft_strlcpy(char *dst, const char *src, size_t dsize);

```
Not library functions:
```c
char		*ft_itoa(int n);
void		ft_putchar_fd(char c, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_putstr_fd(char *s, int fd);
char		**ft_split(char const *s, char c);
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_substr(char const *s, unsigned int start, size_t len);
```
And for the **bonus part**: functions handling linked lists based on this structure:
```c
struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;
```
```c
t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void*));
void		ft_lstclear(t_list **lst, void (*del)(void*));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
```

---

### ft_printf()

[BONUS VERSION]

A recode of classic `printf()` from `stdio.h`.

I chose to battle the infamous **BONUS version** which includes not only handling basic data type conversions:
- `%c` for character
- `%s` for string
- `%p` for pointer
- `%d` for decimal
- `%i` for integer
- `%u` for unsigned integer
- `%x` for hexadecimal in lowercase
- `%X` for hexadecimal in uppercase
- `%%` for % sign

but also:
- `-` flag for left padding
- `0` flag for zero padding
- `.` flag for precision
- `#` flag for hex prefix
- `(space)` flag for space
- `+` flag for explicit +
- field minimum width

It was tough, but I am really proud at myself and I learned so much from that. :)

---

### get_next_line()
[BONUS VERSION]

A function that returns a line read from a file descriptor.

- Repeated calls (e.g., using a loop) to the `get_next_line()` function should let you read the text file pointed to by the file descriptor, **one line at a time**.
- The function should return the line that was read.
If there is nothing left to read or if an error occurs, it should return `NULL`.

#### Tips for using the `get_next_line()` function in your code:
- Feel free to adjust the `BUFFER_SIZE` directly in the `get_next_line.h`. It is better when it is not too small (10 bytes and less) if you plan to read big files or long lines, because the process can be very time consuming with a small buffer.
- The function returns `NULL` when handed `BUFFER_SIZE <= 0` and/or invalid `fd` argument.
- The function can accept `stdin` as input.
- The function can process multiple `fd` in one program simultaneously.
- Each call reads one line, for reading more, call the function repeatedly.
- To avoid undefined behaviour: do not modify the file associated with the file descriptor between calls when the end of file was yet not reached. Also do not put a binary file as an input.

*Note: it is possible to change the separator character from `\n` to something else completely (f. e. `space`). So with a little adjustment of the code the function can be used in other ways.*

---

### My own additions

When doing other projects I recoded and added some other useful functions:

```c
int		ft_abs(int value);
long	ft_atol(const char *str);
int		ft_count_digits(int n);
int		ft_islower(int c);
int		ft_isupper(int c);
int		ft_putchar(char c);
void	ft_putendl(char *s);
int		ft_putnbr(int n);
int		ft_putstr(char *s);
int		ft_sqrt(int nb);
void	ft_strtoupper(char *s);
void	ft_strtolower(char *s);
```