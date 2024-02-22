FROM nsjailcontainer
RUN apt-get install -y apt-transport-https&&apt-get update && apt-get install -y gcc-multilib

RUN useradd -m magpie
RUN chmod a-w /home/magpie

COPY SpaceEscape.c /home/magpie
RUN gcc -o /home/magpie/chal /home/magpie/SpaceEscape.c
RUN chmod o+x /home/magpie/chal
RUN rm /home/magpie/*.c

EXPOSE 9808

CMD ["/bin/nsjail",                 \
        "-Ml",                      \
        "--hostname", "localhost",  \
        "--port", "9808",           \
        "--user", "1001",           \
        "--group", "1001",          \
        "--chroot", "/",            \
        "-E", "TERM=xterm",         \
        "--cwd", "/home/magpie",    \
        "--",                       \
        "/home/magpie/chal"]



