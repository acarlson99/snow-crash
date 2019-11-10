
void main(int32_t arg_8h, int32_t arg_ch, int32_t arg_10h)
{
    int32_t iVar1;
    int32_t iVar2;
    int32_t in_GS_OFFSET;
    undefined auStack1044 [1024];
    int32_t iStack20;
    
    iStack20 = *(int32_t *)(in_GS_OFFSET + 0x14);
    if (arg_8h == 1) {
        sym.imp.printf("%s [file to read]\n", *(undefined4 *)arg_ch);
        sym.imp.exit(1);
    }
    iVar1 = sym.imp.strstr(*(undefined4 *)(arg_ch + 4), "token");
    if (iVar1 != 0) {
        sym.imp.printf("You may not access \'%s\'\n", *(undefined4 *)(arg_ch + 4));
        sym.imp.exit(1);
    }
    iVar1 = sym.imp.open(*(undefined4 *)(arg_ch + 4), 0);
    if (iVar1 == -1) {
        sym.imp.err(1, "Unable to open %s", *(undefined4 *)(arg_ch + 4));
    }
    iVar2 = sym.imp.read(iVar1, auStack1044, 0x400);
    if (iVar2 == -1) {
        sym.imp.err(1, "Unable to read fd %d", iVar1);
    }
    sym.imp.write(1, auStack1044, iVar2);
    if (iStack20 != *(int32_t *)(in_GS_OFFSET + 0x14)) {
        sym.imp.__stack_chk_fail();
    }
    return;
}
