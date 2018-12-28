//
//  NCBAdvertisementItem.h
//  NanochapSDK
//
//  Created by 刘帅 on 2017/9/6.
//  Copyright © 2017年 刘帅. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>

typedef NS_ENUM(NSUInteger, NCBAdvertisementType){
    NCBFirstAdvertisement = 1, // 第一版协议广播包
    NCBSecondAdvertisement, // 第二版协议广播包
    NCBFirmwareUpgardeAdvertisement
};

@interface NCBAdvertisementItem : NSObject

/** 广播包类型*/
@property (nonatomic, assign) NCBAdvertisementType advertisementType;
/** 设备名字*/
@property (nonatomic, copy) NSString *name;
/** 衰减度*/
@property (nonatomic, copy) NSNumber *RSSI;
/** 是否还可以绑定*/
@property (nonatomic, assign, getter=isCanBind) BOOL canBind;
/** 是否在充电*/
@property (nonatomic, assign, getter=isCahrge) BOOL charge;
/** 外设*/
@property (nonatomic, strong) CBPeripheral *peripheral;



@end
