/* This file has been generated by the Hex-Rays decompiler.
   Copyright (c) 2007-2017 Hex-Rays <info@hex-rays.com>

   Detected compiler: GNU C++
*/

#include <defs.h>

//-------------------------------------------------------------------------
// Function declarations

void (*init_proc())(void);
int sub_8048440();
// size_t fwrite(const void *ptr, size_t size, size_t n, FILE *s);
// char *getenv(const char *name);
// int puts(const char *s);
// int __gmon_start__(void); weak
// int open(const char *file, int oflag, ...);
// int putchar(int c);
// int fputc(int c, FILE *stream);
// int ptrace(enum __ptrace_request request, ...);
void _do_global_dtors_aux();
int frame_dummy();
int __cdecl syscall_open(char *filename, int flags); // idb
unsigned int __cdecl syscall_gets(char **a1, int a2, int fd);
char *__cdecl afterSubstr(char **a1, char *a2);
signed int __cdecl isLib(char **a1, char *a2);
int __cdecl main(int argc, const char **argv, const char **envp);
void __cdecl _libc_csu_init(int a1, int a2, int a3);
void (*_do_global_ctors_aux())(void);
void term_proc();

//-------------------------------------------------------------------------
// Data declarations

int _CTOR_LIST__ = 4294967295;	   // weak
int _DTOR_LIST__[] = {4294967295}; // weak
int _DTOR_END__ = 0;			   // weak
int _JCR_LIST__ = 0;			   // weak
int (*dword_8049FFC)(void) = NULL; // weak
char *end_3170 = ".so\n";		   // weak
FILE *stderr;					   // idb
FILE *stdout;					   // idb
char completed_6159;			   // weak
int dtor_idx_6161;				   // weak
// extern _UNKNOWN _gmon_start__; weak

//----- (08048408) --------------------------------------------------------
void (*init_proc())(void)
{
	if (&_gmon_start__)
		__gmon_start__();
	frame_dummy();
	return _do_global_ctors_aux();
}
// 8048490: using guessed type int __gmon_start__(void);

//----- (08048440) --------------------------------------------------------
int sub_8048440() { return dword_8049FFC(); }
// 8049FFC: using guessed type int (*dword_8049FFC)(void);

//----- (080484F0) --------------------------------------------------------
#error "80484F3: positive sp value has been found (funcsize=2)"

//----- (08048520) --------------------------------------------------------
void _do_global_dtors_aux()
{
	int v0;			// eax
	unsigned int i; // ebx

	if (!completed_6159) {
		v0 = dtor_idx_6161;
		for (i = &_DTOR_END__ - _DTOR_LIST__ - 1; dtor_idx_6161 < i;
			 v0 = dtor_idx_6161) {
			dtor_idx_6161 = v0 + 1;
			((void (*)(void))_DTOR_LIST__[v0 + 1])();
		}
		completed_6159 = 1;
	}
}
// 8049F1C: using guessed type int _DTOR_LIST__[];
// 8049F20: using guessed type int _DTOR_END__;
// 804A064: using guessed type char completed_6159;
// 804A068: using guessed type int dtor_idx_6161;

//----- (08048580) --------------------------------------------------------
int frame_dummy()
{
	int result; // eax

	result = _JCR_LIST__;
	if (_JCR_LIST__)
		result = 0;
	return result;
}
// 8049F24: using guessed type int _JCR_LIST__;

//----- (080485A4) --------------------------------------------------------
int __cdecl syscall_open(char *filename, int flags)
{
	return sys_open(filename, flags, 0);
}

//----- (080485D4) --------------------------------------------------------
unsigned int __cdecl syscall_gets(char **a1, int a2, int fd)
{
	unsigned int i; // [esp+8h] [ebp-10h]

	for (i = 0; a2 - 1 > i && sys_read(fd, (char *)a1 + i, 1u) == 1; ++i) {
		if (*((_BYTE *)a1 + i) == '\n') {
			++i;
			break;
		}
	}
	*((_BYTE *)a1 + i) = 0;
	return i;
}

//----- (08048646) --------------------------------------------------------
char *__cdecl afterSubstr(char **a1, char *a2)
{
	char *result;  // eax
	int j;		   // [esp+4h] [ebp-Ch]
	signed int v4; // [esp+8h] [ebp-8h]
	char **i;	   // [esp+Ch] [ebp-4h]

	v4 = 0;
	for (i = a1; *(_BYTE *)i; i = (char **)((char *)i + 1)) {
		v4 = 1;
		for (j = 0; v4 == 1 && a2[j]; ++j) {
			if (a2[j] != *((_BYTE *)i + j))
				v4 = 0;
		}
		if (v4 == 1)
			break;
	}
	if (v4)
		result = (char *)i + j;
	else
		result = 0;
	return result;
}

