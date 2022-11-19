
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

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
			i ++;

	}
	close(fd_to_read);
	return (i);
}

void	count_linesize(char *file_name, int *size_line)
{

	int	i;
	int	j;
	int	f_;
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

int	main()
{
	char	c;
	char	**dictionnaire;
	int	*size_line;
	int	bytes;
	int	fd_to_read;
	int	size_of_file;	
		
		
		

//	int	fd_to_write = open("test.dict", O_WRONLY | O_CREAT, 0777);

/*	if (argc == 1)
	{
	}
	else if (argc == 2)
	{
	}
	else
	{
	}*/
	char	*ligne;
	int	i;
	int x;
	int y;

	i = 0;
	x = 0;
	y = 0;
	size_of_file = count_lines("numbers.dict");

	
	dictionnaire = malloc(sizeof(dictionnaire) * size_of_file);

	ligne = malloc(sizeof(c)*100);
	count_linesize("numbers.dict",*size_line); 

	fd_to_read = open("numbers.dict", O_RDONLY);
	
	while (i< size_of_file)
	{
		dictionnaire[i][0] = malloc(sizeof(int));
		dictonnaire[i][1] = malloc(sizeof(c) * size_line[i]);
		i++;
	}
	
	
	while ((bytes = read(fd_to_read, &c, sizeof(c))) > 0)
	{
		/*if (c == '!')
		{
			c = '!';
		}*/
		//write (fd_to_write, &c, sizeof(c));
		if (c !=  ' ')
		{
			ligne[i] = c;
			i++;
//			print('z');
			y++;
		}
		if (c == ':')
		{
			
		}
		if (c == '\n')
		{	
			ligne[i] = '\0';
			printstr(ligne);
			print('y');

			i=0;
			x++;
			y = 0;
		}
//		print(' ');
	}
	close(fd_to_read);
//	close(fd_to_write);
	return (0);
}
