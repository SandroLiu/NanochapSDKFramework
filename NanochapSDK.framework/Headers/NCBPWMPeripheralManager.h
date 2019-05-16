//
//  NCBPWMPeripheralManager.h
//  NanochapSDK
//
//  Created by 刘帅 on 2019/4/3.
//  Copyright © 2019年 刘帅. All rights reserved.
//

#import "NCBSecondPeripheralManager.h"
@class NCBPWMPeripheralManager;
@class NCBMutliParameterItem;

@protocol NCBPWMPeripheralManagerDataDelegate <NCBSecondPeripheralManagerDataDelegate>

@optional
/**
 *  开始测量
 *
 *  @param pwmPeripheralManager 外设管理对象
 */
- (void)pwmPeripheralManager:(NCBPWMPeripheralManager *_Nonnull)pwmPeripheralManager didStartBPMeasureState:(NCBPeripheralStartMeasureState)state;

/**
 结束测量
 
 @param pwmPeripheralManager 外设管理对象
 */
- (void)pwmPeripheralManagerDidEndMeasure:(NCBPWMPeripheralManager *_Nonnull)pwmPeripheralManager;

/**
 *  测量血压的数据
 *
 *  @param pwmPeripheralManager 外设管理对象
 *  @param item       测量值
 */
- (void)pwmPeripheralManager:(NCBPWMPeripheralManager *_Nonnull)pwmPeripheralManager didFetchMeasureItem:(NCBMutliParameterItem *_Nonnull)item;

/**
 *  波形数据
 *
 *  @param pwmPeripheralManager 外设管理对象
 *  @param datas      波形数据
 */
- (void)pwmPeripheralManager:(NCBPWMPeripheralManager *_Nonnull)pwmPeripheralManager didReceivePulseWaveData:(NSArray *_Nonnull)datas;

/**
 *  测量失败
 *
 *  @param pwmPeripheralManager 血压外设管理对象
 */
- (void)pwmPeripheralManagerDidMeasureFail:(NCBPWMPeripheralManager *_Nonnull)pwmPeripheralManager;
@end

@interface NCBPWMPeripheralManager : NCBSecondPeripheralManager

/** */
@property (nonatomic, weak, nullable) id<NCBPWMPeripheralManagerDataDelegate> dataDelegate;

/**
 开始测量
 */
- (void)startMeasure;

/**
 停止测量
 */
- (void)stopMeasure;
@end

