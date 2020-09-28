chmod +w jbl/*
cp -a -f $libs/jbl .
chmod -w jbl/*
chmod +w jbl/jbl*config.h
cat examples/makefile jbl/makefile jml/makefile > makefile
cp -a -f jml $libs