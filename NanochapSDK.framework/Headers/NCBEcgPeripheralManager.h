//
//  NCBEcgPeripheralManager.h
//  NanochapSDK
//
//  Created by 刘帅 on 2017/12/19.
//  Copyright © 2017年 刘帅. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NCBDebugConst.h"
#if NCBDEBUG
#import "NCBPeripheralDebugDelegate.h"
#endif
#import "NCBPeripheralState.h"

@class NCBEcgPeripheralManager;
@class NCBMutliParameterItem;
@class NCBAdvertisementItem;

@protocol NCBEcgPeripheralManagerConnectDelegate<NSObject>
@optional
/**
 连接失败回调
 
 @param ecgPeripheralManager 心电外设管理对象
 @param error 错误
 */
- (void)ecgPeripheralManager:(NCBEcgPeripheralManager *_Nonnull)ecgPeripheralManager didFailToConnectDevice:(NSError *_Nullable)error;

/**
 与外设失去连接
 
 @param ecgPeripheralManager 心电外设管理对象
 @param error 错误
 */
- (void)ecgPeripheralManager:(NCBEcgPeripheralManager *_Nonnull)ecgPeripheralManager didDisconnectPeripheral:(NSError * _Nullable)error;

/**
 设备绑定回调
 
 @param ecgPeripheralManager 心电外设管理对象
 @param state 绑定状态
 */
- (void)ecgPeripheralManager:(NCBEcgPeripheralManager *_Nonnull)ecgPeripheralManager didBindState:(NCBPeripheralBindState)state;

/**
 *  返回解绑结果
 *
 *  @param ecgPeripheralManager 心电外设管理对象
 *  @param state      结果
 */
- (void)ecgPeripheralManager:(NCBEcgPeripheralManager *_Nonnull)ecgPeripheralManager didUnbindState:(NCBPeripheralUnbindState)state;

/**
 *  返回登录结果
 *
 *  @param ecgPeripheralManager 心电外设管理对象
 *  @param state      结果
 */
- (void)ecgPeripheralManager:(NCBEcgPeripheralManager *_Nonnull)ecgPeripheralManager didLoginState:(NCBPeripheralLoginState)state;

/**
 *  返回退出结果
 *
 *  @param ecgPeripheralManager 心电外设管理对象
 *  @param state      结果
 */
- (void)ecgPeripheralManager:(NCBEcgPeripheralManager *_Nonnull)ecgPeripheralManager didLogoutState:(NCBPeripheralLogoutState)state;

/**
 返回单纯连接结果
 
 @param ecgPeripheralManager 心电外设管理对象
 @param state 状态
 */
- (void)ecgPeripheralManager:(NCBEcgPeripheralManager *_Nonnull)ecgPeripheralManager didConnectState:(NCBPeripheralConnectState)state;
@end

@protocol NCBEcgPeripheralManagerDataDelegate<NSObject>
@optional
/**
 读取电量值回调
 
 @param ecgPeripheralManager 心电外设管理对象
 @param value 电量值
 */
- (void)ecgPeripheralManager:(NCBEcgPeripheralManager *_Nonnull)ecgPeripheralManager didReadedElectricValue:(NSUInteger)value;
/**
 获取mac地址
 
 @param ecgPeripheralManager 心电外设管理对象
 @param mac mac地址
 */
- (void)ecgPeripheralManager:(NCBEcgPeripheralManager *_Nonnull)ecgPeripheralManager didReadedMac:(NSData *_Nonnull)mac;

/**
 开始测量

 @param ecgPeripheralManager 心电外设管理对象
 */
//- (void)ecgPeripheralManagerDidStartMeasure:(NCBEcgPeripheralManager *_Nonnull)ecgPeripheralManager;
- (void)ecgPeripheralManager:(NCBEcgPeripheralManager *_Nonnull)ecgPeripheralManager didStartMeasureWithState:(NCBPeripheralStartMeasureState)state;
/**
 结束测量
 
 @param ecgPeripheralManager 心电外设管理对象
 */
- (void)ecgPeripheralManagerDidEndMeasure:(NCBEcgPeripheralManager *_Nonnull)ecgPeripheralManager;

