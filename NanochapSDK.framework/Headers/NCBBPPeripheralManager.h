//
//  NCBBPPeripheralManager.h
//  NanochapSDK
//
//  Created by 刘帅 on 2017/12/18.
//  Copyright © 2017年 刘帅. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NCBPeripheralState.h"
#import "NCBDebugConst.h"
#if NCBDEBUG
#import "NCBPeripheralDebugDelegate.h"
#endif

@class NCBBPPeripheralManager;
@class NCBMutliParameterItem;
@class NCBFirstBpMeasureItem;
@class NCBAdvertisementItem;
@class NCBBPMeasureItem;
@class NCBSPMeasureItem;

@protocol NCBBPPeripheralManagerConnectDelegate<NSObject>
@optional
/**
 连接失败回调

 @param bpPeripheralManager 血压外设管理对象
 @param error 错误
 */
- (void)bpPeripheralManager:(NCBBPPeripheralManager *_Nonnull)bpPeripheralManager didFailToConnectDevice:(NSError *_Nullable)error;

/**
 与外设失去连接

 @param bpPeripheralManager 血压外设管理对象
 @param error 错误
 */
- (void)bpPeripheralManager:(NCBBPPeripheralManager *_Nonnull)bpPeripheralManager didDisconnectPeripheral:(NSError * _Nullable)error;

/**
 设备绑定回调

 @param bpPeripheralManager 血压外设管理对象
 @param state 绑定状态
 */
- (void)bpPeripheralManager:(NCBBPPeripheralManager *_Nonnull)bpPeripheralManager didBindState:(NCBPeripheralBindState)state;

/**
 *  返回解绑结果
 *
 *  @param bpPeripheralManager 血压外设管理对象
 *  @param state      结果
 */
- (void)bpPeripheralManager:(NCBBPPeripheralManager *_Nonnull)bpPeripheralManager didUnbindState:(NCBPeripheralUnbindState)state;

/**
 *  返回登录结果
 *
 *  @param bpPeripheralManager 血压外设管理对象
 *  @param state      结果
 */
- (void)bpPeripheralManager:(NCBBPPeripheralManager *_Nonnull)bpPeripheralManager didLoginState:(NCBPeripheralLoginState)state;

/**
 *  返回退出结果
 *
 *  @param bpPeripheralManager 血压外设管理对象
 *  @param state      结果
 */
- (void)bpPeripheralManager:(NCBBPPeripheralManager *_Nonnull)bpPeripheralManager didLogoutState:(NCBPeripheralLogoutState)state;

/**
 返回单纯连接结果
 
 @param bpPeripheralManager 血压外设管理对象
 @param state 状态
 */
- (void)bpPeripheralManager:(NCBBPPeripheralManager *_Nonnull)bpPeripheralManager didConnectState:(NCBPeripheralConnectState)state;

@end

@protocol NCBBPPeripheralManagerDataDelegate<NSObject>

@optional
#pragma mark- 两代设备共有的回调方法
/**
 读取电量值回调

 @param bpPeripheralManager 血压外设管理对象
 @param value 电量值
 */
- (void)bpPeripheralManager:(NCBBPPeripheralManager *_Nonnull)bpPeripheralManager didReadedElectricValue:(NSUInteger)value;
/**
 获取mac地址

 @param bpPeripheralManager 血压外设管理对象
 @param mac mac地址
 */
- (void)bpPeripheralManager:(NCBBPPeripheralManager *_Nonnull)bpPeripheralManager didReadedMac:(NSData *_Nonnull)mac;

/**
 校准回调
 
 @param bpPeripheralManager 血压外设管理对象
 @param state 校准结果
 */
- (void)bpPeripheralManager:(NCBBPPeripheralManager *_Nonnull)bpPeripheralManager didAlignedState:(NCBPeripheralCalibrationState)state;

#pragma mark- 第一代设备有的回调方法

/**
 血压值测量接收

 @param bpPeripheralManager 血压外设管理对象
 @param item 血压测量值
 */
- (void)bpPeripheralManager:(NCBBPPeripheralManager *_Nonnull)bpPeripheralManager didReceivedBloodPressureMeasureItem:(NCBFirstBpMeasureItem *_Nonnull)item;

