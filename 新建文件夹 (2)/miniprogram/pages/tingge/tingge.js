const app = getApp()
Page({data: {},
 send1: function () {
    var that = this //创建一个名为that的变量来保存this当前的值  
    wx.request({
      url: 'http://api.heclouds.com/devices/508870000/datapoints?type=3',
      method: 'post',
      data: {
        Humidity: '8'  //这里是发送给服务器的参数（参数名：参数值）  
      },
      header: {
        'content-type': 'application/json',
        'api-key': 'iBGjCGF2iZcFI1KllNtlb5Xc5Hk=' },
      success: function (res) {
        that.setData({ //这里是修改data的值  
          test: res.data //test等于服务器返回来的数据  
        });
        console.log(res.data)  } }) },
  send2: function () {
      var that = this //创建一个名为that的变量来保存this当前的值  
      wx.request({
        url: 'http://api.heclouds.com/devices/508870000/datapoints?type=3',
        method: 'post',
        data: {
          Humidity: 'a'  //这里是发送给服务器的参数（参数名：参数值）  
        },
        header: {
          'content-type': 'application/json',
          'api-key': 'iBGjCGF2iZcFI1KllNtlb5Xc5Hk='},
        success: function (res) {
          that.setData({ //这里是修改data的值  
            test: res.data //test等于服务器返回来的数据  
          });
          console.log(res.data) }})},
 send3: function () {
        var that = this //创建一个名为that的变量来保存this当前的值  
        wx.request({
          url: 'http://api.heclouds.com/devices/508870000/datapoints?type=3',
          method: 'post',
          data: {
            Humidity: 'b'  //这里是发送给服务器的参数（参数名：参数值）  
          },
          header: {
            'content-type': 'application/json',
            'api-key': 'iBGjCGF2iZcFI1KllNtlb5Xc5Hk=' },
          success: function (res) {
            that.setData({ //这里是修改data的值  
              test: res.data //test等于服务器返回来的数据  
            });
            console.log(res.data)   }  })},},)
