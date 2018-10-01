#include "ft_ssl.h"

void			check_input_errors(int ac, char **av)
{
	if (ac == 1)
	{
		ft_printf("%s\n", "usage: ft_ssl command [command opts] [command args]");
	}
	else if (ft_strcmp(av[1], "sha256") != 0 && ft_strcmp(av[1], "md5") != 0)
	{
		ft_printf("ft_ssl: Error: '%s' is an invalid command.\n\n", av[1]);
		ft_printf("Standard commands:\n\n");
		ft_printf("Message Digest commands:\n");
		ft_printf("md5\nsha256\n");
		ft_printf("\nCipher commands:\n");
	}
}

int				main(int argc, char **argv)
{
	check_input_errors(argc, argv);

}