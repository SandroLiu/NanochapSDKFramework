//
//  NCBBPMeasureItem.h
//  NanochapSDK
//
//  Created by 刘帅 on 2017/8/29.
//  Copyright © 2017年 刘帅. All rights reserved.
//

#import <NanochapSDK/NanochapSDK.h>

@interface NCBBPMeasureItem : NCBMeasureItem

/*****血压数据组*******/
/** 血压高压*/
@property (nonatomic, assign) NSInteger sys;
/** 血压低压*/
@property (nonatomic, assign) NSInteger dia;
/** 心率*/
@property (nonatomic, assign) NSInteger heartRate;
/** NT*/
@property (nonatomic, assign) NSInteger nt;
/** 第一脉象*/
@property (nonatomic, assign) NCBFirstPulseType firstPulse;
/** 第二脉象*/
@property (nonatomic, assign) NCBSecondPulseType secondPulse;
@end
