#include "shell.h"

/**
 * is_cmd - detects if a file contains an executable command
 * @info: the data structure
 * @path: the file's path
 *
 * Return: If true, 1; else, 0.
 */
 
int is_cmd(info_t *info, char *path)
{
	struct stat st;

	(void)info;
	if (!path || stat(path, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * dup_chars - character duplication
 * @pathstr: the PATH variable
 * @start: beginning index
 * @stop: halting index
 *
 * Return: new buffer pointer
 */
 
char *dup_chars(char *pathstr, int start, int stop)
{
	static char buf[1024];
	int i = 0, l = 0;

	for (l = 0, i = start; i < stop; i++)
		if (pathstr[i] != ':')
			buf[l++] = pathstr[i];
	buf[l] = 0;
	return (buf);
}

/**
 * find_path - discovers this command in the PATH string
 * @info: the data layout
 * @pathstr: the PATH variable
 * @cmd: the command to locate
 *
 * Return: If found, the complete path to the command or NULL
 */
 
char *find_path(info_t *info, char *pathstr, char *cmd)
{
	int i = 0, curr_pos = 0;
	char *path;

	if (!pathstr)
		return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (is_cmd(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pathstr[i] || pathstr[i] == ':')
		{
			path = dup_chars(pathstr, curr_pos, i);
			if (!*path)
				_strcat(path, cmd);
			else
			{
				_strcat(path, "/");
				_strcat(path, cmd);
			}
			if (is_cmd(info, path))
				return (path);
			if (!pathstr[i])
				break;
			curr_pos = i;
		}
		i++;
	}
	return (NULL);
}