/**
 *  多参数数据返回
 *
 *  @param bpPeripheralManager 血压外设管理对象
 *  @param item       测量值
 */
- (void)bpPeripheralManager:(NCBBPPeripheralManager *_Nonnull)bpPeripheralManager didFetchMutliParameterMeasureItem:(NCBMutliParameterItem *_Nonnull)item;

/**
 设置用户信息回调

 @param bpPeripheralManager 血压外设管理对象
 @param succeed 成功或失败
 */
- (void)bpPeripheralManager:(NCBBPPeripheralManager *_Nonnull)bpPeripheralManager didSetUserInfoSucceed:(BOOL)succeed;

/**
 时间设置成功回调

 @param bpPeripheralManager 血压外设管理对像
 */
- (void)bpPeripheralManager:(NCBBPPeripheralManager *_Nonnull)bpPeripheralManager didSetTimeSucceed:(BOOL)succeed;

#pragma mark- 第二代设备有的回调方法
/**
 *  开始血压测量
 *
 *  @param bpPeripheralManager 血压外设管理对象
 */
- (void)bpPeripheralManager:(NCBBPPeripheralManager *_Nonnull)bpPeripheralManager didStartBPMeasureState:(NCBPeripheralStartMeasureState)state;

/**
 *  开始血氧测试
 *
 *  @param bpPeripheralManager 血压外设管理对象
 */
- (void)bpPeripheralManager:(NCBBPPeripheralManager *_Nonnull)bpPeripheralManager didStartSPMeasureState:(NCBPeripheralStartMeasureState)state;

/**
 结束测量

 @param bpPeripheralManager 血压外设管理对象
 */
- (void)bpPeripheralManagerDidEndMeasure:(NCBBPPeripheralManager *_Nonnull)bpPeripheralManager;
/**
 *  测量血压的数据
 *
 *  @param bpPeripheralManager 血压外设管理对象
 *  @param item       测量值
 */
- (void)bpPeripheralManager:(NCBBPPeripheralManager *_Nonnull)bpPeripheralManager didFetchBPMeasureItem:(NCBBPMeasureItem *_Nonnull)item;

/**
 *  获得血氧数据
 *
 *  @param bpPeripheralManager 血压外设管理对象
 *  @param item       测量值
 */
- (void)bpPeripheralManager:(NCBBPPeripheralManager *_Nonnull)bpPeripheralManager didFetchSPMeasureItem:(NCBSPMeasureItem *_Nonnull)item;

/**
 *  脉搏波形数据
 *
 *  @param bpPeripheralManager 血压外设管理对象
 *  @param datas      波形数据
 */
- (void)bpPeripheralManager:(NCBBPPeripheralManager *_Nonnull)bpPeripheralManager didReceivePulseWaveData:(NSArray *_Nonnull)datas;

/**
 *  血氧波形数据
 *
 *  @param bpPeripheralManager 血压外设管理对象
 *  @param datas      波形数据
 */
- (void)bpPeripheralManager:(NCBBPPeripheralManager *_Nonnull)bpPeripheralManager didReceiveSPWaveData:(NSArray *_Nonnull)datas;

/**
 *  测量失败
 *
 *  @param bpPeripheralManager 血压外设管理对象
 */
- (void)bpPeripheralManagerDidMeasureFail:(NCBBPPeripheralManager *_Nonnull)bpPeripheralManager;

@end

NS_CLASS_DEPRECATED_IOS(2.0, 2.0, "该类已经废弃，请使用 -NCBBPFirstPeripheralManager或-NCBBPSecondPeripheralManager")
/// 血压外设管理类，非单例类
@interface NCBBPPeripheralManager : NSObject

/// 连接回调
@property (nonatomic, weak) id<NCBBPPeripheralManagerConnectDelegate> _Nullable connectDelegate;
/// 数据回调
@property (nonatomic, weak) id<NCBBPPeripheralManagerDataDelegate> _Nullable dataDelegate;

#if NCBDEBUG
@property (nonatomic, weak) id<NCBPeripheralDebugDelegate> _Nullable debugDelegate;
#endif

