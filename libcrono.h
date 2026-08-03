
#ifndef LIBCRONO_H
# define LIBCRONO_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>

# define CPY_BUFFER 50

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int		count_split(const char *str, char to_find);
void	free_split(char **ptr);
char	**split(const char *str, char c);
char	*strjoin(char const *s1, char const *s2);
char	*substr(char const *s, unsigned int start, size_t len);
int		splitlen(char **ptr);
off_t	get_file_length(char *file1);
int		copy_file(char *file1, char *file2);
char	*get_file_content(char *file);
char	*get_file_name(char *path);
char	*get_free_split(char **ptr, int indice);
int		ipower(int b, int p);
long	lpower(long b, int p);
void	putnbr_on_str(char *str, int index, unsigned long n);
char	*ltoa(long n);
t_list	*lstnew(void *content);
void	lstadd_back(t_list **lst, t_list *new);
void	lstadd_front(t_list **lst, t_list *new);
void	lstclear(t_list **lst, void (*del)(void *));
void	lstdelone(t_list *lst, void (*del)(void *));
void	lstiter(t_list *lst, void (*f)(void *));
t_list	*lstlast(t_list *lst);
t_list	*lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
int		lstsize(t_list *lst);

#endif
