FROM ghcr.io/n1ght-f4ll/ehctf/python:alpine

# Install build dependencies
RUN apk add --no-cache gcc musl-dev

# Install Python packages
RUN pip install --no-cache-dir -i https://pypi.org/simple/ gmpy2 pycryptodome

CMD ["sleep", "infinity"]
