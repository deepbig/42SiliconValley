# ... and bacon strips ... and bacon strips ...
# Docker can be useful to test an application that's still being developed without polluting your libraries.
# You will have to design a Dockerfile that gets the development version of `Gitlab` installs it with all the dependencies and the necessary configurations,
# and launches the application, all as it builds.
# The container will be deemed valid if you can access the web client, create users and interact via GIT with the container (HTTPS and SSH). Obviously, you are not allowed to use official container from Gitlab, it would be a shame...

FROM ubuntu:16.04

MAINTAINER vbrazhni <vbrazhni@student.unit.ua>

RUN apt-get update && \
    apt-get upgrade -y && \
    apt-get install -y ca-certificates openssh-server wget postfix

RUN wget https://packages.gitlab.com/install/repositories/gitlab/gitlab-ce/script.deb.sh && chmod 777 script.deb.sh && ./script.deb.sh && apt-get install -y gitlab-ce

RUN apt update && apt install -y tzdata && \
  apt-get clean && rm -rf /var/lib/apt/lists/* /tmp/* /var/tmp/*

EXPOSE 443 80 22

ENTRYPOINT (/opt/gitlab/embedded/bin/runsvdir-start &) && gitlab-ctl reconfigure && tail -f /dev/null

# How to build it?
# docker build -t ex03 .

# How to run it?
# docker run -it --rm -p 8080:80 -p 8022:22 -p 8443:443 --privileged ex03
