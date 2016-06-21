var gulp = require('gulp'),
	sass = require('gulp-sass'),
	uglify = require('gulp-uglify'),
	minifyCSS = require('gulp-minify-css'),
	browserSync = require('browser-sync').create(),
	reload = browserSync.reload;

gulp.task('sass-watch', function () {
	return gulp.src('sass/*.scss')
		.pipe(sass()) 
		.pipe(minifyCSS({keepBreaks: false}))
		.pipe(gulp.dest('dist/css'))
		.pipe(reload({stream: true}))
		.on('error', sass.logError);
});
gulp.task('js', function () {
	return gulp.src('js/*.js')
		.pipe(uglify())
		.pipe(gulp.dest('dist/js'))
		.on('error', function () {});
})
gulp.task('js-watch', ['js'], reload);


// 开启一个服务器
gulp.task('serve', function () {
	// 从这个项目的根目录启动服务器
	browserSync.init({
		server: {
			baseDir: './'
		}
	});
	gulp.watch('sass/*.scss', ['sass-watch']);
	gulp.watch('js/*.js', ['js-watch']);
	gulp.watch('./**/*.html').on('change', reload);
});

gulp.task('default', ['serve']);