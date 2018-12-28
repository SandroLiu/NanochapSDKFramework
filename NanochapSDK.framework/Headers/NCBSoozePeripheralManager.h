//
//  NCBSoozePeripheralManager.h
//  NanochapSDK
//
//  Created by 刘帅 on 2018/5/24.
//  Copyright © 2018年 刘帅. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NCBPeripheralState.h"
#import "NCBDebugConst.h"
#if NCBDEBUG
#import "NCBPeripheralDebugDelegate.h"
#endif

@class NCBSoozePeripheralManager;
@class NCBAdvertisementItem;
@class NCBSoozeStateItem;

@protocol NCBSoozePeripheralManagerConnectDelegate<NSObject>
@optional
/**
 连接失败回调
 
 @param szPeripheralManager sooze外设管理对象
 @param error 错误
 */
- (void)szPeripheralManager:(NCBSoozePeripheralManager *_Nonnull)szPeripheralManager didFailToConnectDevice:(NSError *_Nullable)error;

/**
 与外设失去连接
 
 @param szPeripheralManager sooze外设管理对象
 @param error 错误
 */
- (void)szPeripheralManager:(NCBSoozePeripheralManager *_Nonnull)szPeripheralManager didDisconnectPeripheral:(NSError * _Nullable)error;

/**
 设备绑定回调
 
 @param szPeripheralManager sooze外设管理对象
 @param state 绑定状态
 */
- (void)szPeripheralManager:(NCBSoozePeripheralManager *_Nonnull)szPeripheralManager didBindState:(NCBPeripheralBindState)state;

/**
 *  返回解绑结果
 *
 *  @param szPeripheralManager sooze外设管理对象
 *  @param state      结果
 */
- (void)szPeripheralManager:(NCBSoozePeripheralManager *_Nonnull)szPeripheralManager didUnbindState:(NCBPeripheralUnbindState)state;

/**
 *  返回登录结果
 *
 *  @param szPeripheralManager sooze外设管理对象
 *  @param state      结果
 */
- (void)szPeripheralManager:(NCBSoozePeripheralManager *_Nonnull)szPeripheralManager didLoginState:(NCBPeripheralLoginState)state;

/**
 *  返回退出结果
 *
 *  @param szPeripheralManager sooze外设管理对象
 *  @param state      结果
 */
- (void)szPeripheralManager:(NCBSoozePeripheralManager *_Nonnull)szPeripheralManager didLogoutState:(NCBPeripheralLogoutState)state;

/**
 返回单纯连接结果
 
 @param szPeripheralManager sooze外设管理对象
 @param state 状态
 */
- (void)szPeripheralManager:(NCBSoozePeripheralManager *_Nonnull)szPeripheralManager didConnectState:(NCBPeripheralConnectState)state;
@end

@protocol NCBSoozePeripheralManagerDataDelegate<NSObject>
@optional

/**
 读取电量值回调
 
 @param szPeripheralManager sooze外设管理对象
 @param value 电量值
 */
- (void)szPeripheralManager:(NCBSoozePeripheralManager *_Nonnull)szPeripheralManager didReadedElectricValue:(NSUInteger)value;

/**
 获取mac地址

 @param szPeripheralManager sooze外设管理对象
 @param mac mac地址
 */
- (void)szPeripheralManager:(NCBSoozePeripheralManager *_Nonnull)szPeripheralManager didReadedMac:(NSData *_Nonnull)mac;

/// 处理启动回调
- (void)szPeripheralManager:(NCBSoozePeripheralManager *_Nonnull)szPeripheralManager handleStartWithSucceed:(BOOL)succeed;

/// 调节档位回调
- (void)szPeripheralManagerDidLevelChangeSucceed:(NCBSoozePeripheralManager *_Nonnull)szPeripheralManager;

/// 暂停回调
- (void)szPeripheralManager:(NCBSoozePeripheralManager *_Nonnull)szPeripheralManager handlePauseForHasRunSeconds:(uint16_t)seconds;

/// 停止回调
- (void)szPeripheralManagerDidStoped:(NCBSoozePeripheralManager *_Nonnull )szPeripheralManager;

/// 蜂鸣器控制回调
- (void)szPeripheralManagerDidSettedBuzzer:(NCBSoozePeripheralManager *_Nonnull )szPeripheralManager;

/// 设置马达回调
- (void)szPeripheralManagerDidSettedShake:(NCBSoozePeripheralManager *_Nonnull )szPeripheralManager;

/// 设置led
- (void)szPeripheralManagerDidSettedLed:(NCBSoozePeripheralManager *_Nonnull )szPeripheralManager;

/// 查询设备信息回调
- (void)szPeripheralManager:(NCBSoozePeripheralManager *_Nonnull )szPeripheralManager handlePeripheralState:(NCBSoozeStateItem *)item;

/// 切换设备运行模式
- (void)szPeripheralManager:(NCBSoozePeripheralManager *_Nonnull )szPeripheralManager didChangeRunModeSucceed:(BOOL)succeed;
@end

@interface NCBSoozePeripheralManager : NSObject

/// 连接回调
@property (nonatomic, weak) id<NCBSoozePeripheralManagerConnectDelegate> _Nullable connectDelegate;
/// 数据回调
@property (nonatomic, weak) id<NCBSoozePeripheralManagerDataDelegate> _Nullable dataDelegate;

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
@end
