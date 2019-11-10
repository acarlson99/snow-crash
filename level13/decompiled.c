#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char *ft_des(char *s)
{
	unsigned int v2; // [esp+2Ch] [ebp-1Ch]
	int v3;			 // [esp+30h] [ebp-18h]
	signed int i;	 // [esp+34h] [ebp-14h]
	signed int j;	 // [esp+38h] [ebp-10h]
	char *v6;		 // [esp+3Ch] [ebp-Ch]

	v6 = strdup(s);
	v3 = 0;
	v2 = 0;
	while (strlen(v6) > v2) {
		if (v3 == 6)
			v3 = 0;
		if (v2 & 1) {
			/* for (i = 0; *(char *)(v3 + 134514368) > i; ++i) { */
			for (i = 0; i < "0123456"[v3]; ++i) {
				if (++v6[v2] == 127)
					v6[v2] = 32;
			}
		} else if (!(v2 & 1)) {
			/* for (j = 0; *(char *)(v3 + 134514368) > j; ++j) { */
			for (j = 0; j < "0123456"[v3]; ++j) {
				if (--v6[v2] == 31)
					v6[v2] = 126;
			}
		}
		++v2;
		++v3;
	}
	return v6;
}

int main(int argc, const char **argv, const char **envp)
{
	__uid_t v3; // eax
	char *v4;	// eax

	if (getuid() != 4242) {
		v3 = getuid();
		printf("UID %d started us but we we expect %d\n", v3, 4242);
		/* exit(1); */
	}
	v4 = ft_des("boe]!ai0FB@.:|L6l@A?>qJ}I");
	return printf("your token is %s\n", v4);
}
