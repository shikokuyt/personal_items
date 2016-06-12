(function () {
	var 
	$ = function (selector) {
		return document.querySelector(selector);
	},
	$$ = function (selectors) {
		return document.querySelectorAll(selectors);
	},

	$back = $('.back'),       // 上一题
	$next = $('.next'), 	  // 切换题目
	$lists = $('.list-page'), // 列表

	$page = $('#page'), 	  // 第几页
	$pages = $('#pages'),     // 页数

	page = parseInt($page.innerHTML),
	pages = parseInt($pages.innerHTML);

	$lists.style.width = pages * 100 + '%';

	/*
	 * 切换题目
	 * @param { Object } 列表对象
	 * @param { number } 第几页
	 * @param { number } 总页数
	 */

	function change(lists) {	
		// 需要判断此道题目是否已选
		var inps = null;
		inps = lists.children[page-1].getElementsByTagName('input');
		if (each(inps)) {
			page ++;
			render(lists);
		} else {
			alert('本道题您并没有完成!')
			inps = null;
		}
	}

	/*
	 * 渲染题目
	 */
	function render(lists) {
		$page.innerHTML = page;
		lists.style.transform = "translateX("+(page-1)*(-100/pages)+"%)";
	}

	/*
	 * 遍历函数
	 * @param { elems }
	 * @return { Boolean }
	 */
	function each(elems) {
		var i, len = elems.length;
		for (i=0; i<len; i++) {
			if (elems[i].checked) {
				return true
			}
		}
		return false;
	}

	$next.addEventListener('click', function () {
		if (page >= pages) {
			return;

			/*
			 * 当代码运行到此处表明题目解答完毕
			 */
		}
		change($lists);
	}, false);
	$back.addEventListener('click', function () {
		if (page === 1) 
			return;
		page --;
		render($lists);
	}, false);
})();