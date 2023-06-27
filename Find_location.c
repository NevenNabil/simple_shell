#include "AN_shell.h"

/**
 * find_location - get location
 * @cmd: the command that was passed
 * Return: file_path
 */
char *find_location(char *cmd)
{
	char *path, *copyPath, *pathToken, *pathFile;
	int cmd_length, directory_length;
	struct stat buff;

	path = _getenv("PATH");
	if (path)
	{
		copyPath = duplicate_str(path);
		cmd_length = string_length(cmd);
		pathToken = strtok(copyPath, ":");
		while (pathToken != NULL)
		{
			directory_length = string_length(pathToken);
			pathFile = malloc(cmd_length + directory_length + 2);
			copy_str(pathFile, pathToken);
			concat_str(pathFile, "/");
			concat_str(pathFile, cmd);
			concat_str(pathFile, "\0");
			if (stat(pathFile, &buff) == 0)
			{
				free(copyPath);
				return (pathFile);
			}
			else
			{
				free(pathFile);
				pathToken = strtok(NULL, ":");
			}
		}
		free(copyPath);
		if (stat(cmd, &buff) == 0)
			return (NULL);
		return (NULL);
	}
	return (NULL);
}
