//
//  NCBSecondAdvertisementItem.h
//  NanochapSDK
//
//  Created by 刘帅 on 2017/12/15.
//  Copyright © 2017年 刘帅. All rights reserved.
//

#import "NCBAdvertisementItem.h"

@interface NCBSecondAdvertisementItem : NCBAdvertisementItem

/** 已经绑定的设备的数量*/
@property (nonatomic, assign) NSInteger bindCount;
/** 固件版本*/
@property (nonatomic, copy) NSString *firmwareVersion;
/** 当前用户是否经过校准*/
@property (nonatomic, assign, getter=isCalibration) BOOL calibration;
/** 是否产生过报警信息*/
@property (nonatomic, assign, getter=isAlarm) BOOL alarm;
/** MAC 地址*/
@property (nonatomic, copy) NSData *MACData;
@end
