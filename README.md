To Build 
./node_modules/.bin/grunt

sudo iptables -t nat -A PREROUTING -i eth0 -p tcp --dport 80 -j REDIRECT --to-port 3000

emcc -s EXPORTED_FUNCTIONS="['_factor']" factor.cpp -o ../public/js/factor.js