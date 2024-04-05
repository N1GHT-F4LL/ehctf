# php base image

## Usage

Start nginx and php, `init.sh` usage example:

```bash
#!/bin/sh
echo $GZCTF_FLAG > /flag
chmod 444 /flag
unset GZCTF_FLAG

php-fpm -D
nginx -g 'daemon off;'
```