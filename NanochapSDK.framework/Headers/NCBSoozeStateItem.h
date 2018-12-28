//
//  NCBSoozeStateItem.h
//  NanochapSDK
//
//  Created by 刘帅 on 2018/5/29.
//  Copyright © 2018年 刘帅. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(uint8_t, NCBSoozeFunction) {
    NCBSoozeFunctionTENS = 0x01, // 经皮神经电刺激
    NCBSoozeFunctionEMS_ASP = 0x02, // 肌肉电刺激-运动员加强模式
    NCBSoozeFunctionEMS_RP = 0x03 // 肌肉电刺激-恢复模式
};

@interface NCBSoozeStateItem : NSObject<NSCopying>

/** 设备功能*/
@property (nonatomic, assign) NCBSoozeFunction soozeFunction;
/** 设备模式 0x01 - 0x04*/
@property (nonatomic, assign) uint8_t mode;
/** 设备档位 0x01 - 0x10*/
@property (nonatomic, assign) uint8_t level;
/** 总的时间 秒为单位*/
@property (nonatomic, assign) uint16_t totalTime;
/** 已经运行的时间 秒为单位*/
@property (nonatomic, assign) uint16_t runTime;
/** 0 没有启动 1 app启动 2是按键启动 3是app启动暂停状态 4是要关机状态*/
@property (nonatomic, assign) uint8_t startMethod;
/** 蜂鸣器 0 关闭 1 启动*/
@property (nonatomic, assign) uint8_t buzzer;
/** 马达 0 关闭 1 启动*/
@property (nonatomic, assign) uint8_t shake;
/** led灯 0 关闭 1 启动*/
@property (nonatomic, assign) uint8_t led;
@end
