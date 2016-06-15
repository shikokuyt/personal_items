# 燕山争霸

``` js
1. git clone git@github.com:shikokuyt/personal_items.git && cd personal_items
2. cd yszb
3. npm install
4. gulp
```

## 配置
```
|--- css
	|--- dist
	|--- sass
		|--- base.scss  		# 基础公用部分
		|--- not_buy.scss 		# 未购买游戏部分
		|--- gut.scss 			# 剧情介绍部分
		|--- ysjx		  		# 燕山脚下
			|--- ysjx.scss
			|--- ysjx_1.scss
		|--- txch.scss 			# 填写称呼
		|--- wmyx.scss 			# 无名游侠
		|--- swdh				# 师我对话
			|--- swdh1.scss
			|--- swdh2.scss
			|--- swdh3.scss
			|--- swdh4.scss
		|--- sflx.scss 			# 师傅练习
		|--- cthg.scss 			# 错题回顾
		|--- tz_base.scss 		# 挑战页面共用部分
		|--- tz_success.scss    # 挑战成功
		|--- tz_fail.scss 		# 挑战失败
		|--- bsrm.scss 			# 拜师入门
|--- img
|--- font
|--- js
	|--- cthg.js 				# 错题回顾页面中DOM操作
	|--- sflx.js 				# 师傅练习页面JS效果
	|--- video.js 				# 视频样式修改
	|--- fitRem.js  			# REM适配
|--- not_buy.html  				# 未购买游戏页面
|--- loading.html 				# 加载页面 
|--- gut.html 					# 剧情介绍页面
|--- ysjx						# 燕山脚下
	|--- ysjx.html 				# 师傅说话
	|--- ysjx_1.html 			# 少侠说话
|--- txch.html 					# 填写称呼
|--- wmyx.html 					# 无名游侠
|--- swdh						# 师我对话
	|--- swdh1.html
	|--- swdh2.html
	|--- swdh3.html
	|--- swdh4.html
	|--- swdh5.html
|--- find_sist.html 			# 寻找师姐
|--- sflx.html 					# 师傅练习
|--- cthg.html 					# 错题回顾
|--- tz_success.html 			# 挑战成功
|--- tz_fail.html 				# 挑战失败
|--- bsrm.html  				# 拜师入门
|--- gulpfile.js 				# gulp配置文件
|--- package.json 				# 包配置文件
```

## 进度

完成地差不多.

## Bug
剧情介绍页面中视频标签样式的修改未完成 `2016-6-14`

## 吐槽一下

1. 样式一直需要修改，心好累。 `2016-6-12`
2. 今天还是该改改 `2016-6-13`
3. 改成单页面应用 `2016-6-15`

## 更改
加入模板，把页面组装起来，`SPA`效果

```
|--- img
|--- js
	|--- fitRem.js 				# REM适配
	|--- jquery-3.0.0.min.js  	# jquery文件
|--- css
	|--- dist
	|--- sass
		|--- base.scss 			# 公用样式
		|--- not_buy.scss 		# 未购买样式
		|--- loading.scss 		# 加载样式
		|--- gut.scss 			# 剧情介绍样式
		|--- entrance.scss 		# 师门入门样式
		|--- challenge.scss 	# 挑战样式
		|--- allow.html 		# 加入师门样式
|--- not_buy.html 				# 未购买页面
|--- loading.html 				# 加载
|--- gut.html 					# 剧情介绍
|--- entrance.html 				# 师门入门
|--- challenge.html 			# 挑战
|--- allow.html 				# 成功加入师门
|--- gulpfile.js 				# gulp配置文件
|--- package.json 				# 包配置文件
```




