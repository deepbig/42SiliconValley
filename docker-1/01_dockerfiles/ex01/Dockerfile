# From a `debian` image you will add the appropriate sources to create a TeamSpeak server, that will launch along with your container. It will be deemed valid if at least one user can connect to it and engage in a normal discussion (no far-fetched setup), so be sure to create your Dockerfile with the right options. Your program should get the sources when it builds, they cannot be in your repository.

# https://github.com/qdm12/teamspeak-server-alpine
# https://unixblogger.com/setup-a-teamspeak-3-server-on-linux-ubuntu-debian/

FROM debian

LABEL maintainer="koreanryu96@gmail.com"

ENV TS3SERVER_LICENSE=accept

WORKDIR /home/teamspeak

EXPOSE 9987/udp 10011 30033

RUN apt-get update && \
	apt-get upgrade && \
	apt-get install -y wget bzip2 && \
	wget https://files.teamspeak-services.com/releases/server/3.10.2/teamspeak3-server_linux_amd64-3.10.2.tar.bz2 && \
	tar xvf teamspeak3-server_linux_amd64-3.10.2.tar.bz2

WORKDIR teamspeak3-server_linux_amd64

ENTRYPOINT sh ts3server_minimal_runscript.sh

# docker build -t ex01 .
# docker run -p 9987:9987/udp -p 10011:10011 -p 30033:30033 ex01

# docker run --name hryu --rm -i -t ex01 bash
# docker exec -it hryu bash

