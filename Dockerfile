FROM ubuntu:22.04

RUN apt-get update && \
    apt-get install -y socat && \
    apt-get clean

RUN useradd -md /home/challenge challenge && \
    echo "challenge:challenge" | chpasswd

WORKDIR /challenge
COPY ./bug .
COPY ./flag.txt .

RUN chmod 755 /challenge
RUN chmod a+x ./bug

USER challenge

CMD socat -T 300 -d -d TCP-LISTEN:2000,reuseaddr,fork EXEC:"./bug",pty,raw,echo=0
    