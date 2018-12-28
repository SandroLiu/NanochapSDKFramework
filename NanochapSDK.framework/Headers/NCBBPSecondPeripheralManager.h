//
//  NCBBPSecondPeripheralManager.h
//  NanochapSDK
//
//  Created by 刘帅 on 2018/12/12.
//  Copyright © 2018年 刘帅. All rights reserved.
//

#import "NCBSecondPeripheralManager.h"
@class NCBBPSecondPeripheralManager;
@class NCBBPMeasureItem;
@class NCBSPMeasureItem;

@protocol NCBBPSecondPeripheralManagerDataDelegate <NCBSecondPeripheralManagerDataDelegate>
@optional

/**
 校准回调
 
 @param secondBpPeripheralManager 血压外设管理对象
 @param state 校准结果
 */
- (void)secondBpPeripheralManager:(NCBBPSecondPeripheralManager *_Nonnull)secondBpPeripheralManager didAlignedState:(NCBPeripheralCalibrationState)state;

/**
 *  开始血压测量
 *
 *  @param secondBpPeripheralManager 血压外设管理对象
 */
- (void)secondBpPeripheralManager:(NCBBPSecondPeripheralManager *_Nonnull)secondBpPeripheralManager didStartBPMeasureState:(NCBPeripheralStartMeasureState)state;

/**
 *  开始血氧测试
 *
 *  @param secondBpPeripheralManager 血压外设管理对象
 */
- (void)secondBpPeripheralManager:(NCBBPSecondPeripheralManager *_Nonnull)secondBpPeripheralManager didStartSPMeasureState:(NCBPeripheralStartMeasureState)state;

/**
 结束测量
 
 @param secondBpPeripheralManager 血压外设管理对象
 */
- (void)secondBpPeripheralManagerDidEndMeasure:(NCBBPSecondPeripheralManager *_Nonnull)secondBpPeripheralManager;

/**
 *  测量血压的数据
 *
 *  @param secondBpPeripheralManager 血压外设管理对象
 *  @param item       测量值
 */
- (void)secondBpPeripheralManager:(NCBBPSecondPeripheralManager *_Nonnull)secondBpPeripheralManager didFetchBPMeasureItem:(NCBBPMeasureItem *_Nonnull)item;

/**
 *  获得血氧数据
 *
 *  @param secondBpPeripheralManager 血压外设管理对象
 *  @param item       测量值
 */
- (void)secondBpPeripheralManager:(NCBBPSecondPeripheralManager *_Nonnull)secondBpPeripheralManager didFetchSPMeasureItem:(NCBSPMeasureItem *_Nonnull)item;

/**
 *  脉搏波形数据
 *
 *  @param secondBpPeripheralManager 血压外设管理对象
 *  @param datas      波形数据
 */
- (void)secondBpPeripheralManager:(NCBBPSecondPeripheralManager *_Nonnull)secondBpPeripheralManager didReceivePulseWaveData:(NSArray *_Nonnull)datas;

/**
 *  血氧波形数据
 *
 *  @param secondBpPeripheralManager 血压外设管理对象
 *  @param datas      波形数据
 */
- (void)secondBpPeripheralManager:(NCBBPSecondPeripheralManager *_Nonnull)secondBpPeripheralManager didReceiveSPWaveData:(NSArray *_Nonnull)datas;

/**
 *  测量失败
 *
 *  @param secondBpPeripheralManager 血压外设管理对象
 */
- (void)secondBpPeripheralManagerDidMeasureFail:(NCBBPSecondPeripheralManager *_Nonnull)secondBpPeripheralManager;
@end


NS_ASSUME_NONNULL_BEGIN

@interface NCBBPSecondPeripheralManager : NCBSecondPeripheralManager

/** */
@property (nonatomic, weak, nullable) id<NCBBPSecondPeripheralManagerDataDelegate> dataDelegate;

/**
 开始测量血压
 */
- (void)startMeasureBloodPresure;

/**
 开始测量血氧
 */
- (void)startMeasureBloodOxygen;

/**
 停止测量
 */
- (void)stopMeasure;

/**
 校准
 
 @param sys 标准高压值
 @param dia 标准低压值
 */
- (void)alignedPeripheralWithSys:(uint8_t)sys dia:(uint8_t)dia;
@end

NS_ASSUME_NONNULL_END
