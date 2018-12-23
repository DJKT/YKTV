// pages/naozhong/naozhong.js
Page({
   /**
   * 页面的初始数据
   */
  data: {},
  /**
   * 生命周期函数--监听页面加载
   */
  onLoad: function (options) { },
   /**
   * 生命周期函数--监听页面初次渲染完成
   */
  onReady: function () {},
  /**
   * 生命周期函数--监听页面显示
   */
  onShow: function () {},
  /**
   * 生命周期函数--监听页面隐藏
   */
  onHide: function () {},
  /**
   * 生命周期函数--监听页面卸载
   */
  onUnload: function () { },
  /**
   * 页面相关事件处理函数--监听用户下拉动作
   */
  onPullDownRefresh: function () {},
  /**
   * 页面上拉触底事件的处理函数
   */
  onReachBottom: function () { },
   /**
   * 用户点击右上角分享
   */
  onShareAppMessage: function () { },
  send1: function () {
    var that = this //创建一个名为that的变量来保存this当前的值  
    wx.request({
      url: 'http://api.heclouds.com/devices/508870000/datapoints?type=3',
      method: 'post',
      data: {
        Humidity: '1'  //这里是发送给服务器的参数（参数名：参数值）  
        },
      header: {
        'content-type': 'application/json',
        'api-key': 'iBGjCGF2iZcFI1KllNtlb5Xc5Hk='},
      success: function (res) {
        that.setData({ //这里是修改data的值  
          test: res.data //test等于服务器返回来的数据  
        });
        console.log(res.data)
      } })},
   send2: function () {
      var that = this //创建一个名为that的变量来保存this当前的值  
      wx.request({
        url: 'http://api.heclouds.com/devices/508870000/datapoints?type=3',
        method: 'post',
        data: {
          Humidity: '2'  //这里是发送给服务器的参数（参数名：参数值）  
        },
        header: {
          'content-type': 'application/json',
          'api-key': 'iBGjCGF2iZcFI1KllNtlb5Xc5Hk=='},
        success: function (res) {
          that.setData({ //这里是修改data的值  
            test: res.data //test等于服务器返回来的数据  
          });
          console.log(res.data)
        }  }) },
      send3: function () {
        var that = this //创建一个名为that的变量来保存this当前的值  
        wx.request({
          url: 'http://api.heclouds.com/devices/508870000/datapoints?type=3',
          method: 'post',
          data: {
            Humidity: '3'  //这里是发送给服务器的参数（参数名：参数值）         
             },
          header: {
            'content-type': 'application/json',
            'api-key': 'iBGjCGF2iZcFI1KllNtlb5Xc5Hk='},
          success: function (res) {
            that.setData({ //这里是修改data的值  
              test: res.data //test等于服务器返回来的数据  
            });
            console.log(res.data)
          }  })},
        send4: function () {
          var that = this //创建一个名为that的变量来保存this当前的值  
          wx.request({
            url: 'http://api.heclouds.com/devices/508870000/datapoints?type=3',
            method: 'post',
            data: {
              Humidity: '4'  //这里是发送给服务器的参数（参数名：参数值）  
            },
            header: {
              'content-type': 'application/json',
              'api-key': 'iBGjCGF2iZcFI1KllNtlb5Xc5Hk='},
            success: function (res) {
              that.setData({ //这里是修改data的值  
                test: res.data //test等于服务器返回来的数据  
              });
              console.log(res.data)
            }}) },
  send5: function () {
              var that = this //创建一个名为that的变量来保存this当前的值  
              wx.request({
                url: 'http://api.heclouds.com/devices/508870000/datapoints?type=3',
                method: 'post',
                data: {
                  Humidity: '5'  //这里是发送给服务器的参数（参数名：参数值）  
                },
                header: {
                  'content-type': 'application/json',
                  'api-key': 'iBGjCGF2iZcFI1KllNtlb5Xc5Hk='},
                success: function (res) {
                  that.setData({ //这里是修改data的值  
                    test: res.data //test等于服务器返回来的数据  
                  });
                  console.log(res.data)
                } }) },
              send6: function () {
                var that = this //创建一个名为that的变量来保存this当前的值  
                wx.request({
                  url: 'http://api.heclouds.com/devices/508870000/datapoints?type=3',
                  method: 'post',
                  data: {
                    Humidity: '6'  //这里是发送给服务器的参数（参数名：参数值）  
                  },
                  header: {
                    'content-type': 'application/json',
                    'api-key': 'iBGjCGF2iZcFI1KllNtlb5Xc5Hk='},
                  success: function (res) {
                    that.setData({ //这里是修改data的值  
                      test: res.data //test等于服务器返回来的数据  
                       });
                    console.log(res.data)
                  } })  },  }, )
