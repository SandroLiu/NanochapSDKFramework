//
//  NCBNSoozPeripheralManager.h
//  NanochapSDK
//
//  Created by 刘帅 on 2018/12/12.
//  Copyright © 2018年 刘帅. All rights reserved.
//

#import "NCBSecondPeripheralManager.h"
@class NCBNSoozPeripheralManager;
@class NCBSoozeStateItem;

@protocol NCBNSoozPeripheralManagerDataDelegate <NCBSecondPeripheralManagerDataDelegate>
@optional
/// 处理启动回调
- (void)szPeripheralManager:(NCBNSoozPeripheralManager *_Nonnull)szPeripheralManager handleStartWithSucceed:(BOOL)succeed;

/// 调节档位回调
- (void)szPeripheralManagerDidLevelChangeSucceed:(NCBNSoozPeripheralManager *_Nonnull)szPeripheralManager;

/// 暂停回调
- (void)szPeripheralManager:(NCBNSoozPeripheralManager *_Nonnull)szPeripheralManager handlePauseForHasRunSeconds:(uint16_t)seconds;

/// 停止回调
- (void)szPeripheralManagerDidStoped:(NCBNSoozPeripheralManager *_Nonnull )szPeripheralManager;

/// 蜂鸣器控制回调
- (void)szPeripheralManagerDidSettedBuzzer:(NCBNSoozPeripheralManager *_Nonnull )szPeripheralManager;

/// 设置马达回调
- (void)szPeripheralManagerDidSettedShake:(NCBNSoozPeripheralManager *_Nonnull )szPeripheralManager;

/// 设置led
- (void)szPeripheralManagerDidSettedLed:(NCBNSoozPeripheralManager *_Nonnull )szPeripheralManager;

/// 查询设备信息回调
- (void)szPeripheralManager:(NCBNSoozPeripheralManager *_Nonnull )szPeripheralManager handlePeripheralState:(NCBSoozeStateItem *)item;

/// 切换设备运行模式
- (void)szPeripheralManager:(NCBNSoozPeripheralManager *_Nonnull )szPeripheralManager didChangeRunModeSucceed:(BOOL)succeed;

/// 更新总运行时间回调
- (void)szPeripheralManager:(NCBNSoozPeripheralManager *_Nonnull )szPeripheralManager didUpdateTotalRuntimeSucceed:(BOOL)succeed;
@end

NS_ASSUME_NONNULL_BEGIN

@interface NCBNSoozPeripheralManager : NCBSecondPeripheralManager

/** */
@property (nonatomic, weak, nullable) id<NCBNSoozPeripheralManagerDataDelegate> dataDelegate;

/**
 启动设备
 
 @param item 启动参数
 */
- (void)startPeripheralWithItem:(NCBSoozeStateItem *)item;

/**
 调节档位
 
 @param level 档位
 */
- (void)changeLevel:(uint8_t)level;

/**
 暂停设备
 */
- (void)pausePeripheral;

/**
 停止设备
 */
- (void)stopPeripheral;

/**
 强制关机
 */
- (void)shutDownPeripheral;

/**
 设置蜂鸣器
 
 @param open 是否打开蜂鸣器
 */
- (void)setBuzzerForOpen:(BOOL)open;

/**
 设置震动马达
 
 @param open 是否打开
 */
- (void)setShakeForOpen:(BOOL)open;

/**
 设置led
 
 @param open 是否打开
 */
- (void)setLedForOpen:(BOOL)open;

/**
 获取设备运行信息
 */
- (void)getPeripheralState;

/**
 切换设备运行模式

 @param mode 模式1 0x01, 模式2 0x02, 模式3 0x03, 模式4 0x04
 */
- (void)changePeripheralRunMode:(uint8_t)mode;

/**
 更新总的运行时间

 @param seconds 秒
 */
- (void)updateTotalRunTime:(uint16_t)seconds;
@end

NS_ASSUME_NONNULL_END
