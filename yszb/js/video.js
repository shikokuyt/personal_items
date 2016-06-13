(function (window) {
	/*
	 * BOM配置
	 */
	var w = window,
		doc = window.document,
		navigator = navigator || w.navigator;
	navigator.getMedia = (
		navigator.getUserMedia || 
		navigator.webkitGetUserMedia || 
		navigator.mozGetUserMedia || 
		navigator.msGetUserMedia
	);

	/*
	 * DOM配置
	 */	
	var video = doc.getElementsByTagName('video')[0];
	var btn = doc.querySelector('.btn');

 	/*
 	 * Video config's property
 	 */ 
 	var total = 0,    // video's total time
 		sound = null, // sound volume
 		undefined;

 	console.log(navigator.getMedia)
 	w.addEventListener('DOMContentLoaded', function () {
 		navigator.getMedia(
		 	{
		 		video: true
		 	},
		 	function (localMediaStream) {
		 		var source = document.querySelector('source');
		 		source.src = "http://112.17.13.233/mp4files/2184000004BE4E3E/vjs.zencdn.net/v/oceans.mp4";
		 		video.onloadedmetadata = function (e) {
		 			// console.log(video.duration)
		 			video.play();
		 		}
		 	},
		 	function (err) {
		 		console.error('The following error occured: '+err);
		 	}
 		)
 	}, false)
 	
	
})(window);