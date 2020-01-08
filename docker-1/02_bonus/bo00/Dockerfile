#
A developing environment to code in nodejs, but using yarn rather than npm.

FROM ubuntu

RUN apt-get update && \
	apt-get upgrade -y && \
	apt-get install -y nodejs npm yarn git vim

RUN npm install yarn --global && npm install npm --global

#docker build -t bo00 .
#docker run --rm -it bo00
