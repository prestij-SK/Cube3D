#include "../header/the_game.h"
#include "../header/parsing.h"

int	ft_isdigit(int c)
{
    return (c >= 48 && c <= 57);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
    size_t	i;
    size_t	j;

    i = 0;
    j = 0;
    while (src[j])
        j++;
    if (dstsize != 0)
    {
        while (src[i] && (i < (dstsize - 1)))
        {
            dst[i] = src[i];
            i++;
        }
        dst[i] = '\0';
    }
    return (j);
}

void	ft_putchar_fd(char c, int fd)
{
    write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
    char	c;

    if (n == -2147483648)
    {
        write(fd, "-2147483648", 11);
        return ;
    }
    else if (n < 0)
    {
        write(fd, "-", 1);
        ft_putnbr_fd(-n, fd);
    }
    else if (n > 9)
    {
        ft_putnbr_fd(n / 10, fd);
        ft_putnbr_fd(n % 10, fd);
    }
    else
    {
        c = n + '0';
        write(fd, &c, 1);
    }
}

void	ft_putstr_fd(char *s, int fd)
{
    int	i;

    i = 0;
    if (!s)
        return ;
    while (s[i])
    {
        ft_putchar_fd(s[i], fd);
        i++;
    }
}

void	ft_putendl_fd(char *s, int fd)
{
    int	i;

    i = 0;
    if (!s)
        return ;
    while (s[i])
    {
        ft_putchar_fd(s[i], fd);
        i++;
    }
    ft_putchar_fd('\n', fd);
}
