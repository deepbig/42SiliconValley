# From an `alpine` image you'll add to your container your favorite text editor, vim or emacs, that will launch along with your container.

# docker build comamnd builds Docker images from a Dockerfile.

FROM alpine

LABEL maintainer="koreanryu96@gmail.com"

RUN apk update && \
	apk upgrade && \
	apk add vim

ENTRYPOINT vim

# docker build -t ex00 .
# docker run --rm -it ex00

# apk is alpine linux package manager.
# update: updates the list of available packages and their versions, but it does not install or upgrade any packages.
# upgrade: actually installs newer versions of the packages you have.
