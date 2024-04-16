docker build . -t babycalc
docker run --rm -v .:/src -p 20000:2000 -it babycalc