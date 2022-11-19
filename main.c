
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct dicStructure
{
	int	num;
	char	*traduction;
}		 dic_t;


void	print(char c)
{
	write(1, &c, 1);
}

void	printstr(char *c)
{
	int	i;
	i = 0;
	while (c[i])
	{
		print(c[i]);
		i++;
	}
}

	void 	save_line(char *str, int i)
	{
		char *s;
		int j;

		j = 0;
		s = malloc(sizeof(s)*i);
		while (str[j])
		{
			s[j] = str[j];
			j++;
		}
	}

int	count_lines(char *file_name)
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

void	count_linesize(char *file_name, int *size_line)
{

	int	i;
	int	j;
	int	f_;
	int	fd_to_read;
	char		c;

	i = 0;
	j = 1;
	f_= 0;
        fd_to_read = open(file_name, O_RDONLY);
	while ((read(fd_to_read, &c, sizeof(c))) > 0)
        	{
		if (f_ == 1)
			j++;
        	if (c == '\n' && f_ == 1)
		{       
			size_line[i] = j;
			i++;
			j = 1; 
			f_ = 0;
	        }
		if (c == ':')
			f_ = 1;

	}
        close(fd_to_read);
}

int	main(void)
{
	char	c;
	dic_t	*dic;
	int	*size_line;
	int	bytes;
	int	fd_to_read;
	int	size_of_file;	
		
	char	*ligne;
	int	i;
	int x;
	int y;

	i = 0;
	x = 0;
	y = 0;
	size_of_file = count_lines("numbers.dict");

	size_line = (int*) malloc(size_of_file * sizeof(int));

	count_linesize("numbers.dict",size_line); 

	fd_to_read = open("numbers.dict", O_RDONLY);
	
	dic = (dic_t*) malloc(4 * sizeof(dic_t));
	
	while (i<4)
	{
		dic[i].traduction =  (char*) malloc(sizeof(char) * size_line[i]);
	}

	i =0;	
	while ((bytes = read(fd_to_read, &c, sizeof(c))) > 0)
	{
		if (c !=  ' ')
		{
			i++;
			y++;
		}
		if (c == ':')
		{
			
		}
		if (c == '\n')
		{	
			printstr(ligne);
			i=0;
			x++;
			y = 0;
		}
	}
	close(fd_to_read);
	return (0);
}
