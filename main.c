
#include "lib.h"

int	count_table_size(char *file_name)
{
	int	i;
	int	fd_to_read;
	char	c;


	i = 0;
	fd_to_read = open(file_name, O_RDONLY);
        while ((read(fd_to_read, &c, sizeof(c))) > 0)
 	{
		if (c == '\n')
			i++;
	}
	close(fd_to_read);
	return (i);
}

void	count_size_line(char *file_name,int *size_line)
{
	int	i;
	int	j;
	int	fd_to_read;
	char		c;

	i = 0;
	j = 1;
	fd_to_read = open(file_name, O_RDONLY);
	while ((read(fd_to_read, &c, sizeof(c))) > 0)
	{	
		j++;	
		if (c == '\n')
		{
			size_line[i]=j;
			i++;
			j = 1;
		}
	}
	close(fd_to_read);
}

void	write_t_dic(char **dic, char *file_name)
{
	int	i;
	int	j;
	int	fd_to_read;
	char		c;

	i = 0;
	j = 0;
        fd_to_read = open(file_name, O_RDONLY);
        while ((read(fd_to_read, &c,1) ) > 0)
        {
		dic[i][j] = c;
		j++;	
		if (c == '\n')
		{
			dic[i][j] = '\0';
			i++;
			j=0;
		}
	}	
	close(fd_to_read);
}
int	main(void)
{
	char	**dic_tmp;
	dic_t	*dic;
	int	*size_line;
	int	size_of_file;	
	int	i;

	size_of_file = 0;
	size_of_file = count_table_size("numbers.dict");
	size_line = (int*) malloc(size_of_file * sizeof(int));
	count_size_line("numbers.dict", size_line);
	dic = (dic_t*) malloc(size_of_file * sizeof(dic_t));
	dic_tmp = (char**) malloc(size_of_file * sizeof(dic_t));
	i = 0;
	while (i < size_of_file)
	{
		dic_tmp[i] =  (char*) malloc(sizeof(char) * size_line[i]);
		dic[i].traduction =  (char*) malloc(sizeof(char) * size_line[i]);
		i++;
	}
	write_t_dic(dic_tmp,"numbers.dict");
	checkline(dic,size_of_file,dic_tmp);
	i=0;
	free(dic_tmp);
	free(dic);
	free(size_line);
	return (0);
}
