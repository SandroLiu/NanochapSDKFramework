//
//  NCBMultiParameterPeripheralManager.h
//  NanochapSDK
//
//  Created by 刘帅 on 2018/8/15.
//  Copyright © 2018年 刘帅. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NCBPeripheralState.h"
#import "NCBDebugConst.h"
#if NCBDEBUG
#import "NCBPeripheralDebugDelegate.h"
#endif

@class NCBMultiParameterPeripheralManager;
@class NCBMutliParameterItem;
@class NCBAdvertisementItem;

@protocol NCBMultiParameterPeripheralManagerConnectDelegate<NSObject>
@optional
/**
 连接失败回调
 
 @param mpPeripheralManager 多参数外设管理对象
 @param error 错误
 */
- (void)mpPeripheralManager:(NCBMultiParameterPeripheralManager *_Nonnull)mpPeripheralManager didFailToConnectDevice:(NSError *_Nullable)error;

/**
 与外设失去连接
 
 @param mpPeripheralManager 多参数外设管理对象
 @param error 错误
 */
- (void)mpPeripheralManager:(NCBMultiParameterPeripheralManager *_Nonnull)mpPeripheralManager didDisconnectPeripheral:(NSError * _Nullable)error;

/**
 设备绑定回调
 
 @param mpPeripheralManager 多参数外设管理对象
 @param state 绑定状态
 */
- (void)mpPeripheralManager:(NCBMultiParameterPeripheralManager *_Nonnull)mpPeripheralManager didBindState:(NCBPeripheralBindState)state;

/**
 *  返回解绑结果
 *
 *  @param mpPeripheralManager 多参数外设管理对象
 *  @param state      结果
 */
- (void)mpPeripheralManager:(NCBMultiParameterPeripheralManager *_Nonnull)mpPeripheralManager didUnbindState:(NCBPeripheralUnbindState)state;

/**
 *  返回登录结果
 *
 *  @param mpPeripheralManager 多参数外设管理对象
 *  @param state      结果
 */
- (void)mpPeripheralManager:(NCBMultiParameterPeripheralManager *_Nonnull)mpPeripheralManager didLoginState:(NCBPeripheralLoginState)state;

/**
 *  返回退出结果
 *
 *  @param mpPeripheralManager 多参数外设管理对象
 *  @param state      结果
 */
- (void)mpPeripheralManager:(NCBMultiParameterPeripheralManager *_Nonnull)mpPeripheralManager didLogoutState:(NCBPeripheralLogoutState)state;

/**
 返回单纯连接结果
 
 @param mpPeripheralManager 多参数外设管理对象
 @param state 状态
 */
- (void)mpPeripheralManager:(NCBMultiParameterPeripheralManager *_Nonnull)mpPeripheralManager didConnectState:(NCBPeripheralConnectState)state;

@end

@protocol NCBMultiParameterPeripheralManagerDataDelegate<NSObject>

@optional
#pragma mark- 两代设备共有的回调方法
/**
 读取电量值回调
 
 @param mpPeripheralManager 多参数外设管理对象
 @param value 电量值
 */
- (void)mpPeripheralManager:(NCBMultiParameterPeripheralManager *_Nonnull)mpPeripheralManager didReadedElectricValue:(NSUInteger)value;

/**
 获取mac地址
 
 @param mpPeripheralManager 多参数外设管理对象
 @param mac mac地址
 */
- (void)mpPeripheralManager:(NCBMultiParameterPeripheralManager *_Nonnull)mpPeripheralManager didReadedMac:(NSData *_Nonnull)mac;

/**
 *  开始测量
 *
 *  @param mpPeripheralManager 多参数外设管理对象
 */
- (void)mpPeripheralManager:(NCBMultiParameterPeripheralManager *_Nonnull)mpPeripheralManager didStartBPMeasureState:(NCBPeripheralStartMeasureState)state;

/**
 结束测量
 
 @param mpPeripheralManager 多参数外设管理对象
 */
- (void)mpPeripheralManagerDidEndMeasure:(NCBMultiParameterPeripheralManager *_Nonnull)mpPeripheralManager;

/**
 *  测量数据返回
 *
 *  @param mpPeripheralManager 血压外设管理对象
 *  @param item       测量值
 */
- (void)mpPeripheralManager:(NCBMultiParameterPeripheralManager *_Nonnull)mpPeripheralManager didFetchMeasureItem:(NCBMutliParameterItem *_Nonnull)item;

/**
 *  波形数据
 *
 *  @param mpPeripheralManager 多参数外设管理对象
 *  @param datas      波形数据
 */
- (void)mpPeripheralManager:(NCBMultiParameterPeripheralManager *_Nonnull)mpPeripheralManager didReceiveWaveData:(NSArray *_Nonnull)datas;

/**
 *  测量失败
 *
 *  @param mpPeripheralManager 多参数外设管理对象
 */
- (void)mpPeripheralManagerDidMeasureFail:(NCBMultiParameterPeripheralManager *_Nonnull)mpPeripheralManager;

@end

NS_CLASS_DEPRECATED_IOS(2.0, 2.0, "该类已经废弃")
@interface NCBMultiParameterPeripheralManager : NSObject

/// 连接回调
@property (nonatomic, weak) id<NCBMultiParameterPeripheralManagerConnectDelegate> _Nullable connectDelegate;
/// 数据回调
@property (nonatomic, weak) id<NCBMultiParameterPeripheralManagerDataDelegate> _Nullable dataDelegate;

#if NCBDEBUG
@property (nonatomic, weak) id<NCBPeripheralDebugDelegate> _Nullable debugDelegate;
#endif


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


/**
 固件更新，直接传递固件文件路径进行更新，新的固件需要手动下载
 
 @param filePath 固件文件路径
 @param updateProgressBlock 固件更新进度
 @param completionHandler 完成的回调
 */
- (void)startFirmwareUpgradeWithFilePath:(NSURL *)filePath updateProgressBlock:(void(^_Nullable)(NSUInteger writeProgress))updateProgressBlock completionHandler:(void(^_Nullable)(NCBPeripheralFirmwareUpdateResutl result))completionHandler;

/**
 开始测量
 */
- (void)startMeasure;

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
