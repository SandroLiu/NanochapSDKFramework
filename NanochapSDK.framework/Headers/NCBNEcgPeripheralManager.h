//
//  NCBNEcgPeripheralManager.h
//  NanochapSDK
//
//  Created by 刘帅 on 2018/12/12.
//  Copyright © 2018年 刘帅. All rights reserved.
//

#import "NCBSecondPeripheralManager.h"
@class NCBNEcgPeripheralManager;
@class NCBMutliParameterItem;

@protocol NCBNEcgPeripheralManagerDataDelegate <NCBSecondPeripheralManagerDataDelegate>
@optional

/**
 开始测量
 
 @param ecgPeripheralManager 心电外设管理对象
 */
- (void)ecgPeripheralManager:(NCBNEcgPeripheralManager *_Nonnull)ecgPeripheralManager didStartMeasureWithState:(NCBPeripheralStartMeasureState)state;
/**
 结束测量
 
 @param ecgPeripheralManager 心电外设管理对象
 */
- (void)ecgPeripheralManagerDidEndMeasure:(NCBNEcgPeripheralManager *_Nonnull)ecgPeripheralManager;

/**
 开始测量阻抗

 @param ecgPeripheralManager 心电外设管理对象
 */
- (void)ecgPeripheralManagerStartImpedanceMeasure:(NCBNEcgPeripheralManager *_Nonnull)ecgPeripheralManager;

/**
 心电波形返回
 
 @param ecgPeripheralManager 心电外设管理对象
 @param datas 心电波形
 @param hr 心率
 */
- (void)ecgPeripheralManager:(NCBNEcgPeripheralManager *_Nonnull)ecgPeripheralManager didReceivedEcgwaveData:(NSArray *_Nonnull)datas heartRate:(NSUInteger)hr;

/**
 *  多参数数据返回
 *
 *  @param ecgPeripheralManager 心电外设管理对象
 *  @param item       测量值
 */
- (void)ecgPeripheralManager:(NCBNEcgPeripheralManager *_Nonnull)ecgPeripheralManager didFetchMutliParameterMeasureItem:(NCBMutliParameterItem *_Nonnull)item waveData:(NSArray *)datas;

/**
 数据crc校验出错

 @param ecgPeripheralManager 心电外设管理对象
 */
- (void)ecgPeripheralDataCrcError:(NCBNEcgPeripheralManager *_Nonnull)ecgPeripheralManager;
@end

@interface NCBNEcgPeripheralManager : NCBSecondPeripheralManager

/** */
@property (nonatomic, weak, nullable) id<NCBNEcgPeripheralManagerDataDelegate> dataDelegate;

/**
 启动测量
 */
- (void)startEcgMeasure;

/**
 结束测量
 */
- (void)endEcgMeasure;

/**
 发送用户信息
 
 @param height 身高cm
 @param weight 体重kg
 @param gender 性别 0女 1男
 @param age 年龄
 */
- (void)sendUserInfoWithHeight:(uint8_t)height weight:(uint8_t)weight gender:(uint8_t)gender age:(uint8_t)age;
@end

