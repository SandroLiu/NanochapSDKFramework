//
//  NCBPressurePeripheralManager.h
//  NanochapSDK
//
//  Created by 刘帅 on 2019/1/17.
//  Copyright © 2019年 刘帅. All rights reserved.
//

#import "NCBSecondPeripheralManager.h"
@class NCBPressurePeripheralManager;

@protocol NCBPressurePeripheralManagerDataDelegate <NCBSecondPeripheralManagerDataDelegate>
@optional

/**
 基准压力测量返回
 */
- (void)pressurePerpheralManager:(NCBPressurePeripheralManager *)pressurePeripheralManager measureBasePressureSucceed:(BOOL)succeed;

/**
 启动气囊压力测量返回
 */
- (void)pressurePerpheralManager:(NCBPressurePeripheralManager *)pressurePeripheralManager startGasbagPressureMeasureSucceed:(BOOL)succeed;

/**
 停止气囊压力测量返回
 */
- (void)pressurePerpheralManager:(NCBPressurePeripheralManager *)pressurePeripheralManager stopGasbagPressureMeasureSucceed:(BOOL)succeed;

/**
 设置压力范围返回
 */
- (void)pressurePerpheralManager:(NCBPressurePeripheralManager *)pressurePeripheralManager setPressureRangeSucceed:(BOOL)succeed;

/**
  压力返回
 */
- (void)pressurePerpheralManager:(NCBPressurePeripheralManager *)pressurePeripheralManager didReceivePressure:(int)pressure;
@end

@interface NCBPressurePeripheralManager : NCBSecondPeripheralManager

/** */
@property (nonatomic, weak) id<NCBPressurePeripheralManagerDataDelegate> dataDelegate;

/**
  测量基准压力
 */
- (void)measureBasePressure;

/**
  设置压力范围
 
  @param highPressure 压力上限
  @param lowPressure 压力下限
 */
- (void)setHighPressure:(uint16_t)highPressure lowPressure:(uint16_t)lowPressure;

/**
  开始测量气囊压力
 */
- (void)startMeasureGasbagPressure;

/**
  停止测量气囊压力
 */
- (void)stopMeasureGasbagPressure;
@end

