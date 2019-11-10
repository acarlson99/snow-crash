
void main(void)
{
    undefined4 uVar1;
    undefined4 uStack28;
    undefined4 uStack24;
    undefined4 uStack20;
    
    uStack24 = sym.imp.getegid();
    uStack20 = sym.imp.geteuid();
    sym.imp.setresgid(uStack24, uStack24, uStack24);
    sym.imp.setresuid(uStack20, uStack20, uStack20);
    uStack28 = 0;
    uVar1 = sym.imp.getenv("LOGNAME");
    sym.imp.asprintf(&uStack28, "/bin/echo %s ", uVar1);
    sym.imp.system(uStack28);
    return;
}
