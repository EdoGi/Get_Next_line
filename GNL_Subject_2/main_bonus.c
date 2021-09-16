int main(void)
{
	int		fd[2];
	char	*line;

	line = NULL;
	fd[0] = open("test.txt", O_RDONLY);
	fd[1] = open("test2.txt", O_RDONLY);
	// while (get_next_line(fd, &line))
	// {
	// 	printf(">>> line : |%s| <<<", line);
	// 	free(line);
	// }
	line = get_next_line(fd[0]);
	printf(">>> line : |%s| <<<", line);
	free(line);
	line = get_next_line(fd[1]);
	printf(">>> line : |%s| <<<", line);
	free(line);
	line = get_next_line(fd[0]);
	printf(">>> line : |%s| <<<", line);
	free(line);
	line = get_next_line(fd[1]);
	printf(">>> line : |%s| <<<", line);
	free(line);
	close (fd[0]);
	close (fd[1]);
	return (0);
}