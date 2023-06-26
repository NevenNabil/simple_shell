#include "AN_shell.h"
/** _getenv - function receive environmental variable
* @name: name of variable
*Return:Null
*/
char *_getenv(const char *name) {
    size_t namelen = string_leghth(name);
    char **envp;

    for (envp = environ; *envp != NULL; envp++) {
        if (copy_str(*envp, name, namelen) == 0 && (*envp)[namelen] == '=') {
            return &((*envp)[namelen+1]);
        }
    }

    return NULL;
}

