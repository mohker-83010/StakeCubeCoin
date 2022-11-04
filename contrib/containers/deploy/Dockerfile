FROM phusion/baseimage:bionic-1.0.0
LABEL maintainer="Dash Developers <dev@scc.org>"
LABEL description="Dockerised SCC Core, built from Travis"

ARG USER_ID
ARG GROUP_ID

ENV HOME /scc

# add user with specified (or default) user/group ids
ENV USER_ID ${USER_ID:-1000}
ENV GROUP_ID ${GROUP_ID:-1000}
RUN groupadd -g ${GROUP_ID} scc
RUN useradd -u ${USER_ID} -g scc -s /bin/bash -m -d /scc scc
RUN mkdir /scc/.stakecubecoin
RUN chown scc:scc -R /scc

COPY bin/* /usr/local/bin/

RUN chmod a+x /usr/local/bin/*

USER scc

VOLUME ["/scc"]

EXPOSE 9998 40000 19998 39995

WORKDIR /scc
