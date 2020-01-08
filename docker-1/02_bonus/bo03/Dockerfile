FROM debian

RUN apt-get update && apt-get install -y cowsay fortune lolcat

ENTRYPOINT /usr/games/fortune | /usr/games/cowsay | /usr/games/lolcat

# fortune: a program that displays message from a database of quotations that first appeared in Version 7 unix.
# cowsay: a program that generates ASCII pictures of a cow with a message.
# lolcat: produce rainbow of colors in terminal.

#docker build -t bo03 .
#docker run --rm -t bo03

