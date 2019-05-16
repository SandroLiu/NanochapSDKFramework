//
//  NCBEPMPeripheralManager.h
//  NanochapSDK
//
//  Created by 刘帅 on 2019/4/3.
//  Copyright © 2019年 刘帅. All rights reserved.
//

#import "NCBSecondPeripheralManager.h"
@class NCBEPMPeripheralManager;
@class NCBMutliParameterItem;

@protocol NCBEPMPeripheralManagerDataDelegate <NCBSecondPeripheralManagerDataDelegate>
/**
 开始测量
 
 @param epmPeripheralManager 外设管理对象
 */
- (void)epmPeripheralManager:(NCBEPMPeripheralManager *_Nonnull)epmPeripheralManager didStartMeasureWithState:(NCBPeripheralStartMeasureState)state;
/**
 结束测量
 
 @param epmPeripheralManager 外设管理对象
 */
- (void)epmPeripheralManagerDidEndMeasure:(NCBEPMPeripheralManager *_Nonnull)epmPeripheralManager;

/**
 *  多参数数据返回
 *
 *  @param epmPeripheralManager 外设管理对象
 *  @param item       测量值
 */
- (void)epmPeripheralManager:(NCBEPMPeripheralManager *_Nonnull)epmPeripheralManager didFetchMutliParameterMeasureItem:(NCBMutliParameterItem *_Nonnull)item;
@end

@interface NCBEPMPeripheralManager : NCBSecondPeripheralManager
/** */
@property (nonatomic, weak, nullable) id<NCBEPMPeripheralManagerDataDelegate> dataDelegate;

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

