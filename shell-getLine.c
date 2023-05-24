#include "shell.h"

/**
 * input_buf - commands chained buffers
 * @info: struct parameters
 * @buf: a buffer's address
 * @len: var len's address
 *
 * Return: data read
 */
 
ssize_t input_buf(info_t *info, char **buf, size_t *len)
{
	ssize_t r = 0;
	size_t len_p = 0;

	if (!*len) /* If there is nothing left in the buffer, fill it. */
	{
		/*bfree((void **)info->cmd_buf);*/
		free(*buf);
		*buf = NULL;
		signal(SIGINT, sigintHandler);
#if USE_GETLINE
		r = getline(buf, &len_p, stdin);
#else
		r = _getline(info, buf, &len_p);
#endif
		if (r > 0)
		{
			if ((*buf)[r - 1] == '\n')
			{
				(*buf)[r - 1] = '\0'; /* delete the last newline */
				r--;
			}
			info->linecount_flag = 1;
			remove_comments(*buf);
			build_history_list(info, *buf, info->histcount++);
			/* if (_strchr(*buf, ';')) Is this a command sequence? */
			{
				*len = r;
				info->cmd_buf = buf;
			}
		}
	}
	return (r);
}

/**
 * get_input - receives a line without the newline
 * @info: parameter struct
 *
 * Return: data read
 */
 
ssize_t get_input(info_t *info)
{
	static char *buf; /* the command chain buffer ';' */
	static size_t i, f, len;
	ssize_t r = 0;
	char **buf_p = &(info->arg), *p;

	_putchar(BUF_FLUSH);
	r = input_buf(info, &buf, &len);
	if (r == -1) /* EOF */
		return (-1);
	if (len) /* We still have commands in the chain buffer */
	{
		f = i; /* start a new iterator with the current buf position */
		p = buf + i; /* get a return pointer */

		check_chain(info, buf, &f, i, len);
		while (f < len) /* iterate to the semicolon or stop */
		{
			if (is_chain(info, buf, &f))
				break;
			f++;
		}

		i = f + 1; /* increment past nulled ';'' */
		if (i >= len) /* reached end of buffer? */
		{
			i = len = 0; /* reset position and length */
			info->cmd_buf_type = CMD_NORM;
		}

		*buf_p = p; /* return the reference to the current command position */
		return (_strlen(p)); /* return the current command's length */
	}

	*buf_p = buf; /* If there is no chain, return the buffer from _getline.() */
	return (r); /* return the buffer length from _getline() */
}

/**
 * read_buf - reads from a buffer
 * @info: struct parameters
 * @buf: buffer
 * @i: size
 *
 * Return: r
 */
 
ssize_t read_buf(info_t *info, char *buf, size_t *i)
{
	ssize_t r = 0;

	if (*i)
		return (0);
	r = read(info->readfd, buf, READ_BUF_SIZE);
	if (r >= 0)
		*i = r;
	return (r);
}

/**
 * _getline - STDIN's next line of input is retrieved.
 * @info: struct parameters
 * @ptr: address of buffer pointer, preallocated or NULL
 * @length: if not NULL, the size of the preallocated ptr buffer
 *
 * Return: s
 */
 
int _getline(info_t *info, char **ptr, size_t *length)
{
	static char buf[READ_BUF_SIZE];
	static size_t i, len;
	size_t t;
	ssize_t r = 0, s = 0;
	char *p = NULL, *new_p = NULL, *c;

	p = *ptr;
	if (p && length)
		s = *length;
	if (i == len)
		i = len = 0;

	r = read_buf(info, buf, &len);
	if (r == -1 || (r == 0 && len == 0))
		return (-1);

	c = _strchr(buf + i, '\n');
	t = c ? 1 + (unsigned int)(c - buf) : len;
	new_p = _realloc(p, s, s ? s + t : t + 1);
	if (!new_p) /* MALLOC FAILURE! */
		return (p ? free(p), -1 : -1);

	if (s)
		_strncat(new_p, buf + i, t - i);
	else
		_strncpy(new_p, buf + i, t - i + 1);

	s += t - i;
	i = t;
	p = new_p;

	if (length)
		*length = s;
	*ptr = p;
	return (s);
}

/**
 * sigintHandler - ctrl-C obstructs
 * @sig_num: the signal code
 *
 * Return: void
 */
 
void sigintHandler(__attribute__((unused))int sig_num)
{
	_puts("\n");
	_puts("$ ");
	_putchar(BUF_FLUSH);
}
