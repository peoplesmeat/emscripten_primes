var nunjucks = require('nunjucks');
var express = require('express');
var app = express();

nunjucks.configure('views', {
    autoescape: true,
    noCache: true,
    express: app
});


app.use(express.static('public'));

app.get('/', function(req, res) {
    res.render('index.html');
});


app.listen(3000, "0.0.0.0", function () {
    console.log('Example app listening on port 3000!');
});
