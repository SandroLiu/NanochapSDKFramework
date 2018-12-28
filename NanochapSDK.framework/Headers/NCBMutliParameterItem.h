//
//  NCBMutliParameterItem.h
//  NanochapSDK
//
//  Created by 刘帅 on 2018/8/15.
//  Copyright © 2018年 刘帅. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NCBCommonConst.h"

@interface NCBMutliParameterItem : NSObject
/** 时间*/
@property (nonatomic, assign) NCBDate date;
/** 用户id*/
@property (nonatomic, assign) uint64_t userId;
/** 动脉硬化指数*/
@property (nonatomic, assign) float asi;
/** 焦虑指数*/
@property (nonatomic, assign) float ai;
/** 脉搏波速度*/
@property (nonatomic, assign) float pwv;
/** qt间期*/
@property (nonatomic, assign) uint16_t qtc;
/** 心率变形分析参数*/
@property (nonatomic, assign) uint8_t hrv;
/** 心率不齐标记 1 正常，2 心率不齐*/
@property (nonatomic, assign) uint8_t arr;
/** NT值*/
@property (nonatomic, assign) uint16_t nt;
/** 血流灌注指数*/
@property (nonatomic, assign) uint8_t pi;
/** 呼吸率*/
@property (nonatomic, assign) uint8_t rr;
/** 高压*/
@property (nonatomic, assign) uint8_t sys;
/** 低压*/
@property (nonatomic, assign) uint8_t dia;
/** 心率*/
@property (nonatomic, assign) uint8_t hr;
/** 第一脉象*/
@property (nonatomic, assign) NCBFirstPulseType firstPulse;
/** 第二脉象*/
@property (nonatomic, assign) NCBSecondPulseType secondPulse;
/** 血氧*/
@property (nonatomic, assign) uint8_t spO2;
/** 温度*/
@property (nonatomic, assign) uint8_t hbt;
/** 体脂率*/
@property (nonatomic, assign) float bfr;
/** 身体水分率*/
@property (nonatomic, assign) uint8_t pbw;
/** 是否有下一条数据*/
@property (nonatomic, assign) BOOL next;
@end