/**
 心电波形返回

 @param ecgPeripheralManager 心电外设管理对象
 @param datas 心电波形
 @param hr 心率
 */
- (void)ecgPeripheralManager:(NCBEcgPeripheralManager *_Nonnull)ecgPeripheralManager didReceivedEcgwaveData:(NSArray *_Nonnull)datas heartRate:(NSUInteger)hr;
//- (void)ecgPeripheralManager:(NCBEcgPeripheralManager *_Nonnull)ecgPeripheralManager didReceivedEcgwaveData:(NSArray *_Nonnull)datas;

/**
 *  多参数数据返回
 *
 *  @param ecgPeripheralManager 心电外设管理对象
 *  @param item       测量值
 */
//- (void)ecgPeripheralManager:(NCBEcgPeripheralManager *_Nonnull)ecgPeripheralManager didFetchMutliParameterMeasureItem:(NCBMutliParameterItem *_Nonnull)item;

- (void)ecgPeripheralManager:(NCBEcgPeripheralManager *_Nonnull)ecgPeripheralManager didFetchMutliParameterMeasureItem:(NCBMutliParameterItem *_Nonnull)item waveData:(NSArray *)datas;

/**
 用户信息设置回调

 @param ecgPeripheralManager 心电外设管理对象
 @param state 状态
 */
- (void)ecgPeripheralManager:(NCBEcgPeripheralManager *_Nonnull)ecgPeripheralManager didSetUserInfoWithState:(NCBPeripheralUserInfoSettingState)state;
@end

@interface NCBEcgPeripheralManager : NSObject

/// 连接回调
@property (nonatomic, weak) id<NCBEcgPeripheralManagerConnectDelegate> _Nullable connectDelegate;
/// 数据回调
@property (nonatomic, weak) id<NCBEcgPeripheralManagerDataDelegate> _Nullable dataDelegate;
#if NCBDEBUG
/// 调试代理
@property (nonatomic, weak) id<NCBPeripheralDebugDelegate> _Nullable debugDelegate;
#endif

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
 启动测量
 */
- (void)startEcgMeasure;

/**
 结束测量
 */
- (void)endEcgMeasure;

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
 使设备的led灯闪烁
 
 @param duraction 闪烁时间, 1亮，0灭
 */
- (void)ledFlashesForDuration:(uint8_t)duraction;

/**
 发送用户信息
 
 @param height 身高cm
 @param weight 体重kg
 @param gender 性别 0女 1男
 @param age 年龄
 */
- (void)sendUserInfoWithHeight:(uint8_t)height weight:(uint8_t)weight gender:(uint8_t)gender age:(uint8_t)age;

/**
 是否有新的固件
 */
- (void)isHaveNewFirmware:(void(^_Nullable)(BOOL isHaveNewFirmware))block NS_DEPRECATED_IOS(2_0, 2_0);

/**
 *  固件更新
 *
 *  @param filePath              文件存储路径
 *  @param downloadProgressBlock 下载固件的进度
 *  @param updateProgressBlock   固件更新的进度
 *  @param completionHandler     完成的回调
 *
 */
- (void)firmwareUpdateWithFilePath:(NSString *_Nonnull)filePath downloadProgressBlock:(void(^_Nullable)(NSUInteger downloadProgress))downloadProgressBlock updateProgressBlock:(void(^_Nullable)(NSUInteger writeProgress))updateProgressBlock completionHandler:(void(^_Nullable)(NCBPeripheralFirmwareUpdateResutl result))completionHandler NS_DEPRECATED_IOS(2_0, 2_0);

/**
 固件更新，直接传递固件文件路径进行更新，新的固件需要手动下载
 
 @param filePath 固件文件路径
 @param updateProgressBlock 固件更新进度
 @param completionHandler 完成的回调
 */
- (void)startFirmwareUpgradeWithFilePath:(NSURL *)filePath updateProgressBlock:(void(^_Nullable)(NSUInteger writeProgress))updateProgressBlock completionHandler:(void(^_Nullable)(NCBPeripheralFirmwareUpdateResutl result))completionHandler;

@end
