//
//  NCBFirstPerihperalManager.h
//  NanochapSDK
//
//  Created by 刘帅 on 2018/12/12.
//  Copyright © 2018年 刘帅. All rights reserved.
//

#import "NCBPeripheralManager.h"
#import "NCBCommonConst.h"

@class NCBFirstPerihperalManager;

@protocol NCBFirstPerihperalManagerDataDelegate <NCBPeripheralManagerDataDelegate>
@optional
/**
 时间设置成功回调
 
 @param firstPeripheralManager 外设管理对像
 */
- (void)firstPeripheralManager:(NCBFirstPerihperalManager *_Nonnull)firstPeripheralManager didSetTimeSucceed:(BOOL)succeed;

/**
 测试led是否正常回调，需要人工判断

 @param firstPeripheralManager 外设管理对像
 @param result 测试结果
 @param errorCode 测试失败错误码
 */
- (void)firstPeripheralManager:(NCBFirstPerihperalManager *)firstPeripheralManager ledTest:(NCBFactoryTestResult)result errorCode:(NCBFactoryTestErrorCode)errorCode;

/**
 测试电池电压是否正常回调
 
 @param firstPeripheralManager 外设管理对像
 @param result 测试结果
 @param errorCode 测试失败错误码
 */
- (void)firstPeripheralManager:(NCBFirstPerihperalManager *)firstPeripheralManager batteryTest:(NCBFactoryTestResult)result errorCode:(NCBFactoryTestErrorCode)errorCode;

/**
 测试充电电路是否正常回调，需要等待插入电源
 
 @param firstPeripheralManager 外设管理对像
 @param result 测试结果
 @param errorCode 测试失败错误码
 */
- (void)firstPeripheralManager:(NCBFirstPerihperalManager *)firstPeripheralManager chargeTest:(NCBFactoryTestResult)result errorCode:(NCBFactoryTestErrorCode)errorCode;

/**
 测试触摸按钮是否正常回调，需要等待
 
 @param firstPeripheralManager 外设管理对像
 @param result 测试结果
 @param errorCode 测试失败错误码
 */
- (void)firstPeripheralManager:(NCBFirstPerihperalManager *)firstPeripheralManager touchButtonTest:(NCBFactoryTestResult)result errorCode:(NCBFactoryTestErrorCode)errorCode;

/**
 测试oled是否正常回调，需要人工判断
 
 @param firstPeripheralManager 外设管理对像
 @param result 测试结果
 @param errorCode 测试失败错误码
 */
- (void)firstPeripheralManager:(NCBFirstPerihperalManager *)firstPeripheralManager oledTest:(NCBFactoryTestResult)result errorCode:(NCBFactoryTestErrorCode)errorCode;

/**
 恢复出厂设置回调

 @param firstPeripheralManager 外设管理对像
 @param result 恢复出厂设置结果
 */
- (void)firstPeripheralManager:(NCBFirstPerihperalManager *)firstPeripheralManager didRestoreFactorySettingsResult:(NCBRestoreFactorySettingsResult)result;

/**
 打印设备当前时间

 @param firstPeripheralManager 外设管理对像
 @param time 时间信息
 */
- (void)firstPeripheralManager:(NCBFirstPerihperalManager *)firstPeripheralManager deviceTime:(NCBDate)time;

/**
 打印设备绑定的用户Id

 @param firstPeripheralManager 外设管理对像
 @param userId 用户id
 */
- (void)firstPeripheralManager:(NCBFirstPerihperalManager *)firstPeripheralManager bindUserId:(uint64_t)userId;

/**
 打印固件版本号

 @param firstPeripheralManager 外设管理对像
 @param firmwareVersion 固件版本
 */
- (void)firstPeripheralManager:(NCBFirstPerihperalManager *)firstPeripheralManager firmwareVersion:(NSString *)firmwareVersion;

@end

NS_ASSUME_NONNULL_BEGIN

@interface NCBFirstPerihperalManager : NCBPeripheralManager

/// 数据回调
@property (nonatomic, weak, nullable) id<NCBFirstPerihperalManagerDataDelegate> dataDelegate;

/**
 设置时间，绑定登录会自动调用，单纯连接需要手动调用
 */
- (void)setTime;

/**
 获取历史测量数据
 */
- (void)readHistoryMeasureData;

/**
 测试LED是否正常，需要人工选择
 */
- (void)testLedIsNormal;

/**
 测试电池电压是否正常
 */
- (void)testBatteryVoltageIsNormal;

/**
 测试充电是否正常
*/
- (void)testChargeIsNormal;

/**
 测试触摸按键是否正常
 */
- (void)testTouchButtonIsNormal;

/**
 测试OLED是否正常，需要人工选择
 */
- (void)testOLEDIsNormal;

/**
进入休眠模式
*/
- (void)testEnterDormancyModel;

/**
恢复出厂设置
*/
- (void)restoreFactorySettings;

/**
打印设备当前时间
*/
- (void)printDeviceCurrentTime;

/**
打印设备绑定id
*/
- (void)printDevieBindId;

/**
打印固件版本
*/
- (void)printDeviceFirmwareVerson;

/**
打印FPGA测量数据
*/
- (void)printFPGAMeasureData;
@end

NS_ASSUME_NONNULL_END
