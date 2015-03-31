功能

  * 全屏显示单一图片
  * ZoomOut ,ZoomIn ，拖动
  * 单屏显示多个图片缩略图
  * 多个图片切换
  * SlideShow


对外接口

  * 调用者通过Intent传入要显示的文件夹路径
  * 调单件FileManager得到要显示图片的Bitmap数据


设计

  * 采用MyGallery(派生自Gallery)做主要控件，实现多个图片之间的切换
  * 采用MainGalleryAdapter（派生自BaseAdapter)为MyGallery提供显示的ImageView
  * 采用ImageView显示图片，实现ZoomOut,zoomin ,拖动功能
  * 缩略图采用Gallery
  * SlideShow 采用Handler类，以发消息延迟控制时间间隔



类图

类说明

关健代码