//----- (080486CB) --------------------------------------------------------
signed int __cdecl isLib(char **a1, char *a2)
{
	int k;		   // [esp+Ch] [ebp-Ch]
	signed int v4; // [esp+10h] [ebp-8h]
	signed int v5; // [esp+10h] [ebp-8h]
	char *v6;	   // [esp+14h] [ebp-4h]
	char *i;	   // [esp+14h] [ebp-4h]
	char *j;	   // [esp+14h] [ebp-4h]

	v6 = afterSubstr(a1, a2);
	if (!v6)
		return 0;
	if (*v6 != '-')
		return 0;
	v4 = 0;
	for (i = v6 + 1; *i > 47 && *i <= '9'; ++i)
		v4 = 1;
	if (!v4 || *i != '.')
		return 0;
	v5 = 0;
	for (j = i + 1; *j > 47 && *j <= '9'; ++j)
		v5 = 1;
	if (!v5)
		return 0;
	for (k = 0; end_3170[k]; ++k) {
		if (end_3170[k] != j[k])
			return 0;
	}
	return 1;
}
// 804A030: using guessed type char *end_3170;

//----- (080487CE) --------------------------------------------------------
int __cdecl main(int argc, const char **argv, const char **envp)
{
	int result;		 // eax
	signed int v4;	 // [esp+20h] [ebp-118h]
	signed int v5;	 // [esp+24h] [ebp-114h]
	int v6;			 // [esp+28h] [ebp-110h]
	char *a1;		 // [esp+2Ch] [ebp-10Ch]
	unsigned int v8; // [esp+12Ch] [ebp-Ch]

	v8 = __readgsdword(0x14u);
	v5 = 0;
	v4 = -1;
	if (ptrace(0, 0, 1, 0) >= 0) {
		if (getenv("LD_PRELOAD")) {
			fwrite("Injection Linked lib detected exit..\n", 1u, 0x25u, stderr);
			result = 1;
		} else if (open("/etc/ld.so.preload", 0) <= 0) {
			v6 = syscall_open("/proc/self/maps", 0);
			if (v6 == -1) {
				fwrite("/proc/self/maps is unaccessible, probably a LD_PRELOAD "
					   "attempt "
					   "exit..\n",
					   1u, 0x46u, stderr);
				result = 1;
			} else {
				while (1) {
					result = syscall_gets(&a1, 256, v6);
					if (!result)
						break;
					if (isLib(&a1, "libc")) {
						v5 = 1;
					} else if (v5) {
						if (isLib(&a1, "ld")) {
							if (argc != 2)
								return fwrite(
									"You need to provied only one arg.\n", 1u,
									0x22u, stderr);
							while (++v4 < strlen(argv[1]))
								putchar(v4 + argv[1][v4]);
							return fputc('\n', stdout);
						}
						if (!afterSubstr(&a1, "00000000 00:00 0"))
							return fwrite("LD_PRELOAD detected through memory "
										  "maps exit ..\n",
										  1u, 0x30u, stderr);
					}
				}
			}
		} else {
			fwrite("Injection Linked lib detected exit..\n", 1u, 0x25u, stderr);
			result = 1;
		}
	} else {
		puts("You should not reverse this");
		result = 1;
	}
	return result;
}

//----- (08048AA0) --------------------------------------------------------
void __cdecl _libc_csu_init(int a1, int a2, int a3) { init_proc(); }

//----- (08048B20) --------------------------------------------------------
void (*_do_global_ctors_aux())(void)
{
	void (*result)(void); // eax
	void (**v1)(void);	  // ebx

	result = (void (*)(void))_CTOR_LIST__;
	if (_CTOR_LIST__ != -1) {
		v1 = (void (**)(void)) & _CTOR_LIST__;
		do {
			--v1;
			result();
			result = *v1;
		} while (*v1 != (void (*)(void)) - 1);
	}
	return result;
}
// 8049F14: using guessed type int _CTOR_LIST__;

//----- (08048B4C) --------------------------------------------------------
void term_proc() { _do_global_dtors_aux(); }

#error "There were 1 decompilation failure(s) on 13 function(s)"
