module.exports = function(grunt) {
    grunt.loadNpmTasks('grunt-exec');

    // Project configuration.
    grunt.initConfig({
        pkg: grunt.file.readJSON('package.json'),
        uglify: {
            options: {
                banner: '/*! <%= pkg.name %> <%= grunt.template.today("yyyy-mm-dd") %> */\n'
            },
            build: {
                src: 'src/<%= pkg.name %>.js',
                dest: 'build/<%= pkg.name %>.min.js'
            }
        },
        exec: {
            emcc: 'emcc -s EXPORTED_FUNCTIONS="[\'_factor\']" ./cpp/factor.cpp -o ./public/js/dist/factor.js'
        }
    });



    // Default task(s).
    grunt.registerTask('default', ['exec:emcc']);

};