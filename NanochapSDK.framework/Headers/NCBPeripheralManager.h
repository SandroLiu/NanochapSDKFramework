//
//  NCBPeripheralManager.h
//  NanochapSDK
//
//  Created by 刘帅 on 2018/12/12.
//  Copyright © 2018年 刘帅. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NCBPeripheralState.h"
#if NCBDEBUG
#import "NCBPeripheralDebugDelegate.h"
#endif

@class NCBAdvertisementItem;
@class NCBPeripheralManager;

@protocol NCBPeripheralManagerConnectDelegate<NSObject>
@optional

/**
 连接失败回调
 
 @param peripheralManager 外设管理对象
 @param error 错误
 */
- (void)peripheralManager:(NCBPeripheralManager *_Nonnull)peripheralManager didFailToConnectDevice:(NSError *_Nullable)error;

/**
 与外设失去连接
 
 @param peripheralManager 外设管理对象
 @param error 错误
 */
- (void)peripheralManager:(NCBPeripheralManager *_Nonnull)peripheralManager didDisconnectPeripheral:(NSError * _Nullable)error;

/**
 设备绑定回调
 
 @param peripheralManager 外设管理对象
 @param state 绑定状态
 */
- (void)peripheralManager:(NCBPeripheralManager *_Nonnull)peripheralManager didBindState:(NCBPeripheralBindState)state;

/**
 *  返回解绑、超级解绑结果
 *
 *  @param peripheralManager 外设管理对象
 *  @param state      结果
 */
- (void)peripheralManager:(NCBPeripheralManager *_Nonnull)peripheralManager didUnbindState:(NCBPeripheralUnbindState)state;

/**
 *  返回登录结果
 *
 *  @param peripheralManager 外设管理对象
 *  @param state      结果
 */
- (void)peripheralManager:(NCBPeripheralManager *_Nonnull)peripheralManager didLoginState:(NCBPeripheralLoginState)state;

/**
 *  返回退出结果
 *
 *  @param peripheralManager 外设管理对象
 *  @param state      结果
 */
- (void)peripheralManager:(NCBPeripheralManager *_Nonnull)peripheralManager didLogoutState:(NCBPeripheralLogoutState)state;

/**
 返回单纯连接结果
 
 @param peripheralManager 外设管理对象
 @param state 状态
 */
- (void)peripheralManager:(NCBPeripheralManager *_Nonnull)peripheralManager didConnectState:(NCBPeripheralConnectState)state;

@end

@protocol NCBPeripheralManagerDataDelegate<NSObject>
@optional
/**
 读取电量值回调
 
 @param peripheralManager 外设管理对象
 @param value 电量值
 */
- (void)peripheralManager:(NCBPeripheralManager *_Nonnull)peripheralManager didReadedElectricValue:(NSUInteger)value;

/**
 获取mac地址
 
 @param peripheralManager 外设管理对象
 @param mac mac地址
 */
- (void)peripheralManager:(NCBPeripheralManager *_Nonnull)peripheralManager didReadedMac:(NSData *_Nonnull)mac;

/**
 设置用户信息回调
 
 @param peripheralManager 外设管理对象
 @param state 状态
 */
- (void)peripheralManager:(NCBPeripheralManager *_Nonnull)peripheralManager didSetUserInfoWithState:(NCBPeripheralUserInfoSettingState)state;
@end



@interface NCBPeripheralManager : NSObject

// 连接回调
@property (nonatomic, weak) id<NCBPeripheralManagerConnectDelegate> _Nullable connectDelegate;
/// 数据回调
@property (nonatomic, weak) id<NCBPeripheralManagerDataDelegate> _Nullable dataDelegate;

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
 读取设备电量
 */
- (void)readPeripheralElectricQuantity;

/**
 读取mac地址
 */
- (void)readPeripheralMacAddress;

/**
 发送用户信息
 
 @param height 身高cm
 @param weight 体重kg
 @param gender 性别 0女 1男
 @param age 年龄
 */
- (void)sendUserInfoWithHeight:(uint8_t)height weight:(uint8_t)weight gender:(uint8_t)gender age:(uint8_t)age;

/**
 获取固件版本号
 */
- (void)readPeripheralFirmwareVersion:(void(^_Nullable)(NSString * _Nonnull firmwareVersion))block;

/**
 固件更新，直接传递固件文件路径进行更新，新的固件需要手动下载
 
 @param filePath 固件文件路径
 @param updateProgressBlock 固件更新进度
 @param completionHandler 完成的回调
 */
- (void)startFirmwareUpgradeWithFilePath:(NSURL *)filePath updateProgressBlock:(void(^_Nullable)(NSUInteger writeProgress))updateProgressBlock completionHandler:(void(^_Nullable)(NCBPeripheralFirmwareUpdateResutl result))completionHandler;


#if NCBDEBUG
/**
 超级解绑
 */
- (void)superUnbind;
#endif

@end

