(function () {
	var $cha = document.querySelectorAll('.check');
	var $gou = document.querySelectorAll('.bingo');

	each($cha, render); // 遍历玩家选择
	each($gou, render); // 遍历正确选择
	function render(ele) {
		var cls = ele.className === 'check'?'cha':'gou';
		var i = document.createElement('i');
		i.className = cls;
		ele.appendChild(i);
		i = null;
		if (cls === 'cha') {
			var div = document.createElement('div');
			div.className = 'circ';
			ele.insertBefore(div, ele.firstChild);
			div = null;
		}
	}
	function each(eles, fn) {
		eles = [].slice.call(eles, 0);
		eles.forEach(function (d) {
			fn && fn(d);
		});
	}
})();