#pragma mark- 两代血压设备都有的功能
/**
 绑定设备
 
 @param advertisementItem 广播包基类
 @param userId 用户id
 */
- (void)bindPeripheralWithAdvertisementItem:(NCBAdvertisementItem *_Nonnull)advertisementItem userId:(uint64_t)userId;

/**
 解绑设备
 */
- (void)unbindPeripheral;

/**
 登录设备
 
 @param advertisementItem 广播包基类
 @param userId 用户id
 */
- (void)logingPeripheralWithAdvertisementItem:(NCBAdvertisementItem *_Nonnull)advertisementItem userId:(uint64_t)userId;

/**
 退出设备
 */
- (void)logoutPeripheral;


/**
 仅是连接设备
 
 @param advertisementItem 广播包基类
 */
- (void)connectPeripheralWithAdvertisementItem:(NCBAdvertisementItem *_Nonnull)advertisementItem;

#if NCBDEBUG
/**
 超级解绑
 */
- (void)superUnbind;

/**
 发送自定义数据

 @param cmd cmd
 @param key key
 @param value value
 */
- (void)sendCmd:(uint8_t)cmd key:(uint8_t)key value:(NSData *_Nullable)value;
#endif

/**
 校准
 
 @param sys 标准高压值
 @param dia 标准低压值
 */
- (void)alignedPeripheralWithSys:(uint8_t)sys dia:(uint8_t)dia;

/**
 读取设备电量
 */
- (void)readPeripheralElectricQuantity;

/**
 读取mac地址
 */
- (void)readPeripheralMacAddress;

/**
 获取固件版本号
 */
- (void)readPeripheralFirmwareVersion:(void(^_Nullable)(NSString * _Nonnull firmwareVersion))block;

/**
 是否与外设连接
 
 @return YES/No
 */
- (BOOL)isConnectedToPeripheral;

/**
 与外设断开连接
 */
- (void)disconnectFromThePeripheral;

/**
 是否有新的固件
 */
- (void)isHaveNewFirmware:(void(^_Nullable)(BOOL isHaveNewFirmware))block NS_DEPRECATED_IOS(2_0, 2_0);

/**
 *  固件更新，自动判断是否有新的固件，并且下载到指定的路径下面进行更新
 *
 *  @param filePath              文件存储路径
 *  @param downloadProgressBlock 下载固件的进度
 *  @param updateProgressBlock   固件更新的进度
 *  @param completionHandler     完成的回调
 *
 */
- (void)firmwareUpdateWithFilePath:(NSString *_Nonnull)filePath downloadProgressBlock:(void(^_Nullable)(NSUInteger downloadProgress))downloadProgressBlock updateProgressBlock:(void(^_Nullable)(NSUInteger writeProgress))updateProgressBlock completionHandler:(void(^_Nullable)(NCBPeripheralFirmwareUpdateResutl result))completionHandler NS_DEPRECATED_IOS(2_0, 2_0);
;


/**
 固件更新，直接传递固件文件路径进行更新，新的固件需要手动下载

 @param filePath 固件文件路径
 @param updateProgressBlock 固件更新进度
 @param completionHandler 完成的回调
 */
- (void)startFirmwareUpgradeWithFilePath:(NSURL *)filePath updateProgressBlock:(void(^_Nullable)(NSUInteger writeProgress))updateProgressBlock completionHandler:(void(^_Nullable)(NCBPeripheralFirmwareUpdateResutl result))completionHandler;
#pragma mark- 第一代设备有的方法

/**
 设置时间，绑定登录会自动调用，单纯连接需要手动调用
 */
- (void)setTime;

/**
 获取历史测量数据
 */
- (void)readHistoryMeasureData;

/**
 发送用户信息

 @param height 身高cm
 @param weight 体重kg
 @param gender 性别 0女 1男
 @param age 年龄
 */
- (void)sendUserInfoWithHeight:(uint8_t)height weight:(uint8_t)weight gender:(uint8_t)gender age:(uint8_t)age;
#pragma mark- 第二代设备有的方法
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
 使设备的led灯闪烁

 @param duraction 闪烁时间, 1亮，0灭
 */
- (void)ledFlashesForDuration:(uint8_t)duraction;

@end
