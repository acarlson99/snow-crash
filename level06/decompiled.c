int main(int argc, char **argv, char **envp)
{
	__gid_t __rgid;
	__uid_t __ruid;
	char *local_34;
	char *local_30;
	char *local_2c;
	char *local_28;
	int local_24;

	local_2c = strdup("");
	local_28 = strdup("");
	if (argv[1] != (char *)0x0) {
		free(local_2c);
		local_2c = strdup(argv[1]);
		if (argv[2] != (char *)0x0) {
			free(local_28);
			local_28 = strdup(argv[2]);
		}
	}

	__rgid = getegid();
	__ruid = geteuid();
	setresgid(__rgid, __rgid, __rgid);
	setresuid(__ruid, __ruid, __ruid);
	local_34 = "/usr/bin/php";
	local_30 = "/home/user/level06/level06.php";
	local_24 = 0;
	execve("/usr/bin/php", &local_34, envp);
	return 0;
}
