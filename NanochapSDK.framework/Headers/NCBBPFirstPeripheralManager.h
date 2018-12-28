//
//  NCBBPFirstPeripheralManager.h
//  NanochapSDK
//
//  Created by 刘帅 on 2018/12/12.
//  Copyright © 2018年 刘帅. All rights reserved.
//

#import "NCBFirstPerihperalManager.h"
@class NCBBPFirstPeripheralManager;
@class NCBFirstBpMeasureItem;
@class NCBMutliParameterItem;

@protocol NCBBPFirstPeripheralManagerDataDelegate <NCBFirstPerihperalManagerDataDelegate>
@optional

/**
 校准回调
 
 @param firstBpPeripheralManager 血压外设管理对象
 @param state 校准结果
 */
- (void)firstBpPeripheralManager:(NCBBPFirstPeripheralManager *_Nonnull)firstBpPeripheralManager didAlignedState:(NCBPeripheralCalibrationState)state;

/**
 血压值测量接收
 
 @param firstBpPeripheralManager 血压外设管理对象
 @param item 血压测量值
 */
- (void)firstBpPeripheralManager:(NCBBPFirstPeripheralManager *_Nonnull)firstBpPeripheralManager didReceivedBloodPressureMeasureItem:(NCBFirstBpMeasureItem *_Nonnull)item;

/**
 *  多参数数据返回
 *
 *  @param firstBpPeripheralManager 血压外设管理对象
 *  @param item       测量值
 */
- (void)firstBpPeripheralManager:(NCBBPFirstPeripheralManager *_Nonnull)firstBpPeripheralManager didFetchMutliParameterMeasureItem:(NCBMutliParameterItem *_Nonnull)item;

/**
 打印fpga测量信息回调

 @param firstBpPeripheralManager 血压外设管理对象
 @param item 血压数据
 */
- (void)firstBpPeripheralManager:(NCBFirstPerihperalManager *)firstBpPeripheralManager fpgaMeasureItem:(NCBFirstBpMeasureItem *)item;
@end

NS_ASSUME_NONNULL_BEGIN

@interface NCBBPFirstPeripheralManager : NCBFirstPerihperalManager

/** */
@property (nonatomic, weak, nullable) id<NCBBPFirstPeripheralManagerDataDelegate> dataDelegate;

/**
 校准
 
 @param sys 标准高压值
 @param dia 标准低压值
 */
- (void)alignedPeripheralWithSys:(uint8_t)sys dia:(uint8_t)dia;
@end

NS_ASSUME_NONNULL_END
